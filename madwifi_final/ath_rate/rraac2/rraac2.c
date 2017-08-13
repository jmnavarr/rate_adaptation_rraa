/*-
 * MadWifi RRAA Implementation by Nathaniel Conos, 
 * Juan M. Navarro, and Lucas Wanner
 * 
 * Original RRAA Implementation by Chris Hunter
 * 
 * Structure based on the AMRR implementation by Sam Leffler
 *
 */

#ifndef AUTOCONF_INCLUDED
#include <linux/config.h>
#endif
#include <linux/version.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/skbuff.h>
#include <linux/netdevice.h>
#include <linux/random.h>
#include <linux/delay.h>
#include <linux/cache.h>
#include <linux/sysctl.h>
#include <linux/proc_fs.h>
#include <linux/if_arp.h>

#include <asm/uaccess.h>

#include <net80211/if_media.h>
#include <net80211/ieee80211_var.h>
#include <net80211/ieee80211_rate.h>

#include "if_athvar.h"
#include "if_ath_hal.h"
#include "ah_desc.h"

#include "rraac2.h"

#define DEBUG 1
#define	AMRR_DEBUG
#ifdef AMRR_DEBUG
#define	DPRINTF(sc, _fmt, ...) do {					\
	if (DEBUG)					\
		printk(_fmt, __VA_ARGS__);				\
} while (0)
#else
#define	DPRINTF(sc, _fmt, ...)
#endif


static bool first_time = true ;
static int total_num_packets ;
static void ath_rate_update(struct ath_softc *, struct ieee80211_node *, int);
static void ath_rate_ctl_start(struct ath_softc *, struct ieee80211_node *);
static void ath_rate_ctl(void *, struct ieee80211_node *);

static void
ath_rate_node_init(struct ath_softc *sc, struct ath_node *an)
{
    /* NB: assumed to be zero'd by caller */

  struct rraa_c2_node *rraa = ATH_NODE_C2_RRAA(an);
  /* initialize rate */

  if (first_time){
    total_num_packets = 0;
      rraa_map[0].rate = 1;
      rraa_map[1].rate = 2;
      rraa_map[2].rate = 5;
      rraa_map[3].rate = 6;
      rraa_map[4].rate = 9;
      rraa_map[5].rate = 11;   	
      rraa_map[6].rate = 12;
      rraa_map[7].rate = 18;
      rraa_map[8].rate = 24;
      rraa_map[9].rate = 36;
      rraa_map[10].rate = 48;
      rraa_map[11].rate = 54;
      
      /* initialize PORI - CASE 2 */
      rraa_map[0].pori = 50;
      rraa_map[1].pori = 50;
      rraa_map[2].pori = 50;
      rraa_map[3].pori = 50; // 6Mbps
      rraa_map[4].pori = 14; // 9Mbps
      rraa_map[5].pori = 16; // 11Mbps
      rraa_map[6].pori = 19; // 12Mbps
      rraa_map[7].pori = 13; // 18Mbps
      rraa_map[8].pori = 17; // 24Mbps
      rraa_map[9].pori = 12;  // 36Mbps
      rraa_map[10].pori = 5;// 48Mbps
      rraa_map[11].pori = 0;// 54Mbps
      
      /* initialize PMTL - CASE 2 */
      rraa_map[0].pmtl = 29;
      rraa_map[1].pmtl = 29;
      rraa_map[2].pmtl = 29;
      rraa_map[3].pmtl = 29; // 6Mbps
      rraa_map[4].pmtl = 29; // 9Mbps
      rraa_map[5].pmtl = 24; // 11Mbps
      rraa_map[6].pmtl = 22; // 12Mbps
      rraa_map[7].pmtl = 28; // 18Mbps
      rraa_map[8].pmtl = 20; // 24Mbps
      rraa_map[9].pmtl = 26;  // 36Mbps
      rraa_map[10].pmtl = 17;// 48Mbps
      rraa_map[11].pmtl = 7;// 54Mbps
      
      /* initialize EWND */
      rraa_map[0].ewnd = 6;
      rraa_map[1].ewnd = 6;
      rraa_map[2].ewnd = 6;
      rraa_map[3].ewnd = 6; // 6Mbps
      rraa_map[4].ewnd = 10; // 9Mbps
      rraa_map[5].ewnd = 15; // 11Mbps
      rraa_map[6].ewnd = 20; // 12Mbps
      rraa_map[7].ewnd = 20; // 18Mbps
      rraa_map[8].ewnd = 40; // 24Mbps
      rraa_map[9].ewnd = 40;  // 36Mbps
      rraa_map[10].ewnd = 40;// 48Mbps
      rraa_map[11].ewnd = 40;// 54Mbps
      
      /* initialize estimation window */
      rraa->rraa_counter = rraa_map[MAX_RATE_POS].ewnd;
      
      ath_rate_update(sc, &an->an_node, 0);
      
      first_time = false;
  }
  

}

static void
ath_rate_node_cleanup(struct ath_softc *sc, struct ath_node *an)
{
}

/* This will be called by MadWifi to set tx rate, index,
	and number of tries */
static void
ath_rate_findrate(struct ath_softc *sc, struct ath_node *an,
	int shortPreamble, size_t frameLen,
	u_int8_t *rix, unsigned int *try0, u_int8_t *txrate)
{

	struct rraa_c2_node *rraa = ATH_NODE_C2_RRAA(an);

	*rix = rraa->rraa_tx_rix0;
	*try0 = rraa->rraa_tx_try0;
	if (shortPreamble)
		*txrate = rraa->rraa_tx_rate0sp;
	else
		*txrate = rraa->rraa_tx_rate0;
}

/* This will be called by MadWifi to set number of retries and
   retry rates when using multi-rate retry */
static void
ath_rate_get_mrr(struct ath_softc *sc, struct ath_node *an, int shortPreamble,
		 size_t frame_size, u_int8_t rix, struct ieee80211_mrr *mrr)
{

  	//struct rraa_c2_node *rraa = ATH_NODE_C2_RRAA(an);
	
	/* Assuming no multi-rate retry for RRAA, all the values will be zero */
  
	mrr->rate1 	= 0;//rraa->rraa_tx_rate1sp;
	mrr->retries1 	= 0; //rraa->rraa_tx_try1;
	mrr->rate2 	= 0; //rraa->rraa_tx_rate2sp;
	mrr->retries2 	= 0; //rraa->rraa_tx_try2;
	mrr->rate3 	= 0;//rraa->rraa_tx_rate3sp;
	mrr->retries3 	= 0; //rraa->rraa_tx_try3;
}

/* This will be called by MadWifi at tx complete */
static void
ath_rate_tx_complete(struct ath_softc *sc,
		     struct ath_node *an, const struct ath_buf *bf)
{

    
  struct rraa_c2_node *rraa = ATH_NODE_C2_RRAA(an);
  
  const struct ath_tx_status *ts = &bf->bf_dsstatus.ds_txstat;
  
  if (ts->ts_status == 0)
      rraa->rraa_tx_complete++;
  else
      rraa->rraa_tx_fail++;

  
  rraa->rraa_tx_retry += ts->ts_shortretry + ts->ts_longretry;

  /* Check if its time for us to perform rate ctl */
    
  if ( --rraa->rraa_counter <= 0 )
	ath_rate_ctl(sc, &an->an_node);

}

static void
ath_rate_newassoc(struct ath_softc *sc, struct ath_node *an, int isnew)
{
	if (isnew)
		ath_rate_ctl_start(sc, &an->an_node);
}

static void
ath_rate_update(struct ath_softc *sc, struct ieee80211_node *ni, int rate)
{
	struct ath_node *an = ATH_NODE(ni);
	struct rraa_c2_node *rraa = ATH_NODE_C2_RRAA(an);
	const HAL_RATE_TABLE *rt = sc->sc_currates;
	
	KASSERT(rt != NULL, ("rraa: no rate table, mode %u", sc->sc_curmode));

#if 0
	DPRINTF(sc, "rraa_map: %s: set tx rate for " MAC_FMT " to %dM\n",
		__func__, MAC_ADDR(ni->ni_macaddr),
		ni->ni_rates.rs_nrates > 0 ?
			(ni->ni_rates.rs_rates[rate] & IEEE80211_RATE_VAL) / 2 : 0);  
#endif

	ni->ni_txrate = rate;

	if (ni->ni_rates.rs_nrates > 0) {
		rraa->rraa_tx_rix0 =
			sc->sc_rixmap[ni->ni_rates.rs_rates[rate] & IEEE80211_RATE_VAL];
		rraa->rraa_tx_rate0 = rt->info[rraa->rraa_tx_rix0].rateCode;
		rraa->rraa_tx_rate0sp = rraa->rraa_tx_rate0 |
			rt->info[rraa->rraa_tx_rix0].shortPreamble;

		/* We are not using Multi-Rate retry for RRAA 
		   Set number of retransmissions to the max with the first rate	
		*/
		
		rraa->rraa_tx_try0 = ATH_TXMAXTRY;
	}
}

/*
 * Set the starting transmit rate for a node.
 */
static void
ath_rate_ctl_start(struct ath_softc *sc, struct ieee80211_node *ni)
{
#define	RATE(_ix)	(ni->ni_rates.rs_rates[(_ix)] & IEEE80211_RATE_VAL)
	struct ieee80211vap *vap = ni->ni_vap;
	int srate;

	KASSERT(ni->ni_rates.rs_nrates > 0, ("rraa: no rates"));
	if (vap->iv_fixed_rate == IEEE80211_FIXED_RATE_NONE) {
		/*
		 * No fixed rate is requested. For 11b start with
		 * the highest negotiated rate; otherwise, for 11g
		 * and 11a, we start "in the middle" at 24Mb or 36Mb.
		 */
		srate = ni->ni_rates.rs_nrates - 1;
		#if 0
		if (sc->sc_curmode != IEEE80211_MODE_11B) {
			/*
			 * Scan the negotiated rate set to find the
			 * closest rate.
			 */
			/* NB: the rate set is assumed sorted */
			for (; srate >= 0 && RATE(srate) > 72; srate--);
			KASSERT(srate >= 0, ("rraa: bogus rate set"));
		}
		#endif 
	} else {
		/*
		 * A fixed rate is to be used; ic_fixed_rate is an
		 * index into the supported rate set.  Convert this
		 * to the index into the negotiated rate set for
		 * the node.  We know the rate is there because the
		 * rate set is checked when the station associates.
		 */
		srate = ni->ni_rates.rs_nrates - 1;
		for (; srate >= 0 && RATE(srate) != vap->iv_fixed_rate; srate--);
		KASSERT(srate >= 0,
			("rraa: fixed rate %d not in rate set", vap->iv_fixed_rate));
	}
	
	ath_rate_update(sc, ni, srate);
#undef RATE
}

static void
ath_rate_cb(void *arg, struct ieee80211_node *ni)
{
  ath_rate_update(netdev_priv(ni->ni_ic->ic_dev), ni, (long) arg);
}

/*
 * Reset the rate control state for each 802.11 state transition.
 */
static void
ath_rate_newstate(struct ieee80211vap *vap, enum ieee80211_state state)
{
	struct ieee80211com *ic = vap->iv_ic;
	struct ath_softc *sc = netdev_priv(ic->ic_dev);
	struct ieee80211_node *ni;

	if (ic->ic_opmode == IEEE80211_M_STA) {
		/*
		 * Reset local xmit state; this is really only
		 * meaningful when operating in station mode.
		 */
		ni = vap->iv_bss;
		if (state == IEEE80211_S_RUN)
			ath_rate_ctl_start(sc, ni);
		else
		{
			if (first_time){
			  ath_rate_update(sc, ni, 0);
			}
		}
	} else {
		/*
		 * When operating as a station the node table holds
		 * the APs that were discovered during scanning.
		 * For any other operating mode we want to reset the
		 * tx rate state of each node.
		 */
		ieee80211_iterate_nodes(&ic->ic_sta, ath_rate_cb, NULL);
		if (first_time){
		  ath_rate_update(sc, vap->iv_bss, 0);
		}
	}
}

/* 
 * Examine and potentially adjust the transmit rate.
 */
static void
ath_rate_ctl(void *arg, struct ieee80211_node *ni)
{
#define is_max_rate(ni) ((ni->ni_txrate + 1) >= ni->ni_rates.rs_nrates) 
#define is_min_rate(ni) (ni->ni_txrate == 0)

	struct rraa_c2_node *rraa = ATH_NODE_C2_RRAA(ATH_NODE(ni));
	struct ath_softc *sc = arg;
	int old_rate;

	old_rate = ni->ni_txrate;
	
	rraa->rraa_loss_ratio = 
	  (rraa->rraa_tx_retry*100)/(rraa->rraa_tx_retry + rraa->rraa_tx_complete);
	
#if 0
	DPRINTF (sc, "rraac2: tx_complete: %d tx_fail: %d tx_retry: %d tx_loss_ratio: %d\n",
		 rraa->rraa_tx_complete,
		 rraa->rraa_tx_fail,
		 rraa->rraa_tx_retry,
		 rraa->rraa_loss_ratio);	
#endif
	
	if ( rraa->rraa_loss_ratio > rraa_map[ni->ni_txrate].pmtl ) {
	  if ( !is_min_rate(ni) )
	    ni->ni_txrate --;
	}
	else if ( rraa->rraa_loss_ratio < rraa_map[ni->ni_txrate].pori ) {
	  if ( !is_max_rate(ni) )
	    ni->ni_txrate ++;
	}
	
	// Update estimation window
	rraa->rraa_counter = rraa_map[ni->ni_txrate].ewnd;
		
	rraa->rraa_tx_count += rraa->rraa_tx_complete ;
	  
	// Reset statistics 
	rraa->rraa_tx_complete = 0;
    	rraa->rraa_tx_fail = 0;
    	rraa->rraa_tx_retry = 0;
   		
	if ( old_rate != ni->ni_txrate ){
	  ath_rate_update(sc, ni, ni->ni_txrate);
	  // Only output statistics when rate change (022709)
	  DPRINTF(sc, "rraac2: " MAC_FMT " : ", MAC_ADDR(ni->ni_macaddr));  
	  DPRINTF(sc, 
		  "tx_count: %d, tx_rate: %dM, loss ratio: %d, window size: %d\n",
		  rraa->rraa_tx_count,
		  rraa_map[ni->ni_txrate].rate,
		  rraa->rraa_loss_ratio,
		  rraa->rraa_counter);	
	}
		

	
}

static struct ath_ratectrl *
ath_rate_attach(struct ath_softc *sc)
{

	struct rraa_c2_softc *asc;

	if (DEBUG){
	  printk("rraac2: this is the new rraac2 module!\n");
	}

	_MOD_INC_USE(THIS_MODULE, return NULL);
	asc = kmalloc(sizeof(struct rraa_c2_softc), GFP_ATOMIC);
	if (asc == NULL) {
		_MOD_DEC_USE(THIS_MODULE);
		return NULL;
	}
	asc->arc.arc_space = sizeof(struct rraa_c2_node);
	asc->arc.arc_vap_space = 0;

	return &asc->arc;
}

static void
ath_rate_detach(struct ath_ratectrl *arc)
{
	struct rraa_c2_softc *asc = (struct rraa_c2_softc *)arc;
	kfree(asc);
	_MOD_DEC_USE(THIS_MODULE);
}

static struct ctl_table_header *ath_sysctl_header;

static struct ieee80211_rate_ops ath_rate_ops = {
	.ratectl_id = IEEE80211_RATE_RRAAC2,
	.node_init = ath_rate_node_init,
	.node_cleanup = ath_rate_node_cleanup,
	.findrate = ath_rate_findrate,
	.get_mrr = ath_rate_get_mrr,
	.tx_complete = ath_rate_tx_complete,
	.newassoc = ath_rate_newassoc,
	.newstate = ath_rate_newstate,
	.attach = ath_rate_attach,
	.detach = ath_rate_detach,
};

static struct ctl_table_header *ath_sysctl_header;

#include "release.h"

MODULE_AUTHOR("Nathaniel Conos, Juan M. Navarro, and Lucas Wanner");
MODULE_DESCRIPTION("RRAA Rate control algorithm");
#ifdef MODULE_VERSION
MODULE_VERSION(RELEASE_VERSION);
#endif
#ifdef MODULE_LICENSE
MODULE_LICENSE("Dual BSD/GPL");
#endif

static int __init
init_ath_rate_rraa_c2_softc(void)
{
	int ret = ieee80211_rate_register(&ath_rate_ops);
	if (ret)
		return ret;
	return (0);
}
module_init(init_ath_rate_rraa_c2_softc);

static void __exit
exit_ath_rate_rraa_c2_softc(void)
{
	if (ath_sysctl_header != NULL)
		unregister_sysctl_table(ath_sysctl_header);
	ieee80211_rate_unregister(&ath_rate_ops);
}
module_exit(exit_ath_rate_rraa_c2_softc);

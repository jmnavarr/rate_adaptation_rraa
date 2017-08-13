/*-
 * MadWifi RRAA Implementation by Nathaniel Conos, 
 * Juan M. Navarro, and Lucas Wanner
 * 
 * Original RRAA Implementation by Chris Hunter
 * 
 * Structure based on the AMRR implementation by Sam Leffler
 *
 */

#ifndef _DEV_ATH_RATE_RRAA_H
#define _DEV_ATH_RATE_RRAA_H

#define MAX_NUM_RATE 12
#define MAX_RATE_POS 11

struct rraa_rate_map {
  u_int rate;
  u_int pori;
  u_int pmtl;
  u_int ewnd;
};

struct rraa_rate_map rraa_map[MAX_NUM_RATE];


float test_num ;

/* per-device state */
struct rraa_softc {
	struct ath_ratectrl arc;		/* base state */
};

/* per-node state */
struct rraa_node {
  
  /* TX Statistics */ 
  u_int rraa_tx_complete;			
  u_int rraa_tx_fail;	
  u_int rraa_tx_retry;	
  
  /* keep track of total number of tx packets completed */
  u_int rraa_tx_count;
  
  /* keep track of loss ratio */
  u_int rraa_loss_ratio;
	
  /* keep track of estimation window */	
 int rraa_counter ;
  

  /* rate index et al. */
  u_int8_t	rraa_tx_rix0;	/* series 0 rate index */
  u_int8_t	rraa_tx_rate0;	/* series 0 h/w rate */
  u_int8_t	rraa_tx_rate0sp;
  u_int8_t	rraa_tx_try0;	/* series 0 try count */

  


};
#define	ATH_NODE_AMRR(an)	((struct rraa_node *)&an[1])
#define	ATH_NODE_RRAA(an)	((struct rraa_node *)&an[1])
#endif /* _DEV_ATH_RATE_RRAA_H */

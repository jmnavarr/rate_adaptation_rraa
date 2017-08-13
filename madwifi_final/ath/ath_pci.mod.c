#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__attribute_used__
__attribute__((section("__versions"))) = {
	{ 0xa024e4b1, "struct_module" },
	{ 0xaba2210b, "ath_hal_getwirelessmodes" },
	{ 0x852abecf, "__request_region" },
	{ 0xab807860, "kmalloc_caches" },
	{ 0xfd2b272, "pci_bus_read_config_byte" },
	{ 0x12da5bb2, "__kmalloc" },
	{ 0x7f16726b, "ieee80211_cancel_scan" },
	{ 0x8cfb218e, "ieee80211_find_txnode" },
	{ 0x227ee406, "ieee80211_getrssi" },
	{ 0xb7670d1a, "register_sysctl_table" },
	{ 0x5f729065, "ieee80211_chan2mode" },
	{ 0xa5423cc4, "param_get_int" },
	{ 0x8d5f3f9e, "ieee80211_crypto_encap" },
	{ 0x98b1f5e8, "del_timer" },
	{ 0x1f9cfe83, "iomem_resource" },
	{ 0xa62f828a, "ieee80211_dturbo_switch" },
	{ 0xd0d8621b, "strlen" },
	{ 0xf3c204f1, "ath_hal_init_channels" },
	{ 0x1a170d21, "proc_dointvec" },
	{ 0xcd6eeb3f, "pci_disable_device" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0xbc0d2992, "ieee80211_state_name" },
	{ 0xc1d68d68, "skb_copy" },
	{ 0xc8be7b15, "_spin_lock" },
	{ 0x63ecad53, "register_netdevice_notifier" },
	{ 0xb58748ba, "ieee80211_chan2ieee" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xe7d78429, "ieee80211_mark_dfs" },
	{ 0xfca081b4, "ieee80211_announce" },
	{ 0x1ecf1830, "ieee80211_vap_detach" },
	{ 0xa3ef802, "ieee80211_start_running" },
	{ 0xf438e063, "ieee80211_media_status" },
	{ 0xcb32da10, "param_set_int" },
	{ 0x6e185827, "_spin_lock_irqsave" },
	{ 0xc63a21f5, "ieee80211_input_all" },
	{ 0x7d11c268, "jiffies" },
	{ 0xfe769456, "unregister_netdevice_notifier" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x1009d14d, "ieee80211_wme_acnames" },
	{ 0x3f03210f, "ieee80211_create_vap" },
	{ 0xda4008e6, "cond_resched" },
	{ 0x6fa568c1, "ieee80211_send_qosnulldata" },
	{ 0xf2afa595, "param_get_charp" },
	{ 0x9dd541c, "pci_set_master" },
	{ 0xcda10c1, "del_timer_sync" },
	{ 0x471e1bdd, "alloc_etherdev_mq" },
	{ 0x3e4f7f36, "pci_set_dma_mask" },
	{ 0x15495d19, "ieee80211_rate_detach" },
	{ 0x871a2a1, "pci_restore_state" },
	{ 0xdf60cc27, "__print_symbol" },
	{ 0x6b9d9fbb, "ath_hal_print_decoded_register" },
	{ 0x1b7d4074, "printk" },
	{ 0x859204af, "sscanf" },
	{ 0x96d730e9, "ieee80211_rate_attach" },
	{ 0x51a400eb, "ath_hal_probe" },
	{ 0x80b53b09, "ieee80211_mhz2ieee" },
	{ 0x8f5087ef, "free_netdev" },
	{ 0x795340bb, "__tasklet_schedule" },
	{ 0xb6ed1e53, "strncpy" },
	{ 0x2f287f0d, "copy_to_user" },
	{ 0x4231da3b, "register_netdev" },
	{ 0x61655a55, "dma_free_coherent" },
	{ 0x6c2e3320, "strncmp" },
	{ 0x4f923fc2, "pci_bus_write_config_dword" },
	{ 0x3ee3eddc, "ieee80211_ibss_merge" },
	{ 0xb2d4a8fd, "ieee80211_wme_updateparams" },
	{ 0x26c2e5e6, "ieee80211_vap_attach" },
	{ 0xa46dc984, "_spin_unlock_irqrestore" },
	{ 0x9545af6d, "tasklet_init" },
	{ 0xa1c9f3d, "mod_timer" },
	{ 0xd4ffa6d7, "ieee80211_iterate_nodes" },
	{ 0x9eac042a, "__ioremap" },
	{ 0xf0f39c7, "ieee80211_getcfframe" },
	{ 0xb1444669, "dma_alloc_coherent" },
	{ 0x89b171aa, "ieee80211_beacon_alloc" },
	{ 0x5788192c, "ieee80211_beacon_miss" },
	{ 0x8ce46225, "ieee80211_media_change" },
	{ 0x144dae77, "ieee80211_skb_untrack" },
	{ 0xb31b1dd0, "ath_debug_global" },
	{ 0xa8df8055, "skb_over_panic" },
	{ 0x7dceceac, "capable" },
	{ 0xbdafff5c, "ieee80211_crypto_delkey" },
	{ 0x1ff2338a, "_ath_hal_detach" },
	{ 0xfb306753, "kmem_cache_alloc" },
	{ 0xed633abc, "pv_irq_ops" },
	{ 0x614b94a5, "__alloc_skb" },
	{ 0x8671d219, "ieee80211_cipher_none" },
	{ 0x97b658e3, "pci_bus_read_config_dword" },
	{ 0xa1df8cf2, "unregister_sysctl_table" },
	{ 0x107d6ba3, "__get_free_pages" },
	{ 0x3bd1b1f6, "msecs_to_jiffies" },
	{ 0xa462748b, "alloc_netdev_mq" },
	{ 0x2cf190e3, "request_irq" },
	{ 0x9c6c66a3, "ieee80211_stop_running" },
	{ 0x6b2dc060, "dump_stack" },
	{ 0xf247df2c, "ath_hal_mhz2ieee" },
	{ 0x20c586be, "ieee80211_dev_alloc_skb" },
	{ 0x7929da6a, "ieee80211_ioctl_create_vap" },
	{ 0xe96c91fe, "ieee80211_dump_pkt" },
	{ 0xef79ac56, "__release_region" },
	{ 0xa611fb46, "pci_unregister_driver" },
	{ 0xadf8da06, "ether_setup" },
	{ 0x13302835, "ieee80211_crypto_setkey" },
	{ 0xffd3c7, "init_waitqueue_head" },
	{ 0x679a54f2, "init_timer" },
	{ 0x8785725d, "param_set_charp" },
	{ 0x76768039, "pci_set_power_state" },
	{ 0x487f9163, "ieee80211_crypto_newkey" },
	{ 0x72270e35, "do_gettimeofday" },
	{ 0xbf00f7ed, "pci_bus_write_config_byte" },
	{ 0x112cf2a6, "ath_hal_computetxtime" },
	{ 0x37a0cba, "kfree" },
	{ 0xf8b0ac33, "ieee80211_unref_node" },
	{ 0x801678, "flush_scheduled_work" },
	{ 0x2d05d253, "ieee80211_dev_kfree_skb" },
	{ 0x6ba1cbc8, "ieee80211_input_monitor" },
	{ 0xedc03953, "iounmap" },
	{ 0x283939d, "__pci_register_driver" },
	{ 0x2a4096a9, "ieee80211_ifdetach" },
	{ 0xd8184020, "ieee80211_vap_setup" },
	{ 0x60a4461c, "__up_wakeup" },
	{ 0xc42dadb, "ieee80211_ref_node" },
	{ 0xf37f4b5a, "unregister_netdev" },
	{ 0x1b9a4b33, "ieee80211_dev_kfree_skb_list" },
	{ 0x6571fb75, "ieee80211_skb_track" },
	{ 0x25da070, "snprintf" },
	{ 0x79c45aa6, "__netif_schedule" },
	{ 0x8235805b, "memmove" },
	{ 0xf0cdaa65, "ieee80211_find_rxnode" },
	{ 0x4a5c7765, "ath_hal_process_noisefloor" },
	{ 0x96b27088, "__down_failed" },
	{ 0x908aa9b2, "iowrite32" },
	{ 0x24bd10b8, "ieee80211_beacon_update" },
	{ 0x8b939a4a, "pci_enable_device" },
	{ 0xd6c963c, "copy_from_user" },
	{ 0x24541f7, "_ath_hal_attach" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0x6db8adf5, "ieee80211_ifattach" },
	{ 0x2241a928, "ioread32" },
	{ 0x820d5e00, "ieee80211_input" },
	{ 0xf20dabd8, "free_irq" },
	{ 0xc2c2b329, "pci_save_state" },
	{ 0x70b459c, "ieee80211_encap" },
	{ 0xe914e41e, "strcpy" },
	{ 0x3f606453, "ieee80211_check_mic" },
};

static const char __module_depends[]
__attribute_used__
__attribute__((section(".modinfo"))) =
"depends=ath_hal,wlan";

MODULE_ALIAS("pci:v0000168Cd00000007sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000012sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000013sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000A727d00000013sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010B7d00000013sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00001014sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd0000101Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000015sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000016sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000017sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000018sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000019sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd0000001Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd0000001Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd0000001Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd0000001Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000023sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000024sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00009013sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "7CF0ED0BD3288F1E04BD0D3");

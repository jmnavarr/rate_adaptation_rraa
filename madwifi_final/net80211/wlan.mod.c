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
	{ 0x8ddcd133, "register_netdevice" },
	{ 0xab807860, "kmalloc_caches" },
	{ 0x12da5bb2, "__kmalloc" },
	{ 0x4b2f14b4, "jiffies_to_timespec" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0x3df7a759, "unregister_netdevice" },
	{ 0x349cba85, "strchr" },
	{ 0xb7670d1a, "register_sysctl_table" },
	{ 0x98b1f5e8, "del_timer" },
	{ 0xd0d8621b, "strlen" },
	{ 0x79aa04a2, "get_random_bytes" },
	{ 0x1a170d21, "proc_dointvec" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x7f5c5d86, "netif_carrier_on" },
	{ 0xc1d68d68, "skb_copy" },
	{ 0x63ecad53, "register_netdevice_notifier" },
	{ 0xacd1aa1f, "netif_carrier_off" },
	{ 0xb7e4fb5c, "remove_proc_entry" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x2fd1d81c, "vfree" },
	{ 0x6e185827, "_spin_lock_irqsave" },
	{ 0x1d26aa98, "sprintf" },
	{ 0x97dc9049, "skb_realloc_headroom" },
	{ 0x78e6e3df, "sysfs_remove_group" },
	{ 0x7d11c268, "jiffies" },
	{ 0xfe769456, "unregister_netdevice_notifier" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x6379457b, "netif_rx" },
	{ 0x518eb764, "per_cpu__cpu_number" },
	{ 0x2bc95bd4, "memset" },
	{ 0xa0cc4195, "proc_mkdir" },
	{ 0x37befc70, "jiffies_to_msecs" },
	{ 0x1b7d4074, "printk" },
	{ 0xb24b42d, "sysfs_create_group" },
	{ 0x1075bf0, "panic" },
	{ 0x8f5087ef, "free_netdev" },
	{ 0x795340bb, "__tasklet_schedule" },
	{ 0x2f287f0d, "copy_to_user" },
	{ 0xb6ed1e53, "strncpy" },
	{ 0x29057745, "wireless_send_event" },
	{ 0x6c2e3320, "strncmp" },
	{ 0x75c93a05, "dev_close" },
	{ 0xa46dc984, "_spin_unlock_irqrestore" },
	{ 0x9545af6d, "tasklet_init" },
	{ 0xa1c9f3d, "mod_timer" },
	{ 0x787880e5, "init_net" },
	{ 0x6dbd894a, "dev_kfree_skb_any" },
	{ 0x46c5f5e5, "proc_dostring" },
	{ 0x52068558, "dev_open" },
	{ 0x61651be, "strcat" },
	{ 0x82072614, "tasklet_kill" },
	{ 0xa8df8055, "skb_over_panic" },
	{ 0x610acedf, "module_put" },
	{ 0x7dceceac, "capable" },
	{ 0x1ba318fa, "skb_copy_expand" },
	{ 0xfb306753, "kmem_cache_alloc" },
	{ 0x614b94a5, "__alloc_skb" },
	{ 0xa1df8cf2, "unregister_sysctl_table" },
	{ 0x3bd1b1f6, "msecs_to_jiffies" },
	{ 0x4292364c, "schedule" },
	{ 0xf42ed654, "kfree_skb" },
	{ 0x6b2dc060, "dump_stack" },
	{ 0x8236592a, "skb_under_panic" },
	{ 0x8680f95d, "create_proc_entry" },
	{ 0xcb31dbe9, "pskb_expand_head" },
	{ 0x679a54f2, "init_timer" },
	{ 0x6989a769, "vsnprintf" },
	{ 0x72270e35, "do_gettimeofday" },
	{ 0xb1cb1056, "_spin_unlock_bh" },
	{ 0x37a0cba, "kfree" },
	{ 0x98adfde2, "request_module" },
	{ 0x2d950fd, "dev_alloc_name" },
	{ 0x25da070, "snprintf" },
	{ 0x8235805b, "memmove" },
	{ 0xfcf4e5db, "dev_queue_xmit" },
	{ 0xe18ae1a, "_spin_lock_bh" },
	{ 0xd6c963c, "copy_from_user" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0xe914e41e, "strcpy" },
};

static const char __module_depends[]
__attribute_used__
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "4F523C44D94300983FFF9E9");

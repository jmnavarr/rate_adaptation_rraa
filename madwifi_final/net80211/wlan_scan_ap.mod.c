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
	{ 0xab807860, "kmalloc_caches" },
	{ 0x2a680bfc, "ieee80211_scanner_unregister_all" },
	{ 0xc8be7b15, "_spin_lock" },
	{ 0x2c1b6439, "ieee80211_saveie" },
	{ 0xb58748ba, "ieee80211_chan2ieee" },
	{ 0xba9e5e19, "ieee80211_scanner_register" },
	{ 0x6e185827, "_spin_lock_irqsave" },
	{ 0x7d11c268, "jiffies" },
	{ 0x518eb764, "per_cpu__cpu_number" },
	{ 0x1b7d4074, "printk" },
	{ 0x795340bb, "__tasklet_schedule" },
	{ 0x6c2e3320, "strncmp" },
	{ 0xa46dc984, "_spin_unlock_irqrestore" },
	{ 0x9545af6d, "tasklet_init" },
	{ 0x310917fe, "sort" },
	{ 0x82072614, "tasklet_kill" },
	{ 0x610acedf, "module_put" },
	{ 0xfb306753, "kmem_cache_alloc" },
	{ 0x6c96e14d, "ieee80211_note" },
	{ 0x54427412, "ieee80211_create_ibss" },
	{ 0x3bd1b1f6, "msecs_to_jiffies" },
	{ 0x2af848cd, "ieee80211_scan_dump_channels" },
	{ 0x37a0cba, "kfree" },
	{ 0x2e60bace, "memcpy" },
	{ 0x7a06654e, "ieee80211_find_channel" },
};

static const char __module_depends[]
__attribute_used__
__attribute__((section(".modinfo"))) =
"depends=wlan";


MODULE_INFO(srcversion, "62021A1C323AD6E6C08AE61");

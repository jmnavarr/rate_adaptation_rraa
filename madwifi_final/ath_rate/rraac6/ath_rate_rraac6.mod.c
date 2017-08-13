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
	{ 0x518eb764, "per_cpu__cpu_number" },
	{ 0x18f0d5ca, "ieee80211_rate_register" },
	{ 0x1b7d4074, "printk" },
	{ 0xfee0463e, "ieee80211_rate_unregister" },
	{ 0xd4ffa6d7, "ieee80211_iterate_nodes" },
	{ 0x610acedf, "module_put" },
	{ 0xfb306753, "kmem_cache_alloc" },
	{ 0xa1df8cf2, "unregister_sysctl_table" },
	{ 0x37a0cba, "kfree" },
};

static const char __module_depends[]
__attribute_used__
__attribute__((section(".modinfo"))) =
"depends=wlan";


MODULE_INFO(srcversion, "A190BBBDC15277443ABC8C9");

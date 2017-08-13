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
	{ 0xc8be7b15, "_spin_lock" },
	{ 0x518eb764, "per_cpu__cpu_number" },
	{ 0x1b7d4074, "printk" },
	{ 0x610acedf, "module_put" },
	{ 0xfb306753, "kmem_cache_alloc" },
	{ 0x6c96e14d, "ieee80211_note" },
	{ 0xe162c75e, "ieee80211_aclator_register" },
	{ 0x37a0cba, "kfree" },
	{ 0x4253791e, "ieee80211_aclator_unregister" },
};

static const char __module_depends[]
__attribute_used__
__attribute__((section(".modinfo"))) =
"depends=wlan";


MODULE_INFO(srcversion, "DB5DC38665FFC920658D99A");

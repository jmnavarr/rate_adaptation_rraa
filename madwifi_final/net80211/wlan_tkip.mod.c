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
	{ 0x350d3c4f, "ieee80211_crypto_register" },
	{ 0x2ec5f316, "ieee80211_notify_replay_failure" },
	{ 0x518eb764, "per_cpu__cpu_number" },
	{ 0xfa2a4702, "ieee80211_note_mac" },
	{ 0x1b7d4074, "printk" },
	{ 0xa8df8055, "skb_over_panic" },
	{ 0x610acedf, "module_put" },
	{ 0xfb306753, "kmem_cache_alloc" },
	{ 0x6c96e14d, "ieee80211_note" },
	{ 0x6b2dc060, "dump_stack" },
	{ 0x8236592a, "skb_under_panic" },
	{ 0x1c269f03, "ieee80211_crypto_unregister" },
	{ 0x2af6d9e6, "ieee80211_notify_michael_failure" },
	{ 0x37a0cba, "kfree" },
	{ 0x8235805b, "memmove" },
};

static const char __module_depends[]
__attribute_used__
__attribute__((section(".modinfo"))) =
"depends=wlan";


MODULE_INFO(srcversion, "B1C46601DF1F85364929AFE");

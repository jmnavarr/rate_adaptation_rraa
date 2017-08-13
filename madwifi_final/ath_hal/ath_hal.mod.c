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
	{ 0x12da5bb2, "__kmalloc" },
	{ 0xb7670d1a, "register_sysctl_table" },
	{ 0xd0d8621b, "strlen" },
	{ 0x1a170d21, "proc_dointvec" },
	{ 0x518eb764, "per_cpu__cpu_number" },
	{ 0x1b7d4074, "printk" },
	{ 0x6c2e3320, "strncmp" },
	{ 0x610acedf, "module_put" },
	{ 0xa1df8cf2, "unregister_sysctl_table" },
	{ 0x6989a769, "vsnprintf" },
	{ 0x37a0cba, "kfree" },
	{ 0x25da070, "snprintf" },
	{ 0x9e7d6bd0, "__udelay" },
};

static const char __module_depends[]
__attribute_used__
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "50BCD94E950C8155A6ABB57");

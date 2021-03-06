#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("atwlam");
MODULE_DESCRIPTION("Hello World");

static int __init hello1(void)
{
	pr_debug("Hello World!\n");
	return 0;
}

static void __exit exit1(void)
{
	pr_debug("Good Bye!\n");
}

module_init(hello1);
module_exit(exit1);

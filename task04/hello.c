#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("atwlam");
MODULE_DESCRIPTION("Hello World");

static int __init hello1(void)
{
	printk(netdev_dbg "Hello World!\n");
	return 0;
}

static void __exit exit1(void)
{
	printk(netdev_dbg "Good Bye!\n");
}

module_init(hello1);
module_exit(exit1);

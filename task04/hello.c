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
	printk(netdev_info "Hello World!\n");
                printk(KERN_INFO "We slept a long time!");

	return 0;
}

static void __exit exit1(void)
{
	printk(KERN_INFo "Good Bye!\n");
}

module_init(hello1);
module_exit(exit1);

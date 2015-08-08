#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("atwlam");
MODULE_DESCRIPTION("Hello World");

static struct usb_device_id skel_table[] = {
	/* { USB_DEVICE(USB_SKEL_VENDOR_ID, USB_SKEL_PRODUCT_ID) }, */
	{ }	/* Terminating entry */
};
MODULE_DEVICE_TABLE(usb, skel_table);

static struct usb_driver skel_driver = {
	.name		= "skeleton",
	/* .probe		= skel_probe, */
	/* .disconnect	= skel_disconnect, */
	/* .fops		= &skel_fops, */
	/* .minor		= USB_SKEL_MINOR_BASE, */
	.id_table	= skel_table,
};

static int __init hello1(void)
{
	pr_debug("Hello World!\n");
	usb_register(&skel_driver);
	return 0;
}
module_init(hello1);

static void __exit exit1(void)
{
	pr_debug("Good Bye!\n");
	usb_deregister(&skel_driver);
}
module_exit(exit1);



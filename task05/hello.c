#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/slab.h>
#include <linux/usb/input.h>
#include <linux/hid.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("atwlam");
MODULE_DESCRIPTION("Hello World");

static struct usb_device_id skel_table[] = {
	{ USB_INTERFACE_INFO(USB_INTERFACE_CLASS_HID,
		USB_INTERFACE_SUBCLASS_BOOT,
		USB_INTERFACE_PROTOCOL_KEYBOARD) },
	{ }	/* Terminating entry */
};
MODULE_DEVICE_TABLE(usb, skel_table);

static int __init hello1(void)
{
	pr_debug("Hello World!\n");

	return 0;
}
module_init(hello1);

static void __exit exit1(void)
{
	pr_debug("Good Bye!\n");
}
module_exit(exit1);


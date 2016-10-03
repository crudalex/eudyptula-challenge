#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/uaccess.h>
#include <linux/usb.h>

#define VENDOR_ID	0x03f0
#define PRODUCT_ID	0x0324

static struct usb_device_id id_table [] = { { USB_DEVICE(VENDOR_ID, PRODUCT_ID) }, { } };
MODULE_DEVICE_TABLE (usb, id_table);
int hotplug_probe (struct usb_interface *intf, const struct usb_device_id *id) { return 0; }
void hotplug_disconnect (struct usb_interface *intf) { }

static struct usb_driver hotplug_driver = {
	// .owner =	THIS_MODULE,
	.name =		"hotplug",
	.probe =	hotplug_probe,
	.disconnect =	hotplug_disconnect,
	.id_table =	id_table,
};


static int __init init1(void)
{
	int retval; 
	
	retval = usb_register(&hotplug_driver);
	if (retval)
		pr_err("usb_register failed. Error number %d", retval);

	pr_info("Module registered\n");
	return 0;
}

static void __exit exit1(void)
{
	pr_info("Module deregistered\n");
}

module_init(init1);
module_exit(exit1);

MODULE_DESCRIPTION("Hotplug device");
MODULE_AUTHOR("atwlam");
MODULE_LICENSE("GPL");

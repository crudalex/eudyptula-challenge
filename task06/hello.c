#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/uaccess.h>

static ssize_t sample_read(struct file *file, char *buf,
size_t len, loff_t *ppos)
{
	int slen;
	int ret;
	const char *str = "hello world\n"; 

	slen = strlen(str);
	if (*ppos > slen){
		return 0; 
	}

	if (*ppos + len > slen){
		len = slen - *ppos; 
	} 

	ret =  copy_to_user(buf, str + *ppos, len); 
	return ret; 
}

static ssize_t sample_write(struct file *file, const char *buf,
size_t len, loff_t *ppos)
{
	return 0;

}

static const struct file_operations sample_fops = {
	.owner			= THIS_MODULE,
	.read			= sample_read,
	.write			= sample_write,
};

struct miscdevice sample_device = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "eudyptula",
	.fops = &sample_fops,
};

static int __init misc_init(void)
{
	int error;

	error = misc_register(&sample_device);
	if (error) {
		pr_err("can't misc_register :(\n");
		return error;
	}

	return 0;
}

static void __exit misc_exit(void)
{
	misc_deregister(&sample_device);
	pr_info("I'm out\n");
}

module_init(misc_init)
module_exit(misc_exit)

MODULE_DESCRIPTION("atwlam");
MODULE_AUTHOR("atwlam");
MODULE_LICENSE("GPL");

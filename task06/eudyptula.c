#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
static struct miscdevice eudyptula_dev;
// static long assigned_id;
// assigned_id = 919705445944;
// static const char assigned_id[] = "919705445944";
static const long assigned_id = 919705445944;

int eudyptula_open(struct inode *inode, struct file *filp) { return 0; }

static ssize_t eudyptula_read(struct file *file, char __user *user,
			size_t count, loff_t *offset) {
	pr_info("%ld\n", assigned_id);
	return 0;
}
static ssize_t eudyptula_write(struct file *file, const char __user *user,
			size_t count, loff_t *offset){

	char buf[count];
	// int input;
	long id;

	if (copy_from_user(buf, user, count))
		return -EFAULT;
	buf[count] = '\0';

	if (kstrtol(buf, 0, &id))
		return -EINVAL;

	// kstrtoint(buf, 10, &input);
	// pr_info("%s\n", buf);
	// if (strcmp(buf, assigned_id) != 0) {
	if (id != assigned_id) {
		pr_err("invalid write: assigned_id = %ld, input_id = %ld\n",
			assigned_id, id);
		return -EFAULT;
	}

	pr_info("correct write\n");
	// printk(KERN_INFO, "correct write\n");
	return count;
}

const struct file_operations eudyptula_fops = {
	.owner = THIS_MODULE,
	.read = eudyptula_read,
	.write = eudyptula_write,
	.open = eudyptula_open,
	// .release = eudyptula_close,
};

static int __init init1(void)
{
	// int misc_register(struct miscdevice * misc);

	int retval;

	eudyptula_dev.minor = MISC_DYNAMIC_MINOR;
	eudyptula_dev.name = "eudyptula";
	eudyptula_dev.fops = &eudyptula_fops;

	retval = misc_register(&eudyptula_dev);
	if (retval)
		return retval;

	pr_info("Module registered\n");
	return 0;
}

static void __exit exit1(void)
{
	// int misc_deregister(struct miscdevice * misc);

	// int retval;
	// retval = misc_deregister(&eudyptula_dev);
	misc_deregister(&eudyptula_dev);
	pr_info("Module deregistered\n");
}

module_init(init1);
module_exit(exit1);

MODULE_DESCRIPTION("Misc character device");
MODULE_AUTHOR("atwlam");
MODULE_LICENSE("GPL");

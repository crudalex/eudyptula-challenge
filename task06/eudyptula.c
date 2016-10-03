#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
static struct miscdevice eudy_dev;
// static long assigned_id;
// assigned_id = 919705445944;
// static const char assigned_id[] = "919705445944";
static const long assigned_id = 919705445944;

int eudy_open(struct inode *inode, struct file *filp) { return 0; }
ssize_t eudy_read(struct file *file, char __user *user,
			size_t count, loff_t *offset) {
	pr_info("%ld\n", assigned_id);
	return 0;
}
ssize_t eudy_write(struct file *file, const char __user *user,
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

const struct file_operations eudy_fops = {
	.owner = THIS_MODULE,
	.read = eudy_read,
	.write = eudy_write,
	.open = eudy_open,
	// .release = eudy_close,
};

static int __init init1(void)
{
	// int misc_register(struct miscdevice * misc);

	int retval;

	eudy_dev.minor = MISC_DYNAMIC_MINOR;
	eudy_dev.name = "eudyptula";
	eudy_dev.fops = &eudy_fops;

	retval = misc_register(&eudy_dev);
	if (retval)
		return retval;

	pr_info("Module registered\n");
	return 0;
}

static void __exit exit1(void)
{
	// int misc_deregister(struct miscdevice * misc);

	// int retval;
	// retval = misc_deregister(&eudy_dev);
	misc_deregister(&eudy_dev);
	pr_info("Module deregistered\n");
}

module_init(init1);
module_exit(exit1);

MODULE_DESCRIPTION("Misc character device");
MODULE_AUTHOR("atwlam");
MODULE_LICENSE("GPL");

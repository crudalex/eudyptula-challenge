#include <linux/module.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/poll.h>
#include <linux/errno.h>

#define MY_ID "919705445944"
#define MY_ID_LEN 13	/* ID length including the final NULL */

static ssize_t eudyptula_read(struct file *file, char __user *buf,
			size_t count, loff_t *ppos)
{
	char *eudyptula_str = MY_ID;

	if (*ppos != 0)
		return 0;

	if ((count < MY_ID_LEN) ||
		(copy_to_user(buf, eudyptula_str, MY_ID_LEN)))
		return -EINVAL;

	*ppos += count;
	return count;
}

static ssize_t eudyptula_write(struct file *file, char const __user *buf,
			size_t count, loff_t *ppos)
{
	char *eudyptula_str = MY_ID;
	char input[MY_ID_LEN];

	if ((count != MY_ID_LEN) ||
		(copy_from_user(input, buf, MY_ID_LEN)) ||
		(strncmp(eudyptula_str, input, MY_ID_LEN - 1)))
		return -EINVAL;
	else
		return count;
}

static const struct file_operations eudyptula_fops = {
	.owner = THIS_MODULE,
	.read = eudyptula_read,
	.write = eudyptula_write
};

static struct miscdevice eudyptula_dev = {
	MISC_DYNAMIC_MINOR,
	"eudyptula",
	&eudyptula_fops
};

static int __init eudyptula_init(void)
{
	int ret;

	ret = misc_register(&eudyptula_dev);
	pr_debug("Hello World!\n");

	return ret;
}

static void __exit eudyptula_exit(void)
{
	misc_deregister(&eudyptula_dev);
}

module_init(eudyptula_init);
module_exit(eudyptula_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("919705445944");
MODULE_DESCRIPTION("Misc char eudyptula module");


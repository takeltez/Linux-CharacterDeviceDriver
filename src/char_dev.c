#include "char_dev.h"

int char_dev_open(struct inode *pinode, struct file *pfile)
{
	printk(KERN_ALERT "Function %s is being executed\n", __FUNCTION__);

	return 0;
}

ssize_t char_dev_read(struct file *pfile, char __user *buffer, size_t length, loff_t *offest)
{
	printk(KERN_ALERT "Function %s is being executed\n", __FUNCTION__);

	return 0;
}

ssize_t char_dev_write(struct file *pfile, const char __user *buffer, size_t length, loff_t *offest)
{
	printk(KERN_ALERT "Function %s is being executed\n", __FUNCTION__);

	return length;
}

int char_dev_release(struct inode *pinode, struct file *pfile)
{
	printk(KERN_ALERT "Function %s is being executed\n", __FUNCTION__);

	return 0;
}

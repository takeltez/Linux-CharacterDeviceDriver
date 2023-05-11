#include "char_dev.h"

char k_buf[100];

int payload_length(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++);

	return i + 1;
}

int char_dev_open(struct inode *pinode, struct file *pfile)
{
	printk(KERN_INFO "Function %s is being executed\n", __FUNCTION__);

	return 0;
}

ssize_t char_dev_read(struct file *pfile, char __user *buffer, size_t length, loff_t *offest)
{
	printk(KERN_INFO "Function %s is being executed\n", __FUNCTION__);

	int len = payload_length(k_buf);

	if (*offest > 0)
	{
		return 0;
	}

	if (copy_to_user(buffer, k_buf, len))
	{
		printk(KERN_ERR "copy_to_user failed!\n");

		return -EFAULT;
	}

	printk(KERN_INFO "%ld bytes were successfully sent to user: %s\n", len, k_buf);

	*offest += len;

	return len;
}

ssize_t char_dev_write(struct file *pfile, const char __user *buffer, size_t length, loff_t *offest)
{
	printk(KERN_INFO "Function %s is being executed\n", __FUNCTION__);


	if (copy_from_user(k_buf, buffer, length))
	{
		printk(KERN_ERR "copy_from_user failed!\n");

		return -EFAULT;
	}

	k_buf[length] = '\0';

	printk(KERN_INFO "%ld bytes were successfully read from user: %s\n", length, k_buf);

	return length;
}

int char_dev_release(struct inode *pinode, struct file *pfile)
{
	printk(KERN_INFO "Function %s is being executed\n", __FUNCTION__);

	return 0;
}

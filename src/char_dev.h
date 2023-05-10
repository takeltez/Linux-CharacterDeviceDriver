#ifndef CHAR_DEV_H
#define CHAR_DEV_H

#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Aleksei Karasev");
MODULE_DESCRIPTION("Character device driver: char_dev_ops");

int char_dev_open(struct inode *pinode, struct file *pfile);

int char_dev_release(struct inode *pinode, struct file *pfile);

ssize_t char_dev_read(struct file *pfile, char __user *buffer, size_t length, loff_t *offest);

ssize_t char_dev_write(struct file *pfile, const char __user *buffer, size_t length, loff_t *offest);

#endif

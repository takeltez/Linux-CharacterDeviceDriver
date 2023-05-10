#include "char_dev.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Aleksei Karasev");
MODULE_DESCRIPTION("Character device driver");

struct file_operations char_dev_ops = {
	.owner = THIS_MODULE,
	.open = char_dev_open,
	.read = char_dev_read,
	.write = char_dev_write,
	.release = char_dev_release,
};

static int __init module_upload(void)
{
	printk(KERN_ALERT "Function %s is being executed\n", __FUNCTION__);

	register_chrdev(255, "char_dev", &char_dev_ops);

	return 0;
}

static void __exit module_extract(void)
{
	printk(KERN_ALERT "Function %s is being executed\n", __FUNCTION__);

	unregister_chrdev(255, "char_dev");
}

module_init(module_upload);
module_exit(module_extract);

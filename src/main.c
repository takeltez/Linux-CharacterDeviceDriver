#include "char_dev.h"

struct file_operations char_dev_ops = {
	.owner = THIS_MODULE,
	.open = char_dev_open,
	.read = char_dev_read,
	.write = char_dev_write,
	.release = char_dev_release,
};

static int __init char_driver_load(void)
{
	printk(KERN_INFO "Function %s is being executed\n", __FUNCTION__);

	register_chrdev(255, "char_dev", &char_dev_ops);

	return 0;
}

static void __exit char_driver_remove(void)
{
	printk(KERN_INFO "Function %s is being executed\n", __FUNCTION__);

	unregister_chrdev(255, "char_dev");
}

module_init(char_driver_load);
module_exit(char_driver_remove);

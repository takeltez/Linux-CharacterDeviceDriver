#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Aleksei Karasev");
MODULE_DESCRIPTION("Character device driver");

static int __init module_upload(void)
{
	printk(KERN_ALERT "Function %s is being executed\n", __FUNCTION__);

	return 0;
}

static void __exit module_extract(void)
{
	printk(KERN_ALERT "Function %s is being executed\n", __FUNCTION__);
}

module_init(module_upload);
module_exit(module_extract);

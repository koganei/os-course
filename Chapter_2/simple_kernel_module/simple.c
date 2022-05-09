#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

int on_module_load(void) {
    printk(KERN_INFO "Loading Module\n");
    return 0;
}

void on_module_exit(void) {
    printk(KERN_INFO "Removing Module\n");
}

module_init(on_module_load);
module_exit(on_module_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("Koganei");
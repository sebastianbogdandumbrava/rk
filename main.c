#include <linux/module.h>
#include <linux/slab.h>

#ifndef for_each_process
#include <linux/sched/signal.h>
#endif







int rk_init(void);
void rk_exit(void);


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


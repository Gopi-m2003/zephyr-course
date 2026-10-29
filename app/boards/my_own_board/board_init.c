/* SPDX-License-Identifier: Apache-2.0 */

#include <zephyr/init.h>
#include <zephyr/kernel.h>

static int board_init(void)
{
    printk("Board Initialized by gopi\n");
    return 0;
}

//SYS_INIT(board_init, PRE_KERNEL_1, 50);
//PRE_KERNEL_1 runs very early, before the console is initialized. Therefore, printk() may execute without its output being visible.
SYS_INIT(board_init, APPLICATION, 50);

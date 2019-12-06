#ifndef _PAGING_KERN_H
#define _PAGING_KERN_H

#include <stdint.h>

uint64_t page_dir_ptr_tab[4] __attribute__((aligned(0x20)));

uint64_t page_dir[512] __attribute__((aligned(0x1000)));
uint64_t page_tab[512] __attribute__((aligned(0x1000)));

void mapTables();
void paging_init();

#endif
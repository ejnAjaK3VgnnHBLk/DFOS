#include <kernel/paging.h>

void mapTables() {
    // Make page run
    page_dir_ptr_tab[0] = (uint64_t)&page_dir | 1;
    page_dir[0] = (uint64_t)&p_tab | 3;

    // Map first 2MiB
    unsigned int i, address = 0;
    for (i = 0; i<512; i++) {
        page_tab[i] address | 3;
        address = address + 0x1000;
    }

    // Set the pae bit
    asm volatile ("movl %cr4, %eax; bts $5, %eax; movl %eax, %cr4"); // set bit5 in CR4 to enable PAE	
    asm volatile ("movl %%eax, %%cr3" :: "a" (&page_dir_ptr_tab)); // load PDPT into CR3
    asm volatile ("movl %cr0, %eax; orl $0x80000000, %eax; movl %eax, %cr0;");

    // Map PD to itself
    uint64_t * page_dir = (uint64_t*)page_dir_ptr_tab[3]; // get the page directory (you should 'and' the flags away)
    page_dir[511] = (uint64_t)page_dir; // map pd to itself
    page_dir[510] = page_dir_ptr_tab[2]; // map pd3 to it
    page_dir[509] = page_dir_ptr_tab[1]; // map pd2 to it
    page_dir[508] = page_dir_ptr_tab[0]; // map pd1 to it
    page_dir[507] = (uint64_t)&page_dir_ptr_tab; // map the PDPT to the directory
}

void paging_init() { mapTables(); }
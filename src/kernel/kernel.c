#include "kernel.h"
#include "../drivers/disk/disk.h"
#include "../drivers/disk/disk_stream.h"
#include "../drivers/screen/terminal.h"
#include "../drivers/screen/vga.h"
#include "../file_system/file.h"
#include "../libc/stdio/stdio.h"
#include "../libc/stdlib/stdlib.h"
#include "../libc/string/string.h"
#include "./memory/paging/page.h"
#include "ascii/ascii.h"
#include "idt/idt.h"
#include "kmem/kheap.h"
#include <stdint.h>

// TODO: READ.ME and all TODOs

static struct page_dir *system_page_dir = 0;

void
kernel_main (void)
{
  uint8_t verbose = 0;
  terminal_init (verbose);
  idt_init (verbose);
  kernel_heap_init (verbose);
  file_system_init (verbose);
  system_page_dir = page_dir_init (IS_WRITABLE | IS_PRESENT | ACCESS_ALL);
  // tell processor where to find entry of system page directory
  switch_page_dir (system_page_dir->dir_entry);
  // initialize paging for virtual memory and full system memory coverage
  enable_system_paging (verbose);
  init_main_master_disk (verbose);
  enable_interrupts (verbose);
  if (verbose)
    {
      moose ("VERSION 0.06 everything looks OK", light_magenta);
    }
  struct disk_t *d = get_disk (0);
  char *buff[512];
  disk_read_block (d, 0, 1, buff);
}

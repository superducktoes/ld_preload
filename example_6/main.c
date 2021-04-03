#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
    const char *msg = "Hello write\n";
    // 1 writes to stdout file descriptor
    write(1, msg, strlen(msg));
    return 0;
}


  

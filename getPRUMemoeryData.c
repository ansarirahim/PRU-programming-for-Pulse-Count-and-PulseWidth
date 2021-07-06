#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>
#include <ctype.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <stdint.h>
//#include <pru_cfg.h>
//#include <pru_ctrl.h>
//#include "resource_table_empty.h"
#include <stdlib.h>
#define MAP_SIZE 4096UL
#define MAP_MASK (MAP_SIZE - 1)


void displayDistance(unsigned int raw_distance){
   float distin = ((float)raw_distance / (100 * 148));
   float distcm = ((float)raw_distance / (100 * 58));
   printf("Distance is %f inches (%f cm)             \r", distin, distcm);
}

#define PRU0_DRAM   0x00000
volatile unsigned int *shared = (unsigned int *)(PRU0_DRAM);

int main(int argc, char **argv) {
    int fd, i, j;
int y;
    void *map_base, *virt_addr;
    unsigned long read_result, writeval;
    unsigned int numberOutputSamples = 2;
    off_t target = 0x4a300008;  if((fd = open("/dev/mem", O_RDWR | O_SYNC)) == -1){
        printf("Failed to open memory!\n");
        return -1;
    }
    fflush(stdout);

    map_base = mmap(0, MAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, target & ~MAP_MASK);
    if(map_base == (void *) -1) {
       printf("Failed to map base address\n");
       return -1;
    }
    fflush(stdout);

    for(j=0; j<1000; j++){
       for(i=0; i<numberOutputSamples; i++){
           virt_addr = map_base + (target & MAP_MASK);
           read_result = *((unsigned long *) virt_addr);
  printf("\nValue at address 0x%X is: 0x%X\n", target, read_result);
 printf("\nNew =0x%X",*((unsigned long *) virt_addr+y));//ansari

//           displayDistance((unsigned int)read_result);
           usleep(500000);
       }
       fflush(stdout);
    }

    if(munmap(map_base, MAP_SIZE) == -1) {
       printf("Failed to unmap memory");
       return -1;
    }
    close(fd);
    return 0;
}


y=atoi(argv[1]);//

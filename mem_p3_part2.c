#include <stdio.h>
#include <stdlib.h>
#include "pagetable.h"
#include "phyframe.h"

int main(int argc, char *argv[]){
  int page_faults = 0;
  int table_size = 8;
  FILE *input_file = fopen(argv[1], "rb");
  unsigned long vAddress;
  while (fread(&vAddress, sizeof(vAddress), 1, input_file) == 1) {
     long pAddress = translateAddress(vAddress, &page_faults);
     printf("0x%lx\n", pAddress); 
   }

   fclose(input_file);
   return 0;
    
}

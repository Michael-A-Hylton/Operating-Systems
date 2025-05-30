#include <stdio.h>
#include <stdlib.h>


int pageTable[7] = {2,4,1,7,3,5,6}; //use this array to hold the mapping for the page table as given


int main(int argc, char *argv[]) {
  int ourPageSize=128; 
  FILE *inputFile = fopen(argv[1], "rb"); //this will read part1test or part1sequence binary
  unsigned long vAddress; 
  while (fread(&vAddress, sizeof(vAddress), 1, inputFile) == 1)  {
  
     unsigned long pageNum=vAddress /ourPageSize; 
     unsigned long offset = vAddress % ourPageSize; //We know that pAddress=frame*size+offset, so we need to calculate which frame and the offset.
     int frame =pageTable[pageNum]; //the page number gives us the correct frame to reference
     unsigned long pAddress = (frame * ourPageSize)+offset;  
     printf("0x%lx\n", pAddress); 
      
  } 
  fclose(inputFile);
  return 0; 
}


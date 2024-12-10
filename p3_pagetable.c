#include <stdio.h>
#include <stdlib.h>
#include "phyframe.h"

int pageTable[7] = {-1};  // Initially, no virtual pages are mapped to physical frames
int reverseMapping[8] = {-1};  

int returnPFrame(long pageNumber) {
    return pageTable[pageNumber];  
}

int handleFault(unsigned long pageNumber) {
    int frame = allocatePFrame();  
    if (frame == -1) {
        frame = evictPFrame();  
    }
    
    // Update page table and reverse mapping
    pageTable[pageNumber] = frame;  
    reverseMapping[frame] = pageNumber;  

    updateLru(pageNumber);  
    return frame;
}

unsigned long translateAddress(unsigned long vAddress, int *pageFaults) {
// Calculate and return the physical address
   unsigned long pageNumber = vAddress / 128;  
   unsigned long offset = vAddress % 128; 
   int pFrame = returnPFrame(pageNumber);  

   if (pFrame == -1) {  // Test for fualts and increment if there is.
       (*pageFaults)++;  
       pFrame = handleFault(pageNumber);  
   }
    
   return (pFrame * 128 + offset);  
}

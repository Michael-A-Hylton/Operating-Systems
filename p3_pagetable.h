// pagetable.h
#ifndef PAGETABLE_H
#define PAGETABLE_H

extern int pageTable[7];  
extern int reverseMapping[8];  

// Function declarations
int returnPFrame(long pageNum);  //
int handleFault(unsigned long pageNum); 
unsigned long translateAddress(unsigned long vAddress, int *pageFaults);  

#endif  // PAGETABLE_H


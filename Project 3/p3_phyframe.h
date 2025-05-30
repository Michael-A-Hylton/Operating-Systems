// phyframe.h
#ifndef PHYFRAME_H
#define PHYFRAME_H

extern int pFrames[8];  
extern int lruTime[8];  

void initializePMemory();  
int allocatePFrame();  
int evictPFrame();  
void updateLru(unsigned long pageNum); 

#endif  // PHYFRAME_H


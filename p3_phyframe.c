#include <stdio.h>
#include <stdlib.h>
#include "pagetable.h"

int pFrames[8] = {0};  // 0 = free, 1 = allocated 
int lruTime[8] = {0};  // Tracks for LRU (Least Recently Used)
int nextFrame = 1;  // Frame 0 is reserved for the OS, so we start allocation from frame 1


// Alllocate a free physical frame
int allocatePFrame() {
    for (int i = 1; i < 8; i++) {  // find free frame and allocate
        if (pFrames[i] == 0) {  
            pFrames[i] = 1;  
            return i;
        }
    }
    return -1;  // If no frames are free, return -1
}

// Evict the least recently used (LRU) physical frame
int evictPFrame() {
    int lruFrame = 0;
    for (int i = 1; i < 8; i++) {
        if (lruTime[i] < lruTime[lruFrame]) {  // Find the LRU frame
            lruFrame = i;
        }
    }

    // Evict the LRU frame
    int pageEvict = reverseMapping[lruFrame];
    pageTable[pageEvict] = -1;  // 
    reverseMapping[lruFrame] = -1;  

    pFrames[lruFrame] = 0;  
    lruTime[lruFrame] = 0;  
    return lruFrame;  
}


void updateLru(unsigned long pageNumber) {
    static int timestamp = 0;  
    lruTime[pageNumber] = timestamp++;  // Increment the timestamp for each access
}

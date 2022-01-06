#pragma once
#define MaximumMemory 10000
#include "HeaderObject.h"
#include "FooterObject.h"

class MemoryPool
{
private:
	void* AllocatedLocations[1000];
	int allocatedSpots;
	void* nextBlockStart;
	MemoryPool();
	void WalkTheHeap();
	static MemoryPool* instance;

public:
	static MemoryPool* GetInstance();
	void* Allocate(size_t sizeOfNewBytes);
	void DeAllocate(void* memoryToClear);
};

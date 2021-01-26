#include "MemoryPool.h"
#include <xmemory>
#include <assert.h>
#include <iostream>

MemoryPool* MemoryPool::instance;

MemoryPool::MemoryPool()	
{
	nextBlockStart = malloc(MaximumMemory);
	AllocatedLocations[0] = nextBlockStart;
	allocatedSpots = 0;
}

void MemoryPool::WalkTheHeap()
{
	for (int i = 0; i < allocatedSpots + 1; i++)
	{
		HeaderObject* header = (HeaderObject*)(char*)AllocatedLocations[i];
		if (header->checkValue != 0xABADBABE)
		{
			assert("Header Value bad when walking heap");
		}

		FooterObject* footer = (FooterObject*)((char*)AllocatedLocations[i]) + sizeof(HeaderObject) + header->size;
		if (footer->checkValue != 0xABADBABE)
		{
			assert("Footer Value bad when walking heap");
		}
	}
}

MemoryPool* MemoryPool::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new MemoryPool();
	}

	return instance;
}

void* MemoryPool::Allocate(size_t sizeOfNewBytes)
{
	std::cout << "Memory Pool Called " << sizeOfNewBytes << "\n";

	// Get Where we are starting
	char* startOfBlock = (char*)nextBlockStart;

	// Construct the header object that represents the start of the memory block
	HeaderObject* header = (HeaderObject*)startOfBlock;
	header->size = sizeOfNewBytes;
	header->checkValue = 0xABADBABE;

	// Construct the footer object that represents the end of the block
	FooterObject* footer = (FooterObject*)startOfBlock + sizeof(HeaderObject) + sizeOfNewBytes;
	footer->checkValue = 0xABADBABE;


	// Walk heap to error check.
	WalkTheHeap();

	// Offset our next location so we don't overwrite memory at any point
	nextBlockStart = (char*)nextBlockStart + (sizeOfNewBytes + sizeof(HeaderObject) + sizeof(FooterObject));
	allocatedSpots += 1;
	AllocatedLocations[allocatedSpots] = nextBlockStart;

	// Return the start of the allocated bytes for this location.
	return startOfBlock + sizeof(header);
}

void MemoryPool::DeAllocate(void* memoryToClear)
{
	HeaderObject* header = (HeaderObject*)(char*)memoryToClear - sizeof(HeaderObject);

	if (header->checkValue != 0xABADBABE)
	{
		assert("Header Value bad when Deallocating Memory");
	}

	FooterObject* footer = (FooterObject*)(char*)memoryToClear + header->size;
	if (footer->checkValue != 0xABADBABE)
	{
		assert("Footer Value bad when Deallocating Memory");
	}

	free(header);
}
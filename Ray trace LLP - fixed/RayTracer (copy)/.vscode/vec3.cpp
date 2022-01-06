#include "vec3.h"
#include "MemoryPool.h"

/*
template<typename T>
void* Vec3<T>::operator new(size_t size)
{
	std::cout << "Allocating " << size << "vec3 class bytes\n";
	return MemoryPool::GetInstance()->Allocate(size);
}

template<typename T>
void Vec3<T>::operator delete(void* p, size_t size)
{
	std::cout << "Freeing " << size << "vec3 class bytes\n";
	MemoryPool::GetInstance()->DeAllocate(p);
}
*/

template<typename T>
void* Vec3<T>::operator new(size_t size)
{
	std::cout << "Allocating " << size << "vec3 class bytes\n";
	return MemoryPool::GetInstance()->Allocate(size);
}

template<typename T>
void Vec3<T>::operator delete(void* p, size_t size)
{
	std::cout << "Freeing " << size << "vec3 class bytes\n";
	MemoryPool::GetInstance()->DeAllocate(p);
}


void* Vec3<float>::operator new(size_t size)
{
	std::cout << "Allocating " << size << "vec3 class bytes\n";
	return MemoryPool::GetInstance()->Allocate(size);
}

void Vec3<float>::operator delete(void* p, size_t size)
{
	std::cout << "Freeing " << size << "vec3 class bytes\n";
	MemoryPool::GetInstance()->DeAllocate(p);
}
#include "sphere.h"
#include "MemoryPool.h"

Sphere::Sphere(float test)
{
	std::cout << "constructor test " << std::endl;
}

void* Sphere::operator new(size_t size)
{
	std::cout << "Allocating " << size << "sphere class bytes\n";
	return MemoryPool::GetInstance()->Allocate(size);
}

void Sphere::operator delete(void* p, size_t size)
{
	std::cout << "Freeing " << size << "sphere class bytes\n";
	MemoryPool::GetInstance()->DeAllocate(p);
}

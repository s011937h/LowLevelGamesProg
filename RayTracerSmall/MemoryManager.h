#pragma once

void * operator new(size_t size);
void operator delete(void * allocated);

class MemoryManager
{
public:
	static MemoryManager& Get();
	void* Allocate(size_t size);
	void Delete(void* allocated);
	void DumpHeap();

	struct Header
	{
		size_t size;
		Header* next;
		Header* previous;
		int magic;
	};

	struct Footer 
	{
		int magic;
	};

	enum magicEnum
	{
		headerMagic = 0xDEADC0DE,
		footerMagic = 0xBADF00D0
	};

	MemoryManager();
	~MemoryManager();
private:
	Header* firstHeader;
	Header* lastHeader;
};


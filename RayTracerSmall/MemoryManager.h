#pragma once

void * operator new(size_t size);
void operator delete(void * allocated);

void* operator new(size_t size, const char * file, int line);
#define NEW new (__FILE__, __LINE__)

class MemoryManager
{
public:
	static MemoryManager& Get();
	void* Allocate(size_t size);
	void* Allocate(size_t size, const char * file, int line);
	void Delete(void* allocated);
	void DumpHeap();

	struct Header
	{
		size_t size;
		Header* next;
		Header* previous;
		const char* file;
		int line;
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

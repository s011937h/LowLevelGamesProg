#include "MemoryManager.h"
#include <memory>
#include <assert.h>

MemoryManager& MemoryManager::Get()
{
	static MemoryManager instance;
	return instance;
}

MemoryManager::MemoryManager()
{
	firstHeader = nullptr;
	lastHeader = nullptr;
}

MemoryManager::~MemoryManager()
{
	if (firstHeader)
		DumpHeap();

	assert(firstHeader == nullptr);
	assert(lastHeader == nullptr);
}

void* operator new(size_t size)
{
	return MemoryManager::Get().Allocate(size);
}


void* operator new(size_t size, const char * file, int line)
{
	return MemoryManager::Get().Allocate(size, file, line);
}

void operator delete(void* allocated)
{
	return MemoryManager::Get().Delete(allocated);
}

void* MemoryManager::Allocate(size_t size)
{
	return Allocate(size, nullptr, -1);
}

void* MemoryManager::Allocate(size_t size, const char * file, int line)
{
	char* allocated = reinterpret_cast<char*>(malloc(size + sizeof(Header) + sizeof(Footer)));
	Header* header = reinterpret_cast<Header*>(allocated);
	Footer* footer = reinterpret_cast<Footer*>(allocated + sizeof(Header) + size);
	header->size = size;
	header->magic = headerMagic;
	footer->magic = footerMagic;
	header->next = firstHeader;
	header->previous = nullptr;
	header->file = file;
	header->line = line;

	if (firstHeader != nullptr)
	{
		firstHeader->previous = header;
	}
	firstHeader = header;
	if (lastHeader == nullptr)
	{
		lastHeader = header;
	}
	return allocated + sizeof(Header);
}

void MemoryManager::Delete(void* allocated)
{
	char* data = reinterpret_cast<char*>(allocated) - sizeof(Header);
	Header* header = reinterpret_cast<Header*>(data);
	assert(header->magic == headerMagic);
	Footer* footer = reinterpret_cast<Footer*>(data + sizeof(Header) + header->size);
	assert(footer->magic == footerMagic);

	Header* next = header->next;
	Header* previous = header->previous;

	if (next != nullptr)
	{
		next->previous = previous;
	}
	else
	{
		assert(header == lastHeader);
		lastHeader = previous;
	}

	if (previous != nullptr)
	{
		previous->next = next;
	}
	else
	{
		assert(header == firstHeader);
		firstHeader = next;
	}
	free(data);
}

void MemoryManager::DumpHeap()
{
	for (Header* header = firstHeader; header != nullptr; header = header->next)
	{
		if (header->file)
		{
			printf("%s(%i): Object size: %zx %x\n", header->file, header->line, header->size, header->magic);
		}
		else
		{
			printf("Object size: %zx %x\n", header->size, header->magic);
		}
		
	}
}
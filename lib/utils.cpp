#include "utils.h"

void UnProtect(DWORD dwAddress, size_t sSize)
{
	// Unprotect the address
#if defined(WIN32)
	DWORD dwOldProtection;
	VirtualProtect((LPVOID)dwAddress, sSize, PAGE_EXECUTE_READWRITE, &dwOldProtection);
#elif defined(LINUX)
	mprotect((void*)(((int)dwAddress / 4096) * 4096), 4096, PROT_WRITE | PROT_READ | PROT_EXEC);
#endif
}

bool Unlock(void* address, size_t len)
{
#ifdef _WIN32
	DWORD oldp;
	return !!VirtualProtect(address, len, PAGE_EXECUTE_READWRITE, &oldp);
#else
	size_t iPageSize = getpagesize();
	size_t iAddr = ((reinterpret_cast <uint32_t>(address) / iPageSize) * iPageSize);
	return !mprotect(reinterpret_cast <void*>(iAddr), len, PROT_READ | PROT_WRITE | PROT_EXEC);
#endif
}

bool memory_compare(const BYTE* data, const BYTE* pattern, const char* mask)
{
	for (; *mask; ++mask, ++data, ++pattern) {
		if (*mask == 'x' && *data != *pattern)
			return false;
	}
	return (*mask) == NULL;
}

DWORD FindPattern(char* pattern, char* mask)
{
	DWORD i;
	DWORD size;
	DWORD address;
#ifdef _WIN32
	MODULEINFO info = { 0 };

	address = (DWORD)GetModuleHandle(NULL);
	GetModuleInformation(GetCurrentProcess(), GetModuleHandle(NULL), &info, sizeof(MODULEINFO));
	size = (DWORD)info.SizeOfImage;
#else
	address = 0x804b480; // around the elf base
	size = 0x8128B80 - address;
#endif
	for (i = 0; i < size; ++i) {
		if (memory_compare((BYTE*)(address + i), (BYTE*)pattern, mask))
			return (DWORD)(address + i);
	}
	return 0;
}

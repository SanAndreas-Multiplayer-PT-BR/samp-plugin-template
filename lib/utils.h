#ifndef _UTILS_H
#define _UTILS_H

#ifdef _WIN32
#include <Windows.h>
#include <Psapi.h>
#endif

#include <unordered_map>
#include <memory>

void UnProtect(DWORD dwAddress, size_t sSize);
bool memory_compare(const BYTE* data, const BYTE* pattern, const char* mask);
DWORD FindPattern(char* pattern, char* mask);

#endif
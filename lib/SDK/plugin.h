#ifndef _PLUGIN_H_
#define _PLUGIN_H_
#include "SDK/plugincommon.h"
#include "SDK/amx/amx.h"

typedef void (*logprintf_t)(const char* szFormat, ...);

extern void** ppPluginData;
extern void* pAMXFunctions;
extern logprintf_t logprintf;

void PluginLoad(void** ppData);

#endif
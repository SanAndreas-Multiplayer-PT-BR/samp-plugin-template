include(AMXConfig)
include(AddSAMPPlugin)

set(SOURCES
	"${SDK}/amxplugin.cpp"
	"${SDK}/plugin.cpp"
	"${RAKNET}/BitStream.cpp"
	"${RAKNET}/Hooks.cpp"
	"${LIB}/subhook/subhook.c"
	"${LIB}/NetGame/Hooks.cpp"
	"${LIB}/utils.cpp"
)

add_samp_plugin(Plugin 
	"${SOURCES}"
	"main.h"
	"main.cpp"
	"Native.cpp"
	"plugin.def"
)

target_include_directories(Plugin PUBLIC
	"${LIB}"
)
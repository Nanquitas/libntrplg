#ifndef FUNC_H
# define FUNC_H
# if IS_PLUGIN
#  define INIT_SHARED_FUNC(name,id) rtGenerateJumpCode(((NS_CONFIG*)(NS_CONFIGURE_ADDR))->sharedFunc[id], (void*) name);rtFlushInstructionCache((void*) name, 8);
# else
#  define INIT_SHARED_FUNC(name,id) (g_nsConfig->sharedFunc[id] = (u32) name)
# endif
# define MAX_PLUGIN_COUNT 32
# define CURRENT_PROCESS_HANDLE	0xffff8001

extern	Handle fsUserHandle;
extern	FS_Archive sdmcArchive;

typedef struct	_PLGLOADER_INFO
{
	u32	plgCount;
	u32	plgBufferPtr[MAX_PLUGIN_COUNT];
	u32	plgSize[MAX_PLUGIN_COUNT];
	u32	arm11BinStart;
	u32	arm11BinSize;
	u32	tid[2];
}		PLGLOADER_INFO;

int	showMenu(u8 *title, u32 entryCount, u8 *captions[]);
int	showMsg(u8 *msg);
void	showDbg(u8 *fmt, u32 v1, u32 v2);
void	kmemcpy(void *dst, void *src, u32 size);
void	updateScreen();

u32	plgRegisterMenuEntry(u32 catalog, char *title, void *callback) ;
u32	plgGetSharedServiceHandle(char *servName, u32 *handle);
u32	protectRemoteMemory(Handle hProcess, void *addr, u32 size);
u32	protectMemory(void *addr, u32 size);

#endif


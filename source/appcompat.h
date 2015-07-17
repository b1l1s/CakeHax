#ifndef __appcompat_h__
#define __appcompat_h__

#include <stdint.h>
#include "launcher_path.h"

// Functions
void (*memcpy)(void *dest, void *src, uint32_t len);
int (*GSPGPU_FlushDataCache)(void *address, uint32_t length);
void (*nn__gxlow__CTR__CmdReqQueueTx__TryEnqueue)(void *arg1, void *arg2);
uint32_t (*svcControlMemory)(uint32_t *outaddr, uint32_t *addr0, uint32_t *addr1, uint32_t size, uint32_t operation, uint32_t permissions);
int (*fopen)(uint32_t (*handle)[], short unsigned int *path, int flags);
int (*fread)(uint32_t (*handle)[], uint32_t *read, void *buffer, uint32_t size);
int (*fwrite)(uint32_t (*handle)[], uint32_t *written, void *src, uint32_t size);

#ifdef ENTRY_SPIDER
int (*GX_SetTextureCopy)(void *input_buffer, void *output_buffer, uint32_t size, int in_x, int in_y, int out_x, int out_y, int flags);
int (*svcSleepThread)(unsigned long long nanoseconds);
#endif


#if defined(ENTRY_MSET_4X) || defined(ENTRY_MSET_4X_DG)
    #define FUNC_MEMCPY 0x001BFA60
    #define FUNC_GSPGPU_FLUSHDATACACHE 0x0013C5D4
    #define FUNC_NN__GXLOW__CTR__CMDREQQUEUETX__TRYENQUEUE 0x001AC924
    #define FUNC_SVCCONTROLMEMORY 0x001C3E24
    #define FUNC_FOPEN 0x001B82A8
    #define FUNC_FREAD 0x001B3954
    #define FUNC_FWRITE 0x001B3B50

    #define APP_GPUHANDLE (0x0027C580 + 0x58)

    #if defined(ENTRY_MSET_4X)
        // Default firm 4.x (0x1F)
        // MSET code offset in FCRAM
        #define APP_CODE_OFFSET 0x03E6D000
    #elif defined(ENTRY_MSET_4X_DG)
        // Firm 6.1, 9.0~9.2 (0x38)
        // MSET code offset in FCRAM
        #define APP_CODE_OFFSET 0x03F00000
    #endif

#elif defined(ENTRY_MSET_6X)
    #define FUNC_MEMCPY 0x001C814C
    #define FUNC_GSPGPU_FLUSHDATACACHE 0x0013D3FC
    #define FUNC_NN__GXLOW__CTR__CMDREQQUEUETX__TRYENQUEUE 0x001B4E8C
    #define FUNC_SVCCONTROLMEMORY 0x001CC63C
    #define FUNC_FOPEN 0x001C08B4
    #define FUNC_FREAD 0x001BC188
    #define FUNC_FWRITE 0x001BC380

    #define APP_GPUHANDLE (0x0028A580 + 0x58)
    #define APP_CODE_OFFSET 0x03F00000

#elif defined(ENTRY_SPIDER_4X)
    #define FUNC_MEMCPY 0x0029BF60
    #define FUNC_GSPGPU_FLUSHDATACACHE 0x00344B84
    #define FUNC_NN__GXLOW__CTR__CMDREQQUEUETX__TRYENQUEUE 0x002CF3EC
    #define FUNC_SVCCONTROLMEMORY 0x002D6ADC
    #define FUNC_FOPEN 0x0025B0A4
    #define FUNC_FREAD 0x002FC8E4
    #define FUNC_FWRITE 0x00311D90

    #define FUNC_GX_SETTEXTURECOPY 0x002C62E4
    #define FUNC_SVCSLEEPTHREAD 0x002A513C

    #define APP_GPUHANDLE (0x003F54E8 + 0x58)

#elif defined(ENTRY_SPIDER_5X)
    #define FUNC_MEMCPY 0x00240B58
    #define FUNC_GSPGPU_FLUSHDATACACHE 0x001914FC
    #define FUNC_NN__GXLOW__CTR__CMDREQQUEUETX__TRYENQUEUE 0x0012BF4C
    #define FUNC_SVCCONTROLMEMORY 0x001431C0
    #define FUNC_FOPEN 0x0022FE44
    #define FUNC_FREAD 0x001686C0
    #define FUNC_FWRITE 0x00168748

    #define FUNC_GX_SETTEXTURECOPY 0x0011DD80
    #define FUNC_SVCSLEEPTHREAD 0x0010420C

    #define APP_GPUHANDLE (0x003D7C40 + 0x58)

#elif defined(ENTRY_SPIDER_9X)
    #define FUNC_MEMCPY 0x00240B50
    #define FUNC_GSPGPU_FLUSHDATACACHE 0x00191504
    #define FUNC_NN__GXLOW__CTR__CMDREQQUEUETX__TRYENQUEUE 0x0012BF04
    #define FUNC_SVCCONTROLMEMORY 0x001431A0
    #define FUNC_FOPEN 0x0022FE08
    #define FUNC_FREAD 0x001686DC
    #define FUNC_FWRITE 0x00168764

    #define FUNC_GX_SETTEXTURECOPY 0x0011DD48
    #define FUNC_SVCSLEEPTHREAD 0x0023FFE8

    #define APP_GPUHANDLE (0x003D7C40 + 0x58)
#elif defined(ENTRY_SPIDER_42_CN)
    #define FUNC_MEMCPY 0x0023F048
    #define FUNC_GSPGPU_FLUSHDATACACHE 0x0012BD1C
    #define FUNC_NN__GXLOW__CTR__CMDREQQUEUETX__TRYENQUEUE 0x0012BA40
    #define FUNC_SVCCONTROLMEMORY 0x00142F64
    #define FUNC_FOPEN 0x0022E334
    #define FUNC_FREAD 0x001674BC
    #define FUNC_FWRITE 0x00167544

    #define FUNC_GX_SETTEXTURECOPY 0x0011DD48
    #define FUNC_SVCSLEEPTHREAD 0x00104218

    #define APP_GPUHANDLE (0x003D6C40 + 0x58)
#elif defined(ENTRY_SPIDER_45_CN)
    #define FUNC_MEMCPY 0x0023EFA0
    #define FUNC_GSPGPU_FLUSHDATACACHE 0x0012BD30
    #define FUNC_NN__GXLOW__CTR__CMDREQQUEUETX__TRYENQUEUE 0x0012BA54
    #define FUNC_SVCCONTROLMEMORY 0x00142F58
    #define FUNC_FOPEN 0x0022E2B0
    #define FUNC_FREAD 0x00166FC8
    #define FUNC_FWRITE 0x00167050

    #define FUNC_GX_SETTEXTURECOPY 0x0011DD68
    #define FUNC_SVCSLEEPTHREAD 0x0010420C

    #define APP_GPUHANDLE (0x003D6C40 + 0x58)
#elif defined(ENTRY_SPIDER_5X_CN)
    #define FUNC_MEMCPY 0x0023F80C
    #define FUNC_GSPGPU_FLUSHDATACACHE 0x0012BD48
    #define FUNC_NN__GXLOW__CTR__CMDREQQUEUETX__TRYENQUEUE 0x0012BA6C
    #define FUNC_SVCCONTROLMEMORY 0x00143110
    #define FUNC_FOPEN 0x0022EA5C
    #define FUNC_FREAD 0x0016751C
    #define FUNC_FWRITE 0x001675A4

    #define FUNC_GX_SETTEXTURECOPY 0x0011DD80
    #define FUNC_SVCSLEEPTHREAD 0x0010420C

    #define APP_GPUHANDLE (0x003D7C40 + 0x58)
#elif defined(ENTRY_SPIDER_9X_CN)
    #define FUNC_MEMCPY 0x0023F808
    #define FUNC_GSPGPU_FLUSHDATACACHE 0x0012BD00
    #define FUNC_NN__GXLOW__CTR__CMDREQQUEUETX__TRYENQUEUE 0x0012BA24
    #define FUNC_SVCCONTROLMEMORY 0x001430F0
    #define FUNC_FOPEN 0x0022EA24
    #define FUNC_FREAD 0x00167540
    #define FUNC_FWRITE 0x001675C8

    #define FUNC_GX_SETTEXTURECOPY 0x0011DD48
    #define FUNC_SVCSLEEPTHREAD 0x001041F8

    #define APP_GPUHANDLE (0x003D7C40 + 0x58)
#elif defined(ENTRY_SPIDER_4X_KR)
    #define FUNC_MEMCPY 0x0023FF90
    #define FUNC_GSPGPU_FLUSHDATACACHE 0x0012BCF0
    #define FUNC_NN__GXLOW__CTR__CMDREQQUEUETX__TRYENQUEUE 0x0012BA14
    #define FUNC_SVCCONTROLMEMORY 0x00142FA0
    #define FUNC_FOPEN 0x0022F284
    #define FUNC_FREAD 0x001680F8
    #define FUNC_FWRITE 0x00168180

    #define FUNC_GX_SETTEXTURECOPY 0x0011DD48
    #define FUNC_SVCSLEEPTHREAD 0x00104218

    #define APP_GPUHANDLE (0x003D7C40 + 0x58)
#elif defined(ENTRY_SPIDER_5X_KR)
    #define FUNC_MEMCPY 0x002407DC
    #define FUNC_GSPGPU_FLUSHDATACACHE 0x0012BD1C
    #define FUNC_NN__GXLOW__CTR__CMDREQQUEUETX__TRYENQUEUE 0x0012BA40
    #define FUNC_SVCCONTROLMEMORY 0x00143108
    #define FUNC_FOPEN 0x0022FAC8
    #define FUNC_FREAD 0x001686FC
    #define FUNC_FWRITE 0x00168784

    #define FUNC_GX_SETTEXTURECOPY 0x0011DD80
    #define FUNC_SVCSLEEPTHREAD 0x0010420C

    #define APP_GPUHANDLE (0x003D7C40 + 0x58)
#elif defined(ENTRY_SPIDER_70_KR)
    #define FUNC_MEMCPY 0x002407DC
    #define FUNC_GSPGPU_FLUSHDATACACHE 0x0012BD1C
    #define FUNC_NN__GXLOW__CTR__CMDREQQUEUETX__TRYENQUEUE 0x0012BA40
    #define FUNC_SVCCONTROLMEMORY 0x00143108
    #define FUNC_FOPEN 0x0022FAC8
    #define FUNC_FREAD 0x001686FC
    #define FUNC_FWRITE 0x00168784

    #define FUNC_GX_SETTEXTURECOPY 0x0011DD80
    #define FUNC_SVCSLEEPTHREAD 0x0010420C

    #define APP_GPUHANDLE (0x003D7C40 + 0x58)
#elif defined(ENTRY_SPIDER_9X_KR)
    #define FUNC_MEMCPY 0x002407D4
    #define FUNC_GSPGPU_FLUSHDATACACHE 0x0012BCD4
    #define FUNC_NN__GXLOW__CTR__CMDREQQUEUETX__TRYENQUEUE 0x0012B9F8
    #define FUNC_SVCCONTROLMEMORY 0x001430E8
    #define FUNC_FOPEN 0x0022FA8C
    #define FUNC_FREAD 0x00168718
    #define FUNC_FWRITE 0x001687A0

    #define FUNC_GX_SETTEXTURECOPY 0x0011DD48
    #define FUNC_SVCSLEEPTHREAD 0x001041F8

    #define APP_GPUHANDLE (0x003D7C40 + 0x58)
#elif defined(ENTRY_SPIDER_4X_TW)
    #define FUNC_MEMCPY 0x0023FFE4
    #define FUNC_GSPGPU_FLUSHDATACACHE 0x0012BD1C
    #define FUNC_NN__GXLOW__CTR__CMDREQQUEUETX__TRYENQUEUE 0x0012BA40
    #define FUNC_SVCCONTROLMEMORY 0x00142F64
    #define FUNC_FOPEN 0x0022F2D8
    #define FUNC_FREAD 0x001680FC
    #define FUNC_FWRITE 0x00168184

    #define FUNC_GX_SETTEXTURECOPY 0x0011DD48
    #define FUNC_SVCSLEEPTHREAD 0x00104218

    #define APP_GPUHANDLE (0x003D7C40 + 0x58)
#elif defined(ENTRY_SPIDER_5X_TW)
    #define FUNC_MEMCPY 0x00240870
    #define FUNC_GSPGPU_FLUSHDATACACHE 0x0012BD48
    #define FUNC_NN__GXLOW__CTR__CMDREQQUEUETX__TRYENQUEUE 0x0012BA6C
    #define FUNC_SVCCONTROLMEMORY 0x00143110
    #define FUNC_FOPEN 0x0022FB5C
    #define FUNC_FREAD 0x00168744
    #define FUNC_FWRITE 0x001687CC

    #define FUNC_GX_SETTEXTURECOPY 0x0011DD80
    #define FUNC_SVCSLEEPTHREAD 0x0010420C

    #define APP_GPUHANDLE (0x003D7C40 + 0x58)
#elif defined(ENTRY_SPIDER_9X_TW)
    #define FUNC_MEMCPY 0x00240868
    #define FUNC_GSPGPU_FLUSHDATACACHE 0x0012BD00
    #define FUNC_NN__GXLOW__CTR__CMDREQQUEUETX__TRYENQUEUE 0x0012BA24
    #define FUNC_SVCCONTROLMEMORY 0x001430F0
    #define FUNC_FOPEN 0x0022FB20
    #define FUNC_FREAD 0x00168760
    #define FUNC_FWRITE 0x001687E8

    #define FUNC_GX_SETTEXTURECOPY 0x0011DD48
    #define FUNC_SVCSLEEPTHREAD 0x001041F8

    #define APP_GPUHANDLE (0x003D7C40 + 0x58)
#endif

#if defined(ENTRY_MSET)
    // The usable area for this app
    #define APP_FCRAM_ADDR 0x14000000

    #define APP_CFW_OFFSET 0x400000
    #define APP_LAUNCHER_PATH (L"YS:/" LAUNCHER_PATH)

#elif defined(ENTRY_SPIDER)
    // The usable area for this app
    #define APP_FCRAM_ADDR 0x18400000

    #define APP_CFW_OFFSET 0x4410000
    #define APP_LAUNCHER_PATH (L"dmc:/" LAUNCHER_PATH)
#endif

// Locations in fcram
#define APP_CHECK_MEM (APP_FCRAM_ADDR + 0x1000)
#define APP_ARM11_BUFFER (APP_FCRAM_ADDR + 0x2000)
#define APP_MEM_HAX_MEM (APP_FCRAM_ADDR + 0x50000)
#define APP_FIRM_COMPAT (APP_FCRAM_ADDR + 0x20000)

#define ARM9_PAYLOAD_MAXSIZE 0x10000

#endif

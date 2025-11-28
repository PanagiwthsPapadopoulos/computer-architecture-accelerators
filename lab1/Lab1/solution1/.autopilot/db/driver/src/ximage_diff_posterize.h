// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.2 (64-bit)
// Tool Version Limit: 2019.12
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XIMAGE_DIFF_POSTERIZE_H
#define XIMAGE_DIFF_POSTERIZE_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "ximage_diff_posterize_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
    u16 DeviceId;
    u64 Control_BaseAddress;
} XImage_diff_posterize_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XImage_diff_posterize;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XImage_diff_posterize_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XImage_diff_posterize_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XImage_diff_posterize_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XImage_diff_posterize_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XImage_diff_posterize_Initialize(XImage_diff_posterize *InstancePtr, u16 DeviceId);
XImage_diff_posterize_Config* XImage_diff_posterize_LookupConfig(u16 DeviceId);
int XImage_diff_posterize_CfgInitialize(XImage_diff_posterize *InstancePtr, XImage_diff_posterize_Config *ConfigPtr);
#else
int XImage_diff_posterize_Initialize(XImage_diff_posterize *InstancePtr, const char* InstanceName);
int XImage_diff_posterize_Release(XImage_diff_posterize *InstancePtr);
#endif

void XImage_diff_posterize_Start(XImage_diff_posterize *InstancePtr);
u32 XImage_diff_posterize_IsDone(XImage_diff_posterize *InstancePtr);
u32 XImage_diff_posterize_IsIdle(XImage_diff_posterize *InstancePtr);
u32 XImage_diff_posterize_IsReady(XImage_diff_posterize *InstancePtr);
void XImage_diff_posterize_EnableAutoRestart(XImage_diff_posterize *InstancePtr);
void XImage_diff_posterize_DisableAutoRestart(XImage_diff_posterize *InstancePtr);

void XImage_diff_posterize_Set_A(XImage_diff_posterize *InstancePtr, u64 Data);
u64 XImage_diff_posterize_Get_A(XImage_diff_posterize *InstancePtr);
void XImage_diff_posterize_Set_B(XImage_diff_posterize *InstancePtr, u64 Data);
u64 XImage_diff_posterize_Get_B(XImage_diff_posterize *InstancePtr);
void XImage_diff_posterize_Set_C(XImage_diff_posterize *InstancePtr, u64 Data);
u64 XImage_diff_posterize_Get_C(XImage_diff_posterize *InstancePtr);

void XImage_diff_posterize_InterruptGlobalEnable(XImage_diff_posterize *InstancePtr);
void XImage_diff_posterize_InterruptGlobalDisable(XImage_diff_posterize *InstancePtr);
void XImage_diff_posterize_InterruptEnable(XImage_diff_posterize *InstancePtr, u32 Mask);
void XImage_diff_posterize_InterruptDisable(XImage_diff_posterize *InstancePtr, u32 Mask);
void XImage_diff_posterize_InterruptClear(XImage_diff_posterize *InstancePtr, u32 Mask);
u32 XImage_diff_posterize_InterruptGetEnabled(XImage_diff_posterize *InstancePtr);
u32 XImage_diff_posterize_InterruptGetStatus(XImage_diff_posterize *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif

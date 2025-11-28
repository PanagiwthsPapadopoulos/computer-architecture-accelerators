// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.2 (64-bit)
// Tool Version Limit: 2019.12
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "ximage_diff_posterize.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XImage_diff_posterize_CfgInitialize(XImage_diff_posterize *InstancePtr, XImage_diff_posterize_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XImage_diff_posterize_Start(XImage_diff_posterize *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XImage_diff_posterize_ReadReg(InstancePtr->Control_BaseAddress, XIMAGE_DIFF_POSTERIZE_CONTROL_ADDR_AP_CTRL) & 0x80;
    XImage_diff_posterize_WriteReg(InstancePtr->Control_BaseAddress, XIMAGE_DIFF_POSTERIZE_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XImage_diff_posterize_IsDone(XImage_diff_posterize *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XImage_diff_posterize_ReadReg(InstancePtr->Control_BaseAddress, XIMAGE_DIFF_POSTERIZE_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XImage_diff_posterize_IsIdle(XImage_diff_posterize *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XImage_diff_posterize_ReadReg(InstancePtr->Control_BaseAddress, XIMAGE_DIFF_POSTERIZE_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XImage_diff_posterize_IsReady(XImage_diff_posterize *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XImage_diff_posterize_ReadReg(InstancePtr->Control_BaseAddress, XIMAGE_DIFF_POSTERIZE_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XImage_diff_posterize_EnableAutoRestart(XImage_diff_posterize *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XImage_diff_posterize_WriteReg(InstancePtr->Control_BaseAddress, XIMAGE_DIFF_POSTERIZE_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XImage_diff_posterize_DisableAutoRestart(XImage_diff_posterize *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XImage_diff_posterize_WriteReg(InstancePtr->Control_BaseAddress, XIMAGE_DIFF_POSTERIZE_CONTROL_ADDR_AP_CTRL, 0);
}

void XImage_diff_posterize_Set_A(XImage_diff_posterize *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XImage_diff_posterize_WriteReg(InstancePtr->Control_BaseAddress, XIMAGE_DIFF_POSTERIZE_CONTROL_ADDR_A_DATA, (u32)(Data));
    XImage_diff_posterize_WriteReg(InstancePtr->Control_BaseAddress, XIMAGE_DIFF_POSTERIZE_CONTROL_ADDR_A_DATA + 4, (u32)(Data >> 32));
}

u64 XImage_diff_posterize_Get_A(XImage_diff_posterize *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XImage_diff_posterize_ReadReg(InstancePtr->Control_BaseAddress, XIMAGE_DIFF_POSTERIZE_CONTROL_ADDR_A_DATA);
    Data += (u64)XImage_diff_posterize_ReadReg(InstancePtr->Control_BaseAddress, XIMAGE_DIFF_POSTERIZE_CONTROL_ADDR_A_DATA + 4) << 32;
    return Data;
}

void XImage_diff_posterize_Set_B(XImage_diff_posterize *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XImage_diff_posterize_WriteReg(InstancePtr->Control_BaseAddress, XIMAGE_DIFF_POSTERIZE_CONTROL_ADDR_B_DATA, (u32)(Data));
    XImage_diff_posterize_WriteReg(InstancePtr->Control_BaseAddress, XIMAGE_DIFF_POSTERIZE_CONTROL_ADDR_B_DATA + 4, (u32)(Data >> 32));
}

u64 XImage_diff_posterize_Get_B(XImage_diff_posterize *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XImage_diff_posterize_ReadReg(InstancePtr->Control_BaseAddress, XIMAGE_DIFF_POSTERIZE_CONTROL_ADDR_B_DATA);
    Data += (u64)XImage_diff_posterize_ReadReg(InstancePtr->Control_BaseAddress, XIMAGE_DIFF_POSTERIZE_CONTROL_ADDR_B_DATA + 4) << 32;
    return Data;
}

void XImage_diff_posterize_Set_C(XImage_diff_posterize *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XImage_diff_posterize_WriteReg(InstancePtr->Control_BaseAddress, XIMAGE_DIFF_POSTERIZE_CONTROL_ADDR_C_DATA, (u32)(Data));
    XImage_diff_posterize_WriteReg(InstancePtr->Control_BaseAddress, XIMAGE_DIFF_POSTERIZE_CONTROL_ADDR_C_DATA + 4, (u32)(Data >> 32));
}

u64 XImage_diff_posterize_Get_C(XImage_diff_posterize *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XImage_diff_posterize_ReadReg(InstancePtr->Control_BaseAddress, XIMAGE_DIFF_POSTERIZE_CONTROL_ADDR_C_DATA);
    Data += (u64)XImage_diff_posterize_ReadReg(InstancePtr->Control_BaseAddress, XIMAGE_DIFF_POSTERIZE_CONTROL_ADDR_C_DATA + 4) << 32;
    return Data;
}

void XImage_diff_posterize_InterruptGlobalEnable(XImage_diff_posterize *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XImage_diff_posterize_WriteReg(InstancePtr->Control_BaseAddress, XIMAGE_DIFF_POSTERIZE_CONTROL_ADDR_GIE, 1);
}

void XImage_diff_posterize_InterruptGlobalDisable(XImage_diff_posterize *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XImage_diff_posterize_WriteReg(InstancePtr->Control_BaseAddress, XIMAGE_DIFF_POSTERIZE_CONTROL_ADDR_GIE, 0);
}

void XImage_diff_posterize_InterruptEnable(XImage_diff_posterize *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XImage_diff_posterize_ReadReg(InstancePtr->Control_BaseAddress, XIMAGE_DIFF_POSTERIZE_CONTROL_ADDR_IER);
    XImage_diff_posterize_WriteReg(InstancePtr->Control_BaseAddress, XIMAGE_DIFF_POSTERIZE_CONTROL_ADDR_IER, Register | Mask);
}

void XImage_diff_posterize_InterruptDisable(XImage_diff_posterize *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XImage_diff_posterize_ReadReg(InstancePtr->Control_BaseAddress, XIMAGE_DIFF_POSTERIZE_CONTROL_ADDR_IER);
    XImage_diff_posterize_WriteReg(InstancePtr->Control_BaseAddress, XIMAGE_DIFF_POSTERIZE_CONTROL_ADDR_IER, Register & (~Mask));
}

void XImage_diff_posterize_InterruptClear(XImage_diff_posterize *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XImage_diff_posterize_WriteReg(InstancePtr->Control_BaseAddress, XIMAGE_DIFF_POSTERIZE_CONTROL_ADDR_ISR, Mask);
}

u32 XImage_diff_posterize_InterruptGetEnabled(XImage_diff_posterize *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XImage_diff_posterize_ReadReg(InstancePtr->Control_BaseAddress, XIMAGE_DIFF_POSTERIZE_CONTROL_ADDR_IER);
}

u32 XImage_diff_posterize_InterruptGetStatus(XImage_diff_posterize *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XImage_diff_posterize_ReadReg(InstancePtr->Control_BaseAddress, XIMAGE_DIFF_POSTERIZE_CONTROL_ADDR_ISR);
}


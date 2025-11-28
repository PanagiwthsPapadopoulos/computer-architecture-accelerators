// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.2 (64-bit)
// Tool Version Limit: 2019.12
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "ximage_diff_posterize.h"

extern XImage_diff_posterize_Config XImage_diff_posterize_ConfigTable[];

XImage_diff_posterize_Config *XImage_diff_posterize_LookupConfig(u16 DeviceId) {
	XImage_diff_posterize_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XIMAGE_DIFF_POSTERIZE_NUM_INSTANCES; Index++) {
		if (XImage_diff_posterize_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XImage_diff_posterize_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XImage_diff_posterize_Initialize(XImage_diff_posterize *InstancePtr, u16 DeviceId) {
	XImage_diff_posterize_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XImage_diff_posterize_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XImage_diff_posterize_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif


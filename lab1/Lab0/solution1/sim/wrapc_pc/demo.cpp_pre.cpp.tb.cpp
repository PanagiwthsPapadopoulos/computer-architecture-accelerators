// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.2 (64-bit)
// Tool Version Limit: 2019.12
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
# 1 "C:/Users/Stavros/AppData/Roaming/Xilinx/Vitis/Lab0/demo.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "C:/Users/Stavros/AppData/Roaming/Xilinx/Vitis/Lab0/demo.cpp"
void simpleALU(int A, int B, int op, int *C){
 switch (op){
 case 0:{
  *C = A + B;
  break;
 }
 case 1:{
  *C = A - B;
  break;
 }
 case 2:{
  *C = A * B;
  break;
 }
 case 3:{
  *C = A / B;
  break;
 }
  }

}
#ifndef HLS_FASTSIM
#ifdef __cplusplus
extern "C"
#endif
void apatb_simpleALU_ir(int, int, int, int *);
#ifdef __cplusplus
extern "C"
#endif
void simpleALU_hw_stub(int A, int B, int op, int *C){
simpleALU(A, B, op, C);
return ;
}
#ifdef __cplusplus
extern "C"
#endif
void apatb_simpleALU_sw(int A, int B, int op, int *C){
apatb_simpleALU_ir(A, B, op, C);
return ;
}
#endif
# 21 "C:/Users/Stavros/AppData/Roaming/Xilinx/Vitis/Lab0/demo.cpp"


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

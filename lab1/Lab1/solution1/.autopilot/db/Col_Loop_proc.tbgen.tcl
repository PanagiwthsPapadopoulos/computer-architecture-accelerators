set moduleName Col_Loop_proc
set isTopModule 0
set isCombinational 0
set isDatapathOnly 0
set isPipelined 1
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set hasInterrupt 0
set C_modelName {Col_Loop_proc}
set C_modelType { void 0 }
set C_modelArgList {
	{ image_diff_posterize_rowA_0 int 8 regular {array 32 { 1 3 } 1 1 }  }
	{ image_diff_posterize_rowA_1 int 8 regular {array 32 { 1 3 } 1 1 }  }
	{ image_diff_posterize_rowA_2 int 8 regular {array 32 { 1 3 } 1 1 }  }
	{ image_diff_posterize_rowA_3 int 8 regular {array 32 { 1 3 } 1 1 }  }
	{ image_diff_posterize_rowA_4 int 8 regular {array 32 { 1 3 } 1 1 }  }
	{ image_diff_posterize_rowA_5 int 8 regular {array 32 { 1 3 } 1 1 }  }
	{ image_diff_posterize_rowA_6 int 8 regular {array 32 { 1 3 } 1 1 }  }
	{ image_diff_posterize_rowA_7 int 8 regular {array 32 { 1 3 } 1 1 }  }
	{ image_diff_posterize_rowB_0 int 8 regular {array 32 { 1 3 } 1 1 }  }
	{ image_diff_posterize_rowB_1 int 8 regular {array 32 { 1 3 } 1 1 }  }
	{ image_diff_posterize_rowB_2 int 8 regular {array 32 { 1 3 } 1 1 }  }
	{ image_diff_posterize_rowB_3 int 8 regular {array 32 { 1 3 } 1 1 }  }
	{ image_diff_posterize_rowB_4 int 8 regular {array 32 { 1 3 } 1 1 }  }
	{ image_diff_posterize_rowB_5 int 8 regular {array 32 { 1 3 } 1 1 }  }
	{ image_diff_posterize_rowB_6 int 8 regular {array 32 { 1 3 } 1 1 }  }
	{ image_diff_posterize_rowB_7 int 8 regular {array 32 { 1 3 } 1 1 }  }
	{ image_diff_posterize_rowC_0 int 8 regular {array 32 { 0 3 } 0 1 }  }
	{ image_diff_posterize_rowC_1 int 8 regular {array 32 { 0 3 } 0 1 }  }
	{ image_diff_posterize_rowC_2 int 8 regular {array 32 { 0 3 } 0 1 }  }
	{ image_diff_posterize_rowC_3 int 8 regular {array 32 { 0 3 } 0 1 }  }
	{ image_diff_posterize_rowC_4 int 8 regular {array 32 { 0 3 } 0 1 }  }
	{ image_diff_posterize_rowC_5 int 8 regular {array 32 { 0 3 } 0 1 }  }
	{ image_diff_posterize_rowC_6 int 8 regular {array 32 { 0 3 } 0 1 }  }
	{ image_diff_posterize_rowC_7 int 8 regular {array 32 { 0 3 } 0 1 }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "image_diff_posterize_rowA_0", "interface" : "memory", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "image_diff_posterize_rowA_1", "interface" : "memory", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "image_diff_posterize_rowA_2", "interface" : "memory", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "image_diff_posterize_rowA_3", "interface" : "memory", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "image_diff_posterize_rowA_4", "interface" : "memory", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "image_diff_posterize_rowA_5", "interface" : "memory", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "image_diff_posterize_rowA_6", "interface" : "memory", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "image_diff_posterize_rowA_7", "interface" : "memory", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "image_diff_posterize_rowB_0", "interface" : "memory", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "image_diff_posterize_rowB_1", "interface" : "memory", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "image_diff_posterize_rowB_2", "interface" : "memory", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "image_diff_posterize_rowB_3", "interface" : "memory", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "image_diff_posterize_rowB_4", "interface" : "memory", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "image_diff_posterize_rowB_5", "interface" : "memory", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "image_diff_posterize_rowB_6", "interface" : "memory", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "image_diff_posterize_rowB_7", "interface" : "memory", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "image_diff_posterize_rowC_0", "interface" : "memory", "bitwidth" : 8, "direction" : "WRITEONLY"} , 
 	{ "Name" : "image_diff_posterize_rowC_1", "interface" : "memory", "bitwidth" : 8, "direction" : "WRITEONLY"} , 
 	{ "Name" : "image_diff_posterize_rowC_2", "interface" : "memory", "bitwidth" : 8, "direction" : "WRITEONLY"} , 
 	{ "Name" : "image_diff_posterize_rowC_3", "interface" : "memory", "bitwidth" : 8, "direction" : "WRITEONLY"} , 
 	{ "Name" : "image_diff_posterize_rowC_4", "interface" : "memory", "bitwidth" : 8, "direction" : "WRITEONLY"} , 
 	{ "Name" : "image_diff_posterize_rowC_5", "interface" : "memory", "bitwidth" : 8, "direction" : "WRITEONLY"} , 
 	{ "Name" : "image_diff_posterize_rowC_6", "interface" : "memory", "bitwidth" : 8, "direction" : "WRITEONLY"} , 
 	{ "Name" : "image_diff_posterize_rowC_7", "interface" : "memory", "bitwidth" : 8, "direction" : "WRITEONLY"} ]}
# RTL Port declarations: 
set portNum 87
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_continue sc_in sc_logic 1 continue -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ image_diff_posterize_rowA_0_address0 sc_out sc_lv 5 signal 0 } 
	{ image_diff_posterize_rowA_0_ce0 sc_out sc_logic 1 signal 0 } 
	{ image_diff_posterize_rowA_0_q0 sc_in sc_lv 8 signal 0 } 
	{ image_diff_posterize_rowA_1_address0 sc_out sc_lv 5 signal 1 } 
	{ image_diff_posterize_rowA_1_ce0 sc_out sc_logic 1 signal 1 } 
	{ image_diff_posterize_rowA_1_q0 sc_in sc_lv 8 signal 1 } 
	{ image_diff_posterize_rowA_2_address0 sc_out sc_lv 5 signal 2 } 
	{ image_diff_posterize_rowA_2_ce0 sc_out sc_logic 1 signal 2 } 
	{ image_diff_posterize_rowA_2_q0 sc_in sc_lv 8 signal 2 } 
	{ image_diff_posterize_rowA_3_address0 sc_out sc_lv 5 signal 3 } 
	{ image_diff_posterize_rowA_3_ce0 sc_out sc_logic 1 signal 3 } 
	{ image_diff_posterize_rowA_3_q0 sc_in sc_lv 8 signal 3 } 
	{ image_diff_posterize_rowA_4_address0 sc_out sc_lv 5 signal 4 } 
	{ image_diff_posterize_rowA_4_ce0 sc_out sc_logic 1 signal 4 } 
	{ image_diff_posterize_rowA_4_q0 sc_in sc_lv 8 signal 4 } 
	{ image_diff_posterize_rowA_5_address0 sc_out sc_lv 5 signal 5 } 
	{ image_diff_posterize_rowA_5_ce0 sc_out sc_logic 1 signal 5 } 
	{ image_diff_posterize_rowA_5_q0 sc_in sc_lv 8 signal 5 } 
	{ image_diff_posterize_rowA_6_address0 sc_out sc_lv 5 signal 6 } 
	{ image_diff_posterize_rowA_6_ce0 sc_out sc_logic 1 signal 6 } 
	{ image_diff_posterize_rowA_6_q0 sc_in sc_lv 8 signal 6 } 
	{ image_diff_posterize_rowA_7_address0 sc_out sc_lv 5 signal 7 } 
	{ image_diff_posterize_rowA_7_ce0 sc_out sc_logic 1 signal 7 } 
	{ image_diff_posterize_rowA_7_q0 sc_in sc_lv 8 signal 7 } 
	{ image_diff_posterize_rowB_0_address0 sc_out sc_lv 5 signal 8 } 
	{ image_diff_posterize_rowB_0_ce0 sc_out sc_logic 1 signal 8 } 
	{ image_diff_posterize_rowB_0_q0 sc_in sc_lv 8 signal 8 } 
	{ image_diff_posterize_rowB_1_address0 sc_out sc_lv 5 signal 9 } 
	{ image_diff_posterize_rowB_1_ce0 sc_out sc_logic 1 signal 9 } 
	{ image_diff_posterize_rowB_1_q0 sc_in sc_lv 8 signal 9 } 
	{ image_diff_posterize_rowB_2_address0 sc_out sc_lv 5 signal 10 } 
	{ image_diff_posterize_rowB_2_ce0 sc_out sc_logic 1 signal 10 } 
	{ image_diff_posterize_rowB_2_q0 sc_in sc_lv 8 signal 10 } 
	{ image_diff_posterize_rowB_3_address0 sc_out sc_lv 5 signal 11 } 
	{ image_diff_posterize_rowB_3_ce0 sc_out sc_logic 1 signal 11 } 
	{ image_diff_posterize_rowB_3_q0 sc_in sc_lv 8 signal 11 } 
	{ image_diff_posterize_rowB_4_address0 sc_out sc_lv 5 signal 12 } 
	{ image_diff_posterize_rowB_4_ce0 sc_out sc_logic 1 signal 12 } 
	{ image_diff_posterize_rowB_4_q0 sc_in sc_lv 8 signal 12 } 
	{ image_diff_posterize_rowB_5_address0 sc_out sc_lv 5 signal 13 } 
	{ image_diff_posterize_rowB_5_ce0 sc_out sc_logic 1 signal 13 } 
	{ image_diff_posterize_rowB_5_q0 sc_in sc_lv 8 signal 13 } 
	{ image_diff_posterize_rowB_6_address0 sc_out sc_lv 5 signal 14 } 
	{ image_diff_posterize_rowB_6_ce0 sc_out sc_logic 1 signal 14 } 
	{ image_diff_posterize_rowB_6_q0 sc_in sc_lv 8 signal 14 } 
	{ image_diff_posterize_rowB_7_address0 sc_out sc_lv 5 signal 15 } 
	{ image_diff_posterize_rowB_7_ce0 sc_out sc_logic 1 signal 15 } 
	{ image_diff_posterize_rowB_7_q0 sc_in sc_lv 8 signal 15 } 
	{ image_diff_posterize_rowC_0_address0 sc_out sc_lv 5 signal 16 } 
	{ image_diff_posterize_rowC_0_ce0 sc_out sc_logic 1 signal 16 } 
	{ image_diff_posterize_rowC_0_we0 sc_out sc_logic 1 signal 16 } 
	{ image_diff_posterize_rowC_0_d0 sc_out sc_lv 8 signal 16 } 
	{ image_diff_posterize_rowC_1_address0 sc_out sc_lv 5 signal 17 } 
	{ image_diff_posterize_rowC_1_ce0 sc_out sc_logic 1 signal 17 } 
	{ image_diff_posterize_rowC_1_we0 sc_out sc_logic 1 signal 17 } 
	{ image_diff_posterize_rowC_1_d0 sc_out sc_lv 8 signal 17 } 
	{ image_diff_posterize_rowC_2_address0 sc_out sc_lv 5 signal 18 } 
	{ image_diff_posterize_rowC_2_ce0 sc_out sc_logic 1 signal 18 } 
	{ image_diff_posterize_rowC_2_we0 sc_out sc_logic 1 signal 18 } 
	{ image_diff_posterize_rowC_2_d0 sc_out sc_lv 8 signal 18 } 
	{ image_diff_posterize_rowC_3_address0 sc_out sc_lv 5 signal 19 } 
	{ image_diff_posterize_rowC_3_ce0 sc_out sc_logic 1 signal 19 } 
	{ image_diff_posterize_rowC_3_we0 sc_out sc_logic 1 signal 19 } 
	{ image_diff_posterize_rowC_3_d0 sc_out sc_lv 8 signal 19 } 
	{ image_diff_posterize_rowC_4_address0 sc_out sc_lv 5 signal 20 } 
	{ image_diff_posterize_rowC_4_ce0 sc_out sc_logic 1 signal 20 } 
	{ image_diff_posterize_rowC_4_we0 sc_out sc_logic 1 signal 20 } 
	{ image_diff_posterize_rowC_4_d0 sc_out sc_lv 8 signal 20 } 
	{ image_diff_posterize_rowC_5_address0 sc_out sc_lv 5 signal 21 } 
	{ image_diff_posterize_rowC_5_ce0 sc_out sc_logic 1 signal 21 } 
	{ image_diff_posterize_rowC_5_we0 sc_out sc_logic 1 signal 21 } 
	{ image_diff_posterize_rowC_5_d0 sc_out sc_lv 8 signal 21 } 
	{ image_diff_posterize_rowC_6_address0 sc_out sc_lv 5 signal 22 } 
	{ image_diff_posterize_rowC_6_ce0 sc_out sc_logic 1 signal 22 } 
	{ image_diff_posterize_rowC_6_we0 sc_out sc_logic 1 signal 22 } 
	{ image_diff_posterize_rowC_6_d0 sc_out sc_lv 8 signal 22 } 
	{ image_diff_posterize_rowC_7_address0 sc_out sc_lv 5 signal 23 } 
	{ image_diff_posterize_rowC_7_ce0 sc_out sc_logic 1 signal 23 } 
	{ image_diff_posterize_rowC_7_we0 sc_out sc_logic 1 signal 23 } 
	{ image_diff_posterize_rowC_7_d0 sc_out sc_lv 8 signal 23 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_continue", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "continue", "bundle":{"name": "ap_continue", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "image_diff_posterize_rowA_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "image_diff_posterize_rowA_0", "role": "address0" }} , 
 	{ "name": "image_diff_posterize_rowA_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "image_diff_posterize_rowA_0", "role": "ce0" }} , 
 	{ "name": "image_diff_posterize_rowA_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "image_diff_posterize_rowA_0", "role": "q0" }} , 
 	{ "name": "image_diff_posterize_rowA_1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "image_diff_posterize_rowA_1", "role": "address0" }} , 
 	{ "name": "image_diff_posterize_rowA_1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "image_diff_posterize_rowA_1", "role": "ce0" }} , 
 	{ "name": "image_diff_posterize_rowA_1_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "image_diff_posterize_rowA_1", "role": "q0" }} , 
 	{ "name": "image_diff_posterize_rowA_2_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "image_diff_posterize_rowA_2", "role": "address0" }} , 
 	{ "name": "image_diff_posterize_rowA_2_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "image_diff_posterize_rowA_2", "role": "ce0" }} , 
 	{ "name": "image_diff_posterize_rowA_2_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "image_diff_posterize_rowA_2", "role": "q0" }} , 
 	{ "name": "image_diff_posterize_rowA_3_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "image_diff_posterize_rowA_3", "role": "address0" }} , 
 	{ "name": "image_diff_posterize_rowA_3_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "image_diff_posterize_rowA_3", "role": "ce0" }} , 
 	{ "name": "image_diff_posterize_rowA_3_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "image_diff_posterize_rowA_3", "role": "q0" }} , 
 	{ "name": "image_diff_posterize_rowA_4_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "image_diff_posterize_rowA_4", "role": "address0" }} , 
 	{ "name": "image_diff_posterize_rowA_4_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "image_diff_posterize_rowA_4", "role": "ce0" }} , 
 	{ "name": "image_diff_posterize_rowA_4_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "image_diff_posterize_rowA_4", "role": "q0" }} , 
 	{ "name": "image_diff_posterize_rowA_5_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "image_diff_posterize_rowA_5", "role": "address0" }} , 
 	{ "name": "image_diff_posterize_rowA_5_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "image_diff_posterize_rowA_5", "role": "ce0" }} , 
 	{ "name": "image_diff_posterize_rowA_5_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "image_diff_posterize_rowA_5", "role": "q0" }} , 
 	{ "name": "image_diff_posterize_rowA_6_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "image_diff_posterize_rowA_6", "role": "address0" }} , 
 	{ "name": "image_diff_posterize_rowA_6_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "image_diff_posterize_rowA_6", "role": "ce0" }} , 
 	{ "name": "image_diff_posterize_rowA_6_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "image_diff_posterize_rowA_6", "role": "q0" }} , 
 	{ "name": "image_diff_posterize_rowA_7_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "image_diff_posterize_rowA_7", "role": "address0" }} , 
 	{ "name": "image_diff_posterize_rowA_7_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "image_diff_posterize_rowA_7", "role": "ce0" }} , 
 	{ "name": "image_diff_posterize_rowA_7_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "image_diff_posterize_rowA_7", "role": "q0" }} , 
 	{ "name": "image_diff_posterize_rowB_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "image_diff_posterize_rowB_0", "role": "address0" }} , 
 	{ "name": "image_diff_posterize_rowB_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "image_diff_posterize_rowB_0", "role": "ce0" }} , 
 	{ "name": "image_diff_posterize_rowB_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "image_diff_posterize_rowB_0", "role": "q0" }} , 
 	{ "name": "image_diff_posterize_rowB_1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "image_diff_posterize_rowB_1", "role": "address0" }} , 
 	{ "name": "image_diff_posterize_rowB_1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "image_diff_posterize_rowB_1", "role": "ce0" }} , 
 	{ "name": "image_diff_posterize_rowB_1_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "image_diff_posterize_rowB_1", "role": "q0" }} , 
 	{ "name": "image_diff_posterize_rowB_2_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "image_diff_posterize_rowB_2", "role": "address0" }} , 
 	{ "name": "image_diff_posterize_rowB_2_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "image_diff_posterize_rowB_2", "role": "ce0" }} , 
 	{ "name": "image_diff_posterize_rowB_2_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "image_diff_posterize_rowB_2", "role": "q0" }} , 
 	{ "name": "image_diff_posterize_rowB_3_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "image_diff_posterize_rowB_3", "role": "address0" }} , 
 	{ "name": "image_diff_posterize_rowB_3_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "image_diff_posterize_rowB_3", "role": "ce0" }} , 
 	{ "name": "image_diff_posterize_rowB_3_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "image_diff_posterize_rowB_3", "role": "q0" }} , 
 	{ "name": "image_diff_posterize_rowB_4_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "image_diff_posterize_rowB_4", "role": "address0" }} , 
 	{ "name": "image_diff_posterize_rowB_4_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "image_diff_posterize_rowB_4", "role": "ce0" }} , 
 	{ "name": "image_diff_posterize_rowB_4_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "image_diff_posterize_rowB_4", "role": "q0" }} , 
 	{ "name": "image_diff_posterize_rowB_5_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "image_diff_posterize_rowB_5", "role": "address0" }} , 
 	{ "name": "image_diff_posterize_rowB_5_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "image_diff_posterize_rowB_5", "role": "ce0" }} , 
 	{ "name": "image_diff_posterize_rowB_5_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "image_diff_posterize_rowB_5", "role": "q0" }} , 
 	{ "name": "image_diff_posterize_rowB_6_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "image_diff_posterize_rowB_6", "role": "address0" }} , 
 	{ "name": "image_diff_posterize_rowB_6_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "image_diff_posterize_rowB_6", "role": "ce0" }} , 
 	{ "name": "image_diff_posterize_rowB_6_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "image_diff_posterize_rowB_6", "role": "q0" }} , 
 	{ "name": "image_diff_posterize_rowB_7_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "image_diff_posterize_rowB_7", "role": "address0" }} , 
 	{ "name": "image_diff_posterize_rowB_7_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "image_diff_posterize_rowB_7", "role": "ce0" }} , 
 	{ "name": "image_diff_posterize_rowB_7_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "image_diff_posterize_rowB_7", "role": "q0" }} , 
 	{ "name": "image_diff_posterize_rowC_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "image_diff_posterize_rowC_0", "role": "address0" }} , 
 	{ "name": "image_diff_posterize_rowC_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "image_diff_posterize_rowC_0", "role": "ce0" }} , 
 	{ "name": "image_diff_posterize_rowC_0_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "image_diff_posterize_rowC_0", "role": "we0" }} , 
 	{ "name": "image_diff_posterize_rowC_0_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "image_diff_posterize_rowC_0", "role": "d0" }} , 
 	{ "name": "image_diff_posterize_rowC_1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "image_diff_posterize_rowC_1", "role": "address0" }} , 
 	{ "name": "image_diff_posterize_rowC_1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "image_diff_posterize_rowC_1", "role": "ce0" }} , 
 	{ "name": "image_diff_posterize_rowC_1_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "image_diff_posterize_rowC_1", "role": "we0" }} , 
 	{ "name": "image_diff_posterize_rowC_1_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "image_diff_posterize_rowC_1", "role": "d0" }} , 
 	{ "name": "image_diff_posterize_rowC_2_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "image_diff_posterize_rowC_2", "role": "address0" }} , 
 	{ "name": "image_diff_posterize_rowC_2_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "image_diff_posterize_rowC_2", "role": "ce0" }} , 
 	{ "name": "image_diff_posterize_rowC_2_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "image_diff_posterize_rowC_2", "role": "we0" }} , 
 	{ "name": "image_diff_posterize_rowC_2_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "image_diff_posterize_rowC_2", "role": "d0" }} , 
 	{ "name": "image_diff_posterize_rowC_3_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "image_diff_posterize_rowC_3", "role": "address0" }} , 
 	{ "name": "image_diff_posterize_rowC_3_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "image_diff_posterize_rowC_3", "role": "ce0" }} , 
 	{ "name": "image_diff_posterize_rowC_3_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "image_diff_posterize_rowC_3", "role": "we0" }} , 
 	{ "name": "image_diff_posterize_rowC_3_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "image_diff_posterize_rowC_3", "role": "d0" }} , 
 	{ "name": "image_diff_posterize_rowC_4_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "image_diff_posterize_rowC_4", "role": "address0" }} , 
 	{ "name": "image_diff_posterize_rowC_4_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "image_diff_posterize_rowC_4", "role": "ce0" }} , 
 	{ "name": "image_diff_posterize_rowC_4_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "image_diff_posterize_rowC_4", "role": "we0" }} , 
 	{ "name": "image_diff_posterize_rowC_4_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "image_diff_posterize_rowC_4", "role": "d0" }} , 
 	{ "name": "image_diff_posterize_rowC_5_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "image_diff_posterize_rowC_5", "role": "address0" }} , 
 	{ "name": "image_diff_posterize_rowC_5_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "image_diff_posterize_rowC_5", "role": "ce0" }} , 
 	{ "name": "image_diff_posterize_rowC_5_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "image_diff_posterize_rowC_5", "role": "we0" }} , 
 	{ "name": "image_diff_posterize_rowC_5_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "image_diff_posterize_rowC_5", "role": "d0" }} , 
 	{ "name": "image_diff_posterize_rowC_6_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "image_diff_posterize_rowC_6", "role": "address0" }} , 
 	{ "name": "image_diff_posterize_rowC_6_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "image_diff_posterize_rowC_6", "role": "ce0" }} , 
 	{ "name": "image_diff_posterize_rowC_6_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "image_diff_posterize_rowC_6", "role": "we0" }} , 
 	{ "name": "image_diff_posterize_rowC_6_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "image_diff_posterize_rowC_6", "role": "d0" }} , 
 	{ "name": "image_diff_posterize_rowC_7_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "image_diff_posterize_rowC_7", "role": "address0" }} , 
 	{ "name": "image_diff_posterize_rowC_7_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "image_diff_posterize_rowC_7", "role": "ce0" }} , 
 	{ "name": "image_diff_posterize_rowC_7_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "image_diff_posterize_rowC_7", "role": "we0" }} , 
 	{ "name": "image_diff_posterize_rowC_7_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "image_diff_posterize_rowC_7", "role": "d0" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1"],
		"CDFG" : "Col_Loop_proc",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "1", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "34", "EstimateLatencyMax" : "34",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "1",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "image_diff_posterize_rowA_0", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["0"], "DependentChan" : "0"},
			{"Name" : "image_diff_posterize_rowA_1", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["0"], "DependentChan" : "0"},
			{"Name" : "image_diff_posterize_rowA_2", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["0"], "DependentChan" : "0"},
			{"Name" : "image_diff_posterize_rowA_3", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["0"], "DependentChan" : "0"},
			{"Name" : "image_diff_posterize_rowA_4", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["0"], "DependentChan" : "0"},
			{"Name" : "image_diff_posterize_rowA_5", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["0"], "DependentChan" : "0"},
			{"Name" : "image_diff_posterize_rowA_6", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["0"], "DependentChan" : "0"},
			{"Name" : "image_diff_posterize_rowA_7", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["0"], "DependentChan" : "0"},
			{"Name" : "image_diff_posterize_rowB_0", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["0"], "DependentChan" : "0"},
			{"Name" : "image_diff_posterize_rowB_1", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["0"], "DependentChan" : "0"},
			{"Name" : "image_diff_posterize_rowB_2", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["0"], "DependentChan" : "0"},
			{"Name" : "image_diff_posterize_rowB_3", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["0"], "DependentChan" : "0"},
			{"Name" : "image_diff_posterize_rowB_4", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["0"], "DependentChan" : "0"},
			{"Name" : "image_diff_posterize_rowB_5", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["0"], "DependentChan" : "0"},
			{"Name" : "image_diff_posterize_rowB_6", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["0"], "DependentChan" : "0"},
			{"Name" : "image_diff_posterize_rowB_7", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["0"], "DependentChan" : "0"},
			{"Name" : "image_diff_posterize_rowC_0", "Type" : "Memory", "Direction" : "O", "DependentProc" : ["0"], "DependentChan" : "0"},
			{"Name" : "image_diff_posterize_rowC_1", "Type" : "Memory", "Direction" : "O", "DependentProc" : ["0"], "DependentChan" : "0"},
			{"Name" : "image_diff_posterize_rowC_2", "Type" : "Memory", "Direction" : "O", "DependentProc" : ["0"], "DependentChan" : "0"},
			{"Name" : "image_diff_posterize_rowC_3", "Type" : "Memory", "Direction" : "O", "DependentProc" : ["0"], "DependentChan" : "0"},
			{"Name" : "image_diff_posterize_rowC_4", "Type" : "Memory", "Direction" : "O", "DependentProc" : ["0"], "DependentChan" : "0"},
			{"Name" : "image_diff_posterize_rowC_5", "Type" : "Memory", "Direction" : "O", "DependentProc" : ["0"], "DependentChan" : "0"},
			{"Name" : "image_diff_posterize_rowC_6", "Type" : "Memory", "Direction" : "O", "DependentProc" : ["0"], "DependentChan" : "0"},
			{"Name" : "image_diff_posterize_rowC_7", "Type" : "Memory", "Direction" : "O", "DependentProc" : ["0"], "DependentChan" : "0"}],
		"Loop" : [
			{"Name" : "Col_Loop", "PipelineType" : "UPC",
				"LoopDec" : {"FSMBitwidth" : "1", "FirstState" : "ap_ST_fsm_pp0_stage0", "FirstStateIter" : "ap_enable_reg_pp0_iter0", "FirstStateBlock" : "ap_block_pp0_stage0_subdone", "LastState" : "ap_ST_fsm_pp0_stage0", "LastStateIter" : "ap_enable_reg_pp0_iter1", "LastStateBlock" : "ap_block_pp0_stage0_subdone", "QuitState" : "ap_ST_fsm_pp0_stage0", "QuitStateIter" : "ap_enable_reg_pp0_iter0", "QuitStateBlock" : "ap_block_pp0_stage0_subdone", "OneDepthLoop" : "0", "has_ap_ctrl" : "1", "has_continue" : "1"}}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.flow_control_loop_pipe_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	Col_Loop_proc {
		image_diff_posterize_rowA_0 {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowA_1 {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowA_2 {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowA_3 {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowA_4 {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowA_5 {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowA_6 {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowA_7 {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowB_0 {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowB_1 {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowB_2 {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowB_3 {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowB_4 {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowB_5 {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowB_6 {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowB_7 {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowC_0 {Type O LastRead -1 FirstWrite 1}
		image_diff_posterize_rowC_1 {Type O LastRead -1 FirstWrite 1}
		image_diff_posterize_rowC_2 {Type O LastRead -1 FirstWrite 1}
		image_diff_posterize_rowC_3 {Type O LastRead -1 FirstWrite 1}
		image_diff_posterize_rowC_4 {Type O LastRead -1 FirstWrite 1}
		image_diff_posterize_rowC_5 {Type O LastRead -1 FirstWrite 1}
		image_diff_posterize_rowC_6 {Type O LastRead -1 FirstWrite 1}
		image_diff_posterize_rowC_7 {Type O LastRead -1 FirstWrite 1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "34", "Max" : "34"}
	, {"Name" : "Interval", "Min" : "34", "Max" : "34"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	image_diff_posterize_rowA_0 { ap_memory {  { image_diff_posterize_rowA_0_address0 mem_address 1 5 }  { image_diff_posterize_rowA_0_ce0 mem_ce 1 1 }  { image_diff_posterize_rowA_0_q0 in_data 0 8 } } }
	image_diff_posterize_rowA_1 { ap_memory {  { image_diff_posterize_rowA_1_address0 mem_address 1 5 }  { image_diff_posterize_rowA_1_ce0 mem_ce 1 1 }  { image_diff_posterize_rowA_1_q0 in_data 0 8 } } }
	image_diff_posterize_rowA_2 { ap_memory {  { image_diff_posterize_rowA_2_address0 mem_address 1 5 }  { image_diff_posterize_rowA_2_ce0 mem_ce 1 1 }  { image_diff_posterize_rowA_2_q0 in_data 0 8 } } }
	image_diff_posterize_rowA_3 { ap_memory {  { image_diff_posterize_rowA_3_address0 mem_address 1 5 }  { image_diff_posterize_rowA_3_ce0 mem_ce 1 1 }  { image_diff_posterize_rowA_3_q0 in_data 0 8 } } }
	image_diff_posterize_rowA_4 { ap_memory {  { image_diff_posterize_rowA_4_address0 mem_address 1 5 }  { image_diff_posterize_rowA_4_ce0 mem_ce 1 1 }  { image_diff_posterize_rowA_4_q0 in_data 0 8 } } }
	image_diff_posterize_rowA_5 { ap_memory {  { image_diff_posterize_rowA_5_address0 mem_address 1 5 }  { image_diff_posterize_rowA_5_ce0 mem_ce 1 1 }  { image_diff_posterize_rowA_5_q0 in_data 0 8 } } }
	image_diff_posterize_rowA_6 { ap_memory {  { image_diff_posterize_rowA_6_address0 mem_address 1 5 }  { image_diff_posterize_rowA_6_ce0 mem_ce 1 1 }  { image_diff_posterize_rowA_6_q0 in_data 0 8 } } }
	image_diff_posterize_rowA_7 { ap_memory {  { image_diff_posterize_rowA_7_address0 mem_address 1 5 }  { image_diff_posterize_rowA_7_ce0 mem_ce 1 1 }  { image_diff_posterize_rowA_7_q0 in_data 0 8 } } }
	image_diff_posterize_rowB_0 { ap_memory {  { image_diff_posterize_rowB_0_address0 mem_address 1 5 }  { image_diff_posterize_rowB_0_ce0 mem_ce 1 1 }  { image_diff_posterize_rowB_0_q0 in_data 0 8 } } }
	image_diff_posterize_rowB_1 { ap_memory {  { image_diff_posterize_rowB_1_address0 mem_address 1 5 }  { image_diff_posterize_rowB_1_ce0 mem_ce 1 1 }  { image_diff_posterize_rowB_1_q0 in_data 0 8 } } }
	image_diff_posterize_rowB_2 { ap_memory {  { image_diff_posterize_rowB_2_address0 mem_address 1 5 }  { image_diff_posterize_rowB_2_ce0 mem_ce 1 1 }  { image_diff_posterize_rowB_2_q0 in_data 0 8 } } }
	image_diff_posterize_rowB_3 { ap_memory {  { image_diff_posterize_rowB_3_address0 mem_address 1 5 }  { image_diff_posterize_rowB_3_ce0 mem_ce 1 1 }  { image_diff_posterize_rowB_3_q0 in_data 0 8 } } }
	image_diff_posterize_rowB_4 { ap_memory {  { image_diff_posterize_rowB_4_address0 mem_address 1 5 }  { image_diff_posterize_rowB_4_ce0 mem_ce 1 1 }  { image_diff_posterize_rowB_4_q0 in_data 0 8 } } }
	image_diff_posterize_rowB_5 { ap_memory {  { image_diff_posterize_rowB_5_address0 mem_address 1 5 }  { image_diff_posterize_rowB_5_ce0 mem_ce 1 1 }  { image_diff_posterize_rowB_5_q0 in_data 0 8 } } }
	image_diff_posterize_rowB_6 { ap_memory {  { image_diff_posterize_rowB_6_address0 mem_address 1 5 }  { image_diff_posterize_rowB_6_ce0 mem_ce 1 1 }  { image_diff_posterize_rowB_6_q0 in_data 0 8 } } }
	image_diff_posterize_rowB_7 { ap_memory {  { image_diff_posterize_rowB_7_address0 mem_address 1 5 }  { image_diff_posterize_rowB_7_ce0 mem_ce 1 1 }  { image_diff_posterize_rowB_7_q0 in_data 0 8 } } }
	image_diff_posterize_rowC_0 { ap_memory {  { image_diff_posterize_rowC_0_address0 mem_address 1 5 }  { image_diff_posterize_rowC_0_ce0 mem_ce 1 1 }  { image_diff_posterize_rowC_0_we0 mem_we 1 1 }  { image_diff_posterize_rowC_0_d0 mem_din 1 8 } } }
	image_diff_posterize_rowC_1 { ap_memory {  { image_diff_posterize_rowC_1_address0 mem_address 1 5 }  { image_diff_posterize_rowC_1_ce0 mem_ce 1 1 }  { image_diff_posterize_rowC_1_we0 mem_we 1 1 }  { image_diff_posterize_rowC_1_d0 mem_din 1 8 } } }
	image_diff_posterize_rowC_2 { ap_memory {  { image_diff_posterize_rowC_2_address0 mem_address 1 5 }  { image_diff_posterize_rowC_2_ce0 mem_ce 1 1 }  { image_diff_posterize_rowC_2_we0 mem_we 1 1 }  { image_diff_posterize_rowC_2_d0 mem_din 1 8 } } }
	image_diff_posterize_rowC_3 { ap_memory {  { image_diff_posterize_rowC_3_address0 mem_address 1 5 }  { image_diff_posterize_rowC_3_ce0 mem_ce 1 1 }  { image_diff_posterize_rowC_3_we0 mem_we 1 1 }  { image_diff_posterize_rowC_3_d0 mem_din 1 8 } } }
	image_diff_posterize_rowC_4 { ap_memory {  { image_diff_posterize_rowC_4_address0 mem_address 1 5 }  { image_diff_posterize_rowC_4_ce0 mem_ce 1 1 }  { image_diff_posterize_rowC_4_we0 mem_we 1 1 }  { image_diff_posterize_rowC_4_d0 mem_din 1 8 } } }
	image_diff_posterize_rowC_5 { ap_memory {  { image_diff_posterize_rowC_5_address0 mem_address 1 5 }  { image_diff_posterize_rowC_5_ce0 mem_ce 1 1 }  { image_diff_posterize_rowC_5_we0 mem_we 1 1 }  { image_diff_posterize_rowC_5_d0 mem_din 1 8 } } }
	image_diff_posterize_rowC_6 { ap_memory {  { image_diff_posterize_rowC_6_address0 mem_address 1 5 }  { image_diff_posterize_rowC_6_ce0 mem_ce 1 1 }  { image_diff_posterize_rowC_6_we0 mem_we 1 1 }  { image_diff_posterize_rowC_6_d0 mem_din 1 8 } } }
	image_diff_posterize_rowC_7 { ap_memory {  { image_diff_posterize_rowC_7_address0 mem_address 1 5 }  { image_diff_posterize_rowC_7_ce0 mem_ce 1 1 }  { image_diff_posterize_rowC_7_we0 mem_we 1 1 }  { image_diff_posterize_rowC_7_d0 mem_din 1 8 } } }
}

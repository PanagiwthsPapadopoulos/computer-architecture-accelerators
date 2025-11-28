set moduleName image_diff_posterize
set isTopModule 1
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
set C_modelName {image_diff_posterize}
set C_modelType { void 0 }
set C_modelArgList {
	{ gmem0 int 8 regular {axi_master 0}  }
	{ gmem1 int 8 regular {axi_master 0}  }
	{ gmem2 int 8 regular {axi_master 1}  }
	{ A int 64 regular {axi_slave 0}  }
	{ B int 64 regular {axi_slave 0}  }
	{ C int 64 regular {axi_slave 0}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "gmem0", "interface" : "axi_master", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[ {"cElement": [{"cName": "A","offset": { "type": "dynamic","port_name": "A","bundle": "control"},"direction": "READONLY"}]}]} , 
 	{ "Name" : "gmem1", "interface" : "axi_master", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[ {"cElement": [{"cName": "B","offset": { "type": "dynamic","port_name": "B","bundle": "control"},"direction": "READONLY"}]}]} , 
 	{ "Name" : "gmem2", "interface" : "axi_master", "bitwidth" : 8, "direction" : "WRITEONLY", "bitSlice":[ {"cElement": [{"cName": "C","offset": { "type": "dynamic","port_name": "C","bundle": "control"},"direction": "WRITEONLY"}]}]} , 
 	{ "Name" : "A", "interface" : "axi_slave", "bundle":"control","type":"ap_none","bitwidth" : 64, "direction" : "READONLY", "offset" : {"in":16}, "offset_end" : {"in":27}} , 
 	{ "Name" : "B", "interface" : "axi_slave", "bundle":"control","type":"ap_none","bitwidth" : 64, "direction" : "READONLY", "offset" : {"in":28}, "offset_end" : {"in":39}} , 
 	{ "Name" : "C", "interface" : "axi_slave", "bundle":"control","type":"ap_none","bitwidth" : 64, "direction" : "READONLY", "offset" : {"in":40}, "offset_end" : {"in":51}} ]}
# RTL Port declarations: 
set portNum 155
set portList { 
	{ s_axi_control_AWVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_AWREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_AWADDR sc_in sc_lv 6 signal -1 } 
	{ s_axi_control_WVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_WREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_WDATA sc_in sc_lv 32 signal -1 } 
	{ s_axi_control_WSTRB sc_in sc_lv 4 signal -1 } 
	{ s_axi_control_ARVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_ARREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_ARADDR sc_in sc_lv 6 signal -1 } 
	{ s_axi_control_RVALID sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_RREADY sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_RDATA sc_out sc_lv 32 signal -1 } 
	{ s_axi_control_RRESP sc_out sc_lv 2 signal -1 } 
	{ s_axi_control_BVALID sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_BREADY sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_BRESP sc_out sc_lv 2 signal -1 } 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst_n sc_in sc_logic 1 reset -1 active_low_sync } 
	{ interrupt sc_out sc_logic 1 signal -1 } 
	{ m_axi_gmem0_AWVALID sc_out sc_logic 1 signal 0 } 
	{ m_axi_gmem0_AWREADY sc_in sc_logic 1 signal 0 } 
	{ m_axi_gmem0_AWADDR sc_out sc_lv 64 signal 0 } 
	{ m_axi_gmem0_AWID sc_out sc_lv 1 signal 0 } 
	{ m_axi_gmem0_AWLEN sc_out sc_lv 8 signal 0 } 
	{ m_axi_gmem0_AWSIZE sc_out sc_lv 3 signal 0 } 
	{ m_axi_gmem0_AWBURST sc_out sc_lv 2 signal 0 } 
	{ m_axi_gmem0_AWLOCK sc_out sc_lv 2 signal 0 } 
	{ m_axi_gmem0_AWCACHE sc_out sc_lv 4 signal 0 } 
	{ m_axi_gmem0_AWPROT sc_out sc_lv 3 signal 0 } 
	{ m_axi_gmem0_AWQOS sc_out sc_lv 4 signal 0 } 
	{ m_axi_gmem0_AWREGION sc_out sc_lv 4 signal 0 } 
	{ m_axi_gmem0_AWUSER sc_out sc_lv 1 signal 0 } 
	{ m_axi_gmem0_WVALID sc_out sc_logic 1 signal 0 } 
	{ m_axi_gmem0_WREADY sc_in sc_logic 1 signal 0 } 
	{ m_axi_gmem0_WDATA sc_out sc_lv 32 signal 0 } 
	{ m_axi_gmem0_WSTRB sc_out sc_lv 4 signal 0 } 
	{ m_axi_gmem0_WLAST sc_out sc_logic 1 signal 0 } 
	{ m_axi_gmem0_WID sc_out sc_lv 1 signal 0 } 
	{ m_axi_gmem0_WUSER sc_out sc_lv 1 signal 0 } 
	{ m_axi_gmem0_ARVALID sc_out sc_logic 1 signal 0 } 
	{ m_axi_gmem0_ARREADY sc_in sc_logic 1 signal 0 } 
	{ m_axi_gmem0_ARADDR sc_out sc_lv 64 signal 0 } 
	{ m_axi_gmem0_ARID sc_out sc_lv 1 signal 0 } 
	{ m_axi_gmem0_ARLEN sc_out sc_lv 8 signal 0 } 
	{ m_axi_gmem0_ARSIZE sc_out sc_lv 3 signal 0 } 
	{ m_axi_gmem0_ARBURST sc_out sc_lv 2 signal 0 } 
	{ m_axi_gmem0_ARLOCK sc_out sc_lv 2 signal 0 } 
	{ m_axi_gmem0_ARCACHE sc_out sc_lv 4 signal 0 } 
	{ m_axi_gmem0_ARPROT sc_out sc_lv 3 signal 0 } 
	{ m_axi_gmem0_ARQOS sc_out sc_lv 4 signal 0 } 
	{ m_axi_gmem0_ARREGION sc_out sc_lv 4 signal 0 } 
	{ m_axi_gmem0_ARUSER sc_out sc_lv 1 signal 0 } 
	{ m_axi_gmem0_RVALID sc_in sc_logic 1 signal 0 } 
	{ m_axi_gmem0_RREADY sc_out sc_logic 1 signal 0 } 
	{ m_axi_gmem0_RDATA sc_in sc_lv 32 signal 0 } 
	{ m_axi_gmem0_RLAST sc_in sc_logic 1 signal 0 } 
	{ m_axi_gmem0_RID sc_in sc_lv 1 signal 0 } 
	{ m_axi_gmem0_RUSER sc_in sc_lv 1 signal 0 } 
	{ m_axi_gmem0_RRESP sc_in sc_lv 2 signal 0 } 
	{ m_axi_gmem0_BVALID sc_in sc_logic 1 signal 0 } 
	{ m_axi_gmem0_BREADY sc_out sc_logic 1 signal 0 } 
	{ m_axi_gmem0_BRESP sc_in sc_lv 2 signal 0 } 
	{ m_axi_gmem0_BID sc_in sc_lv 1 signal 0 } 
	{ m_axi_gmem0_BUSER sc_in sc_lv 1 signal 0 } 
	{ m_axi_gmem1_AWVALID sc_out sc_logic 1 signal 1 } 
	{ m_axi_gmem1_AWREADY sc_in sc_logic 1 signal 1 } 
	{ m_axi_gmem1_AWADDR sc_out sc_lv 64 signal 1 } 
	{ m_axi_gmem1_AWID sc_out sc_lv 1 signal 1 } 
	{ m_axi_gmem1_AWLEN sc_out sc_lv 8 signal 1 } 
	{ m_axi_gmem1_AWSIZE sc_out sc_lv 3 signal 1 } 
	{ m_axi_gmem1_AWBURST sc_out sc_lv 2 signal 1 } 
	{ m_axi_gmem1_AWLOCK sc_out sc_lv 2 signal 1 } 
	{ m_axi_gmem1_AWCACHE sc_out sc_lv 4 signal 1 } 
	{ m_axi_gmem1_AWPROT sc_out sc_lv 3 signal 1 } 
	{ m_axi_gmem1_AWQOS sc_out sc_lv 4 signal 1 } 
	{ m_axi_gmem1_AWREGION sc_out sc_lv 4 signal 1 } 
	{ m_axi_gmem1_AWUSER sc_out sc_lv 1 signal 1 } 
	{ m_axi_gmem1_WVALID sc_out sc_logic 1 signal 1 } 
	{ m_axi_gmem1_WREADY sc_in sc_logic 1 signal 1 } 
	{ m_axi_gmem1_WDATA sc_out sc_lv 32 signal 1 } 
	{ m_axi_gmem1_WSTRB sc_out sc_lv 4 signal 1 } 
	{ m_axi_gmem1_WLAST sc_out sc_logic 1 signal 1 } 
	{ m_axi_gmem1_WID sc_out sc_lv 1 signal 1 } 
	{ m_axi_gmem1_WUSER sc_out sc_lv 1 signal 1 } 
	{ m_axi_gmem1_ARVALID sc_out sc_logic 1 signal 1 } 
	{ m_axi_gmem1_ARREADY sc_in sc_logic 1 signal 1 } 
	{ m_axi_gmem1_ARADDR sc_out sc_lv 64 signal 1 } 
	{ m_axi_gmem1_ARID sc_out sc_lv 1 signal 1 } 
	{ m_axi_gmem1_ARLEN sc_out sc_lv 8 signal 1 } 
	{ m_axi_gmem1_ARSIZE sc_out sc_lv 3 signal 1 } 
	{ m_axi_gmem1_ARBURST sc_out sc_lv 2 signal 1 } 
	{ m_axi_gmem1_ARLOCK sc_out sc_lv 2 signal 1 } 
	{ m_axi_gmem1_ARCACHE sc_out sc_lv 4 signal 1 } 
	{ m_axi_gmem1_ARPROT sc_out sc_lv 3 signal 1 } 
	{ m_axi_gmem1_ARQOS sc_out sc_lv 4 signal 1 } 
	{ m_axi_gmem1_ARREGION sc_out sc_lv 4 signal 1 } 
	{ m_axi_gmem1_ARUSER sc_out sc_lv 1 signal 1 } 
	{ m_axi_gmem1_RVALID sc_in sc_logic 1 signal 1 } 
	{ m_axi_gmem1_RREADY sc_out sc_logic 1 signal 1 } 
	{ m_axi_gmem1_RDATA sc_in sc_lv 32 signal 1 } 
	{ m_axi_gmem1_RLAST sc_in sc_logic 1 signal 1 } 
	{ m_axi_gmem1_RID sc_in sc_lv 1 signal 1 } 
	{ m_axi_gmem1_RUSER sc_in sc_lv 1 signal 1 } 
	{ m_axi_gmem1_RRESP sc_in sc_lv 2 signal 1 } 
	{ m_axi_gmem1_BVALID sc_in sc_logic 1 signal 1 } 
	{ m_axi_gmem1_BREADY sc_out sc_logic 1 signal 1 } 
	{ m_axi_gmem1_BRESP sc_in sc_lv 2 signal 1 } 
	{ m_axi_gmem1_BID sc_in sc_lv 1 signal 1 } 
	{ m_axi_gmem1_BUSER sc_in sc_lv 1 signal 1 } 
	{ m_axi_gmem2_AWVALID sc_out sc_logic 1 signal 2 } 
	{ m_axi_gmem2_AWREADY sc_in sc_logic 1 signal 2 } 
	{ m_axi_gmem2_AWADDR sc_out sc_lv 64 signal 2 } 
	{ m_axi_gmem2_AWID sc_out sc_lv 1 signal 2 } 
	{ m_axi_gmem2_AWLEN sc_out sc_lv 8 signal 2 } 
	{ m_axi_gmem2_AWSIZE sc_out sc_lv 3 signal 2 } 
	{ m_axi_gmem2_AWBURST sc_out sc_lv 2 signal 2 } 
	{ m_axi_gmem2_AWLOCK sc_out sc_lv 2 signal 2 } 
	{ m_axi_gmem2_AWCACHE sc_out sc_lv 4 signal 2 } 
	{ m_axi_gmem2_AWPROT sc_out sc_lv 3 signal 2 } 
	{ m_axi_gmem2_AWQOS sc_out sc_lv 4 signal 2 } 
	{ m_axi_gmem2_AWREGION sc_out sc_lv 4 signal 2 } 
	{ m_axi_gmem2_AWUSER sc_out sc_lv 1 signal 2 } 
	{ m_axi_gmem2_WVALID sc_out sc_logic 1 signal 2 } 
	{ m_axi_gmem2_WREADY sc_in sc_logic 1 signal 2 } 
	{ m_axi_gmem2_WDATA sc_out sc_lv 32 signal 2 } 
	{ m_axi_gmem2_WSTRB sc_out sc_lv 4 signal 2 } 
	{ m_axi_gmem2_WLAST sc_out sc_logic 1 signal 2 } 
	{ m_axi_gmem2_WID sc_out sc_lv 1 signal 2 } 
	{ m_axi_gmem2_WUSER sc_out sc_lv 1 signal 2 } 
	{ m_axi_gmem2_ARVALID sc_out sc_logic 1 signal 2 } 
	{ m_axi_gmem2_ARREADY sc_in sc_logic 1 signal 2 } 
	{ m_axi_gmem2_ARADDR sc_out sc_lv 64 signal 2 } 
	{ m_axi_gmem2_ARID sc_out sc_lv 1 signal 2 } 
	{ m_axi_gmem2_ARLEN sc_out sc_lv 8 signal 2 } 
	{ m_axi_gmem2_ARSIZE sc_out sc_lv 3 signal 2 } 
	{ m_axi_gmem2_ARBURST sc_out sc_lv 2 signal 2 } 
	{ m_axi_gmem2_ARLOCK sc_out sc_lv 2 signal 2 } 
	{ m_axi_gmem2_ARCACHE sc_out sc_lv 4 signal 2 } 
	{ m_axi_gmem2_ARPROT sc_out sc_lv 3 signal 2 } 
	{ m_axi_gmem2_ARQOS sc_out sc_lv 4 signal 2 } 
	{ m_axi_gmem2_ARREGION sc_out sc_lv 4 signal 2 } 
	{ m_axi_gmem2_ARUSER sc_out sc_lv 1 signal 2 } 
	{ m_axi_gmem2_RVALID sc_in sc_logic 1 signal 2 } 
	{ m_axi_gmem2_RREADY sc_out sc_logic 1 signal 2 } 
	{ m_axi_gmem2_RDATA sc_in sc_lv 32 signal 2 } 
	{ m_axi_gmem2_RLAST sc_in sc_logic 1 signal 2 } 
	{ m_axi_gmem2_RID sc_in sc_lv 1 signal 2 } 
	{ m_axi_gmem2_RUSER sc_in sc_lv 1 signal 2 } 
	{ m_axi_gmem2_RRESP sc_in sc_lv 2 signal 2 } 
	{ m_axi_gmem2_BVALID sc_in sc_logic 1 signal 2 } 
	{ m_axi_gmem2_BREADY sc_out sc_logic 1 signal 2 } 
	{ m_axi_gmem2_BRESP sc_in sc_lv 2 signal 2 } 
	{ m_axi_gmem2_BID sc_in sc_lv 1 signal 2 } 
	{ m_axi_gmem2_BUSER sc_in sc_lv 1 signal 2 } 
}
set NewPortList {[ 
	{ "name": "s_axi_control_AWADDR", "direction": "in", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "control", "role": "AWADDR" },"address":[{"name":"image_diff_posterize","role":"start","value":"0","valid_bit":"0"},{"name":"image_diff_posterize","role":"continue","value":"0","valid_bit":"4"},{"name":"image_diff_posterize","role":"auto_start","value":"0","valid_bit":"7"},{"name":"A","role":"data","value":"16"},{"name":"B","role":"data","value":"28"},{"name":"C","role":"data","value":"40"}] },
	{ "name": "s_axi_control_AWVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "AWVALID" } },
	{ "name": "s_axi_control_AWREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "AWREADY" } },
	{ "name": "s_axi_control_WVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "WVALID" } },
	{ "name": "s_axi_control_WREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "WREADY" } },
	{ "name": "s_axi_control_WDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "control", "role": "WDATA" } },
	{ "name": "s_axi_control_WSTRB", "direction": "in", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "control", "role": "WSTRB" } },
	{ "name": "s_axi_control_ARADDR", "direction": "in", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "control", "role": "ARADDR" },"address":[{"name":"image_diff_posterize","role":"start","value":"0","valid_bit":"0"},{"name":"image_diff_posterize","role":"done","value":"0","valid_bit":"1"},{"name":"image_diff_posterize","role":"idle","value":"0","valid_bit":"2"},{"name":"image_diff_posterize","role":"ready","value":"0","valid_bit":"3"},{"name":"image_diff_posterize","role":"auto_start","value":"0","valid_bit":"7"}] },
	{ "name": "s_axi_control_ARVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "ARVALID" } },
	{ "name": "s_axi_control_ARREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "ARREADY" } },
	{ "name": "s_axi_control_RVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "RVALID" } },
	{ "name": "s_axi_control_RREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "RREADY" } },
	{ "name": "s_axi_control_RDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "control", "role": "RDATA" } },
	{ "name": "s_axi_control_RRESP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "control", "role": "RRESP" } },
	{ "name": "s_axi_control_BVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "BVALID" } },
	{ "name": "s_axi_control_BREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "BREADY" } },
	{ "name": "s_axi_control_BRESP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "control", "role": "BRESP" } },
	{ "name": "interrupt", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "interrupt" } }, 
 	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst_n", "role": "default" }} , 
 	{ "name": "m_axi_gmem0_AWVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem0", "role": "AWVALID" }} , 
 	{ "name": "m_axi_gmem0_AWREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem0", "role": "AWREADY" }} , 
 	{ "name": "m_axi_gmem0_AWADDR", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "gmem0", "role": "AWADDR" }} , 
 	{ "name": "m_axi_gmem0_AWID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem0", "role": "AWID" }} , 
 	{ "name": "m_axi_gmem0_AWLEN", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "gmem0", "role": "AWLEN" }} , 
 	{ "name": "m_axi_gmem0_AWSIZE", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "gmem0", "role": "AWSIZE" }} , 
 	{ "name": "m_axi_gmem0_AWBURST", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "gmem0", "role": "AWBURST" }} , 
 	{ "name": "m_axi_gmem0_AWLOCK", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "gmem0", "role": "AWLOCK" }} , 
 	{ "name": "m_axi_gmem0_AWCACHE", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "gmem0", "role": "AWCACHE" }} , 
 	{ "name": "m_axi_gmem0_AWPROT", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "gmem0", "role": "AWPROT" }} , 
 	{ "name": "m_axi_gmem0_AWQOS", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "gmem0", "role": "AWQOS" }} , 
 	{ "name": "m_axi_gmem0_AWREGION", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "gmem0", "role": "AWREGION" }} , 
 	{ "name": "m_axi_gmem0_AWUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem0", "role": "AWUSER" }} , 
 	{ "name": "m_axi_gmem0_WVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem0", "role": "WVALID" }} , 
 	{ "name": "m_axi_gmem0_WREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem0", "role": "WREADY" }} , 
 	{ "name": "m_axi_gmem0_WDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "gmem0", "role": "WDATA" }} , 
 	{ "name": "m_axi_gmem0_WSTRB", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "gmem0", "role": "WSTRB" }} , 
 	{ "name": "m_axi_gmem0_WLAST", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem0", "role": "WLAST" }} , 
 	{ "name": "m_axi_gmem0_WID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem0", "role": "WID" }} , 
 	{ "name": "m_axi_gmem0_WUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem0", "role": "WUSER" }} , 
 	{ "name": "m_axi_gmem0_ARVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem0", "role": "ARVALID" }} , 
 	{ "name": "m_axi_gmem0_ARREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem0", "role": "ARREADY" }} , 
 	{ "name": "m_axi_gmem0_ARADDR", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "gmem0", "role": "ARADDR" }} , 
 	{ "name": "m_axi_gmem0_ARID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem0", "role": "ARID" }} , 
 	{ "name": "m_axi_gmem0_ARLEN", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "gmem0", "role": "ARLEN" }} , 
 	{ "name": "m_axi_gmem0_ARSIZE", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "gmem0", "role": "ARSIZE" }} , 
 	{ "name": "m_axi_gmem0_ARBURST", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "gmem0", "role": "ARBURST" }} , 
 	{ "name": "m_axi_gmem0_ARLOCK", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "gmem0", "role": "ARLOCK" }} , 
 	{ "name": "m_axi_gmem0_ARCACHE", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "gmem0", "role": "ARCACHE" }} , 
 	{ "name": "m_axi_gmem0_ARPROT", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "gmem0", "role": "ARPROT" }} , 
 	{ "name": "m_axi_gmem0_ARQOS", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "gmem0", "role": "ARQOS" }} , 
 	{ "name": "m_axi_gmem0_ARREGION", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "gmem0", "role": "ARREGION" }} , 
 	{ "name": "m_axi_gmem0_ARUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem0", "role": "ARUSER" }} , 
 	{ "name": "m_axi_gmem0_RVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem0", "role": "RVALID" }} , 
 	{ "name": "m_axi_gmem0_RREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem0", "role": "RREADY" }} , 
 	{ "name": "m_axi_gmem0_RDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "gmem0", "role": "RDATA" }} , 
 	{ "name": "m_axi_gmem0_RLAST", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem0", "role": "RLAST" }} , 
 	{ "name": "m_axi_gmem0_RID", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem0", "role": "RID" }} , 
 	{ "name": "m_axi_gmem0_RUSER", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem0", "role": "RUSER" }} , 
 	{ "name": "m_axi_gmem0_RRESP", "direction": "in", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "gmem0", "role": "RRESP" }} , 
 	{ "name": "m_axi_gmem0_BVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem0", "role": "BVALID" }} , 
 	{ "name": "m_axi_gmem0_BREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem0", "role": "BREADY" }} , 
 	{ "name": "m_axi_gmem0_BRESP", "direction": "in", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "gmem0", "role": "BRESP" }} , 
 	{ "name": "m_axi_gmem0_BID", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem0", "role": "BID" }} , 
 	{ "name": "m_axi_gmem0_BUSER", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem0", "role": "BUSER" }} , 
 	{ "name": "m_axi_gmem1_AWVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem1", "role": "AWVALID" }} , 
 	{ "name": "m_axi_gmem1_AWREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem1", "role": "AWREADY" }} , 
 	{ "name": "m_axi_gmem1_AWADDR", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "gmem1", "role": "AWADDR" }} , 
 	{ "name": "m_axi_gmem1_AWID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem1", "role": "AWID" }} , 
 	{ "name": "m_axi_gmem1_AWLEN", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "gmem1", "role": "AWLEN" }} , 
 	{ "name": "m_axi_gmem1_AWSIZE", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "gmem1", "role": "AWSIZE" }} , 
 	{ "name": "m_axi_gmem1_AWBURST", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "gmem1", "role": "AWBURST" }} , 
 	{ "name": "m_axi_gmem1_AWLOCK", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "gmem1", "role": "AWLOCK" }} , 
 	{ "name": "m_axi_gmem1_AWCACHE", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "gmem1", "role": "AWCACHE" }} , 
 	{ "name": "m_axi_gmem1_AWPROT", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "gmem1", "role": "AWPROT" }} , 
 	{ "name": "m_axi_gmem1_AWQOS", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "gmem1", "role": "AWQOS" }} , 
 	{ "name": "m_axi_gmem1_AWREGION", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "gmem1", "role": "AWREGION" }} , 
 	{ "name": "m_axi_gmem1_AWUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem1", "role": "AWUSER" }} , 
 	{ "name": "m_axi_gmem1_WVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem1", "role": "WVALID" }} , 
 	{ "name": "m_axi_gmem1_WREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem1", "role": "WREADY" }} , 
 	{ "name": "m_axi_gmem1_WDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "gmem1", "role": "WDATA" }} , 
 	{ "name": "m_axi_gmem1_WSTRB", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "gmem1", "role": "WSTRB" }} , 
 	{ "name": "m_axi_gmem1_WLAST", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem1", "role": "WLAST" }} , 
 	{ "name": "m_axi_gmem1_WID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem1", "role": "WID" }} , 
 	{ "name": "m_axi_gmem1_WUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem1", "role": "WUSER" }} , 
 	{ "name": "m_axi_gmem1_ARVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem1", "role": "ARVALID" }} , 
 	{ "name": "m_axi_gmem1_ARREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem1", "role": "ARREADY" }} , 
 	{ "name": "m_axi_gmem1_ARADDR", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "gmem1", "role": "ARADDR" }} , 
 	{ "name": "m_axi_gmem1_ARID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem1", "role": "ARID" }} , 
 	{ "name": "m_axi_gmem1_ARLEN", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "gmem1", "role": "ARLEN" }} , 
 	{ "name": "m_axi_gmem1_ARSIZE", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "gmem1", "role": "ARSIZE" }} , 
 	{ "name": "m_axi_gmem1_ARBURST", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "gmem1", "role": "ARBURST" }} , 
 	{ "name": "m_axi_gmem1_ARLOCK", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "gmem1", "role": "ARLOCK" }} , 
 	{ "name": "m_axi_gmem1_ARCACHE", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "gmem1", "role": "ARCACHE" }} , 
 	{ "name": "m_axi_gmem1_ARPROT", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "gmem1", "role": "ARPROT" }} , 
 	{ "name": "m_axi_gmem1_ARQOS", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "gmem1", "role": "ARQOS" }} , 
 	{ "name": "m_axi_gmem1_ARREGION", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "gmem1", "role": "ARREGION" }} , 
 	{ "name": "m_axi_gmem1_ARUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem1", "role": "ARUSER" }} , 
 	{ "name": "m_axi_gmem1_RVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem1", "role": "RVALID" }} , 
 	{ "name": "m_axi_gmem1_RREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem1", "role": "RREADY" }} , 
 	{ "name": "m_axi_gmem1_RDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "gmem1", "role": "RDATA" }} , 
 	{ "name": "m_axi_gmem1_RLAST", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem1", "role": "RLAST" }} , 
 	{ "name": "m_axi_gmem1_RID", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem1", "role": "RID" }} , 
 	{ "name": "m_axi_gmem1_RUSER", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem1", "role": "RUSER" }} , 
 	{ "name": "m_axi_gmem1_RRESP", "direction": "in", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "gmem1", "role": "RRESP" }} , 
 	{ "name": "m_axi_gmem1_BVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem1", "role": "BVALID" }} , 
 	{ "name": "m_axi_gmem1_BREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem1", "role": "BREADY" }} , 
 	{ "name": "m_axi_gmem1_BRESP", "direction": "in", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "gmem1", "role": "BRESP" }} , 
 	{ "name": "m_axi_gmem1_BID", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem1", "role": "BID" }} , 
 	{ "name": "m_axi_gmem1_BUSER", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem1", "role": "BUSER" }} , 
 	{ "name": "m_axi_gmem2_AWVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem2", "role": "AWVALID" }} , 
 	{ "name": "m_axi_gmem2_AWREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem2", "role": "AWREADY" }} , 
 	{ "name": "m_axi_gmem2_AWADDR", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "gmem2", "role": "AWADDR" }} , 
 	{ "name": "m_axi_gmem2_AWID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem2", "role": "AWID" }} , 
 	{ "name": "m_axi_gmem2_AWLEN", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "gmem2", "role": "AWLEN" }} , 
 	{ "name": "m_axi_gmem2_AWSIZE", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "gmem2", "role": "AWSIZE" }} , 
 	{ "name": "m_axi_gmem2_AWBURST", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "gmem2", "role": "AWBURST" }} , 
 	{ "name": "m_axi_gmem2_AWLOCK", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "gmem2", "role": "AWLOCK" }} , 
 	{ "name": "m_axi_gmem2_AWCACHE", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "gmem2", "role": "AWCACHE" }} , 
 	{ "name": "m_axi_gmem2_AWPROT", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "gmem2", "role": "AWPROT" }} , 
 	{ "name": "m_axi_gmem2_AWQOS", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "gmem2", "role": "AWQOS" }} , 
 	{ "name": "m_axi_gmem2_AWREGION", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "gmem2", "role": "AWREGION" }} , 
 	{ "name": "m_axi_gmem2_AWUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem2", "role": "AWUSER" }} , 
 	{ "name": "m_axi_gmem2_WVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem2", "role": "WVALID" }} , 
 	{ "name": "m_axi_gmem2_WREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem2", "role": "WREADY" }} , 
 	{ "name": "m_axi_gmem2_WDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "gmem2", "role": "WDATA" }} , 
 	{ "name": "m_axi_gmem2_WSTRB", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "gmem2", "role": "WSTRB" }} , 
 	{ "name": "m_axi_gmem2_WLAST", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem2", "role": "WLAST" }} , 
 	{ "name": "m_axi_gmem2_WID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem2", "role": "WID" }} , 
 	{ "name": "m_axi_gmem2_WUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem2", "role": "WUSER" }} , 
 	{ "name": "m_axi_gmem2_ARVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem2", "role": "ARVALID" }} , 
 	{ "name": "m_axi_gmem2_ARREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem2", "role": "ARREADY" }} , 
 	{ "name": "m_axi_gmem2_ARADDR", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "gmem2", "role": "ARADDR" }} , 
 	{ "name": "m_axi_gmem2_ARID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem2", "role": "ARID" }} , 
 	{ "name": "m_axi_gmem2_ARLEN", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "gmem2", "role": "ARLEN" }} , 
 	{ "name": "m_axi_gmem2_ARSIZE", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "gmem2", "role": "ARSIZE" }} , 
 	{ "name": "m_axi_gmem2_ARBURST", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "gmem2", "role": "ARBURST" }} , 
 	{ "name": "m_axi_gmem2_ARLOCK", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "gmem2", "role": "ARLOCK" }} , 
 	{ "name": "m_axi_gmem2_ARCACHE", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "gmem2", "role": "ARCACHE" }} , 
 	{ "name": "m_axi_gmem2_ARPROT", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "gmem2", "role": "ARPROT" }} , 
 	{ "name": "m_axi_gmem2_ARQOS", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "gmem2", "role": "ARQOS" }} , 
 	{ "name": "m_axi_gmem2_ARREGION", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "gmem2", "role": "ARREGION" }} , 
 	{ "name": "m_axi_gmem2_ARUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem2", "role": "ARUSER" }} , 
 	{ "name": "m_axi_gmem2_RVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem2", "role": "RVALID" }} , 
 	{ "name": "m_axi_gmem2_RREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem2", "role": "RREADY" }} , 
 	{ "name": "m_axi_gmem2_RDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "gmem2", "role": "RDATA" }} , 
 	{ "name": "m_axi_gmem2_RLAST", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem2", "role": "RLAST" }} , 
 	{ "name": "m_axi_gmem2_RID", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem2", "role": "RID" }} , 
 	{ "name": "m_axi_gmem2_RUSER", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem2", "role": "RUSER" }} , 
 	{ "name": "m_axi_gmem2_RRESP", "direction": "in", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "gmem2", "role": "RRESP" }} , 
 	{ "name": "m_axi_gmem2_BVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem2", "role": "BVALID" }} , 
 	{ "name": "m_axi_gmem2_BREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem2", "role": "BREADY" }} , 
 	{ "name": "m_axi_gmem2_BRESP", "direction": "in", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "gmem2", "role": "BRESP" }} , 
 	{ "name": "m_axi_gmem2_BID", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem2", "role": "BID" }} , 
 	{ "name": "m_axi_gmem2_BUSER", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "gmem2", "role": "BUSER" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5"],
		"CDFG" : "image_diff_posterize",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "Dataflow", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "1",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "69168", "EstimateLatencyMax" : "69168",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "1",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"InputProcess" : [
			{"ID" : "5", "Name" : "dataflow_in_loop_Row_Loop_U0"}],
		"OutputProcess" : [
			{"ID" : "5", "Name" : "dataflow_in_loop_Row_Loop_U0"}],
		"Port" : [
			{"Name" : "gmem0", "Type" : "MAXI", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "5", "SubInstance" : "dataflow_in_loop_Row_Loop_U0", "Port" : "gmem0"}]},
			{"Name" : "gmem1", "Type" : "MAXI", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "5", "SubInstance" : "dataflow_in_loop_Row_Loop_U0", "Port" : "gmem1"}]},
			{"Name" : "gmem2", "Type" : "MAXI", "Direction" : "O",
				"SubConnect" : [
					{"ID" : "5", "SubInstance" : "dataflow_in_loop_Row_Loop_U0", "Port" : "gmem2"}]},
			{"Name" : "A", "Type" : "None", "Direction" : "I"},
			{"Name" : "B", "Type" : "None", "Direction" : "I"},
			{"Name" : "C", "Type" : "None", "Direction" : "I"},
			{"Name" : "image_diff_posterize_rowA_0", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "5", "SubInstance" : "dataflow_in_loop_Row_Loop_U0", "Port" : "image_diff_posterize_rowA_0"}]},
			{"Name" : "image_diff_posterize_rowB_0", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "5", "SubInstance" : "dataflow_in_loop_Row_Loop_U0", "Port" : "image_diff_posterize_rowB_0"}]},
			{"Name" : "image_diff_posterize_rowA_1", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "5", "SubInstance" : "dataflow_in_loop_Row_Loop_U0", "Port" : "image_diff_posterize_rowA_1"}]},
			{"Name" : "image_diff_posterize_rowB_1", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "5", "SubInstance" : "dataflow_in_loop_Row_Loop_U0", "Port" : "image_diff_posterize_rowB_1"}]},
			{"Name" : "image_diff_posterize_rowA_2", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "5", "SubInstance" : "dataflow_in_loop_Row_Loop_U0", "Port" : "image_diff_posterize_rowA_2"}]},
			{"Name" : "image_diff_posterize_rowB_2", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "5", "SubInstance" : "dataflow_in_loop_Row_Loop_U0", "Port" : "image_diff_posterize_rowB_2"}]},
			{"Name" : "image_diff_posterize_rowA_3", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "5", "SubInstance" : "dataflow_in_loop_Row_Loop_U0", "Port" : "image_diff_posterize_rowA_3"}]},
			{"Name" : "image_diff_posterize_rowB_3", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "5", "SubInstance" : "dataflow_in_loop_Row_Loop_U0", "Port" : "image_diff_posterize_rowB_3"}]},
			{"Name" : "image_diff_posterize_rowA_4", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "5", "SubInstance" : "dataflow_in_loop_Row_Loop_U0", "Port" : "image_diff_posterize_rowA_4"}]},
			{"Name" : "image_diff_posterize_rowB_4", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "5", "SubInstance" : "dataflow_in_loop_Row_Loop_U0", "Port" : "image_diff_posterize_rowB_4"}]},
			{"Name" : "image_diff_posterize_rowA_5", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "5", "SubInstance" : "dataflow_in_loop_Row_Loop_U0", "Port" : "image_diff_posterize_rowA_5"}]},
			{"Name" : "image_diff_posterize_rowB_5", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "5", "SubInstance" : "dataflow_in_loop_Row_Loop_U0", "Port" : "image_diff_posterize_rowB_5"}]},
			{"Name" : "image_diff_posterize_rowA_6", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "5", "SubInstance" : "dataflow_in_loop_Row_Loop_U0", "Port" : "image_diff_posterize_rowA_6"}]},
			{"Name" : "image_diff_posterize_rowB_6", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "5", "SubInstance" : "dataflow_in_loop_Row_Loop_U0", "Port" : "image_diff_posterize_rowB_6"}]},
			{"Name" : "image_diff_posterize_rowA_7", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "5", "SubInstance" : "dataflow_in_loop_Row_Loop_U0", "Port" : "image_diff_posterize_rowA_7"}]},
			{"Name" : "image_diff_posterize_rowB_7", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "5", "SubInstance" : "dataflow_in_loop_Row_Loop_U0", "Port" : "image_diff_posterize_rowB_7"}]},
			{"Name" : "image_diff_posterize_rowC_0", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "5", "SubInstance" : "dataflow_in_loop_Row_Loop_U0", "Port" : "image_diff_posterize_rowC_0"}]},
			{"Name" : "image_diff_posterize_rowC_1", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "5", "SubInstance" : "dataflow_in_loop_Row_Loop_U0", "Port" : "image_diff_posterize_rowC_1"}]},
			{"Name" : "image_diff_posterize_rowC_2", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "5", "SubInstance" : "dataflow_in_loop_Row_Loop_U0", "Port" : "image_diff_posterize_rowC_2"}]},
			{"Name" : "image_diff_posterize_rowC_3", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "5", "SubInstance" : "dataflow_in_loop_Row_Loop_U0", "Port" : "image_diff_posterize_rowC_3"}]},
			{"Name" : "image_diff_posterize_rowC_4", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "5", "SubInstance" : "dataflow_in_loop_Row_Loop_U0", "Port" : "image_diff_posterize_rowC_4"}]},
			{"Name" : "image_diff_posterize_rowC_5", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "5", "SubInstance" : "dataflow_in_loop_Row_Loop_U0", "Port" : "image_diff_posterize_rowC_5"}]},
			{"Name" : "image_diff_posterize_rowC_6", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "5", "SubInstance" : "dataflow_in_loop_Row_Loop_U0", "Port" : "image_diff_posterize_rowC_6"}]},
			{"Name" : "image_diff_posterize_rowC_7", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "5", "SubInstance" : "dataflow_in_loop_Row_Loop_U0", "Port" : "image_diff_posterize_rowC_7"}]}],
		"Loop" : [
			{"Name" : "Row_Loop", "PipelineType" : "dataflow",
				"LoopDec" : {"InfiniteLoop" : "0", "BodyInst" : "dataflow_in_loop_Row_Loop_U0", "has_continue" : "0"}}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.control_s_axi_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.gmem0_m_axi_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.gmem1_m_axi_U", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.gmem2_m_axi_U", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0", "Parent" : "0", "Child" : ["6", "7", "10", "12", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41"],
		"CDFG" : "dataflow_in_loop_Row_Loop",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "1", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "Dataflow", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "1",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "571", "EstimateLatencyMax" : "571",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "1",
		"InDataflowNetwork" : "1",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"InputProcess" : [
			{"ID" : "6", "Name" : "entry_proc_U0"},
			{"ID" : "7", "Name" : "Read_Loop_proc_U0"}],
		"OutputProcess" : [
			{"ID" : "12", "Name" : "Write_Loop_proc_U0"}],
		"Port" : [
			{"Name" : "gmem0", "Type" : "MAXI", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "7", "SubInstance" : "Read_Loop_proc_U0", "Port" : "gmem0"}]},
			{"Name" : "i", "Type" : "None", "Direction" : "I"},
			{"Name" : "A", "Type" : "None", "Direction" : "I"},
			{"Name" : "gmem1", "Type" : "MAXI", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "7", "SubInstance" : "Read_Loop_proc_U0", "Port" : "gmem1"}]},
			{"Name" : "B", "Type" : "None", "Direction" : "I"},
			{"Name" : "gmem2", "Type" : "MAXI", "Direction" : "O",
				"SubConnect" : [
					{"ID" : "12", "SubInstance" : "Write_Loop_proc_U0", "Port" : "gmem2"}]},
			{"Name" : "C", "Type" : "None", "Direction" : "I"},
			{"Name" : "image_diff_posterize_rowA_0", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "10", "SubInstance" : "Col_Loop_proc_U0", "Port" : "image_diff_posterize_rowA_0"},
					{"ID" : "7", "SubInstance" : "Read_Loop_proc_U0", "Port" : "image_diff_posterize_rowA_0"}]},
			{"Name" : "image_diff_posterize_rowB_0", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "10", "SubInstance" : "Col_Loop_proc_U0", "Port" : "image_diff_posterize_rowB_0"},
					{"ID" : "7", "SubInstance" : "Read_Loop_proc_U0", "Port" : "image_diff_posterize_rowB_0"}]},
			{"Name" : "image_diff_posterize_rowA_1", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "10", "SubInstance" : "Col_Loop_proc_U0", "Port" : "image_diff_posterize_rowA_1"},
					{"ID" : "7", "SubInstance" : "Read_Loop_proc_U0", "Port" : "image_diff_posterize_rowA_1"}]},
			{"Name" : "image_diff_posterize_rowB_1", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "10", "SubInstance" : "Col_Loop_proc_U0", "Port" : "image_diff_posterize_rowB_1"},
					{"ID" : "7", "SubInstance" : "Read_Loop_proc_U0", "Port" : "image_diff_posterize_rowB_1"}]},
			{"Name" : "image_diff_posterize_rowA_2", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "10", "SubInstance" : "Col_Loop_proc_U0", "Port" : "image_diff_posterize_rowA_2"},
					{"ID" : "7", "SubInstance" : "Read_Loop_proc_U0", "Port" : "image_diff_posterize_rowA_2"}]},
			{"Name" : "image_diff_posterize_rowB_2", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "10", "SubInstance" : "Col_Loop_proc_U0", "Port" : "image_diff_posterize_rowB_2"},
					{"ID" : "7", "SubInstance" : "Read_Loop_proc_U0", "Port" : "image_diff_posterize_rowB_2"}]},
			{"Name" : "image_diff_posterize_rowA_3", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "10", "SubInstance" : "Col_Loop_proc_U0", "Port" : "image_diff_posterize_rowA_3"},
					{"ID" : "7", "SubInstance" : "Read_Loop_proc_U0", "Port" : "image_diff_posterize_rowA_3"}]},
			{"Name" : "image_diff_posterize_rowB_3", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "10", "SubInstance" : "Col_Loop_proc_U0", "Port" : "image_diff_posterize_rowB_3"},
					{"ID" : "7", "SubInstance" : "Read_Loop_proc_U0", "Port" : "image_diff_posterize_rowB_3"}]},
			{"Name" : "image_diff_posterize_rowA_4", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "10", "SubInstance" : "Col_Loop_proc_U0", "Port" : "image_diff_posterize_rowA_4"},
					{"ID" : "7", "SubInstance" : "Read_Loop_proc_U0", "Port" : "image_diff_posterize_rowA_4"}]},
			{"Name" : "image_diff_posterize_rowB_4", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "10", "SubInstance" : "Col_Loop_proc_U0", "Port" : "image_diff_posterize_rowB_4"},
					{"ID" : "7", "SubInstance" : "Read_Loop_proc_U0", "Port" : "image_diff_posterize_rowB_4"}]},
			{"Name" : "image_diff_posterize_rowA_5", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "10", "SubInstance" : "Col_Loop_proc_U0", "Port" : "image_diff_posterize_rowA_5"},
					{"ID" : "7", "SubInstance" : "Read_Loop_proc_U0", "Port" : "image_diff_posterize_rowA_5"}]},
			{"Name" : "image_diff_posterize_rowB_5", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "10", "SubInstance" : "Col_Loop_proc_U0", "Port" : "image_diff_posterize_rowB_5"},
					{"ID" : "7", "SubInstance" : "Read_Loop_proc_U0", "Port" : "image_diff_posterize_rowB_5"}]},
			{"Name" : "image_diff_posterize_rowA_6", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "10", "SubInstance" : "Col_Loop_proc_U0", "Port" : "image_diff_posterize_rowA_6"},
					{"ID" : "7", "SubInstance" : "Read_Loop_proc_U0", "Port" : "image_diff_posterize_rowA_6"}]},
			{"Name" : "image_diff_posterize_rowB_6", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "10", "SubInstance" : "Col_Loop_proc_U0", "Port" : "image_diff_posterize_rowB_6"},
					{"ID" : "7", "SubInstance" : "Read_Loop_proc_U0", "Port" : "image_diff_posterize_rowB_6"}]},
			{"Name" : "image_diff_posterize_rowA_7", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "10", "SubInstance" : "Col_Loop_proc_U0", "Port" : "image_diff_posterize_rowA_7"},
					{"ID" : "7", "SubInstance" : "Read_Loop_proc_U0", "Port" : "image_diff_posterize_rowA_7"}]},
			{"Name" : "image_diff_posterize_rowB_7", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "10", "SubInstance" : "Col_Loop_proc_U0", "Port" : "image_diff_posterize_rowB_7"},
					{"ID" : "7", "SubInstance" : "Read_Loop_proc_U0", "Port" : "image_diff_posterize_rowB_7"}]},
			{"Name" : "image_diff_posterize_rowC_0", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "10", "SubInstance" : "Col_Loop_proc_U0", "Port" : "image_diff_posterize_rowC_0"},
					{"ID" : "12", "SubInstance" : "Write_Loop_proc_U0", "Port" : "image_diff_posterize_rowC_0"}]},
			{"Name" : "image_diff_posterize_rowC_1", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "10", "SubInstance" : "Col_Loop_proc_U0", "Port" : "image_diff_posterize_rowC_1"},
					{"ID" : "12", "SubInstance" : "Write_Loop_proc_U0", "Port" : "image_diff_posterize_rowC_1"}]},
			{"Name" : "image_diff_posterize_rowC_2", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "10", "SubInstance" : "Col_Loop_proc_U0", "Port" : "image_diff_posterize_rowC_2"},
					{"ID" : "12", "SubInstance" : "Write_Loop_proc_U0", "Port" : "image_diff_posterize_rowC_2"}]},
			{"Name" : "image_diff_posterize_rowC_3", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "10", "SubInstance" : "Col_Loop_proc_U0", "Port" : "image_diff_posterize_rowC_3"},
					{"ID" : "12", "SubInstance" : "Write_Loop_proc_U0", "Port" : "image_diff_posterize_rowC_3"}]},
			{"Name" : "image_diff_posterize_rowC_4", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "10", "SubInstance" : "Col_Loop_proc_U0", "Port" : "image_diff_posterize_rowC_4"},
					{"ID" : "12", "SubInstance" : "Write_Loop_proc_U0", "Port" : "image_diff_posterize_rowC_4"}]},
			{"Name" : "image_diff_posterize_rowC_5", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "10", "SubInstance" : "Col_Loop_proc_U0", "Port" : "image_diff_posterize_rowC_5"},
					{"ID" : "12", "SubInstance" : "Write_Loop_proc_U0", "Port" : "image_diff_posterize_rowC_5"}]},
			{"Name" : "image_diff_posterize_rowC_6", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "10", "SubInstance" : "Col_Loop_proc_U0", "Port" : "image_diff_posterize_rowC_6"},
					{"ID" : "12", "SubInstance" : "Write_Loop_proc_U0", "Port" : "image_diff_posterize_rowC_6"}]},
			{"Name" : "image_diff_posterize_rowC_7", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "10", "SubInstance" : "Col_Loop_proc_U0", "Port" : "image_diff_posterize_rowC_7"},
					{"ID" : "12", "SubInstance" : "Write_Loop_proc_U0", "Port" : "image_diff_posterize_rowC_7"}]}]},
	{"ID" : "6", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.entry_proc_U0", "Parent" : "5",
		"CDFG" : "entry_proc",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "1", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "1",
		"VariableLatency" : "0", "ExactLatency" : "0", "EstimateLatencyMin" : "0", "EstimateLatencyMax" : "0",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "1",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "C", "Type" : "None", "Direction" : "I"},
			{"Name" : "C_c", "Type" : "Fifo", "Direction" : "O", "DependentProc" : ["12"], "DependentChan" : "40", "DependentChanDepth" : "4", "DependentChanType" : "2",
				"BlockSignal" : [
					{"Name" : "C_c_blk_n", "Type" : "RtlSignal"}]}]},
	{"ID" : "7", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.Read_Loop_proc_U0", "Parent" : "5", "Child" : ["8"],
		"CDFG" : "Read_Loop_proc",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "1", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "268", "EstimateLatencyMax" : "268",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "1",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "gmem0", "Type" : "MAXI", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "gmem0_blk_n_AR", "Type" : "RtlSignal"}],
				"SubConnect" : [
					{"ID" : "8", "SubInstance" : "grp_Read_Loop_proc_Pipeline_Read_Loop_fu_106", "Port" : "gmem0", "Inst_start_state" : "9", "Inst_end_state" : "10"}]},
			{"Name" : "i", "Type" : "None", "Direction" : "I"},
			{"Name" : "A", "Type" : "None", "Direction" : "I"},
			{"Name" : "gmem1", "Type" : "MAXI", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "gmem1_blk_n_AR", "Type" : "RtlSignal"}],
				"SubConnect" : [
					{"ID" : "8", "SubInstance" : "grp_Read_Loop_proc_Pipeline_Read_Loop_fu_106", "Port" : "gmem1", "Inst_start_state" : "9", "Inst_end_state" : "10"}]},
			{"Name" : "B", "Type" : "None", "Direction" : "I"},
			{"Name" : "image_diff_posterize_rowA_0", "Type" : "Memory", "Direction" : "O", "DependentProc" : ["10"], "DependentChan" : "16",
				"SubConnect" : [
					{"ID" : "8", "SubInstance" : "grp_Read_Loop_proc_Pipeline_Read_Loop_fu_106", "Port" : "image_diff_posterize_rowA_0", "Inst_start_state" : "9", "Inst_end_state" : "10"}]},
			{"Name" : "image_diff_posterize_rowB_0", "Type" : "Memory", "Direction" : "O", "DependentProc" : ["10"], "DependentChan" : "17",
				"SubConnect" : [
					{"ID" : "8", "SubInstance" : "grp_Read_Loop_proc_Pipeline_Read_Loop_fu_106", "Port" : "image_diff_posterize_rowB_0", "Inst_start_state" : "9", "Inst_end_state" : "10"}]},
			{"Name" : "image_diff_posterize_rowA_1", "Type" : "Memory", "Direction" : "O", "DependentProc" : ["10"], "DependentChan" : "18",
				"SubConnect" : [
					{"ID" : "8", "SubInstance" : "grp_Read_Loop_proc_Pipeline_Read_Loop_fu_106", "Port" : "image_diff_posterize_rowA_1", "Inst_start_state" : "9", "Inst_end_state" : "10"}]},
			{"Name" : "image_diff_posterize_rowB_1", "Type" : "Memory", "Direction" : "O", "DependentProc" : ["10"], "DependentChan" : "19",
				"SubConnect" : [
					{"ID" : "8", "SubInstance" : "grp_Read_Loop_proc_Pipeline_Read_Loop_fu_106", "Port" : "image_diff_posterize_rowB_1", "Inst_start_state" : "9", "Inst_end_state" : "10"}]},
			{"Name" : "image_diff_posterize_rowA_2", "Type" : "Memory", "Direction" : "O", "DependentProc" : ["10"], "DependentChan" : "20",
				"SubConnect" : [
					{"ID" : "8", "SubInstance" : "grp_Read_Loop_proc_Pipeline_Read_Loop_fu_106", "Port" : "image_diff_posterize_rowA_2", "Inst_start_state" : "9", "Inst_end_state" : "10"}]},
			{"Name" : "image_diff_posterize_rowB_2", "Type" : "Memory", "Direction" : "O", "DependentProc" : ["10"], "DependentChan" : "21",
				"SubConnect" : [
					{"ID" : "8", "SubInstance" : "grp_Read_Loop_proc_Pipeline_Read_Loop_fu_106", "Port" : "image_diff_posterize_rowB_2", "Inst_start_state" : "9", "Inst_end_state" : "10"}]},
			{"Name" : "image_diff_posterize_rowA_3", "Type" : "Memory", "Direction" : "O", "DependentProc" : ["10"], "DependentChan" : "22",
				"SubConnect" : [
					{"ID" : "8", "SubInstance" : "grp_Read_Loop_proc_Pipeline_Read_Loop_fu_106", "Port" : "image_diff_posterize_rowA_3", "Inst_start_state" : "9", "Inst_end_state" : "10"}]},
			{"Name" : "image_diff_posterize_rowB_3", "Type" : "Memory", "Direction" : "O", "DependentProc" : ["10"], "DependentChan" : "23",
				"SubConnect" : [
					{"ID" : "8", "SubInstance" : "grp_Read_Loop_proc_Pipeline_Read_Loop_fu_106", "Port" : "image_diff_posterize_rowB_3", "Inst_start_state" : "9", "Inst_end_state" : "10"}]},
			{"Name" : "image_diff_posterize_rowA_4", "Type" : "Memory", "Direction" : "O", "DependentProc" : ["10"], "DependentChan" : "24",
				"SubConnect" : [
					{"ID" : "8", "SubInstance" : "grp_Read_Loop_proc_Pipeline_Read_Loop_fu_106", "Port" : "image_diff_posterize_rowA_4", "Inst_start_state" : "9", "Inst_end_state" : "10"}]},
			{"Name" : "image_diff_posterize_rowB_4", "Type" : "Memory", "Direction" : "O", "DependentProc" : ["10"], "DependentChan" : "25",
				"SubConnect" : [
					{"ID" : "8", "SubInstance" : "grp_Read_Loop_proc_Pipeline_Read_Loop_fu_106", "Port" : "image_diff_posterize_rowB_4", "Inst_start_state" : "9", "Inst_end_state" : "10"}]},
			{"Name" : "image_diff_posterize_rowA_5", "Type" : "Memory", "Direction" : "O", "DependentProc" : ["10"], "DependentChan" : "26",
				"SubConnect" : [
					{"ID" : "8", "SubInstance" : "grp_Read_Loop_proc_Pipeline_Read_Loop_fu_106", "Port" : "image_diff_posterize_rowA_5", "Inst_start_state" : "9", "Inst_end_state" : "10"}]},
			{"Name" : "image_diff_posterize_rowB_5", "Type" : "Memory", "Direction" : "O", "DependentProc" : ["10"], "DependentChan" : "27",
				"SubConnect" : [
					{"ID" : "8", "SubInstance" : "grp_Read_Loop_proc_Pipeline_Read_Loop_fu_106", "Port" : "image_diff_posterize_rowB_5", "Inst_start_state" : "9", "Inst_end_state" : "10"}]},
			{"Name" : "image_diff_posterize_rowA_6", "Type" : "Memory", "Direction" : "O", "DependentProc" : ["10"], "DependentChan" : "28",
				"SubConnect" : [
					{"ID" : "8", "SubInstance" : "grp_Read_Loop_proc_Pipeline_Read_Loop_fu_106", "Port" : "image_diff_posterize_rowA_6", "Inst_start_state" : "9", "Inst_end_state" : "10"}]},
			{"Name" : "image_diff_posterize_rowB_6", "Type" : "Memory", "Direction" : "O", "DependentProc" : ["10"], "DependentChan" : "29",
				"SubConnect" : [
					{"ID" : "8", "SubInstance" : "grp_Read_Loop_proc_Pipeline_Read_Loop_fu_106", "Port" : "image_diff_posterize_rowB_6", "Inst_start_state" : "9", "Inst_end_state" : "10"}]},
			{"Name" : "image_diff_posterize_rowA_7", "Type" : "Memory", "Direction" : "O", "DependentProc" : ["10"], "DependentChan" : "30",
				"SubConnect" : [
					{"ID" : "8", "SubInstance" : "grp_Read_Loop_proc_Pipeline_Read_Loop_fu_106", "Port" : "image_diff_posterize_rowA_7", "Inst_start_state" : "9", "Inst_end_state" : "10"}]},
			{"Name" : "image_diff_posterize_rowB_7", "Type" : "Memory", "Direction" : "O", "DependentProc" : ["10"], "DependentChan" : "31",
				"SubConnect" : [
					{"ID" : "8", "SubInstance" : "grp_Read_Loop_proc_Pipeline_Read_Loop_fu_106", "Port" : "image_diff_posterize_rowB_7", "Inst_start_state" : "9", "Inst_end_state" : "10"}]}]},
	{"ID" : "8", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.Read_Loop_proc_U0.grp_Read_Loop_proc_Pipeline_Read_Loop_fu_106", "Parent" : "7", "Child" : ["9"],
		"CDFG" : "Read_Loop_proc_Pipeline_Read_Loop",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "259", "EstimateLatencyMax" : "259",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "gmem1", "Type" : "MAXI", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "gmem1_blk_n_R", "Type" : "RtlSignal"}]},
			{"Name" : "add_ln41_1_i", "Type" : "None", "Direction" : "I"},
			{"Name" : "gmem0", "Type" : "MAXI", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "gmem0_blk_n_R", "Type" : "RtlSignal"}]},
			{"Name" : "add_ln41_i", "Type" : "None", "Direction" : "I"},
			{"Name" : "image_diff_posterize_rowA_0", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "image_diff_posterize_rowB_0", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "image_diff_posterize_rowA_1", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "image_diff_posterize_rowB_1", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "image_diff_posterize_rowA_2", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "image_diff_posterize_rowB_2", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "image_diff_posterize_rowA_3", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "image_diff_posterize_rowB_3", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "image_diff_posterize_rowA_4", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "image_diff_posterize_rowB_4", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "image_diff_posterize_rowA_5", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "image_diff_posterize_rowB_5", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "image_diff_posterize_rowA_6", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "image_diff_posterize_rowB_6", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "image_diff_posterize_rowA_7", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "image_diff_posterize_rowB_7", "Type" : "Memory", "Direction" : "O"}],
		"Loop" : [
			{"Name" : "Read_Loop", "PipelineType" : "UPC",
				"LoopDec" : {"FSMBitwidth" : "1", "FirstState" : "ap_ST_fsm_pp0_stage0", "FirstStateIter" : "ap_enable_reg_pp0_iter0", "FirstStateBlock" : "ap_block_pp0_stage0_subdone", "LastState" : "ap_ST_fsm_pp0_stage0", "LastStateIter" : "ap_enable_reg_pp0_iter2", "LastStateBlock" : "ap_block_pp0_stage0_subdone", "QuitState" : "ap_ST_fsm_pp0_stage0", "QuitStateIter" : "ap_enable_reg_pp0_iter2", "QuitStateBlock" : "ap_block_pp0_stage0_subdone", "OneDepthLoop" : "0", "has_ap_ctrl" : "1", "has_continue" : "0"}}]},
	{"ID" : "9", "Level" : "4", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.Read_Loop_proc_U0.grp_Read_Loop_proc_Pipeline_Read_Loop_fu_106.flow_control_loop_pipe_sequential_init_U", "Parent" : "8"},
	{"ID" : "10", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.Col_Loop_proc_U0", "Parent" : "5", "Child" : ["11"],
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
			{"Name" : "image_diff_posterize_rowA_0", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["7"], "DependentChan" : "16"},
			{"Name" : "image_diff_posterize_rowA_1", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["7"], "DependentChan" : "18"},
			{"Name" : "image_diff_posterize_rowA_2", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["7"], "DependentChan" : "20"},
			{"Name" : "image_diff_posterize_rowA_3", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["7"], "DependentChan" : "22"},
			{"Name" : "image_diff_posterize_rowA_4", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["7"], "DependentChan" : "24"},
			{"Name" : "image_diff_posterize_rowA_5", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["7"], "DependentChan" : "26"},
			{"Name" : "image_diff_posterize_rowA_6", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["7"], "DependentChan" : "28"},
			{"Name" : "image_diff_posterize_rowA_7", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["7"], "DependentChan" : "30"},
			{"Name" : "image_diff_posterize_rowB_0", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["7"], "DependentChan" : "17"},
			{"Name" : "image_diff_posterize_rowB_1", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["7"], "DependentChan" : "19"},
			{"Name" : "image_diff_posterize_rowB_2", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["7"], "DependentChan" : "21"},
			{"Name" : "image_diff_posterize_rowB_3", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["7"], "DependentChan" : "23"},
			{"Name" : "image_diff_posterize_rowB_4", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["7"], "DependentChan" : "25"},
			{"Name" : "image_diff_posterize_rowB_5", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["7"], "DependentChan" : "27"},
			{"Name" : "image_diff_posterize_rowB_6", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["7"], "DependentChan" : "29"},
			{"Name" : "image_diff_posterize_rowB_7", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["7"], "DependentChan" : "31"},
			{"Name" : "image_diff_posterize_rowC_0", "Type" : "Memory", "Direction" : "O", "DependentProc" : ["12"], "DependentChan" : "32"},
			{"Name" : "image_diff_posterize_rowC_1", "Type" : "Memory", "Direction" : "O", "DependentProc" : ["12"], "DependentChan" : "33"},
			{"Name" : "image_diff_posterize_rowC_2", "Type" : "Memory", "Direction" : "O", "DependentProc" : ["12"], "DependentChan" : "34"},
			{"Name" : "image_diff_posterize_rowC_3", "Type" : "Memory", "Direction" : "O", "DependentProc" : ["12"], "DependentChan" : "35"},
			{"Name" : "image_diff_posterize_rowC_4", "Type" : "Memory", "Direction" : "O", "DependentProc" : ["12"], "DependentChan" : "36"},
			{"Name" : "image_diff_posterize_rowC_5", "Type" : "Memory", "Direction" : "O", "DependentProc" : ["12"], "DependentChan" : "37"},
			{"Name" : "image_diff_posterize_rowC_6", "Type" : "Memory", "Direction" : "O", "DependentProc" : ["12"], "DependentChan" : "38"},
			{"Name" : "image_diff_posterize_rowC_7", "Type" : "Memory", "Direction" : "O", "DependentProc" : ["12"], "DependentChan" : "39"}],
		"Loop" : [
			{"Name" : "Col_Loop", "PipelineType" : "UPC",
				"LoopDec" : {"FSMBitwidth" : "1", "FirstState" : "ap_ST_fsm_pp0_stage0", "FirstStateIter" : "ap_enable_reg_pp0_iter0", "FirstStateBlock" : "ap_block_pp0_stage0_subdone", "LastState" : "ap_ST_fsm_pp0_stage0", "LastStateIter" : "ap_enable_reg_pp0_iter1", "LastStateBlock" : "ap_block_pp0_stage0_subdone", "QuitState" : "ap_ST_fsm_pp0_stage0", "QuitStateIter" : "ap_enable_reg_pp0_iter0", "QuitStateBlock" : "ap_block_pp0_stage0_subdone", "OneDepthLoop" : "0", "has_ap_ctrl" : "1", "has_continue" : "1"}}]},
	{"ID" : "11", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.Col_Loop_proc_U0.flow_control_loop_pipe_U", "Parent" : "10"},
	{"ID" : "12", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.Write_Loop_proc_U0", "Parent" : "5", "Child" : ["13"],
		"CDFG" : "Write_Loop_proc",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "1", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "267", "EstimateLatencyMax" : "267",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "1",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "gmem2", "Type" : "MAXI", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "gmem2_blk_n_AW", "Type" : "RtlSignal"},
					{"Name" : "gmem2_blk_n_B", "Type" : "RtlSignal"}],
				"SubConnect" : [
					{"ID" : "13", "SubInstance" : "grp_Write_Loop_proc_Pipeline_Write_Loop_fu_82", "Port" : "gmem2", "Inst_start_state" : "3", "Inst_end_state" : "4"}]},
			{"Name" : "p_read", "Type" : "None", "Direction" : "I", "DependentProc" : ["7"], "DependentChan" : "41", "DependentChanDepth" : "3", "DependentChanType" : "1"},
			{"Name" : "C", "Type" : "Fifo", "Direction" : "I", "DependentProc" : ["6"], "DependentChan" : "40", "DependentChanDepth" : "4", "DependentChanType" : "2",
				"BlockSignal" : [
					{"Name" : "C_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "image_diff_posterize_rowC_0", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["10"], "DependentChan" : "32",
				"SubConnect" : [
					{"ID" : "13", "SubInstance" : "grp_Write_Loop_proc_Pipeline_Write_Loop_fu_82", "Port" : "image_diff_posterize_rowC_0", "Inst_start_state" : "3", "Inst_end_state" : "4"}]},
			{"Name" : "image_diff_posterize_rowC_1", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["10"], "DependentChan" : "33",
				"SubConnect" : [
					{"ID" : "13", "SubInstance" : "grp_Write_Loop_proc_Pipeline_Write_Loop_fu_82", "Port" : "image_diff_posterize_rowC_1", "Inst_start_state" : "3", "Inst_end_state" : "4"}]},
			{"Name" : "image_diff_posterize_rowC_2", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["10"], "DependentChan" : "34",
				"SubConnect" : [
					{"ID" : "13", "SubInstance" : "grp_Write_Loop_proc_Pipeline_Write_Loop_fu_82", "Port" : "image_diff_posterize_rowC_2", "Inst_start_state" : "3", "Inst_end_state" : "4"}]},
			{"Name" : "image_diff_posterize_rowC_3", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["10"], "DependentChan" : "35",
				"SubConnect" : [
					{"ID" : "13", "SubInstance" : "grp_Write_Loop_proc_Pipeline_Write_Loop_fu_82", "Port" : "image_diff_posterize_rowC_3", "Inst_start_state" : "3", "Inst_end_state" : "4"}]},
			{"Name" : "image_diff_posterize_rowC_4", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["10"], "DependentChan" : "36",
				"SubConnect" : [
					{"ID" : "13", "SubInstance" : "grp_Write_Loop_proc_Pipeline_Write_Loop_fu_82", "Port" : "image_diff_posterize_rowC_4", "Inst_start_state" : "3", "Inst_end_state" : "4"}]},
			{"Name" : "image_diff_posterize_rowC_5", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["10"], "DependentChan" : "37",
				"SubConnect" : [
					{"ID" : "13", "SubInstance" : "grp_Write_Loop_proc_Pipeline_Write_Loop_fu_82", "Port" : "image_diff_posterize_rowC_5", "Inst_start_state" : "3", "Inst_end_state" : "4"}]},
			{"Name" : "image_diff_posterize_rowC_6", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["10"], "DependentChan" : "38",
				"SubConnect" : [
					{"ID" : "13", "SubInstance" : "grp_Write_Loop_proc_Pipeline_Write_Loop_fu_82", "Port" : "image_diff_posterize_rowC_6", "Inst_start_state" : "3", "Inst_end_state" : "4"}]},
			{"Name" : "image_diff_posterize_rowC_7", "Type" : "Memory", "Direction" : "I", "DependentProc" : ["10"], "DependentChan" : "39",
				"SubConnect" : [
					{"ID" : "13", "SubInstance" : "grp_Write_Loop_proc_Pipeline_Write_Loop_fu_82", "Port" : "image_diff_posterize_rowC_7", "Inst_start_state" : "3", "Inst_end_state" : "4"}]}]},
	{"ID" : "13", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.Write_Loop_proc_U0.grp_Write_Loop_proc_Pipeline_Write_Loop_fu_82", "Parent" : "12", "Child" : ["14", "15"],
		"CDFG" : "Write_Loop_proc_Pipeline_Write_Loop",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "259", "EstimateLatencyMax" : "259",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "gmem2", "Type" : "MAXI", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "gmem2_blk_n_W", "Type" : "RtlSignal"}]},
			{"Name" : "add_ln41", "Type" : "None", "Direction" : "I"},
			{"Name" : "image_diff_posterize_rowC_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "image_diff_posterize_rowC_1", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "image_diff_posterize_rowC_2", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "image_diff_posterize_rowC_3", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "image_diff_posterize_rowC_4", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "image_diff_posterize_rowC_5", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "image_diff_posterize_rowC_6", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "image_diff_posterize_rowC_7", "Type" : "Memory", "Direction" : "I"}],
		"Loop" : [
			{"Name" : "Write_Loop", "PipelineType" : "UPC",
				"LoopDec" : {"FSMBitwidth" : "1", "FirstState" : "ap_ST_fsm_pp0_stage0", "FirstStateIter" : "ap_enable_reg_pp0_iter0", "FirstStateBlock" : "ap_block_pp0_stage0_subdone", "LastState" : "ap_ST_fsm_pp0_stage0", "LastStateIter" : "ap_enable_reg_pp0_iter2", "LastStateBlock" : "ap_block_pp0_stage0_subdone", "QuitState" : "ap_ST_fsm_pp0_stage0", "QuitStateIter" : "ap_enable_reg_pp0_iter2", "QuitStateBlock" : "ap_block_pp0_stage0_subdone", "OneDepthLoop" : "0", "has_ap_ctrl" : "1", "has_continue" : "0"}}]},
	{"ID" : "14", "Level" : "4", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.Write_Loop_proc_U0.grp_Write_Loop_proc_Pipeline_Write_Loop_fu_82.mux_83_8_1_1_U68", "Parent" : "13"},
	{"ID" : "15", "Level" : "4", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.Write_Loop_proc_U0.grp_Write_Loop_proc_Pipeline_Write_Loop_fu_82.flow_control_loop_pipe_sequential_init_U", "Parent" : "13"},
	{"ID" : "16", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.image_diff_posterize_rowA_0_U", "Parent" : "5"},
	{"ID" : "17", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.image_diff_posterize_rowB_0_U", "Parent" : "5"},
	{"ID" : "18", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.image_diff_posterize_rowA_1_U", "Parent" : "5"},
	{"ID" : "19", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.image_diff_posterize_rowB_1_U", "Parent" : "5"},
	{"ID" : "20", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.image_diff_posterize_rowA_2_U", "Parent" : "5"},
	{"ID" : "21", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.image_diff_posterize_rowB_2_U", "Parent" : "5"},
	{"ID" : "22", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.image_diff_posterize_rowA_3_U", "Parent" : "5"},
	{"ID" : "23", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.image_diff_posterize_rowB_3_U", "Parent" : "5"},
	{"ID" : "24", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.image_diff_posterize_rowA_4_U", "Parent" : "5"},
	{"ID" : "25", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.image_diff_posterize_rowB_4_U", "Parent" : "5"},
	{"ID" : "26", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.image_diff_posterize_rowA_5_U", "Parent" : "5"},
	{"ID" : "27", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.image_diff_posterize_rowB_5_U", "Parent" : "5"},
	{"ID" : "28", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.image_diff_posterize_rowA_6_U", "Parent" : "5"},
	{"ID" : "29", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.image_diff_posterize_rowB_6_U", "Parent" : "5"},
	{"ID" : "30", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.image_diff_posterize_rowA_7_U", "Parent" : "5"},
	{"ID" : "31", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.image_diff_posterize_rowB_7_U", "Parent" : "5"},
	{"ID" : "32", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.image_diff_posterize_rowC_0_U", "Parent" : "5"},
	{"ID" : "33", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.image_diff_posterize_rowC_1_U", "Parent" : "5"},
	{"ID" : "34", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.image_diff_posterize_rowC_2_U", "Parent" : "5"},
	{"ID" : "35", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.image_diff_posterize_rowC_3_U", "Parent" : "5"},
	{"ID" : "36", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.image_diff_posterize_rowC_4_U", "Parent" : "5"},
	{"ID" : "37", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.image_diff_posterize_rowC_5_U", "Parent" : "5"},
	{"ID" : "38", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.image_diff_posterize_rowC_6_U", "Parent" : "5"},
	{"ID" : "39", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.image_diff_posterize_rowC_7_U", "Parent" : "5"},
	{"ID" : "40", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.C_c_U", "Parent" : "5"},
	{"ID" : "41", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.dataflow_in_loop_Row_Loop_U0.tmp_U", "Parent" : "5"}]}


set ArgLastReadFirstWriteLatency {
	image_diff_posterize {
		gmem0 {Type I LastRead 1 FirstWrite -1}
		gmem1 {Type I LastRead 1 FirstWrite -1}
		gmem2 {Type O LastRead 4 FirstWrite 2}
		A {Type I LastRead 0 FirstWrite -1}
		B {Type I LastRead 0 FirstWrite -1}
		C {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowA_0 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowB_0 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowA_1 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowB_1 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowA_2 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowB_2 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowA_3 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowB_3 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowA_4 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowB_4 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowA_5 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowB_5 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowA_6 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowB_6 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowA_7 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowB_7 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowC_0 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowC_1 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowC_2 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowC_3 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowC_4 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowC_5 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowC_6 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowC_7 {Type IO LastRead -1 FirstWrite -1}}
	dataflow_in_loop_Row_Loop {
		gmem0 {Type I LastRead 1 FirstWrite -1}
		i {Type I LastRead 0 FirstWrite -1}
		A {Type I LastRead 0 FirstWrite -1}
		gmem1 {Type I LastRead 1 FirstWrite -1}
		B {Type I LastRead 0 FirstWrite -1}
		gmem2 {Type O LastRead 4 FirstWrite 2}
		C {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowA_0 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowB_0 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowA_1 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowB_1 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowA_2 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowB_2 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowA_3 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowB_3 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowA_4 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowB_4 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowA_5 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowB_5 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowA_6 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowB_6 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowA_7 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowB_7 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowC_0 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowC_1 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowC_2 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowC_3 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowC_4 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowC_5 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowC_6 {Type IO LastRead -1 FirstWrite -1}
		image_diff_posterize_rowC_7 {Type IO LastRead -1 FirstWrite -1}}
	entry_proc {
		C {Type I LastRead 0 FirstWrite -1}
		C_c {Type O LastRead -1 FirstWrite 0}}
	Read_Loop_proc {
		gmem0 {Type I LastRead 1 FirstWrite -1}
		i {Type I LastRead 0 FirstWrite -1}
		A {Type I LastRead 0 FirstWrite -1}
		gmem1 {Type I LastRead 1 FirstWrite -1}
		B {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowA_0 {Type O LastRead -1 FirstWrite 2}
		image_diff_posterize_rowB_0 {Type O LastRead -1 FirstWrite 2}
		image_diff_posterize_rowA_1 {Type O LastRead -1 FirstWrite 2}
		image_diff_posterize_rowB_1 {Type O LastRead -1 FirstWrite 2}
		image_diff_posterize_rowA_2 {Type O LastRead -1 FirstWrite 2}
		image_diff_posterize_rowB_2 {Type O LastRead -1 FirstWrite 2}
		image_diff_posterize_rowA_3 {Type O LastRead -1 FirstWrite 2}
		image_diff_posterize_rowB_3 {Type O LastRead -1 FirstWrite 2}
		image_diff_posterize_rowA_4 {Type O LastRead -1 FirstWrite 2}
		image_diff_posterize_rowB_4 {Type O LastRead -1 FirstWrite 2}
		image_diff_posterize_rowA_5 {Type O LastRead -1 FirstWrite 2}
		image_diff_posterize_rowB_5 {Type O LastRead -1 FirstWrite 2}
		image_diff_posterize_rowA_6 {Type O LastRead -1 FirstWrite 2}
		image_diff_posterize_rowB_6 {Type O LastRead -1 FirstWrite 2}
		image_diff_posterize_rowA_7 {Type O LastRead -1 FirstWrite 2}
		image_diff_posterize_rowB_7 {Type O LastRead -1 FirstWrite 2}}
	Read_Loop_proc_Pipeline_Read_Loop {
		gmem1 {Type I LastRead 1 FirstWrite -1}
		add_ln41_1_i {Type I LastRead 0 FirstWrite -1}
		gmem0 {Type I LastRead 1 FirstWrite -1}
		add_ln41_i {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowA_0 {Type O LastRead -1 FirstWrite 2}
		image_diff_posterize_rowB_0 {Type O LastRead -1 FirstWrite 2}
		image_diff_posterize_rowA_1 {Type O LastRead -1 FirstWrite 2}
		image_diff_posterize_rowB_1 {Type O LastRead -1 FirstWrite 2}
		image_diff_posterize_rowA_2 {Type O LastRead -1 FirstWrite 2}
		image_diff_posterize_rowB_2 {Type O LastRead -1 FirstWrite 2}
		image_diff_posterize_rowA_3 {Type O LastRead -1 FirstWrite 2}
		image_diff_posterize_rowB_3 {Type O LastRead -1 FirstWrite 2}
		image_diff_posterize_rowA_4 {Type O LastRead -1 FirstWrite 2}
		image_diff_posterize_rowB_4 {Type O LastRead -1 FirstWrite 2}
		image_diff_posterize_rowA_5 {Type O LastRead -1 FirstWrite 2}
		image_diff_posterize_rowB_5 {Type O LastRead -1 FirstWrite 2}
		image_diff_posterize_rowA_6 {Type O LastRead -1 FirstWrite 2}
		image_diff_posterize_rowB_6 {Type O LastRead -1 FirstWrite 2}
		image_diff_posterize_rowA_7 {Type O LastRead -1 FirstWrite 2}
		image_diff_posterize_rowB_7 {Type O LastRead -1 FirstWrite 2}}
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
		image_diff_posterize_rowC_7 {Type O LastRead -1 FirstWrite 1}}
	Write_Loop_proc {
		gmem2 {Type O LastRead 4 FirstWrite 2}
		p_read {Type I LastRead 0 FirstWrite -1}
		C {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowC_0 {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowC_1 {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowC_2 {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowC_3 {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowC_4 {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowC_5 {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowC_6 {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowC_7 {Type I LastRead 0 FirstWrite -1}}
	Write_Loop_proc_Pipeline_Write_Loop {
		gmem2 {Type O LastRead -1 FirstWrite 2}
		add_ln41 {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowC_0 {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowC_1 {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowC_2 {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowC_3 {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowC_4 {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowC_5 {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowC_6 {Type I LastRead 0 FirstWrite -1}
		image_diff_posterize_rowC_7 {Type I LastRead 0 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "69168", "Max" : "69168"}
	, {"Name" : "Interval", "Min" : "69169", "Max" : "69169"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	gmem0 { m_axi {  { m_axi_gmem0_AWVALID VALID 1 1 }  { m_axi_gmem0_AWREADY READY 0 1 }  { m_axi_gmem0_AWADDR ADDR 1 64 }  { m_axi_gmem0_AWID ID 1 1 }  { m_axi_gmem0_AWLEN SIZE 1 8 }  { m_axi_gmem0_AWSIZE BURST 1 3 }  { m_axi_gmem0_AWBURST LOCK 1 2 }  { m_axi_gmem0_AWLOCK CACHE 1 2 }  { m_axi_gmem0_AWCACHE PROT 1 4 }  { m_axi_gmem0_AWPROT QOS 1 3 }  { m_axi_gmem0_AWQOS REGION 1 4 }  { m_axi_gmem0_AWREGION USER 1 4 }  { m_axi_gmem0_AWUSER DATA 1 1 }  { m_axi_gmem0_WVALID VALID 1 1 }  { m_axi_gmem0_WREADY READY 0 1 }  { m_axi_gmem0_WDATA FIFONUM 1 32 }  { m_axi_gmem0_WSTRB STRB 1 4 }  { m_axi_gmem0_WLAST LAST 1 1 }  { m_axi_gmem0_WID ID 1 1 }  { m_axi_gmem0_WUSER DATA 1 1 }  { m_axi_gmem0_ARVALID VALID 1 1 }  { m_axi_gmem0_ARREADY READY 0 1 }  { m_axi_gmem0_ARADDR ADDR 1 64 }  { m_axi_gmem0_ARID ID 1 1 }  { m_axi_gmem0_ARLEN SIZE 1 8 }  { m_axi_gmem0_ARSIZE BURST 1 3 }  { m_axi_gmem0_ARBURST LOCK 1 2 }  { m_axi_gmem0_ARLOCK CACHE 1 2 }  { m_axi_gmem0_ARCACHE PROT 1 4 }  { m_axi_gmem0_ARPROT QOS 1 3 }  { m_axi_gmem0_ARQOS REGION 1 4 }  { m_axi_gmem0_ARREGION USER 1 4 }  { m_axi_gmem0_ARUSER DATA 1 1 }  { m_axi_gmem0_RVALID VALID 0 1 }  { m_axi_gmem0_RREADY READY 1 1 }  { m_axi_gmem0_RDATA FIFONUM 0 32 }  { m_axi_gmem0_RLAST LAST 0 1 }  { m_axi_gmem0_RID ID 0 1 }  { m_axi_gmem0_RUSER DATA 0 1 }  { m_axi_gmem0_RRESP RESP 0 2 }  { m_axi_gmem0_BVALID VALID 0 1 }  { m_axi_gmem0_BREADY READY 1 1 }  { m_axi_gmem0_BRESP RESP 0 2 }  { m_axi_gmem0_BID ID 0 1 }  { m_axi_gmem0_BUSER DATA 0 1 } } }
	gmem1 { m_axi {  { m_axi_gmem1_AWVALID VALID 1 1 }  { m_axi_gmem1_AWREADY READY 0 1 }  { m_axi_gmem1_AWADDR ADDR 1 64 }  { m_axi_gmem1_AWID ID 1 1 }  { m_axi_gmem1_AWLEN SIZE 1 8 }  { m_axi_gmem1_AWSIZE BURST 1 3 }  { m_axi_gmem1_AWBURST LOCK 1 2 }  { m_axi_gmem1_AWLOCK CACHE 1 2 }  { m_axi_gmem1_AWCACHE PROT 1 4 }  { m_axi_gmem1_AWPROT QOS 1 3 }  { m_axi_gmem1_AWQOS REGION 1 4 }  { m_axi_gmem1_AWREGION USER 1 4 }  { m_axi_gmem1_AWUSER DATA 1 1 }  { m_axi_gmem1_WVALID VALID 1 1 }  { m_axi_gmem1_WREADY READY 0 1 }  { m_axi_gmem1_WDATA FIFONUM 1 32 }  { m_axi_gmem1_WSTRB STRB 1 4 }  { m_axi_gmem1_WLAST LAST 1 1 }  { m_axi_gmem1_WID ID 1 1 }  { m_axi_gmem1_WUSER DATA 1 1 }  { m_axi_gmem1_ARVALID VALID 1 1 }  { m_axi_gmem1_ARREADY READY 0 1 }  { m_axi_gmem1_ARADDR ADDR 1 64 }  { m_axi_gmem1_ARID ID 1 1 }  { m_axi_gmem1_ARLEN SIZE 1 8 }  { m_axi_gmem1_ARSIZE BURST 1 3 }  { m_axi_gmem1_ARBURST LOCK 1 2 }  { m_axi_gmem1_ARLOCK CACHE 1 2 }  { m_axi_gmem1_ARCACHE PROT 1 4 }  { m_axi_gmem1_ARPROT QOS 1 3 }  { m_axi_gmem1_ARQOS REGION 1 4 }  { m_axi_gmem1_ARREGION USER 1 4 }  { m_axi_gmem1_ARUSER DATA 1 1 }  { m_axi_gmem1_RVALID VALID 0 1 }  { m_axi_gmem1_RREADY READY 1 1 }  { m_axi_gmem1_RDATA FIFONUM 0 32 }  { m_axi_gmem1_RLAST LAST 0 1 }  { m_axi_gmem1_RID ID 0 1 }  { m_axi_gmem1_RUSER DATA 0 1 }  { m_axi_gmem1_RRESP RESP 0 2 }  { m_axi_gmem1_BVALID VALID 0 1 }  { m_axi_gmem1_BREADY READY 1 1 }  { m_axi_gmem1_BRESP RESP 0 2 }  { m_axi_gmem1_BID ID 0 1 }  { m_axi_gmem1_BUSER DATA 0 1 } } }
	gmem2 { m_axi {  { m_axi_gmem2_AWVALID VALID 1 1 }  { m_axi_gmem2_AWREADY READY 0 1 }  { m_axi_gmem2_AWADDR ADDR 1 64 }  { m_axi_gmem2_AWID ID 1 1 }  { m_axi_gmem2_AWLEN SIZE 1 8 }  { m_axi_gmem2_AWSIZE BURST 1 3 }  { m_axi_gmem2_AWBURST LOCK 1 2 }  { m_axi_gmem2_AWLOCK CACHE 1 2 }  { m_axi_gmem2_AWCACHE PROT 1 4 }  { m_axi_gmem2_AWPROT QOS 1 3 }  { m_axi_gmem2_AWQOS REGION 1 4 }  { m_axi_gmem2_AWREGION USER 1 4 }  { m_axi_gmem2_AWUSER DATA 1 1 }  { m_axi_gmem2_WVALID VALID 1 1 }  { m_axi_gmem2_WREADY READY 0 1 }  { m_axi_gmem2_WDATA FIFONUM 1 32 }  { m_axi_gmem2_WSTRB STRB 1 4 }  { m_axi_gmem2_WLAST LAST 1 1 }  { m_axi_gmem2_WID ID 1 1 }  { m_axi_gmem2_WUSER DATA 1 1 }  { m_axi_gmem2_ARVALID VALID 1 1 }  { m_axi_gmem2_ARREADY READY 0 1 }  { m_axi_gmem2_ARADDR ADDR 1 64 }  { m_axi_gmem2_ARID ID 1 1 }  { m_axi_gmem2_ARLEN SIZE 1 8 }  { m_axi_gmem2_ARSIZE BURST 1 3 }  { m_axi_gmem2_ARBURST LOCK 1 2 }  { m_axi_gmem2_ARLOCK CACHE 1 2 }  { m_axi_gmem2_ARCACHE PROT 1 4 }  { m_axi_gmem2_ARPROT QOS 1 3 }  { m_axi_gmem2_ARQOS REGION 1 4 }  { m_axi_gmem2_ARREGION USER 1 4 }  { m_axi_gmem2_ARUSER DATA 1 1 }  { m_axi_gmem2_RVALID VALID 0 1 }  { m_axi_gmem2_RREADY READY 1 1 }  { m_axi_gmem2_RDATA FIFONUM 0 32 }  { m_axi_gmem2_RLAST LAST 0 1 }  { m_axi_gmem2_RID ID 0 1 }  { m_axi_gmem2_RUSER DATA 0 1 }  { m_axi_gmem2_RRESP RESP 0 2 }  { m_axi_gmem2_BVALID VALID 0 1 }  { m_axi_gmem2_BREADY READY 1 1 }  { m_axi_gmem2_BRESP RESP 0 2 }  { m_axi_gmem2_BID ID 0 1 }  { m_axi_gmem2_BUSER DATA 0 1 } } }
}

set maxi_interface_dict [dict create]
dict set maxi_interface_dict gmem0 {NUM_READ_OUTSTANDING 16 NUM_WRITE_OUTSTANDING 16 MAX_READ_BURST_LENGTH 16 MAX_WRITE_BURST_LENGTH 16 READ_WRITE_MODE READ_ONLY}
dict set maxi_interface_dict gmem1 {NUM_READ_OUTSTANDING 16 NUM_WRITE_OUTSTANDING 16 MAX_READ_BURST_LENGTH 16 MAX_WRITE_BURST_LENGTH 16 READ_WRITE_MODE READ_ONLY}
dict set maxi_interface_dict gmem2 {NUM_READ_OUTSTANDING 16 NUM_WRITE_OUTSTANDING 16 MAX_READ_BURST_LENGTH 16 MAX_WRITE_BURST_LENGTH 16 READ_WRITE_MODE WRITE_ONLY}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
	{ gmem0 1 }
	{ gmem1 1 }
	{ gmem2 1 }
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
	{ gmem0 1 }
	{ gmem1 1 }
	{ gmem2 1 }
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}

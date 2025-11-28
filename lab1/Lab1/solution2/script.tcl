############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
############################################################
open_project Lab1
set_top image_diff_posterize
add_files image_diff_posterize.c
add_files -tb Lab1/tb_image_diff_posterize.c -cflags "-Wno-unknown-pragmas -Wno-unknown-pragmas -Wno-unknown-pragmas -Wno-unknown-pragmas -Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution2" -flow_target vivado
set_part {xcu200-fsgd2104-2-e}
create_clock -period 10 -name default
#source "./Lab1/solution2/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog

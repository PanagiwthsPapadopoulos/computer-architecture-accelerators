set SynModuleInfo {
  {SRCNAME entry_proc MODELNAME entry_proc RTLNAME image_diff_posterize_entry_proc}
  {SRCNAME Read_Loop_proc_Pipeline_Read_Loop MODELNAME Read_Loop_proc_Pipeline_Read_Loop RTLNAME image_diff_posterize_Read_Loop_proc_Pipeline_Read_Loop
    SUBMODULES {
      {MODELNAME image_diff_posterize_flow_control_loop_pipe_sequential_init RTLNAME image_diff_posterize_flow_control_loop_pipe_sequential_init BINDTYPE interface TYPE internal_upc_flow_control INSTNAME image_diff_posterize_flow_control_loop_pipe_sequential_init_U}
    }
  }
  {SRCNAME Read_Loop_proc MODELNAME Read_Loop_proc RTLNAME image_diff_posterize_Read_Loop_proc}
  {SRCNAME Col_Loop_proc MODELNAME Col_Loop_proc RTLNAME image_diff_posterize_Col_Loop_proc
    SUBMODULES {
      {MODELNAME image_diff_posterize_flow_control_loop_pipe RTLNAME image_diff_posterize_flow_control_loop_pipe BINDTYPE interface TYPE internal_upc_flow_control INSTNAME image_diff_posterize_flow_control_loop_pipe_U}
    }
  }
  {SRCNAME Write_Loop_proc_Pipeline_Write_Loop MODELNAME Write_Loop_proc_Pipeline_Write_Loop RTLNAME image_diff_posterize_Write_Loop_proc_Pipeline_Write_Loop
    SUBMODULES {
      {MODELNAME image_diff_posterize_mux_83_8_1_1 RTLNAME image_diff_posterize_mux_83_8_1_1 BINDTYPE op TYPE mux IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
    }
  }
  {SRCNAME Write_Loop_proc MODELNAME Write_Loop_proc RTLNAME image_diff_posterize_Write_Loop_proc}
  {SRCNAME dataflow_in_loop_Row_Loop MODELNAME dataflow_in_loop_Row_Loop RTLNAME image_diff_posterize_dataflow_in_loop_Row_Loop
    SUBMODULES {
      {MODELNAME image_diff_posterize_dataflow_in_loop_Row_Loop_image_diff_posterize_rowA_0_RAM_AUTO_1R1W_memcore RTLNAME image_diff_posterize_dataflow_in_loop_Row_Loop_image_diff_posterize_rowA_0_RAM_AUTO_1R1W_memcore BINDTYPE storage TYPE ram IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME image_diff_posterize_dataflow_in_loop_Row_Loop_image_diff_posterize_rowA_0_RAM_AUTO_1R1W RTLNAME image_diff_posterize_dataflow_in_loop_Row_Loop_image_diff_posterize_rowA_0_RAM_AUTO_1R1W BINDTYPE storage TYPE ram IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME image_diff_posterize_fifo_w64_d4_S RTLNAME image_diff_posterize_fifo_w64_d4_S BINDTYPE storage TYPE fifo IMPL srl ALLOW_PRAGMA 1 INSTNAME C_c_U}
      {MODELNAME image_diff_posterize_fifo_w8_d3_S RTLNAME image_diff_posterize_fifo_w8_d3_S BINDTYPE storage TYPE fifo IMPL srl ALLOW_PRAGMA 1 INSTNAME tmp_U}
    }
  }
  {SRCNAME image_diff_posterize MODELNAME image_diff_posterize RTLNAME image_diff_posterize IS_TOP 1
    SUBMODULES {
      {MODELNAME image_diff_posterize_gmem0_m_axi RTLNAME image_diff_posterize_gmem0_m_axi BINDTYPE interface TYPE adapter IMPL m_axi}
      {MODELNAME image_diff_posterize_gmem1_m_axi RTLNAME image_diff_posterize_gmem1_m_axi BINDTYPE interface TYPE adapter IMPL m_axi}
      {MODELNAME image_diff_posterize_gmem2_m_axi RTLNAME image_diff_posterize_gmem2_m_axi BINDTYPE interface TYPE adapter IMPL m_axi}
      {MODELNAME image_diff_posterize_control_s_axi RTLNAME image_diff_posterize_control_s_axi BINDTYPE interface TYPE interface_s_axilite}
    }
  }
}

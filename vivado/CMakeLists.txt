project(vivado_study)

# download Cora z7 board
FetchContent_Declare(
  xilinxboardstore
  GIT_REPOSITORY https://github.com/Xilinx/XilinxBoardStore.git
  GIT_TAG d4e7c68d16042b32a88790162d9b2b5642ca476b
)
FetchContent_MakeAvailable(xilinxboardstore)
configure_file(set_board_path.config.tcl ${CMAKE_CURRENT_BINARY_DIR}/set_board_path.tcl)

add_vivado_project(vivado_study
  TOP        top
  BOARD      digilentinc.com:cora-z7-07s:part0:1.0
  TCL0       ${CMAKE_CURRENT_BINARY_DIR}/set_board_path.tcl
  DFX        dfx.tcl
  RTL        ${RTL_DIR} top.v
  CONSTRAINT ${CONSTRAINT_DIR} dfx.xdc
  IP         ${BUILD_HLS_DIR}
  DESIGN     design_1.tcl
  DEPENDS    csynth_hlsled
)

# program_vivado_study_pr0
add_write_bitstream(vivado_study pr0
  impl_1/myrtl_myrtl_partial.bit
)

# program_vivado_study_pr1
add_write_bitstream(vivado_study pr1
  child_0_impl_1/myrtl_myled2_partial.bit
)

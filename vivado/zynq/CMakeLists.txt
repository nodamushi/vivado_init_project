project(zynq)

add_vivado_project(zynq_study
  TOP        design_1_wrapper
  BOARD      digilentinc.com:cora-z7-07s:part0:1.0
  BOARD_REPO ${xilinxboardstore_SOURCE_DIR}
  DESIGN     design_1.tcl
)

add_vitis_hw_project(zynq_vitis
  XSA   zynq_study
  PROC  ps7_cortexa9_0
  SOURCES src
)


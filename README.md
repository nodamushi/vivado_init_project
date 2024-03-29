# vivado init project

Simple sample project for Cora Z7 07S.

## Environment

- Ubuntu18.04
- Vivado 2021.1

## License

- Unlicense

## Build

```sh
mkdir build
cd build
cmake ..
make impl_vivado_study
```

## Bitstreams

Output Directory:

- `build/vivado/vivado_study.prj/vivado_study.runs/impl_1`
- `build/vivado/vivado_study.prj/vivado_study.runs/child_0_impl_1`

## Program FPGA

You can write a bitstream by the following command.

write `build/vivado/vivado_study.prj/vivado_study.runs/impl_1/top.bit`

```sh
make JTAG=<Target Number> program_vivado_study
```

write `build/vivado/vivado_study.prj/vivado_study.runs/impl_1/myrtl_myrtl_partial.bit`

```sh
make JTAG=<Target Number> program_vivado_study_pr0
```

write `build/vivado/vivado_study.prj/vivado_study.runs/child_0_impl_1/myrtl_myled2_partial.bit`

```sh
make JTAG=<Target Number> program_vivado_study_pr1
```

### CMake Option

- `-DVIVADO_ROOT=<Vivado Directory>` : Vivado install directory(exp: C:/Xilinx/Vivado/2021.1)
- `-DVITIS_HLS_ROOT=<Vitis HLS Directory>` : Vitis HLS install directory(exp: C:/Xilinx/Vitis_HLS/2021.1)

## Make Target

- `xsdb`: run xsdb
- `vivado_study` : Create [vivado_study](./vivado) Vivado project
- `open_vivado_study` : Open vivado_study project
- `clear_vivado_study` : Delete [vivado_study](./vivado) Vivado project
- `impl_vivado_study` : Generate a bitstream
- `program_vivado_study` : Write a bitstream to FPGA (use xsdb)
- `export_bd_vivado_study`: Export design file ([vivado/design_1.tcl](./vivado/design_1.tcl))
- `report_addr_vivado_study`: Report address
- `create_project_hlsled` : Create [hlsled](./src/hls/hlsled) Vitis HLS project
- `open_hlsled` : Open hlsled project
- `clear_hlsled` : Delete [hlsled](./src/hls/hlsled) Vitis HLS project
- `build_test_hlsled` : Compile C++ Test of [hlsled](./src/hls/hlsled) (* You can run this test using `ctest`)
- `test_hlsled` : Run `build_test_hlsled` products
- `csynth_hlsled` : Perform high-level synthesis of [hlsled](./src/hls/hlsled)
- `cosim_hlsled` : Run C/RTL simulation of [hlsled](./src/hls/hlsled) (It don't work)

## Directory

- src/constraint/ : constraints
- src/rtl/ : Verilog RTL
- vivado/ : vivado project
- cmake/  : cmake codes

## Generated Vivado Project Directory

- `build/vivado/dfx/vivado_study.prj` : Vivado project
- `build/vivado/zynq/zynq_study.prj` : Zynq vivado project
- `build/vivado/zynq/zynq_vitis.prj` : Zynq vitis workspace
- `build/src/hls/hlsled/hlsled` : Vitis HLS project

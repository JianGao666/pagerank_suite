open_project pagerank_naive_hls

add_files pagerank.c
add_files input.data
add_files check.data
add_files -tb .../../common/harness.c
add_files local_support.c

set_top pagerank

open_solution -reset solution
set_part virtex7
create_clock -period 10

csynth_design
cosim_design -rtl verilog -tool xsim -trace_level all

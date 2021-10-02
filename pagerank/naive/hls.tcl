open_project pagerank_naive_hls

add_files pagerank.c
add_files -tb harness.c
add_files local_support.c
add_files support.c

set_top pagerank

open_solution -reset solution
set_part virtex7
create_clock -period 10

csynth_design
cosim_design -rtl verilog -tool xsim -trace_level all

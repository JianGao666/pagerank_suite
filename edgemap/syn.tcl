create_project -force vivado_syn ./syn -part xc7z020clg484-1

add_files -norecurse "
    pagerank_edgemap_hls/solution/syn/verilog/pagerank.v
    pagerank_edgemap_hls/solution/syn/verilog/pagerank_dadddsubbkb.v
    pagerank_edgemap_hls/solution/syn/verilog/pagerank_dcmp_64neOg.v
    pagerank_edgemap_hls/solution/syn/verilog/pagerank_ddiv_64ndEe.v
    pagerank_edgemap_hls/solution/syn/verilog/pagerank_dmul_64ncud.v
    pagerank_edgemap_hls/solution/syn/verilog/pagerank_uitodp_6fYi.v
"
source pagerank_edgemap_hls/solution/syn/verilog/pagerank_ap_dadddsub_2_full_dsp_64_ip.tcl
source pagerank_edgemap_hls/solution/syn/verilog/pagerank_ap_dcmp_0_no_dsp_64_ip.tcl
source pagerank_edgemap_hls/solution/syn/verilog/pagerank_ap_ddiv_15_no_dsp_64_ip.tcl
source pagerank_edgemap_hls/solution/syn/verilog/pagerank_ap_dmul_3_max_dsp_64_ip.tcl
source pagerank_edgemap_hls/solution/syn/verilog/pagerank_ap_uitodp_1_no_dsp_64_ip.tcl
add_files -fileset constrs_1 -norecurse xdc.xdc

launch_runs synth_1 -jobs 4
wait_on_run synth_1

exit
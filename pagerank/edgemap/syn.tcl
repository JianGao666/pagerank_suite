create_project -force vivado_syn ./syn -part xc7z020clg484-1

add_files -norecurse "
    pagerank_edgemap_hls/solution/syn/verilog/pagerank.v
"

add_files -fileset constrs_1 -norecurse xdc.xdc

launch_runs synth_1 -jobs 4
wait_on_run synth_1

exit
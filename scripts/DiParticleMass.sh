#!/bin/bash
curr_dir=$PWD
working_dir=/afs/desy.de/group/flc/pool/hosseins/DiMuonMass
detector_model=ILD_s5_o1_v02
cd $working_dir
no_process="$(wc -l < $working_dir/database_list/current_physical_processes.txt)"

for (( p=1; p<=$no_process; p++))
do
	current_processes="$(head -n $p ${working_dir}/database_list/current_physical_processes.txt | tail -1)"
	echo $current_processes
	no_files="$(wc -l < $working_dir/database_list/$detector_model/$current_processes.txt)"
	cp ${working_dir}/scripts/job_submit.submit ${working_dir}/submit_files/${current_processes}.submit
	sed -i s/current_processes/${current_processes}/g ${working_dir}/submit_files/${current_processes}.submit
	sed -i s/detector_model/${detector_model}/g ${working_dir}/submit_files/${current_processes}.submit
	sed -i s/N=50/N=${no_files}/g ${working_dir}/submit_files/${current_processes}.submit
	condor_submit ${working_dir}/submit_files/${current_processes}.submit
done
cd $curr_dir

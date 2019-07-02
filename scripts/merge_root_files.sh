#!/bin/bash
curr_dir=$PWD
detector_model=ILD_s5_o1_v02
working_dir=/afs/desy.de/group/flc/pool/hosseins/DiMuonMass
root_dir=/nfs/dust/ilc/user/hosseins/DiMuMass/root_files/$detector_model
cd $working_dir
no_process="$(wc -l < $working_dir/database_list/current_physical_processes.txt)"

for (( p=1; p<=$no_process; p++))
do
	current_processes="$(head -n $p ${working_dir}/database_list/current_physical_processes.txt | tail -1)"
	echo $current_processes
	no_files="$(wc -l < $working_dir/database_list/$detector_model/$current_processes.txt)"
	echo $no_files
	file_list=" "
	for (( n=1; n<=$no_files; n++))
	do
		file_list="$file_list ${root_dir}/${current_processes}_${n}.root"
	done
	hadd ${root_dir}/merged_root_files/${current_processes}.root ${file_list}
done
cd $curr_dir
#rm /nfs/dust/ilc/user/hosseins/DiMuMass/BIRD_LOG/ERR/*
#rm /nfs/dust/ilc/user/hosseins/DiMuMass/BIRD_LOG/LOG/*
#rm /nfs/dust/ilc/user/hosseins/DiMuMass/BIRD_LOG/OUT/*
#rm $root_dir/*.root

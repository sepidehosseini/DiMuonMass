#!/bin/bash
filename='/afs/desy.de/group/flc/pool/hosseins/Internship/mymarlin/examples/DiMuonMassProcessor/physical_processes.txt'
n=1
while read line; do
# reading each line
physical_process[n]=$line
echo "Line No. $n : $line"
if (($n <= 34)); then
	ls /pnfs/desy.de/ilc/prod/ilc/mc-opt-3/ild/dst-merged/500-TDR_ws/$line/ILD_l5_o1_v02/v02-00-01/* > /afs/desy.de/group/flc/pool/hosseins/Internship/mymarlin/examples/DiMuonMassProcessor/database_list/ILD_l5_o1_v02/$line.txt
	ls /pnfs/desy.de/ilc/prod/ilc/mc-opt-3/ild/dst-merged/500-TDR_ws/$line/ILD_s5_o1_v02/v02-00-01/* > /afs/desy.de/group/flc/pool/hosseins/Internship/mymarlin/examples/DiMuonMassProcessor/database_list/ILD_s5_o1_v02/$line.txt
else
	ls /pnfs/desy.de/ilc/prod/ilc/mc-opt-3/ild/dst-merged/500-TDR_ws/$line/ILD_l5_o1_v02_nobg/v02-00-01/* > /afs/desy.de/group/flc/pool/hosseins/Internship/mymarlin/examples/DiMuonMassProcessor/database_list/ILD_l5_o1_v02/$line.txt
	ls /pnfs/desy.de/ilc/prod/ilc/mc-opt-3/ild/dst-merged/500-TDR_ws/$line/ILD_s5_o1_v02_nobg/v02-00-01/* > /afs/desy.de/group/flc/pool/hosseins/Internship/mymarlin/examples/DiMuonMassProcessor/database_list/ILD_s5_o1_v02/$line.txt
fi
n=$((n+1))
echo $physical_process[n-1]
done < $filename



#export cur_fil="$(sed -n '2p' < ../database_list/2f_Z_hadronic.txt)"

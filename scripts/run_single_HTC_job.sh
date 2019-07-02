#!/bin/bash

source /cvmfs/ilc.desy.de/sw/x86_64_gcc49_sl6/v02-00-02/init_ilcsoft.sh

export MARLIN_DLL=/cvmfs/ilc.desy.de/sw/x86_64_gcc49_sl6/v02-00-02/MarlinDD4hep/v00-06/lib/libMarlinDD4hep.so:/cvmfs/ilc.desy.de/sw/x86_64_gcc49_sl6/v02-00-02/DDMarlinPandora/v00-10/lib/libDDMarlinPandora.so:/cvmfs/ilc.desy.de/sw/x86_64_gcc49_sl6/v02-00-02/MarlinReco/v01-25/lib/libMarlinReco.so:/cvmfs/ilc.desy.de/sw/x86_64_gcc49_sl6/v02-00-02/PandoraAnalysis/v02-00-00/lib/libPandoraAnalysis.so:/cvmfs/ilc.desy.de/sw/x86_64_gcc49_sl6/v02-00-02/LCFIVertex/v00-07-04/lib/libLCFIVertexProcessors.so:/cvmfs/ilc.desy.de/sw/x86_64_gcc49_sl6/v02-00-02/CEDViewer/v01-16/lib/libCEDViewer.so:/cvmfs/ilc.desy.de/sw/x86_64_gcc49_sl6/v02-00-02/Overlay/v00-21/lib/libOverlay.so:/cvmfs/ilc.desy.de/sw/x86_64_gcc49_sl6/v02-00-02/MarlinFastJet/v00-05-01/lib/libMarlinFastJet.so:/cvmfs/ilc.desy.de/sw/x86_64_gcc49_sl6/v02-00-02/LCTuple/v01-11/lib/libLCTuple.so:/cvmfs/ilc.desy.de/sw/x86_64_gcc49_sl6/v02-00-02/MarlinKinfit/v00-06/lib/libMarlinKinfit.so:/cvmfs/ilc.desy.de/sw/x86_64_gcc49_sl6/v02-00-02/MarlinTrkProcessors/v02-10/lib/libMarlinTrkProcessors.so:/cvmfs/ilc.desy.de/sw/x86_64_gcc49_sl6/v02-00-02/MarlinKinfitProcessors/v00-04/lib/libMarlinKinfitProcessors.so:/cvmfs/ilc.desy.de/sw/x86_64_gcc49_sl6/v02-00-02/ILDPerformance/v01-06/lib/libILDPerformance.so:/cvmfs/ilc.desy.de/sw/x86_64_gcc49_sl6/v02-00-02/Clupatra/v01-03/lib/libClupatra.so:/cvmfs/ilc.desy.de/sw/x86_64_gcc49_sl6/v02-00-02/Physsim/v00-04-01/lib/libPhyssim.so:/cvmfs/ilc.desy.de/sw/x86_64_gcc49_sl6/v02-00-02/LCFIPlus/v00-06-09/lib/libLCFIPlus.so:/cvmfs/ilc.desy.de/sw/x86_64_gcc49_sl6/v02-00-02/FCalClusterer/v01-00/lib/libFCalClusterer.so:/cvmfs/ilc.desy.de/sw/x86_64_gcc49_sl6/v02-00-02/ForwardTracking/v01-13/lib/libForwardTracking.so:/cvmfs/ilc.desy.de/sw/x86_64_gcc49_sl6/v02-00-02/ConformalTracking/v01-07/lib/libConformalTracking.so:/cvmfs/ilc.desy.de/sw/x86_64_gcc49_sl6/v02-00-02/LICH/v00-01/lib/libLICH.so:/cvmfs/ilc.desy.de/sw/x86_64_gcc49_sl6/v02-00-02/MarlinTPC/v01-04/lib/libMarlinTPC.so:/cvmfs/ilc.desy.de/sw/x86_64_gcc49_sl6/v02-00-02/Garlic/v03-01/lib/libGarlic.so:/afs/desy.de/group/flc/pool/hosseins/DiMuonMass/lib/libDiMuonMass.so

current_processes=$1

file_no=$2

detecctor_model=$3

file_id=`expr $2 + 1`

database_DIR=/afs/desy.de/group/flc/pool/hosseins/DiMuonMass/database_list/${detecctor_model}

root_dir=/nfs/dust/ilc/user/hosseins/DiMuMass/root_files/${detecctor_model}

out_DIR=/nfs/dust/ilc/user/hosseins/DiMuMass/Marlin_Out

input_file="$(head -n ${file_id} ${database_DIR}/${current_processes}.txt | tail -1)"

cd /afs/desy.de/group/flc/pool/hosseins/DiMuonMass

Marlin xml/mymarlin_htcondor.xml --global.LCIOInputFiles=${input_file} --constant.OutputBaseName=${root_dir}/${current_processes}_${file_id} # > $out_DIR/Marlin_${current_processes}_${file_id}.out

#!/bin/bash
curr_dir=$PWD
detector_model=ILD_s5_o1_v02
root_dir=/nfs/dust/ilc/user/hosseins/DiMuMass/root_files/$detector_model
rm /nfs/dust/ilc/user/hosseins/DiMuMass/BIRD_LOG/ERR/*
rm /nfs/dust/ilc/user/hosseins/DiMuMass/BIRD_LOG/LOG/*
rm /nfs/dust/ilc/user/hosseins/DiMuMass/BIRD_LOG/OUT/*
rm $root_dir/*.root

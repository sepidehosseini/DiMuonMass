using namespace std;
void JpsiInvMass()
{
	string file_path_mcp = "/nfs/dust/ilc/user/hosseins/DiMuMass/root_files/ILD_l5_o1_v02/merged_root_files/";
	string file_path_l5 = "/nfs/dust/ilc/user/hosseins/DiMuMass/root_files/ILD_l5_o1_v02/merged_root_files/";
	string file_path_s5 = "/nfs/dust/ilc/user/hosseins/DiMuMass/root_files/ILD_s5_o1_v02/merged_root_files/";
	string plots_dir = "/afs/desy.de/group/flc/pool/hosseins/DiMuonMass/Analysis/Plots/";
	std::string input_tree_name = "DiMuonMass";

	std::vector<std::string> physical_process;
	physical_process.push_back("2f_Z_hadronic");
/*	physical_process.push_back("4f_singleW_semileptonic");
	physical_process.push_back("4f_singleZee_semileptonic");
	physical_process.push_back("4f_singleZnunu_semileptonic");
	physical_process.push_back("4f_WW_hadronic");
	physical_process.push_back("4f_WW_semileptonic");
	physical_process.push_back("4f_ZZ_hadronic");
	physical_process.push_back("4f_ZZ_semileptonic");
	physical_process.push_back("4f_ZZWWMix_hadronic");
	physical_process.push_back("6f_eeWW");
	physical_process.push_back("6f_llWW");
	physical_process.push_back("6f_ttbar");
	physical_process.push_back("6f_vvWW");
	physical_process.push_back("6f_xxWW");
	physical_process.push_back("6f_xxxxZ");
	physical_process.push_back("6f_yyyyZ");
*/	
	std::vector<float> e_pol_percentage = {-0.8,-0.8,0.8,0.8};
	std::vector<float> p_pol_percentage = {-0.3,0.3,-0.3,0.3};

	for (int n=0; n<physical_process.size();++n)
	{
		TFile *file_l5 = new TFile((file_path_l5+physical_process[n]+".root").c_str());
		TTree *tree_l5 = (TTree*)file_l5->Get((input_tree_name).c_str());
		int nEntries_l5 = tree_l5->GetEntries();
		TFile *file_s5 = new TFile((file_path_s5+physical_process[n]+".root").c_str());
		TTree *tree_s5 = (TTree*)file_s5->Get((input_tree_name).c_str());
		int nEntries_s5 = tree_s5->GetEntries();
		float xSection_l5 = 0;
		float ePol_l5 = 0;
		float pPol_l5 = 0;
		float xSection_s5 = 0;
		float ePol_s5 = 0;
		float pPol_s5 = 0;
		int nMuons_MCP = 0;
		int nJpsiLikesign_MCP = 0;
		int nJpsiOppositesign_MCP = 0;
		int nMuons_l5 = 0;
		int nJpsiLikesign_l5 = 0;
		int nJpsiOppositesign_l5 = 0;
		int nMuons_s5 = 0;
		int nJpsiLikesign_s5 = 0;
		int nJpsiOppositesign_s5 = 0;

		vector<int> N_l5 = {0,0,0,0};
		vector<float> sig_l5 = {0,0,0,0};
		vector<float> Sigma_l5 = {0,0,0,0};
		vector<float> Luminosity_l5 = {0,0,0,0};
		vector<float> weight_l5 = {0,0,0,0};
		vector<int> N_s5 = {0,0,0,0};
		vector<float> sig_s5 = {0,0,0,0};
		vector<float> Sigma_s5 = {0,0,0,0};
		vector<float> Luminosity_s5 = {0,0,0,0};
		vector<float> weight_s5 = {0,0,0,0};


		vector<float> mcpJpsiCharge;
		vector<float> JpsiPt_MCP;
		vector<float> JpsiCosTheta_MCP;
		vector<float> JpsiInvMass_MCP;
		vector<float> JpsiCharge_l5;
		vector<float> JpsiPt_l5;
		vector<float> JpsiCosTheta_l5;
		vector<float> JpsiInvMass_l5;
		vector<float> JpsiCharge_s5;
		vector<float> JpsiPt_s5;
		vector<float> JpsiCosTheta_s5;
		vector<float> JpsiInvMass_s5;
		
		tree_l5->SetBranchAddress("CrossSection",&xSection_l5);
		tree_l5->SetBranchAddress("polarizationElectron",&ePol_l5);
		tree_l5->SetBranchAddress("polarizationPositron",&pPol_l5);
	/*	tree_l5->SetBranchAddress("nMcpMuons",&nMuons_MCP);
		tree_l5->SetBranchAddress("nMcpJpsisLikeSign",&nJpsiLikesign_MCP);
		tree_l5->SetBranchAddress("nMcpJpsisOppositeSign",&nJpsiOppositesign_MCP);
		tree_l5->SetBranchAddress("mcpJpsiCharge",mcpJpsiCharge);		
		tree_l5->SetBranchAddress("mcpJpsiPt",&JpsiPt_MCP);
		tree_l5->SetBranchAddress("mcpJpsiCosTheta",&JpsiCosTheta_MCP);
		tree_l5->SetBranchAddress("mcpJpsiInvMass",&JpsiInvMass_MCP);


*/


	}


}

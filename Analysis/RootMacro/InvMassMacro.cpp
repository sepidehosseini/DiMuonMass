using namespace std;
void InvMassMacro()
{
	string file_path_mcp = "/nfs/dust/ilc/user/hosseins/DiMuMass/root_files/ILD_l5_o1_v02/merged_root_files/";
	string file_path_l5 = "/nfs/dust/ilc/user/hosseins/DiMuMass/root_files/ILD_l5_o1_v02/merged_root_files/";
	string file_path_s5 = "/nfs/dust/ilc/user/hosseins/DiMuMass/root_files/ILD_s5_o1_v02/merged_root_files/";
	string plots_dir = "/afs/desy.de/group/flc/pool/hosseins/DiMuonMass/Analysis/Plots/";
	std::string input_tree_name = "DiMuonMass";

	std::vector<std::string> physical_process;
	physical_process.push_back("2f_Z_hadronic");
	physical_process.push_back("4f_singleW_semileptonic");
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
	
	int n_bins=100;
	
	TFile *file_mcp = new TFile((file_path_mcp+physical_process[0]+".root").c_str());
	TTree *tree_mcp = (TTree*)file_mcp->Get((input_tree_name).c_str());
	int nEntries_mcp = tree_mcp->GetEntries();
	float xSection = 0;
	float ePol = 0;
	float pPol = 0;
	int mcp_PDG1 = 0;
	int mcp_PDG2 = 0;
	float mcpCosTheta1 = 0;
	float mcpCosTheta2 = 0;
	float mcpInvMass = 0;
	int pfo_PDG1 = 0;
	int pfo_PDG2 = 0;
	float pfoCosTheta1 = 0;
	float pfoCosTheta2 = 0;
	float pfoInvMass = 0;
	tree_mcp->SetBranchAddress("CrossSection",&xSection);
	tree_mcp->SetBranchAddress("polarizationElectron",&ePol);
	tree_mcp->SetBranchAddress("polarizationPositron",&pPol);
	tree_mcp->SetBranchAddress("mcpPDG1", &mcp_PDG1);
	tree_mcp->SetBranchAddress("mcpPDG2", &mcp_PDG2);
	tree_mcp->SetBranchAddress("mcpCosTheta1",&mcpCosTheta1);
	tree_mcp->SetBranchAddress("mcpCosTheta2",&mcpCosTheta2);
	tree_mcp->SetBranchAddress("mcpInvMass", &mcpInvMass);
	tree_mcp->SetBranchAddress("pfoPDG1", &pfo_PDG1);
	tree_mcp->SetBranchAddress("pfoPDG2", &pfo_PDG2);
	tree_mcp->SetBranchAddress("pfoCosTheta1",&pfoCosTheta1);
	tree_mcp->SetBranchAddress("pfoCosTheta2",&pfoCosTheta2);
	tree_mcp->SetBranchAddress("pfoInvMass", &pfoInvMass);
	
	TH1 *h_mcpInvMass_os = new TH1F("h_mcpInvMass_os","Invariant Mass of DiMuons", n_bins,0.,10.);
	TH1 *h_mcpInvMass_ls = new TH1F("h_mcpInvMass_ls","Invariant Mass of DiMuons", n_bins,0.,10.);
	TH1 *h_pfoInvMass_os = new TH1F("h_pfoInvMass_os","Invariant Mass of DiMuons", n_bins,0.,10.);
	TH1 *h_pfoInvMass_ls = new TH1F("h_pfoInvMass_ls","Invariant Mass of DiMuons", n_bins,0.,10.);
	for (int i=0; i<nEntries_mcp; ++i)
	{
		tree_mcp->GetEntry(i);
		if ((mcp_PDG1==13 && mcp_PDG2==-13)||(mcp_PDG1==-13 && mcp_PDG2==13))
		{
			h_mcpInvMass_os->Fill(mcpInvMass);
		}
		if ((mcp_PDG1==13 && mcp_PDG2==13)||(mcp_PDG1==-13 && mcp_PDG2==-13))
		{
			h_mcpInvMass_ls->Fill(mcpInvMass);		
		}
		if ((pfo_PDG1==13 && pfo_PDG2==-13)||(pfo_PDG1==-13 && pfo_PDG2==13))
		{
			h_pfoInvMass_os->Fill(pfoInvMass);
		}
		if ((pfo_PDG1==13 && pfo_PDG2==13)||(pfo_PDG1==-13 && pfo_PDG2==-13))
		{
			h_pfoInvMass_ls->Fill(pfoInvMass);		
		}
	}
	
	TCanvas *can_mcpInvMass = new TCanvas("can_mcpInvMass","",800,800);
	h_mcpInvMass_os->Draw();
	h_mcpInvMass_ls->Draw("same");
	can_mcpInvMass->SaveAs((plots_dir+"mcpInvMass.pdf").c_str());
	TCanvas *can_pfoInvMass = new TCanvas("can_pfoInvMass","",800,800);
	h_pfoInvMass_ls->Draw();
	h_pfoInvMass_os->Draw("same");
	can_pfoInvMass->SaveAs((plots_dir+"pfoInvMass.pdf").c_str());
	
}

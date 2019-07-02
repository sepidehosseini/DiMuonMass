
TLatex* add_ILD_mark( TCanvas* canvas, Double_t x0, Double_t y0, Float_t text_size=0.25 ) {
  canvas->cd();
  TLatex* ild_tex = new TLatex(x0,y0,"ILD ");
  ild_tex->SetName( (string(canvas->GetName()) + "_ildlogo").c_str() );
  ild_tex->SetTextSize(text_size);
  ild_tex->SetTextFont(62);
  ild_tex->SetLineWidth(2);
  ild_tex->Draw();
  return ild_tex;
}

TLatex* add_prelim_mark( TCanvas* canvas, Double_t x0, Double_t y0, Float_t text_size=0.2 ) {
  canvas->cd();
  TLatex* prelim_tex = new TLatex(x0,y0,"preliminary");
  prelim_tex->SetName( (string(canvas->GetName()) + "_prelim_text").c_str() );
  prelim_tex->SetTextSize(text_size);
  prelim_tex->SetTextFont(42);
  prelim_tex->SetLineWidth(2);
  prelim_tex->Draw();
  return prelim_tex;
}



using namespace std;
void InvMassMacro_1()
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

	TH1 *h_mcpInvMass_os = new TH1F("h_mcpInvMass_os","Invariant Mass of DiMuons(MC)", n_bins,2.8,3.8);
	TH1 *h_mcpInvMass_ls = new TH1F("h_mcpInvMass_ls","Invariant Mass of DiMuons(MC)", n_bins,2.8,3.8);
	TH1 *h_mcpInvMass_norm = new TH1F("h_mcpInvMass_norm","Invariant Mass of DiMuons Norm(MC)", n_bins,2.8,3.8);
	//TH1 *h_pfoInvMass_norm_l5_vs_s5 = new TH1F("h_pfoInvMass_norm_l5_vs_s5","", n_bins,2.8,3.8);

	TH1 *h_pfoInvMass_l5_vs_s5 = new TH1F("h_pfoInvMass_l5_vs_s5","Invariant Mass of DiMuons l5_s5", n_bins,2.8,3.8);
	TH1 *h_pfoInvMass_os_l5 = new TH1F("h_pfoInvMass_os_l5","Invariant Mass of DiMuons", n_bins,2.8,3.8);
	TH1 *h_pfoInvMass_ls_l5 = new TH1F("h_pfoInvMass_ls_l5","Invariant Mass of DiMuons", n_bins,2.8,3.8);
	TH1 *h_pfoInvMass_norm_l5 = new TH1F("h_pfoInvMass_norm_l5","", n_bins,2.8,3.8);
	TH1 *h_pfoInvMass_os_s5 = new TH1F("h_pfoInvMass_os_s5","Invariant Mass of DiMuons", n_bins,2.8,3.8);
	TH1 *h_pfoInvMass_ls_s5 = new TH1F("h_pfoInvMass_ls_s5","Invariant Mass of DiMuons", n_bins,2.8,3.8);
	TH1 *h_pfoInvMass_norm_s5 = new TH1F("h_pfoInvMass_norm_s5","Invariant Mass of DiMuons Norm(Rec)", n_bins,2.8,3.8);
	TH1 *h_mcpCosTheta_os = new TH1F("h_mcpCosTheta_os","CosTheta of DiMuons", n_bins,-1.,1.);
	TH1 *h_mcpCosTheta_ls = new TH1F("h_mcpCosTheta_ls","CosTheta of DiMuons", n_bins,-1.,1.);
	TH1 *h_mcpCosTheta_norm = new TH1F("h_mcpCosTheta_norm","CosTheta of DiMuons Norm(MC)", n_bins,-1.,1.);
	TH1 *h_pfoCosTheta_os_l5 = new TH1F("h_pfoCosTheta_os_l5","CosTheta of DiMuons", n_bins,-1.,1.);
	TH1 *h_pfoCosTheta_ls_l5 = new TH1F("h_pfoCosTheta_ls_l5","CosTheta of DiMuons", n_bins,-1.,1.);
	TH1 *h_pfoCosTheta_norm_l5 = new TH1F("h_pfoCosTheta_norm_l5","CosTheta of DiMuons Norm(Rec)", n_bins,-1.,1.);
	TH1 *h_pfoCosTheta_os_s5 = new TH1F("h_pfoCosTheta_os_s5","CosTheta of DiMuons", n_bins,-1.,1.);
	TH1 *h_pfoCosTheta_ls_s5 = new TH1F("h_pfoCosTheta_ls_s5","CosTheta of DiMuons", n_bins,-1.,1.);
	TH1 *h_pfoCosTheta_norm_s5 = new TH1F("h_pfoCosTheta_norm_s5","CosTheta of DiMuons Norm(Rec)", n_bins,-1.,1.);
	TH1 *h_mcpCosThetaMuon_os = new TH1F("h_mcpCosThetaMuon_os","CosTheta of Muon", n_bins,-1.,1.);
	TH1 *h_mcpCosThetaMuon_ls = new TH1F("h_mcpCosThetaMuon_ls","CosTheta of Muon", n_bins,-1.,1.);
	TH1 *h_mcpCosThetaMuon_norm = new TH1F("h_mcpCosThetaMuon_norm","CosTheta of Muon Norm(MC)", n_bins,-1.,1.);
	TH1 *h_pfoCosThetaMuon_os_l5 = new TH1F("h_pfoCosThetaMuon_os_l5","CosTheta of Muon", n_bins,-1.,1.);
	TH1 *h_pfoCosThetaMuon_ls_l5 = new TH1F("h_pfoCosThetaMuon_ls_l5","CosTheta of Muon", n_bins,-1.,1.);
	TH1 *h_pfoCosThetaMuon_norm_l5 = new TH1F("h_pfoCosThetaMuon_norm_l5","CosTheta of Muon Norm(Rec)", n_bins,-1.,1.);
	TH1 *h_pfoCosThetaMuon_os_s5 = new TH1F("h_pfoCosThetaMuon_os_s5","CosTheta of Muon", n_bins,-1.,1.);
	TH1 *h_pfoCosThetaMuon_ls_s5 = new TH1F("h_pfoCosThetaMuon_ls_s5","CosTheta of Muon", n_bins,-1.,1.);
	TH1 *h_pfoCosThetaMuon_norm_s5 = new TH1F("h_pfoCosThetaMuon_norm_s5","CosTheta of Muon Norm(Rec)", n_bins,-1.,1.);
	TH1 *h_mcpCosThetaAntimuon_os = new TH1F("h_mcpCosThetaAntimuon_os","CosTheta of Antimuon", n_bins,-1.,1.);
	TH1 *h_mcpCosThetaAntimuon_ls = new TH1F("h_mcpCosThetaAntimuon_ls","CosTheta of Antimuon", n_bins,-1.,1.);
	TH1 *h_mcpCosThetaAntimuon_norm = new TH1F("h_mcpCosThetaAntimuon_norm","CosTheta of Antimuon Norm(MC)", n_bins,-1.,1.);
	TH1 *h_pfoCosThetaAntimuon_os_l5 = new TH1F("h_pfoCosThetaAntimuon_os_l5","CosTheta of AntiMuon", n_bins,-1.,1.);
	TH1 *h_pfoCosThetaAntimuon_ls_l5 = new TH1F("h_pfoCosThetaAntimuon_ls_l5","CosTheta of AntiMuon", n_bins,-1.,1.);
	TH1 *h_pfoCosThetaAntimuon_norm_l5 = new TH1F("h_pfoCosThetaAntimuon_norm_l5","CosTheta of AntiMuon Norm(Rec)", n_bins,-1.,1.);
	TH1 *h_pfoCosThetaAntimuon_os_s5 = new TH1F("h_pfoCosThetaAntimuon_os_s5","CosTheta of AntiMuon", n_bins,-1.,1.);
	TH1 *h_pfoCosThetaAntimuon_ls_s5 = new TH1F("h_pfoCosThetaAntimuon_ls_s5","CosTheta of AntiMuon", n_bins,-1.,1.);
	TH1 *h_pfoCosThetaAntimuon_norm_s5 = new TH1F("h_pfoCosThetaAntimuon_norm_s5","CosTheta of AntiMuon Norm(Rec)", n_bins,-1.,1.);
	TH1 *h_mcpPt_os = new TH1F("h_mcpPt_os","Pt of DiMuons", n_bins,0.,100.);
	TH1 *h_mcpPt_ls = new TH1F("h_mcpPt_ls","Pt of DiMuons", n_bins,0.,100.);
	TH1 *h_mcpPt_norm = new TH1F("h_mcpPt_norm","Pt of DiMuons Norm(MC)", n_bins,0.,100.);
	TH1 *h_pfoPt_os_l5 = new TH1F("h_pfoPt_os_l5","Pt of DiMuons", n_bins,0.,100.);
	TH1 *h_pfoPt_ls_l5 = new TH1F("h_pfoPt_ls_l5","Pt of DiMuons", n_bins,0.,100.);
	TH1 *h_pfoPt_norm_l5 = new TH1F("h_pfoPt_norm_l5","Pt of DiMuons Norm(Rec)", n_bins,0.,100.);
	TH1 *h_pfoPt_os_s5 = new TH1F("h_pfoPt_os_s5","Pt of DiMuons", n_bins,0.,100.);
	TH1 *h_pfoPt_ls_s5 = new TH1F("h_pfoPt_ls_s5","Pt of DiMuons", n_bins,0.,100.);
	TH1 *h_pfoPt_norm_s5 = new TH1F("h_pfoPt_norm_s5","Pt of DiMuons Norm(Rec)", n_bins,0.,100.);

	std::vector<float> e_pol_percentage = {-0.8,-0.8,0.8,0.8};
	std::vector<float> p_pol_percentage = {-0.3,0.3,-0.3,0.3};

	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;


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
	int mcp_PDG1 = 0;
	int mcp_PDG2 = 0;
	float mcpCosTheta1 = 0;
	float mcpCosTheta2 = 0;
	float mcpCosTheta = 0;
	float mcpInvMass = 0;
	int pfo_PDG1_l5 = 0;
	int pfo_PDG2_l5 = 0;
	float pfoCosTheta1_l5 = 0;
	float pfoCosTheta2_l5 = 0;
	float pfoCosTheta_l5 = 0;
	float pfoInvMass_l5 = 0;
	float mcpPt = 0;
	float pfoPt_l5 = 0;
	float mcpPx1 = 0;
	float mcpPx2 = 0;
	float mcpPy1 = 0;
	float mcpPy2 = 0;
	float mcpPz1 = 0;
	float mcpPz2 = 0;
	float pfoPx1_l5 = 0;
	float pfoPx2_l5 = 0;
	float pfoPy1_l5 = 0;
	float pfoPy2_l5 = 0;
	float pfoPz1_l5 = 0;
	float pfoPz2_l5 = 0;
	float pfoPt_s5 = 0;
	float pfoPx1_s5 = 0;
	float pfoPx2_s5 = 0;
	float pfoPy1_s5 = 0;
	float pfoPy2_s5 = 0;
	float pfoPz1_s5 = 0;
	float pfoPz2_s5 = 0;

	float xSection_s5 = 0;
	float ePol_s5 = 0;
	float pPol_s5 = 0;
	int pfo_PDG1_s5 = 0;
	int pfo_PDG2_s5 = 0;
	float pfoCosTheta1_s5 = 0;
	float pfoCosTheta2_s5 = 0;
	float pfoCosTheta_s5 = 0;
	float pfoInvMass_s5 = 0;
/*
*************************************************************
	N_ll = N[0] ; N_lr = N[1] ; N_rl = N[2] ; N_rr = N[3]
*************************************************************
*/
	std::vector<int> N_l5 = {0,0,0,0};
	std::vector<float> sig_l5 = {0,0,0,0};
	std::vector<float> Sigma_l5 = {0,0,0,0};
	std::vector<float> Luminosity_l5 = {0,0,0,0};
	std::vector<float> weight_l5 = {0,0,0,0};
	std::vector<int> N_s5 = {0,0,0,0};
	std::vector<float> sig_s5 = {0,0,0,0};
	std::vector<float> Sigma_s5 = {0,0,0,0};
	std::vector<float> Luminosity_s5 = {0,0,0,0};
	std::vector<float> weight_s5 = {0,0,0,0};


	tree_l5->SetBranchAddress("CrossSection",&xSection_l5);
	tree_l5->SetBranchAddress("polarizationElectron",&ePol_l5);
	tree_l5->SetBranchAddress("polarizationPositron",&pPol_l5);

	tree_l5->SetBranchAddress("mcpPDG1", &mcp_PDG1);
	tree_l5->SetBranchAddress("mcpPDG2", &mcp_PDG2);
	tree_l5->SetBranchAddress("mcpCosTheta1",&mcpCosTheta1);
	tree_l5->SetBranchAddress("mcpCosTheta2",&mcpCosTheta2);
	tree_l5->SetBranchAddress("mcpCosTheta",&mcpCosTheta);
	tree_l5->SetBranchAddress("mcpInvMass", &mcpInvMass);
	tree_l5->SetBranchAddress("mcpPt", &mcpPt);
	tree_l5->SetBranchAddress("mcpPx1", &mcpPx1);
	tree_l5->SetBranchAddress("mcpPx2", &mcpPx2);
	tree_l5->SetBranchAddress("mcpPy1", &mcpPy1);
	tree_l5->SetBranchAddress("mcpPy2", &mcpPy2);
	tree_l5->SetBranchAddress("mcpPz1", &mcpPz1);
	tree_l5->SetBranchAddress("mcpPz2", &mcpPz2);

	tree_l5->SetBranchAddress("pfoPDG1", &pfo_PDG1_l5);
	tree_l5->SetBranchAddress("pfoPDG2", &pfo_PDG2_l5);
	tree_l5->SetBranchAddress("pfoCosTheta1",&pfoCosTheta1_l5);
	tree_l5->SetBranchAddress("pfoCosTheta2",&pfoCosTheta2_l5);
	tree_l5->SetBranchAddress("pfoCosTheta",&pfoCosTheta_l5);
	tree_l5->SetBranchAddress("pfoInvMass", &pfoInvMass_l5);
	tree_l5->SetBranchAddress("pfoPt", &pfoPt_l5);
	tree_l5->SetBranchAddress("pfoPx1", &pfoPx1_l5);
	tree_l5->SetBranchAddress("pfoPx2", &pfoPx2_l5);
	tree_l5->SetBranchAddress("pfoPy1", &pfoPy1_l5);
	tree_l5->SetBranchAddress("pfoPy2", &pfoPy2_l5);
	tree_l5->SetBranchAddress("pfoPz1", &pfoPz1_l5);
	tree_l5->SetBranchAddress("pfoPz2", &pfoPz2_l5);


	tree_s5->SetBranchAddress("CrossSection",&xSection_s5);
	tree_s5->SetBranchAddress("polarizationElectron",&ePol_s5);
	tree_s5->SetBranchAddress("polarizationPositron",&pPol_s5);

	tree_s5->SetBranchAddress("pfoPDG1", &pfo_PDG1_s5);
	tree_s5->SetBranchAddress("pfoPDG2", &pfo_PDG2_s5);
	tree_s5->SetBranchAddress("pfoCosTheta1",&pfoCosTheta1_s5);
	tree_s5->SetBranchAddress("pfoCosTheta2",&pfoCosTheta2_s5);
	tree_s5->SetBranchAddress("pfoCosTheta",&pfoCosTheta_s5);
	tree_s5->SetBranchAddress("pfoInvMass", &pfoInvMass_s5);
	tree_s5->SetBranchAddress("pfoPt", &pfoPt_s5);
	tree_s5->SetBranchAddress("pfoPx1", &pfoPx1_s5);
	tree_s5->SetBranchAddress("pfoPx2", &pfoPx2_s5);
	tree_s5->SetBranchAddress("pfoPy1", &pfoPy1_s5);
	tree_s5->SetBranchAddress("pfoPy2", &pfoPy2_s5);
	tree_s5->SetBranchAddress("pfoPz1", &pfoPz1_s5);
	tree_s5->SetBranchAddress("pfoPz2", &pfoPz2_s5);

	for (int i=0; i<nEntries_l5; ++i)
	{
		tree_l5->GetEntry(i);
		N_l5[((2*ePol_l5+pPol_l5)+3)/2]++;
		sig_l5[((2*ePol_l5+pPol_l5)+3)/2]=xSection_l5;
		Luminosity_l5[((2*ePol_l5+pPol_l5)+3)/2]=(1.-ePol_l5*pPol_l5)*1600./2. + (1.+ePol_l5*pPol_l5)*400./2.;
	}

	for (int p=0; p<e_pol_percentage.size(); ++p)
	{
		Sigma_l5[p] = 0.25 *( (1 - e_pol_percentage[p]) * (1 - p_pol_percentage[p]) * sig_l5[0] + (1 - e_pol_percentage[p]) * (1 + p_pol_percentage[p]) * sig_l5[1] + (1 + e_pol_percentage[p]) * (1 - p_pol_percentage[p]) * sig_l5[2] + (1 + e_pol_percentage[p]) * (1 + p_pol_percentage[p]) * sig_l5[3] );
		if (N_l5[p]!=0)
		{
			weight_l5[p] = double(Sigma_l5[p]) * double(Luminosity_l5[p]) / double(N_l5[p]);
		}
		if (N_l5[p]==0)
		{
			weight_l5[p] = 0;
		}
	}
	cout << "***************                Processing " << physical_process[n] << "               ***************" << endl;
	cout << "" << endl;
	cout << "******************************************   ILD_l5_v2   ******************************************" << endl;
	cout << "N_ll = " << N_l5[0] << " ;		Luminosity_l5_ll = " << Luminosity_l5[0] << " ;		CrossSection_MM = " << Sigma_l5[0] << " ;		Weighting_ll = " << weight_l5[0] << endl;
	cout << "N_lr = " << N_l5[1] << " ;		Luminosity_l5_lr = " << Luminosity_l5[1] << " ;		CrossSection_MP = " << Sigma_l5[1] << " ;		Weighting_lr = " << weight_l5[1] << endl;
	cout << "N_rl = " << N_l5[2] << " ;		Luminosity_l5_rl = " << Luminosity_l5[2] << " ;		CrossSection_PM = " << Sigma_l5[2] << " ;		Weighting_rl = " << weight_l5[2] << endl;
	cout << "N_rr = " << N_l5[3] << " ;		Luminosity_l5_rr = " << Luminosity_l5[3] << " ;		CrossSection_PP = " << Sigma_l5[3] << " ;		Weighting_rr = " << weight_l5[3] << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;

	for (int i=0; i<nEntries_s5; ++i)
	{
		tree_s5->GetEntry(i);
		N_s5[((2*ePol_s5+pPol_s5)+3)/2]++;
		sig_s5[((2*ePol_s5+pPol_s5)+3)/2]=xSection_s5;
		Luminosity_s5[((2*ePol_s5+pPol_s5)+3)/2]=(1-ePol_s5*pPol_s5)*1600/2 + (1+ePol_s5*pPol_s5)*400/2;
	}

	for (int p=0; p<e_pol_percentage.size(); ++p)
	{
		Sigma_s5[p] = (1 - e_pol_percentage[p]) * (1 - p_pol_percentage[p]) * sig_s5[0] + (1 - e_pol_percentage[p]) * (1 + p_pol_percentage[p]) * sig_s5[1] + (1 + e_pol_percentage[p]) * (1 - p_pol_percentage[p]) * sig_s5[2] + (1 + e_pol_percentage[p]) * (1 + p_pol_percentage[p]) * sig_s5[3];
		if (N_s5[p]!=0)
		{
			weight_s5[p] = 0.25 * Sigma_s5[p] * Luminosity_s5[p] / N_s5[p];
		}
		if (N_s5[p]==0)
		{
			weight_s5[p] = 0;
		}
	}
	cout << "******************************************   ILD_s5_v2   ******************************************" << endl;
	cout << "N_ll = " << N_s5[0] << " ;		Luminosity_s5_ll = " << Luminosity_s5[0] << " ;		CrossSection_ll = " << sig_s5[0] << " ;		Weighting_ll = " << weight_s5[0] << endl;
	cout << "N_lr = " << N_s5[1] << " ;		Luminosity_s5_lr = " << Luminosity_s5[1] << " ;		CrossSection_lr = " << sig_s5[1] << " ;		Weighting_lr = " << weight_s5[1] << endl;
	cout << "N_rl = " << N_s5[2] << " ;		Luminosity_s5_rl = " << Luminosity_s5[2] << " ;		CrossSection_rl = " << sig_s5[2] << " ;		Weighting_rl = " << weight_s5[2] << endl;
	cout << "N_rr = " << N_s5[3] << " ;		Luminosity_s5_rr = " << Luminosity_s5[3] << " ;		CrossSection_rr = " << sig_s5[3] << " ;		Weighting_rr = " << weight_s5[3] << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;

	int int_mcpInvMass_os=0;
	int int_mcpInvMass_ls=0;
	int int_pfoInvMass_os_l5=0;
	int int_pfoInvMass_ls_l5=0;
	int int_pfoInvMass_os_s5=0;
	int int_pfoInvMass_ls_s5=0;
	for (int i=0; i<nEntries_l5; ++i)
	{
		tree_l5->GetEntry(i);
		if (((mcp_PDG1==13 && mcp_PDG2==-13)||(mcp_PDG1==-13 && mcp_PDG2==13))&&(mcpInvMass<=3.05||mcpInvMass>=3.15))
			int_mcpInvMass_os++;
		if (((mcp_PDG1==13 && mcp_PDG2==13)||(mcp_PDG1==-13 && mcp_PDG2==-13))&&(mcpInvMass<=3.05||mcpInvMass>=3.15))
			int_mcpInvMass_ls++;
		if (((pfo_PDG1_l5==13 && pfo_PDG2_l5==-13)||(pfo_PDG1_l5==-13 && pfo_PDG2_l5==13))&&(pfoInvMass_l5<=3.05||pfoInvMass_l5>=3.15))
			int_pfoInvMass_os_l5++;
		if (((pfo_PDG1_l5==13 && pfo_PDG2_l5==13)||(pfo_PDG1_l5==-13 && pfo_PDG2_l5==-13))&&(pfoInvMass_l5<=3.05||pfoInvMass_l5>=3.15))
			int_pfoInvMass_ls_l5++;
	}
	for (int i=0; i<nEntries_s5; ++i)
	{
		tree_s5->GetEntry(i);
		if (((pfo_PDG1_s5==13 && pfo_PDG2_s5==-13)||(pfo_PDG1_s5==-13 && pfo_PDG2_s5==13))&&(pfoInvMass_s5<=3.05||pfoInvMass_s5>=3.15))
			int_pfoInvMass_os_s5++;
		if (((pfo_PDG1_s5==13 && pfo_PDG2_s5==13)||(pfo_PDG1_s5==-13 && pfo_PDG2_s5==-13))&&(pfoInvMass_s5<=3.05||pfoInvMass_s5>=3.15))
			int_pfoInvMass_ls_s5++;
	}

	for (int i=0; i<nEntries_l5; ++i)
	{
		tree_l5->GetEntry(i);

		if (mcp_PDG1*mcp_PDG2<0)
		{
			h_mcpInvMass_os->Fill(mcpInvMass,weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);
			if (mcpInvMass<=3.15 && mcpInvMass>=3.05)
			{
				h_mcpCosTheta_os->Fill(mcpCosTheta,weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);
				h_mcpCosTheta_norm->Fill(mcpCosTheta,weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);
				h_mcpPt_os->Fill(mcpPt,weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);
			}
			h_mcpInvMass_norm->Fill(mcpInvMass,weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);
			if(mcp_PDG1==13)
			{
				h_mcpCosThetaMuon_os->Fill(mcpCosTheta1,weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);
				h_mcpCosThetaAntimuon_os->Fill(mcpCosTheta2,weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);
			}
			if(mcp_PDG1==-13)
			{
				h_mcpCosThetaAntimuon_os->Fill(mcpCosTheta1,weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);
				h_mcpCosThetaMuon_os->Fill(mcpCosTheta2,weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);
			}
		}
		if (mcp_PDG1*mcp_PDG2>0)
		{
			h_mcpInvMass_ls->Fill(mcpInvMass,weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);
			if (mcpInvMass<=3.15 && mcpInvMass>=3.05)
			{
				h_mcpCosTheta_ls->Fill(mcpCosTheta,weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);
				h_mcpCosTheta_norm->Fill(mcpCosTheta,-weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);
				h_mcpPt_ls->Fill(mcpPt,weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);
			}
			h_mcpInvMass_norm->Fill(mcpInvMass,-int_mcpInvMass_os*weight_l5[((2*ePol_l5+pPol_l5)+3)/2]/int_mcpInvMass_ls);
			if(mcp_PDG1==13)
			{
				h_mcpCosThetaMuon_ls->Fill(mcpCosTheta1,weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);
				h_mcpCosThetaMuon_ls->Fill(mcpCosTheta2,weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);

			}
			if(mcp_PDG1==-13)
			{
				h_mcpCosThetaAntimuon_ls->Fill(mcpCosTheta1,weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);
				h_mcpCosThetaAntimuon_ls->Fill(mcpCosTheta2,weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);
			}
		}


		if (pfo_PDG1_l5*pfo_PDG2_l5<0)
		{
			h_pfoInvMass_os_l5->Fill(pfoInvMass_l5,weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);
			if (pfoInvMass_l5<=3.15 && pfoInvMass_l5>=3.05)
			{
				h_pfoCosTheta_os_l5->Fill(pfoCosTheta_l5,weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);
				h_pfoCosTheta_norm_l5->Fill(pfoCosTheta_l5,weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);
				h_pfoPt_os_l5->Fill(pfoPt_l5,weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);
			}
			h_pfoInvMass_norm_l5->Fill(pfoInvMass_l5,weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);
			if(pfo_PDG1_l5==13)
			{
				h_pfoCosThetaMuon_os_l5->Fill(pfoCosTheta1_l5,weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);
				h_pfoCosThetaAntimuon_os_l5->Fill(pfoCosTheta2_l5,weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);
			}
			if(pfo_PDG1_l5==-13)
			{
				h_pfoCosThetaAntimuon_os_l5->Fill(pfoCosTheta1_l5,weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);
				h_pfoCosThetaMuon_os_l5->Fill(pfoCosTheta2_l5,weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);
			}
		}
		if (pfo_PDG1_l5*pfo_PDG2_l5>0)
		{
			h_pfoInvMass_ls_l5->Fill(pfoInvMass_l5,weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);
			if (pfoInvMass_l5<=3.15 && pfoInvMass_l5>=3.05)
			{
				h_pfoCosTheta_ls_l5->Fill(pfoCosTheta_l5,weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);
				h_pfoCosTheta_norm_l5->Fill(pfoCosTheta_l5,-weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);
				h_pfoPt_ls_l5->Fill(pfoPt_l5,weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);
			}
			h_pfoInvMass_norm_l5->Fill(pfoInvMass_l5,-int_pfoInvMass_os_l5*weight_l5[((2*ePol_l5+pPol_l5)+3)/2]/int_pfoInvMass_ls_l5);
			if(pfo_PDG1_l5==13)
			{
				h_pfoCosThetaMuon_ls_l5->Fill(pfoCosTheta1_l5,weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);
				h_pfoCosThetaMuon_ls_l5->Fill(pfoCosTheta2_l5,weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);

			}
			if(pfo_PDG1_l5==-13)
			{
				h_pfoCosThetaAntimuon_ls_l5->Fill(pfoCosTheta1_l5,weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);
				h_pfoCosThetaAntimuon_ls_l5->Fill(pfoCosTheta2_l5,weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);
			}
		}
	}

	for (int i=0; i<nEntries_s5; ++i)
	{
		tree_s5->GetEntry(i);

		if ((pfo_PDG1_s5==13 && pfo_PDG2_s5==-13)||(pfo_PDG1_s5==-13 && pfo_PDG2_s5==13))
		{
			h_pfoInvMass_os_s5->Fill(pfoInvMass_s5,weight_s5[((2*ePol_s5+pPol_s5)+3)/2]);

			if (pfoInvMass_s5<=3.15 && pfoInvMass_s5>=3.05)
			{
				h_pfoCosTheta_os_s5->Fill(pfoCosTheta_s5,weight_s5[((2*ePol_s5+pPol_s5)+3)/2]);
				h_pfoCosTheta_norm_s5->Fill(pfoCosTheta_s5,weight_s5[((2*ePol_s5+pPol_s5)+3)/2]);
				h_pfoPt_os_s5->Fill(pfoPt_s5,weight_s5[((2*ePol_s5+pPol_s5)+3)/2]);
			}
			h_pfoInvMass_norm_s5->Fill(pfoInvMass_s5,weight_s5[((2*ePol_s5+pPol_s5)+3)/2]);
			if(pfo_PDG1_s5==13)
			{
				h_pfoCosThetaMuon_os_s5->Fill(pfoCosTheta1_s5,weight_s5[((2*ePol_s5+pPol_s5)+3)/2]);
				h_pfoCosThetaAntimuon_os_s5->Fill(pfoCosTheta2_s5,weight_s5[((2*ePol_s5+pPol_s5)+3)/2]);
			}
			if(pfo_PDG2_s5==13)
			{
				h_pfoCosThetaAntimuon_os_s5->Fill(pfoCosTheta1_s5,weight_s5[((2*ePol_s5+pPol_s5)+3)/2]);
				h_pfoCosThetaMuon_os_s5->Fill(pfoCosTheta2_s5,weight_s5[((2*ePol_s5+pPol_s5)+3)/2]);
			}
		}
		if ((pfo_PDG1_s5==13 && pfo_PDG2_s5==13)||(pfo_PDG1_s5==-13 && pfo_PDG2_s5==-13))
		{
			h_pfoInvMass_ls_s5->Fill(pfoInvMass_s5,weight_s5[((2*ePol_s5+pPol_s5)+3)/2]);
			if (pfoInvMass_s5<=3.15 && pfoInvMass_s5>=3.05)
			{
				h_pfoCosTheta_ls_s5->Fill(pfoCosTheta_s5,weight_s5[((2*ePol_s5+pPol_s5)+3)/2]);
				h_pfoCosTheta_norm_s5->Fill(pfoCosTheta_s5,-weight_s5[((2*ePol_s5+pPol_s5)+3)/2]);
				h_pfoPt_ls_s5->Fill(pfoPt_s5,weight_s5[((2*ePol_s5+pPol_s5)+3)/2]);
				h_pfoPt_ls_l5->Fill(pfoPt_l5,weight_l5[((2*ePol_l5+pPol_l5)+3)/2]);
			}
+			h_pfoInvMass_norm_s5->Fill(pfoInvMass_s5,-int_pfoInvMass_os_s5*weight_s5[((2*ePol_s5+pPol_s5)+3)/2]/int_pfoInvMass_ls_s5);
			if(pfo_PDG1_s5==13)
			{
				h_pfoCosThetaMuon_ls_s5->Fill(pfoCosTheta1_s5,weight_s5[((2*ePol_s5+pPol_s5)+3)/2]);
				h_pfoCosThetaMuon_ls_s5->Fill(pfoCosTheta2_s5,weight_s5[((2*ePol_s5+pPol_s5)+3)/2]);
			}
			if(pfo_PDG1_s5==-13)
			{
				h_pfoCosThetaAntimuon_ls_s5->Fill(pfoCosTheta1_s5,weight_s5[((2*ePol_s5+pPol_s5)+3)/2]);
				h_pfoCosThetaAntimuon_ls_s5->Fill(pfoCosTheta2_s5,weight_s5[((2*ePol_s5+pPol_s5)+3)/2]);
			}
		}

	}
}

//	//	//	MCP Invariant Mass
	TCanvas *can_mcpInvMass = new TCanvas("can_mcpInvMass","",800,800);
	h_mcpInvMass_os->Draw("hist");
	h_mcpInvMass_os -> GetXaxis() -> SetTitle("Inv m_{#mu#bar{#mu}} [GeV]");
	h_mcpInvMass_os -> GetYaxis() -> SetTitle("number of J/#psi candidates");
	h_mcpInvMass_os->GetXaxis()->SetTitleSize(0.06);
	h_mcpInvMass_os->GetYaxis()->SetTitleSize(0.06);
	h_mcpInvMass_os->GetYaxis()->SetLabelSize(0.035);
	h_mcpInvMass_os->GetYaxis()->SetTitleOffset(1.25);
	gPad->Update();
                can_mcpInvMass->Modified();
                can_mcpInvMass->Update();
 	TPaveStats *tps_mcpInvMass_os = (TPaveStats*)h_mcpInvMass_os->FindObject("stats");
                tps_mcpInvMass_os->SetX1NDC(0.75);
                tps_mcpInvMass_os->SetY1NDC(0.75);
                tps_mcpInvMass_os->SetX2NDC(0.9);
                tps_mcpInvMass_os->SetY2NDC(0.9);
	h_mcpInvMass_ls->SetLineColor(4);
	h_mcpInvMass_ls->Draw("hist,sames");
	gPad->Update();
                can_mcpInvMass->Modified();
                can_mcpInvMass->Update();
	TPaveStats *tps_mcpInvMass_ls = (TPaveStats*)h_mcpInvMass_ls->FindObject("stats");
                tps_mcpInvMass_ls->SetX1NDC(0.75);
                tps_mcpInvMass_ls->SetY1NDC(0.6);
                tps_mcpInvMass_ls->SetX2NDC(0.9);
                tps_mcpInvMass_ls->SetY2NDC(0.75);
	h_mcpInvMass_norm->SetLineColor(2);
	h_mcpInvMass_norm->Draw("hist,sames");
	gPad->Update();
                can_mcpInvMass->Modified();
                can_mcpInvMass->Update();
	TPaveStats *tps_mcpInvMass_norm = (TPaveStats*)h_mcpInvMass_norm->FindObject("stats");
                tps_mcpInvMass_norm->SetX1NDC(0.75);
                tps_mcpInvMass_norm->SetY1NDC(0.45);
                tps_mcpInvMass_norm->SetX2NDC(0.9);
                tps_mcpInvMass_norm->SetY2NDC(0.6);
	tps_mcpInvMass_os->Draw();
	tps_mcpInvMass_ls->Draw("same");
	tps_mcpInvMass_norm->Draw("same");
	TLegend *mcpInvMass_os = new TLegend(0.45, 0.6, 0.7, 0.8);
	mcpInvMass_os->SetHeader("MC","l");
	mcpInvMass_os->AddEntry(h_mcpInvMass_os,"#mu^{+}#mu^{-}","l");
	mcpInvMass_os->AddEntry(h_mcpInvMass_ls,"#mu^{+}#mu^{+}+#mu^{-}#mu^{-}","l");
	mcpInvMass_os->AddEntry(h_mcpInvMass_norm,"(#mu^{+}#mu^{-})-(#mu^{+}#mu^{+}+#mu^{-}#mu^{-})","l");
	mcpInvMass_os->Draw();

	can_mcpInvMass->SaveAs((plots_dir+"mcpInvMass.pdf").c_str());
	can_mcpInvMass->SaveAs((plots_dir+"mcpInvMass.eps").c_str());
	can_mcpInvMass->SaveAs((plots_dir+"mcpInvMass.C").c_str());

//	//	//	PFO-l5 Invariant Mass

	TCanvas *can_pfoInvMass = new TCanvas("can_pfoInvMass","",800,800);
	h_pfoInvMass_os_l5->Draw("hist");
	h_pfoInvMass_os_l5 -> GetXaxis() -> SetTitle("Inv m_{#mu#bar{#mu}} [GeV]");
	h_pfoInvMass_os_l5 -> GetYaxis() -> SetTitle("number of J/#psi candidates");
	h_pfoInvMass_os_l5->GetXaxis()->SetTitleSize(0.06);
	h_pfoInvMass_os_l5->GetYaxis()->SetTitleSize(0.06);
	h_pfoInvMass_os_l5->GetYaxis()->SetLabelSize(0.035);
	h_pfoInvMass_os_l5->GetYaxis()->SetTitleOffset(1.25);
	gPad->Update();
                can_pfoInvMass->Modified();
                can_pfoInvMass->Update();
 	TPaveStats *tps_pfoInvMass_os_l5 = (TPaveStats*)h_pfoInvMass_os_l5->FindObject("stats");
                tps_pfoInvMass_os_l5->SetX1NDC(0.75);
                tps_pfoInvMass_os_l5->SetY1NDC(0.75);
                tps_pfoInvMass_os_l5->SetX2NDC(0.9);
                tps_pfoInvMass_os_l5->SetY2NDC(0.9);
	h_pfoInvMass_ls_l5->Draw("hist,sames");
	h_pfoInvMass_ls_l5->SetLineColor(4);
	gPad->Update();
                can_pfoInvMass->Modified();
                can_pfoInvMass->Update();
 	TPaveStats *tps_pfoInvMass_ls_l5 = (TPaveStats*)h_pfoInvMass_ls_l5->FindObject("stats");
                tps_pfoInvMass_ls_l5->SetX1NDC(0.75);
                tps_pfoInvMass_ls_l5->SetY1NDC(0.6);
                tps_pfoInvMass_ls_l5->SetX2NDC(0.9);
                tps_pfoInvMass_ls_l5->SetY2NDC(0.75);
	h_pfoInvMass_norm_l5->SetLineColor(2);
	h_pfoInvMass_norm_l5->Draw("hist,sames");
	gPad->Update();
                can_pfoInvMass->Modified();
                can_pfoInvMass->Update();
 	TPaveStats *tps_pfoInvMass_norm_l5 = (TPaveStats*)h_pfoInvMass_norm_l5->FindObject("stats");
                tps_pfoInvMass_norm_l5->SetX1NDC(0.75);
                tps_pfoInvMass_norm_l5->SetY1NDC(0.45);
                tps_pfoInvMass_norm_l5->SetX2NDC(0.9);
                tps_pfoInvMass_norm_l5->SetY2NDC(0.6);
	TLegend *pfoInvMass_norm_l5 = new TLegend(0.45, 0.6, 0.7, 0.8);
	pfoInvMass_norm_l5->SetHeader("ILD_l5","l");
	pfoInvMass_norm_l5->AddEntry(h_mcpInvMass_os,"#mu^{+}#mu^{-}","l");
	pfoInvMass_norm_l5->AddEntry(h_mcpInvMass_ls,"#mu^{+}#mu^{+}+#mu^{-}#mu^{-}","l");
	pfoInvMass_norm_l5->AddEntry(h_mcpInvMass_norm,"(#mu^{+}#mu^{-})-(#mu^{+}#mu^{+}+#mu^{-}#mu^{-})","l");
	pfoInvMass_norm_l5->Draw();
	can_pfoInvMass->SaveAs((plots_dir+"pfoInvMass_l5.pdf").c_str());
	can_pfoInvMass->SaveAs((plots_dir+"pfoInvMass_l5.eps").c_str());
	can_pfoInvMass->SaveAs((plots_dir+"pfoInvMass_l5.C").c_str());

//	//	//	PFO-s5 Invariant Mass

	TCanvas *can_pfoInvMass_s5 = new TCanvas("can_pfoInvMass_s5","",800,800);
	h_pfoInvMass_os_s5->Draw("hist");
	h_pfoInvMass_os_s5 -> GetXaxis() -> SetTitle("Inv m_{#mu#bar{#mu}} [GeV]");
	h_pfoInvMass_os_s5 -> GetYaxis() -> SetTitle("number of J/#psi candidates");
	h_pfoInvMass_os_s5->GetXaxis()->SetTitleSize(0.06);
	h_pfoInvMass_os_s5->GetYaxis()->SetTitleSize(0.06);
	h_pfoInvMass_os_s5->GetYaxis()->SetLabelSize(0.035);
	h_pfoInvMass_os_s5->GetYaxis()->SetTitleOffset(1.25);
	gPad->Update();
                can_pfoInvMass_s5->Modified();
                can_pfoInvMass_s5->Update();
 	TPaveStats *tps_pfoInvMass_os_s5 = (TPaveStats*)h_pfoInvMass_os_s5->FindObject("stats");
                tps_pfoInvMass_os_s5->SetX1NDC(0.75);
                tps_pfoInvMass_os_s5->SetY1NDC(0.75);
                tps_pfoInvMass_os_s5->SetX2NDC(0.9);
                tps_pfoInvMass_os_s5->SetY2NDC(0.9);
	h_pfoInvMass_ls_s5->Draw("hist,sames");
	h_pfoInvMass_ls_s5->SetLineColor(4);
	gPad->Update();
                can_pfoInvMass_s5->Modified();
                can_pfoInvMass_s5->Update();
 	TPaveStats *tps_pfoInvMass_ls_s5 = (TPaveStats*)h_pfoInvMass_ls_s5->FindObject("stats");
                tps_pfoInvMass_ls_s5->SetX1NDC(0.75);
                tps_pfoInvMass_ls_s5->SetY1NDC(0.6);
                tps_pfoInvMass_ls_s5->SetX2NDC(0.9);
                tps_pfoInvMass_ls_s5->SetY2NDC(0.75);
	h_pfoInvMass_norm_s5->SetLineColor(2);
	h_pfoInvMass_norm_s5->Draw("hist,sames");
	gPad->Update();
                can_pfoInvMass_s5->Modified();
                can_pfoInvMass_s5->Update();
 	TPaveStats *tps_pfoInvMass_norm_s5 = (TPaveStats*)h_pfoInvMass_norm_s5->FindObject("stats");
                tps_pfoInvMass_norm_s5->SetX1NDC(0.75);
                tps_pfoInvMass_norm_s5->SetY1NDC(0.45);
                tps_pfoInvMass_norm_s5->SetX2NDC(0.9);
                tps_pfoInvMass_norm_s5->SetY2NDC(0.6);
	TLegend *pfoInvMass_os_s5 = new TLegend(0.45, 0.6, 0.7, 0.8);
	pfoInvMass_os_s5->SetHeader("ILD_s5","l");
	pfoInvMass_os_s5->AddEntry(h_mcpInvMass_os,"#mu^{+}#mu^{-}","l");
	pfoInvMass_os_s5->AddEntry(h_mcpInvMass_ls,"#mu^{+}#mu^{+}+#mu^{-}#mu^{-}","l");
	pfoInvMass_os_s5->AddEntry(h_mcpInvMass_norm,"(#mu^{+}#mu^{-})-(#mu^{+}#mu^{+}+#mu^{-}#mu^{-})","l");
	pfoInvMass_os_s5->Draw();
	can_pfoInvMass_s5->SaveAs((plots_dir+"pfoInvMass_s5.pdf").c_str());
	can_pfoInvMass_s5->SaveAs((plots_dir+"pfoInvMass_s5.eps").c_str());
	can_pfoInvMass_s5->SaveAs((plots_dir+"pfoInvMass_s5.C").c_str());

//	//	//	MCP CosTheta
	TCanvas *can_mcpCosTheta = new TCanvas("can_mcpCosTheta","",800,800);
	h_mcpCosTheta_os->Draw("hist");
	h_mcpCosTheta_os -> GetXaxis() -> SetTitle("cos #theta_{#mu#bar{#mu}}");
	h_mcpCosTheta_os -> GetYaxis() -> SetTitle("number of J/#psi candidates");
	h_mcpCosTheta_os->GetXaxis()->SetTitleSize(0.06);
	h_mcpCosTheta_os->GetYaxis()->SetTitleSize(0.06);
	h_mcpCosTheta_os->GetYaxis()->SetLabelSize(0.035);
	h_mcpCosTheta_os->GetYaxis()->SetTitleOffset(1.25);
	gPad->Update();
                can_mcpCosTheta->Modified();
                can_mcpCosTheta->Update();
 	TPaveStats *tps_mcpCosTheta_os = (TPaveStats*)h_mcpCosTheta_os->FindObject("stats");
                tps_mcpCosTheta_os->SetX1NDC(0.75);
                tps_mcpCosTheta_os->SetY1NDC(0.75);
                tps_mcpCosTheta_os->SetX2NDC(0.9);
                tps_mcpCosTheta_os->SetY2NDC(0.9);
	h_mcpCosTheta_ls->SetLineColor(4);
	h_mcpCosTheta_ls->Draw("hist,sames");
	gPad->Update();
                can_mcpCosTheta->Modified();
                can_mcpCosTheta->Update();
	TPaveStats *tps_mcpCosTheta_ls = (TPaveStats*)h_mcpCosTheta_ls->FindObject("stats");
                tps_mcpCosTheta_ls->SetX1NDC(0.75);
                tps_mcpCosTheta_ls->SetY1NDC(0.6);
                tps_mcpCosTheta_ls->SetX2NDC(0.9);
                tps_mcpCosTheta_ls->SetY2NDC(0.75);
	h_mcpCosTheta_norm->SetLineColor(2);
	h_mcpCosTheta_norm->Draw("hist,sames");
	gPad->Update();
                can_mcpCosTheta->Modified();
                can_mcpCosTheta->Update();
	TPaveStats *tps_mcpCosTheta_norm = (TPaveStats*)h_mcpCosTheta_norm->FindObject("stats");
                tps_mcpCosTheta_norm->SetX1NDC(0.75);
                tps_mcpCosTheta_norm->SetY1NDC(0.45);
                tps_mcpCosTheta_norm->SetX2NDC(0.9);
                tps_mcpCosTheta_norm->SetY2NDC(0.6);
	tps_mcpCosTheta_os->Draw();
	tps_mcpCosTheta_ls->Draw("same");
	tps_mcpCosTheta_norm->Draw("same");
	TLegend *mcpCosTheta_os = new TLegend(0.45, 0.6, 0.7, 0.8);
	mcpCosTheta_os->SetHeader("MC","l");
	mcpCosTheta_os->AddEntry(h_mcpCosTheta_os,"#mu^{+}#mu^{-}","l");
	mcpCosTheta_os->AddEntry(h_mcpCosTheta_ls,"#mu^{+}#mu^{+}+#mu^{-}#mu^{-}","l");
	mcpCosTheta_os->AddEntry(h_mcpCosTheta_norm,"(#mu^{+}#mu^{-})-(#mu^{+}#mu^{+}+#mu^{-}#mu^{-})","l");
	mcpCosTheta_os->Draw();
	can_mcpCosTheta->SaveAs((plots_dir+"mcpCosTheta.pdf").c_str());
	can_mcpCosTheta->SaveAs((plots_dir+"mcpCosTheta.eps").c_str());
	can_mcpCosTheta->SaveAs((plots_dir+"mcpCosTheta.C").c_str());

//	//	//	PFO-l5 CosTheta
	TCanvas *can_pfoCosTheta_l5 = new TCanvas("can_pfoCosTheta_l5","",800,800);
	h_pfoCosTheta_os_l5->Draw("hist");
	h_pfoCosTheta_os_l5 -> GetXaxis() -> SetTitle("cos #theta_{#mu#bar{#mu}}");
	h_pfoCosTheta_os_l5 -> GetYaxis() -> SetTitle("number of J/#psi candidates");
	h_pfoCosTheta_os_l5->GetXaxis()->SetTitleSize(0.06);
	h_pfoCosTheta_os_l5->GetYaxis()->SetTitleSize(0.06);
	h_pfoCosTheta_os_l5->GetYaxis()->SetLabelSize(0.035);
	h_pfoCosTheta_os_l5->GetYaxis()->SetTitleOffset(1.25);
	gPad->Update();
                can_pfoCosTheta_l5->Modified();
                can_pfoCosTheta_l5->Update();
	TPaveStats *tps_pfoCosTheta_os_l5 = (TPaveStats*)h_pfoCosTheta_os_l5->FindObject("stats");
                tps_pfoCosTheta_os_l5->SetX1NDC(0.75);
                tps_pfoCosTheta_os_l5->SetY1NDC(0.75);
                tps_pfoCosTheta_os_l5->SetX2NDC(0.9);
                tps_pfoCosTheta_os_l5->SetY2NDC(0.9);
	h_pfoCosTheta_ls_l5->SetLineColor(4);
	h_pfoCosTheta_ls_l5->Draw("hist,sames");
	gPad->Update();
                can_pfoCosTheta_l5->Modified();
                can_pfoCosTheta_l5->Update();
	TPaveStats *tps_pfoCosTheta_ls_l5 = (TPaveStats*)h_pfoCosTheta_ls_l5->FindObject("stats");
                tps_pfoCosTheta_ls_l5->SetX1NDC(0.75);
                tps_pfoCosTheta_ls_l5->SetY1NDC(0.6);
                tps_pfoCosTheta_ls_l5->SetX2NDC(0.9);
                tps_pfoCosTheta_ls_l5->SetY2NDC(0.75);
	h_pfoCosTheta_norm_l5->SetLineColor(2);
	h_pfoCosTheta_norm_l5->Draw("hist,sames");
	gPad->Update();
                can_pfoCosTheta_l5->Modified();
                can_pfoCosTheta_l5->Update();
	TPaveStats *tps_pfoCosTheta_norm_l5 = (TPaveStats*)h_pfoCosTheta_norm_l5->FindObject("stats");
                tps_pfoCosTheta_norm_l5->SetX1NDC(0.75);
                tps_pfoCosTheta_norm_l5->SetY1NDC(0.45);
                tps_pfoCosTheta_norm_l5->SetX2NDC(0.9);
                tps_pfoCosTheta_norm_l5->SetY2NDC(0.6);
	TLegend *pfoCosTheta_os_l5 = new TLegend(0.45, 0.6, 0.7, 0.8);
	pfoCosTheta_os_l5->SetHeader("ILD_l5","l");
	pfoCosTheta_os_l5->AddEntry(h_pfoCosTheta_os_l5,"#mu^{+}#mu^{-}","l");
	pfoCosTheta_os_l5->AddEntry(h_pfoCosTheta_ls_l5,"#mu^{+}#mu^{+}+#mu^{-}#mu^{-}","l");
	pfoCosTheta_os_l5->AddEntry(h_pfoCosTheta_norm_l5,"(#mu^{+}#mu^{-})-(#mu^{+}#mu^{+}+#mu^{-}#mu^{-})","l");
	pfoCosTheta_os_l5->Draw();
	can_pfoCosTheta_l5->SaveAs((plots_dir+"pfoCosTheta_l5.pdf").c_str());
	can_pfoCosTheta_l5->SaveAs((plots_dir+"pfoCosTheta_l5.eps").c_str());
	can_pfoCosTheta_l5->SaveAs((plots_dir+"pfoCosTheta_l5.C").c_str());

//	//	//	PFO-s5 CosTheta
	TCanvas *can_pfoCosTheta_s5 = new TCanvas("can_pfoCosTheta_s5","",800,800);
	h_pfoCosTheta_os_s5->Draw("hist");
	h_pfoCosTheta_os_s5 -> GetXaxis() -> SetTitle("cos #theta_{#mu#bar{#mu}}");
	h_pfoCosTheta_os_s5 -> GetYaxis() -> SetTitle("number of J/#psi candidates");
	h_pfoCosTheta_os_s5->GetXaxis()->SetTitleSize(0.06);
	h_pfoCosTheta_os_s5->GetYaxis()->SetTitleSize(0.06);
	h_pfoCosTheta_os_s5->GetYaxis()->SetLabelSize(0.035);
	h_pfoCosTheta_os_s5->GetYaxis()->SetTitleOffset(1.25);
	gPad->Update();
                can_pfoCosTheta_s5->Modified();
                can_pfoCosTheta_s5->Update();
	TPaveStats *tps_pfoCosTheta_os_s5 = (TPaveStats*)h_pfoCosTheta_os_s5->FindObject("stats");
                tps_pfoCosTheta_os_s5->SetX1NDC(0.65);
                tps_pfoCosTheta_os_s5->SetY1NDC(0.75);
                tps_pfoCosTheta_os_s5->SetX2NDC(0.8);
                tps_pfoCosTheta_os_s5->SetY2NDC(0.9);
	h_pfoCosTheta_ls_s5->SetLineColor(4);
	h_pfoCosTheta_ls_s5->Draw("hist,sames");
	gPad->Update();
                can_pfoCosTheta_s5->Modified();
                can_pfoCosTheta_s5->Update();
	TPaveStats *tps_pfoCosTheta_ls_s5 = (TPaveStats*)h_pfoCosTheta_ls_s5->FindObject("stats");
                tps_pfoCosTheta_ls_s5->SetX1NDC(0.65);
                tps_pfoCosTheta_ls_s5->SetY1NDC(0.6);
                tps_pfoCosTheta_ls_s5->SetX2NDC(0.8);
                tps_pfoCosTheta_ls_s5->SetY2NDC(0.75);
	h_pfoCosTheta_norm_s5->SetLineColor(2);
	h_pfoCosTheta_norm_s5->Draw("hist,sames");
	gPad->Update();
                can_pfoCosTheta_s5->Modified();
                can_pfoCosTheta_s5->Update();
	TPaveStats *tps_pfoCosTheta_norm_s5 = (TPaveStats*)h_pfoCosTheta_norm_s5->FindObject("stats");
                tps_pfoCosTheta_norm_s5->SetX1NDC(0.65);
                tps_pfoCosTheta_norm_s5->SetY1NDC(0.45);
                tps_pfoCosTheta_norm_s5->SetX2NDC(0.8);
                tps_pfoCosTheta_norm_s5->SetY2NDC(0.6);
	TLegend *pfoCosTheta_os = new TLegend(0.25, 0.6, 0.5, 0.8);
	pfoCosTheta_os->SetHeader("ILD_s5","l");
	pfoCosTheta_os->AddEntry(h_pfoCosTheta_os_s5,"#mu^{+}#mu^{-}","l");
	pfoCosTheta_os->AddEntry(h_pfoCosTheta_ls_s5,"#mu^{+}#mu^{+}+#mu^{-}#mu^{-}","l");
	pfoCosTheta_os->AddEntry(h_pfoCosTheta_norm_s5,"(#mu^{+}#mu^{-})-(#mu^{+}#mu^{+}+#mu^{-}#mu^{-})","l");
	pfoCosTheta_os->Draw();
	can_pfoCosTheta_s5->SaveAs((plots_dir+"pfoCosTheta_s5.pdf").c_str());
	can_pfoCosTheta_s5->SaveAs((plots_dir+"pfoCosTheta_s5.eps").c_str());
	can_pfoCosTheta_s5->SaveAs((plots_dir+"pfoCosTheta_s5.C").c_str());
//       //      //    l5_vs_s5 cos theta
ildStyle->SetOptStat(0);
ildStyle->SetOptFit(0);
	TCanvas *can_pfoCos_l5_vs_s5 = new TCanvas("can_pfoCos_l5_vs_s5","",800,800);
	h_pfoCosTheta_norm_l5->Draw("hist");
	h_pfoCosTheta_norm_l5 -> GetXaxis() -> SetTitle("cos #theta_{#mu#bar{#mu}}");
	h_pfoCosTheta_norm_l5 -> GetYaxis() -> SetTitle("number of J/#psi candidates");
	h_pfoCosTheta_norm_l5->SetLineColor(4);
	h_pfoCosTheta_norm_l5->SetLineWidth(1);
	h_pfoCosTheta_norm_s5->SetLineColor(2);
	h_pfoCosTheta_norm_s5->SetLineWidth(1);
	h_pfoCosTheta_norm_s5->Draw("hist,sames");
	TLegend *pfoCos_l5_vs_s5 = new TLegend(0.55,0.6,0.90,0.745);
	pfoCos_l5_vs_s5->SetHeader("500Gev, 4ab^{-1},e^{-}e^{+}#rightarrowq#bar{q}","C"); // option "C" allows to center the header
	pfoCos_l5_vs_s5->AddEntry(h_pfoCosTheta_norm_s5,"IDR-S","l");
	pfoCos_l5_vs_s5->AddEntry(h_pfoCosTheta_norm_l5,"IDR-L","l");
	pfoCos_l5_vs_s5->SetTextSize(0.02);
	pfoCos_l5_vs_s5->Draw();

	can_pfoCos_l5_vs_s5->SaveAs((plots_dir+"pfocos_l5_vs_s5.pdf").c_str());
	can_pfoCos_l5_vs_s5->SaveAs((plots_dir+"pfoCos_l5_vs_s5.eps").c_str());
	can_pfoCos_l5_vs_s5->SaveAs((plots_dir+"pfoCos_l5_vs_s5.C").c_str());

//       //      //    l5_vs_s5 PFoInvMass
ildStyle->SetOptStat(0);
ildStyle->SetOptFit(0);
	TCanvas *can_pfoInvMass_l5_vs_s5 = new TCanvas("can_pfoInvMass_l5_vs_s5","",800,800);
	h_pfoInvMass_norm_l5->Draw("hist");
	h_pfoInvMass_norm_l5 -> GetXaxis() -> SetTitle("m#mu^{+}#mu^{-} /GeV");
	h_pfoInvMass_norm_l5 -> GetYaxis() -> SetTitle("number of J/#psi candidates");

	h_pfoInvMass_norm_l5->GetXaxis()->SetTitleSize(0.06);
	h_pfoInvMass_norm_l5->GetXaxis()->SetLabelSize(0.035);
	h_pfoInvMass_norm_l5->GetXaxis()->SetTitleSize(0.06);
	h_pfoInvMass_norm_l5->GetYaxis()->SetTitleSize(0.06);
	h_pfoInvMass_norm_l5->GetYaxis()->SetLabelSize(0.035);
	h_pfoInvMass_norm_l5->GetYaxis()->SetTitleOffset(1.25);
	h_pfoInvMass_norm_l5->SetLineWidth(1);
	h_pfoInvMass_norm_l5->SetLineColor(4);
	//h_pfoInvMass_norm_s5->SetTextSize(0.02);
	h_pfoInvMass_norm_s5->SetLineColor(2);
	h_pfoInvMass_norm_s5->SetLineWidth(1);

	h_pfoInvMass_norm_s5->Draw("hist,sames");

//	h_pfoInvMass_norm_s5->GetYaxis()->SetRangeUser(0., 3000.);
//	h_pfoInvMass_norm_l5->GetYaxis()->SetRangeUser(0., 3000.);

	TLegend *pfoInvMass_l5_vs_s5 = new TLegend(0.55,0.6,0.90,0.745);
	pfoInvMass_l5_vs_s5->SetHeader("500Gev, 4ab^{-1}","l"); // option "C" allows to center the header
	pfoInvMass_l5_vs_s5->AddEntry(h_pfoInvMass_norm_s5,"IDR-S","l");
	pfoInvMass_l5_vs_s5->AddEntry(h_pfoInvMass_norm_l5,"IDR-L","l");

	pfoInvMass_l5_vs_s5->Draw();
	h_pfoInvMass_norm_s5->SetLineStyle(7);
	TLatex* text_logo = add_ILD_mark( can_pfoInvMass_l5_vs_s5, 3.2,  2500, 0.05);
		TLatex* text_prelim = add_prelim_mark( can_pfoInvMass_l5_vs_s5, 3.3,  2500, 0.05);
	cout << "******************************************   ILD_s5  ******************************************" << endl;
	float N_candidates_s5 = h_pfoInvMass_norm_s5->Integral(18,25);
	cout << "N_candidates_s5 = " << N_candidates_s5 << endl;
	cout << "******************************************   ILD_l5  ******************************************" << endl;
	float N_candidates_l5 = h_pfoInvMass_norm_l5->Integral(18,25);
	cout << "N_candidates_l5 = " << N_candidates_l5 << endl;
	can_pfoInvMass_l5_vs_s5->SaveAs((plots_dir+"pfoInvMass_l5_vs_s5.pdf").c_str());
	can_pfoInvMass_l5_vs_s5->SaveAs((plots_dir+"pfoInvMass_l5_vs_s5.eps").c_str());
	can_pfoInvMass_l5_vs_s5->SaveAs((plots_dir+"pfoInvMass_l5_vs_s5.C").c_str());
/*
//	//	//	l5_vs_s5_fit PFO InvMass

ildStyle->SetOptStat(0);
ildStyle->SetOptFit(1111);
	TCanvas *pfoInvMass_l5_vs_s5_fit = new TCanvas("pfoInvMass_l5_vs_s5_fit","",800,800);
	TF1 *myfit_s = new TF1("myfit_s","[0]*exp(-0.5*((x-[1])/[2])^2) + [3]",2.8,3.8);
	myfit_s->SetParameter(0,10000);
	myfit_s->SetParameter(1,3.1);
	myfit_s->SetParameter(2,0.015);
	myfit_s->SetParameter(3,0);
	myfit_s->SetLineColor(2);
	TF1 *myfit_l = new TF1("myfit_l","[0]*exp(-0.5*((x-[1])/[2])^2) + [3]",2.8,3.8);
	myfit_l->SetParameter(0,10000);
	myfit_l->SetParameter(1,3.1);
	myfit_l->SetParameter(2,0.01);
	myfit_l->SetParameter(3,0);
	myfit_l->SetLineColor(4);
	h_pfoInvMass_norm_l5->Draw("hist");
	h_pfoInvMass_norm_l5->SetLineColor(4);
	h_pfoInvMass_norm_l5->SetLineWidth(1);
	h_pfoInvMass_norm_l5->SetLineStyle(3);
	h_pfoInvMass_norm_s5->SetLineColor(2);
	h_pfoInvMass_norm_s5->SetLineWidth(1);
	h_pfoInvMass_norm_s5->SetLineStyle(7);
	h_pfoInvMass_norm_s5->Draw("hist,sames");
	myfit_s->Draw("same");
	h_pfoInvMass_norm_s5->Fit(myfit_s, "R");
	myfit_l->Draw("same");
	h_pfoInvMass_norm_l5->Fit(myfit_l,"R");
	gPad->Update();
	TPaveStats *txt_fit_s5 = (TPaveStats*)h_pfoInvMass_norm_s5->FindObject("stats");
                txt_fit_s5->SetX1NDC(0.75);
                txt_fit_s5->SetY1NDC(0.75);
                txt_fit_s5->SetX2NDC(0.9);
                txt_fit_s5->SetY2NDC(0.9);
                txt_fit_s5->SetTextColor(2);
	TPaveStats *txt_fit_l5 = (TPaveStats*)h_pfoInvMass_norm_l5->FindObject("stats");
                txt_fit_l5->SetX1NDC(0.75);
                txt_fit_l5->SetY1NDC(0.6);
                txt_fit_l5->SetX2NDC(0.9);
                txt_fit_l5->SetY2NDC(0.75);
                txt_fit_l5->SetTextColor(4);

	h_pfoInvMass_norm_s5->GetYaxis()->SetRangeUser(0., 3000.);
	h_pfoInvMass_norm_l5->GetYaxis()->SetRangeUser(0., 3000.);
	TLegend *pfoInvMass_vs_fit = new TLegend(0.45, 0.6, 0.7, 0.8);
	pfoInvMass_vs_fit->AddEntry(h_pfoInvMass_norm_s5,"ILD_s5","l");
	pfoInvMass_vs_fit->AddEntry(h_pfoInvMass_norm_l5,"ILD_l5","l");

	pfoInvMass_l5_vs_s5_fit->SaveAs((plots_dir+"pfoInvMass_l5_vs_s5_fit.pdf").c_str());
	pfoInvMass_l5_vs_s5_fit->SaveAs((plots_dir+"pfoInvMass_l5_vs_s5_fit.eps").c_str());
	pfoInvMass_l5_vs_s5_fit->SaveAs((plots_dir+"pfoInvMass_l5_vs_s5_fit.C").c_str());

*/
}

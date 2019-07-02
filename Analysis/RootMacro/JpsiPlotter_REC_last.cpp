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
void JpsiPlotter_REC_last()
{
	gStyle->SetOptStat(0);
	string file_path_mcp = "/nfs/dust/ilc/user/hosseins/DiMuMass/root_files/ILD_l5_o1_v02/merged_root_files/";
	string file_path_l5 = "/nfs/dust/ilc/user/hosseins/DiMuMass/root_files/ILD_l5_o1_v02/merged_root_files/";
	string file_path_s5 = "/nfs/dust/ilc/user/hosseins/DiMuMass/root_files/ILD_s5_o1_v02/merged_root_files/";
	string plots_dir = "/afs/desy.de/group/flc/pool/hosseins/DiMuonMass/Analysis/Plots/";
	std::string input_tree_name = "DiMuonMass";

	std::vector<std::string> physical_process;
	physical_process.push_back("2f_Z_hadronic");
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


	int nbins_InvMass = 100;
	int nbins_CosTheta = 50;
	int nbins_Pt = 50 ;
	int n_binning_pt = 13;
	double binning_pt[14] = {0,10,12,14,16,18,20,22,24,26,28,30,100,250};

	TH1F *hist_InvMassMCP_os = new TH1F("hist_InvMassMCP_os",";m_{#mu^{+}#mu^{-}};No.of J/#psi candidates",nbins_InvMass,2.8,3.8);
	hist_InvMassMCP_os->SetLineWidth(1); hist_InvMassMCP_os->SetLineColor(4);
	hist_InvMassMCP_os->GetYaxis()->SetLabelSize(0.035);

	TH1F *hist_CosThetaMCP_os = new TH1F("hist_CosThetaMCP_os"," ;cos#theta ;No.of J/#psi candidates",nbins_CosTheta,-1.,1.);
	hist_CosThetaMCP_os->SetLineWidth(1); hist_CosThetaMCP_os->SetLineColor(4);
	hist_CosThetaMCP_os->GetYaxis()->SetLabelSize(0.04);

	TH1F *hist_PtMCP_os = new TH1F("hist_PtMCP_os",";p_{t} ;No.of J/#psi candidates",n_binning_pt,binning_pt);
	hist_PtMCP_os->SetLineWidth(1); hist_PtMCP_os->SetLineColor(4);
	hist_PtMCP_os->GetYaxis()->SetLabelSize(0.04);

	TH2F *hist_PtCosThetaMCP_os = new TH2F("hist_PtCosThetaMCP_os"," ;cos#theta ;p_{t} ",nbins_CosTheta,-1.,1.,n_binning_pt,binning_pt);
	hist_PtCosThetaMCP_os->SetLineWidth(1); hist_PtCosThetaMCP_os->SetLineColor(4);
	hist_PtCosThetaMCP_os->GetYaxis()->SetLabelSize(0.04);

	TH1F *hist_InvMassMCP_ls = new TH1F("hist_InvMassMCP_ls","",nbins_InvMass,2.8,3.8);
	hist_InvMassMCP_ls->SetLineWidth(1); hist_InvMassMCP_ls->SetLineColor(2);

	TH1F *hist_CosThetaMCP_ls = new TH1F("hist_CosThetaMCP_ls","cos#theta (3.096 < m_{cut} < 3.1)",nbins_CosTheta,-1.,1.);
	hist_CosThetaMCP_ls->SetLineWidth(1); hist_CosThetaMCP_ls->SetLineColor(2);

	TH1F *hist_PtMCP_ls = new TH1F("hist_PtMCP_ls","p_{t} (3.096 < m_{cut} < 3.1)",n_binning_pt,binning_pt);
	hist_PtMCP_ls->SetLineWidth(1); hist_PtMCP_ls->SetLineColor(2);

	TH2F *hist_PtCosThetaMCP_ls = new TH2F("hist_PtCosThetaMCP_ls"," ;cos#theta;p_{t} [GeV];cos#theta;p_{t} [GeV]",nbins_CosTheta,-1.,1.,n_binning_pt,binning_pt);
	hist_PtCosThetaMCP_ls->SetLineWidth(1); hist_PtCosThetaMCP_ls->SetLineColor(2);

	TH1F *hist_InvMassMCP_norm = new TH1F("hist_InvMassMCP_norm",";m_{#mu^{+}#mu^{-}} [GeV] ; No.of J/#psi candidates",nbins_InvMass,2.8,3.8);
	hist_InvMassMCP_norm->SetLineWidth(1); hist_InvMassMCP_norm->SetLineColor(1);
	hist_InvMassMCP_norm->GetYaxis()->SetLabelSize(0.035);

	TH1F *hist_CosThetaMCP_norm = new TH1F("hist_CosThetaMCP_norm"," ;cos#theta; No.of J/#psi candidates",nbins_CosTheta,-1.,1.);
	hist_CosThetaMCP_norm->SetLineWidth(1); hist_CosThetaMCP_norm->SetLineColor(1);
	hist_CosThetaMCP_norm->GetYaxis()->SetLabelSize(0.035);

	TH1F *hist_PtMCP_norm = new TH1F("hist_PtMCP_norm"," ;p_{t} [GeV];No.of J/#psi candidates",n_binning_pt,binning_pt);
	hist_PtMCP_norm->SetLineWidth(1); hist_PtMCP_norm->SetLineColor(1);
	hist_PtMCP_norm->GetYaxis()->SetLabelSize(0.035);

	TH2F *hist_PtCosThetaMCP_norm = new TH2F("hist_PtCosThetaMCP_norm"," ;cos#theta;p_{t} [GeV]",nbins_CosTheta,-1.,1.,n_binning_pt,binning_pt);//p_{t} - cos#theta (3.096 < m_{cut} < 3.1)
	hist_PtCosThetaMCP_norm->SetLineWidth(1); hist_PtCosThetaMCP_norm->SetLineColor(1);
	hist_PtCosThetaMCP_norm->GetYaxis()->SetLabelSize(0.05);

	TH1F *hist_InvMassL5_os = new TH1F("hist_InvMassL5_os"," ;m_{#mu^{+}#mu^{-}} [GeV];No.of J/#psi candidates",nbins_InvMass,2.8,3.8);
	hist_InvMassL5_os->SetLineWidth(1); hist_InvMassL5_os->SetLineColor(4);
	hist_InvMassL5_os->GetYaxis()->SetLabelSize(0.04);

	TH1F *hist_CosThetaL5_os = new TH1F("hist_CosThetaL5_os",";cos#theta ;No.of J/#psi candidates",nbins_CosTheta,-1.,1.);
	hist_CosThetaL5_os->SetLineWidth(1); hist_CosThetaL5_os->SetLineColor(4);
	hist_CosThetaL5_os->GetYaxis()->SetLabelSize(0.04);

	TH1F *hist_PtL5_os = new TH1F("hist_PtL5_os"," ;p_{t} [GeV];No.of J/#psi candidates",n_binning_pt,binning_pt);
	hist_PtL5_os->SetLineWidth(1); hist_PtL5_os->SetLineColor(4);
	hist_PtL5_os->GetYaxis()->SetLabelSize(0.04);

	TH2F *hist_PtCosThetaS5_os = new TH2F("hist_PtCosThetaS5_os"," ;cos#theta;p_{t} [GeV]",nbins_CosTheta,-1.,1.,n_binning_pt,binning_pt);
	hist_PtCosThetaS5_os->SetLineWidth(1); hist_PtCosThetaS5_os->SetLineColor(4);

	TH1F *hist_InvMassL5_ls = new TH1F("hist_InvMassL5_ls","",nbins_InvMass,2.8,3.8);
	hist_InvMassL5_ls->SetLineWidth(1); hist_InvMassL5_ls->SetLineColor(2);

	TH1F *hist_CosThetaL5_ls = new TH1F("hist_CosThetaL5_ls","cos#theta (3.05 < m_{cut} < 3.15)",nbins_CosTheta,-1.,1.);
	hist_CosThetaL5_ls->SetLineWidth(1); hist_CosThetaL5_ls->SetLineColor(2);

	TH1F *hist_PtL5_ls = new TH1F("hist_PtL5_ls",";p_{t};No.of J/#psi candidates",n_binning_pt,binning_pt);
	hist_PtL5_ls->SetLineWidth(1); hist_PtL5_ls->SetLineColor(2);

	TH2F *hist_PtCosThetaL5_ls = new TH2F("hist_PtCosThetaL5_ls",";cos#theta;p_{t} [GeV]",nbins_CosTheta,-1.,1.,n_binning_pt,binning_pt);
	hist_PtCosThetaL5_ls->SetLineWidth(1); hist_PtCosThetaL5_ls->SetLineColor(2);

	TH1F *hist_InvMassL5_norm = new TH1F("hist_InvMassL5_norm","",nbins_InvMass,2.8,3.8);
	hist_InvMassL5_norm->SetLineWidth(1); //hist_InvMassL5_norm->SetLineColor(1);

	TH1F *hist_CosThetaL5_norm = new TH1F("hist_CosThetaL5_norm",";cos#theta;No.of J/#psi candidates",nbins_CosTheta,-1.,1.);
	hist_CosThetaL5_norm->SetLineWidth(1); hist_CosThetaL5_norm->SetLineColor(1);

	TH1F *hist_PtL5_norm = new TH1F("hist_PtL5_norm",";p_{t} [GeV];No.of J/#psi candidates",n_binning_pt,binning_pt);
	hist_PtL5_norm->SetLineWidth(1); hist_PtL5_norm->SetLineColor(1);

	TH2F *hist_PtCosThetaL5_norm = new TH2F("hist_PtCosThetaL5_norm",";cos#theta;p_{t} [GeV]",nbins_CosTheta,-1.,1.,n_binning_pt,binning_pt);
	hist_PtCosThetaL5_norm->SetLineWidth(1); hist_PtCosThetaL5_norm->SetLineColor(1);

	TH1F *hist_InvMassS5_os = new TH1F("hist_InvMassS5_os"," ;m_{#mu^{+}#mu^{-}}[GeV];No.of J/#psi candidates",nbins_InvMass,2.8,3.8);
	hist_InvMassS5_os->SetLineWidth(1); hist_InvMassS5_os->SetLineColor(4);
	hist_InvMassS5_os->GetYaxis()->SetLabelSize(0.04);

	TH1F *hist_CosThetaS5_os = new TH1F("hist_CosThetaS5_os",";cos#theta;No.of J/#psi candidates",nbins_CosTheta,-1.,1.);
	hist_CosThetaS5_os->SetLineWidth(1); hist_CosThetaS5_os->SetLineColor(4);
	hist_CosThetaS5_os->GetYaxis()->SetLabelSize(0.04);

	TH1F *hist_PtS5_os = new TH1F("hist_PtS5_os"," ;p_{t} [GeV];No.of J/#psi candidates",n_binning_pt,binning_pt);
	hist_PtS5_os->SetLineWidth(1); hist_PtS5_os->SetLineColor(4);
	hist_PtS5_os->GetYaxis()->SetLabelSize(0.04);

	TH2F *hist_PtCosThetaL5_os = new TH2F("hist_PtCosThetaL5_os"," ;cos#theta;p_{t} [GeV]",nbins_CosTheta,-1.,1.,n_binning_pt,binning_pt);
	hist_PtCosThetaL5_os->SetLineWidth(1); hist_PtCosThetaL5_os->SetLineColor(4);

	TH1F *hist_InvMassS5_ls = new TH1F("hist_InvMassS5_ls","",nbins_InvMass,2.8,3.8);
	hist_InvMassS5_ls->SetLineWidth(1); hist_InvMassS5_ls->SetLineColor(2);

	TH1F *hist_CosThetaS5_ls = new TH1F("hist_CosThetaS5_ls",";cos#theta;No.of J/#psi candidates",nbins_CosTheta,-1.,1.);
	hist_CosThetaS5_ls->SetLineWidth(1); hist_CosThetaS5_ls->SetLineColor(2);

	TH1F *hist_PtS5_ls = new TH1F("hist_PtS5_ls",";p_{t}; No.of J/#psi candidates",n_binning_pt,binning_pt);
	hist_PtS5_ls->SetLineWidth(1); hist_PtS5_ls->SetLineColor(2);

	TH2F *hist_PtCosThetaS5_ls = new TH2F("hist_PtCosThetaS5_ls",";cos#theta;p_{t} [GeV]",nbins_CosTheta,-1.,1.,n_binning_pt,binning_pt);
	hist_PtCosThetaS5_ls->SetLineWidth(1); hist_PtCosThetaS5_ls->SetLineColor(2);

	TH1F *hist_InvMassS5_norm = new TH1F("hist_InvMassS5_norm",";m_{#mu^{+}#mu^{-}} [GeV];No.of J/#psi candidates",nbins_InvMass,2.8,3.8);
	hist_InvMassS5_norm->SetLineWidth(1);// hist_InvMassS5_norm->SetLineColor(1);

	TH1F *hist_CosThetaS5_norm = new TH1F("hist_CosThetaS5_norm"," ;cos#theta ;No.of J/#psi candidates",nbins_CosTheta,-1.,1.);
	hist_CosThetaS5_norm->SetLineWidth(1); hist_CosThetaS5_norm->SetLineColor(1);

	TH1F *hist_PtS5_norm = new TH1F("hist_PtS5_norm",";p_{t};No.of J/#psi candidates ",n_binning_pt,binning_pt);
	hist_PtS5_norm->SetLineWidth(1); hist_PtS5_norm->SetLineColor(1);

	TH2F *hist_PtCosThetaS5_norm = new TH2F("hist_PtCosThetaS5_norm",";cos#theta;p_{t} [GeV]",nbins_CosTheta,-1.,1.,n_binning_pt,binning_pt);
	hist_PtCosThetaS5_norm->SetLineWidth(1); hist_PtCosThetaS5_norm->SetLineColor(1);

	TH1F *hist_InvMassS5_vs_l5 = new TH1F("hist_InvMassS5_vs_l5"," ;m_{#mu^{+}#mu^{-}} [GeV];No.of J/#psi candidates",nbins_InvMass,2.8,3.8);
	hist_InvMassS5_vs_l5->SetLineWidth(1); hist_InvMassS5_vs_l5->SetLineColor(4);
	hist_InvMassS5_vs_l5->GetYaxis()->SetLabelSize(0.04);

	for (int i_process=0; i_process<physical_process.size();++i_process)
	{
		cout << "processing " << i_process+1 << " out of " << physical_process.size() << " process; " << (physical_process[i_process]).c_str() << endl;
		TFile *file_l5 = new TFile((file_path_l5+physical_process[i_process]+".root").c_str());
		TTree *tree_l5 = (TTree*)file_l5->Get((input_tree_name).c_str());
		int nEntries_l5 = tree_l5->GetEntries();
		TFile *file_s5 = new TFile((file_path_s5+physical_process[i_process]+".root").c_str());
		TTree *tree_s5 = (TTree*)file_s5->Get((input_tree_name).c_str());
		int nEntries_s5 = tree_s5->GetEntries();

		float			m_crossSection_l5 = 0;
		float			m_polarizatione_l5 = 0;
		float			m_polarizationp_l5 = 0;

		int			m_nMcpMuons = 0;
		int			m_nMcpJpsis = 0;
		int			m_nMcpJpsisLikeSign = 0;
		int			m_nMcpJpsisOppositeSign = 0;
		vector<int>		*m_mcpMuonPDG{};
		vector<float>		*m_mcpMuonCharge{};
		vector<float>		*m_mcpMuonEnergy{};
		vector<float>		*m_mcpMuonPx{};
		vector<float>		*m_mcpMuonPy{};
		vector<float>		*m_mcpMuonPz{};
		vector<float>		*m_mcpMuonPt{};
		vector<float>		*m_mcpMuonCosTheta{};
		vector<float>		*m_mcpJpsiCharge{};
		vector<float>		*m_mcpJpsiEnergy{};
		vector<float>		*m_mcpJpsiPx{};
		vector<float>		*m_mcpJpsiPy{};
		vector<float>		*m_mcpJpsiPz{};
		vector<float>		*m_mcpJpsiPt{};
		vector<float>		*m_mcpJpsiCosTheta{};
		vector<float>		*m_mcpJpsiInvMass{};
		vector<int>		*m_mcpMuon1Index{};
		vector<int>		*m_mcpMuon2Index{};

		int			m_nPfoMuons_l5 = 0;
		int			m_nPfoJpsis_l5 = 0;
		int			m_nPfoJpsisLikeSign_l5 = 0;
		int			m_nPfoJpsisOppositeSign_l5 = 0;
		vector<int>		*m_pfoMuonPDG_l5{};
		vector<float>		*m_pfoMuonCharge_l5{};
		vector<float>		*m_pfoMuonEnergy_l5{};
		vector<float>		*m_pfoMuonPx_l5{};
		vector<float>		*m_pfoMuonPy_l5{};
		vector<float>		*m_pfoMuonPz_l5{};
		vector<float>		*m_pfoMuonPt_l5{};
		vector<float>		*m_pfoMuonCosTheta_l5{};
		vector<float>		*m_pfoJpsiCharge_l5{};
		vector<float>		*m_pfoJpsiEnergy_l5{};
		vector<float>		*m_pfoJpsiPx_l5{};
		vector<float>		*m_pfoJpsiPy_l5{};
		vector<float>		*m_pfoJpsiPz_l5{};
		vector<float>		*m_pfoJpsiPt_l5{};
		vector<float>		*m_pfoJpsiCosTheta_l5{};
		vector<float>		*m_pfoJpsiInvMass_l5{};
		vector<int>		*m_pfoMuon1Index_l5{};
		vector<int>		*m_pfoMuon2Index_l5{};

		float			m_crossSection_s5 = 0;
		float			m_polarizatione_s5 = 0;
		float			m_polarizationp_s5 = 0;

		int			m_nPfoMuons_s5 = 0;
		int			m_nPfoJpsis_s5 = 0;
		int			m_nPfoJpsisLikeSign_s5 = 0;
		int			m_nPfoJpsisOppositeSign_s5 = 0;
		vector<int>		*m_pfoMuonPDG_s5{};
		vector<float>		*m_pfoMuonCharge_s5{};
		vector<float>		*m_pfoMuonEnergy_s5{};
		vector<float>		*m_pfoMuonPx_s5{};
		vector<float>		*m_pfoMuonPy_s5{};
		vector<float>		*m_pfoMuonPz_s5{};
		vector<float>		*m_pfoMuonPt_s5{};
		vector<float>		*m_pfoMuonCosTheta_s5{};
		vector<float>		*m_pfoJpsiCharge_s5{};
		vector<float>		*m_pfoJpsiEnergy_s5{};
		vector<float>		*m_pfoJpsiPx_s5{};
		vector<float>		*m_pfoJpsiPy_s5{};
		vector<float>		*m_pfoJpsiPz_s5{};
		vector<float>		*m_pfoJpsiPt_s5{};
		vector<float>		*m_pfoJpsiCosTheta_s5{};
		vector<float>		*m_pfoJpsiInvMass_s5{};
		vector<int>		*m_pfoMuon1Index_s5{};
		vector<int>		*m_pfoMuon2Index_s5{};

		tree_l5->SetBranchAddress("CrossSection", &m_crossSection_l5);
		tree_l5->SetBranchAddress("polarizationElectron", &m_polarizatione_l5);
		tree_l5->SetBranchAddress("polarizationPositron", &m_polarizationp_l5);
		tree_l5->SetBranchAddress("nMcpMuons", &m_nMcpMuons);
		tree_l5->SetBranchAddress("nMcpJpsis", &m_nMcpJpsis);
		tree_l5->SetBranchAddress("nMcpJpsisLikeSign", &m_nMcpJpsisLikeSign);
		tree_l5->SetBranchAddress("nMcpJpsisOppositeSign", &m_nMcpJpsisOppositeSign);
		tree_l5->SetBranchAddress("mcpMuonPDG", &m_mcpMuonPDG);
		tree_l5->SetBranchAddress("mcpMuonCharge", &m_mcpMuonCharge);
		tree_l5->SetBranchAddress("mcpMuonEnergy", &m_mcpMuonEnergy);
		tree_l5->SetBranchAddress("mcpMuonPx", &m_mcpMuonPx);
		tree_l5->SetBranchAddress("mcpMuonPy", &m_mcpMuonPy);
		tree_l5->SetBranchAddress("mcpMuonPz", &m_mcpMuonPz);
		tree_l5->SetBranchAddress("mcpMuonPt", &m_mcpMuonPt);
		tree_l5->SetBranchAddress("mcpMuonCosTheta", &m_mcpMuonCosTheta);
		tree_l5->SetBranchAddress("mcpJpsiCharge", &m_mcpJpsiCharge);
		tree_l5->SetBranchAddress("mcpJpsiEnergy", &m_mcpJpsiEnergy);
		tree_l5->SetBranchAddress("mcpJpsiPx", &m_mcpJpsiPx);
		tree_l5->SetBranchAddress("mcpJpsiPy", &m_mcpJpsiPy);
		tree_l5->SetBranchAddress("mcpJpsiPz", &m_mcpJpsiPz);
		tree_l5->SetBranchAddress("mcpJpsiPt", &m_mcpJpsiPt);
		tree_l5->SetBranchAddress("mcpJpsiCosTheta", &m_mcpJpsiCosTheta);
		tree_l5->SetBranchAddress("mcpJpsiInvMass", &m_mcpJpsiInvMass);
		tree_l5->SetBranchAddress("mcpMuon1Index", &m_mcpMuon1Index);
		tree_l5->SetBranchAddress("mcpMuon2Index", &m_mcpMuon2Index);

		tree_l5->SetBranchAddress("nPfoMuons", &m_nPfoMuons_l5);
		tree_l5->SetBranchAddress("nPfoJpsis", &m_nPfoJpsis_l5);
		tree_l5->SetBranchAddress("nPfoJpsisLikeSign", &m_nPfoJpsisLikeSign_l5);
		tree_l5->SetBranchAddress("nPfoJpsisOppositeSign", &m_nPfoJpsisOppositeSign_l5);
		tree_l5->SetBranchAddress("pfoMuonPDG", &m_pfoMuonPDG_l5);
		tree_l5->SetBranchAddress("pfoMuonCharge", &m_pfoMuonCharge_l5);
		tree_l5->SetBranchAddress("pfoMuonEnergy", &m_pfoMuonEnergy_l5);
		tree_l5->SetBranchAddress("pfoMuonPx", &m_pfoMuonPx_l5);
		tree_l5->SetBranchAddress("pfoMuonPy", &m_pfoMuonPy_l5);
		tree_l5->SetBranchAddress("pfoMuonPz", &m_pfoMuonPz_l5);
		tree_l5->SetBranchAddress("pfoMuonPt", &m_pfoMuonPt_l5);
		tree_l5->SetBranchAddress("pfoMuonCosTheta", &m_pfoMuonCosTheta_l5);
		tree_l5->SetBranchAddress("pfoJpsiCharge", &m_pfoJpsiCharge_l5);
		tree_l5->SetBranchAddress("pfoJpsiEnergy", &m_pfoJpsiEnergy_l5);
		tree_l5->SetBranchAddress("pfoJpsiPx", &m_pfoJpsiPx_l5);
		tree_l5->SetBranchAddress("pfoJpsiPy", &m_pfoJpsiPy_l5);
		tree_l5->SetBranchAddress("pfoJpsiPz", &m_pfoJpsiPz_l5);
		tree_l5->SetBranchAddress("pfoJpsiPt", &m_pfoJpsiPt_l5);
		tree_l5->SetBranchAddress("pfoJpsiCosTheta", &m_pfoJpsiCosTheta_l5);
		tree_l5->SetBranchAddress("pfoJpsiInvMass", &m_pfoJpsiInvMass_l5);
		tree_l5->SetBranchAddress("pfoMuon1Index", &m_pfoMuon1Index_l5);
		tree_l5->SetBranchAddress("pfoMuon2Index", &m_pfoMuon2Index_l5);

		tree_s5->SetBranchAddress("CrossSection", &m_crossSection_s5);
		tree_s5->SetBranchAddress("polarizationElectron", &m_polarizatione_s5);
		tree_s5->SetBranchAddress("polarizationPositron", &m_polarizationp_s5);
		tree_s5->SetBranchAddress("nPfoMuons", &m_nPfoMuons_s5);
		tree_s5->SetBranchAddress("nPfoJpsis", &m_nPfoJpsis_s5);
		tree_s5->SetBranchAddress("nPfoJpsisLikeSign", &m_nPfoJpsisLikeSign_s5);
		tree_s5->SetBranchAddress("nPfoJpsisOppositeSign", &m_nPfoJpsisOppositeSign_s5);
		tree_s5->SetBranchAddress("pfoMuonPDG", &m_pfoMuonPDG_s5);
		tree_s5->SetBranchAddress("pfoMuonCharge", &m_pfoMuonCharge_s5);
		tree_s5->SetBranchAddress("pfoMuonEnergy", &m_pfoMuonEnergy_s5);
		tree_s5->SetBranchAddress("pfoMuonPx", &m_pfoMuonPx_s5);
		tree_s5->SetBranchAddress("pfoMuonPy", &m_pfoMuonPy_s5);
		tree_s5->SetBranchAddress("pfoMuonPz", &m_pfoMuonPz_s5);
		tree_s5->SetBranchAddress("pfoMuonPt", &m_pfoMuonPt_s5);
		tree_s5->SetBranchAddress("pfoMuonCosTheta", &m_pfoMuonCosTheta_s5);
		tree_s5->SetBranchAddress("pfoJpsiCharge", &m_pfoJpsiCharge_s5);
		tree_s5->SetBranchAddress("pfoJpsiEnergy", &m_pfoJpsiEnergy_s5);
		tree_s5->SetBranchAddress("pfoJpsiPx", &m_pfoJpsiPx_s5);
		tree_s5->SetBranchAddress("pfoJpsiPy", &m_pfoJpsiPy_s5);
		tree_s5->SetBranchAddress("pfoJpsiPz", &m_pfoJpsiPz_s5);
		tree_s5->SetBranchAddress("pfoJpsiPt", &m_pfoJpsiPt_s5);
		tree_s5->SetBranchAddress("pfoJpsiCosTheta", &m_pfoJpsiCosTheta_s5);
		tree_s5->SetBranchAddress("pfoJpsiInvMass", &m_pfoJpsiInvMass_s5);
		tree_s5->SetBranchAddress("pfoMuon1Index", &m_pfoMuon1Index_s5);
		tree_s5->SetBranchAddress("pfoMuon2Index", &m_pfoMuon2Index_s5);


		std::vector<float> e_pol_percentage = {-0.8,-0.8,0.8,0.8};
		std::vector<float> p_pol_percentage = {-0.3,0.3,-0.3,0.3};
		std::vector<float> e_pol_sign = {-1,-1,1,1};
		std::vector<float> p_pol_sign = {-1,1,-1,1};

		std::vector<float> Luminosity = {400,1600,1600,400};

		std::vector<int> N_mcp = {0,0,0,0};
		std::vector<float> xSection_mcp = {0,0,0,0};
		std::vector<float> polWeight_mcp = {0,0,0,0};
		std::vector<float> weight_mcp = {0,0,0,0};

		std::vector<int> N_l5 = {0,0,0,0};
		std::vector<float> xSection_l5 = {0,0,0,0};
		std::vector<float> polWeight_l5 = {0,0,0,0};
		std::vector<float> weight_l5 = {0,0,0,0};

		std::vector<int> N_s5 = {0,0,0,0};
		std::vector<float> xSection_s5 = {0,0,0,0};
		std::vector<float> polWeight_s5 = {0,0,0,0};
		std::vector<float> weight_s5 = {0,0,0,0};


		for (int i_entry=0; i_entry<nEntries_l5; ++i_entry)
		{
			tree_l5->GetEntry(i_entry);
			N_mcp[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]++;
			xSection_mcp[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]=m_crossSection_l5;
			N_l5[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]++;
			xSection_l5[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]=m_crossSection_l5;
		}
		for (int i_entry=0; i_entry<nEntries_s5; ++i_entry)
		{
			tree_s5->GetEntry(i_entry);
			N_s5[((2*m_polarizatione_s5+m_polarizationp_s5)+3)/2]++;
			xSection_s5[((2*m_polarizatione_s5+m_polarizationp_s5)+3)/2]=m_crossSection_s5;
		}

		for (int iter = 0; iter<N_mcp.size(); ++iter)
		{
			for (int pol_iter = 0; pol_iter<e_pol_percentage.size(); ++pol_iter)
			{
				polWeight_mcp[iter] += (1 + e_pol_sign[iter] * e_pol_percentage[pol_iter])*(1 + p_pol_sign[iter] * p_pol_percentage[pol_iter])*Luminosity[pol_iter];
				polWeight_l5[iter] += (1 + e_pol_sign[iter] * e_pol_percentage[pol_iter])*(1 + p_pol_sign[iter] * p_pol_percentage[pol_iter])*Luminosity[pol_iter];
				polWeight_s5[iter] += (1 + e_pol_sign[iter] * e_pol_percentage[pol_iter])*(1 + p_pol_sign[iter] * p_pol_percentage[pol_iter])*Luminosity[pol_iter];
			}
		}
		for (int iter = 0; iter<N_mcp.size(); ++iter)
		{
			if (N_mcp[iter]!=0)
				weight_mcp[iter] = polWeight_mcp[iter] * xSection_mcp[iter] / (4 * N_mcp[iter]);

			if (N_l5[iter]!=0)
				weight_l5[iter] = polWeight_l5[iter] * xSection_l5[iter] / (4 * N_l5[iter]);

			if (N_s5[iter]!=0)
				weight_s5[iter] = polWeight_s5[iter] * xSection_s5[iter] / (4 * N_s5[iter]);
                }
		int Num_Jpsis_os = 0;
		int Num_Jpsis_ls = 0;
		float norm = 0;

		for (int i_entry=0; i_entry<nEntries_l5; ++i_entry)
		{
			tree_l5->GetEntry(i_entry);
			for (int Jpsi_index=0; Jpsi_index<(m_mcpJpsiCharge->size()); ++Jpsi_index)
			{
				if ((m_mcpJpsiCharge->at(Jpsi_index))==0)
				{
					hist_InvMassMCP_os->Fill((m_mcpJpsiInvMass->at(Jpsi_index)),weight_mcp[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
					if (((m_mcpJpsiInvMass->at(Jpsi_index))<3.1) && ((m_mcpJpsiInvMass->at(Jpsi_index))>=3.09))
					{
						hist_CosThetaMCP_os->Fill((m_mcpJpsiCosTheta->at(Jpsi_index)),weight_mcp[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
						hist_PtMCP_os->Fill((m_mcpJpsiPt->at(Jpsi_index)),weight_mcp[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
						hist_PtCosThetaMCP_os->Fill((m_mcpJpsiCosTheta->at(Jpsi_index)),(m_mcpJpsiPt->at(Jpsi_index)),weight_mcp[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
					}
					if ((((m_mcpJpsiInvMass->at(Jpsi_index))<3.8) && ((m_mcpJpsiInvMass->at(Jpsi_index))>=3.1)) || (((m_mcpJpsiInvMass->at(Jpsi_index))<3.09) && ((m_mcpJpsiInvMass->at(Jpsi_index))>=2.8)))
						++Num_Jpsis_os;
				}
				if ((m_mcpJpsiCharge->at(Jpsi_index))!=0)
				{
					hist_InvMassMCP_ls->Fill((m_mcpJpsiInvMass->at(Jpsi_index)),weight_mcp[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
					if (((m_mcpJpsiInvMass->at(Jpsi_index))<3.1) && ((m_mcpJpsiInvMass->at(Jpsi_index))>=3.09))
					{
						hist_CosThetaMCP_ls->Fill((m_mcpJpsiCosTheta->at(Jpsi_index)),weight_mcp[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
						hist_PtMCP_ls->Fill((m_mcpJpsiPt->at(Jpsi_index)),weight_mcp[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
						hist_PtCosThetaMCP_ls->Fill((m_mcpJpsiCosTheta->at(Jpsi_index)),(m_mcpJpsiPt->at(Jpsi_index)),weight_mcp[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
					}
					if ((((m_mcpJpsiInvMass->at(Jpsi_index))<3.8) && ((m_mcpJpsiInvMass->at(Jpsi_index))>=3.1)) || (((m_mcpJpsiInvMass->at(Jpsi_index))<3.09) && ((m_mcpJpsiInvMass->at(Jpsi_index))>=2.8)))
						++Num_Jpsis_ls;
				}
			}
		}
		if (Num_Jpsis_ls!=0)
                norm = Num_Jpsis_os/Num_Jpsis_ls;
		for (int i_entry=0; i_entry<nEntries_l5; ++i_entry)
		{
			tree_l5->GetEntry(i_entry);
			for (int Jpsi_index=0; Jpsi_index<(m_mcpJpsiCharge->size()); ++Jpsi_index)
			{
				if ((m_mcpJpsiCharge->at(Jpsi_index))==0)
				{
					hist_InvMassMCP_norm->Fill((m_mcpJpsiInvMass->at(Jpsi_index)),weight_mcp[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
					if (((m_mcpJpsiInvMass->at(Jpsi_index))<3.1) && ((m_mcpJpsiInvMass->at(Jpsi_index))>=3.09))
					{
						hist_CosThetaMCP_norm->Fill((m_mcpJpsiCosTheta->at(Jpsi_index)),weight_mcp[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
						hist_PtMCP_norm->Fill((m_mcpJpsiPt->at(Jpsi_index)),weight_mcp[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
						hist_PtCosThetaMCP_norm->Fill((m_mcpJpsiCosTheta->at(Jpsi_index)),(m_mcpJpsiPt->at(Jpsi_index)),weight_mcp[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
					}
				}
				if ((m_mcpJpsiCharge->at(Jpsi_index))!=0)
				{
					hist_InvMassMCP_norm->Fill((m_mcpJpsiInvMass->at(Jpsi_index)),-norm * weight_mcp[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
					if (((m_mcpJpsiInvMass->at(Jpsi_index))<3.1) && ((m_mcpJpsiInvMass->at(Jpsi_index))>=3.09))
					{
						hist_CosThetaMCP_norm->Fill((m_mcpJpsiCosTheta->at(Jpsi_index)),-norm * weight_mcp[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
						hist_PtMCP_norm->Fill((m_mcpJpsiPt->at(Jpsi_index)),-norm * weight_mcp[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
						hist_PtCosThetaMCP_norm->Fill((m_mcpJpsiCosTheta->at(Jpsi_index)),(m_mcpJpsiPt->at(Jpsi_index)),-norm * weight_mcp[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
					}
				}
			}
		}
		cout << "nEntries_l5 = " << nEntries_l5 << endl;
		for (int i_entry=0; i_entry<nEntries_l5; ++i_entry)
		{
			tree_l5->GetEntry(i_entry);
			for (int Jpsi_index=0; Jpsi_index<m_nPfoJpsis_l5; ++Jpsi_index)
			{
				if ((m_pfoJpsiCharge_l5->at(Jpsi_index))==0)
				{
					hist_InvMassL5_os->Fill((m_pfoJpsiInvMass_l5->at(Jpsi_index)),weight_l5[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
					if (((m_pfoJpsiInvMass_l5->at(Jpsi_index))<3.15) && ((m_pfoJpsiInvMass_l5->at(Jpsi_index))>3.05))
					{
						hist_CosThetaL5_os->Fill((m_pfoJpsiCosTheta_l5->at(Jpsi_index)),weight_l5[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
						hist_PtL5_os->Fill((m_pfoJpsiPt_l5->at(Jpsi_index)),weight_l5[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
						hist_PtCosThetaL5_os->Fill((m_pfoJpsiCosTheta_l5->at(Jpsi_index)),(m_pfoJpsiPt_l5->at(Jpsi_index)),weight_l5[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
					}
					if ((((m_pfoJpsiInvMass_l5->at(Jpsi_index))<=3.8) && ((m_pfoJpsiInvMass_l5->at(Jpsi_index))>=3.15)) || (((m_pfoJpsiInvMass_l5->at(Jpsi_index))<=3.04) && ((m_pfoJpsiInvMass_l5->at(Jpsi_index))>=2.8)))
					++Num_Jpsis_os;
				}
				if ((m_pfoJpsiCharge_l5->at(Jpsi_index))!=0)
				{
					hist_InvMassL5_ls->Fill((m_pfoJpsiInvMass_l5->at(Jpsi_index)),weight_l5[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
					if (((m_pfoJpsiInvMass_l5->at(Jpsi_index))<3.15) && ((m_pfoJpsiInvMass_l5->at(Jpsi_index))>3.05))
					{
						hist_CosThetaL5_ls->Fill((m_pfoJpsiCosTheta_l5->at(Jpsi_index)),weight_l5[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
						hist_PtL5_ls->Fill((m_pfoJpsiPt_l5->at(Jpsi_index)),weight_l5[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
						hist_PtCosThetaL5_ls->Fill((m_pfoJpsiCosTheta_l5->at(Jpsi_index)),(m_pfoJpsiPt_l5->at(Jpsi_index)),weight_l5[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
					}
					if ((((m_pfoJpsiInvMass_l5->at(Jpsi_index))<=3.8) && ((m_pfoJpsiInvMass_l5->at(Jpsi_index))>=3.15)) || (((m_pfoJpsiInvMass_l5->at(Jpsi_index))<=3.04) && ((m_pfoJpsiInvMass_l5->at(Jpsi_index))>=2.8)))
					++Num_Jpsis_ls;
				}
			}
		}
		for (int i_entry=0; i_entry<nEntries_s5; ++i_entry)
		{
			tree_s5->GetEntry(i_entry);
			for (int Jpsi_index=0; Jpsi_index<m_nPfoJpsis_s5; ++Jpsi_index)
			{
				if ((m_pfoJpsiCharge_s5->at(Jpsi_index))==0)
				{
					hist_InvMassS5_os->Fill((m_pfoJpsiInvMass_s5->at(Jpsi_index)),weight_s5[((2*m_polarizatione_s5+m_polarizationp_s5)+3)/2]);
					if (((m_pfoJpsiInvMass_s5->at(Jpsi_index))<3.15) && ((m_pfoJpsiInvMass_s5->at(Jpsi_index))>3.05))
					{
						hist_CosThetaS5_os->Fill((m_pfoJpsiCosTheta_s5->at(Jpsi_index)),weight_s5[((2*m_polarizatione_s5+m_polarizationp_s5)+3)/2]);
						hist_PtS5_os->Fill((m_pfoJpsiPt_s5->at(Jpsi_index)),weight_s5[((2*m_polarizatione_s5+m_polarizationp_s5)+3)/2]);
						hist_PtCosThetaS5_os->Fill((m_pfoJpsiCosTheta_s5->at(Jpsi_index)),(m_pfoJpsiPt_s5->at(Jpsi_index)),weight_s5[((2*m_polarizatione_s5+m_polarizationp_s5)+3)/2]);
					}
					if ((((m_pfoJpsiInvMass_s5->at(Jpsi_index))<=3.8) && ((m_pfoJpsiInvMass_s5->at(Jpsi_index))>=3.15)) || (((m_pfoJpsiInvMass_s5->at(Jpsi_index))<=3.04) && ((m_pfoJpsiInvMass_s5->at(Jpsi_index))>=2.8)))
					++Num_Jpsis_os;
				}
				if ((m_pfoJpsiCharge_s5->at(Jpsi_index))!=0)
				{
					hist_InvMassS5_ls->Fill((m_pfoJpsiInvMass_s5->at(Jpsi_index)),weight_s5[((2*m_polarizatione_s5+m_polarizationp_s5)+3)/2]);
					if (((m_pfoJpsiInvMass_s5->at(Jpsi_index))<3.15) && ((m_pfoJpsiInvMass_s5->at(Jpsi_index))>3.05))
					{
						hist_CosThetaS5_ls->Fill((m_pfoJpsiCosTheta_s5->at(Jpsi_index)),weight_s5[((2*m_polarizatione_s5+m_polarizationp_s5)+3)/2]);
						hist_PtS5_ls->Fill((m_pfoJpsiPt_s5->at(Jpsi_index)),weight_s5[((2*m_polarizatione_s5+m_polarizationp_s5)+3)/2]);
						hist_PtCosThetaS5_ls->Fill((m_pfoJpsiCosTheta_s5->at(Jpsi_index)),(m_pfoJpsiPt_s5->at(Jpsi_index)),weight_s5[((2*m_polarizatione_s5+m_polarizationp_s5)+3)/2]);
					}
					if ((((m_pfoJpsiInvMass_s5->at(Jpsi_index))<=3.8) && ((m_pfoJpsiInvMass_s5->at(Jpsi_index))>=3.15)) || (((m_pfoJpsiInvMass_s5->at(Jpsi_index))<=3.04) && ((m_pfoJpsiInvMass_s5->at(Jpsi_index))>=2.8)))
					++Num_Jpsis_ls;
				}
			}
		}
		if (Num_Jpsis_ls!=0)
		norm = Num_Jpsis_os/Num_Jpsis_ls;
	}
	cout << "******************   ALL PROCESSES FINISHED   ******************" << endl;
	float norm_s5 = (hist_InvMassS5_os->Integral(1,25) + hist_InvMassS5_os->Integral(35,100))/(hist_InvMassS5_ls->Integral(1,25) + hist_InvMassS5_ls->Integral(35,100));
	hist_InvMassS5_norm->Add(hist_InvMassS5_os);
	hist_InvMassS5_norm->Add(hist_InvMassS5_ls,-norm_s5);
	hist_CosThetaS5_norm->Add(hist_CosThetaS5_os);
	hist_CosThetaS5_norm->Add(hist_CosThetaS5_ls,-norm_s5);
	hist_PtS5_norm->Add(hist_PtS5_os);
	hist_PtS5_norm->Add(hist_PtS5_ls,-norm_s5);
	hist_PtCosThetaS5_norm->Add(hist_PtCosThetaS5_os);
	hist_PtCosThetaS5_norm->Add(hist_PtCosThetaS5_ls,-norm_s5);
	float norm_l5 = (hist_InvMassL5_os->Integral(1,25) + hist_InvMassL5_os->Integral(35,100))/(hist_InvMassL5_ls->Integral(1,25) + hist_InvMassL5_ls->Integral(35,100));
	hist_InvMassL5_norm->Add(hist_InvMassL5_os);
	hist_InvMassL5_norm->Add(hist_InvMassL5_ls,-norm_l5);
	hist_CosThetaL5_norm->Add(hist_CosThetaL5_os);
	hist_CosThetaL5_norm->Add(hist_CosThetaL5_ls,-norm_l5);
	hist_PtL5_norm->Add(hist_PtL5_os);
	hist_PtL5_norm->Add(hist_PtL5_ls,-norm_l5);
	hist_PtCosThetaL5_norm->Add(hist_PtCosThetaL5_os);
	hist_PtCosThetaL5_norm->Add(hist_PtCosThetaL5_ls,-norm_l5);

        float int_InvMassS5_norm1 = (hist_InvMassS5_norm->Integral(1,100)-hist_InvMassS5_norm->Integral(1,25)-hist_InvMassS5_norm->Integral(35,100));
	cout <<"Num_Jpsis_S5_norm(26,34) = " << int_InvMassS5_norm1 << endl;
	float int_InvMassL5_norm1 = (hist_InvMassL5_norm->Integral(1,100)-hist_InvMassL5_norm->Integral(1,25)-hist_InvMassL5_norm->Integral(35,100));
	cout <<"Num_Jpsis_L5_norm(26,34) = " << int_InvMassL5_norm1 << endl;
        float int_CosS5_norm1 = hist_CosThetaS5_norm->Integral(1,50);
	cout <<"Num_Cos_S5_norm(26,34) = " << int_CosS5_norm1 << endl;
	float int_CosL5_norm1 = hist_CosThetaL5_norm->Integral(1,50);
	cout <<"Num_Cos_L5_norm(26,34) = " << int_CosL5_norm1 << endl;
        float int_PtS5_norm1 = hist_PtS5_norm->Integral(1,50);
	cout <<"Num_Pt_S5_norm(26,34) = " << int_PtS5_norm1 << endl;
	float int_PtL5_norm1 = hist_PtL5_norm->Integral(1,50);
	cout <<"Num_Pt_L5_norm(26,34) = " << int_PtL5_norm1 << endl;
	float int_InvMassS5_norm_left = hist_InvMassS5_norm->Integral(1,25);
	cout << "Num_InvMassS5_norm_left = " << int_InvMassS5_norm_left << endl;
	float int_InvMassS5_norm_right = hist_InvMassS5_norm->Integral(35,100);
	cout << "Num_InvMassS5_norm_right = " << int_InvMassS5_norm_right << endl;
	float int_InvMassL5_norm_left = hist_InvMassL5_norm->Integral(1,25);
	cout << "Num_InvMassL5_norm_left = " << int_InvMassL5_norm_left << endl;
	float int_InvMassL5_norm_right = hist_InvMassL5_norm->Integral(35,100);
	cout << "Num_InvMassL5_norm_right = " << int_InvMassL5_norm_right << endl;

        gStyle->SetOptStat(0);
	TCanvas *can_InvMassMCP_os = new TCanvas("can_InvMassMCP_os","can_InvMassMCP_os",1200,800);
	hist_InvMassMCP_norm->Sumw2();
	hist_InvMassMCP_norm->SetMinimum(-600);
	//hist_InvMassMCP_norm->SetMaximum(6000);
	hist_InvMassMCP_norm->Draw("hist");
	hist_InvMassMCP_ls->Sumw2();
	hist_InvMassMCP_ls->Draw("sames,hist");
	hist_InvMassMCP_os->Sumw2();
	hist_InvMassMCP_os->Draw("sames,hist");
	TLegend *InvMassMCP_os = new TLegend(0.45, 0.6, 0.7, 0.8);
	InvMassMCP_os->SetHeader("MC","l");
	InvMassMCP_os->AddEntry(hist_InvMassMCP_os,"#mu^{+}#mu^{-}","l");
	InvMassMCP_os->AddEntry(hist_InvMassMCP_ls,"#mu^{+}#mu^{+}+#mu^{-}#mu^{-}","l");
	InvMassMCP_os->AddEntry(hist_InvMassMCP_norm,"(#mu^{+}#mu^{-})-(#mu^{+}#mu^{+}+#mu^{-}#mu^{-})","l");
	InvMassMCP_os->Draw();
	can_InvMassMCP_os->SaveAs((plots_dir+"test_InvMass.pdf").c_str());
	can_InvMassMCP_os->SaveAs((plots_dir+"test_InvMass.C").c_str());
	can_InvMassMCP_os->SaveAs((plots_dir+"test_InvMass.eps").c_str());


	gStyle->SetOptStat(0);		;
	TCanvas *can_CosThetaMCP_os = new TCanvas("can_CosThetaMCP_os","can_CosThetaMCP_os",800,800);
	hist_CosThetaMCP_norm->Sumw2();
	hist_CosThetaMCP_norm->SetMinimum(-10);
	hist_CosThetaMCP_norm->SetMaximum(3000);
	hist_CosThetaMCP_norm->Draw("hist");
	hist_CosThetaMCP_ls->Sumw2();
	hist_CosThetaMCP_ls->Draw("sames,hist");
	hist_CosThetaMCP_os->Sumw2();
	hist_CosThetaMCP_os->Draw("sames,hist");
	TLegend *CosThetaMCP_os = new TLegend(0.45, 0.6, 0.7, 0.8);
	CosThetaMCP_os->SetHeader("Cos#theta","l");
	CosThetaMCP_os->AddEntry(hist_CosThetaMCP_os,"#mu^{+}#mu^{-}","l");
	CosThetaMCP_os->AddEntry(hist_CosThetaMCP_ls,"#mu^{+}#mu^{+}+#mu^{-}#mu^{-}","l");
	CosThetaMCP_os->AddEntry(hist_CosThetaMCP_norm,"(#mu^{+}#mu^{-})-(#mu^{+}#mu^{+}+#mu^{-}#mu^{-})","l");
	CosThetaMCP_os->Draw();
	can_CosThetaMCP_os->SaveAs((plots_dir+"test_CosTheta.pdf").c_str());
	can_CosThetaMCP_os->SaveAs((plots_dir+"test_CosTheta.C").c_str());
	can_CosThetaMCP_os->SaveAs((plots_dir+"test_CosTheta.eps").c_str());


        gStyle->SetOptStat(0);		;
	TCanvas *can_PtMCP_os = new TCanvas("can_PtMCP_os","can_PtMCP_os",800,800);
	hist_PtMCP_norm->Sumw2();
	hist_PtMCP_norm->SetMinimum(-10);
	hist_PtMCP_norm->SetMaximum(6000);
	hist_PtMCP_norm->Draw("hist");
	hist_PtMCP_ls->Sumw2();
	hist_PtMCP_ls->Draw("sames,hist");
	hist_PtMCP_os->Sumw2();
	hist_PtMCP_os->Draw("sames,hist");
	TLegend *PtMCP_os = new TLegend(0.45, 0.6, 0.7, 0.8);
	PtMCP_os->SetHeader("pt","l");
	PtMCP_os->AddEntry(hist_PtMCP_os,"#mu^{+}#mu^{-}","l");
	PtMCP_os->AddEntry(hist_PtMCP_ls,"#mu^{+}#mu^{+}+#mu^{-}#mu^{-}","l");
	PtMCP_os->AddEntry(hist_PtMCP_norm,"(#mu^{+}#mu^{-})-(#mu^{+}#mu^{+}+#mu^{-}#mu^{-})","l");
	PtMCP_os->Draw();
	can_PtMCP_os->SaveAs((plots_dir+"test_Pt.pdf").c_str());
	can_PtMCP_os->SaveAs((plots_dir+"test_Pt.C").c_str());
	can_PtMCP_os->SaveAs((plots_dir+"test_Pt.eps").c_str());


        gStyle->SetOptStat(0);
	TCanvas *can_PtCosThetaMCP_os = new TCanvas("can_PtCosThetaMCP_os","can_PtCosThetaMCP_os",1280,1000);
	hist_PtCosThetaMCP_norm->Sumw2();
	hist_PtCosThetaMCP_norm->SetMaximum(300);
	hist_PtCosThetaMCP_norm->SetMinimum(-300);
	hist_PtCosThetaMCP_norm->Draw("colz");
	gPad->Update();
	TPaletteAxis *pal_PtCosThetaMCP_norm = (TPaletteAxis*)hist_PtCosThetaMCP_norm->GetListOfFunctions()->FindObject("palette");
	pal_PtCosThetaMCP_norm->SetX1NDC(0.85);
	pal_PtCosThetaMCP_norm->SetX2NDC(0.885);
	gPad->SetRightMargin(0.15);
	gPad->Update();
	can_PtCosThetaMCP_os->Modified();
	can_PtCosThetaMCP_os->Update();
	float int_PtCosThetaMCP_os = hist_PtCosThetaMCP_os->Integral(1,100,1,100);
	cout << "Num_PtCosThetaMCP_os = " << int_PtCosThetaMCP_os << endl;
	float int_PtCosThetaMCP_ls = hist_PtCosThetaMCP_ls->Integral(1,100,1,100);
	cout << "Num_PtCosThetaMCP_ls = " << int_PtCosThetaMCP_ls << endl;
	float int_PtCosThetaMCP_norm = hist_PtCosThetaMCP_norm->Integral(1,100,1,100);
	cout << "Num_PtCosThetaMCP_norm = " << int_PtCosThetaMCP_norm << endl;
	can_PtCosThetaMCP_os->SaveAs((plots_dir+"test_Pt_cosThetaMCP.pdf").c_str());
	can_PtCosThetaMCP_os->SaveAs((plots_dir+"test_Pt_cosThetaMCP.C").c_str());
	can_PtCosThetaMCP_os->SaveAs((plots_dir+"test_Pt_cosThetaMCP.eps").c_str());

	gStyle->SetOptStat(0);
	TCanvas *can_InvMassL5_os = new TCanvas("can_InvMassL5_os","can_InvMassL5_os",800,800);
	hist_InvMassL5_os->Sumw2();
	hist_InvMassL5_os->SetMinimum(-600);
	hist_InvMassL5_os->SetMaximum(6000);
	hist_InvMassL5_os->Draw("hist");
	hist_InvMassL5_ls->Sumw2();
	hist_InvMassL5_ls->Draw("sames,hist");
	hist_InvMassL5_norm->Sumw2();
	hist_InvMassL5_norm->Draw("sames,hist");
	TLegend *InvMassL5_os = new TLegend(0.45, 0.6, 0.7, 0.8);
	InvMassL5_os->SetHeader("ILD_L5","l");
	InvMassL5_os->AddEntry(hist_InvMassL5_os,"#mu^{+}#mu^{-}","l");
	InvMassL5_os->AddEntry(hist_InvMassL5_ls,"#mu^{+}#mu^{+}+#mu^{-}#mu^{-}","l");
	InvMassL5_os->AddEntry(hist_InvMassL5_norm,"(#mu^{+}#mu^{-})-(#mu^{+}#mu^{+}+#mu^{-}#mu^{-})","l");
	InvMassL5_os->Draw();
	can_InvMassL5_os->SaveAs((plots_dir+"test_InvMassL5.pdf").c_str());
	can_InvMassL5_os->SaveAs((plots_dir+"test_InvMassL5.C").c_str());
	can_InvMassL5_os->SaveAs((plots_dir+"test_InvMassL5.eps").c_str());

	TCanvas *can_CosThetaL5_os = new TCanvas("can_CosThetaL5_os","can_CosThetaL5_os",800,800);
	hist_CosThetaL5_os->Sumw2();
	hist_CosThetaL5_os->SetMinimum(-10);
	hist_CosThetaL5_os->SetMaximum(3000);
	hist_CosThetaL5_os->Draw("hist");
	hist_CosThetaL5_ls->Sumw2();
	hist_CosThetaL5_ls->Draw("sames,hist");
	hist_CosThetaL5_norm->Sumw2();
	hist_CosThetaL5_norm->Draw("sames,hist");
	TLegend *CosThetaL5_os = new TLegend(0.45, 0.6, 0.7, 0.8);
	CosThetaL5_os->SetHeader("ILD_L5","l");
	CosThetaL5_os->AddEntry(hist_CosThetaL5_os,"#mu^{+}#mu^{-}","l");
	CosThetaL5_os->AddEntry(hist_CosThetaL5_ls,"#mu^{+}#mu^{+}+#mu^{-}#mu^{-}","l");
	CosThetaL5_os->AddEntry(hist_CosThetaL5_norm,"(#mu^{+}#mu^{-})-(#mu^{+}#mu^{+}+#mu^{-}#mu^{-})","l");
	CosThetaL5_os->Draw();
	can_CosThetaL5_os->SaveAs((plots_dir+"test_CosThetaL5.pdf").c_str());
	can_CosThetaL5_os->SaveAs((plots_dir+"test_CosThetaL5.C").c_str());
	can_CosThetaL5_os->SaveAs((plots_dir+"test_CosThetaL5.eps").c_str());

	TCanvas *can_PtL5_os = new TCanvas("can_PtL5_os","can_PtL5_os",800,800);
	hist_PtL5_os->Sumw2();
	hist_PtL5_os->SetMinimum(-10);
	hist_PtL5_os->SetMaximum(6000);
	hist_PtL5_os->Draw("hist");
	hist_PtL5_ls->Sumw2();
	hist_PtL5_ls->Draw("sames,hist");
	hist_PtL5_norm->Sumw2();
	hist_PtL5_norm->Draw("sames,hist");
	TLegend *PtL5_os = new TLegend(0.45, 0.6, 0.7, 0.8);
	PtL5_os->SetHeader("ILD_L5","l");
	PtL5_os->AddEntry(hist_PtL5_os,"#mu^{+}#mu^{-}","l");
	PtL5_os->AddEntry(hist_PtL5_ls,"#mu^{+}#mu^{+}+#mu^{-}#mu^{-}","l");
	PtL5_os->AddEntry(hist_PtL5_norm,"(#mu^{+}#mu^{-})-(#mu^{+}#mu^{+}+#mu^{-}#mu^{-})","l");
	PtL5_os->Draw();
	can_PtL5_os->SaveAs((plots_dir+"test_PtL5.pdf").c_str());
	can_PtL5_os->SaveAs((plots_dir+"test_PtL5.C").c_str());
	can_PtL5_os->SaveAs((plots_dir+"test_PtL5.eps").c_str());

	TCanvas *can_PtCosThetaL5_norm = new TCanvas("can_PtCosThetaL5_norm","can_PtCosThetaL5_norm",1280,1000);
	hist_PtCosThetaL5_norm->Sumw2();
	hist_PtCosThetaL5_norm->SetMaximum(300);
	hist_PtCosThetaL5_norm->SetMinimum(-300);
	hist_PtCosThetaL5_norm->Draw("colz");
	gPad->Update();
	TPaletteAxis *pal_PtCosThetaL5_norm = (TPaletteAxis*)hist_PtCosThetaL5_norm->GetListOfFunctions()->FindObject("palette");
	pal_PtCosThetaL5_norm->SetX1NDC(0.85);
	pal_PtCosThetaL5_norm->SetX2NDC(0.885);
	gPad->SetRightMargin(0.15);
	gPad->Update();
	can_PtCosThetaL5_norm->Modified();
	can_PtCosThetaL5_norm->Update();
	can_PtCosThetaL5_norm->SaveAs((plots_dir+"test_Pt_cosThetaL5.pdf").c_str());
	can_PtCosThetaL5_norm->SaveAs((plots_dir+"test_Pt_cosThetaL5.eps").c_str());
	can_PtCosThetaL5_norm->SaveAs((plots_dir+"test_Pt_cosThetaL5.C").c_str());


	TCanvas *can_InvMassS5_os = new TCanvas("can_InvMassS5_os","can_InvMassS5_os",800,800);
	hist_InvMassS5_os->Sumw2();
	hist_InvMassS5_os->SetMinimum(-600);
	hist_InvMassS5_os->SetMaximum(6000);
	hist_InvMassS5_os->Draw("hist");
	hist_InvMassS5_os->SetMinimum(-600);
	hist_InvMassS5_ls->Sumw2();
	hist_InvMassS5_ls->Draw("sames,hist");
	hist_InvMassS5_norm->Sumw2();
	hist_InvMassS5_norm->Draw("sames,hist");
	TLegend *InvMassS5_os = new TLegend(0.45, 0.6, 0.7, 0.8);
	InvMassS5_os->SetHeader("ILD_S5","l");
	InvMassS5_os->AddEntry(hist_InvMassS5_os,"#mu^{+}#mu^{-}","l");
	InvMassS5_os->AddEntry(hist_InvMassS5_ls,"#mu^{+}#mu^{+}+#mu^{-}#mu^{-}","l");
	InvMassS5_os->AddEntry(hist_InvMassS5_norm,"(#mu^{+}#mu^{-})-(#mu^{+}#mu^{+}+#mu^{-}#mu^{-})","l");
	InvMassS5_os->Draw();
	can_InvMassS5_os->SaveAs((plots_dir+"test_InvMassS5.pdf").c_str());
	can_InvMassS5_os->SaveAs((plots_dir+"test_InvMassS5.eps").c_str());
	can_InvMassS5_os->SaveAs((plots_dir+"test_InvMassS5.C").c_str());

	TCanvas *can_CosThetaS5_os = new TCanvas("can_CosThetaS5_os","can_CosThetaS5_os",800,800);
	hist_CosThetaS5_os->Sumw2();
	hist_CosThetaS5_os->SetMinimum(-10);
	hist_CosThetaS5_os->SetMaximum(3000);
	hist_CosThetaS5_os->Draw("hist");
	hist_CosThetaS5_ls->Sumw2();
	hist_CosThetaS5_ls->Draw("sames,hist");
	hist_CosThetaS5_norm->Sumw2();
	hist_CosThetaS5_norm->Draw("sames,hist");
	TLegend *CosThetaS5_os = new TLegend(0.45, 0.6, 0.7, 0.8);
	CosThetaS5_os->SetHeader("ILD_S5","l");
	CosThetaS5_os->AddEntry(hist_CosThetaS5_os,"#mu^{+}#mu^{-}","l");
	CosThetaS5_os->AddEntry(hist_CosThetaS5_ls,"#mu^{+}#mu^{+}+#mu^{-}#mu^{-}","l");
	CosThetaS5_os->AddEntry(hist_CosThetaS5_norm,"(#mu^{+}#mu^{-})-(#mu^{+}#mu^{+}+#mu^{-}#mu^{-})","l");
	CosThetaS5_os->Draw();
	can_CosThetaS5_os->SaveAs((plots_dir+"test_CosThetaS5.pdf").c_str());
	can_CosThetaS5_os->SaveAs((plots_dir+"test_CosThetaS5.eps").c_str());
	can_CosThetaS5_os->SaveAs((plots_dir+"test_CosThetaS5.C").c_str());

	TCanvas *can_PtS5_os = new TCanvas("can_PtS5_os","can_PtS5_os",800,800);
	hist_PtS5_os->Sumw2();
	hist_PtS5_os->SetMinimum(-10);
	hist_PtS5_os->SetMaximum(6000);
	hist_PtS5_os->Draw("hist");
	hist_PtS5_ls->Sumw2();
	hist_PtS5_ls->Draw("sames,hist");
	hist_PtS5_norm->Sumw2();
	hist_PtS5_norm->Draw("sames,hist");
	TLegend *PtS5_os = new TLegend(0.45, 0.6, 0.7, 0.8);
	PtS5_os->SetHeader("ILD_S5","l");
	PtS5_os->AddEntry(hist_PtS5_os,"#mu^{+}#mu^{-}","l");
	PtS5_os->AddEntry(hist_PtS5_ls,"#mu^{+}#mu^{+}+#mu^{-}#mu^{-}","l");
	PtS5_os->AddEntry(hist_PtS5_norm,"(#mu^{+}#mu^{-})-(#mu^{+}#mu^{+}+#mu^{-}#mu^{-})","l");
	PtS5_os->Draw();
	can_PtS5_os->SaveAs((plots_dir+"test_PtS5.pdf").c_str());
	can_PtS5_os->SaveAs((plots_dir+"test_PtS5.eps").c_str());
	can_PtS5_os->SaveAs((plots_dir+"test_PtS5.C").c_str());

	TCanvas *can_PtCosThetaS5_norm = new TCanvas("can_PtCosThetaS5_os","can_PtCosThetaS5_os",1280,1000);
	hist_PtCosThetaS5_norm->Sumw2();
	hist_PtCosThetaS5_norm->SetMaximum(300);
	hist_PtCosThetaS5_norm->SetMinimum(-300);
	hist_PtCosThetaS5_norm->Draw("colz");
	gPad->Update();
	TPaletteAxis *pal_PtCosThetas5_norm = (TPaletteAxis*)hist_PtCosThetaS5_norm->GetListOfFunctions()->FindObject("palette");
	pal_PtCosThetas5_norm->SetX1NDC(0.85);
	pal_PtCosThetas5_norm->SetX2NDC(0.885);
	gPad->SetRightMargin(0.15);
	gPad->Update();
	can_PtCosThetaS5_norm->Modified();
	can_PtCosThetaS5_norm->Update();
	can_PtCosThetaS5_norm->SaveAs((plots_dir+"test_Pt_cosThetaS5.pdf").c_str());
	can_PtCosThetaS5_norm->SaveAs((plots_dir+"test_Pt_cosThetaS5.eps").c_str());
	can_PtCosThetaS5_norm->SaveAs((plots_dir+"test_Pt_cosThetaS5.C").c_str());
/*
	TCanvas *can_PtCosTheta = new TCanvas("can_PtCosTheta","can_PtCosTheta",1800,1200);
	hist_PtCosThetaMCP_norm->Draw("box");
	hist_PtCosThetaMCP_norm->SetLineColor(1); hist_PtCosThetaMCP_norm->SetLineWidth(1);
	hist_PtCosThetaS5_norm->Draw("same");
	hist_PtCosThetaS5_norm->SetLineColor(4); hist_PtCosThetaS5_norm->SetLineWidth(1);
	hist_PtCosThetaL5_norm->Draw("same");
	hist_PtCosThetaL5_norm->SetLineColor(2); hist_PtCosThetaL5_norm->SetLineWidth(1);

	TLegend *leg_PtCosTheta = new TLegend(0.4,0.6,0.6,0.9);
	leg_PtCosTheta->AddEntry(hist_PtCosThetaMCP_norm,"MCP","l");
	leg_PtCosTheta->AddEntry(hist_PtCosThetaS5_norm,"ILD_s5","l");
	leg_PtCosTheta->AddEntry(hist_PtCosThetaL5_norm,"ILD_l5","l");

	can_PtCosTheta->SaveAs((plots_dir+"PtCosTheta.pdf").c_str());
	can_PtCosTheta->SaveAs((plots_dir+"PtCosTheta.C").c_str());
*/

	TCanvas *can_InvMassS5_vs_l5 = new TCanvas("can_InvMassS5_vs_l5","can_InvMassS5_vs_l5",1200,800);
	//hist_InvMassS5_norm->Sumw2();
	hist_InvMassL5_os->SetMinimum(-600);
	hist_InvMassL5_os->SetMaximum(6000);
	hist_InvMassS5_norm->SetLineColor(2);
	hist_InvMassS5_norm->SetLineStyle(7);
	hist_InvMassS5_norm->Draw("hist");
	//hist_InvMassL5_norm->Sumw2();
	hist_InvMassL5_norm->SetLineColor(4);
	hist_InvMassL5_norm->SetLineStyle(1);
	hist_InvMassL5_norm->Draw("sames,hist");
	TLegend *InvMassS5_vs_l5 = new TLegend(0.51, 0.48, 0.76, 0.68);
	InvMassS5_vs_l5->SetHeader("500 GeV, 4ab^{-1}","l");
	InvMassS5_vs_l5->AddEntry(hist_InvMassS5_norm,"IDR-S","l");
	InvMassS5_vs_l5->AddEntry(hist_InvMassL5_norm,"IDR-L","l");
	InvMassS5_vs_l5->Draw();
        TLatex* text_logo = add_ILD_mark( can_InvMassS5_vs_l5, 3.24, 3696, 0.08);
        TLatex* text_prelim = add_prelim_mark( can_InvMassS5_vs_l5, 3.35, 3696, 0.08);
	can_InvMassS5_vs_l5->SaveAs((plots_dir+"test_InvMassS5_vs_l5.pdf").c_str());
	can_InvMassS5_vs_l5->SaveAs((plots_dir+"test_InvMassS5_vs_l5.eps").c_str());
	can_InvMassS5_vs_l5->SaveAs((plots_dir+"test_InvMassS5_vs_l5.C").c_str());

        TCanvas *can_PtS5_divid = new TCanvas("can_PtS5_divid","can_PtS5_divid",800,800);
	//hist_PtS5_norm->Sumw2();
	hist_PtS5_norm->Divide(hist_PtMCP_norm);
	hist_PtS5_norm->Draw("hist");
	TLegend *PtS5_divid = new TLegend(0.45, 0.6, 0.7, 0.8);
	PtS5_divid->SetHeader("ILD_S5","l");
	PtS5_divid->Draw();
	can_PtS5_divid->SaveAs((plots_dir+"test_PtS5_divid.pdf").c_str());
	can_PtS5_divid->SaveAs((plots_dir+"test_PtS5_divid.eps").c_str());
	can_PtS5_divid->SaveAs((plots_dir+"test_PtS5_divid.C").c_str());

	TCanvas *can_PtL5_divid = new TCanvas("can_PtL5_divid","can_PtL5_divid",800,800);
	//hist_PtL5_norm->Sumw2();
	hist_PtL5_norm->Divide(hist_PtMCP_norm);
	hist_PtL5_norm->Draw("hist");
	TLegend *PtL5_divid = new TLegend(0.45, 0.6, 0.7, 0.8);
	PtL5_divid->SetHeader("ILD_L5","l");
	PtL5_divid->Draw();
	can_PtL5_divid->SaveAs((plots_dir+"test_PtL5_divid.pdf").c_str());
	can_PtL5_divid->SaveAs((plots_dir+"test_PtL5_divid.eps").c_str());
	can_PtL5_divid->SaveAs((plots_dir+"test_PtL5_divid.C").c_str());

	TCanvas *can_PtS5_L5_divid = new TCanvas("can_PtS5_L5_divid","can_PtS5_L5_divid",1200,800);
	hist_PtS5_norm->Draw("E1");
	//hist_PtS5_norm->SetMaximum(200);
	hist_PtS5_norm->SetLineColor(2);hist_PtS5_norm->GetYaxis()->SetTitle("(# J/#psi^{rec})/(# J/#psi^{MC})");
	hist_PtL5_norm->Draw("sames,E1");
	hist_PtL5_norm->SetLineColor(4);
	hist_PtS5_norm->GetXaxis()->SetRangeUser(0,100);
	gPad->Update();
	can_PtS5_L5_divid->Update();
	TLegend *PtS5_L5_divid = new TLegend(0.36, 0.33, 0.61, 0.43);
	PtS5_L5_divid->SetHeader("(# J/#psi^{rec})/(# J/#psi^{MC})","l");
	PtS5_L5_divid->AddEntry(hist_PtS5_norm,"IDR-S","l");
	PtS5_L5_divid->AddEntry(hist_PtL5_norm,"IDR-L","l");
	PtS5_L5_divid->Draw();
	can_PtS5_L5_divid->SaveAs((plots_dir+"test_PtS5_L5_divid.pdf").c_str());
	can_PtS5_L5_divid->SaveAs((plots_dir+"test_PtS5_L5_divid.eps").c_str());
	can_PtS5_L5_divid->SaveAs((plots_dir+"test_PtS5_L5_divid.C").c_str());

}

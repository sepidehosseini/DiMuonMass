using namespace std;
void JpsiPlotter()
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
	

	int nbins_InvMass = 100;
	int nbins_CosTheta = 100;
	int nbins_Pt = 100 ;
	TH1F *hist_InvMassMCP_os = new TH1F("hist_InvMassMCP_os",";m_{#mu^{+}#mu^{-}};No.of J/#psi",nbins_InvMass,2.8,3.8);
	hist_InvMassMCP_os->SetLineWidth(1); hist_InvMassMCP_os->SetLineColor(4);
	hist_InvMassMCP_os->GetYaxis()->SetLabelSize(0.04);

	TH1F *hist_CosThetaMCP_os = new TH1F("hist_CosThetaMCP_os"," ;cos#theta ;No.of J/#psi",nbins_CosTheta,-1.,1.);
	hist_CosThetaMCP_os->SetLineWidth(1); hist_CosThetaMCP_os->SetLineColor(4);
	hist_CosThetaMCP_os->GetYaxis()->SetLabelSize(0.04);
	TH1F *hist_PtMCP_os = new TH1F("hist_PtMCP_os",";p_{t} ;No.of J/#psi",nbins_Pt,0.,150.);
	hist_PtMCP_os->SetLineWidth(1); hist_PtMCP_os->SetLineColor(4);
	hist_PtMCP_os->GetYaxis()->SetLabelSize(0.04);
	TH2F *hist_PtCosThetaMCP_os = new TH2F("hist_PtCosThetaMCP_os"," ;cos#theta ;p_{t} ",nbins_CosTheta,-1.,1.,nbins_Pt,0.,150.); //p_{t} - cos#theta (3.05 < m_{cut} < 3.15);cos#theta;p_{t} [GeV]
	hist_PtCosThetaMCP_os->SetLineWidth(1); hist_PtCosThetaMCP_os->SetLineColor(4);
	hist_PtCosThetaMCP_os->GetYaxis()->SetLabelSize(0.04);
	//hist_PtCosThetaMCP_os->SetLableSize(0.04);



	TH1F *hist_InvMassMCP_ls = new TH1F("hist_InvMassMCP_ls","",nbins_InvMass,2.8,3.8);
	hist_InvMassMCP_ls->SetLineWidth(1); hist_InvMassMCP_ls->SetLineColor(2);
	TH1F *hist_CosThetaMCP_ls = new TH1F("hist_CosThetaMCP_ls","cos#theta (3.05 < m_{cut} < 3.15)",nbins_CosTheta,-1.,1.);
	hist_CosThetaMCP_ls->SetLineWidth(1); hist_CosThetaMCP_ls->SetLineColor(2);
	TH1F *hist_PtMCP_ls = new TH1F("hist_PtMCP_ls","p_{t} (3.05 < m_{cut} < 3.15)",nbins_Pt,0.,150.);
	hist_PtMCP_ls->SetLineWidth(1); hist_PtMCP_ls->SetLineColor(2);
	TH2F *hist_PtCosThetaMCP_ls = new TH2F("hist_PtCosThetaMCP_ls"," ;cos#theta;p_{t} [GeV];cos#theta;p_{t} [GeV]",nbins_CosTheta,-1.,1.,nbins_Pt,0.,150.);
	hist_PtCosThetaMCP_ls->SetLineWidth(1); hist_PtCosThetaMCP_ls->SetLineColor(2);

	TH1F *hist_InvMassMCP_norm = new TH1F("hist_InvMassMCP_norm","m_{#mu^{+}#mu^{-}}",nbins_InvMass,2.8,3.8);
	hist_InvMassMCP_norm->SetLineWidth(1); hist_InvMassMCP_norm->SetLineColor(1);
	TH1F *hist_CosThetaMCP_norm = new TH1F("hist_CosThetaMCP_norm"," ;cos#theta; No. of J/#psi",nbins_CosTheta,-1.,1.);
	hist_CosThetaMCP_norm->SetLineWidth(1); hist_CosThetaMCP_norm->SetLineColor(1);
	TH1F *hist_PtMCP_norm = new TH1F("hist_PtMCP_norm"," ;pt [GeV];No. of J/#psi)",nbins_Pt,0.,150.);
	hist_PtMCP_norm->SetLineWidth(1); hist_PtMCP_norm->SetLineColor(1);
	TH2F *hist_PtCosThetaMCP_norm = new TH2F("hist_PtCosThetaMCP_norm"," ;cos#theta;p_{t} [GeV]",nbins_CosTheta,-1.,1.,nbins_Pt,0.,150.);//p_{t} - cos#theta (3.05 < m_{cut} < 3.15)
	hist_PtCosThetaMCP_norm->SetLineWidth(1); hist_PtCosThetaMCP_norm->SetLineColor(1);
 	hist_PtCosThetaMCP_norm->GetYaxis()->SetLabelSize(0.04);
	for (int i_process=0; i_process<physical_process.size();++i_process)
	{
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

			cout << "N_mcp = " << N_mcp[iter] << ",	xSection_mcp = " << xSection_mcp[iter] << ",	Luminosity = " << Luminosity[iter] << ",	polWeight_mcp = " << polWeight_mcp[iter] << ",	weight_mcp = " << weight_mcp[iter] << endl;
			cout << "N_l5 = " << N_l5[iter] << ",	xSection_l5 = " << xSection_l5[iter] << ",	Luminosity = " << Luminosity[iter] << ",	polWeight_l5 = " << polWeight_l5[iter] << ",	weight_l5 = " << weight_l5[iter] << endl;
			cout << "N_s5 = " << N_s5[iter] << ",	xSection_s5 = " << xSection_s5[iter] << ",	Luminosity = " << Luminosity[iter] << ",	polWeight_s5 = " << polWeight_s5[iter] << ",	weight_s5 = " << weight_s5[iter] << endl;
		}
//			if (m_mcpMuonPDG->size() > 2)
//				cout << i_entry << "	- Number of Muons = " << m_mcpMuonPDG->size() << endl;

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
					if (((m_mcpJpsiInvMass->at(Jpsi_index))<3.15) && ((m_mcpJpsiInvMass->at(Jpsi_index))>3.05))
					{
						hist_CosThetaMCP_os->Fill((m_mcpJpsiCosTheta->at(Jpsi_index)),weight_mcp[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
						hist_PtMCP_os->Fill((m_mcpJpsiPt->at(Jpsi_index)),weight_mcp[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
						hist_PtCosThetaMCP_os->Fill((m_mcpJpsiCosTheta->at(Jpsi_index)),(m_mcpJpsiPt->at(Jpsi_index)),weight_mcp[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
					}
					if ((((m_mcpJpsiInvMass->at(Jpsi_index))<=3.8) && ((m_mcpJpsiInvMass->at(Jpsi_index))>=3.15)) || (((m_mcpJpsiInvMass->at(Jpsi_index))<=3.05) && ((m_mcpJpsiInvMass->at(Jpsi_index))>=2.8)))
						++Num_Jpsis_os;
				}
				if ((m_mcpJpsiCharge->at(Jpsi_index))!=0)
				{
					hist_InvMassMCP_ls->Fill((m_mcpJpsiInvMass->at(Jpsi_index)),weight_mcp[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
					if (((m_mcpJpsiInvMass->at(Jpsi_index))<3.15) && ((m_mcpJpsiInvMass->at(Jpsi_index))>3.05))
					{
						hist_CosThetaMCP_ls->Fill((m_mcpJpsiCosTheta->at(Jpsi_index)),weight_mcp[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
						hist_PtMCP_ls->Fill((m_mcpJpsiPt->at(Jpsi_index)),weight_mcp[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
						hist_PtCosThetaMCP_ls->Fill((m_mcpJpsiCosTheta->at(Jpsi_index)),(m_mcpJpsiPt->at(Jpsi_index)),weight_mcp[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
					}
					if ((((m_mcpJpsiInvMass->at(Jpsi_index))<=3.8) && ((m_mcpJpsiInvMass->at(Jpsi_index))>=3.15)) || (((m_mcpJpsiInvMass->at(Jpsi_index))<=3.05) && ((m_mcpJpsiInvMass->at(Jpsi_index))>=2.8)))
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
					if (((m_mcpJpsiInvMass->at(Jpsi_index))<3.15) && ((m_mcpJpsiInvMass->at(Jpsi_index))>3.05))
					{
						hist_CosThetaMCP_norm->Fill((m_mcpJpsiCosTheta->at(Jpsi_index)),weight_mcp[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
						hist_PtMCP_norm->Fill((m_mcpJpsiPt->at(Jpsi_index)),weight_mcp[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
						hist_PtCosThetaMCP_norm->Fill((m_mcpJpsiCosTheta->at(Jpsi_index)),(m_mcpJpsiPt->at(Jpsi_index)),weight_mcp[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
					}
				}
				if ((m_mcpJpsiCharge->at(Jpsi_index))!=0)
				{
					hist_InvMassMCP_norm->Fill((m_mcpJpsiInvMass->at(Jpsi_index)),-norm * weight_mcp[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
					if (((m_mcpJpsiInvMass->at(Jpsi_index))<3.15) && ((m_mcpJpsiInvMass->at(Jpsi_index))>3.05))
					{
						hist_CosThetaMCP_norm->Fill((m_mcpJpsiCosTheta->at(Jpsi_index)),-norm * weight_mcp[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
						hist_PtMCP_norm->Fill((m_mcpJpsiPt->at(Jpsi_index)),-norm * weight_mcp[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
						hist_PtCosThetaMCP_norm->Fill((m_mcpJpsiCosTheta->at(Jpsi_index)),(m_mcpJpsiPt->at(Jpsi_index)),-norm * weight_mcp[((2*m_polarizatione_l5+m_polarizationp_l5)+3)/2]);
					}
				}
			}
		}
		cout << "Num_Jpsis_os = " << Num_Jpsis_os << endl;
		cout << "Num_Jpsis_ls = " << Num_Jpsis_ls << endl;
		
	}

	TCanvas *can_InvMassMCP_os = new TCanvas("can_InvMassMCP_os","can_InvMassMCP_os",800,800);
	hist_InvMassMCP_os->Draw("hist");
	hist_InvMassMCP_ls->Draw("sames,hist");
	hist_InvMassMCP_norm->Draw("sames,hist");
	TLegend *InvMassMCP_os = new TLegend(0.45, 0.6, 0.7, 0.8);
	InvMassMCP_os->SetHeader("MC","l");
	InvMassMCP_os->AddEntry(hist_InvMassMCP_os,"#mu^{+}#mu^{-}","l");
	InvMassMCP_os->AddEntry(hist_InvMassMCP_ls,"#mu^{+}#mu^{+}+#mu^{-}#mu^{-}","l");
	InvMassMCP_os->AddEntry(hist_InvMassMCP_norm,"(#mu^{+}#mu^{-})-(#mu^{+}#mu^{+}+#mu^{-}#mu^{-})","l");
	InvMassMCP_os->Draw();
	can_InvMassMCP_os->SaveAs((plots_dir+"test_InvMass.pdf").c_str());
	can_InvMassMCP_os->SaveAs((plots_dir+"test_InvMass.C").c_str());
	can_InvMassMCP_os->SaveAs((plots_dir+"test_InvMass.eps").c_str());

	TCanvas *can_CosThetaMCP_os = new TCanvas("can_CosThetaMCP_os","can_CosThetaMCP_os",800,800);
	hist_CosThetaMCP_os->Draw("hist");

	hist_CosThetaMCP_ls->Draw("sames,hist");
	hist_CosThetaMCP_norm->Draw("sames,hist");
	TLegend *CosThetaMCP_os = new TLegend(0.45, 0.6, 0.7, 0.8);
	CosThetaMCP_os->SetHeader("Cos#theta","l");
	CosThetaMCP_os->AddEntry(hist_CosThetaMCP_os,"#mu^{+}#mu^{-}","l");
	CosThetaMCP_os->AddEntry(hist_CosThetaMCP_ls,"#mu^{+}#mu^{+}+#mu^{-}#mu^{-}","l");
	CosThetaMCP_os->AddEntry(hist_CosThetaMCP_norm,"(#mu^{+}#mu^{-})-(#mu^{+}#mu^{+}+#mu^{-}#mu^{-})","l");
	CosThetaMCP_os->Draw();
	can_CosThetaMCP_os->SaveAs((plots_dir+"test_CosTheta.pdf").c_str());
	can_CosThetaMCP_os->SaveAs((plots_dir+"test_CosTheta.C").c_str());
	can_CosThetaMCP_os->SaveAs((plots_dir+"test_CosTheta.eps").c_str());

	TCanvas *can_PtMCP_os = new TCanvas("can_PtMCP_os","can_PtMCP_os",1280,1000);
	hist_PtMCP_os->Draw("hist");
	hist_PtMCP_ls->Draw("sames,hist");
	hist_PtMCP_norm->Draw("sames,hist");
	TLegend *PtMCP_os = new TLegend(0.45, 0.6, 0.7, 0.8);
	PtMCP_os->SetHeader("pt","l");
	PtMCP_os->AddEntry(hist_PtMCP_os,"#mu^{+}#mu^{-}","l");
	PtMCP_os->AddEntry(hist_PtMCP_ls,"#mu^{+}#mu^{+}+#mu^{-}#mu^{-}","l");
	PtMCP_os->AddEntry(hist_PtMCP_norm,"(#mu^{+}#mu^{-})-(#mu^{+}#mu^{+}+#mu^{-}#mu^{-})","l");
	PtMCP_os->Draw();

	can_PtMCP_os->SaveAs((plots_dir+"test_Pt.pdf").c_str());
	can_PtMCP_os->SaveAs((plots_dir+"test_Pt.C").c_str());
	can_PtMCP_os->SaveAs((plots_dir+"test_Pt.eps").c_str());
		
	TCanvas *can_PtCosThetaMCP_os = new TCanvas("can_PtCosThetaMCP_os","can_PtCosThetaMCP_os",800,800);
	hist_PtCosThetaMCP_norm->Draw("colz");
	gPad->Update();
	TPaveStats *tps_PtCosThetaMCP_norm = (TPaveStats*)hist_PtCosThetaMCP_norm->FindObject("stats");
	TPaletteAxis *pal_PtCosThetaMCP_norm = (TPaletteAxis*)hist_PtCosThetaMCP_norm->GetListOfFunctions()->FindObject("palette");
	can_PtCosThetaMCP_os->Update();
	tps_PtCosThetaMCP_norm->SetX1NDC(0.70);
	tps_PtCosThetaMCP_norm->SetY1NDC(0.7);
	tps_PtCosThetaMCP_norm->SetX2NDC(0.8495);
	tps_PtCosThetaMCP_norm->SetY2NDC(0.965);
	pal_PtCosThetaMCP_norm->SetX1NDC(0.85);
	pal_PtCosThetaMCP_norm->SetX2NDC(0.885);
	gPad->SetRightMargin(0.15);
	gPad->Update();
	can_PtCosThetaMCP_os->Modified();
	can_PtCosThetaMCP_os->Update();
	can_PtCosThetaMCP_os->SaveAs((plots_dir+"test_Pt_cosThetaMCP.pdf").c_str());
	can_PtCosThetaMCP_os->SaveAs((plots_dir+"test_Pt_cosThetaMCP.C").c_str());
	can_PtCosThetaMCP_os->SaveAs((plots_dir+"test_Pt_cosThetaMCP.eps").c_str());	




}

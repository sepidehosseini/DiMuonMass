// DiMuonMass Processor
#include "DiMuonMass.h"
#include <iostream>

#include "EVENT/LCCollection.h"
#include "EVENT/MCParticle.h"
#include "EVENT/ReconstructedParticle.h"
#include "marlin/VerbosityLevels.h"

#ifdef MARLIN_USE_AIDA
#include <marlin/AIDAProcessor.h>
#include <AIDA/IHistogramFactory.h>
#include <AIDA/ICloud1D.h>
//#include <AIDA/IHistogram1D.h>
#endif // MARLIN_USE_AIDA

#include "TLorentzVector.h"
#include "TFile.h"
#include "TH1F.h"
#include "TTree.h"
#include <cmath>

using namespace lcio ;
using namespace marlin ;

DiMuonMass aDiMuonMass ;

DiMuonMass::DiMuonMass() :
	Processor("DiMuonMass"),
	m_nRun(0),
	m_nEvt(0),
	m_nRunSum(0),
	m_nEvtSum(0),

	m_crossSection(0.f),
	m_polarizatione(0.f),
	m_polarizationp(0.f),
//	m_PhysicsProcess(NULL),

	m_mcpMuonPDG{},
	m_mcpMuonCharge{},
	m_mcpMuonEnergy{},
	m_mcpMuonPx{},
	m_mcpMuonPy{},
	m_mcpMuonPz{},
	m_mcpMuonPt{},
	m_mcpMuonCosTheta{},

	m_mcpJpsiCharge{},
	m_mcpJpsiEnergy{},
	m_mcpJpsiPx{},
	m_mcpJpsiPy{},
	m_mcpJpsiPz{},
	m_mcpJpsiPt{},
	m_mcpJpsiCosTheta{},
	m_mcpJpsiInvMass{},
	m_mcpMuon1Index{},
	m_mcpMuon2Index{},

	m_pfoMuonPDG{},
	m_pfoMuonCharge{},
	m_pfoMuonEnergy{},
	m_pfoMuonPx{},
	m_pfoMuonPy{},
	m_pfoMuonPz{},
	m_pfoMuonPt{},
	m_pfoMuonCosTheta{},

	m_pfoJpsiCharge{},
	m_pfoJpsiEnergy{},
	m_pfoJpsiPx{},
	m_pfoJpsiPy{},
	m_pfoJpsiPz{},
	m_pfoJpsiPt{},
	m_pfoJpsiCosTheta{},
	m_pfoJpsiInvMass{},
	m_pfoMuon1Index{},
	m_pfoMuon2Index{},


	m_pTFile(NULL),
	m_pTTree(NULL)

{

//	modify processor description
	_description = "DiMuonMass calculates Invariant Mass of DiMuons" ;


//	register steering parameters: name, description, class-variable, default value
	registerInputCollection(	LCIO::MCPARTICLE,
					"MCParticleCollection" ,
					"Name of the MCParticle collection"  ,
					m_mcParticleCollection,
					std::string("MCParticle")
					);

	registerInputCollection(	LCIO::RECONSTRUCTEDPARTICLE,
					"PfoCollection",
					"Name of input pfo collection",
					m_PfoCollection,
					std::string("PandoraPFOs")
					);

	registerProcessorParameter(	"FileName",
					"Name of the output root file",
					m_rootFile,
					std::string()
					);

}



void DiMuonMass::init()
{

	streamlog_out(DEBUG) << "   init called  " << std::endl ;

	// usually a good idea to
	printParameters() ;

	m_nRun = 0 ;
	m_nEvt = 0 ;
	m_nRunSum = 0;
	m_nEvtSum = 0;
	this->Clear();

	m_pTFile = new TFile(m_rootFile.c_str(), "recreate");
	m_pTTree = new TTree("DiMuonMass", "DiMuonMass");
        m_pTTree->SetDirectory(m_pTFile);
        m_pTTree->Branch("run", &m_nRun, "run/I");
        m_pTTree->Branch("event", &m_nEvt, "event/I");
        m_pTTree->Branch("PhysicsProcess", &m_PhysicsProcess);
        m_pTTree->Branch("CrossSection", &m_crossSection, "CrossSection/F");
        m_pTTree->Branch("polarizationElectron", &m_polarizatione, "polarizationElectron/F");
        m_pTTree->Branch("polarizationPositron", &m_polarizationp, "polarizationPositron/F");
        m_pTTree->Branch("nMcpMuons", &m_nMcpMuons, "nMcpMuons/I");
        m_pTTree->Branch("nMcpJpsis", &m_nMcpJpsis, "nMcpJpsis/I");
        m_pTTree->Branch("nMcpJpsisLikeSign", &m_nMcpJpsisLikeSign, "nMcpJpsisLikeSign/I");
        m_pTTree->Branch("nMcpJpsisOppositeSign", &m_nMcpJpsisOppositeSign, "nMcpJpsisOppositeSign/I");
        m_pTTree->Branch("nPfoMuons", &m_nPfoMuons, "nPfoMuons/I");
        m_pTTree->Branch("nPfoJpsis", &m_nPfoJpsis, "nPfoJpsis/I");
        m_pTTree->Branch("nPfoJpsisLikeSign", &m_nPfoJpsisLikeSign, "nPfoJpsisLikeSign/I");
        m_pTTree->Branch("nPfoJpsisOppositeSign", &m_nPfoJpsisOppositeSign, "nPfoJpsisOppositeSign/I");

        m_pTTree->Branch("mcpMuonPDG", &m_mcpMuonPDG);
        m_pTTree->Branch("mcpMuonCharge", &m_mcpMuonCharge);
	m_pTTree->Branch("mcpMuonEnergy", &m_mcpMuonEnergy);
        m_pTTree->Branch("mcpMuonPx", &m_mcpMuonPx);
        m_pTTree->Branch("mcpMuonPy", &m_mcpMuonPy);
        m_pTTree->Branch("mcpMuonPz", &m_mcpMuonPz);
        m_pTTree->Branch("mcpMuonPt", &m_mcpMuonPt);
        m_pTTree->Branch("mcpMuonCosTheta", &m_mcpMuonCosTheta);
        m_pTTree->Branch("mcpJpsiCharge", &m_mcpJpsiCharge);
        m_pTTree->Branch("mcpJpsiEnergy", &m_mcpJpsiEnergy);
        m_pTTree->Branch("mcpJpsiPx", &m_mcpJpsiPx);
        m_pTTree->Branch("mcpJpsiPy", &m_mcpJpsiPy);
        m_pTTree->Branch("mcpJpsiPz", &m_mcpJpsiPz);
        m_pTTree->Branch("mcpJpsiPt", &m_mcpJpsiPt);
        m_pTTree->Branch("mcpJpsiCosTheta", &m_mcpJpsiCosTheta);
        m_pTTree->Branch("mcpJpsiInvMass", &m_mcpJpsiInvMass);
        m_pTTree->Branch("mcpMuon1Index", &m_mcpMuon1Index);
        m_pTTree->Branch("mcpMuon2Index", &m_mcpMuon2Index);

        m_pTTree->Branch("pfoMuonPDG", &m_pfoMuonPDG);
        m_pTTree->Branch("pfoMuonCharge", &m_pfoMuonCharge);
	m_pTTree->Branch("pfoMuonEnergy", &m_pfoMuonEnergy);
        m_pTTree->Branch("pfoMuonPx", &m_pfoMuonPx);
        m_pTTree->Branch("pfoMuonPy", &m_pfoMuonPy);
        m_pTTree->Branch("pfoMuonPz", &m_pfoMuonPz);
        m_pTTree->Branch("pfoMuonPt", &m_pfoMuonPt);
        m_pTTree->Branch("pfoMuonCosTheta", &m_pfoMuonCosTheta);
        m_pTTree->Branch("pfoJpsiCharge", &m_pfoJpsiCharge);
        m_pTTree->Branch("pfoJpsiEnergy", &m_pfoJpsiEnergy);
        m_pTTree->Branch("pfoJpsiPx", &m_pfoJpsiPx);
        m_pTTree->Branch("pfoJpsiPy", &m_pfoJpsiPy);
        m_pTTree->Branch("pfoJpsiPz", &m_pfoJpsiPz);
        m_pTTree->Branch("pfoJpsiPt", &m_pfoJpsiPt);
        m_pTTree->Branch("pfoJpsiCosTheta", &m_pfoJpsiCosTheta);
        m_pTTree->Branch("pfoJpsiInvMass", &m_pfoJpsiInvMass);
        m_pTTree->Branch("pfoMuon1Index", &m_pfoMuon1Index);
        m_pTTree->Branch("pfoMuon2Index", &m_pfoMuon2Index);


}

void DiMuonMass::processRunHeader( LCRunHeader *pLCRunHeader)
{
	m_nRun = 0;
	m_nEvt = 0;
	++m_nRunSum;

//	m_nRun++ ;
}


void DiMuonMass::processEvent( LCEvent *pLCEvent )
{

	m_nRun = pLCEvent->getRunNumber();
	m_nEvt = pLCEvent->getEventNumber();
	++m_nEvtSum;

	if ((m_nEvtSum % 100) == 0)
	std::cout << " processed events: " << m_nEvtSum << std::endl;

	this->Clear();
	this->ExtractCollections(pLCEvent);
	this->InvariantMass(pLCEvent);
	m_pTTree->Fill();
}

void DiMuonMass::check( LCEvent *pLCEvent )
{
//	nothing to check here - could be used to fill checkplots in reconstruction processor
}


void DiMuonMass::end()
{

	m_pTFile->cd();
	m_pTTree->Write();
	m_pTFile->Close();
	delete m_pTFile;

//	std::cout << "MySLDecayFinder::end()  " << name()
//	<< " processed " << _nEvt << " events in " << _nRun << " runs "
//	<< std::endl ;

}

void DiMuonMass::Clear()
{
	m_PhysicsProcess = "";
	m_crossSection = 0.f;
	m_polarizatione = 0;
	m_polarizationp = 0;

	m_nMcpMuons = 0;
	m_nMcpJpsis = 0;
	m_nMcpJpsisLikeSign = 0;
	m_nMcpJpsisOppositeSign = 0;
	m_nPfoMuons = 0;
	m_nPfoJpsis = 0;
	m_nPfoJpsisLikeSign = 0;
	m_nPfoJpsisOppositeSign = 0;

	m_mcpMuonPDG = {};
	m_mcpMuonCharge = {};
	m_mcpMuonEnergy = {};
	m_mcpMuonPx = {};
	m_mcpMuonPy = {};
	m_mcpMuonPz = {};
	m_mcpMuonPt = {};
	m_mcpMuonCosTheta = {};

	m_mcpJpsiCharge = {};
	m_mcpJpsiEnergy = {};
	m_mcpJpsiPx = {};
	m_mcpJpsiPy = {};
	m_mcpJpsiPz = {};
	m_mcpJpsiPt = {};
	m_mcpJpsiCosTheta = {};
	m_mcpJpsiInvMass = {};
	m_mcpMuon1Index = {};
	m_mcpMuon2Index = {};

	m_pfoMuonPDG = {};
	m_pfoMuonCharge = {};
	m_pfoMuonEnergy = {};
	m_pfoMuonPx = {};
	m_pfoMuonPy = {};
	m_pfoMuonPz = {};
	m_pfoMuonPt = {};
	m_pfoMuonCosTheta = {};

	m_pfoJpsiCharge = {};
	m_pfoJpsiEnergy = {};
	m_pfoJpsiPx = {};
	m_pfoJpsiPy = {};
	m_pfoJpsiPz = {};
	m_pfoJpsiPt = {};
	m_pfoJpsiCosTheta = {};
	m_pfoJpsiInvMass = {};
	m_pfoMuon1Index = {};
	m_pfoMuon2Index = {};

}

void DiMuonMass::ExtractCollections(EVENT::LCEvent *pLCEvent)
{
	try
	{
		const EVENT::LCCollection *pLCCollection = pLCEvent->getCollection(m_mcParticleCollection);

		for (unsigned int i = 0, nElements = pLCCollection->getNumberOfElements(); i < nElements; ++i)
		{
			const EVENT::MCParticle *pMCParticle = dynamic_cast<EVENT::MCParticle*>(pLCCollection->getElementAt(i));

			if (NULL == pMCParticle)
				throw EVENT::Exception("Collection type mismatch");

			if (!pMCParticle->getParents().empty())
				continue;

		}
	}
	catch (...)
	{
		streamlog_out(WARNING) << "Could not extract mc particle collection " << m_mcParticleCollection << std::endl;
	}

	try
	{
		const EVENT::LCCollection *pLCCollection = pLCEvent->getCollection(m_PfoCollection);

		for (unsigned int i = 0, nElements = pLCCollection->getNumberOfElements(); i < nElements; ++i)
		{
			const EVENT::ReconstructedParticle *pReconstructedParticle = dynamic_cast<EVENT::ReconstructedParticle*>(pLCCollection->getElementAt(i));

			if (NULL == pReconstructedParticle)
				throw EVENT::Exception("Collection type mismatch");

		}
	}
	catch (...)
	{
		streamlog_out(ERROR) << "Could not extract input particle collection: " << m_PfoCollection << std::endl;
	}
}

void DiMuonMass::InvariantMass(EVENT::LCEvent *pLCEvent)
{
	try
	{
		int FirstMuonIndex = 0;
		int SecondMuonIndex = 0;
		const EVENT::LCCollection *pLCCollection = pLCEvent->getCollection(m_mcParticleCollection);
		m_crossSection = pLCEvent->getParameters().getFloatVal("crossSection");
		m_PhysicsProcess = pLCEvent->getParameters().getStringVal("processName");
		m_polarizatione = pLCEvent->getParameters().getFloatVal("Pol0");
		m_polarizationp = pLCEvent->getParameters().getFloatVal("Pol1");
		int nElements = pLCCollection->getNumberOfElements();
		for (int i = 0; i < nElements; ++i)
		{
			const EVENT::MCParticle *pMCParticle1 = dynamic_cast<EVENT::MCParticle*>(pLCCollection->getElementAt(i));
			if ((std::abs(pMCParticle1->getPDG()) == 13) && (pMCParticle1->getGeneratorStatus() == 1))
			{
				++m_nMcpMuons;
				FirstMuonIndex = m_nMcpMuons;
				SecondMuonIndex = m_nMcpMuons;
				TLorentzVector mcpMuon1_tlv = TLorentzVector(pMCParticle1->getMomentum(),pMCParticle1->getEnergy());
				m_mcpMuonPDG.push_back(pMCParticle1->getPDG());
				m_mcpMuonCharge.push_back(pMCParticle1->getCharge());
				m_mcpMuonEnergy.push_back(mcpMuon1_tlv.E());
				m_mcpMuonPx.push_back(mcpMuon1_tlv.Px());
				m_mcpMuonPy.push_back(mcpMuon1_tlv.Py());
				m_mcpMuonPz.push_back(mcpMuon1_tlv.Pz());
				m_mcpMuonPt.push_back(std::sqrt(std::pow(mcpMuon1_tlv.Px(),2)+std::pow(mcpMuon1_tlv.Py(),2)));
				m_mcpMuonCosTheta.push_back(mcpMuon1_tlv.CosTheta());
				for (int j = i+1; j < nElements; ++j)
				{
					const EVENT::MCParticle *pMCParticle2 = dynamic_cast<EVENT::MCParticle*>(pLCCollection->getElementAt(j));
					if ((std::abs(pMCParticle2->getPDG()) == 13) && (pMCParticle2->getGeneratorStatus() == 1))
					{
						++SecondMuonIndex;
						m_mcpMuon1Index.push_back(FirstMuonIndex);
						m_mcpMuon2Index.push_back(SecondMuonIndex);
						int JpsiCharge = pMCParticle1->getCharge() + pMCParticle2->getCharge();
						m_mcpJpsiCharge.push_back(JpsiCharge);
						++m_nMcpJpsis;
						if (JpsiCharge == 0)
						{
							++m_nMcpJpsisOppositeSign;
						}
						if (std::abs(JpsiCharge) == 2)
						{
							++m_nMcpJpsisLikeSign;
						}
							
						TLorentzVector mcpMuon2_tlv = TLorentzVector(pMCParticle2->getMomentum(),pMCParticle2->getEnergy());
						TLorentzVector mcpJpsi_tlv = mcpMuon1_tlv + mcpMuon2_tlv;
						m_mcpJpsiEnergy.push_back(mcpJpsi_tlv.E());
						m_mcpJpsiPx.push_back(mcpJpsi_tlv.Px());
						m_mcpJpsiPy.push_back(mcpJpsi_tlv.Py());
						m_mcpJpsiPz.push_back(mcpJpsi_tlv.Pz());
						m_mcpJpsiPt.push_back(std::sqrt(std::pow(mcpJpsi_tlv.Px(),2)+std::pow(mcpJpsi_tlv.Py(),2)));
						m_mcpJpsiCosTheta.push_back(mcpJpsi_tlv.CosTheta());
						m_mcpJpsiInvMass.push_back(mcpJpsi_tlv.M());
					}
				}
			}
		}
	}
	catch (...)
	{
		streamlog_out(WARNING) << "Could not extract input particle collection: " << m_mcParticleCollection << std::endl;
	}

	try
	{
		int FirstMuonIndex = 0;
		int SecondMuonIndex = 0;
		const EVENT::LCCollection *pLCCollection = pLCEvent->getCollection(m_PfoCollection);
		int nElements = pLCCollection->getNumberOfElements();
		for (int i = 0; i < nElements; ++i)
		{
			const EVENT::ReconstructedParticle *pPFO1 = dynamic_cast<EVENT::ReconstructedParticle*>(pLCCollection->getElementAt(i));
			if (std::abs(pPFO1->getType()) == 13)
			{
				++m_nPfoMuons;
				FirstMuonIndex = m_nPfoMuons;
				SecondMuonIndex = m_nPfoMuons;
				TLorentzVector pfoMuon1_tlv = TLorentzVector(pPFO1->getMomentum(),pPFO1->getEnergy());
				m_pfoMuonPDG.push_back(pPFO1->getType());
				m_pfoMuonCharge.push_back(pPFO1->getCharge());
				m_pfoMuonEnergy.push_back(pfoMuon1_tlv.E());
				m_pfoMuonPx.push_back(pfoMuon1_tlv.Px());
				m_pfoMuonPy.push_back(pfoMuon1_tlv.Py());
				m_pfoMuonPz.push_back(pfoMuon1_tlv.Pz());
				m_pfoMuonPt.push_back(std::sqrt(std::pow(pfoMuon1_tlv.Px(),2)+std::pow(pfoMuon1_tlv.Py(),2)));
				m_pfoMuonCosTheta.push_back(pfoMuon1_tlv.CosTheta());
				for (int j = i+1; j < nElements; ++j)
				{
					const EVENT::ReconstructedParticle *pPFO2 = dynamic_cast<EVENT::ReconstructedParticle*>(pLCCollection->getElementAt(j));
					if (std::abs(pPFO2->getType()) == 13)
					{
						++SecondMuonIndex;
						m_pfoMuon1Index.push_back(FirstMuonIndex);
						m_pfoMuon2Index.push_back(SecondMuonIndex);

						float JpsiCharge = pPFO1->getCharge() + pPFO2->getCharge();
						m_pfoJpsiCharge.push_back(JpsiCharge);
						if (JpsiCharge == 0)
						{
							++m_nPfoJpsisOppositeSign;
						}
						else
						{
							++m_nPfoJpsisLikeSign;
						}
							
						TLorentzVector pfoMuon2_tlv = TLorentzVector(pPFO2->getMomentum(),pPFO2->getEnergy());
						TLorentzVector pfoJpsi_tlv = pfoMuon1_tlv + pfoMuon2_tlv;
						m_pfoJpsiEnergy.push_back(pfoJpsi_tlv.E());
						m_pfoJpsiPx.push_back(pfoJpsi_tlv.Px());
						m_pfoJpsiPy.push_back(pfoJpsi_tlv.Py());
						m_pfoJpsiPz.push_back(pfoJpsi_tlv.Pz());
						m_pfoJpsiPt.push_back(std::sqrt(std::pow(pfoJpsi_tlv.Px(),2)+std::pow(pfoJpsi_tlv.Py(),2)));
						m_pfoJpsiCosTheta.push_back(pfoJpsi_tlv.CosTheta());
						m_pfoJpsiInvMass.push_back(pfoJpsi_tlv.M());
						++m_nPfoJpsis;
					}
				}
			}
		}
	}
	catch (...)
	{
		streamlog_out(WARNING) << "Could not extract input particle collection: " << m_PfoCollection << std::endl;
	}

}

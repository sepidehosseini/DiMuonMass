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
	m_polarizaione(0.f),
	m_polarizaionp(0.f),
/*
	m_mcpPDG1(0),
	m_mcpPDG2(0),
	m_mcpCosTheta1(0.f),
	m_mcpCosTheta2(0.f),
	m_mcpMomentum1(0.f),
	m_mcpMomentum2(0.f),
	m_mcpPt1(0.f),
	m_mcpPt2(0.f),

	m_mcpInvMass(0.f),
	m_mcpCosTheta(0.f),
	m_mcpMomentum(0.f),
	m_mcpPt(0.f),
        
	m_pfoPDG1(0),
	m_pfoPDG2(0),
	m_pfoCosTheta1(0.f),
	m_pfoCosTheta2(0.f),
	m_pfoMomentum1(0.f),
	m_pfoMomentum2(0.f),
	m_pfoPt1(0.f),
	m_pfoPt2(0.f),

	m_pfoInvMass(0.f),
	m_pfoCosTheta(0.f),
	m_pfoMomentum(0.f),
	m_pfoPt(0.f),
  */      
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
        m_pTTree->Branch("CrossSection", &m_crossSection, "CrossSection/F");
        m_pTTree->Branch("polarizaionElectron", &m_polarizaione, "polarizaionElectron/F");
        m_pTTree->Branch("polarizaionPositron", &m_polarizaionp, "polarizaionPositron/F");

        m_pTTree->Branch("mcpPDG1", &m_mcpPDG1);
        m_pTTree->Branch("mcpPDG2", &m_mcpPDG2);
        m_pTTree->Branch("mcpCosTheta1", &m_mcpCosTheta1);
        m_pTTree->Branch("mcpCosTheta2", &m_mcpCosTheta2);
        m_pTTree->Branch("mcpPx1", &m_mcpPx1);
        m_pTTree->Branch("mcpPx2", &m_mcpPx2);
        m_pTTree->Branch("mcpPy1", &m_mcpPy1);
        m_pTTree->Branch("mcpPy2", &m_mcpPy2);
        m_pTTree->Branch("mcpPz1", &m_mcpPz1);
        m_pTTree->Branch("mcpPz2", &m_mcpPz2);
        m_pTTree->Branch("mcpInvMass", &m_mcpInvMass);
        m_pTTree->Branch("mcpCosTheta", &m_mcpCosTheta);
        m_pTTree->Branch("mcpMomentum", &m_mcpMomentum);
        m_pTTree->Branch("mcpPt", &m_mcpPt);

        m_pTTree->Branch("pfoPDG1", &m_pfoPDG1);
        m_pTTree->Branch("pfoPDG2", &m_pfoPDG2);
        m_pTTree->Branch("pfoCosTheta1", &m_pfoCosTheta1);
        m_pTTree->Branch("pfoCosTheta2", &m_pfoCosTheta2);
        m_pTTree->Branch("pfoPx1", &m_pfoPx1);
        m_pTTree->Branch("pfoPx2", &m_pfoPx2);
        m_pTTree->Branch("pfoPy1", &m_pfoPy1);
        m_pTTree->Branch("pfoPy2", &m_pfoPy2);
        m_pTTree->Branch("pfoPz1", &m_pfoPz1);
        m_pTTree->Branch("pfoPz2", &m_pfoPz2);
        m_pTTree->Branch("pfoInvMass", &m_pfoInvMass);
        m_pTTree->Branch("pfoCosTheta", &m_pfoCosTheta);
        m_pTTree->Branch("pfoMomentum", &m_pfoMomentum);
        m_pTTree->Branch("pfoPt", &m_pfoPt);


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

	m_crossSection = 0.f;
	m_polarizaione = 0;
	m_polarizaionp = 0;

	m_mcpPDG1.clear();
	m_mcpPDG2.clear();
	m_mcpCosTheta1.clear();
	m_mcpCosTheta2.clear();
	m_mcpPx1.clear();
	m_mcpPx2.clear();
	m_mcpPy1.clear();
	m_mcpPy2.clear();
	m_mcpPz1.clear();
	m_mcpPz2.clear();

	m_mcpInvMass.clear();
	m_mcpCosTheta.clear();
	m_mcpMomentum.clear();
	m_mcpPt.clear();
        
	m_pfoPDG1.clear();
	m_pfoPDG2.clear();
	m_pfoCosTheta1.clear();
	m_pfoCosTheta2.clear();
	m_pfoPx1.clear();
	m_pfoPx2.clear();
	m_pfoPy1.clear();
	m_pfoPy2.clear();
	m_pfoPz1.clear();
	m_pfoPz2.clear();

	m_pfoInvMass.clear();
	m_pfoCosTheta.clear();
	m_pfoMomentum.clear();
	m_pfoPt.clear();

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
		const EVENT::LCCollection *pLCCollection = pLCEvent->getCollection(m_mcParticleCollection);
		m_crossSection = pLCEvent->getParameters().getFloatVal("crossSection");
		m_polarizaione = pLCEvent->getParameters().getFloatVal("Pol0");
		m_polarizaionp = pLCEvent->getParameters().getFloatVal("Pol1");
		for (unsigned int i = 0, nElements = pLCCollection->getNumberOfElements(); i < nElements; ++i)
		{
			const EVENT::MCParticle *pMCParticle1 = dynamic_cast<EVENT::MCParticle*>(pLCCollection->getElementAt(i));
			if ((std::abs(pMCParticle1->getPDG()) == 13) && (pMCParticle1->getGeneratorStatus() == 1))
			{
				for (unsigned int j = i+1, nElements = pLCCollection->getNumberOfElements(); j < nElements; ++j)
				{
					const EVENT::MCParticle *pMCParticle2 = dynamic_cast<EVENT::MCParticle*>(pLCCollection->getElementAt(j));
					if ((std::abs(pMCParticle2->getPDG()) == 13) && (pMCParticle2->getGeneratorStatus() == 1))
					{
						TLorentzVector MCP_tlv_1 = TLorentzVector(pMCParticle1->getMomentum(),pMCParticle1->getEnergy());
						TLorentzVector MCP_tlv_2 = TLorentzVector(pMCParticle2->getMomentum(),pMCParticle2->getEnergy());
						TLorentzVector MCP_tlv = MCP_tlv_1 + MCP_tlv_2;
						m_mcpPDG1.push_back(pMCParticle1->getPDG());
						m_mcpPDG2.push_back(pMCParticle2->getPDG());
						m_mcpCosTheta1.push_back(MCP_tlv_1.CosTheta());
						m_mcpCosTheta2.push_back(MCP_tlv_2.CosTheta());
						m_mcpPx1.push_back(MCP_tlv_1.Px());
						m_mcpPx2.push_back(MCP_tlv_2.Px());
						m_mcpPy1.push_back(MCP_tlv_1.Py());
						m_mcpPy2.push_back(MCP_tlv_2.Py());
						m_mcpPz1.push_back(MCP_tlv_1.Pz());
						m_mcpPz2.push_back(MCP_tlv_2.Pz());
						m_mcpInvMass.push_back(MCP_tlv.M());
						m_mcpCosTheta.push_back(MCP_tlv.CosTheta());
						m_mcpMomentum.push_back(std::sqrt(MCP_tlv.Px()*MCP_tlv.Px()+MCP_tlv.Py()*MCP_tlv.Py()+MCP_tlv.Pz()*MCP_tlv.Pz()));
						m_mcpPt.push_back(std::sqrt(MCP_tlv.Px()*MCP_tlv.Px()+MCP_tlv.Py()*MCP_tlv.Py()));
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
		const EVENT::LCCollection *pLCCollection = pLCEvent->getCollection(m_PfoCollection);
		for (unsigned int i = 0, nElements = pLCCollection->getNumberOfElements(); i < nElements; ++i)
		{
			const EVENT::ReconstructedParticle *pPFO1 = dynamic_cast<EVENT::ReconstructedParticle*>(pLCCollection->getElementAt(i));
			if (std::abs(pPFO1->getType()) == 13)
			{
				for (unsigned int j = i+1, nElements = pLCCollection->getNumberOfElements(); j < nElements; ++j)
				{
					const EVENT::ReconstructedParticle *pPFO2 = dynamic_cast<EVENT::ReconstructedParticle*>(pLCCollection->getElementAt(j));
					if (std::abs(pPFO2->getType()) == 13)
					{
						TLorentzVector PFO_tlv_1 = TLorentzVector(pPFO1->getMomentum(),pPFO1->getEnergy());
						TLorentzVector PFO_tlv_2 = TLorentzVector(pPFO2->getMomentum(),pPFO2->getEnergy());
						TLorentzVector PFO_tlv = PFO_tlv_1 + PFO_tlv_2;
						m_pfoPDG1.push_back(pPFO1->getType());
						m_pfoPDG2.push_back(pPFO2->getType());
						m_pfoCosTheta1.push_back(PFO_tlv_1.CosTheta());
						m_pfoCosTheta2.push_back(PFO_tlv_2.CosTheta());
						m_pfoPx1.push_back(PFO_tlv_1.Px());
						m_pfoPx2.push_back(PFO_tlv_2.Px());
						m_pfoPy1.push_back(PFO_tlv_1.Py());
						m_pfoPy2.push_back(PFO_tlv_2.Py());
						m_pfoPz1.push_back(PFO_tlv_1.Pz());
						m_pfoPz2.push_back(PFO_tlv_2.Pz());
						m_pfoInvMass.push_back(PFO_tlv.M());
						m_pfoCosTheta.push_back(PFO_tlv.CosTheta());
						m_pfoMomentum.push_back(std::sqrt(PFO_tlv.Px()*PFO_tlv.Px()+PFO_tlv.Py()*PFO_tlv.Py()+PFO_tlv.Pz()*PFO_tlv.Pz()));
						m_pfoPt.push_back(std::sqrt(PFO_tlv.Px()*PFO_tlv.Px()+PFO_tlv.Py()*PFO_tlv.Py()));
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

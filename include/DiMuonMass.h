// DiMuonMass header
#ifndef DiMuonMass_h
#define DiMuonMass_h 1

#include "EVENT/LCStrVec.h"
#include <EVENT/MCParticle.h>
#include "IMPL/LCCollectionVec.h"
#include "marlin/Processor.h"
#include "lcio.h"
#include <string>
#include <vector>
#include <math.h>
//#include "CalibrationHelper.h"

#include <set>
#include <vector>

class TFile;
class TH1F;
class TTree;

using namespace lcio ;
using namespace marlin ;

class DiMuonMass : public Processor
{

	public:

		virtual Processor*  newProcessor() { return new DiMuonMass ; }


		DiMuonMass() ;

		/*
		* Called at the begin of the job before anything is read.
		* Use to initialize the processor, e.g. book histograms.
		*/
		virtual void init() ;

		/*
		* Called for every run.
		*/
		virtual void processRunHeader( lcio::LCRunHeader *pLCRunHeader ) ;

		/*
		* Called for every event - the working horse.
		*/
		virtual void processEvent( EVENT::LCEvent *pLCEvent ) ;


		virtual void check( EVENT::LCEvent *pLCEvent ) ;

	private:

		void Clear();

		void ExtractCollections(EVENT::LCEvent *pLCEvent);

		void InvariantMass(EVENT::LCEvent *pLCEvent);

		/*
		* Called after data processing for clean up.
		*/
		virtual void end() ;


//	protected:

		/*
		* Input collection name.
		*/
		std::string			m_mcParticleCollection{} ;
		std::string			m_PfoCollection{};
		std::string			m_rootFile{};

		int				m_nRun{} ;
		int				m_nEvt{} ;
		int				m_nRunSum{};
		int				m_nEvtSum{};

		float				m_crossSection;
		float				m_polarizatione;
		float				m_polarizationp;

		int			m_mcpPDG1;
		int			m_mcpPDG2;
		
		float			m_mcpCosTheta1;
		float			m_mcpCosTheta2;
		float			m_mcpPx1;
		float			m_mcpPx2;
		float			m_mcpPy1;
		float			m_mcpPy2;
		float			m_mcpPz1;
		float			m_mcpPz2;
		float			m_mcpInvMass;
		float			m_mcpCosTheta;
		float			m_mcpMomentum;
		float			m_mcpPt;

		int			m_pfoPDG1;
		int			m_pfoPDG2;
		float			m_pfoCosTheta1;
		float			m_pfoCosTheta2;
		float			m_pfoPx1;
		float			m_pfoPx2;
		float			m_pfoPy1;
		float			m_pfoPy2;
		float			m_pfoPz1;
		float			m_pfoPz2;
		float			m_pfoInvMass;
		float			m_pfoCosTheta;
		float			m_pfoMomentum;
		float			m_pfoPt;


		TFile				*m_pTFile{};
		TTree				*m_pTTree{};

};

#endif

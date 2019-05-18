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
		float				m_polarizaione;
		float				m_polarizaionp;

		typedef std::vector<int> IntVector;
		
		IntVector			m_mcpPDG1{};
		IntVector			m_mcpPDG2{};

		typedef std::vector<float> FloatVector;
		
		FloatVector			m_mcpCosTheta1{};
		FloatVector			m_mcpCosTheta2{};
		FloatVector			m_mcpPx1{};
		FloatVector			m_mcpPx2{};
		FloatVector			m_mcpPy1{};
		FloatVector			m_mcpPy2{};
		FloatVector			m_mcpPz1{};
		FloatVector			m_mcpPz2{};
		FloatVector			m_mcpInvMass{};
		FloatVector			m_mcpCosTheta{};
		FloatVector			m_mcpMomentum{};
		FloatVector			m_mcpPt{};

		IntVector			m_pfoPDG1{};
		IntVector			m_pfoPDG2{};
		FloatVector			m_pfoCosTheta1{};
		FloatVector			m_pfoCosTheta2{};
		FloatVector			m_pfoPx1{};
		FloatVector			m_pfoPx2{};
		FloatVector			m_pfoPy1{};
		FloatVector			m_pfoPy2{};
		FloatVector			m_pfoPz1{};
		FloatVector			m_pfoPz2{};
		FloatVector			m_pfoInvMass{};
		FloatVector			m_pfoCosTheta{};
		FloatVector			m_pfoMomentum{};
		FloatVector			m_pfoPt{};


		TFile				*m_pTFile{};
		TTree				*m_pTTree{};

};

#endif

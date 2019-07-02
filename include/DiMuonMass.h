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

const int nMcpMuons_Max = 50;
const int nMcpJpsis_Max = 500;
const int nPfoMuons_Max = 50;
const int nPfoJpsis_Max = 500;


using namespace std ;
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
		std::string			m_PhysicsProcess{};
		float				m_crossSection;
		float				m_polarizatione;
		float				m_polarizationp;
		int				m_nMcpMuons{} ;
		int				m_nMcpJpsis{} ;
		int				m_nMcpJpsisLikeSign{} ;
		int				m_nMcpJpsisOppositeSign{} ;
		int				m_nPfoMuons{} ;
		int				m_nPfoJpsis{} ;
		int				m_nPfoJpsisLikeSign{} ;
		int				m_nPfoJpsisOppositeSign{} ;

		typedef std::vector<float> FloatVector;
		typedef std::vector<int> IntVector;

		IntVector	 		m_mcpMuonPDG;
		FloatVector	 		m_mcpMuonCharge;
		FloatVector			m_mcpMuonEnergy;
		FloatVector			m_mcpMuonPx;
		FloatVector			m_mcpMuonPy;
		FloatVector			m_mcpMuonPz;
		FloatVector			m_mcpMuonPt;
		FloatVector			m_mcpMuonCosTheta;

		FloatVector			m_mcpJpsiCharge;
		FloatVector			m_mcpJpsiEnergy;
		FloatVector			m_mcpJpsiPx;
		FloatVector			m_mcpJpsiPy;
		FloatVector			m_mcpJpsiPz;
		FloatVector			m_mcpJpsiPt;
		FloatVector			m_mcpJpsiCosTheta;
		FloatVector			m_mcpJpsiInvMass;
		IntVector			m_mcpMuon1Index;
		IntVector			m_mcpMuon2Index;

		IntVector	 		m_pfoMuonPDG;
		FloatVector	 		m_pfoMuonCharge;
		FloatVector			m_pfoMuonEnergy;
		FloatVector			m_pfoMuonPx;
		FloatVector			m_pfoMuonPy;
		FloatVector			m_pfoMuonPz;
		FloatVector			m_pfoMuonPt;
		FloatVector			m_pfoMuonCosTheta;

		FloatVector			m_pfoJpsiCharge;
		FloatVector			m_pfoJpsiEnergy;
		FloatVector			m_pfoJpsiPx;
		FloatVector			m_pfoJpsiPy;
		FloatVector			m_pfoJpsiPz;
		FloatVector			m_pfoJpsiPt;
		FloatVector			m_pfoJpsiCosTheta;
		FloatVector			m_pfoJpsiInvMass;
		IntVector			m_pfoMuon1Index;
		IntVector			m_pfoMuon2Index;

/*
		int	 		m_mcpMuonPDG[nMcpMuons_Max];
		float	 		m_mcpMuonCharge[nMcpMuons_Max];
		float			m_mcpMuonEnergy[nMcpMuons_Max];
		float			m_mcpMuonPx[nMcpMuons_Max];
		float			m_mcpMuonPy[nMcpMuons_Max];
		float			m_mcpMuonPz[nMcpMuons_Max];
		float			m_mcpMuonPt[nMcpMuons_Max];
		float			m_mcpMuonCosTheta[nMcpMuons_Max];

		float			m_mcpJpsiCharge[nMcpJpsis_Max];
		float			m_mcpJpsiEnergy[nMcpJpsis_Max];
		float			m_mcpJpsiPx[nMcpJpsis_Max];
		float			m_mcpJpsiPy[nMcpJpsis_Max];
		float			m_mcpJpsiPz[nMcpJpsis_Max];
		float			m_mcpJpsiPt[nMcpJpsis_Max];
		float			m_mcpJpsiCosTheta[nMcpJpsis_Max];
		float			m_mcpJpsiInvMass[nMcpJpsis_Max];
		int			m_mcpMuon1Index[nMcpJpsis_Max];
		int			m_mcpMuon2Index[nMcpJpsis_Max];

		int	 		m_pfoMuonPDG[nPfoMuons_Max];
		float	 		m_pfoMuonCharge[nPfoMuons_Max];
		float			m_pfoMuonEnergy[nPfoMuons_Max];
		float			m_pfoMuonPx[nPfoMuons_Max];
		float			m_pfoMuonPy[nPfoMuons_Max];
		float			m_pfoMuonPz[nPfoMuons_Max];
		float			m_pfoMuonPt[nPfoMuons_Max];
		float			m_pfoMuonCosTheta[nPfoMuons_Max];

		float			m_pfoJpsiCharge[nPfoJpsis_Max];
		float			m_pfoJpsiEnergy[nPfoJpsis_Max];
		float			m_pfoJpsiPx[nPfoJpsis_Max];
		float			m_pfoJpsiPy[nPfoJpsis_Max];
		float			m_pfoJpsiPz[nPfoJpsis_Max];
		float			m_pfoJpsiPt[nPfoJpsis_Max];
		float			m_pfoJpsiCosTheta[nPfoJpsis_Max];
		float			m_pfoJpsiInvMass[nPfoJpsis_Max];
		int			m_pfoMuon1Index[nPfoJpsis_Max];
		int			m_pfoMuon2Index[nPfoJpsis_Max];
*/

		TFile				*m_pTFile{};
		TTree				*m_pTTree{};


};

#endif

//----------------------------------------------------------------------------------------------------| FunktionWin.cpp von Dietmar Schrausser 2009    
//
#include "stdafx.h"
#include "FunktionWin.h"
#include "FunktionWinDlg.h"
#include "FW_INF.h"
#include "FW_FISHERZ.h"
#include "process.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


BEGIN_MESSAGE_MAP(CFunktionWinApp, CWinApp)
	//{{AFX_MSG_MAP(CFunktionWinApp)
	ON_COMMAND(ID_PROGRAMM_INFO, OnProgrammInfo)
	ON_COMMAND(ID_PROGRAMM_BEENDEN, OnProgrammBeenden)
	ON_WM_SYSCOMMAND()
	ON_COMMAND(ID_TRANSFORMATIONEN_FISHERZFUNKTION, OnTransformationenFisherzfunktion)
	ON_COMMAND(ID_VERTEILUNGSFUNKTIONEN_NORMALVERTEILUNGSFUNKTION, OnVerteilungsfunktionenNormalverteilungsfunktion)
	ON_COMMAND(ID_TRANSFORMATIONEN_GAMMA, OnTransformationenGamma)
	ON_COMMAND(ID_VERTEILUNGSFUNKTIONEN_NORMALVERTEILUNGSDICHTEFUNKTION, OnVerteilungsfunktionenNormalverteilungsdichtefunktion)
	ON_COMMAND(ID_VERTEILUNGSFUNKTIONEN_TFUNKTION, OnVerteilungsfunktionenTfunktion)
	ON_COMMAND(ID_VERTEILUNGSFUNKTIONEN_CHIQUADRATFUNKTION, OnVerteilungsfunktionenChiquadratfunktion)
	ON_COMMAND(ID_VERTEILUNGSFUNKTIONEN_FFUNKTION, OnVerteilungsfunktionenFfunktion)
	ON_COMMAND(ID_WAHRSCHEINLICHKEITSFUNKTIONEN_BINOMIALFUNKTION, OnWahrscheinlichkeitsfunktionenBinomialfunktion)
	ON_COMMAND(ID_WAHRSCHEINLICHKEITSFUNKTIONEN_GEOMETRISCHEFUNKTION, OnWahrscheinlichkeitsfunktionenGeometrischefunktion)
	ON_COMMAND(ID_WAHRSCHEINLICHKEITSFUNKTIONEN_POISSONFUNKTION, OnWahrscheinlichkeitsfunktionenPoissonfunktion)
	ON_COMMAND(ID_WAHRSCHEINLICHKEITSFUNKTIONEN_HYPERGEOMETRISCHEFUNKTION, OnWahrscheinlichkeitsfunktionenHypergeometrischefunktion)
	ON_COMMAND(ID_WAHRSCHEINLICHKEITSFUNKTIONEN_HYPERGEOMETRISCHER4FELDERFISHEREXACTTEST, OnWahrscheinlichkeitsfunktionenHypergeometrischer4feldertest)
	ON_COMMAND(ID_BINOMIALTEST, OnBinomialtest)
	ON_COMMAND(ID_EPSILON, OnEpsilon)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()


CFunktionWinApp::CFunktionWinApp(){}
CFunktionWinApp theApp;

BOOL CFunktionWinApp::InitInstance()
{
	#ifdef _AFXDLL 
				   Enable3dControls();		
	#else          Enable3dControlsStatic();
	#endif

	CFunktionWinDlg ooo;
	  m_pMainWnd = &ooo;
	                ooo.DoModal();
	
	return 0;
}


void CFunktionWinApp::OnProgrammInfo() {	FW_INF ooo;
					                               ooo.DoModal(); }

void CFunktionWinApp::OnWahrscheinlichkeitsfunktionenBinomialfunktion()             { _spawnl( _P_NOWAIT, "FWBinomial.exe"," " );}
void CFunktionWinApp::OnWahrscheinlichkeitsfunktionenPoissonfunktion()              { _spawnl( _P_NOWAIT, "FWPoisson.exe"," " );}
void CFunktionWinApp::OnWahrscheinlichkeitsfunktionenGeometrischefunktion()         { _spawnl( _P_NOWAIT, "FWGeometric.exe"," " );}
void CFunktionWinApp::OnWahrscheinlichkeitsfunktionenHypergeometrischefunktion()    {_spawnl( _P_NOWAIT, "FWHypergeometric.exe"," " );} 
void CFunktionWinApp::OnBinomialtest()                                              {_spawnl( _P_NOWAIT, "FWBinomial_T.exe"," " );}
void CFunktionWinApp::OnWahrscheinlichkeitsfunktionenHypergeometrischer4feldertest(){_spawnl( _P_NOWAIT, "FWFisherEXACT.exe"," " );}

void CFunktionWinApp::OnVerteilungsfunktionenNormalverteilungsfunktion()            { _spawnl( _P_NOWAIT, "FWzFunktion.exe"," " );}
void CFunktionWinApp::OnVerteilungsfunktionenNormalverteilungsdichtefunktion()      { _spawnl( _P_NOWAIT, "FWzDichte.exe"," " );}
void CFunktionWinApp::OnVerteilungsfunktionenTfunktion()                            { _spawnl( _P_NOWAIT, "FWtFunktion.exe"," " );}
void CFunktionWinApp::OnVerteilungsfunktionenChiquadratfunktion()                   { _spawnl( _P_NOWAIT, "FWx2Funktion.exe"," " );}
void CFunktionWinApp::OnVerteilungsfunktionenFfunktion()                            { _spawnl( _P_NOWAIT, "FWFFunktion.exe"," " );}
void CFunktionWinApp::OnEpsilon()                                                   { _spawnl( _P_NOWAIT, "FWepsilon.exe"," " );}

void CFunktionWinApp::OnTransformationenFisherzfunktion()                           { _spawnl( _P_NOWAIT, "FWFisherZ.exe"," " );}
void CFunktionWinApp::OnTransformationenGamma()                                     { _spawnl( _P_NOWAIT, "FWGamma.exe"," " );}


void CFunktionWinApp::OnProgrammBeenden() {	OnSysCommand(SC_CLOSE, 0);}

void CFunktionWinApp::OnSysCommand(UINT nID, LPARAM lParam)
{
	if(nID==SC_CLOSE)
	{
		CFunktionWinDlg ooo;
			            ooo.DestroyWindow();
	}
		
	OnSysCommand(nID, lParam);	
}







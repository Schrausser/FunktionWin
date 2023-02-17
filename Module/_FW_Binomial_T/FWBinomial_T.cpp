//----------------------------------------------------------------------------------------------------|FWBinomial_T.cpp, SCHRAUSSER 2010
//
#include "stdafx.h"
#include "FWBinomial_T.h"
#include "FWBinomial_TDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BEGIN_MESSAGE_MAP(CFWBinomial_TApp, CWinApp)
	//{{AFX_MSG_MAP(CFWBinomial_TApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

CFWBinomial_TApp::CFWBinomial_TApp(){}
CFWBinomial_TApp theApp;

BOOL CFWBinomial_TApp::InitInstance()
{

	#ifdef _AFXDLL
			Enable3dControls();		
	#else	Enable3dControlsStatic();			
	#endif

	CFWBinomial_TDlg dlg;
	  m_pMainWnd = &dlg;
	                dlg.DoModal();
	return 1;
}

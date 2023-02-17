//----------------------------------------------------------------------------------------------------|FWBinomial.cpp, SCHRAUSSER 2009
//
#include "stdafx.h"
#include "FWBinomial.h"
#include "FWBinomialDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BEGIN_MESSAGE_MAP(CFWBinomialApp, CWinApp)
	//{{AFX_MSG_MAP(CFWBinomialApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

CFWBinomialApp::CFWBinomialApp(){}
CFWBinomialApp theApp;

BOOL CFWBinomialApp::InitInstance()
{

	#ifdef _AFXDLL
			Enable3dControls();		
	#else	Enable3dControlsStatic();			
	#endif

	CFWBinomialDlg dlg;
	  m_pMainWnd = &dlg;
	                dlg.DoModal();
	return 1;
}

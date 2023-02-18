//----------------------------------------------------------------------------------------------------|FWPoisson.cpp, SCHRAUSSER 2009
//
#include "stdafx.h"
#include "FWPoisson.h"
#include "FWPoissonDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BEGIN_MESSAGE_MAP(CFWPoissonApp, CWinApp)
	//{{AFX_MSG_MAP(CFWPoissonApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

CFWPoissonApp::CFWPoissonApp(){}
CFWPoissonApp theApp;

BOOL CFWPoissonApp::InitInstance()
{

	#ifdef _AFXDLL
			Enable3dControls();		
	#else	Enable3dControlsStatic();			
	#endif

	CFWPoissonDlg dlg;
	  m_pMainWnd = &dlg;
	                dlg.DoModal();
	return 1;
}

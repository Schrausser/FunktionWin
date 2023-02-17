//----------------------------------------------------------------------------------------------------|FWepsilon.cpp, SCHRAUSSER 2009
//
#include "stdafx.h"
#include "FWepsilon.h"
#include "FWepsilonDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BEGIN_MESSAGE_MAP(CFWepsilonApp, CWinApp)
	//{{AFX_MSG_MAP(CFWepsilonApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

CFWepsilonApp::CFWepsilonApp(){}
CFWepsilonApp theApp;

BOOL CFWepsilonApp::InitInstance()
{

	#ifdef _AFXDLL
			Enable3dControls();		
	#else	Enable3dControlsStatic();			
	#endif

	CFWepsilonDlg dlg;
	  m_pMainWnd = &dlg;
	                dlg.DoModal();
	return 1;
}

//----------------------------------------------------------------------------------------------------|FWzFunktion.cpp, SCHRAUSSER 2009
//
#include "stdafx.h"
#include "FWzFunktion.h"
#include "FWzFunktionDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BEGIN_MESSAGE_MAP(CFWzFunktionApp, CWinApp)
	//{{AFX_MSG_MAP(CFWzFunktionApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

CFWzFunktionApp::CFWzFunktionApp(){}
CFWzFunktionApp theApp;

BOOL CFWzFunktionApp::InitInstance()
{

	#ifdef _AFXDLL
			Enable3dControls();		
	#else	Enable3dControlsStatic();			
	#endif

	CFWzFunktionDlg dlg;
	  m_pMainWnd = &dlg;
	                dlg.DoModal();
	return 1;
}

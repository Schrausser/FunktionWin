//----------------------------------------------------------------------------------------------------|FWtFunktion.cpp, SCHRAUSSER 2009
//
#include "stdafx.h"
#include "FWtFunktion.h"
#include "FWtFunktionDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BEGIN_MESSAGE_MAP(CFWtFunktionApp, CWinApp)
	//{{AFX_MSG_MAP(CFWtFunktionApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

CFWtFunktionApp::CFWtFunktionApp(){}
CFWtFunktionApp theApp;

BOOL CFWtFunktionApp::InitInstance()
{

	#ifdef _AFXDLL
			Enable3dControls();		
	#else	Enable3dControlsStatic();			
	#endif

	CFWtFunktionDlg dlg;
	  m_pMainWnd = &dlg;
	                dlg.DoModal();
	return 1;
}

//----------------------------------------------------------------------------------------------------|FWFFunktion.cpp, SCHRAUSSER 2009
//
#include "stdafx.h"
#include "FWFFunktion.h"
#include "FWFFunktionDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BEGIN_MESSAGE_MAP(CFWFFunktionApp, CWinApp)
	//{{AFX_MSG_MAP(CFWFFunktionApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

CFWFFunktionApp::CFWFFunktionApp(){}
CFWFFunktionApp theApp;

BOOL CFWFFunktionApp::InitInstance()
{

	#ifdef _AFXDLL
			Enable3dControls();		
	#else	Enable3dControlsStatic();			
	#endif

	CFWFFunktionDlg dlg;
	  m_pMainWnd = &dlg;
	                dlg.DoModal();
	return 1;
}

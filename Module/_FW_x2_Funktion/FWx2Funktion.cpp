//----------------------------------------------------------------------------------------------------|FWx2Funktion.cpp, SCHRAUSSER 2009
//
#include "stdafx.h"
#include "FWx2Funktion.h"
#include "FWx2FunktionDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BEGIN_MESSAGE_MAP(CFWx2FunktionApp, CWinApp)
	//{{AFX_MSG_MAP(CFWx2FunktionApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

CFWx2FunktionApp::CFWx2FunktionApp(){}
CFWx2FunktionApp theApp;

BOOL CFWx2FunktionApp::InitInstance()
{

	#ifdef _AFXDLL
			Enable3dControls();		
	#else	Enable3dControlsStatic();			
	#endif

	CFWx2FunktionDlg dlg;
	  m_pMainWnd = &dlg;
	                dlg.DoModal();
	return 1;
}

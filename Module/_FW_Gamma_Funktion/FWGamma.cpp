//----------------------------------------------------------------------------------------------------|FWGamma.cpp, SCHRAUSSER 2009
//
#include "stdafx.h"
#include "FWGamma.h"
#include "FWGammaDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BEGIN_MESSAGE_MAP(CFWGammaApp, CWinApp)
	//{{AFX_MSG_MAP(CFWGammaApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

CFWGammaApp::CFWGammaApp(){}
CFWGammaApp theApp;

BOOL CFWGammaApp::InitInstance()
{

	#ifdef _AFXDLL
			Enable3dControls();		
	#else	Enable3dControlsStatic();			
	#endif

	CFWGammaDlg dlg;
	  m_pMainWnd = &dlg;
	                dlg.DoModal();
	return 1;
}

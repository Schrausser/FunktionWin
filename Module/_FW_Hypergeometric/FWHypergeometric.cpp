//----------------------------------------------------------------------------------------------------|FWHypergeometric.cpp, SCHRAUSSER 2009
//
#include "stdafx.h"
#include "FWHypergeometric.h"
#include "FWHypergeometricDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BEGIN_MESSAGE_MAP(CFWHypergeometricApp, CWinApp)
	//{{AFX_MSG_MAP(CFWHypergeometricApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

CFWHypergeometricApp::CFWHypergeometricApp(){}
CFWHypergeometricApp theApp;

BOOL CFWHypergeometricApp::InitInstance()
{

	#ifdef _AFXDLL
			Enable3dControls();		
	#else	Enable3dControlsStatic();			
	#endif

	CFWHypergeometricDlg dlg;
	  m_pMainWnd = &dlg;
	                dlg.DoModal();
	return 1;
}

//----------------------------------------------------------------------------------------------------|FWGeometric.cpp, SCHRAUSSER 2009
//
#include "stdafx.h"
#include "FWGeometric.h"
#include "FWGeometricDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BEGIN_MESSAGE_MAP(CFWGeometricApp, CWinApp)
	//{{AFX_MSG_MAP(CFWGeometricApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

CFWGeometricApp::CFWGeometricApp(){}
CFWGeometricApp theApp;

BOOL CFWGeometricApp::InitInstance()
{

	#ifdef _AFXDLL
			Enable3dControls();		
	#else	Enable3dControlsStatic();			
	#endif

	CFWGeometricDlg dlg;
	  m_pMainWnd = &dlg;
	                dlg.DoModal();
	return 1;
}

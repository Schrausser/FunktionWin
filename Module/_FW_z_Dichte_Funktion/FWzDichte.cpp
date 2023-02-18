//----------------------------------------------------------------------------------------------------|FWzDichte.cpp, SCHRAUSSER 2009
//
#include "stdafx.h"
#include "FWzDichte.h"
#include "FWzDichteDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BEGIN_MESSAGE_MAP(CFWzDichteApp, CWinApp)
	//{{AFX_MSG_MAP(CFWzDichteApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

CFWzDichteApp::CFWzDichteApp(){}
CFWzDichteApp theApp;

BOOL CFWzDichteApp::InitInstance()
{

	#ifdef _AFXDLL
			Enable3dControls();		
	#else	Enable3dControlsStatic();			
	#endif

	CFWzDichteDlg dlg;
	  m_pMainWnd = &dlg;
	                dlg.DoModal();
	return 1;
}

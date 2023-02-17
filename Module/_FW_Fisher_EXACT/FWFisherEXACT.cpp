//----------------------------------------------------------------------------------------------------|FWFisherEXACT.cpp, SCHRAUSSER 2009
//
#include "stdafx.h"
#include "FWFisherEXACT.h"
#include "FWFisherEXACTDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BEGIN_MESSAGE_MAP(CFWFisherEXACTApp, CWinApp)
	//{{AFX_MSG_MAP(CFWFisherEXACTApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

CFWFisherEXACTApp::CFWFisherEXACTApp(){}
CFWFisherEXACTApp theApp;

BOOL CFWFisherEXACTApp::InitInstance()
{

	#ifdef _AFXDLL
			Enable3dControls();		
	#else	Enable3dControlsStatic();			
	#endif

	CFWFisherEXACTDlg dlg;
	  m_pMainWnd = &dlg;
	                dlg.DoModal();
	return 1;
}

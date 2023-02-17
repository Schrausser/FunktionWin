
#include "stdafx.h"
#include "FunktionWin.h"
#include <process.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString arg;

char mode[2]; 

FW_FISHERZ::FW_FISHERZ(CWnd* pParent /*=NULL*/)
	: CDialog(FW_FISHERZ::IDD, pParent)
{
	//{{AFX_DATA_INIT(FW_FISHERZ)
	//}}AFX_DATA_INIT
}


void FW_FISHERZ::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(FW_FISHERZ)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(FW_FISHERZ, CDialog)
	//{{AFX_MSG_MAP(FW_FISHERZ)
	ON_BN_CLICKED(IDC_INFO, OnInfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


void FW_FISHERZ::OnInfo() {system("start Fisher_Z.exe");	 }//_spawnl( _P_NOWAIT, "Fisher_Z"," " );

void FW_FISHERZ::OnOK() 
{
	UpdateData(1);
	
	itoa(m_modus+1,mode,10);
	
	UpdateData(0);

		          arg+="Start ";
		          arg+=m_CMD;     arg+=" ";
		          arg+=mode; arg+=" ";
		          arg+=m_x;       arg+=" ";
	
	system(       arg );
	             
	              arg="";
}


	




//----------------------------------------------------------------------------------------------------| FW_INF.cpp von Dietmar Schrausser 2009    
//
#include "stdafx.h"
#include "FunktionWin.h"
#include "FW_INF.h"
#include <time.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


FW_INF::FW_INF(CWnd* pParent /*=NULL*/)
	: CDialog(FW_INF::IDD, pParent)
{
	//{{AFX_DATA_INIT(FW_INF)
	m_date = __DATE__;
	m_time = __TIME__;
	//}}AFX_DATA_INIT
}


void FW_INF::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(FW_INF)
	DDX_Text(pDX, IDC_DATE, m_date);
	DDX_Text(pDX, IDC_TIME, m_time);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(FW_INF, CDialog)
	//{{AFX_MSG_MAP(FW_INF)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



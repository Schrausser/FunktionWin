//----------------------------------------------------------------------------------------------------|FWzFunktionDlg.cpp, SCHRAUSSER 2009
//
#include "stdafx.h"
#include "FWzFunktion.h"
#include "FWzFunktionDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString arg;

char mode[2]; 

CFWzFunktionDlg::CFWzFunktionDlg(CWnd* pParent)
	: CDialog(CFWzFunktionDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFWzFunktionDlg)
	m_CMD = "z_Function";
	m_x = "0";
	m_modus = 1;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFWzFunktionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFWzFunktionDlg)
	DDX_Text(pDX, IDC_CMD, m_CMD);
	DDX_CBString(pDX, IDC_X, m_x);
	DDX_CBIndex(pDX, IDC_MODUS, m_modus);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFWzFunktionDlg, CDialog)
	//{{AFX_MSG_MAP(CFWzFunktionDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_INFO, OnInfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CFWzFunktionDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, 1);SetIcon(m_hIcon, 0); return 1;				  
}

void CFWzFunktionDlg::OnPaint() {CDialog::OnPaint();}

HCURSOR CFWzFunktionDlg::OnQueryDragIcon(){return (HCURSOR) m_hIcon;}

void CFWzFunktionDlg::OnInfo() {system("start z_Function.exe");	 }

void CFWzFunktionDlg::OnOK() 
{
	UpdateData(1);
	
	itoa(m_modus+1,mode,10);
	
	UpdateData(0);

		          arg+="Start ";
		          arg+=m_CMD;     arg+=" ";
		          arg+=mode;      arg+=" ";
		          arg+=m_x;       arg+=" ";
	
	system(       arg );
	             
	              arg="";
}

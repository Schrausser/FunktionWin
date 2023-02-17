//----------------------------------------------------------------------------------------------------|FWFFunktionDlg.cpp, SCHRAUSSER 2009
//
#include "stdafx.h"
#include "FWFFunktion.h"
#include "FWFFunktionDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString arg;

char mode[2]; 

CFWFFunktionDlg::CFWFFunktionDlg(CWnd* pParent)
	: CDialog(CFWFFunktionDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFWFFunktionDlg)
	m_CMD = "F_Function";
	m_x = "0";
	m_modus = 1;
	m_n1 = "5";
	m_n2 = "10";
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFWFFunktionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFWFFunktionDlg)
	DDX_Text(pDX, IDC_CMD, m_CMD);
	DDX_CBString(pDX, IDC_X, m_x);
	DDX_CBIndex(pDX, IDC_MODUS, m_modus);
	DDX_CBString(pDX, IDC_N1, m_n1);
	DDX_CBString(pDX, IDC_N2, m_n2);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFWFFunktionDlg, CDialog)
	//{{AFX_MSG_MAP(CFWFFunktionDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_INFO, OnInfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CFWFFunktionDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, 1);SetIcon(m_hIcon, 0); return 1;				  
}

void CFWFFunktionDlg::OnPaint() {CDialog::OnPaint();}

HCURSOR CFWFFunktionDlg::OnQueryDragIcon(){return (HCURSOR) m_hIcon;}

void CFWFFunktionDlg::OnInfo() {system("start F_Function.exe");	 }

void CFWFFunktionDlg::OnOK() 
{
	UpdateData(1);
	
	itoa(m_modus+1,mode,10);
	
	UpdateData(0);

		          arg+="Start ";
		          arg+=m_CMD;     arg+=" ";
		          arg+=mode;      arg+=" ";
		          arg+=m_x;       arg+=" ";
				  arg+=m_n1;       arg+=" ";
				  arg+=m_n2;       arg+=" ";
	
	system(       arg );
	             
	              arg="";
}

//----------------------------------------------------------------------------------------------------|FWx2FunktionDlg.cpp, SCHRAUSSER 2009
//
#include "stdafx.h"
#include "FWx2Funktion.h"
#include "FWx2FunktionDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString arg;

char mode[2]; 

CFWx2FunktionDlg::CFWx2FunktionDlg(CWnd* pParent)
	: CDialog(CFWx2FunktionDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFWx2FunktionDlg)
	m_CMD = "x2_Function";
	m_x = "0";
	m_modus = 1;
	m_n = "10";
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFWx2FunktionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFWx2FunktionDlg)
	DDX_Text(pDX, IDC_CMD, m_CMD);
	DDX_CBString(pDX, IDC_X, m_x);
	DDX_CBIndex(pDX, IDC_MODUS, m_modus);
	DDX_CBString(pDX, IDC_N, m_n);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFWx2FunktionDlg, CDialog)
	//{{AFX_MSG_MAP(CFWx2FunktionDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_INFO, OnInfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CFWx2FunktionDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, 1);SetIcon(m_hIcon, 0); return 1;				  
}

void CFWx2FunktionDlg::OnPaint() {CDialog::OnPaint();}

HCURSOR CFWx2FunktionDlg::OnQueryDragIcon(){return (HCURSOR) m_hIcon;}

void CFWx2FunktionDlg::OnInfo() {system("start x2_Function.exe");	 }

void CFWx2FunktionDlg::OnOK() 
{
	UpdateData(1);
	
	itoa(m_modus+1,mode,10);
	
	UpdateData(0);

		          arg+="Start ";
		          arg+=m_CMD;     arg+=" ";
		          arg+=mode;      arg+=" ";
		          arg+=m_x;       arg+=" ";
				  arg+=m_n;       arg+=" ";
	
	system(       arg );
	             
	              arg="";
}

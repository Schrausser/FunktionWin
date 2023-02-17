//----------------------------------------------------------------------------------------------------|FWGammaDlg.cpp, SCHRAUSSER 2009
//
#include "stdafx.h"
#include "FWGamma.h"
#include "FWGammaDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString arg;

char mode[2]; 

CFWGammaDlg::CFWGammaDlg(CWnd* pParent)
	: CDialog(CFWGammaDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFWGammaDlg)
	m_CMD = "GAMMA_Function";
	m_x = "1";
	m_modus = 0;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFWGammaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFWGammaDlg)
	DDX_Text(pDX, IDC_CMD, m_CMD);
	DDX_CBString(pDX, IDC_X, m_x);
	DDX_CBIndex(pDX, IDC_MODUS, m_modus);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFWGammaDlg, CDialog)
	//{{AFX_MSG_MAP(CFWGammaDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_INFO, OnInfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CFWGammaDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, 1);SetIcon(m_hIcon, 0); return 1;				  
}

void CFWGammaDlg::OnPaint() {CDialog::OnPaint();}

HCURSOR CFWGammaDlg::OnQueryDragIcon(){return (HCURSOR) m_hIcon;}

void CFWGammaDlg::OnInfo() {system("start GAMMA_Function.exe");	 }

void CFWGammaDlg::OnOK() 
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

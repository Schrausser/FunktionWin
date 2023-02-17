//----------------------------------------------------------------------------------------------------|FWGeometricDlg.cpp, SCHRAUSSER 2009
//
#include "stdafx.h"
#include "FWGeometric.h"
#include "FWGeometricDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString arg;

char grp[2];  

CFWGeometricDlg::CFWGeometricDlg(CWnd* pParent)
	: CDialog(CFWGeometricDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFWGeometricDlg)
	m_CMD = "Geometric";
	m_n = "10";
	m_pa = "0.2";
	m_ch_grp = 1;
	m_grp = "EIN";
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFWGeometricDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFWGeometricDlg)
	DDX_Text(pDX, IDC_CMD, m_CMD);
	DDX_CBString(pDX, IDC_N, m_n);
	DDX_CBString(pDX, IDC_PA, m_pa);
	DDX_Check(pDX, IDC_CHECK_GRP, m_ch_grp);
	DDX_Text(pDX, IDC_GRP, m_grp);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFWGeometricDlg, CDialog)
	//{{AFX_MSG_MAP(CFWGeometricDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_INFO, OnInfo)
	ON_BN_CLICKED(IDC_LOG, OnLog)
	ON_BN_CLICKED(IDC_LOGP, OnLogp)
	ON_BN_CLICKED(IDC_CHECK_GRP, OnCheckGrp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CFWGeometricDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, 1);SetIcon(m_hIcon, 0); return 1;				  
}

void CFWGeometricDlg::OnPaint() {CDialog::OnPaint();}

HCURSOR CFWGeometricDlg::OnQueryDragIcon(){return (HCURSOR) m_hIcon;}

void CFWGeometricDlg::OnInfo() {system("start Geometric.exe");	  }
void CFWGeometricDlg::OnLog()  {system("start notepad geometric_log.txt");}
void CFWGeometricDlg::OnLogp() {system("start notepad geometric_p.txt");  }

void CFWGeometricDlg::OnOK() 
{
	UpdateData(1);
	
	itoa(m_ch_grp,grp,10);
	
	UpdateData(0);

		          arg+="Start ";
		          arg+=m_CMD;     arg+=" ";
				  arg+=m_pa;       arg+=" ";
				  arg+=m_n;       arg+=" ";
		          arg+=grp;       arg+=" ";
	
	system(       arg );
	             
	              arg="";
}

void CFWGeometricDlg::OnCheckGrp() 
{
	UpdateData(1); 
					m_grp="";
	if(m_ch_grp==1) m_grp="EIN";

	UpdateData(0);
	
}

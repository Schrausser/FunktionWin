//----------------------------------------------------------------------------------------------------|FWPoissonDlg.cpp, SCHRAUSSER 2009
//
#include "stdafx.h"
#include "FWPoisson.h"
#include "FWPoissonDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString arg;

char grp[2];  

CFWPoissonDlg::CFWPoissonDlg(CWnd* pParent)
	: CDialog(CFWPoissonDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFWPoissonDlg)
	m_CMD = "Poisson";
	m_n = "1000";
	m_na = "1";
	m_pa = "0.003";
	m_ch_grp = 1;
	m_grp = "EIN";
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFWPoissonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFWPoissonDlg)
	DDX_Text(pDX, IDC_CMD, m_CMD);
	DDX_CBString(pDX, IDC_N, m_n);
	DDX_CBString(pDX, IDC_NA, m_na);
	DDX_CBString(pDX, IDC_PA, m_pa);
	DDX_Check(pDX, IDC_CHECK_GRP, m_ch_grp);
	DDX_Text(pDX, IDC_GRP, m_grp);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFWPoissonDlg, CDialog)
	//{{AFX_MSG_MAP(CFWPoissonDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_INFO, OnInfo)
	ON_BN_CLICKED(IDC_LOG, OnLog)
	ON_BN_CLICKED(IDC_LOGP, OnLogp)
	ON_BN_CLICKED(IDC_CHECK_GRP, OnCheckGrp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CFWPoissonDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, 1);SetIcon(m_hIcon, 0); return 1;				  
}

void CFWPoissonDlg::OnPaint() {CDialog::OnPaint();}

HCURSOR CFWPoissonDlg::OnQueryDragIcon(){return (HCURSOR) m_hIcon;}

void CFWPoissonDlg::OnInfo() {system("start Poisson.exe");	  }
void CFWPoissonDlg::OnLog()  {system("start notepad poisson_log.txt");}
void CFWPoissonDlg::OnLogp() {system("start notepad poisson_p.txt");  }

void CFWPoissonDlg::OnOK() 
{
	UpdateData(1);
	
	itoa(m_ch_grp,grp,10);
	
	UpdateData(0);

		          arg+="Start ";
		          arg+=m_CMD;     arg+=" ";
				  arg+=m_pa;       arg+=" ";
				  arg+=m_na;       arg+=" ";
				  arg+=m_n;       arg+=" ";
		          arg+=grp;       arg+=" ";
	
	system(       arg );
	             
	              arg="";
}

void CFWPoissonDlg::OnCheckGrp() 
{
	UpdateData(1); 
					m_grp="";
	if(m_ch_grp==1) m_grp="EIN";

	UpdateData(0);
	
}

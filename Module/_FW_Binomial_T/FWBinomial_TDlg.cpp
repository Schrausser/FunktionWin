//----------------------------------------------------------------------------------------------------|FWBinomial_TDlg.cpp, SCHRAUSSER 2010
//
#include "stdafx.h"
#include "FWBinomial_T.h"
#include "FWBinomial_TDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString arg;

char grp[2];  

CFWBinomial_TDlg::CFWBinomial_TDlg(CWnd* pParent)
	: CDialog(CFWBinomial_TDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFWBinomial_TDlg)
	m_CMD = "Binomial_T";
	m_n = "30";
	m_na = "35";
	m_ch_grp = 1;
	m_grp = "EIN";
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFWBinomial_TDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFWBinomial_TDlg)
	DDX_Text(pDX, IDC_CMD, m_CMD);
	DDX_CBString(pDX, IDC_N, m_n);
	DDX_CBString(pDX, IDC_NA, m_na);
	DDX_Check(pDX, IDC_CHECK_GRP, m_ch_grp);
	DDX_Text(pDX, IDC_GRP, m_grp);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFWBinomial_TDlg, CDialog)
	//{{AFX_MSG_MAP(CFWBinomial_TDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_INFO, OnInfo)
	ON_BN_CLICKED(IDC_LOG, OnLog)
	ON_BN_CLICKED(IDC_LOGP, OnLogp)
	ON_BN_CLICKED(IDC_CHECK_GRP, OnCheckGrp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CFWBinomial_TDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, 1);SetIcon(m_hIcon, 0); return 1;				  
}

void CFWBinomial_TDlg::OnPaint() {CDialog::OnPaint();}

HCURSOR CFWBinomial_TDlg::OnQueryDragIcon(){return (HCURSOR) m_hIcon;}

void CFWBinomial_TDlg::OnInfo() {system("start Binomial_T.exe");	  }
void CFWBinomial_TDlg::OnLog()  {system("start notepad binomial_t_log.txt");}
void CFWBinomial_TDlg::OnLogp() {system("start notepad binomial_t_p.txt");  }

void CFWBinomial_TDlg::OnOK() 
{
	UpdateData(1);
	
	itoa(m_ch_grp,grp,10);
	
	UpdateData(0);

		          arg+="Start ";
		          arg+=m_CMD;     arg+=" ";
				  arg+=m_na;       arg+=" ";
				  arg+=m_n;       arg+=" ";
		          arg+=grp;       arg+=" ";
	
	system(       arg );
	             
	              arg="";
}

void CFWBinomial_TDlg::OnCheckGrp() 
{
	UpdateData(1); 
					m_grp="";
	if(m_ch_grp==1) m_grp="EIN";

	UpdateData(0);
	
}

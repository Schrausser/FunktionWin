//----------------------------------------------------------------------------------------------------|FWHypergeometricDlg.cpp, SCHRAUSSER 2009
//
#include "stdafx.h"
#include "FWHypergeometric.h"
#include "FWHypergeometricDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString arg;

char grp[2];  

CFWHypergeometricDlg::CFWHypergeometricDlg(CWnd* pParent)
	: CDialog(CFWHypergeometricDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFWHypergeometricDlg)
	m_CMD = "Hypergeometric";
	m_n = "100";
	m_ch_grp = 1;
	m_grp = "EIN";
	m_n_ = "30";
	m_k_ = "5";
	m_k = "20";
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFWHypergeometricDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFWHypergeometricDlg)
	DDX_Text(pDX, IDC_CMD, m_CMD);
	DDX_CBString(pDX, IDC_N, m_n);
	DDX_Check(pDX, IDC_CHECK_GRP, m_ch_grp);
	DDX_Text(pDX, IDC_GRP, m_grp);
	DDX_CBString(pDX, IDC_n_, m_n_);
	DDX_CBString(pDX, IDC_k_, m_k_);
	DDX_CBString(pDX, IDC_K, m_k);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFWHypergeometricDlg, CDialog)
	//{{AFX_MSG_MAP(CFWHypergeometricDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_INFO, OnInfo)
	ON_BN_CLICKED(IDC_LOG, OnLog)
	ON_BN_CLICKED(IDC_LOGP, OnLogp)
	ON_BN_CLICKED(IDC_CHECK_GRP, OnCheckGrp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CFWHypergeometricDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, 1);SetIcon(m_hIcon, 0); return 1;				  
}

void CFWHypergeometricDlg::OnPaint() {CDialog::OnPaint();}

HCURSOR CFWHypergeometricDlg::OnQueryDragIcon(){return (HCURSOR) m_hIcon;}

void CFWHypergeometricDlg::OnInfo() {system("start Hypergeometric.exe");	  }
void CFWHypergeometricDlg::OnLog()  {system("start notepad hypergeometric_log.txt");}
void CFWHypergeometricDlg::OnLogp() {system("start notepad hypergeometric_p.txt");  }

void CFWHypergeometricDlg::OnOK() 
{
	UpdateData(1);
	
	itoa(m_ch_grp,grp,10);
	
	UpdateData(0);

		          arg+="Start ";
		          arg+=m_CMD;     arg+=" ";
				  arg+=m_k_;      arg+=" ";
				  arg+=m_n_;      arg+=" ";
				  arg+=m_n;       arg+=" ";
				  arg+=m_k;       arg+=" ";
		          arg+=grp;       arg+=" ";
	
	system(       arg );
	             
	              arg="";
}

void CFWHypergeometricDlg::OnCheckGrp() 
{
	UpdateData(1); 
					m_grp="";
	if(m_ch_grp==1) m_grp="EIN";

	UpdateData(0);
	
}

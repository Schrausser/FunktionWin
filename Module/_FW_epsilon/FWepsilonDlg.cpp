//----------------------------------------------------------------------------------------------------|FWepsilonDlg.cpp, SCHRAUSSER 2010
//
#include "stdafx.h"
#include "FWepsilon.h"
#include "FWepsilonDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString arg;
CString sw="2";

char grp[2]; 
 
CFWepsilonDlg::CFWepsilonDlg(CWnd* pParent)
	: CDialog(CFWepsilonDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFWepsilonDlg)
	m_CMD = "epsilon";
	m_ch_grp = 0;
	m_grp = "";
	m_q0 = "40";
	m_s = "7.92";
	m_n = "100";
	m_df = "1";
	m_p = "0.99";
	m_e = "0.375";
	m_ch_e = 0;
	m_ch_q1 = 1;
	m_q1 = "43";
	m_x = "";
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFWepsilonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFWepsilonDlg)
	DDX_Control(pDX, IDC_q1, m_q1_ctr);
	DDX_Control(pDX, IDC_e, m_e_ctr);
	DDX_Control(pDX, IDC_qx, m_qx);
	DDX_Text(pDX, IDC_CMD, m_CMD);
	DDX_Check(pDX, IDC_CHECK_GRP, m_ch_grp);
	DDX_Text(pDX, IDC_GRP, m_grp);
	DDX_CBString(pDX, IDC_Q0, m_q0);
	DDX_CBString(pDX, IDC_s, m_s);
	DDX_CBString(pDX, IDC_n, m_n);
	DDX_CBString(pDX, IDC_df, m_df);
	DDX_CBString(pDX, IDC_p, m_p);
	DDX_Text(pDX, IDC_e, m_e);
	DDX_Check(pDX, IDC_CHECK_e, m_ch_e);
	DDX_Check(pDX, IDC_CHECK_q1, m_ch_q1);
	DDX_Text(pDX, IDC_q1, m_q1);
	DDX_Text(pDX, IDC_qx, m_x);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFWepsilonDlg, CDialog)
	//{{AFX_MSG_MAP(CFWepsilonDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_INFO, OnInfo)
	ON_BN_CLICKED(IDC_CHECK_GRP, OnCheckGrp)
	ON_BN_CLICKED(IDC_LOGP, OnLogp)
	ON_BN_CLICKED(IDC_CHECK_e, OnCHECKe)
	ON_BN_CLICKED(IDC_CHECK_q1, OnCHECKq1)
	ON_EN_UPDATE(IDC_e, OnUpdatee)
	ON_EN_UPDATE(IDC_q1, OnUpdateq1)
	ON_EN_UPDATE(IDC_qx, OnUpdateqx)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CFWepsilonDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, 1);SetIcon(m_hIcon, 0); return 1;				  
}

void CFWepsilonDlg::OnPaint() {CDialog::OnPaint();}

HCURSOR CFWepsilonDlg::OnQueryDragIcon(){return (HCURSOR) m_hIcon;}

void CFWepsilonDlg::OnCheckGrp() 
{
	UpdateData(1); 
	
	m_x="";
	m_qx.SetReadOnly(!m_ch_grp); 

	UpdateData(0);
}

void CFWepsilonDlg::OnCHECKe() 
{
	UpdateData(1); 
	
	m_e_ctr.SetReadOnly(!m_ch_e); 
	m_q1_ctr.SetReadOnly(m_ch_e);

	m_ch_q1 = !m_ch_e;

	UpdateData(0);

	sw="1";
}

void CFWepsilonDlg::OnCHECKq1() 
{
	UpdateData(1); 
	
	m_q1_ctr.SetReadOnly(!m_ch_q1); 
	  m_e_ctr.SetReadOnly(m_ch_q1);
	
	m_ch_e = !m_ch_q1;

	UpdateData(0);

	sw="2";
}

void CFWepsilonDlg::OnUpdatee()  { UpdateData(1); UpdateData(0);}
void CFWepsilonDlg::OnUpdateq1() { UpdateData(1); UpdateData(0);}
void CFWepsilonDlg::OnUpdateqx() { UpdateData(1); UpdateData(0);}

void CFWepsilonDlg::OnInfo() {system("start epsilon.exe");	  }
void CFWepsilonDlg::OnLogp() {system("start notepad epsilon_log.txt");}

void CFWepsilonDlg::OnOK() 
{
	UpdateData(1);
	
	UpdateData(0);

		          arg+="Start ";
		          arg+=m_CMD;     arg+=" ";
				  arg+=sw;        arg+=" ";
				  arg+=m_q0;      arg+=" ";
				  arg+=m_s;       arg+=" ";
				  arg+=m_n;       arg+=" ";
	   if(sw=="1")arg+=m_e; 
	   if(sw=="2")arg+=m_q1;      arg+=" ";  
		          arg+=m_p;       arg+=" ";
				  arg+=m_df;      arg+=" ";
				  arg+=m_x;       arg+=" ";
	
	system(       arg );
	             
	              arg="";
}





		
	
	

	
	


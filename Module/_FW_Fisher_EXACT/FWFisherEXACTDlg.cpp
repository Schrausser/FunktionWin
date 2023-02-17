//----------------------------------------------------------------------------------------------------|FWFisherEXACTDlg.cpp, SCHRAUSSER 2009
//
#include "stdafx.h"
#include "FWFisherEXACT.h"
#include "FWFisherEXACTDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString arg;

char grp[2];  

CFWFisherEXACTDlg::CFWFisherEXACTDlg(CWnd* pParent)
	: CDialog(CFWFisherEXACTDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFWFisherEXACTDlg)
	m_CMD = "Fisher_Exact";
	m_ch_grp = 1;
	m_grp = "EIN";
	m_a = "25";
	m_b = "30";
	m_c = "35";
	m_d = "25";
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFWFisherEXACTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFWFisherEXACTDlg)
	DDX_Text(pDX, IDC_CMD, m_CMD);
	DDX_Check(pDX, IDC_CHECK_GRP, m_ch_grp);
	DDX_Text(pDX, IDC_GRP, m_grp);
	DDX_CBString(pDX, IDC_a, m_a);
	DDX_CBString(pDX, IDC_b, m_b);
	DDX_CBString(pDX, IDC_c, m_c);
	DDX_CBString(pDX, IDC_d, m_d);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFWFisherEXACTDlg, CDialog)
	//{{AFX_MSG_MAP(CFWFisherEXACTDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_INFO, OnInfo)
	ON_BN_CLICKED(IDC_CHECK_GRP, OnCheckGrp)
	ON_BN_CLICKED(IDC_LOGP, OnLogp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CFWFisherEXACTDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, 1);SetIcon(m_hIcon, 0); return 1;				  
}

void CFWFisherEXACTDlg::OnPaint() {CDialog::OnPaint();}

HCURSOR CFWFisherEXACTDlg::OnQueryDragIcon(){return (HCURSOR) m_hIcon;}

void CFWFisherEXACTDlg::OnInfo() {system("start Fisher_Exact.exe");	  }
void CFWFisherEXACTDlg::OnLogp() {system("start notepad Fisher_Exact_p.txt");}

void CFWFisherEXACTDlg::OnOK() 
{
	UpdateData(1);
	
	itoa(m_ch_grp,grp,10);
	
	UpdateData(0);

		          arg+="Start ";
		          arg+=m_CMD;     arg+=" ";
				  arg+=m_a;      arg+=" ";
				  arg+=m_b;      arg+=" ";
				  arg+=m_c;       arg+=" ";
				  arg+=m_d;       arg+=" ";
		          arg+=grp;       arg+=" ";
	
	system(       arg );
	             
	              arg="";
}

void CFWFisherEXACTDlg::OnCheckGrp() 
{
	UpdateData(1); 
					m_grp="";
	if(m_ch_grp==1) m_grp="EIN";

	UpdateData(0);
	
}
 

//----------------------------------------------------------------------------------------------------|FWzDichteDlg.cpp, SCHRAUSSER 2009
//
#include "stdafx.h"
#include "FWzDichte.h"
#include "FWzDichteDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString arg;

char mode[2], grp[2]; 

CFWzDichteDlg::CFWzDichteDlg(CWnd* pParent)
	: CDialog(CFWzDichteDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFWzDichteDlg)
	m_CMD = "z_Dichte";
	m_x = "0";
	m_modus = 0;
	m_grp = "EIN";
	m_ch_grp = 1;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFWzDichteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFWzDichteDlg)
	DDX_Text(pDX, IDC_CMD, m_CMD);
	DDX_CBString(pDX, IDC_X, m_x);
	DDX_CBIndex(pDX, IDC_MODUS, m_modus);
	DDX_Text(pDX, IDC_GRP, m_grp);
	DDX_Check(pDX, IDC_CHECK_GRP, m_ch_grp);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFWzDichteDlg, CDialog)
	//{{AFX_MSG_MAP(CFWzDichteDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_INFO, OnInfo)
	ON_BN_CLICKED(IDC_CHECK_GRP, OnCheckGrp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CFWzDichteDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, 1);SetIcon(m_hIcon, 0); return 1;				  
}

void CFWzDichteDlg::OnPaint() {CDialog::OnPaint();}

HCURSOR CFWzDichteDlg::OnQueryDragIcon(){return (HCURSOR) m_hIcon;}

void CFWzDichteDlg::OnInfo() {system("start z_Dichte.exe");	 }

void CFWzDichteDlg::OnOK() 
{
	UpdateData(1);
	
	itoa(m_modus+1,mode,10);
	itoa(m_ch_grp,grp,10);
	
	UpdateData(0);

		          arg+="Start ";
		          arg+=m_CMD;     arg+=" ";
		          arg+=mode;      arg+=" ";
		          arg+=m_x;       arg+=" ";
				  arg+=grp;       arg+=" ";
	
	system(       arg );
	             
	              arg="";
}

void CFWzDichteDlg::OnCheckGrp() 
{
	UpdateData(1); 
					m_grp="";
	if(m_ch_grp==1) m_grp="EIN";

	UpdateData(0);
}

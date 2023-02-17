//----------------------------------------------------------------------------------------------------|FWFisherZDlg.cpp, SCHRAUSSER 2009
//
#include "stdafx.h"
#include "FWFisherZ.h"
#include "FWFisherZDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString arg;

char mode[2]; 

CFWFisherZDlg::CFWFisherZDlg(CWnd* pParent)
	: CDialog(CFWFisherZDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFWFisherZDlg)
	m_CMD = "Fisher_Z";
	m_x = "0";
	m_modus = 0;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFWFisherZDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFWFisherZDlg)
	DDX_Text(pDX, IDC_CMD, m_CMD);
	DDX_CBString(pDX, IDC_X, m_x);
	DDX_CBIndex(pDX, IDC_MODUS, m_modus);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFWFisherZDlg, CDialog)
	//{{AFX_MSG_MAP(CFWFisherZDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_INFO, OnInfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CFWFisherZDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, 1);SetIcon(m_hIcon, 0); return 1;				  
}

void CFWFisherZDlg::OnPaint() {CDialog::OnPaint();}

HCURSOR CFWFisherZDlg::OnQueryDragIcon(){return (HCURSOR) m_hIcon;}

void CFWFisherZDlg::OnInfo() {system("start Fisher_Z.exe");	 }

void CFWFisherZDlg::OnOK() 
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

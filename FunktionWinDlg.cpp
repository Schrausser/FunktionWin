//----------------------------------------------------------------------------------------------------| FunktionWinDlg.cpp von Dietmar Schrausser 2009    
//
#include "stdafx.h"
#include "FunktionWin.h"
#include "FunktionWinDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

int dlg_x, dlg_y;

CFunktionWinDlg::CFunktionWinDlg(CWnd* pParent)
	: CDialog(CFunktionWinDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFunktionWinDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFunktionWinDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFunktionWinDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFunktionWinDlg, CDialog)
	//{{AFX_MSG_MAP(CFunktionWinDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


BOOL CFunktionWinDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, 1); SetIcon(m_hIcon, 0); return 1; 			
}


void CFunktionWinDlg::OnPaint() 
{
	CPaintDC ooo(this); 
						 CRect oo1(20, dlg_y-10, 25, dlg_y-20);
			 ooo.FillSolidRect(oo1, 13357270  );
			 			 CRect oo2(20, dlg_y-15, 25, dlg_y-25);
			 ooo.FillSolidRect(oo2, 8421504  );
			 			 CRect oo3(20, dlg_y-20, 25, dlg_y-30);
			 ooo.FillSolidRect(oo3, 13357270  );

}

HCURSOR CFunktionWinDlg::OnQueryDragIcon(){return (HCURSOR) m_hIcon;}

	
void CFunktionWinDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	dlg_x= cx;         
	dlg_y= cy;
	
	CDialog::OnPaint();
	
 	RedrawWindow();	
}




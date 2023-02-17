//----------------------------------------------------------------------------------------------------| FunktionWinDlg.h von Dietmar Schrausser 2009    
//
#if !defined(AFX_FUNKTIONWINDLG_H__C8777C67_35DB_48BF_993A_48E48CE75E4F__INCLUDED_)
#define AFX_FUNKTIONWINDLG_H__C8777C67_35DB_48BF_993A_48E48CE75E4F__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class CFunktionWinDlg : public CDialog
{

	public:
	CFunktionWinDlg(CWnd* pParent = NULL);	


	//{{AFX_DATA(CFunktionWinDlg)
	enum { IDD = IDD_FUNKTIONWIN_DIALOG };
	//}}AFX_DATA


	//{{AFX_VIRTUAL(CFunktionWinDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	
	//}}AFX_VIRTUAL


	protected:
	HICON m_hIcon;

	//{{AFX_MSG(CFunktionWinDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif

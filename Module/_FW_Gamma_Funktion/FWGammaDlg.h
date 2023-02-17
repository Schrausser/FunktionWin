//----------------------------------------------------------------------------------------------------|FWGammaDlg.h, SCHRAUSSER 2009
//
#if !defined(AFX_FWGammaDLG_H__E366356F_1D52_41BD_975D_AE4B1E4CA9C5__INCLUDED_)
#define AFX_FWGammaDLG_H__E366356F_1D52_41BD_975D_AE4B1E4CA9C5__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class CFWGammaDlg : public CDialog
{
	public:
	CFWGammaDlg(CWnd* pParent = NULL);	

	//{{AFX_DATA(CFWGammaDlg)
	enum { IDD = IDD_FWGamma_DIALOG };
	CString	m_CMD;
	CString	m_x;
	int		m_modus;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CFWGammaDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	
	//}}AFX_VIRTUAL

	protected:
	HICON m_hIcon;

	//{{AFX_MSG(CFWGammaDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnInfo();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 

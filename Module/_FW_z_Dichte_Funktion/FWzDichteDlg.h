//----------------------------------------------------------------------------------------------------|FWzDichteDlg.h, SCHRAUSSER 2009
//
#if !defined(AFX_FWzDichteDLG_H__E366356F_1D52_41BD_975D_AE4B1E4CA9C5__INCLUDED_)
#define AFX_FWzDichteDLG_H__E366356F_1D52_41BD_975D_AE4B1E4CA9C5__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class CFWzDichteDlg : public CDialog
{
	public:
	CFWzDichteDlg(CWnd* pParent = NULL);	

	//{{AFX_DATA(CFWzDichteDlg)
	enum { IDD = IDD_FWzDichte_DIALOG };
	CString	m_CMD;
	CString	m_x;
	int		m_modus;
	CString	m_grp;
	BOOL	m_ch_grp;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CFWzDichteDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	
	//}}AFX_VIRTUAL

	protected:
	HICON m_hIcon;

	//{{AFX_MSG(CFWzDichteDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnInfo();
	virtual void OnOK();
	afx_msg void OnCheckGrp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 

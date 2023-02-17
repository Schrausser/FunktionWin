//----------------------------------------------------------------------------------------------------|FWGeometricDlg.h, SCHRAUSSER 2009
//
#if !defined(AFX_FWGeometricDLG_H__E366356F_1D52_41BD_975D_AE4B1E4CA9C5__INCLUDED_)
#define AFX_FWGeometricDLG_H__E366356F_1D52_41BD_975D_AE4B1E4CA9C5__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class CFWGeometricDlg : public CDialog
{
	public:
	CFWGeometricDlg(CWnd* pParent = NULL);	

	//{{AFX_DATA(CFWGeometricDlg)
	enum { IDD = IDD_FWGeometric_DIALOG };
	CString	m_CMD;
	CString	m_n;
	CString	m_pa;
	BOOL	m_ch_grp;
	CString	m_grp;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CFWGeometricDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	
	//}}AFX_VIRTUAL

	protected:
	HICON m_hIcon;

	//{{AFX_MSG(CFWGeometricDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnInfo();
	virtual void OnOK();
	afx_msg void OnLog();
	afx_msg void OnLogp();
	afx_msg void OnCheckGrp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 

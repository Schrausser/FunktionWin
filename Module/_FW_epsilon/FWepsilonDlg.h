//----------------------------------------------------------------------------------------------------|FWepsilonDlg.h, SCHRAUSSER 2009
//
#if !defined(AFX_FWepsilonDLG_H__E366356F_1D52_41BD_975D_AE4B1E4CA9C5__INCLUDED_)
#define AFX_FWepsilonDLG_H__E366356F_1D52_41BD_975D_AE4B1E4CA9C5__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class CFWepsilonDlg : public CDialog
{
	public:
	CFWepsilonDlg(CWnd* pParent = NULL);	

	//{{AFX_DATA(CFWepsilonDlg)
	enum { IDD = IDD_FWepsilon_DIALOG };
	CEdit	m_q1_ctr;
	CEdit	m_e_ctr;
	CEdit	m_qx;
	CString	m_CMD;
	BOOL	m_ch_grp;
	CString	m_grp;
	CString	m_q0;
	CString	m_s;
	CString	m_n;
	CString	m_df;
	CString	m_p;
	CString	m_e;
	BOOL	m_ch_e;
	BOOL	m_ch_q1;
	CString	m_q1;
	CString	m_x;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CFWepsilonDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	
	//}}AFX_VIRTUAL

	protected:
	HICON m_hIcon;

	//{{AFX_MSG(CFWepsilonDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnInfo();
	virtual void OnOK();
	afx_msg void OnCheckGrp();
	afx_msg void OnLogp();
	afx_msg void OnSelchangee();
	afx_msg void OnCHECKe();
	afx_msg void OnCHECKq1();
	afx_msg void OnUpdatee();
	afx_msg void OnUpdateq1();
	afx_msg void OnUpdateqx();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 

//----------------------------------------------------------------------------------------------------|FWFisherEXACTDlg.h, SCHRAUSSER 2009
//
#if !defined(AFX_FWFisherEXACTDLG_H__E366356F_1D52_41BD_975D_AE4B1E4CA9C5__INCLUDED_)
#define AFX_FWFisherEXACTDLG_H__E366356F_1D52_41BD_975D_AE4B1E4CA9C5__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class CFWFisherEXACTDlg : public CDialog
{
	public:
	CFWFisherEXACTDlg(CWnd* pParent = NULL);	

	//{{AFX_DATA(CFWFisherEXACTDlg)
	enum { IDD = IDD_FWFisherEXACT_DIALOG };
	CString	m_CMD;
	BOOL	m_ch_grp;
	CString	m_grp;
	CString	m_a;
	CString	m_b;
	CString	m_c;
	CString	m_d;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CFWFisherEXACTDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	
	//}}AFX_VIRTUAL

	protected:
	HICON m_hIcon;

	//{{AFX_MSG(CFWFisherEXACTDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnInfo();
	virtual void OnOK();
	afx_msg void OnCheckGrp();
	afx_msg void OnLogp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 

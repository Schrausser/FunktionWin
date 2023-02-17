#if !defined(AFX_FW_FISHERZ_H__7C560E3D_6787_4E81_8B06_B2C841B50EDC__INCLUDED_)
#define AFX_FW_FISHERZ_H__7C560E3D_6787_4E81_8B06_B2C841B50EDC__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// FW_FISHERZ.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// FW_FISHERZ dialog

class FW_FISHERZ : public CDialog
{
// Construction
public:
	FW_FISHERZ(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(FW_FISHERZ)
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(FW_FISHERZ)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(FW_FISHERZ)
	virtual void OnOK();
	afx_msg void OnInfo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FW_FISHERZ_H__7C560E3D_6787_4E81_8B06_B2C841B50EDC__INCLUDED_)

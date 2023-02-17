//----------------------------------------------------------------------------------------------------| FW_INF.h von Dietmar Schrausser 2009    
//
#if !defined(AFX_FW_INF_H__28109692_55B0_4716_BF0A_647EEFD5E28F__INCLUDED_)
#define AFX_FW_INF_H__28109692_55B0_4716_BF0A_647EEFD5E28F__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class FW_INF : public CDialog
{
	public:
	FW_INF(CWnd* pParent = NULL);   

	//{{AFX_DATA(FW_INF)
	enum { IDD = IDD_FW_INF };
	CString	m_date;
	CString	m_time;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(FW_INF)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

	protected:
	//{{AFX_MSG(FW_INF)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 

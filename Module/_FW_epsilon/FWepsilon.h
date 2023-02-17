//----------------------------------------------------------------------------------------------------|FWepsilon.h, SCHRAUSSER 2010
//
#if !defined(AFX_FWepsilon_H__0AAAAE94_E8F1_4C30_86BA_B40597F3E177__INCLUDED_)
#define AFX_FWepsilon_H__0AAAAE94_E8F1_4C30_86BA_B40597F3E177__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 
#ifndef __AFXWIN_H__
#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		

class CFWepsilonApp : public CWinApp
{
	public:
	CFWepsilonApp();

	//{{AFX_VIRTUAL(CFWepsilonApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CFWepsilonApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif
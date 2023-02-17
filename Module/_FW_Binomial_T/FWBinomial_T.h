//----------------------------------------------------------------------------------------------------|FWBinomial_T.h, SCHRAUSSER 2010
//
#if !defined(AFX_FWBinomial_T_H__0AAAAE94_E8F1_4C30_86BA_B40597F3E177__INCLUDED_)
#define AFX_FWBinomial_T_H__0AAAAE94_E8F1_4C30_86BA_B40597F3E177__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 
#ifndef __AFXWIN_H__
#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		

class CFWBinomial_TApp : public CWinApp
{
	public:
	CFWBinomial_TApp();

	//{{AFX_VIRTUAL(CFWBinomial_TApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CFWBinomial_TApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif
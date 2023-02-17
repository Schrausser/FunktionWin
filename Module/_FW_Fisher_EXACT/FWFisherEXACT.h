//----------------------------------------------------------------------------------------------------|FWFisherEXACT.h, SCHRAUSSER 2009
//
#if !defined(AFX_FWFisherEXACT_H__0AAAAE94_E8F1_4C30_86BA_B40597F3E177__INCLUDED_)
#define AFX_FWFisherEXACT_H__0AAAAE94_E8F1_4C30_86BA_B40597F3E177__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 
#ifndef __AFXWIN_H__
#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		

class CFWFisherEXACTApp : public CWinApp
{
	public:
	CFWFisherEXACTApp();

	//{{AFX_VIRTUAL(CFWFisherEXACTApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CFWFisherEXACTApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif
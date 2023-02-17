//----------------------------------------------------------------------------------------------------| FunktionWin.h von Dietmar Schrausser 2009    
//
#if !defined(AFX_FUNKTIONWIN_H__AFF64653_ED92_4DB4_AFD2_B3B63986AA42__INCLUDED_)
#define AFX_FUNKTIONWIN_H__AFF64653_ED92_4DB4_AFD2_B3B63986AA42__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

#ifndef __AFXWIN_H__
#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"	

class CFunktionWinApp : public CWinApp
{
	public:
	CFunktionWinApp();

	//{{AFX_VIRTUAL(CFunktionWinApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CFunktionWinApp)
	afx_msg void OnProgrammInfo();
	afx_msg void OnProgrammBeenden();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnTransformationenFisherzfunktion();
	afx_msg void OnVerteilungsfunktionenNormalverteilungsfunktion();
	afx_msg void OnTransformationenGamma();
	afx_msg void OnVerteilungsfunktionenNormalverteilungsdichtefunktion();
	afx_msg void OnVerteilungsfunktionenTfunktion();
	afx_msg void OnVerteilungsfunktionenChiquadratfunktion();
	afx_msg void OnVerteilungsfunktionenFfunktion();
	afx_msg void OnWahrscheinlichkeitsfunktionenBinomialfunktion();
	afx_msg void OnWahrscheinlichkeitsfunktionenGeometrischefunktion();
	afx_msg void OnWahrscheinlichkeitsfunktionenPoissonfunktion();
	afx_msg void OnWahrscheinlichkeitsfunktionenHypergeometrischefunktion();
	afx_msg void OnWahrscheinlichkeitsfunktionenHypergeometrischer4feldertest();
	afx_msg void OnBinomialtest();
	afx_msg void OnEpsilon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 

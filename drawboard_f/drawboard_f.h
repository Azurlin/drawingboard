// drawboard_f.h : main header file for the drawboard_f application
//

#if !defined(AFX_drawboard_f_H__D56DD254_AC57_4494_BBE6_18463E504748__INCLUDED_)
#define AFX_drawboard_f_H__D56DD254_AC57_4494_BBE6_18463E504748__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// Cdrawboard_fApp:
// See drawboard_f.cpp for the implementation of this class
//

class Cdrawboard_fApp : public CWinApp
{
public:
	Cdrawboard_fApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cdrawboard_fApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(Cdrawboard_fApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_drawboard_f_H__D56DD254_AC57_4494_BBE6_18463E504748__INCLUDED_)

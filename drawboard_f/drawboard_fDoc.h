// drawboard_fDoc.h : interface of the Cdrawboard_fDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_drawboard_fDOC_H__AFF67CBD_CA80_49CD_9CF9_6411F71B2A7B__INCLUDED_)
#define AFX_drawboard_fDOC_H__AFF67CBD_CA80_49CD_9CF9_6411F71B2A7B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class Cdrawboard_fDoc : public CDocument
{
protected: // create from serialization only
	Cdrawboard_fDoc();
	DECLARE_DYNCREATE(Cdrawboard_fDoc)

// Attributes
public:
	int model;
	int color;
	int thickness;
	int wm_width;
	int wm_height;

// Operations
public:
	void SetTitle(LPCTSTR lpszTitle);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cdrawboard_fDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~Cdrawboard_fDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(Cdrawboard_fDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_drawboard_fDOC_H__AFF67CBD_CA80_49CD_9CF9_6411F71B2A7B__INCLUDED_)

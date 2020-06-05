// drawboard_fDoc.cpp : implementation of the Cdrawboard_fDoc class
//

#include "stdafx.h"
#include "drawboard_f.h"

#include "drawboard_fDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cdrawboard_fDoc

IMPLEMENT_DYNCREATE(Cdrawboard_fDoc, CDocument)

BEGIN_MESSAGE_MAP(Cdrawboard_fDoc, CDocument)
	//{{AFX_MSG_MAP(Cdrawboard_fDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cdrawboard_fDoc construction/destruction

Cdrawboard_fDoc::Cdrawboard_fDoc()
{
	// TODO: add one-time construction code here
	model = 0;
	color = RGB(0,0,0);
	thickness = 0;
}

Cdrawboard_fDoc::~Cdrawboard_fDoc()
{
}

BOOL Cdrawboard_fDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}
void Cdrawboard_fDoc::SetTitle(LPCTSTR lpszTitle)
{
   CDocument::SetTitle("计算机图形学");
}
/////////////////////////////////////////////////////////////////////////////
// Cdrawboard_fDoc serialization

void Cdrawboard_fDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// Cdrawboard_fDoc diagnostics

#ifdef _DEBUG
void Cdrawboard_fDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void Cdrawboard_fDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// Cdrawboard_fDoc commands

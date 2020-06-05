// drawboard_fView.cpp : implementation of the Cdrawboard_fView class
//

#include "stdafx.h"
#include "drawboard_f.h"
#include "math.h"
#include "drawboard_fDoc.h"
#include "drawboard_fView.h"
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cdrawboard_fView

IMPLEMENT_DYNCREATE(Cdrawboard_fView, CView)

BEGIN_MESSAGE_MAP(Cdrawboard_fView, CView)
	//{{AFX_MSG_MAP(Cdrawboard_fView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cdrawboard_fView construction/destruction

Cdrawboard_fView::Cdrawboard_fView()
{
	// TODO: add construction code here

}

Cdrawboard_fView::~Cdrawboard_fView()
{
}

BOOL Cdrawboard_fView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// Cdrawboard_fView drawing

void Cdrawboard_fView::OnDraw(CDC* pDC)
{
	Cdrawboard_fDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->MoveTo(0,pDoc->wm_height/2);
	pDC->LineTo(pDoc->wm_width,pDoc->wm_height/2);
	pDC->MoveTo(pDoc->wm_width/2,0);
	pDC->LineTo(pDoc->wm_width/2,pDoc->wm_height);
}

/////////////////////////////////////////////////////////////////////////////
// Cdrawboard_fView printing

BOOL Cdrawboard_fView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Cdrawboard_fView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Cdrawboard_fView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// Cdrawboard_fView diagnostics

#ifdef _DEBUG
void Cdrawboard_fView::AssertValid() const
{
	CView::AssertValid();
}

void Cdrawboard_fView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cdrawboard_fDoc* Cdrawboard_fView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cdrawboard_fDoc)));
	return (Cdrawboard_fDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// Cdrawboard_fView message handlers

void Cdrawboard_fView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	Cdrawboard_fDoc *pDoc = GetDocument();
	if(pDoc->model == 0)
	{
		//�ѵ�ǰ����ĵ��λ�ø�����m_point
		m_point = point;
		m_click = true;
	}
	else if(pDoc->model == 1)
	{	
		flag = 2;
		if( false==nClick)
		{
			m_Start = m_End = point;
			DrawCircle(false,m_Start,m_End);
			nClick=true;
		}
		else
		{
			DrawCircle(false,m_Start,m_End);
			nClick=false;
		}
	}
	else if(pDoc->model == 2)
	{
		flag = 3;
		if( false==nClick)
		{
			m_Start = m_End = point;
			DrawRect(false,m_Start,m_End);
			nClick=true;
		}
		else
		{
			DrawRect(false,m_Start,m_End);
			nClick=false;
		}
	}
	else if(pDoc->model == 3)
	{
		flag = 1;
		// ����ֱ��
		if( false==nClick)
		{
			m_Start = m_End = point;
			DrawLine(false,m_Start,m_End);
			nClick=true;
		}
		else
		{
			DrawLine(false,m_Start,m_End);
			nClick=false;
		}
	}
	else if(pDoc->model == 4)
	{
		flag = 4;
		if( false==nClick)
		{
			m_Start = m_End = point;
			DrawEllipse(false,m_Start,m_End);
			nClick=true;
		}
		else
		{
			DrawEllipse(false,m_Start,m_End);
			nClick=false;
		}
	}
	CView::OnLButtonDown(nFlags, point);
}

void Cdrawboard_fView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	Cdrawboard_fDoc *pDoc = GetDocument();
	if(pDoc->model == 0)
	{
		m_click = false;
	}
	CView::OnLButtonUp(nFlags, point);
}

void Cdrawboard_fView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CString str1; 
	str1.Format (_T("x=%d,y=%d  "),point.x,point.y); 
	CString str2; //��ȡϵͳʱ�� ����
	CTime tm;
	tm = CTime::GetCurrentTime();
	str2=tm.Format("����ʱ����%Y��%m��%d�� %X");
	((CMainFrame *)GetParent())->SetMessageText (str1+str2); 
	
	Cdrawboard_fDoc *pDoc = GetDocument();
	if(pDoc->model == 0)
	{
			//��ͼ	
		CDC *p=GetDC();
		CPen pen(PS_SOLID, pDoc->thickness, pDoc->color);
		p->SelectObject(pen);
 
		//��갴�½��л���
		if(m_click==true)
		{
			p->MoveTo(m_point);
			p->LineTo(point);
			m_point = point;
		}
	}
	else if(pDoc->model == 1)
	{
		if(nClick)
		{
			DrawCircle(true,m_Start,m_End);
			DrawCircle(true,m_Start,point);
			m_End=point;
		}
	}
	else if(pDoc->model == 2)
	{
		if(nClick)
		{
			DrawRect(true,m_Start,m_End);
			DrawRect(true,m_Start,point);
			m_End=point;
		}
	}
	else if(pDoc->model == 3)
	{
		if(nClick)
		{
			DrawLine(true,m_Start,m_End);
			DrawLine(true,m_Start,point);
			m_End=point;
		}
	}
	else if(pDoc->model == 4)
	{
		if(nClick)
		{
			DrawEllipse(true,m_Start,m_End);
			DrawEllipse(true,m_Start,point);
			m_End=point;
		}
	}
	CView::OnMouseMove(nFlags, point);
}

void Cdrawboard_fView::DrawCircle(bool isRubber, CPoint ptCenter, CPoint ptOnCircle)
{
	CDC* pDC = GetDC();
	// �뾶����
	Cdrawboard_fDoc *pDoc = GetDocument();
	float r1 = (float)((ptCenter.x-ptOnCircle.x)*(ptCenter.x-ptOnCircle.x) + (ptCenter.y-ptOnCircle.y)*(ptCenter.y-ptOnCircle.y));
	LONG r = sqrt(r1);
	// ����͸����ˢ
	CBrush *pBrush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	CBrush *pOldBrush =pDC->SelectObject(pBrush);
	if(isRubber)
	{
		pDC->SetROP2(R2_NOT);
		pDC->MoveTo(ptCenter.x,ptCenter.y);
		pDC->LineTo(ptOnCircle.x,ptOnCircle.y);
		// �뾶
		pDC->Ellipse(ptCenter.x-r,ptCenter.y-r,ptCenter.x+r,ptCenter.y+r);
	}
	else
	{
		CPen pen(PS_SOLID,pDoc->thickness,pDoc->color);
		CPen *pOldPen = pDC->SelectObject(&pen);
		pDC->Ellipse(ptCenter.x-r,ptCenter.y-r,ptCenter.x+r,ptCenter.y+r);
		pDC->SelectObject(pOldPen);
		pDC->SetROP2(R2_NOT);
		pDC->MoveTo(ptCenter.x,ptCenter.y);
		pDC->LineTo(ptOnCircle.x,ptOnCircle.y);
	}
	ReleaseDC(pDC);
}

// ���ƾ��Σ�ptUL: ���ϣ�ptLR: ����
void Cdrawboard_fView::DrawRect(bool isRubber, CPoint ptUL, CPoint ptLR)
{
	CDC* pDC = GetDC();
	Cdrawboard_fDoc *pDoc = GetDocument();
	// ����͸����ˢ
	CBrush *pBrush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	CBrush *pOldBrush =pDC->SelectObject(pBrush);
	if(isRubber)
	{
		pDC->SetROP2(R2_NOT);
		pDC->Rectangle(ptUL.x,ptUL.y,ptLR.x,ptLR.y);
	}
	else
	{
		CPen pen(PS_SOLID,pDoc->thickness,pDoc->color);
		CPen *pOldPen = pDC->SelectObject(&pen);
		pDC->Rectangle(ptUL.x,ptUL.y,ptLR.x,ptLR.y);
	}
	ReleaseDC(pDC);
}

void Cdrawboard_fView::DrawLine(bool isRubber, CPoint ptStart, CPoint ptEnd)
{
	CDC* pDC = GetDC();
	Cdrawboard_fDoc *pDoc = GetDocument();
	if(isRubber)
	{
		pDC->SetROP2(R2_NOT);
	}
	CPen pen(PS_SOLID,pDoc->thickness,pDoc->color);
	CPen *pOldPen = pDC->SelectObject(&pen);
	pDC->MoveTo(ptStart.x,ptStart.y);
	pDC->LineTo(ptEnd.x,ptEnd.y);
	pDC->SelectObject(pOldPen);
	ReleaseDC(pDC);
}
void Cdrawboard_fView::DrawEllipse(bool isRubber, CPoint ptUL, CPoint ptLR)
{
	CDC* pDC = GetDC();
	Cdrawboard_fDoc *pDoc = GetDocument();
	// ����͸����ˢ
	CBrush *pBrush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	CBrush *pOldBrush =pDC->SelectObject(pBrush);
	if(isRubber)
	{
		pDC->SetROP2(R2_NOT);
		pDC->Ellipse(ptUL.x,ptUL.y,ptLR.x,ptLR.y);
	}
	else
	{
		CPen pen(PS_SOLID,pDoc->thickness,pDoc->color);
		CPen *pOldPen = pDC->SelectObject(&pen);
		pDC->Ellipse(ptUL.x,ptUL.y,ptLR.x,ptLR.y);
	}
	ReleaseDC(pDC);
}

void Cdrawboard_fView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	// TODO: Add your message handler code here
	Cdrawboard_fDoc *pDoc = GetDocument();
	pDoc->wm_height = cy;
	pDoc->wm_width = cx;
}

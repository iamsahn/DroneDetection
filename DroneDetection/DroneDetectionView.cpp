
// DroneDetectionView.cpp : implementation of the CDroneDetectionView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "DroneDetection.h"
#endif

#include "DroneDetectionDoc.h"
#include "DroneDetectionView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDroneDetectionView

IMPLEMENT_DYNCREATE(CDroneDetectionView, CFormView)

BEGIN_MESSAGE_MAP(CDroneDetectionView, CFormView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDroneDetectionView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CDroneDetectionView construction/destruction

CDroneDetectionView::CDroneDetectionView()
	: CFormView(IDD_DRONEDETECTION_FORM)
{
	// TODO: add construction code here

}

CDroneDetectionView::~CDroneDetectionView()
{
}

void CDroneDetectionView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CDroneDetectionView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CDroneDetectionView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	ResizeParentToFit();

}


// CDroneDetectionView printing


void CDroneDetectionView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDroneDetectionView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDroneDetectionView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDroneDetectionView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CDroneDetectionView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

void CDroneDetectionView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDroneDetectionView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDroneDetectionView diagnostics

#ifdef _DEBUG
void CDroneDetectionView::AssertValid() const
{
	CFormView::AssertValid();
}

void CDroneDetectionView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDroneDetectionDoc* CDroneDetectionView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDroneDetectionDoc)));
	return (CDroneDetectionDoc*)m_pDocument;
}
#endif //_DEBUG


// CDroneDetectionView message handlers

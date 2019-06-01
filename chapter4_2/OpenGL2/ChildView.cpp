// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "OpenGL.h"
#include "ChildView.h"

#include "gl/gl.h"
#include "gl/glu.h"
#include "gl/glaux.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildView

CChildView::CChildView()
{
    m_hRC = NULL; 
    m_pDC = NULL; 
    m_nID = 0; 
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView,CWnd )
	//{{AFX_MSG_MAP(CChildView)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
    cs.style |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN; 
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS|CS_OWNDC, 
		::LoadCursor(NULL, IDC_ARROW), HBRUSH(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
    ::wglMakeCurrent(m_pDC->GetSafeHdc(), m_hRC); 

    GLfloat light_position[] = { 2.0f, 0.0f, 4.0f, 0.0f }; 
    ::glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    ::glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    ::glPushMatrix(); 
    ::glTranslatef(0.0f, 0.0f, 2.0f); 
    ::glLightfv(GL_LIGHT0, GL_POSITION, light_position); 
    ::glEnable(GL_LIGHTING); 
    ::glEnable(GL_LIGHT0); 
    ::glDepthFunc(GL_LESS); 
    ::glEnable(GL_DEPTH_TEST); 

    if(m_nID % 2 == 0)
    {
        ::auxSolidSphere(1); 
    }
    else 
    {
        ::auxWireSphere(1); 
    }

    ::glPopMatrix(); 
    ::glFinish(); 
    ::wglMakeCurrent(NULL, NULL); 
}


int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd ::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
    m_pDC = new CClientDC(this);       
    static PIXELFORMATDESCRIPTOR pfd =
    {
        sizeof(PIXELFORMATDESCRIPTOR), 1, 
        PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_TYPE_RGBA, 16, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0, 
        PFD_MAIN_PLANE, 0, 0, 0, 0
    }; 
    
    int pixelformat = ChoosePixelFormat(m_pDC->GetSafeHdc(), &pfd); 
    if(pixelformat == 0)
    {
        MessageBox("在该 DC 上找不到与 PFD 接近的位图结构."); 
        return -1; 
    }

    if(!SetPixelFormat(m_pDC->GetSafeHdc(), pixelformat, &pfd))
    {
        MessageBox("无法在该 DC 上设置位图结构."); 
        return -1; 
    }

    //m_hRC = ::wglCreateContext(m_pDC->GetSafeHdc()); 
    //::wglMakeCurrent(m_pDC->GetSafeHdc(), m_hRC); 
    //::glClearDepth(1.0f); 
    //::glEnable(GL_DEPTH_TEST); 
    //::glMatrixMode(GL_PROJECTION); 
    //::glLoadIdentity();

    int n = ::GetPixelFormat(m_pDC->GetSafeHdc()); 
    ::DescribePixelFormat(m_pDC->GetSafeHdc(), n, sizeof(pfd), &pfd); 
    m_hRC = ::wglCreateContext(m_pDC->GetSafeHdc()); 
    ::wglMakeCurrent(m_pDC->GetSafeHdc(), m_hRC); 
    //::wglMakeCurrent(NULL, NULL); 

    COpenGLApp* pApp = (COpenGLApp*)AfxGetApp(); 
    m_nID = pApp->m_nCount; 
	return 0;
}

void CChildView::OnDestroy() 
{
	CWnd ::OnDestroy();
	
	// TODO: Add your message handler code here
    ::wglMakeCurrent(m_pDC->GetSafeHdc(), m_hRC); 
    if(m_hRC != NULL)
        ::wglDeleteContext(m_hRC); 
    if(m_pDC != NULL)
        delete m_pDC; 
}

void CChildView::OnSize(UINT nType, int cx, int cy) 
{
	CWnd ::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
    
    ::glViewport(0, 0, cx, cy); 
    ::glMatrixMode(GL_PROJECTION); 
    ::glLoadIdentity(); 

    if(cx <= cy)
    {
        ::glOrtho(-3.0, 3.0, -3.0 * (GLfloat)cx / (GLfloat)cy, 3.0 * (GLfloat)cx / (GLfloat)cy, -3.0, 3.0); 
    }
    else 
        ::glOrtho(-3.0, 3.0, -3.0 * (GLfloat)cy / (GLfloat)cx, 3.0 * (GLfloat)cy / (GLfloat)cx, -3.0, 3.0); 

    ::glMatrixMode(GL_MODELVIEW); 
}

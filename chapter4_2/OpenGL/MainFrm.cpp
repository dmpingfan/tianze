// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "OpenGL.h"
#include "MainFrm.h"

#include "gl/glu.h"
#include "gl/gl.h"
#include "gl/glaux.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
    m_pDC = NULL; 
    m_hrc = NULL; 

}

CMainFrame::~CMainFrame()
{
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(
        CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW | CS_SAVEBITS | CS_OWNDC, // | CS_NOCLOSE, 
        AfxGetApp()->LoadStandardCursor(IDC_ARROW), 0,
        AfxGetApp()->LoadStandardIcon(IDI_APPLICATION));

	return TRUE;
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

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

    m_hrc = ::wglCreateContext(m_pDC->GetSafeHdc()); 
    ::wglMakeCurrent(m_pDC->GetSafeHdc(), m_hrc); 
    ::glClearDepth(1.0f); 
    ::glEnable(GL_DEPTH_TEST); 
    ::glMatrixMode(GL_PROJECTION); 
    ::glLoadIdentity();    

	return 0;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnSize(UINT nType, int cx, int cy) 
{
	CFrameWnd::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	if(cy > 0)
    {
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
}

void CMainFrame::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
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
    ::auxSolidSphere(1); 
    //::auxSolidCube(1); 
    //::auxSolidBox(1, 2, 0.5); 
    //::auxWireSphere(1); 
    //::auxSolidTeapot(0.5); 
    //::auxWireTeapot(1); 
    ::glPopMatrix(); 
    ::glFinish(); 
}

BOOL CMainFrame::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
    return TRUE; 
	//return CFrameWnd::OnEraseBkgnd(pDC);
}

void CMainFrame::OnDestroy() 
{
	CFrameWnd::OnDestroy();
	
	// TODO: Add your message handler code here
    ::wglMakeCurrent(NULL, NULL); 
    if(m_hrc)
        ::wglDeleteContext(m_hrc);
    if(m_pDC)
        delete m_pDC; 
}

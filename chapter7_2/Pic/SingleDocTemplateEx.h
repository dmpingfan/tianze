// SingleDocTemplateEx.h: interface for the CSingleDocTemplateEx class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SINGLEDOCTEMPLATEEX_H__45ACF1F1_A753_4C7D_9EAD_2B85144A1983__INCLUDED_)
#define AFX_SINGLEDOCTEMPLATEEX_H__45ACF1F1_A753_4C7D_9EAD_2B85144A1983__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSingleDocTemplateEx : public CSingleDocTemplate  
{
public:
	CSingleDocTemplateEx(UINT nIDResource, CRuntimeClass* pDocClass,
		CRuntimeClass* pFrameClass, CRuntimeClass* pViewClass);
	virtual ~CSingleDocTemplateEx();
	virtual Confidence MatchDocType(LPCTSTR lpszPathName,
					CDocument*& rpDocMatch);

};

#endif // !defined(AFX_SINGLEDOCTEMPLATEEX_H__45ACF1F1_A753_4C7D_9EAD_2B85144A1983__INCLUDED_)

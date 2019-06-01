// Menu.h: interface for the CCustomMenu class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MENU_H__D5CDF922_42B0_431F_BF04_AB292789DB69__INCLUDED_)
#define AFX_MENU_H__D5CDF922_42B0_431F_BF04_AB292789DB69__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class MENUDATA
{
public:
	MENUDATA() 
	{
		menuIconNormal = -1; 
		menuIconSelected = -1; 
	}

	char menuText[32]; 
	UINT menuIconNormal; 
	UINT menuIconSelected; 
}; 

typedef enum { Normal, TextOnly} HIGHLIGHTSTYLE; 


class CCustomMenu : public CMenu  
{
public:
	CCustomMenu();
	virtual ~CCustomMenu();

public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct); 
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct); 
	void SetTextColor(COLORREF clr); 
	void SetBackColor(COLORREF clr); 
	void SetHighlightColor(COLORREF clr); 
	void SetIconSize(int cx, int cy); 
	void SetHighlightStyle(HIGHLIGHTSTYLE style); 
	void SetHighlightTextColor(COLORREF clr); 

protected:
	COLORREF m_crText; 
	COLORREF m_clrBack; 
	COLORREF m_clrText; 
	COLORREF m_clrHilight; 
	COLORREF m_clrHilightText; 
	LOGFONT m_lf; 
	CFont m_fontMenu; 
	UINT m_iMenuHeight; 
	BOOL m_bLBtnDown; 
	CBrush m_brBackground; 
	CBrush m_brSelect; 
	CPen m_penBack; 
	int m_iconX; 
	int m_iconY; 
	HIGHLIGHTSTYLE m_hilightStyle; 
};

#endif // !defined(AFX_MENU_H__D5CDF922_42B0_431F_BF04_AB292789DB69__INCLUDED_)

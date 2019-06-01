// ELISSet.h : interface of the CELISSet class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ELISSET_H__6385DB98_AD2B_4F4A_9279_622E07A753F3__INCLUDED_)
#define AFX_ELISSET_H__6385DB98_AD2B_4F4A_9279_622E07A753F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CELISSet : public CRecordset
{
public:
	CELISSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CELISSet)

// Field/Param Data
	//{{AFX_FIELD(CELISSet, CRecordset)
    //long    m_ID;
    //long    m_ToolID;
    //CString    m_Name;
    //float    m_Offset;
    //CString    m_OffsetUnit;
    //CString    m_IsDisplay;
	long	m_ID;
	CString	m_Name;
	CString	m_Remark;
	CString	m_ImagePath;
	CString	m_SN;
	float	m_Length;
	CString	m_LengthUnit;
	float	m_Weight;
	CString	m_WeightUnit;
	float	m_OutterDiameter;
	CString	m_OutterDiameterUnit;
	float	m_InnerDiameter;
	CString	m_InnerDiameterUnit;
	float	m_TemperatureEndure;
	CString	m_TemperatureEndureUnit;
	float	m_PressureEndure;
	CString	m_PressureEndureUnit;
	float	m_MaxSpeed;
	CString	m_MaxSpeedUnit;
	int	m_DisplayMask;
	CString	m_TopTransformer;
	CString	m_BottomTransformer;
	//}}AFX_FIELD
    CString m_strNameLike; 

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CELISSet)
	public:
	virtual CString GetDefaultConnect();	// Default connection string
	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ELISSET_H__6385DB98_AD2B_4F4A_9279_622E07A753F3__INCLUDED_)


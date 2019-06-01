// DBSet.h : interface of the CDBSet class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DBSET_H__A1DD2358_1AAA_4FE0_A238_C50967A0AAC0__INCLUDED_)
#define AFX_DBSET_H__A1DD2358_1AAA_4FE0_A238_C50967A0AAC0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDBSet : public CRecordset
{
public:
	CDBSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CDBSet)

// Field/Param Data
	//{{AFX_FIELD(CDBSet, CRecordset)
    //CString    m_ID;
    //CString    m_Name;
    //CString    m_Remark;
    //CString    m_ImagePath;
    //CString    m_SN;
    //float    m_Length;
    //CString    m_LengthUnit;
    //float    m_Weight;
    //CString    m_WeightUnit;
    //float    m_OutterDiameter;
    //CString    m_OutterDiameterUnit;
    //float    m_InnerDiameter;
    //CString    m_InnerDiameterUnit;
    //float    m_TemperatureEndure;
    //CString    m_TemperatureEndureUnit;
    //float    m_PressureEndure;
    //CString    m_PressureEndureUnit;
    //float    m_MaxSpeed;
    //CString    m_MaxSpeedUnit;
    //int    m_DisplayMask;
    //CString    m_TopTransformer;
    //CString    m_BottomTransformer;
	//}}AFX_FIELD
    CStringArray m_arrFields; 
    CStringArray m_arrValues; 

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDBSet)
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

#endif // !defined(AFX_DBSET_H__A1DD2358_1AAA_4FE0_A238_C50967A0AAC0__INCLUDED_)


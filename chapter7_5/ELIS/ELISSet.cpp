// ELISSet.cpp : implementation of the CELISSet class
//

#include "stdafx.h"
#include "ELIS.h"
#include "ELISSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CELISSet implementation

IMPLEMENT_DYNAMIC(CELISSet, CRecordset)

CELISSet::CELISSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CELISSet)
    //m_ID = 0;
    //m_ToolID = 0;
    //m_Name = _T("");
    //m_Offset = 0.0f;
    //m_OffsetUnit = _T("");
    //m_IsDisplay = _T("");
	m_ID = 0;
	m_Name = _T("");
	m_Remark = _T("");
	m_ImagePath = _T("");
	m_SN = _T("");
	m_Length = 0.0f;
	m_LengthUnit = _T("");
	m_Weight = 0.0f;
	m_WeightUnit = _T("");
	m_OutterDiameter = 0.0f;
	m_OutterDiameterUnit = _T("");
	m_InnerDiameter = 0.0f;
	m_InnerDiameterUnit = _T("");
	m_TemperatureEndure = 0.0f;
	m_TemperatureEndureUnit = _T("");
	m_PressureEndure = 0.0f;
	m_PressureEndureUnit = _T("");
	m_MaxSpeed = 0.0f;
	m_MaxSpeedUnit = _T("");
	m_DisplayMask = 0;
	m_TopTransformer = _T("");
	m_BottomTransformer = _T("");
	m_nFields = 22;
	//}}AFX_FIELD_INIT
    m_strNameLike = _T(""); 
    m_nParams = 1; 
    m_strFilter = "Name = ?"; 
	m_nDefaultType = snapshot;
}

CString CELISSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=ELISEN");
}

CString CELISSet::GetDefaultSQL()
{
    //return _T("[SensorInformation],[ToolInformation]");
    return _T("[ToolInformation]"); 
}

void CELISSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CELISSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
    //RFX_Long(pFX, _T("[SensorInformation].[ID]"), m_ID);
    //RFX_Long(pFX, _T("[ToolID]"), m_ToolID);
    //RFX_Text(pFX, _T("[SensorInformation].[Name]"), m_Name);
    //RFX_Single(pFX, _T("[Offset]"), m_Offset);
    //RFX_Text(pFX, _T("[OffsetUnit]"), m_OffsetUnit);
    //RFX_Text(pFX, _T("[IsDisplay]"), m_IsDisplay);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[Name]"), m_Name);
	RFX_Text(pFX, _T("[Remark]"), m_Remark);
	RFX_Text(pFX, _T("[ImagePath]"), m_ImagePath);
	RFX_Text(pFX, _T("[SN]"), m_SN);
	RFX_Single(pFX, _T("[Length]"), m_Length);
	RFX_Text(pFX, _T("[LengthUnit]"), m_LengthUnit);
	RFX_Single(pFX, _T("[Weight]"), m_Weight);
	RFX_Text(pFX, _T("[WeightUnit]"), m_WeightUnit);
	RFX_Single(pFX, _T("[OutterDiameter]"), m_OutterDiameter);
	RFX_Text(pFX, _T("[OutterDiameterUnit]"), m_OutterDiameterUnit);
	RFX_Single(pFX, _T("[InnerDiameter]"), m_InnerDiameter);
	RFX_Text(pFX, _T("[InnerDiameterUnit]"), m_InnerDiameterUnit);
	RFX_Single(pFX, _T("[TemperatureEndure]"), m_TemperatureEndure);
	RFX_Text(pFX, _T("[TemperatureEndureUnit]"), m_TemperatureEndureUnit);
	RFX_Single(pFX, _T("[PressureEndure]"), m_PressureEndure);
	RFX_Text(pFX, _T("[PressureEndureUnit]"), m_PressureEndureUnit);
	RFX_Single(pFX, _T("[MaxSpeed]"), m_MaxSpeed);
	RFX_Text(pFX, _T("[MaxSpeedUnit]"), m_MaxSpeedUnit);
	RFX_Int(pFX, _T("[DisplayMask]"), m_DisplayMask);
	RFX_Text(pFX, _T("[TopTransformer]"), m_TopTransformer);
	RFX_Text(pFX, _T("[BottomTransformer]"), m_BottomTransformer);
	//}}AFX_FIELD_MAP
    pFX->SetFieldType(CFieldExchange::param); 
    RFX_Text(pFX, _T("Name"), m_strNameLike); 
}

/////////////////////////////////////////////////////////////////////////////
// CELISSet diagnostics

#ifdef _DEBUG
void CELISSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CELISSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

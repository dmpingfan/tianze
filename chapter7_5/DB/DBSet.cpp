// DBSet.cpp : implementation of the CDBSet class
//

#include "stdafx.h"
#include "DB.h"
#include "DBSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDBSet implementation

IMPLEMENT_DYNAMIC(CDBSet, CRecordset)

CDBSet::CDBSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CDBSet)
    //m_ID = _T("");
    //m_Name = _T("");
    //m_Remark = _T("");
    //m_ImagePath = _T("");
    //m_SN = _T("");
    //m_Length = 0.0f;
    //m_LengthUnit = _T("");
    //m_Weight = 0.0f;
    //m_WeightUnit = _T("");
    //m_OutterDiameter = 0.0f;
    //m_OutterDiameterUnit = _T("");
    //m_InnerDiameter = 0.0f;
    //m_InnerDiameterUnit = _T("");
    //m_TemperatureEndure = 0.0f;
    //m_TemperatureEndureUnit = _T("");
    //m_PressureEndure = 0.0f;
    //m_PressureEndureUnit = _T("");
    //m_MaxSpeed = 0.0f;
    //m_MaxSpeedUnit = _T("");
    //m_DisplayMask = 0;
    //m_TopTransformer = _T("");
    //m_BottomTransformer = _T("");
	//}}AFX_FIELD_INIT
    m_nFields = 22;
    m_arrFields.SetSize(22); 
    m_arrValues.SetSize(22); 
    m_arrFields[0] = "[ID]"; 
    m_arrFields[1] = "[Name]"; 
    m_arrFields[2] = "[Remark]"; 
    m_arrFields[3] = "[ImagePath]"; 
    m_arrFields[4] = "[SN]"; 
    m_arrFields[5] = "[Length]"; 
    m_arrFields[6] = "[LengthUnit]"; 
    m_arrFields[7] = "[Weight]"; 
    m_arrFields[8] = "[WeightUnit]"; 
    m_arrFields[9] = "[OutterDiameter]"; 
    m_arrFields[10] = "[OutterDiameterUnit]"; 
    m_arrFields[11] = "[InnerDiameter]"; 
    m_arrFields[12] = "[InnerDiameterUnit]"; 
    m_arrFields[13] = "[TemperatureEndure]"; 
    m_arrFields[14] = "[TemperatureEndureUnit]"; 
    m_arrFields[15] = "[PressureEndure]"; 
    m_arrFields[16] = "[PressureEndureUnit]"; 
    m_arrFields[17] = "[MaxSpeed]"; 
    m_arrFields[18] = "[MaxSpeedUnit]"; 
    m_arrFields[19] = "[DisplayMask]"; 
    m_arrFields[20] = "[TopTransformer]"; 
    m_arrFields[21] = "[BottomTransformer]"; 

	m_nDefaultType = snapshot;
}

CString CDBSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=ELISEN");
}

CString CDBSet::GetDefaultSQL()
{
	return _T("[ToolInformation]");
}

void CDBSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CDBSet)
    pFX->SetFieldType(CFieldExchange::outputColumn);
    //RFX_Text(pFX, _T("[ID]"), m_ID);
    //RFX_Text(pFX, _T("[Name]"), m_Name);
    //RFX_Text(pFX, _T("[Remark]"), m_Remark);
    //RFX_Text(pFX, _T("[ImagePath]"), m_ImagePath);
    //RFX_Text(pFX, _T("[SN]"), m_SN);
    //RFX_Single(pFX, _T("[Length]"), m_Length);
    //RFX_Text(pFX, _T("[LengthUnit]"), m_LengthUnit);
    //RFX_Single(pFX, _T("[Weight]"), m_Weight);
    //RFX_Text(pFX, _T("[WeightUnit]"), m_WeightUnit);
    //RFX_Single(pFX, _T("[OutterDiameter]"), m_OutterDiameter);
    //RFX_Text(pFX, _T("[OutterDiameterUnit]"), m_OutterDiameterUnit);
    //RFX_Single(pFX, _T("[InnerDiameter]"), m_InnerDiameter);
    //RFX_Text(pFX, _T("[InnerDiameterUnit]"), m_InnerDiameterUnit);
    //RFX_Single(pFX, _T("[TemperatureEndure]"), m_TemperatureEndure);
    //RFX_Text(pFX, _T("[TemperatureEndureUnit]"), m_TemperatureEndureUnit);
    //RFX_Single(pFX, _T("[PressureEndure]"), m_PressureEndure);
    //RFX_Text(pFX, _T("[PressureEndureUnit]"), m_PressureEndureUnit);
    //RFX_Single(pFX, _T("[MaxSpeed]"), m_MaxSpeed);
    //RFX_Text(pFX, _T("[MaxSpeedUnit]"), m_MaxSpeedUnit);
    //RFX_Int(pFX, _T("[DisplayMask]"), m_DisplayMask);
    //RFX_Text(pFX, _T("[TopTransformer]"), m_TopTransformer);
    //RFX_Text(pFX, _T("[BottomTransformer]"), m_BottomTransformer);
	//}}AFX_FIELD_MAP
    for(int i=0; i<m_nFields; i++)
        RFX_Text(pFX, m_arrFields[i], m_arrValues[i]); 
}

/////////////////////////////////////////////////////////////////////////////
// CDBSet diagnostics

#ifdef _DEBUG
void CDBSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDBSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

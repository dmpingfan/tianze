// DataObject.cpp: implementation of the CDataObject class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Serial.h"
#include "DataObject.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_SERIAL(CDataObject, CObject, 1)

CDataObject::CDataObject()
{
    m_nNumber = 100; 
    m_strName = "YunHai"; 
}

CDataObject::~CDataObject()
{

}

void CDataObject::Serialize(CArchive& ar)
{
    if(ar.IsStoring())
    {
        ar << GetRuntimeClass()->m_wSchema; 
        ar << m_strName; 
        ar << m_nNumber; 
    }
    else 
    {
        UINT nVersion = 0; 
        ar >> nVersion; 
        switch(nVersion)
        {
            case 0:
                ar >> m_nNumber; 
                ar >> m_strName; 
                break; 
            case 1:
                ar >> m_strName; 
                ar >> m_nNumber; 
                break; 
            default:
                CString str; 
                str.Format("Unknown schema number %d.", nVersion); 
                AfxMessageBox(str); 
                break; 
        }
    }
}
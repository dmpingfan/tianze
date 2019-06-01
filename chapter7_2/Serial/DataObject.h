// DataObject.h: interface for the CDataObject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATAOBJECT_H__4CD76AC8_D203_41BE_AE03_BE617F2AA334__INCLUDED_)
#define AFX_DATAOBJECT_H__4CD76AC8_D203_41BE_AE03_BE617F2AA334__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDataObject : public CObject  
{
    DECLARE_SERIAL(CDataObject)
public:
	CDataObject();
	virtual ~CDataObject();
    virtual void Serialize(CArchive& ar); 

public:
    int m_nNumber; 
    CString m_strName; 
};

#endif // !defined(AFX_DATAOBJECT_H__4CD76AC8_D203_41BE_AE03_BE617F2AA334__INCLUDED_)

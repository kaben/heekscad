// Sphere.h
// Copyright (c) 2009, Dan Heeks
// This program is released under the BSD license. See the file COPYING for details.

#pragma once

#include "Solid.h"

class CSphere: public CSolid{
protected:
	static wxIcon* m_icon;

	// CShape's virtual functions
	CShape* MakeTransformedShape(const gp_Trsf &mat);
	wxString StretchedName();

public:
	gp_Pnt m_pos;
	double m_radius;

	CSphere(const gp_Pnt& pos, double radius, const wxChar* title, const HeeksColor& col);
	CSphere(const TopoDS_Solid &solid, const wxChar* title, const HeeksColor& col);

	virtual const CSphere& operator=(const CSphere& s);

	// HeeksObj's virtual functions
	const wxChar* GetTypeString(void)const{return _("Sphere");}
	wxString GetIcon(){return wxGetApp().GetResFolder() + _T("/icons/sphere");}
	HeeksObj *MakeACopy(void)const;
	void GetProperties(std::list<Property *> *list);
	void GetGripperPositions(std::list<GripData> *list, bool just_for_endof);
	void OnApplyProperties();
	bool GetCentrePoint(double* pos);
	bool GetScaleAboutMatrix(double *m);
	bool IsDifferent(HeeksObj* other);
	bool DescendForUndo(){return false;}

	// CShape's virtual functions
	void SetXMLElement(TiXmlElement* element);
	void SetFromXMLElement(TiXmlElement* pElem);

	// CSolid's virtual functions
	SolidTypeEnum GetSolidType(){return SOLID_TYPE_SPHERE;}
};

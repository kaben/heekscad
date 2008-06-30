// DigitizeMode.h
#pragma once

#include "../interface/InputMode.h"

class CViewPoint;
class PointOrWindow;

enum DigitizeType{
	DigitizeNoItemType,
	DigitizeEndofType,
	DigitizeIntersType,
	DigitizeMidpointType,
	DigitizeCentreType,
	DigitizeScreenType,
	DigitizeCoordsType,
	DigitizeNearestType
};


class DigitizeMode:public CInputMode{
private:
	PointOrWindow *point_or_window;
	gp_Pnt lbutton_position;
	DigitizeType lbutton_type_found;
	std::set<HeeksObj*> m_only_coords_set;

	DigitizeType digitize1(const wxPoint &input_point, gp_Pnt &point, gp_Pnt &closest_point);

public:
	gp_Pnt position_found;
	DigitizeType digitize_type_found;

	DigitizeMode();
	virtual ~DigitizeMode(void);

	// InputMode's virtual functions
	void OnMouse( wxMouseEvent& event );
	bool OnModeChange(void);
	void OnFrontRender();
	void GetProperties(std::list<Property *> *list);
	void GetSharedProperties(std::list<Property *> *list);

	DigitizeType Digitize(const gp_Lin &ray, gp_Pnt &point);
	DigitizeType digitize(const wxPoint &point);
	void SetOnlyCoords(HeeksObj* object, bool onoff);
	bool OnlyCoords(HeeksObj* object);
};
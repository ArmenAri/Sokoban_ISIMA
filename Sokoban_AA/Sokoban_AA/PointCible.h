#pragma once

#ifndef POINT_CIBLE_
#define POINT_CIBLE_

#include "CaseClassique.h"

class PointCible : public CaseClassique {

public:
	PointCible(Point point);

	/*
	*@return : la nature de la case
	*/
	int NatureCase();
};

#endif

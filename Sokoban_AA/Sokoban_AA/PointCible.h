#pragma once

#ifndef POINT_CIBLE_
#define POINT_CIBLE_

#include "Cases.h"

class PointCible : public Cases {

public:
	PointCible(Point point);

	/*
	*@return : la nature de la case
	*/
	int NatureCase();
};

#endif

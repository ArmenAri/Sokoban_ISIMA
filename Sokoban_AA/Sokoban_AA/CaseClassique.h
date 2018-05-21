#pragma once

#ifndef CASE_CLASSIQUE_
#define CASE_CLASSIQUE_

#include "Cases.h"

class CaseClassique : public Cases {

public:
	CaseClassique(Point point);
	/*
	*@return : la nature de la case
	*/
	int NatureCase();
};

#endif

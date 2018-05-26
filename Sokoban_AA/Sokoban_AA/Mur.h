#pragma once

#ifndef MUR_
#define MUR_

#include "Cases.h"

class Mur : public Cases 
{

public:
	Mur(Point point);

	/*
	*@return : la nature de la case
	*/
	int NatureCase();
};

#endif
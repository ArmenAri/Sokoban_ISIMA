#pragma once

#ifndef PION_
#define PION_

#include "Point.h"

class Pion 
{
private:
	Point m_coordonnees;

public:
	Pion();
	Pion(Point p);

	/*
	*@return : le point corresspondant aux positions du pion
	*/
	Point get_position();

	/*
	*@param : p
	*@brief : met les positions du joueur à p
	*/
	void set_position(Point p);
};

#endif

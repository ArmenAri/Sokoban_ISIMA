#pragma once
#ifndef POINT_
#define POINT_

#include <math.h>
#include <iostream>
#include <string>

class Point 
{
private:
	int m_x, m_y;

public:
	Point();
	Point(int, int);

	/*
	*@return : la coordonnee x du point
	*/
	int get_x();

	/*
	*@return : la coordonnee y du point
	*/
	int get_y();

	/*
	*@brief : surchage l'opérateur + pour la classe Point
	*/
	Point& operator+ (const Point& point);
};

#endif
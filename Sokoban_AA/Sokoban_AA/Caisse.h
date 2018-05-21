#pragma once

#ifndef CAISSE_
#define CAISSE_

#include "Point.h"

class Caisse {
private:
	Point m_coordonnees;
	int m_id;

public:
	Caisse();
	Caisse(Point point, int id);
};

#endif

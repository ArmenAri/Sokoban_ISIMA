#include "Caisse.h"

Caisse::Caisse()
{
	m_coordonnees = Point(0, 0);
}

Caisse::Caisse(Point point, int id)
{
	m_coordonnees = point;
	m_id = id;
}

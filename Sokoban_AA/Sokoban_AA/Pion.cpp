#include "Pion.h"

Pion::Pion()
{
}

Pion::Pion(Point p)
{
	m_coordonnees = p;
}

Point Pion::get_position()
{
	return m_coordonnees;
}

void Pion::set_position(Point p)
{
	m_coordonnees = p;
}

#include "Cases.h"

Cases::Cases(Point point)
{
	m_coordonnees = point;
	m_possCaisse = false;
	m_possPion = false;
}

bool Cases::PossCaisse()
{
	return m_possCaisse;
}

bool Cases::PossPion()
{
	return m_possPion;
}

void Cases::setPossPion(bool b)
{
	m_possPion = b;
}

void Cases::setPossCaisse(bool b)
{
	m_possCaisse = b;
}

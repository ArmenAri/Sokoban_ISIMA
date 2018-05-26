#include "Chronometre.h"

Chronometre::Chronometre()
{

}

void Chronometre::start()
{
	m_temps = time(NULL);
}

void Chronometre::start(time_t temps)
{
	m_temps = time(NULL) - temps;
}

double Chronometre::stop()
{
	return difftime(time(NULL), m_temps);
}

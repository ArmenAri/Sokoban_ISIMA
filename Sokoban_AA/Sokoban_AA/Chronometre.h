#pragma once

#ifndef CHRONOMETRE_
#define CHRONOMETRE_

#include <time.h>

class Chronometre {
private:
	time_t m_temps;

public:
	Chronometre();
	/*
	*@brief : demarre le chronometre
	*/
	void start();
	/*
	*@param : temps
	*@brief : demarre le chronometre avec comme temps de départ temps
	*/
	void start(time_t temps);
	/*
	*@brief : arrete le chronometre
	*@return : le temps écoulé depuis l'appel de la fonction start()
	*/
	time_t stop();
};

#endif

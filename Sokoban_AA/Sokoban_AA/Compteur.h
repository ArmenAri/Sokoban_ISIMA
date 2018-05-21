#pragma once

#ifndef COMPTEUR_
#define COMPTEUR_

class Compteur {
private:
	int m_nbCoup;

public:
	Compteur();
	/*
	*@brief : enleve 1 au nombre de coups m_nbCoup
	*/
	void decrementerCoup();

	/*
	*@brief : ajoute 1 au nombre de coups m_nbCoup
	*/
	void incrementerCoup();

	/*
	*@brief : demarre le compteur en initialisant m_nbCoup à 0
	*/
	void start();

	/*
	*@param : nbCoup
	*@brief : demarre le compteur en initialisant m_nbCoup à nbCoup
	*/
	void start(int nbCoup);

	/*
	*@brief : arrete le compteur
	*@return : le nombre de coups m_nbCoup
	*/
	int stop();

	/*
	*@return : le nombre de coups m_nbCoup
	*/
	int nombreCoup();
};

#endif

#include "Compteur.h"

Compteur::Compteur()
{

}

void Compteur::decrementerCoup()
{
	m_nbCoup--;
}

void Compteur::incrementerCoup()
{
	m_nbCoup++;
}

void Compteur::start()
{
	m_nbCoup = 0;
}

void Compteur::start(int nbCoup)
{
	m_nbCoup = nbCoup;
}

int Compteur::stop()
{
	return m_nbCoup;
}

int Compteur::nombreCoup()
{
	return m_nbCoup;
}
#pragma once

#ifndef PARTIE_
#define PARTIE_

#include "Niveau.h"

class Partie {
private:
	Niveau m_niveau;
	int m_score;
	int m_niveauCourant;

public:
	Partie();
	int nivPartieCourant();

	/*
	*@param : niveau
	*@brief : recharge le niveau niveau
	*/
	void recommencerNiveau(int niveau);

	/*
	*@param : niveau
	*@brief : charge le niveau niveau à partir du fichier correspondant
	*/
	void chargerNiveau(int niveau);

	/*
	*@brief : recommence le niveau 1
	*/
	void recommencerPartie();

	/*
	*@brief : commence le niveau suivant
	*/
	void passerNiveauSuivant();

	/*
	*@brief : commence la partie
	*/
	void start();

	/*
	*@brief : affiche l'aide utilisateur
	*/
	void afficherAide();

};

#endif // !PARTIE_


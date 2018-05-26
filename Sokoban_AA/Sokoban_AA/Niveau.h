#pragma once

#ifndef NIVEAU_
#define NIVEAU_

#include "Plateau.h"
#include "CaseClassique.h"
#include "Compteur.h"
#include "Chronometre.h"
#include <fstream>
#include <iostream>
#include <sstream>

class Niveau {

private:
	Compteur compteur;
	Chronometre chronometre;
	Plateau m_plateau;
	Plateau m_old_plateau;
	int m_nbCiasse;
	int m_resultat;
	int m_numeroNiveau;

public:
	Niveau();
	Niveau(int niveau);
	Niveau(int niveau, bool charger);

	/*
	*@brief : charge le plateau avant le dernier coup
	*/
	void annulerDernierCoup();

	/*
	*@param : direction
	*@brief : bouge le pion dans la direction direction
	*/
	void bougerPion(int direction);

	/*
	*@param : nomFichier
	*@brief : initialise le plateau avec les donnée du fichier nomFichier
	*/
	void InitialiserPlateau(std::string nomFichier);

	/*
	*@param : nomFichier
	*@brief : initialise le plateau avec les donnée du fichier nomFichier
	*/
	void InitialiserPlateauDefaut(std::string nomFichier);

	/*
	*@param : nomFichier
	*@brief : ecrit le chronometre, le compteur, les positions des caisse et du pion dans le fichier nomFichier
	*/
	void SauvegarderNiveau(std::string nomFichier);

	/*
	*@param : nomFichier
	*@brief : charge le plateau à partir du fichier nomFichier
	*/
	void ChargerNiveau(std::string nomFichier);

	/*
	*@return : le nombre de coup executé
	*/
	int nbCoupExecute();

	/*
	*@return : true si le joueur à gagné false sinon
	*/
	bool testSiGagner();

	/*
	*@brief : affiche le niveau
	*/
	void afficherNiveau();
};

#endif

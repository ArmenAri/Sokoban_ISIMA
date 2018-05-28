#pragma once

#if defined(_WIN32)
#include <Windows.h>
#define WIN true
#define colorWin(param) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), param | BACKGROUND_INTENSITY)
#elif defined(__linux__)
#define WIN false
#endif

#ifndef PLATEAU_
#define PLATEAU_

#include <iostream>
#include <vector>
#include <algorithm>

#include "CaseClassique.h"
#include "Mur.h"
#include "PointCible.h"
#include "Caisse.h"
#include "Pion.h"
#include "colors.h"

class Plateau 
{

private:
	Pion pion;
	Cases ***m_cases;
	int m_xSize, m_ySize, m_nbCaisse;
	int m_ICaisseD;

public:
	Plateau();
	~Plateau();
	Plateau(int largeur, int longueur);

	/*
	*@return : la hauteur du plateau
	*/
	int get_ySize();

	/*
	*@return : la largeur du plateau
	*/
	int get_xSize();

	/*
	*@param : direction
	*@brief : deplace le pion dans la direction direction
	*/
	void deplacerPion(int direction);

	/*
	*@return : true si le joueur à gagné false sinon
	*/
	bool gagner();

	/*
	*@param : i, j
	*@return : la nature de la case à la position i, j
	*/
	int natureCasePlateau(int i, int j);

	/*
	*@param : p
	*@brief : met le boolean possCaisse de la case à la position p à true
	*/
	void positionnerCaisse(Point p, int i);

	/*
	*@param : p
	*@brief : place un Mur à la position p
	*/
	void positionnerMur(Point p);

	/*
	*@param : p
	*@brief : met le boolean possPion de la case à la position p à true
	*/
	void positionnerPion(Point p);

	/*
	*@param : p
	*@brief : place un PointCible à la position p
	*/
	void positionnerPointCible(Point p);

	/*
	*@param : p
	*@brief : place une CaseClassique à la position p
	*/
	void positionnerCaseClassique(Point p);

	/*
	*@param : p
	*@brief : met le boolean possCaisse de la case à la position p à true
	*/
	void chargerCaisse(Point p);

	/*
	*@param : p
	*@brief : met le boolean possPion de la case à la position p à true
	*/
	void chargerPion(Point p);

	/*
	*@param : i, j
	*@return : true si la case à la position i et j possede une Caisse
	*/
	bool possedeCaissePlateau(int i, int j);

	/*
	*@param : i, j
	*@return : true si la case à la position i et j possede un Pion
	*/
	bool possedePionPlateau(int i, int j);

	/*
	*@brief : affiche le plateau
	*/
	void afficherPlateau();

	/*
	*@return : 0 si le pion ne peux pas se déplacer, 1 si il peut et 2 si il y a une caisse devant lui
	*/
	int peutDeplacer(Point direction);

	/*
	*@param : plateau
	*@brief : copie le plateau plateau dans this
	*/
	void copy(Plateau * plateau);
};

#endif
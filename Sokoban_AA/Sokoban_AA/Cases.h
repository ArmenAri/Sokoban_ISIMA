#pragma once

#ifndef CASES_
#define CASES_

#include "Point.h"

/*
*Classe abstraite Cases
*/
class Cases {
private:
	Point m_coordonnees;
	bool m_possCaisse;
	bool m_possPion;

public:
	Cases(Point point);
	/*
	*@brief : methode abstraite qui retourne la nature de la case
	*/
	virtual int NatureCase() = 0;
	/*
	*@return : un boolean qui indique si la case possede une caisse
	*/
	bool PossCaisse();
	/*
	*@return : un boolean qui indique si la case possede un pion
	*/
	bool PossPion();
	/*
	*@param : b
	*@brief : met le boolean m_possPion à b
	*/
	void setPossPion(bool b);
	/*
	*@param : b
	*@brief : met le boolean m_possCaisse à b
	*/
	void setPossCaisse(bool b);
};

#endif

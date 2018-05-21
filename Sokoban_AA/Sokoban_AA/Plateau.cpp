#include "Plateau.h"

Plateau::Plateau()
{
	m_xSize = 0;
	m_ySize = 0;
}

Plateau::Plateau(int xSize, int ySize)
{
	m_xSize = xSize;
	m_ySize = ySize;
	m_cases = new Cases **[m_ySize];
	for (int i = 0; i < m_ySize; i++)
	{
		m_cases[i] = new Cases*[m_xSize];
	}
}

int Plateau::get_ySize()
{
	return m_ySize;
}

int Plateau::get_xSize()
{
	return m_xSize;
}

bool Plateau::annulerDernierCoupPlateau()
{
	//TODO:
	return false;
}

/*
*	dirs : (-> 6), (<- 4), (8), (2)
*/
void Plateau::deplacerPion(int direction)
{
	int peutBouger = 0;
	Point dir;
	Point p(0, 0);
	switch (direction)
	{
	case 6:
		dir = Point(1, 0);
		peutBouger = peutDeplacer(dir);
		p = pion.get_position() + dir;

		if (peutBouger)
		{
			m_cases[pion.get_position().get_y()][pion.get_position().get_x()]->setPossPion(false);
			m_cases[p.get_y()][p.get_x()]->setPossPion(true);
			pion.set_position(p);

			if (peutBouger == 2)
			{
				Point p_caisse = p + dir;
				(m_cases[p.get_y()][p.get_x()])->setPossCaisse(false);
				m_cases[p_caisse.get_y()][p_caisse.get_x()]->setPossCaisse(true);
			}
		}
		break;
	case 4:
		dir = Point(-1, 0);
		peutBouger = peutDeplacer(dir);
		p = pion.get_position() + dir;

		if (peutBouger)
		{
			m_cases[pion.get_position().get_y()][pion.get_position().get_x()]->setPossPion(false);
			m_cases[p.get_y()][p.get_x()]->setPossPion(true);
			pion.set_position(p);

			if (peutBouger == 2)
			{
				Point p_caisse = p + dir;
				(m_cases[p.get_y()][p.get_x()])->setPossCaisse(false);
				m_cases[p_caisse.get_y()][p_caisse.get_x()]->setPossCaisse(true);
			}
		}
		break;
	case 2:
		dir = Point(0, 1);
		peutBouger = peutDeplacer(dir);
		p = pion.get_position() + dir;

		if (peutBouger)
		{
			m_cases[pion.get_position().get_y()][pion.get_position().get_x()]->setPossPion(false);
			m_cases[p.get_y()][p.get_x()]->setPossPion(true);
			pion.set_position(p);

			if (peutBouger == 2)
			{
				Point p_caisse = p + dir;
				(m_cases[p.get_y()][p.get_x()])->setPossCaisse(false);
				m_cases[p_caisse.get_y()][p_caisse.get_x()]->setPossCaisse(true);
			}
		}
		break;
	case 8:
		dir = Point(0, -1);
		peutBouger = peutDeplacer(dir);
		p = pion.get_position() + dir;

		if (peutBouger)
		{
			m_cases[pion.get_position().get_y()][pion.get_position().get_x()]->setPossPion(false);
			m_cases[p.get_y()][p.get_x()]->setPossPion(true);
			pion.set_position(p);

			if (peutBouger == 2)
			{
				Point p_caisse = p + dir;
				(m_cases[p.get_y()][p.get_x()])->setPossCaisse(false);
				m_cases[p_caisse.get_y()][p_caisse.get_x()]->setPossCaisse(true);
			}
		}
		break;
	default:
		std::cout << "Direction invalide !" << std::endl;
		break;
	}
}

bool Plateau::gagner()
{
	bool aGagne = true;
	for (int j = 0; j < m_ySize; j++)
	{
		for (int i = 0; i < m_xSize; i++)
		{
			if ((natureCasePlateau(j, i) == 2) && !possedeCaissePlateau(j, i))
			{
				aGagne = false;
			}
		}
	}
	return aGagne;
}

int Plateau::natureCasePlateau(int i, int j)
{
	return (m_cases[i][j])->NatureCase();
}

void Plateau::positionnerCaisse(Point p, int i)
{
	m_cases[p.get_y()][p.get_x()] = new CaseClassique(p);
	(m_cases[p.get_y()][p.get_x()])->setPossCaisse(true);
}

void Plateau::positionnerPion(Point p)
{
	pion = Pion(p);
	m_cases[p.get_y()][p.get_x()] = new CaseClassique(p);
	(m_cases[p.get_y()][p.get_x()])->setPossPion(true);
}

void Plateau::chargerCaisse(Point p)
{
	m_cases[p.get_y()][p.get_x()]->setPossCaisse(true);
}

void Plateau::chargerPion(Point p)
{
	pion = Pion(p);
	m_cases[p.get_y()][p.get_x()]->setPossPion(true);
}

void Plateau::positionnerMur(Point p)
{
	m_cases[p.get_y()][p.get_x()] = new Mur(p);
}

void Plateau::positionnerPointCible(Point p)
{
	m_cases[p.get_y()][p.get_x()] = new PointCible(p);
}

void Plateau::positionnerCaseClassique(Point p)
{
	m_cases[p.get_y()][p.get_x()] = new CaseClassique(p);
}

bool Plateau::possedeCaissePlateau(int i, int j)
{
	if ((m_cases[i][j])->PossCaisse()) {
		return true;
	}
	return false;
}

bool Plateau::possedePionPlateau(int i, int j)
{
	if ((m_cases[i][j])->PossPion()) {
		return true;
	}
	return false;
}

void Plateau::afficherPlateau()
{
	for (int y = 0; y < m_ySize; y++) {
		for (int x = 0; x < m_xSize; x++) {
			if (natureCasePlateau(y, x) == 1) /*Mur*/
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 | BACKGROUND_INTENSITY);
				std::cout << "  ";
			}
			else if (possedePionPlateau(y, x)) /*Pion*/
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 * 16 | BACKGROUND_INTENSITY);
				std::cout << "^^";
			}
			else if (possedeCaissePlateau(y, x)) /*Caisse*/
			{
				if (natureCasePlateau(y, x) == 2)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13 * 16 | BACKGROUND_INTENSITY);
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9 * 16 | BACKGROUND_INTENSITY | 15);
				}
				std::cout << "><";
			}
			else if (natureCasePlateau(y, x) == 2) /*PointCible*/
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 * 16 | BACKGROUND_INTENSITY);
				std::cout << "<>";
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16);
				std::cout << "  ";
			}
		}
		std::cout << std::endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

int Plateau::peutDeplacer(Point direction)
{
	Point new_position = pion.get_position() + direction;
	if (new_position.get_x() < 0 || new_position.get_x() >= m_xSize || new_position.get_y() < 0 || new_position.get_y() >= m_ySize)
	{
		return 0;
	}
	if ((m_cases[new_position.get_y()][new_position.get_x()])->NatureCase() == 1)
	{
		return 0;
	}
	else if (possedeCaissePlateau(new_position.get_y(), new_position.get_x()))
	{
		Point next_position = new_position + direction;
		if (next_position.get_x() < 0 || next_position.get_x() >= m_xSize || next_position.get_y() < 0 || next_position.get_y() >= m_ySize)
		{
			return 0;
		}
		else if ((m_cases[next_position.get_y()][next_position.get_x()])->NatureCase() == 1)
		{
			return 0;
		}
		else if (possedeCaissePlateau(next_position.get_y(), next_position.get_x()))
		{
			return 0;
		}
		else
		{
			return 2;
		}
	}
	return 1;
}

void Plateau::copy(Plateau & plateau)
{
	pion = plateau.pion;

	for (int y = 0; y < m_ySize; y++)
	{
		for (int x = 0; x < m_xSize; x++)
		{
			m_cases[y][x]->setPossCaisse(plateau.m_cases[y][x]->PossCaisse());
			m_cases[y][x]->setPossPion(plateau.m_cases[y][x]->PossPion());
		}
	}

}

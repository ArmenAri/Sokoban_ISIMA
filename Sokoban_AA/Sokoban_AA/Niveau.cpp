#include "Niveau.h"

Niveau::Niveau()
{
	InitialiserPlateau("niveau1.txt");
	compteur.start();
	chronometre.start();
}

Niveau::Niveau(int numero)
{
	std::ostringstream oss;
	oss << "niveau" << numero << ".txt";
	InitialiserPlateau(oss.str());
	compteur.start();
	chronometre.start();
}

Niveau::Niveau(int numero, bool charger)
{
	if (charger)
	{
		std::ostringstream oss;
		std::ostringstream sauvegarde;
		oss << "niveau" << numero << ".txt";
		sauvegarde << "niveau" << numero << ".sav";
		InitialiserPlateauDefaut(oss.str());
		ChargerNiveau(sauvegarde.str());
	}
	else
	{
		Niveau(numero);
	}
}

void Niveau::dechargerNiveau()
{
	delete(m_plateau); 
	delete(m_old_plateau);
}

void Niveau::annulerDernierCoup()
{
	m_plateau->copy(m_old_plateau);
}

void Niveau::bougerPion(int direction)
{
	m_old_plateau->copy(m_plateau);
	m_plateau->deplacerPion(direction);
	compteur.incrementerCoup();
}

void Niveau::InitialiserPlateau(std::string nomFichier)
{
	std::ifstream monFlux(nomFichier.c_str());

	int xSize, ySize;
	char c;
	int caisse_id = 0;

	if (monFlux)
	{
		monFlux >> xSize;
		monFlux >> ySize;

		m_plateau = new Plateau(xSize, ySize);
		m_old_plateau = new Plateau(xSize, ySize);

		for (int y = 0; y < m_plateau->get_ySize(); y++)
		{
			for (int x = 0; x < m_plateau->get_xSize(); x++)
			{
				monFlux >> c;
				if (c == 'M') {
					m_plateau->positionnerMur(Point(x, y));
					m_old_plateau->positionnerMur(Point(x, y));
				}
				else if (c == 'O') {
					m_plateau->positionnerPointCible(Point(x, y));
					m_old_plateau->positionnerPointCible(Point(x, y));
				}
				else if (c == 'P') {
					m_plateau->positionnerPion(Point(x, y));
					m_old_plateau->positionnerPion(Point(x, y));
				}
				else if (c == 'C') {
					m_plateau->positionnerCaisse(Point(x, y), caisse_id);
					m_old_plateau->positionnerCaisse(Point(x, y), caisse_id);
					caisse_id++;
				}
				else {
					m_plateau->positionnerCaseClassique(Point(x, y));
					m_old_plateau->positionnerCaseClassique(Point(x, y));
				}
			}
		}
		monFlux.close();
		m_old_plateau->copy(m_plateau);
	}
	else
	{
		std::cout << "ERREUR : Impossible d'ouvrir le fichier en lecture." << std::endl;
	}
}

void Niveau::InitialiserPlateauDefaut(std::string nomFichier)
{
	std::ifstream monFlux(nomFichier.c_str());

	int xSize, ySize;
	char c;
	int caisse_id = 0;

	if (monFlux)
	{
		monFlux >> xSize;
		monFlux >> ySize;

		m_plateau = new Plateau(xSize, ySize);
		m_old_plateau = new Plateau(xSize, ySize);

		for (int y = 0; y < m_plateau->get_ySize(); y++)
		{
			for (int x = 0; x < m_plateau->get_xSize(); x++)
			{
				monFlux >> c;
				if (c == 'M')
				{
					m_plateau->positionnerMur(Point(x, y));
					m_old_plateau->positionnerMur(Point(x, y));
				}
				else if (c == 'O')
				{
					m_plateau->positionnerPointCible(Point(x, y));
					m_old_plateau->positionnerPointCible(Point(x, y));
				}
				else
				{
					m_plateau->positionnerCaseClassique(Point(x, y));
					m_old_plateau->positionnerCaseClassique(Point(x, y));
				}
			}
		}
		monFlux.close();
		m_old_plateau->copy(m_plateau);
	}
	else
	{
		std::cout << "ERREUR : Impossible d'ouvrir le fichier en lecture." << std::endl;
	}
}

void Niveau::SauvegarderNiveau(std::string nomFichier) {
	std::ofstream outfile(nomFichier);
	int caseType = 0;
	outfile << nbCoupExecute() << '\n';
	outfile << chronometre.stop() << '\n';

	for (int y = 0; y < m_plateau->get_ySize(); y++)
	{
		for (int x = 0; x < m_plateau->get_xSize(); x++)
		{
			if (m_plateau->possedeCaissePlateau(y, x)) {
				outfile << "C" << ";" << x << ";" << y << '\n';
			}
			else if (m_plateau->possedePionPlateau(y, x)) {
				outfile << "P" << ";" << x << ";" << y << '\n';
			}
		}
	}
	outfile.close();
}

void Niveau::ChargerNiveau(std::string nomFichier)
{
	std::string ligne;
	int nbCoup;
	time_t temps;
	std::ifstream monFlux(nomFichier.c_str());

	monFlux >> nbCoup;
	monFlux >> temps;

	compteur.start(nbCoup);
	chronometre.start(temps);

	while (std::getline(monFlux, ligne))
	{
		if (ligne != "")
		{
			unsigned int i = 2;
			std::string coordonnee = "";
			int x, y;
			while (i < ligne.length() && ligne[i] != ';')
			{
				coordonnee += ligne[i];
				i++;
			}
			x = stoi(coordonnee);
			coordonnee.clear();
			i++;
			while (i < ligne.length() && ligne[i] != '/n')
			{
				coordonnee += ligne[i];
				i++;
			}
			y = stoi(coordonnee);

			if (ligne[0] == 'C')
			{
				m_plateau->chargerCaisse(Point(x, y));
			}
			else if (ligne[0] == 'P')
			{
				m_plateau->chargerPion(Point(x, y));
			}
		}
	}
	monFlux.close();
}

int Niveau::nbCoupExecute()
{
	return compteur.nombreCoup();
}

bool Niveau::testSiGagner()
{
	if (m_plateau->gagner()) {
		std::cout << "Vous avez termine le niveau en : " << chronometre.stop() << "sec." << std::endl;
		std::cout << "Nombre de coups : " << nbCoupExecute() << std::endl;
	}
	return m_plateau->gagner();
}

void Niveau::afficherNiveau()
{
	m_plateau->afficherPlateau();
}

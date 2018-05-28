#include "Partie.h"


Partie::Partie()
{
	m_niveau = Niveau();
	m_niveauCourant = 1;
}

int Partie::nivPartieCourant()
{
	return m_niveauCourant;
}

void Partie::recommencerNiveau(int niveau)
{
	m_niveau = Niveau(niveau);
	m_niveauCourant = niveau;
}

void Partie::chargerNiveau(int niveau)
{
	m_niveau.dechargerNiveau();
	m_niveau = Niveau(niveau, true);
	m_niveauCourant = niveau;
}

/* Le probleme c'est que on fait un nouveau niveau*/
/* L'ancien niveau lui il est pas détruit Ah !!!!
*/

void Partie::recommencerPartie()
{
	m_score = 0;
	m_niveauCourant = 1;
	m_niveau = Niveau();
}

void Partie::passerNiveauSuivant()
{
	m_niveauCourant++;
	m_niveau = Niveau(m_niveauCourant);
}

void Partie::start()
{
	bool isQuiting = false;
	//int input = 0;
	char input;
	//std::cout << "------------- .:: SOKOBAN ARMENIEN ::. -------------" << std::endl << std::endl;
	afficherAide();
	m_niveau.afficherNiveau();
	do {
		std::ifstream ifs;
		std::ostringstream oss;
		//std::cin >> input;
		std::cin >> input;
		input -= 48;
		system("cls"); //TODO : Change on linux os

		switch (input)
		{
		case 5:
			m_niveau.annulerDernierCoup();
			break;
		case 0:
			recommencerPartie();
			break;
		case 1:
			int niveau;
			char ouiOuNon;
			std::cin >> niveau;
			oss << "niveau" << niveau << ".sav";
			ifs.open(oss.str());
			if (ifs.fail()) {
				recommencerNiveau(niveau);
			}
			else 
			{
				std::cout << "Voulez vous charger le niveau depuis la sauvegarde ? [Y/N]" << std::endl;
				std::cin >> ouiOuNon;
				if (ouiOuNon == 'Y' || ouiOuNon == 'y')
				{
					chargerNiveau(niveau);
				}
				else
				{
					recommencerNiveau(niveau);
				}
			}
			ifs.close();
			break;
		case 9:
			afficherAide();
			break;
		case 7:
			isQuiting = true;
			break;
		default:
			m_niveau.bougerPion(input);
			std::ostringstream ostrings;
			ostrings << m_niveauCourant;
			m_niveau.SauvegarderNiveau(("niveau" + ostrings.str() + ".sav"));
			break;
		}
		if (m_niveau.testSiGagner()) {
			passerNiveauSuivant();
		}
		std::cout << "NIVEAU " << m_niveauCourant << std::endl;
		m_niveau.afficherNiveau();
	} while (!m_niveau.testSiGagner() && !isQuiting);
}

void Partie::afficherAide()
{
	std::cout << "---------------- .: AIDE SOKOBAN :. ----------------" << std::endl;
	std::cout << "	Afficher aide : 9" << std::endl;
	std::cout << "	Deplacements :" << std::endl;
	std::cout << "		- 8 : haut" << std::endl;
	std::cout << "		- 2 : bas" << std::endl;
	std::cout << "		- 4 : gauche" << std::endl;
	std::cout << "		- 6 : droite" << std::endl;
	std::cout << "	Recommencer partie : 0" << std::endl;
	std::cout << "	Recommencer niveau : 1 + numero du niveau" << std::endl;
	std::cout << "	Quitter le jeu : 7" << std::endl;
	std::cout << "---------------------------------------------------" << std::endl << std::endl;
}
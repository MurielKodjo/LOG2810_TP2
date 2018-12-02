#include "lexique.h"
#include "Mot.h"
#include <fstream>
#include <iostream>

Lexique::Lexique()
{
	
}

Lexique::Lexique(string nomFichier)
{
	lectureFichier(nomFichier);
}

Lexique::~Lexique()
{
}

void Lexique::clear()
{
	vecLexique_.clear();
}

void Lexique::lectureFichier(string nomFichier)
{
	ifstream fichier(nomFichier) ;
	
	if (!fichier.fail()) {
		Mot motLu = Mot();
		string ligne;
		while (getline(fichier, ligne))
		{
			size_t found = ligne.find(" ");
			motLu.setValeurMot(ligne.substr(0, found));
			this->vecLexique_.push_back(motLu);
		}
		fichier.close();
	}
	else
		cout << "Impossible d'ouvrir le fichier " << nomFichier << " !" << endl;
}

void Lexique::setVecLexique(vector<string> vectMot)
{
}

int Lexique::getNombreUtilisation(string mot)
{
	for (int i = 0; i < vecLexique_.size(); i++)
	{
		if (vecLexique_[i].getValeurMot() == mot)
		{
			return vecLexique_[i].getNbUtilisation();
		}
	}
	cout << "Le mot entr\202 n'est pas dans le lexique !" << endl;
	return 0 ; 
}

vector<Mot> Lexique::getVecLexique()
{
	return vecLexique_;
}

void Lexique::setMotRecent(string mot)
{
	motRecent_.addElement(mot);
	for (int i = 0; i < vecLexique_.size(); i++)
	{
		if (vecLexique_[i].getValeurMot() == mot)
		{
			vecLexique_[i].augmenterNbUtilisation();
			break;
		}
	}
}

cinqPremier Lexique::getMotRecent()
{
	return motRecent_;
}
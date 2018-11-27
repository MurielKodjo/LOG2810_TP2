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

int Lexique::getPremierLabel(string mot)
{
	for (int i = 0; i < vecLexique_.size(); i++)
	{
		if (vecLexique_[i].getValeurMot() == mot)
		{
			return vecLexique_[i].getNbUtilisation();
		}
	}
	return 0 ; //retourne exception "Mot pas dans lexique"
}

int Lexique::getSecondLabel(string mot)
{
	for (int i = 0; i < vecLexique_.size(); i++)
	{
		if (vecLexique_[i].getValeurMot() == mot)
		{
			return int(vecLexique_[i].getUtilisation());
		}
	}
	return 0; //retourne exception "Mot pas dans lexique"
}

vector<Mot> Lexique::getVecLexique()
{
	return vecLexique_;
}

//AJOUTÉ PAR HORBY POUR TEST----------------------------------------------------
void Lexique::setVecLexique(vector<Mot> vectMot)
{
	vecLexique_ = vectMot;
}
//------------------------------------------------------------------------------

void Lexique::incrementerNbUtilisation(Mot* mot)
{
	int ancienNbUtilisation = mot->getNbUtilisation();
	int nouveauNbUtilisation = ancienNbUtilisation + 1;
	mot->setNbUtilisation(nouveauNbUtilisation);
}

void Lexique::actualiserMotRecent(Mot* mot)
{
	for (int i = 0; i < vecMotRecent_->size(); i++)
	{
		if (mot == &vecLexique_[i])
		{
			return;
		}
	}
	vector<Mot*>::iterator it = vecMotRecent_->begin();
	vecMotRecent_->insert(it, mot);
	vector<Mot*>::iterator end = vecMotRecent_->end();
	vecMotRecent_->erase(end);
}
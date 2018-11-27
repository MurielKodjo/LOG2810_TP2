#pragma once

#include <vector>
#include <string>
#include "Mot.h"
#include "VariablesGlobales.h"
using namespace std;

class Lexique
{
public:
	Lexique();
	Lexique(string nomFichier);
	~Lexique();
	void lectureFichier(string nomFichier);
	void setVecLexique(vector<string> vectMot);
	int getPremierLabel(string mot);
	int getSecondLabel(string mot);

	//AJOUTÉ PAR HORBY-------------------------------------
	vector<Mot> getVecLexique();
	void incrementerNbUtilisation(Mot* mot);
	void actualiserMotRecent(Mot* mot);
	vector<Mot*> getMotRecent();
	void setVecLexique(vector<Mot> vectMot); // AJOUTÉ POUR TEST
	//-----------------------------------------------------

private:
	vector<Mot> vecLexique_ ;
	vector<Mot*> vecMotRecent_[NB_MOTS_SAUVEGARDES];
};


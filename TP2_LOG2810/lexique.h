#pragma once

#include <vector>
#include <string>
#include "Mot.h"
#include "cinqPremier.h"
using namespace std;

class Lexique
{
public:
	Lexique();
	Lexique(string nomFichier);
	~Lexique();
	void lectureFichier(string nomFichier);
	void setVecLexique(vector<string> vectMot);
	int getNombreUtilisation(string mot);
	void setMotRecent(string mot);
	cinqPremier getMotRecent();
	vector<Mot> getVecLexique();

private:
	vector<Mot> vecLexique_ ;
	cinqPremier motRecent_;
};


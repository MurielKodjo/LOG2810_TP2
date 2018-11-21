#pragma once

#include <vector>
#include <string>
#include "Mot.h"
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
private:
	vector<Mot> vecLexique_ ;
	Mot vecMotRecent_[5];
};


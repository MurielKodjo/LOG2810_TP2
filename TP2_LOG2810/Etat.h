#pragma once
#include "lexique.h"

using namespace std;

class Etat
{
public:
	Etat(string prefix);

	string getPrefix();

	bool getEtatFinal();
	void setEtatFinal(bool estEtatFinal);

	vector<Mot> getMotsPossibles();
	void setMotsPossibles(Lexique* lexique);

private:
	string prefix_;
	bool etatFinal_;
	vector<Mot> motsPossibles_;

};

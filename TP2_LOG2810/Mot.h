#pragma once
#include <string>

using namespace std;

class Mot
{
public:
	Mot();
	~Mot();
	int getNbUtilisation();
	bool getUtilisation();
	string getValeurMot();
	void setUtilisationRecente(bool recent);
	void setNbUtilisation(int nombre);
	void setValeurMot(string mot);
private:
	string valeur_;
	int nbUtilisation_;
	bool recemmentUtilise_;
};

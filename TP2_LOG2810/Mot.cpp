#include "Mot.h"

Mot::Mot(): nbUtilisation_(0), recemmentUtilise_(false)
{
}

Mot::~Mot()
{
}

int Mot::getNbUtilisation()
{
	return nbUtilisation_;
}

bool Mot::getUtilisation()
{
	return recemmentUtilise_;
}

string Mot::getValeurMot()
{
	return valeur_;
}

void Mot::setUtilisationRecente(bool recent)
{
	recemmentUtilise_ = recent;
}

void Mot::setNbUtilisation(int nombre)
{
	nbUtilisation_ = nombre;
}

void Mot::setValeurMot(string mot)
{
	valeur_ = mot;
}

#include "Etat.h"

Etat::Etat(string prefix)
{
	prefix_ = prefix;
}

string Etat::getPrefix()
{
	return prefix_;
}

bool Etat::getEtatFinal()
{
	return etatFinal_;
}

void Etat::setEtatFinal(bool estEtatFinal)
{
	etatFinal_ = estEtatFinal;
}

vector<Mot> Etat::getMotsPossibles()
{
	return motsPossibles_;
}

void Etat::setMotsPossibles(Lexique* lexique)
{
	for (int i = 0; i < lexique->getVecLexique().size(); i++)
	{
		if (prefix_.size() < lexique->getVecLexique()[i].getValeurMot().size())
		{
			string prefixMotDuLexique = "";
			for (int j = 0; j < prefix_.size(); j++)
			{
				prefixMotDuLexique += lexique->getVecLexique()[i].getValeurMot()[j];
			}
			if (prefix_ == prefixMotDuLexique)
			{
				motsPossibles_.push_back(lexique->getVecLexique()[i]);
			}
		}
	}
}
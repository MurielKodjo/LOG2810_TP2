#include "Automate.h"
#include "variablesGlobales.h"
#include <iostream>

Automate::Automate(Lexique* langageReconnu)
{
	motFinaux_ = langageReconnu;
	prefixEntree_ = "";
	start_ = new Etat("");
	construireFSM();
	etatPresent_ = start_;
}

void Automate::construireFSM()
{
	etats_.push_back(start_);
	for (int i = 0; i < motFinaux_->getVecLexique().size(); i++)
	{
		string prefix = "";
		for (int j = 0; j < motFinaux_->getVecLexique()[i].getValeurMot().size(); j++)
		{
			char lettre = motFinaux_->getVecLexique()[i].getValeurMot()[j];
			actualiserAlphabet(lettre);
			prefix += lettre;
			actualiserFSM(prefix);
		}
	}
	for (int k = 0; k < etats_.size(); k++)
	{
		etats_[k]->setMotsPossibles(motFinaux_);
	}
}

void Automate::actualiserFSM(string prefix)
{
	for (int i = 0; i < etats_.size(); i++)
	{
		//S'il existe déjà un état pour ce préfix, ne pas créer un doublon
		if (prefix == etats_[i]->getPrefix())
		{
			return;
		}
	}
	//On crée un état, s'il n'existe pas un état pour ce prefix
	Etat* nouveauEtat = new Etat(prefix);
	for (int i = 0; i < motFinaux_->getVecLexique().size(); i++)
	{
		if (prefix == motFinaux_->getVecLexique()[i].getValeurMot())
		{
			nouveauEtat->setEtatFinal(true);
			etatsFinaux_.push_back(nouveauEtat);
		}
	}
	etats_.push_back(nouveauEtat);
}

void Automate::actualiserAlphabet(char lettre)
{
	for (int i = 0; i < alphabet_.size(); i++)
	{
		if (lettre == alphabet_[i])
		{
			return;
		}
	}
	alphabet_.push_back(lettre);
}

bool Automate::presentDansAlphabet(char lettre)
{
	for (int i = 0; i < alphabet_.size(); i++)
	{
		if (lettre == alphabet_[i])
		{
			return true;
		}
	}
	return false;
}

void Automate::transition(char entree)
{
	string nouveauPrefix = etatPresent_->getPrefix() + entree;
	prefixEntree_ += entree;
	if (presentDansAlphabet(entree))
	{
		for (int i = 0; i < etats_.size(); i++)
		{
			if (nouveauPrefix == etats_[i]->getPrefix())
			{
				etatPresent_ = etats_[i];
				proposer();
				return;
			}
		}
		cout << "Malheureusement, il n'existe aucun mot correspondant a votre entr\202e dans le lexique selectionne. Veuillez entrer une lettre valide" << endl << endl;
		etatPresent_ = start_;
	}
	else
	{
		etatPresent_ = start_;
		if (entree != TOUCHE_SPACE)
		{
			cout << "Cette entree ne fait pas partie de l'alphabet du lexique selectionne. Veuillez entrer une lettre valide" << endl << endl;
		}
	}
}

void Automate::proposer()
{
	if (etatPresent_->getMotsPossibles().empty())
	{
		if (etatPresent_->getEtatFinal())
		{
			cout << "Il n'existe aucune proposition possible" << endl;
		}
	}
	else
	{
		cout << "Vouliez-vous ecrire : " << endl;
		for (int i = 0; i < etatPresent_->getMotsPossibles().size(); i++)
		{
			cout << (i + 1) << ") " << etatPresent_->getMotsPossibles()[i].getValeurMot() << endl;
		}
		cout << endl;
	}
}

Lexique* Automate::getLexique()
{
	return motFinaux_;
}

string Automate::getPrefixEntree()
{
	return prefixEntree_;
}
#include "Automate.h"
#include "VariablesGlobales.h"
#include <iostream>

Automate::Automate(Lexique* langageReconnu)
{
	motFinaux_ = langageReconnu;
	prefixEntree_ = ""; //INUTILE?
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

string Automate::transition(char entree)
{
	if (presentDansAlphabet(entree))
	{
		string nouveauPrefix = etatPresent_->getPrefix() + entree;
		for (int i = 0; i < etats_.size(); i++)
		{
			if (nouveauPrefix == etats_[i]->getPrefix())
			{
				prefixEntree_ = nouveauPrefix; //INUTILE?
				etatPresent_ = etats_[i];
				string propositions = proposer();
				return propositions;
			}
		}
		nouveauPrefix = "" + entree;
		for (int i = 0; i < etats_.size(); i++)
		{
			if (nouveauPrefix == etats_[i]->getPrefix())
			{
				prefixEntree_ = nouveauPrefix; //INUTILE?
				etatPresent_ = etats_[i];
				string propositions = proposer();
				return propositions;
			}
		}
		etatPresent_ = start_;
		prefixEntree_ = "";
	}
	else
	{
		if (entree == ESPACE || entree == RETOUR_DE_LIGNE)
		{
			actualiserLabels();
			etatPresent_ = start_;
			prefixEntree_ = ""; //INUTILE?
			string propositions = proposer();
			return propositions;

		}
		else 
		{
			etatPresent_ = start_;
			prefixEntree_ = "";
			cout << "Cette entree ne fait pas partie de l'alphabet du lexique selectionne. Veuillez entrer une lettre valide" << endl << endl;
		}
	}
}

string Automate::proposer()
{
	string propositions = "";
	if (etatPresent_->getMotsPossibles().empty())
	{
		string message = "Malheureusement, il n'existe aucun mot correspondant a votre entree dans le lexique selectionne\n";
		cout << message;
		propositions += message;
		return propositions;
	}
	else
	{
		string message = "Vouliez-vous ecrire :\n";
		cout << message;
		for (int i = 0; i < etatPresent_->getMotsPossibles().size(); i++)
		{
			string uneProposition = "";
			uneProposition += (i + 1);
			uneProposition += ") ";
			uneProposition += etatPresent_->getMotsPossibles()[i].getValeurMot();
			uneProposition += "\n";
			//cout << (i + 1) << ") " << etatPresent_->getMotsPossibles()[i].getValeurMot() << endl;
			cout << uneProposition;
			propositions += uneProposition;
		}
		propositions += "\n";
		cout << endl;
		return propositions;
	}
}

void Automate::actualiserLabels()
{
	for (int i = 0; i < motFinaux_->getVecLexique().size(); i++)
	{
		if (etatPresent_->getPrefix() == motFinaux_->getVecLexique()[i].getValeurMot())
		{
			motFinaux_->incrementerNbUtilisation(&motFinaux_->getVecLexique()[i]);
			motFinaux_->actualiserMotRecent(&motFinaux_->getVecLexique()[i]);
		}
	}
}
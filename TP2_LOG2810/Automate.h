#pragma once
#include "lexique.h"
#include "Etat.h"
#include <vector>

class Automate
{
public:
	Automate();
	Automate(Lexique* langageReconnu);
	~Automate();

	void construireFSM();
	void actualiserFSM(string prefix);
	void actualiserAlphabet(char lettre);
	bool presentDansAlphabet(char lettre);

	string transition(char entree);
	string proposer();

	void actualiserLabels();

private:
	Lexique* motFinaux_;
	string prefixEntree_; //INUTILE?
	Etat* start_;
	Etat* etatPresent_;
	//Etat* prochainEtats_;
	vector<Etat*> etats_;
	vector<Etat*> etatsFinaux_;
	vector<char> alphabet_;

};


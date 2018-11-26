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

	void transition(char entree);
	void proposer();

private:
	Lexique* motFinaux_;
	string prefixEntree_;
	Etat* start_;
	Etat* etatPresent_;
	//Etat* prochainEtats_;
	vector<Etat*> etats_;
	vector<Etat*> etatsFinaux_;
	vector<char> alphabet_;

};


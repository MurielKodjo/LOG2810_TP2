#pragma once

#include<vector>
#include<string>
#include<iostream>
#include "Mot.h"

using namespace std;

class cinqPremier
{

private:
	Mot tab[5];
	void replaceOnTop(int position);
	void pushTop(string elem);

public:
	cinqPremier();
	~cinqPremier();
	Mot get(int position);
	void addElement(string elem);
	bool trouverMot(string mot);
	Mot getMot(string mot);
};


#include "cinqPremier.h"



cinqPremier::cinqPremier()
{
}


cinqPremier::~cinqPremier()
{
}

string cinqPremier::get(int position)
{
	return tab[position];
}

void cinqPremier::replaceOnTop(int position)
{
	string elem = tab[position];
	string temp[5];
	temp[0] = elem;
	int index = 1;
	for (int i = 0; i < 5; ++i) {
		if (position != i) {
			temp[index++] = tab[i];
		}
	}
	for (int i = 0; i < 5; ++i) {
		tab[i] = temp[i];
	}
}

void cinqPremier::pushTop(string elem)
{
	string temp;
	for (int i = 0; i < 5; i++) {
		if (i == 0) {
			temp = tab[i];
			tab[i] = elem;
		}
		else {
			string temp2 = tab[i];
			tab[i] = temp;
			temp = temp2;
		}
	}
}

void cinqPremier::addElement(string elem)
{

	
	for (int i = 0; i < 5; ++i) {
		if (tab[i] == elem) {
			replaceOnTop(i);
			return;
		}
	}
	pushTop(elem);
}

#include "cinqPremier.h"


cinqPremier::cinqPremier()
{
}

cinqPremier::~cinqPremier()
{
}

Mot cinqPremier::get(int position)
{
	return tab[position];
}

void cinqPremier::replaceOnTop(int position)
{
	string elem = tab[position].getValeurMot();
	string temp[5];
	temp[0] = elem;
	int index = 1;
	for (int i = 0; i < 5; ++i) {
		if (position != i) {
			temp[index++] = tab[i].getValeurMot();
		}
	}
	for (int i = 0; i < 5; ++i) {
		tab[i].setValeurMot(temp[i]);
	}
}

void cinqPremier::pushTop(string elem)
{
	string temp;
	for (int i = 0; i < 5; i++) {
		if (i == 0) {
			temp = tab[i].getValeurMot();
			tab[i].setValeurMot(elem);
			tab[i].augmenterNbUtilisation();
		}
		else {
			string temp2 = tab[i].getValeurMot();
			tab[i].setValeurMot(temp);
			temp = temp2;
		}
	}
}

void cinqPremier::addElement(string elem)
{
	for (int i = 0; i < 5; ++i) {
		if (tab[i].getValeurMot() == elem) {
			replaceOnTop(i);
			return;
		}
	}
	pushTop(elem);
}

bool cinqPremier::trouverMot(string mot)
{
	for (int i = 0; i < 5; i++)
	{
		if (mot == tab[i].getValeurMot())
		{
			cout << "Le mot fait parti des cinq mot recemment utilise \n";
			return true;
		}
	}
	cout << "Le mot ne fait pas parti des cinq mot recemment utilis\202 \n";
	return false;
	
}

Mot cinqPremier::getMot(string mot)
{
	for (int i = 0; i < 5; i++)
	{
		if (mot == tab[i].getValeurMot())
		{
			return tab[i];
		}
	}
	return Mot(); //throw exception 
}

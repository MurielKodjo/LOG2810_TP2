#include <iostream>
#include <string>
#include <stdio.h>
#include "lexique.h"
#include "Automate.h"
#include <conio.h>
using namespace std;

int main() {
	//TODO : interface graphique permettant de saisir texte
	//TODO : Afficher le label
	bool exit = true;
	do
	{
		string outputString;
		Lexique lex;
		cout << "Choisir une des options suivantes : \n" << 
			"a) Mettre a jour \nb) Saisir du texte \nc) Afficher les labels \nd) Quitter \n";
		cin >> outputString;
		char output = outputString[0];
		if (output == 'a' || output == 'A')
		{
			cout << "Entrer le fichier de lexique a charger \n";
			string nomfichier;
			cin >> nomfichier;
			
			lex.lectureFichier(nomfichier);

		}
		else if (output == 'b' || output == 'B')
		{
			cout << "Entrez un mot \n";
			string mot;
			cin >> mot;

		}
		else if (output == 'c' || output == 'C')
		{
			char cha = 'é';
			cout << "Entrez le mot dont vous voulez connaitre le label \n" ;
			string motLabel;
			cin >> motLabel;
			cout <<  motLabel << " a \202t\202 utilise " << lex.getPremierLabel(motLabel) << " fois \n";
			if (lex.getSecondLabel(motLabel) == 1)
				cout << "Le mot fait parti des cinq mot recemment utilise \n\n";
			else
				cout << "Le mot ne fait pas parti des cinq mot recemment utilis\202 \n\n";
		}
		else if (output == 'd' || output == 'D')
		{
			exit = false;
		}
		else
		{
			cout << "Svp entrez un caractere valide \n";
		}
	} while (exit);
	return 0;
}
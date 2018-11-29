#include <iostream>
#include <string>
#include <stdio.h>
#include "lexique.h"
#include "Automate.h"
#include "oneChar.h"
#include <conio.h>
using namespace std;

int main() {
	bool exit = true;
	Lexique lex;
	Automate* automate =new Automate(&lex);
	oneChar reader;
	do
	{
		string outputString;
		cout << "Choisir une des options suivantes : \n" <<
			"a) Mettre a jour \nb) Saisir du texte \nc) Afficher les labels \nd) Quitter \n";
		cin >> outputString;
		char output = outputString[0];
		if (output == 'a' || output == 'A')
		{
			cout << "Entrer le fichier de lexique a charger \n";
			string nomfichier;
			cin >> nomfichier;
			lex.clear();
			lex.lectureFichier(nomfichier);

		}
		else if (output == 'b' || output == 'B')
		{
			cout << "Entrez un mot \n";
			automate = new Automate(&lex);
			string mot;
			char charLu = reader.readOneChar();
			while (charLu != '\r') { //temps que enter pas presser si on veut pour space mettre ' '
				mot += charLu;
				cout << mot << endl;
				automate->transition(charLu);
				charLu = reader.readOneChar();
			}
			automate->getLexique()->setMotRecent(mot);
		}
		else if (output == 'c' || output == 'C')
		{
			cout << "Entrez le mot dont vous voulez connaitre le label \n";
			string motLabel;
			cin >> motLabel;
			//Vérifier que le mot est dans le lexique MK
			automate->getLexique()->getMotRecent().trouverMot(motLabel);
			cout << motLabel << " a \202t\202 utilise " 
				 << automate->getLexique()->getNombreUtilisation(motLabel) << " fois \n";
			
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
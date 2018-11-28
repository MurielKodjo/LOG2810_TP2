#include "oneChar.h"



oneChar::oneChar()
{
}


oneChar::~oneChar()
{
}
char oneChar::readOneChar() {
	char buf;
	buf = _getche();
	//system("cls");
	return buf;
}
string oneChar::readOneString()
{
	//essaie Muriel
	string buf;
	buf = _getche();
	//system("cls");
	return buf;
}

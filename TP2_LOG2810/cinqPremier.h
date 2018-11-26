#pragma once

#include<vector>
#include<string>
#include<iostream>

using namespace std;

class cinqPremier
{

private:
	
	string tab[5];
	void replaceOnTop(int position);
	void pushTop(string elem);

public:
	cinqPremier();
	~cinqPremier();
	string get(int position);
	void addElement(string elem);
};


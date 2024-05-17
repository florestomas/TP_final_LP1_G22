#pragma once
#include <string>
using namespace std;

class cArmas
{
public:
	cArmas(string nom, int d);
	~cArmas();

	int getDanio();

private:
	string nombre;
	int danio;
};


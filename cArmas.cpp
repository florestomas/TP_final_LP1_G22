#include "cArmas.h"

cArmas::cArmas(string nom, int d)
{
	nombre = nom;
	danio = d;
}
cArmas::~cArmas() {}

int cArmas::getDanio()
{
	return this->danio;
}
#include "cAtaque.h"

cAtaque::cAtaque(tipo_ataque ta, int danioo) {
	
	tAtaque = ta;
	danio = danioo;
}
cAtaque::~cAtaque() {}

int cAtaque::getDanio() {
	return this->danio;
}


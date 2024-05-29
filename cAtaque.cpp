#include "cAtaque.h"

cAtaque::cAtaque(int danioo) {
	
	danio = danioo;
}
cAtaque::~cAtaque() {}

int cAtaque::getDanio() {
	return this->danio;
}

/* PODRIAMOS HACER UN RAND PARA PROBABILIDAD DE CRITICO */
#pragma once
#include <iostream>
#include <list>

#include "cAtaque.h"
#include "cDragones.h"
#include "cArmas.h"
#include "cVikingos.h"
#include "cJinete.h"


class cIsla
{

private:
	list<cDragones*> dragoncinhios;
	list<cJinete*> jinetecinhios;
	list<cVikingos*> vikinguitos;
public:
	cIsla();
	~cIsla();

	void agregar_vikingo(cVikingos* p);
	void agregar_jinete(cJinete* p);

	/* SOBRECARGA DE OPERADORES */
	void operator+(cDragones* p);
	void operator-(cDragones* p);
	friend ostream& operator<<(ostream& os, cIsla& isla);

	bool MonturaDoble(cDragones* drake);
	list<cDragones*>& getListaDragones() { return dragoncinhios; }
	list<cVikingos*>& getListaVikingos() { return vikinguitos; }
	list <cJinete*>& getListaJinetes() { return jinetecinhios; }
};


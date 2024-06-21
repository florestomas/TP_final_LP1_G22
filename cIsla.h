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
	
	void eliminarVikingo(cVikingos* p);
	void imprimirVikingos();
	void imprimirJinetes();
	
	/* PARA RECORRER LAS LISTAS */
	list<cDragones*>::iterator getDragoncinhiosBegin() { return dragoncinhios.begin(); }
	list<cDragones*>::iterator getDragoncinhiosEnd() { return dragoncinhios.end(); }

	list<cJinete*>::iterator getJinetecinhiosBegin() { return jinetecinhios.begin(); }
	list<cJinete*>::iterator getJinetecinhiosEnd() { return jinetecinhios.end(); }

	list<cVikingos*>::iterator getVikinguitosBegin() { return vikinguitos.begin(); }
	list<cVikingos*>::iterator getVikinguitosEnd() { return vikinguitos.end(); }

	list<cDragones*>& getListaDragones() { return dragoncinhios; }
	list<cVikingos*>& getListaVikingos() { return vikinguitos; }
	list <cJinete*>& getListaJinetes() { return jinetecinhios;}

};


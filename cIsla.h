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

	void operator+(cDragones* p);
	void operator-(cDragones* p);
	friend ostream& operator<<(ostream& os, cIsla& isla);
};


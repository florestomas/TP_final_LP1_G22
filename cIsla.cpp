#include "cIsla.h"

ostream& operator<<(ostream& os, cIsla& isla)
{
	list<cDragones*>::iterator it = isla.dragoncinhios.begin();

	if (it == isla.dragoncinhios.end()) //Si ni bien empezar a recorrerla veo que está vacía:
	{
		os << "La lista esta vacia" << endl;
		return os;
	}

	while (it != isla.dragoncinhios.end())
	{
		cDragones* aux = *it;
		os << aux->getNombre() << endl;	
		it++;
	}
	return os;
}

cIsla::cIsla()
{
	
	dragoncinhios.clear();
	jinetecinhios.clear();
	vikinguitos.clear();
}

cIsla::~cIsla(){}

void cIsla::operator+(cDragones* p)
{
	if (p != nullptr)
	{
		dragoncinhios.push_back(p);
		return;
	}
	throw new exception("No se peude agregar un elemento nulo");
}

void cIsla::operator-(cDragones* p)
{
	list<cDragones*>::iterator it = dragoncinhios.begin();
	while (it != dragoncinhios.end())
	{
		if (*(it) == p)
		{
			dragoncinhios.erase(it);
			return;
		}
	}
	throw new exception("No se encontró el dragón a eliminar");
}
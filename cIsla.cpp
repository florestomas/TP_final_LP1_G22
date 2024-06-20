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

void cIsla::agregar_vikingo(cVikingos* p)
{
	vikinguitos.push_back(p);
}

void cIsla::agregar_jinete(cJinete* p)
{
	jinetecinhios.push_back(p);
}

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

bool cIsla::MonturaDoble(cDragones* drake)
{

	/* REVISO QUE EL DRAGON ADMITA 2 JINETES (SEA GRANDE) */
	if (drake->getTamanio() != cDragones::grande)
	{
		cout << "El dragon no admite montura doble" << endl;
		return false;
	}

	int contJinetes = 0;
	cJinete* aux; //Para bajar los datos. No me deja acceder a los metodos del objeto al que apunta el iterador con (*it)


	list<cJinete*>::iterator it2 = jinetecinhios.begin();


	/* REVISO QUE EL DRAGON NO TENGA 2 JINETES */
	while (it2 != jinetecinhios.end() )
	{
		aux = *it2;

		if (aux->getpDragones() == drake)
		{
			contJinetes++;
		}
		if (contJinetes >= 2)
		{
			cout << " El dragon grande ya tiene 2 jinetes " << endl;
			return false;
		}
		it2++;
	}

	cout << "El dragon tiene " << contJinetes << " jinetes, es posible asignarle uno nuevo!" << endl;
	return true;

}

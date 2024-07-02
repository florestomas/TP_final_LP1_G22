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
		if (*it == p) {
			it = dragoncinhios.erase(it);
			return;
		}
		else {
			it++;
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

		if (compararDragones(aux,drake) == true) //Para esquivar la excepcion que me puede saltar de un dragon que no se le asigno a un jinete (no me hace problema, solo quiero ver si esta repetido el elemento) hicimos esta funcion friend
		{
				contJinetes++;
		}
		if (contJinetes >= 2)
		{
			cout << " El dragon grande ya tiene 2 jinetes asignados, no se pudo asignar un tercero..." << endl;
			return false;
		}
		it2++;
	}

	cout << endl << "El dragon tiene " << contJinetes << " jinetes, es posible asignarle uno nuevo!" << endl;
	return true;

}

void cIsla::eliminarVikingo(cVikingos* p)
{
	list<cVikingos*>::iterator it = vikinguitos.begin();
	while (it != vikinguitos.end())
	{
		if (*it == p) {
			it = vikinguitos.erase(it);
			return;
		}
		else {
			it++;
		}
	}
}

void cIsla::imprimirVikingos()
{
	list<cVikingos*>::iterator it = vikinguitos.begin();
	cVikingos* aux = nullptr;

	while (it != vikinguitos.end())
	{
		aux = *it;
		cout << aux->getNombre() << endl;
		it++;
	}
}
void cIsla::imprimirJinetes()
{
	list<cJinete*>::iterator it = jinetecinhios.begin();
	cJinete* aux = nullptr;

	while (it != jinetecinhios.end())
	{
		aux = *it;
		cout << aux->getNombre() << endl;
		it++;
	}
}

int cIsla::NumerarJinetes()
{
	list<cJinete*>::iterator it = jinetecinhios.begin();
	cJinete* aux = nullptr;
	int cont = 1;
	while (it != jinetecinhios.end())
	{
		aux = *it;
		cout <<cont<<") " << aux->getNombre() << endl;
		cont++;
		it++;
	}
	return cont;
}
int cIsla::NumerarVikingos()
{
	list<cVikingos*>::iterator it = vikinguitos.begin();
	cVikingos* aux = nullptr;
	int cont = 1;
	while (it != vikinguitos.end())
	{
		aux = *it;
		cout <<cont<<") " << aux->getNombre() << endl;
		cont++;
		it++;
	}
	return cont;
}
int cIsla::NumerarDragones()
{
	list<cDragones*>::iterator it = dragoncinhios.begin();
	cDragones* aux = nullptr;
	int cont = 1;
	while (it != dragoncinhios.end())
	{
		aux = *it;
		cout << cont << ") " << aux->getNombre() << endl;
		cont++;
		it++;
	}
	return cont;
}

int cIsla::NumerarDragonesPelea(cDragones* p)
{
	list<cDragones*>::iterator it = dragoncinhios.begin();
	cDragones* aux = nullptr;
	int cont = 1;
	while (it != dragoncinhios.end())
	{
		aux = *it;
		if (aux != p)
		{
			cout << cont << ") " << aux->getNombre() << endl;
			cont++;
		}
		it++;
	}
	return cont;
}


cDragones* cIsla::AccederDragon(int pos)
{
	list<cDragones*>::iterator it = dragoncinhios.begin();
	advance(it, pos);

	return *it;
}

cDragones* cIsla::AccederDragonPelea(int pos, cDragones* saltear)
{
	list<cDragones*>::iterator it = dragoncinhios.begin();

	int cont = 0;
	cDragones* aux;
	while (it != dragoncinhios.end())
	{
		aux = *it;
		if (aux != saltear)
			cont++;
		
		if (cont == pos)
			break;
		it++;
	}
	return *it;
}

cVikingos* cIsla::AccederVikingo(int pos)
{
	list<cVikingos*>::iterator it = vikinguitos.begin();
	advance(it, pos);

	return *it;
}

cJinete* cIsla::AccederJinete(int pos)
{
	list<cJinete*>::iterator it = jinetecinhios.begin();
	advance(it, pos);

	return *it;
}



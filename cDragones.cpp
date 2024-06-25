#include "cDragones.h"
#include "cAtaque.h"
#include "iostream"
#include <sstream>

using namespace std;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CLASE PADRE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


int cDragones::totalDragones = 0; //Inicializamos la variable static

cDragones::cDragones(string nom, string caract, string col)
{
	srand(time(NULL));
	int aux = rand() % (3) + 1;

	tamanio tam_aux = static_cast<tamanio>(aux);
	
	switch (aux)
	{
	case 1:
		vida = 1000;
	case 2:
		vida = 2000;
	case 3:
		vida = 3000;
	}

	nombre = nom;
	caracteristica = caract;
	color = col;
	estado = false;
	pAtaque = nullptr;
	tamanio_dragon = tam_aux;
	vivo = true;

	totalDragones++;
}

cDragones::~cDragones() {}

void cDragones::setMuerto()
{
	this->vivo = false;
}

void cDragones::domar()
{
	srand(time(NULL));
	int aux = 0;
	int contIntentos = 1;

	while (getEstado() != true)
	{
		aux = rand() % (11) + 1;
		if (aux == 5) //10% de probabilidades de domar el dragon a la primera
		{
			cout << "Se ha podido domar al dragon!" << endl;
			this->estado = true;
		}
		contIntentos++;
	}
	cout << endl << "El dragon fue domado al intento nro " << contIntentos << endl;
}

void cDragones::baja()
{
	totalDragones--;
}

void cDragones::setApodo(string nuevo_nombre)
{
	this->nombre = nuevo_nombre;
}

bool cDragones::getEstado()
{
	return this->estado;
}

int cDragones::getVida()
{
	return this->vida;
}

string cDragones::getNombre()
{
	return nombre;
}

void cDragones::setVida(int nueva_vida)
{
	if ( (vida+=nueva_vida) <= 0)
	{
		vida = 0;
		return;
	}
	this->vida += nueva_vida;

	if (this->vida <= 0)
	{
		baja();
		setMuerto();
	}

}

void cDragones::curar()
{
	vida = tamanio_dragon * 1000;
}

void cDragones::CriarDragonGrande()
{
	tamanio_dragon = cDragones::grande;
	vida = 1000 * (cDragones::grande);
}

void cDragones::setAtaque(cAtaque* nuevo_ataque)
{
	if ( nuevo_ataque == nullptr)
	{
		throw new exception("No se le puede asignar el ataque");
	}
	/*LA VARIABLE PUNTERO DE 'cAtaque' DEL DRAGON, AHORA APUNTARÁ A UN OBJETO DE ESTA MISMA CLASE*/
	pAtaque = nuevo_ataque;
}

bool cDragones::ataqueAprendible(cAtaque* p)
{
	return true;
}

cAtaque* cDragones::getpAtaque()
{
	if (pAtaque == nullptr)
	{
		throw new exception("El dragon no sabe ningun ataque");
	}
	return this->pAtaque;
}

bool cDragones::getVivo()
{
	return vivo;
}

cDragones::tamanio cDragones::getTamanio()
{
	return tamanio_dragon;
}

string cDragones::toStringD() const
{
	stringstream ss;
	ss << endl;
	ss << "Nombre: " << nombre << ", ";
	ss << "Vida: " << vida << ", ";
	ss << "Caracteristica: " << caracteristica << ", ";
	ss << "Color: " << color << ", ";
	ss << "Estado: ";
	if (estado == true)
	{
		ss << " Domado, ";
	}
	else {
		ss << " Sin domar, ";
	}

	ss << "Ataque: ";
	if (pAtaque == nullptr)
	{
		ss << "Ninguno, ";
	}
	else
	{
		ss << pAtaque->toStringA()<<", ";
	}	

	ss << "Tamanio: ";

	switch (tamanio_dragon) {
	case chico:
		ss << "Chico";
		break;
	case mediano:
		ss << "Mediano";
		break;
	case grande:
		ss << "Grande";
		break;
	}
	ss << ", ";
	ss << "Vivo: ";
	
	if (vivo == true)
	{
		ss << " Si";
    }
	else {
		ss << " No";
	}
	ss << endl;
	return ss.str();
}


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DRAGÓN DE FUEGO ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


cDragonFuego::cDragonFuego(string _nom, string _caracte, string _color) : cDragones(_nom, _caracte, _color) {}

void cDragonFuego::setAtaque(cAtaque* nuevo_ataque)
{
	if (nuevo_ataque == nullptr)
	{
		throw new exception("No se le puede asignar el ataque");
		return;
	}

	/* SI EL ATAQUE QUE SE LE INTENTA AGREGAR NO ES EL DE SU TIPO DE DRAGON PERO ES MORDIDA (ATAQUE DEFAULT) SE LE AGREGA IGUAL */
	cMordida* aux1 = dynamic_cast<cMordida*>(nuevo_ataque);
	if (aux1 != nullptr)
	{
		pAtaque = nuevo_ataque;
		return;
	}

	cBolaDeFuego* aux = dynamic_cast<cBolaDeFuego*>(nuevo_ataque);
	if (aux == nullptr )
	{
		throw new exception("Los dragones de fuego solo pueden aprender ataques de fuego!");
		return;
	}
	pAtaque = nuevo_ataque;

}

bool cDragonFuego::ataqueAprendible(cAtaque* p)
{
	cBolaDeFuego* aux = dynamic_cast<cBolaDeFuego*>(p);
	if (aux != nullptr)
		return true;

	return false;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DRAGÓN DE AGUA ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

cDragonAgua::cDragonAgua(string _nom, string _caracte, string _color) : cDragones(_nom, _caracte, _color) {}

void cDragonAgua::setAtaque(cAtaque* nuevo_ataque)
{
	if (nuevo_ataque == nullptr)
	{
		throw new exception("No se le puede asignar el ataque");
		return;
	}

	/* SI EL ATAQUE QUE SE LE INTENTA AGREGAR NO ES EL DE SU TIPO DE DRAGON PERO ES MORDIDA (ATAQUE DEFAULT) SE LE AGREGA IGUAL */
	cMordida* aux1 = dynamic_cast<cMordida*>(nuevo_ataque);
	if (aux1 != nullptr)
	{
		pAtaque = nuevo_ataque;
		return;
	}

	cHidroImpulso* aux = dynamic_cast<cHidroImpulso*>(nuevo_ataque);
	if (aux == nullptr)
	{
		throw new exception("Los dragones de agua solo pueden aprender ataques de agua!");
		return;
	}
	pAtaque = nuevo_ataque;

}

bool cDragonAgua::ataqueAprendible(cAtaque* p)
{
	cHidroImpulso* aux = dynamic_cast<cHidroImpulso*>(p);
	if (aux != nullptr)
		return true;

	return false;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DRAGÓN DE PIEDRA ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

cDragonPiedra::cDragonPiedra(string _nom, string _caracte, string _color) : cDragones(_nom, _caracte, _color) {}

void cDragonPiedra::setAtaque(cAtaque* nuevo_ataque)
{
	if (nuevo_ataque == nullptr)
	{
		throw new exception("No se le puede asignar el ataque");
		return;
	}

	/* SI EL ATAQUE QUE SE LE INTENTA AGREGAR NO ES EL DE SU TIPO DE DRAGON PERO ES MORDIDA (ATAQUE DEFAULT) SE LE AGREGA IGUAL */
	cMordida* aux1 = dynamic_cast<cMordida*>(nuevo_ataque);
	if (aux1 != nullptr)
	{
		pAtaque = nuevo_ataque;
		return;
	}

	cPedrada* aux = dynamic_cast<cPedrada*>(nuevo_ataque);
	if (aux == nullptr)
	{
		throw new exception("Los dragones de piedra solo pueden aprender ataques de piedra!");
		return;
	}
	pAtaque = nuevo_ataque;

}

bool cDragonPiedra::ataqueAprendible(cAtaque* p)
{
	cPedrada* aux = dynamic_cast<cPedrada*>(p);
	if (aux != nullptr)
		return true;

	return false;
}

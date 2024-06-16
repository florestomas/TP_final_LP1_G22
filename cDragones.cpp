#include "cDragones.h"
#include "cAtaque.h"


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
	this->vida += nueva_vida;

	if (this->vida <= 0)
	{
		baja();
		setMuerto();
	}

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

cAtaque* cDragones::getpAtaque()
{
	return this->pAtaque;
}


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DRAGÓN DE FUEGO ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


cDragonFuego::cDragonFuego(string _nom, string _caracte, string _color) : cDragones(_nom, _caracte, _color) {}

void cDragonFuego::setAtaque(cAtaque* nuevo_ataque)
{
	if (nuevo_ataque == nullptr)
	{
		throw new exception("No se le puede asignar el ataque");
	}

	cBolaDeFuego* aux = dynamic_cast<cBolaDeFuego*>(nuevo_ataque);
	if (aux == nullptr)
	{
		throw new exception("Los dragones de fuego solo pueden aprender ataques de fuego!");
		return;
	}
	pAtaque = nuevo_ataque;

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DRAGÓN DE AGUA ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

cDragonAgua::cDragonAgua(string _nom, string _caracte, string _color) : cDragones(_nom, _caracte, _color) {}

void cDragonAgua::setAtaque(cAtaque* nuevo_ataque)
{
	if (nuevo_ataque == nullptr)
	{
		throw new exception("No se le puede asignar el ataque");
	}

	cHidroImpulso* aux = dynamic_cast<cHidroImpulso*>(nuevo_ataque);
	if (aux == nullptr)
	{
		throw new exception("Los dragones de agua solo pueden aprender ataques de agua!");
		return;
	}
	pAtaque = nuevo_ataque;

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DRAGÓN DE PIEDRA ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

cDragonPiedra::cDragonPiedra(string _nom, string _caracte, string _color) : cDragones(_nom, _caracte, _color) {}

void cDragonPiedra::setAtaque(cAtaque* nuevo_ataque)
{
	if (nuevo_ataque == nullptr)
	{
		throw new exception("No se le puede asignar el ataque");
	}

	cPedrada* aux = dynamic_cast<cPedrada*>(nuevo_ataque);
	if (aux == nullptr)
	{
		throw new exception("Los dragones de piedra solo pueden aprender ataques de piedra!");
		return;
	}
	pAtaque = nuevo_ataque;

}
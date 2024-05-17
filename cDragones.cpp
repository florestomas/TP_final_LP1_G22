#include "cDragones.h"

int cDragones::totalDragones = 0; /* SE INICIALIZA LA VARIABLE STATIC */

cDragones::cDragones(string nom, int vidaa, string caract, string col, bool est, tamanio tam)
{
	nombre = nom;
	vida = vidaa;
	caracteristica = caract;
	color = col;
	estado = est;
	pAtaque = nullptr;
	tamanio_dragon = tam;
}

cDragones::~cDragones() {}

void cDragones::baja()
{
	totalDragones -= 1;
}

void cDragones::setNombre(string nuevo_nombre)
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

void cDragones::setVida(int nueva_vida)
{
	this->vida += nueva_vida;

	if (this->vida <= 0)
	{
		baja();
		delete this;/* LEGAL?? */
	}

}

void cDragones::setAtaque(cAtaque* nuevo_ataque)
{
	/*LA VARIABLE PUNTERO DE 'cAtaque' DEL DRAGON, AHORA APUNTARÁ A UN OBJETO DE ESTA MISMA CLASE*/
	pAtaque = nuevo_ataque;
}

cAtaque* cDragones::getpAtaque()
{
	return this->pAtaque;
}
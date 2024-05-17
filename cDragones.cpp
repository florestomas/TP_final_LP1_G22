#include "cDragones.h"

int cDragones::totalDragones = 0; /* SE INICIALIZA LA VARIABLE STATIC */

cDragones::cDragones(string nom, int vidaa, string caract, string col, tamanio tam)
{
	nombre = nom;
	vida = vidaa;
	caracteristica = caract;
	color = col;
	estado = false;
	pAtaque = nullptr;
	tamanio_dragon = tam;
	vivo = true;
}

cDragones::~cDragones() {}

void cDragones::setMuerto()
{
	this->vivo = false;
}

void cDragones::domar()
{
	this->estado = true;
}

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
		setMuerto();
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
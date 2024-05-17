#include "cJinete.h"

cJinete::cJinete(string nom, string ape, string apo, string fNc, caract_fisicas caract, resultBocon resultado)
{
	nombre = nom;
	apellido = ape;
	apodo = apo;
	fNac = fNc;
	caracteristicas = caract;
	result = resultado;
	pDragon = nullptr;

}
cJinete::~cJinete() {}

string cJinete::getNombre()
{
	return this->nombre;
}

cJinete::resultBocon cJinete::getResult()
{
	return this->result;
}

void cJinete::setMontura(cDragones* nuevo_dragon)
{
	this->pDragon = nuevo_dragon;
	nuevo_dragon->domar();
}





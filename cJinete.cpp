#include "cJinete.h"
#include "cDragones.h"
#include <iostream>

using namespace std;

cJinete::cJinete(string nom, string ape, string apo, string fNc)
{
	srand(time(NULL));
	int resultadito = rand() % (5) + 1;
	srand(time(NULL));
	int caract = rand() % (3) + 1;

	//static_cast para generar un resultado del entrenamiento al azar y una caracteristica fisica
	resultBocon result_aux = static_cast<resultBocon>(resultadito);
	caract_fisicas car_aux = static_cast<caract_fisicas>(caract);

	nombre = nom;
	apellido = ape;
	apodo = apo;
	fNac = fNc;
	caracteristicas = car_aux;
	result = result_aux;
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
	if (nuevo_dragon == nullptr)
	{
		throw new exception("No se puede asignar un dargon que no existe");
	}
	this->pDragon = nuevo_dragon;
}





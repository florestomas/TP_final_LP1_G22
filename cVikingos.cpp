#include "cVikingos.h"
#include "cDragones.h"
#include "cArmas.h"
#include "cAtaque.h"

cVikingos::cVikingos(string nom, int hp, int f, string ape, posicion posi)
{
	nombre = nom;
	vida = hp;
	fuerza = f;
	apellido = ape;
	pos = posi;
	contador_dragones = 0;
	arma = nullptr;
}
cVikingos::~cVikingos() {}

int cVikingos::getVida() {
	return this->vida;
}

unsigned int cVikingos::getContDragones()
{
	return this->contador_dragones;
}

void cVikingos::setContDragones(unsigned int bajas)
{
	contador_dragones += bajas;
}

void cVikingos::setVida(int nueva_vida)
{
	this->vida += nueva_vida;
}

bool cVikingos::dragones_terminados()
{
	unsigned int aux = this->getContDragones();

	if (aux != 0)
	{
		return true;
	}
	return false;
}

void cVikingos::setArma(cArmas* p)
{
	this->arma = p;/* EL PUNTERO AHORA APUNTA A UN OBJETO DE LA CLASE cARMAS*/
}

void cVikingos::atacar_dragones(cDragones* objetivo)
{
	int i = 1;

	if (objetivo != nullptr)
	{
	cout << " Ataquemos a los dragones! " << endl;//xd
	
	while ((this->getVida() > 0) && objetivo->getVida()	> 0)
	{
		cout <<endl<< "Turno " << i << ": " << endl;
		cout<<"La vida del dragon es:"<<objetivo->getVida()<< " y la vida del Vikingo es: "<< this->getVida() << endl;

		objetivo->setVida( (-1) * ( (this->fuerza) * (this->arma->getDanio())) );/*A LA VIDA DEL OBJETIVO SE LE RESTAN EL DANIO DEL VIKINGO MULTIPLICADO POR EL DA—O DEL ARMA*/
		this->setVida(( (-1)) * (objetivo->getpAtaque()->getDanio()) );/* AL VIKINGO LE SETEO LA VIDA RESTANDOLE EL DAÒO DEL DRAKE */

		cout << "La vida del dragon es:" << objetivo->getVida() << " y la vida del Vikingo es: " << this->getVida() << endl;
		i++;

	}

	}
	return;
}

void cVikingos::trabajar()
{
	/*A DEFINIR*/
}




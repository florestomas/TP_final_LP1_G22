#include "cVikingos.h"
#include "cDragones.h"
#include "cArmas.h"
#include "cAtaque.h"


cArmas* cVikingos::getArma() {	
	if (this->arma == nullptr)
	{
		throw new exception("El vikingo no tiene arma");
	}
	return this->arma;
}

cVikingos::posicion cVikingos::getPos()
{
	return this->pos;
}



cVikingos::cVikingos(string nom, string ape)
{
	srand(time(NULL));
	int fuercinhia = rand() % (5) + 1;

//static_cast para generar una posicion en la isla al azar la cual esta relacionada con la fuerza (el pescador más debil que el herrero por ej)
	posicion posi_aux = static_cast<posicion>(fuercinhia);

	nombre = nom;
	vida = 2500;
	fuerza = fuercinhia;
	apellido = ape;
	pos = posi_aux;
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
	if (p == nullptr)
	{
		throw new exception("No se le está asignando ningun arma");
	}
	this->arma = p;/* EL PUNTERO AHORA APUNTA A UN OBJETO DE LA CLASE cARMAS*/
	
}

void cVikingos::atacar_dragones(cDragones* objetivo)
{
	/* SI EL VIKINGO NO TIENE ARMA, ES UN HERRERO Y SE ESTÁ POR PEGAR CON UN DRAGON, SE LA CRAFTEA */
	try {
		this->getArma();
	}
	catch (exception* e)
	{
		cout << e->what();
		if (this->pos == cVikingos::herrero)
		{
			cArmas* nuevaArma = new cArmas(300);
			this->setArma(nuevaArma);
		}
		else
		{
			cArmas* punios = new cArmas(80);
			this->setArma(punios);
		}
	}


	if (objetivo == nullptr)
	{
		throw new exception("No existe el dragon al que se quiere atacar");
		return;
	}

	if (objetivo->getVivo() == false)
	{
		throw new exception("No se puede atacar un dragon que no este vivo!");
		return;
	}

	int i = 1;

	cout << " Ataquemos a los dragones! " << endl;//xd
	


	while ((this->getVida() > 0) && objetivo->getVida()	> 0)
	{
		cout <<endl<< "Turno " << i << ": " << endl;
		cout<<"La vida del dragon es: "<<objetivo->getVida()<< " y la vida del Vikingo es: "<< this->getVida() << endl;

		
		/* Hay que aclarar que el 'setVida()' a la vida actual le suma lo que se le pasa como parametro */


		/*A LA VIDA DEL OBJETIVO SE LE RESTAN EL DANIO DEL VIKINGO MULTIPLICADO POR EL DAÑO DEL ARMA*/
		objetivo->setVida( (-1) * ( (this->fuerza) * (this->arma->getDanio()) ) );

		cout << objetivo->getNombre();
		/* AL VIKINGO LE SETEO LA VIDA RESTANDOLE EL DAñO DEL DRAKE */
		this->setVida(  (-1) * (objetivo->getpAtaque()->getDanio() ) );

		cout << "La vida del dragon es:" << objetivo->getVida() << " y la vida del Vikingo es: " << this->getVida() << endl;
		
		
		i++;
	}


	return;
}

void cVikingos::trabajar()
{
	if (pos == granjero)
	{
		cout << "Trabajando en la granja..." << endl;
		return;
	}
	else if (pos == pescador)
	{
		cout << "Pescando..." << endl;
		return;
	}
	else if (pos == carpintero)
	{
		cout << "Trabajando en la carpinteria..." << endl;
		return;
	}
	
		cout << "Trabajando en la fragua..." << endl;
		
}




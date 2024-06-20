#include "cJinete.h"
#include "cDragones.h"
#include "cAtaque.h"
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

cDragones* cJinete::getpDragones()
{
	if (pDragon == nullptr)
	{
		throw new exception("El jinete no tiene ningun dragon asignado");
	}
	return pDragon;
}

void cJinete::setMontura(cDragones* nuevo_dragon)
{
	if (nuevo_dragon == nullptr)
	{
		throw new exception("No se puede asignar un dragon que no existe");
	}
	this->pDragon = nuevo_dragon;
}

void cJinete::atacarDragones(cDragones* objetivo)
{
	if (objetivo == nullptr)
	{
		throw new exception("No se encontro el objetivo");
		return;
	}

	/*ME FIJO SI EL DRAGON ALIADO TIENE UN ATAQUE APRENDIDO, SI NO, PELEA CON EL ATAQUE POR DEFAULT*/
	try {
		pDragon->getpAtaque();
	}
	catch (const exception* e)
	{
		cout << e->what() << endl
			;
		cAtaque* ataque_default1 = new cMordida();
		pDragon->setAtaque(ataque_default1);
	}

	/*ME FIJO SI EL DRAGON ENEMIGO TIENE UN ATAQUE APRENDIDO, SI NO, PELEA CON EL ATAQUE POR DEFAULT*/
	try {
		objetivo->getpAtaque();
	}
	catch (const exception* e2)
	{
		cout << e2->what() << endl
			;
		cAtaque* ataque_default2 = new cMordida();
		objetivo->setAtaque(ataque_default2);
	}
    

	int i = 1;

	cout << " Ataquemos a los dragones! " << endl;//xd



	while ((pDragon->getVida() > 0) && (objetivo->getVida() > 0))
	{
		cout << endl << "Turno " << i << ": " << endl;
		cout << "La vida del dragon enemigo es: " << objetivo->getVida() << " y la vida del jinete con el dragon es: " << pDragon->getVida() << endl;


		/* Hay que aclarar que el 'setVida()' a la vida actual le suma lo que se le pasa como parametro */

		cout << pDragon->getNombre() << " (Dragon aliado)";
		/*A LA VIDA DEL OBJETIVO SE LE RESTAN EL DANIO INFLIGIDO POR EL DRAGON ALIADO*/
		objetivo->setVida((-1) * (pDragon->getpAtaque()->getDanio()));


		cout << objetivo->getNombre() << " (Dragon enemigo) ";
		/* AL DRAGON ALIADO LE SETEO LA VIDA RESTANDOLE EL DAñO QUE LE INFLIGIERON */
		pDragon->setVida((-1) * (objetivo->getpAtaque()->getDanio()));


		cout << "La vida del dragon enemigo es: " << objetivo->getVida() << " y la vida del jinete con su dragon es: " << pDragon->getVida() << endl;


		i++;
	}
}





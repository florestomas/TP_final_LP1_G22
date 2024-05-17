#include <iostream>

#include "cAtaque.h"
#include "cDragones.h"
#include "cArmas.h"
#include "cVikingos.h"
#include "cJinete.h"

#include <list>

int main()
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ EXPERIMENTO ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


		/*  CREO LOS TIPOS DE ATAQUE QUE PUEDEN EXISTIR */
	cAtaque ataque1(cAtaque::fuego, 500);
	cAtaque ataque2(cAtaque::garras, 300);
	cAtaque ataque3(cAtaque::muerde, 300);

	/* CREO SUS RESPECTIVOS PUNTEROS */
	cAtaque* pAtaque1 = &ataque1;
	cAtaque* pAtaque2 = &ataque2;
	cAtaque* pAtaque3 = &ataque3;

	/* GENERAMOS UN DRAGON */
	cDragones* drake = new cDragones("Drake", 2000, "Es albino", "Blanco", cDragones::chico);
	drake->setAtaque(pAtaque1);

	cout << "Drake hace " << drake->getpAtaque()->getDanio() << " De danio" << endl;

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	cArmas arma1("Garrote", 3);

	cVikingos* ChristianMartin = new cVikingos("Bobina", 2500, 300, "Martin", cVikingos::herrero);
	ChristianMartin->setArma(&arma1);

	ChristianMartin->atacar_dragones(drake);


	cJinete* rugbier = new cJinete("Maximo", "Thompsen", "azotador", "20-9-1998", cJinete::robusto, cJinete::desaprobado);
	rugbier->setMontura(drake);



	delete rugbier;
	delete ChristianMartin;
	delete drake;
	return 0;
}


#include <iostream>
#include "cAtaque.h"
#include "cDragones.h"
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
	cDragones* drake = new cDragones("Drake",2000,"Es albino","Blanco",false,cDragones::chico);
	drake->setAtaque(pAtaque1);

	cout << "Drake hace " << drake->getpAtaque()->getDanio()<< " De danio"<< endl;

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


	delete drake;
	return 0;
}

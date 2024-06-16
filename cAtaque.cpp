#include "cAtaque.h"


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CLASE PADRE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

cAtaque::cAtaque(int danioo) : danio(danioo) {}
cAtaque::~cAtaque() {}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ BOLA DE FUEGO ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


cBolaDeFuego::cBolaDeFuego(): cAtaque(800){}

int cBolaDeFuego::getDanio()
{
	srand(time(NULL));
	cout << " tiro una bola de fuego!" << endl;
	int aux = rand() % (11) + 1;

		if(aux > 7)
			return (danio*(1.5));

	return danio;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ATAQUE DE AGUA ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


cHidroImpulso::cHidroImpulso() : cAtaque(600) {}

int cHidroImpulso::getDanio()
{
	srand(time(NULL));
	cout << " tiro un hidro impulso!" << endl;
	int aux = rand() % (11) + 1;

	if (aux > 7)
	{
		return (danio * 1.5);
	}

	return danio;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ATAQUE DE PIEDRA ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


cPedrada::cPedrada(): cAtaque(777) {}

int cPedrada::getDanio()
{
	srand(time(NULL));
	cout << " tiro una piedra!" << endl;
	int aux = rand() % (11) + 1;

	if (aux > 7)
	{
		return (danio * 1.5);
	}

	return danio;
}

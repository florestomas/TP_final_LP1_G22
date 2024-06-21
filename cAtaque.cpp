#include "cAtaque.h"
#include <sstream>

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CLASE PADRE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

string cAtaque::toStringA() const
{
	stringstream ss;
	ss << "Ataque: " << danio << " de danio";
	return ss.str();
}

cAtaque::cAtaque(int danioo) : danio(danioo) {}
cAtaque::~cAtaque() {}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ BOLA DE FUEGO ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


cBolaDeFuego::cBolaDeFuego(): cAtaque(800){}

int cBolaDeFuego::getDanio()
{
	srand(time(NULL));
	cout << " tiro una bola de fuego!" << endl;
	int aux = rand() % (11) + 1;

	if (aux > 7)
	{
		cout << " Fue un golpe critico!" << endl;
		return (danio * (1.5));
	}
	return danio;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ATAQUE DE AGUA ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


cHidroImpulso::cHidroImpulso() : cAtaque(600) {}

int cHidroImpulso::getDanio()
{
	srand(time(NULL));
	cout << " tiro un hidro-impulso!" << endl;
	int aux = rand() % (11) + 1;

	if (aux > 7)
	{
		cout << " Fue un golpe critico!" << endl;
		return (danio * 1.5);
	}

	return danio;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ATAQUE DE PIEDRA ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


cPedrada::cPedrada(): cAtaque(700) {}

int cPedrada::getDanio()
{
	srand(time(NULL));
	cout << " tiro una piedra!" << endl;
	int aux = rand() % (11) + 1;

	if (aux > 7)
	{
		cout << " Fue un golpe critico!" << endl;
		return (danio * 1.5);
	}

	return danio;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MORDIDA ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

cMordida::cMordida() : cAtaque(400){}

int cMordida::getDanio()
{
	srand(time(NULL));
	cout << " mordio al enemigo!" << endl;
	int aux = rand() % (11) + 1;

	if (aux > 7)
	{
		cout << " Fue un golpe critico!" << endl;
		return (danio * 1.5);
	}
	return danio;
}

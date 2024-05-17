#pragma once
#include <iostream>
#include <string>
using namespace std;
class cDragones;
class cArmas;

class cVikingos
{
public:
	enum posicion { granjero = 1, plomero, carpintero, herrero };

	void trabajar();
	bool dragones_terminados();
	void atacar_dragones(cDragones* objetivo);

	unsigned int getContDragones();
	int getVida();
	void setContDragones(unsigned int);/*SUMA DRAGONES MATADOS AL CONTADOR*/
	void setVida(int nueva_vida);
	void setArma(cArmas* p);

	cVikingos(string nom, int hp, int f, string ape, posicion posi, cArmas* arm);
	~cVikingos();
	
private:

	string nombre;
	int vida;
	int fuerza;
	string apellido;
	posicion pos;
	unsigned int contador_dragones;
	cArmas* arma;
};


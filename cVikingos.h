#pragma once
#include <iostream>
#include <string>

using namespace std;
class cDragones;
class cArmas;

class cVikingos
{
public:
	enum posicion { granjero = 1, pescador , carpintero, herrero, guerrero };

	void trabajar();
	bool dragones_terminados();
	bool atacar_dragones(cDragones* objetivo);
	cArmas* getArma();
	posicion getPos();
	string getNombre();

	string toStringV() const;

	unsigned int getContDragones();
	int getVida();
	void setContDragones(unsigned int);/*SUMA DRAGONES MATADOS AL CONTADOR*/
	void setVida(int nueva_vida);
	void setArma(cArmas* p);

	cVikingos(string nom, string ape);
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


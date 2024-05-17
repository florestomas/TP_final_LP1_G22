#pragma once
using namespace std;
#include <string>
#include "cAtaque.h"

class cDragones
{

public:
	static int totalDragones;
	enum tamanio { chico = 1, mediano, grande };

	void setNombre(string nuevo_nombre);
	void setAtaque(cAtaque* nuevo_ataque);
	void setVida(int nueva_vida);

	bool getEstado(); /*ME INFORMA SI ESTA DOMADO O NO*/
	int getVida();
	cAtaque* getpAtaque();
	void static baja();/*ELIMINO UN DRAKE DEL CONTADOR*/
	void setMuerto();
	void domar();

	cDragones(string nom, int vidaa, string caract, string col,tamanio tam);
	~cDragones();


private:
	string nombre;
	int vida;
	string caracteristica;
	string color;
	bool estado; /* DOMADO O SIN DOMAR */
	cAtaque* pAtaque; /* UN PUNTERO A UN OBJETO DE LA CLASE cATAQUE */
	tamanio tamanio_dragon;
	bool vivo;


};


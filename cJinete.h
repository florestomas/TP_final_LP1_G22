#pragma once
#include <string>
using namespace std;

class cDragones;

class cJinete
{

public:
	enum caract_fisicas { alto = 1, flaco, robusto};
	enum resultBocon { no_asistio = 1, aprobado, desaprobado, primero, ultimo };

	string getNombre();
	resultBocon getResult();

	void setMontura(cDragones* nuevo_dragon);

	cJinete(string nom, string ape, string apo, string fNc, caract_fisicas caract, resultBocon resultado);
	~cJinete();

private:
	string nombre;
	string apellido;
	string apodo;
	string fNac;
	caract_fisicas caracteristicas;
	resultBocon result;
	cDragones* pDragon;
};


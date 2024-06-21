#pragma once
#include <string>
using namespace std;


class cDragones;

class cJinete
{

public:
	enum caract_fisicas { alto = 1, flaco, robusto};
	enum resultBocon { no_asistio = 1, aprobado, desaprobado, primero, ultimo };


	/*~~~~~~~~~~~~~ GETTERS ~~~~~~~~~~~~~*/
	string getNombre();
	resultBocon getResult();
	cDragones* getpDragones();

	/*~~~~~~~~~~~~~ SETTERS ~~~~~~~~~~~~~*/
	void setMontura(cDragones* nuevo_dragon);

	cDragones* atacarDragones(cDragones *&objetivo);
	friend bool compararDragones(cJinete* jinete, cDragones* p);

	cJinete(string nom, string ape, string apo, string fNc);
	~cJinete();

	string toStringJ() const;

protected:
	string nombre;
	string apellido;
	string apodo;
	string fNac;
	caract_fisicas caracteristicas;
	resultBocon result;
	cDragones* pDragon;
};

#pragma once
using namespace std;
#include <string>

class cAtaque;

class cDragones
{
public:
	
	static int totalDragones;
	enum tamanio { chico = 1, mediano, grande };


	/*~~~~~~~~~~~~~~~~~ SETTERS ~~~~~~~~~~~~~~~~~*/
	
	void setApodo(string nuevo_nombre);
	virtual void setAtaque(cAtaque* nuevo_ataque);
	virtual bool ataqueAprendible(cAtaque* p);
	void setVida(int nueva_vida);
	void curar();
	void CriarDragonGrande();

	/*~~~~~~~~~~~~~~~~~ GETTERS ~~~~~~~~~~~~~~~~~*/

	bool getEstado(); /*ME INFORMA SI ESTA DOMADO O NO*/
	int getVida();
	string getNombre();
	cAtaque* getpAtaque();
	bool getVivo();
	tamanio getTamanio();

	string toStringD() const;

	/*~~~~~~~~~~~~~~~~~ MÉTODOS ADMINISTRACION ~~~~~~~~~~~~~~~~~*/

	void static baja();//Elimino un dragon del contador
	void setMuerto();
	void domar();


	cDragones(string nom, string caract, string col);
	virtual ~cDragones();


protected:
	string nombre;
	int vida;
	string caracteristica;
	string color;
	bool estado; //Domado o sin domar
	cAtaque* pAtaque;
	tamanio tamanio_dragon;
	bool vivo;

};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DRAGON DE FUEGO ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


class cDragonFuego : public cDragones
{
public:
	cDragonFuego(string _nom, string _caracte, string _color);
	void setAtaque(cAtaque* nuevo_ataque) override;
	bool ataqueAprendible(cAtaque* p) override;
};


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DRAGON DE AGUA ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

class cDragonAgua : public cDragones
{
public:
	cDragonAgua(string _nom, string _caracte, string _color);
	void setAtaque(cAtaque* nuevo_ataque) override;
	bool ataqueAprendible(cAtaque* p) override;

};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DRAGON DE PIEDRA ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

class cDragonPiedra : public cDragones
{
public:
	cDragonPiedra(string _nom, string _caracte, string _color);
	void setAtaque(cAtaque* nuevo_ataque) override;
	bool ataqueAprendible(cAtaque* p) override;

};



#include <iostream>

#include "cAtaque.h"
#include "cDragones.h"
#include "cArmas.h"
#include "cVikingos.h"
#include "cJinete.h"
#include "cIsla.h"
#include <list>


/*

- Dos aplicaciones de herencia 
- Dos aplicaciones de polimorfismo 
- Variable static y const 
- Control de excepciones 
- Tres aplicaciones de sobrecarga 
- Tres tipos de constructores 
- Getters y setters 

FLATA:
- Metodos "to-string" 

*/

int main() {

	/*SE CREAN LOS OBJETOS */

		/*JINETES ----> Se genera un resultado del test de Bocon random*/
	cJinete* jinete1 = new cJinete("Ricardo", "Cirne", "Chirne", "23/04/1950");
	cJinete* jinete2 = new cJinete("Theodore", "Campos", "Teo", "14/11/1995");
	cJinete* jinete3 = new cJinete("Mathew", "Balero", "Mat", "30/01/1983");

	/*ATAQUES*/
	cAtaque* aPiedra = new cPedrada();
	cAtaque* aAgua = new cHidroImpulso();
	cAtaque* aFuego = new cBolaDeFuego();

	/*DRAGONES ----> Se genera un tamanio random para el dragon y en base a eso se define su vida*/
	cDragones* drake1 = new cDragonFuego("Alacambiante", "Veloz", "Rojo");
	cDragones* drake2 = new cDragonAgua("Skrill", "Cuerpo con espinas", "Violeta");
	cDragones* drake3 = new cDragonPiedra("Gronckle", "Cola en forma de roca", "Marron");

	cArmas* arko = new cArco();
	cArmas* acha = new cHacha();
	cArmas* espadinhia = new cEspada();

	/*VIKINGOS ----> Se genera un puesto en la isla random y en base a eso se define su fuerza*/
	cVikingos* vicky1 = new cVikingos("Vick", "Ingo");
	cVikingos* vicky2 = new cVikingos("Elvi", "Kingo");
	cVikingos* vicky3 = new cVikingos("Osbaldo", "Santillan");


	cIsla IslaDeBerk;

	/*
	jinete1->setMontura(drake1);
	jinete1->atacarDragones(drake2);
		*/

	
		/* PODEMOS VER LOS DRAGONES QUE HABITAN LA ISLA, AGREGAR, SACARLOS DE LA LISTA  E IMPRIMIRLOS MEDIANTE EL OPERADOR "<<" */
	/*
	    cout << IslaDeBerk << endl;
		IslaDeBerk + drake1;
		cout << IslaDeBerk << endl;;
		IslaDeBerk - drake1;
		cout << IslaDeBerk << endl;
	*/

	IslaDeBerk + drake1;
	IslaDeBerk + drake2;
	IslaDeBerk + drake3;

	IslaDeBerk.agregar_vikingo(vicky1);
	IslaDeBerk.agregar_vikingo(vicky2);
	IslaDeBerk.agregar_vikingo(vicky3);

	IslaDeBerk.agregar_jinete(jinete1);
	IslaDeBerk.agregar_jinete(jinete2);
	IslaDeBerk.agregar_jinete(jinete3);

		
	list<cDragones*>::iterator itD = IslaDeBerk.getListaDragones().begin();
	list<cVikingos*>::iterator itV = IslaDeBerk.getListaVikingos().begin();
	list<cJinete*>::iterator itJ = IslaDeBerk.getListaJinetes().begin();

	cDragones* auxD = nullptr;
	cVikingos* auxV = nullptr;
	cJinete* auxJ = nullptr;

	    /* LOS JINETES PUEDEN INTERACTUAR CON LOS DRAGONES DOMÁNDOLOS, AUNQUE NO SIEMPRE ES TAN FÁCIL */
		
	advance(itD, 1);

	try {
			jinete1->getpDragones();
		}
		catch (const exception* e1)
		{
			cerr << e1->what()<<endl;
			cout << "Intentemos domar un dragon"<<endl;
			drake2->domar();
			jinete1->setMontura(drake1);
			delete e1;
		}
		
		cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl <<endl;



		/*UNA VEZ DOMADO, EL JINETE PUEDE ENSEÑARLES ATAQUES A SU DRAGON. LOS DRAGONES SOLO PUEDEN APRENDER ATAQUES DE SU TIPO, UN DRAGON DE FUEGO NO PODRÍA APRENDER ATAQUES DE AGUA (Se usa "dynamic_cast" para esto) */
		try {
			jinete1->getpDragones()->setAtaque(aAgua);
		}
		catch (const exception* e2)
		{
			cerr << e2->what() << endl;
			cout << "Intentemos enseniarle algun ataque que si pueda aprender" << endl;


			jinete1->getpDragones()->setAtaque(aFuego);
			delete e2;
		}
		


		/* Y AUNQUE LOS DRAGONES NO SEPAN NINGUN ATAQUE IGUAL PUEDEN PELAR, TODOS SABEN MORDER */
		try {
			jinete1->atacarDragones(drake2);
		}
		catch (const exception *e3)
		{
			delete e3;
		}



	delete jinete1;
	delete jinete2;
	delete jinete3;

	delete aPiedra;
	delete aAgua;
	delete aFuego;

	delete drake1;
	delete drake2;
	delete drake3;

	delete arko;
	delete acha;
	delete espadinhia;

	delete vicky1;
	delete vicky2;
	delete vicky3;


	return 0;
}

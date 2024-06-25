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


	IslaDeBerk + drake1;
	IslaDeBerk + drake2;
	IslaDeBerk + drake3;

	IslaDeBerk.agregar_vikingo(vicky1);
	IslaDeBerk.agregar_vikingo(vicky2);
	IslaDeBerk.agregar_vikingo(vicky3);

	IslaDeBerk.agregar_jinete(jinete1);
	IslaDeBerk.agregar_jinete(jinete2);
	IslaDeBerk.agregar_jinete(jinete3);

	list<cAtaque*> ataques;
	ataques.clear();
	ataques.push_back(aAgua);
	ataques.push_back(aFuego);
	ataques.push_back(aPiedra);

	list<cAtaque*>::iterator it4 = ataques.begin();
	cAtaque* auxA;


	    /* 1) LOS JINETES PUEDEN INTERACTUAR CON LOS DRAGONES DOMÁNDOLOS, AUNQUE NO SIEMPRE ES TAN FÁCIL */

	cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl << "1)" << endl << endl;
	try {
			jinete1->getpDragones();
		}
	catch (const exception* e1)
	{
		cerr << e1->what() << endl;

		if (drake1->getEstado() != true)
		{
			cout << "Intentemos domar un dragon" << endl;
			drake1->domar();
		}
			jinete1->setMontura(drake1);

			delete e1;
		}
		
	cout <<endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl << "2)" << endl << endl;

		/* 2) UNA VEZ DOMADO, EL JINETE PUEDE ENSEÑARLES ATAQUES A SU DRAGON. LOS DRAGONES SOLO PUEDEN APRENDER ATAQUES DE SU TIPO, UN DRAGON DE FUEGO NO PODRÍA APRENDER ATAQUES DE AGUA (Se usa "dynamic_cast" para esto) */
		try {
			jinete1->getpDragones()->setAtaque(aAgua);
		}
		catch (const exception* e2)
		{
			cerr << e2->what() << endl;
			cout << "Intentemos enseniarle algun ataque que si pueda aprender" << endl;
			
			/* RECORREMOS LA LISTA DE TODOS LOS ATAQUES HASTA ENCONTRAR UNO COMPATIBLE CON EL TIPO DE DRAGON */
			while (it4 != ataques.end() )
			{
				auxA = *it4;
				if (jinete1->getpDragones()->ataqueAprendible(auxA) == true)
				{
					jinete1->getpDragones()->setAtaque(auxA);
				}
				it4++;
			}
			delete e2;
		}
		
		cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl<< "3)" << endl;

		/* 3) Y AUNQUE LOS DRAGONES NO SEPAN NINGUN ATAQUE IGUAL PUEDEN PELAR, TODOS SABEN MORDER */

		cout << endl << " ANTES DE LA PELEA: " << endl;
		cout << endl << "~~~~~ DRAGONES: ~~~~~" << endl << IslaDeBerk << endl;

	    
		IslaDeBerk - (jinete1->atacarDragones(drake2));
		

		cout << endl << " DESPUES DE LA PELEA: " << endl;
		cout << endl << "~~~~~ DRAGONES: ~~~~~" << endl << IslaDeBerk << endl;

		cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl << "4)" << endl << endl;

		/* 4) DOMEMOS UN DRAGON GRANDE Y ASIGNEMOSLE 2 JINETES */
		cDragones* dragonGrande = new cDragones("Juan", "Gigante", "Rosa");
		dragonGrande->CriarDragonGrande();
		IslaDeBerk + dragonGrande;

		cout << " PRIMER JINETE: " << endl;
		try {
			jinete2->getpDragones();
		}
		catch (const exception* e4)
		{
			cerr << e4->what() << endl;

			if (dragonGrande->getEstado() != true)
			{
				cout << "Intentemos domar un dragon" << endl;
				dragonGrande->domar();
			}
			if(IslaDeBerk.MonturaDoble(dragonGrande) == true)
				jinete2->setMontura(dragonGrande);

			delete e4;
		}
		cout <<endl<<endl<<" SEGUNDO JINETE: " << endl;
		try {
			jinete3->getpDragones();
		}
		catch (const exception* e5)
		{
			cerr << e5->what() << endl;

			if (dragonGrande->getEstado() != true)
			{
				cout << "Intentemos domar un dragon" << endl;
				dragonGrande->domar();
			}
			if (IslaDeBerk.MonturaDoble(dragonGrande) == true)
				jinete3->setMontura(dragonGrande);

			delete e5;
		}

		cout <<endl<< endl << " TERCER JINETE? " << endl;
		if (IslaDeBerk.MonturaDoble(dragonGrande) == true)
			jinete1->setMontura(dragonGrande);
		
		cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl << "5)" << endl;

		/* 5) POR OTRO LADO, LOS VIKINGOS TAMBIEN PUEDEN PELEAR CON LOS DRAGONES -> LA PELEA PUEDE TENER DISTINTOS RESULTADOS, SI EL VIKINGO ES UN HERRERO, SE CREARÁ UN ARMA. EL DRAGON TIENE CIERTA PROBABILIDAD DE PEGAR GOLPES CRÍTICOS. LA VIDA DEL DRAGON PUEDE SER 1000, 2000 ó 3000 DEPENDIENDO DEL TAMANIO */
		cout <<endl<< " ANTES DE LA PELEA: " << endl;

		cout <<endl<< "~~~~~ VIKINGOS: ~~~~~" << endl;
		IslaDeBerk.imprimirVikingos();
		cout << endl << "~~~~~ DRAGONES: ~~~~~" << endl << IslaDeBerk << endl;

		if (vicky1->atacar_dragones(drake3) == false)
		{
			IslaDeBerk.eliminarVikingo(vicky1);
		}
		else {
			IslaDeBerk - drake3;
		}

		cout << endl<< " DESPUES DE LA PELEA: " << endl;
		cout << endl << "~~~~~ VIKINGOS: ~~~~~" << endl;
		IslaDeBerk.imprimirVikingos();
		cout << endl << "~~~~~ DRAGONES: ~~~~~" << endl << IslaDeBerk << endl;

		cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl << "6)" << endl;

        /* RESUMIENDO LO SUCEDIDO EN LA ISLA: */

		list<cDragones*>::iterator it1 = IslaDeBerk.getDragoncinhiosBegin();
		list<cJinete*>::iterator it2 = IslaDeBerk.getJinetecinhiosBegin();
		list<cVikingos*>::iterator it3 = IslaDeBerk.getVikinguitosBegin();

		cDragones* auxD = nullptr;
		cVikingos* auxV = nullptr;
		cJinete* auxJ = nullptr;



		cout << endl << "~~~~~ DRAGONES: ~~~~~" << endl;
		while (it1 != IslaDeBerk.getDragoncinhiosEnd())
		{
			auxD = *it1;
			cout<<auxD->toStringD();
			it1++;
		}

		cout << endl << "~~~~~ JINETES: ~~~~~" << endl;
		while (it2 != IslaDeBerk.getJinetecinhiosEnd())
		{
			auxJ = *it2;
			cout<<auxJ->toStringJ();

			it2++;
		}

		cout << endl << "~~~~~ VIKINGOS: ~~~~~";
		while (it3 != IslaDeBerk.getVikinguitosEnd())
		{
			auxV = *it3;
			cout<<auxV->toStringV();

			it3++;
		}

		cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

	delete jinete1;
	delete jinete2;
	delete jinete3;

	delete aPiedra;
	delete aAgua;
	delete aFuego;

	delete drake1;
	delete drake2;
	delete drake3;
	delete dragonGrande;

	delete arko;
	delete acha;
	delete espadinhia;

	delete vicky1;
	delete vicky2;
	delete vicky3;


	return 0;
}

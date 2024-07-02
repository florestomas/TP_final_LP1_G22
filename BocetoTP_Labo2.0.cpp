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


	int opcion;

	do {
		cout << endl << "~~~~~ MENU ~~~~~" << endl;
		cout << "1) Imprimir" << endl;
		cout << "2) Jinetes" << endl;
		cout << "3) Dragones" << endl;
		cout << "4) Vikingos" << endl;
		cout << "5) Terminar el programa" << endl;
		cout << endl << "Ingrese su opcion: ";

		cin >> opcion;
		switch (opcion) {

		case 1:
		{
			while (true) {
				cout << endl << "QUE DESEA IMPRIMIR? " << endl << endl;
				cout << "1) Dragones" << endl;
				cout << "2) Jinetes" << endl;
				cout << "3) Vikingos" << endl;
				cout << "4) Volver" << endl;
				cout << "Ingrese su opcion: ";

				int opcion2;
				cin >> opcion2;

				switch (opcion2) {

				case 1:
				{
					cout << "~~~~~ DRAGONES ~~~~~" << endl;

					list<cDragones*>::iterator it1 = IslaDeBerk.getDragoncinhiosBegin();
					while (it1 != IslaDeBerk.getDragoncinhiosEnd())
					{
						cout << (*it1)->toStringD();
						it1++;
					}
					break;
				}
				case 2:
				{
					cout << "~~~~~ JINETES ~~~~~" << endl;

					list<cJinete*>::iterator it2 = IslaDeBerk.getJinetecinhiosBegin();
					while (it2 != IslaDeBerk.getJinetecinhiosEnd())
					{
						cout << (*it2)->toStringJ();
						it2++;
					}

					break;
				}
				case 3:
				{
					cout << "~~~~~ VIKINGOS ~~~~~" << endl;

					list<cVikingos*>::iterator it3 = IslaDeBerk.getVikinguitosBegin();
					while (it3 != IslaDeBerk.getVikinguitosEnd())
					{
						cout << (*it3)->toStringV();
						it3++;
					}
					break;
				}
				case 4:
				{
					break;
				}
				default:
				{
					cout << endl << "Se introdujo una opcion que no es valida" << endl;
				}
				}
				if (opcion2 == 4)
					break;
			}
				break;
			}

		case 2:
		{
			int max = 0;
			int opcion3;

			do {
				cout << endl << "~~~~~ JINETES ~~~~~" << endl;
				max = IslaDeBerk.NumerarJinetes();
				cout << endl << "Elija un jinete: ";
				cin >> opcion3;

				if (opcion3 > max)
					cout << endl << "Ingreso un numero no valido" << endl;

			} while (opcion3 > max);

			int opcion4;

			while (true) {
				cout << endl << "~~~~~ OPCIONES ~~~~~" << endl;
				cout << "1) Asignar un dragon" << endl;
				cout << "2) Domar un dragon" << endl;
				cout << "3) Atacar un dragon" << endl;
				cout << "4) Volver" << endl;
				cout << "Ingrese su opcion: ";

				cin >> opcion4;


				switch (opcion4)
				{
				case 1: /* ASIGNAR DRAGONES */
				{
					int opcion5 = 0;
					int max1 = 0;
					do {

						cout << endl << "~~~~~ DRAGONES ~~~~~" << endl;
						max1 = IslaDeBerk.NumerarDragones();
						cout << endl << " Elija el dragon a asignar" << endl;
						cin >> opcion5;

						if (opcion5 > max1)
							cout << endl << "Se ingreso un valor invalido" << endl;

					} while (opcion5 > max1);

					if ((IslaDeBerk.AccederDragon(opcion5 - 1)->getTamanio() == cDragones::grande) && (IslaDeBerk.MonturaDoble(IslaDeBerk.AccederDragon(opcion5 - 1)) == false))
					{
						break;
					}
					IslaDeBerk.AccederJinete(opcion3 - 1)->setMontura(IslaDeBerk.AccederDragon(opcion5 - 1));

					break;
				}
				case 2: /* DOMAR DRAGONES */
				{
					int opcion5 = 0;
					int max1 = 0;
					do {

						cout << endl << "~~~~~ DRAGONES ~~~~~" << endl;
						max1 = IslaDeBerk.NumerarDragones();
						cout << endl << " Elija el dragon a domar: ";
						cin >> opcion5;

						if (opcion5 > max1)
							cout << endl << " Se ingreso un valor invalido " << endl;

					} while (opcion5 > max1);

					IslaDeBerk.AccederDragon(opcion5 - 1)->domar();

					break;
				}
				case 3:
				{
					int opcion5 = 0;
					int max1 = 0;

					do {
						try {
							IslaDeBerk.AccederJinete(opcion3 - 1)->getpDragones();
						}
						catch (const exception* e)
						{
							cerr << e->what() << endl;
							break;
						}


						cout << endl << "~~~~~ DRAGONES ~~~~~" << endl;
						max1 = IslaDeBerk.NumerarDragonesPelea(IslaDeBerk.AccederJinete(opcion3 - 1)->getpDragones());
						cout << endl << " Elija el dragon a atacar: ";
						cin >> opcion5;



						if (opcion5 > max1)
							cout << endl << " Se ingreso un valor invalido " << endl;

						/* DRAGON ENEMIGO: */
						cDragones* auxPelea = IslaDeBerk.AccederDragonPelea(opcion5, IslaDeBerk.AccederJinete(opcion3 - 1)->getpDragones());
						/* ENFRENTAMIENTO */
						IslaDeBerk - IslaDeBerk.AccederJinete(opcion3 - 1)->atacarDragones(auxPelea);


					} while (opcion5 > max1);

					break;
				}
				case 4:
				{
					break;

				}
				default:
					cout << endl << "Se introdujo una opcion que no es valida" << endl;
				}
				if (opcion4 == 4)
					break;
			}
		}

		case 3:
		{
			int opcion6 = 0;
			int max2 = 0;

			do {
				cout << endl << "~~~~~ DRAGONES ~~~~~" << endl;
				max2 = IslaDeBerk.NumerarDragones();

				cout << "Elija el dragon: ";
				cin >> opcion6;

				if (opcion6 > max2)
					cout << endl << "Ingreso un numero no valido" << endl;

			} while (opcion6 > max2);

			while (true)
			{
				cout << endl << "~~~~~ OPCIONES ~~~~~" << endl;
				cout << "1) Ataque del dragon" << endl;
				cout << "2) Enseniar un nuevo ataque" << endl;
				cout << "3) Volver" << endl;
				cout << "Ingrese su opcion : ";
				
				int opcion7 = 0;
				cin >> opcion7;

				switch (opcion7)
				{
				case 1:
				{
					try {
						IslaDeBerk.AccederDragon(opcion7 - 1)->getpAtaque()->toStringA();
					}
					catch (const exception* e)
					{
						cerr << endl << e->what() << endl;
						delete e;
					}
					break;
				}
				case 2:
				{
					int opcion8 = 0;
					cout << endl <<"QUE ATAQUE DESEA ENSEÑARLE AL DRAGON?" << endl;
					cout << "1) Bola de fuego" << endl;
					cout << "2) Hidropulso" << endl;
					cout << "3) Pedrada" << endl;
					cout << "Seleccione un ataque: ";
					cin >> opcion8;

					switch (opcion8)
					{
					case 1:
					{
						try {
							IslaDeBerk.AccederDragon(opcion7 - 1)->setAtaque(aFuego);
						}
						catch (const exception* e2) {
							cerr << endl << e2->what() << endl;
							delete e2;
							break;
						}
						cout << endl << IslaDeBerk.AccederDragon(opcion6 - 1)->getNombre() << " ahora sabe 'Bola de fuego' ! " << endl;
						break;
					}
					case 2:
					{
						try {
							IslaDeBerk.AccederDragon(opcion6 - 1)->setAtaque(aAgua);
						}
						catch (const exception* e2) {
							cerr << endl << e2->what() << endl;
							delete e2;
							break;
						}
						cout << endl << IslaDeBerk.AccederDragon(opcion7 - 1)->getNombre() << " ahora sabe 'Hidroimpulso' ! " << endl;

						break;
					}
					case 3:
					{
						try {
							IslaDeBerk.AccederDragon(opcion6 - 1)->setAtaque(aPiedra);
						}
						catch (const exception* e2) {
							cerr << endl << e2->what() << endl;
							delete e2;
							break;
						}
						cout << endl << IslaDeBerk.AccederDragon(opcion6 - 1)->getNombre() << " ahora sabe 'Pedrada' ! " << endl;

						break;
					}
					}

					break; //NO TOCAR
				}
				case 3:
				{
					break;
				}
				
			    }
				if (opcion7 == 3)
					break;
			}


			break;//NO TOCAR
		}

		case 4:
		{
			int opcion9 = 0;
			int max = 0;
			
			do {
				cout << endl << "~~~~~ VIKINGOS ~~~~~" << endl;
				max = IslaDeBerk.NumerarVikingos();
				cout << endl << "Elija un vikingo: ";
				cin >> opcion9;

				if (opcion9 > max)
					cout << "Ingreso una opcion invalida" << endl;
			} while (opcion9 > max);

			int opcion10 = 0;

			while (true)
			{
				cout << endl << "~~~~~ OPCIONES ~~~~~" << endl;
				cout << "1) Trabajar" << endl;
				cout << "2) Asignar un arma" << endl;
				cout << "3) Atacar dragones" << endl;
				cout << "4) Volver" << endl;
				cout << "Ingrese su opcion: ";

				cin >> opcion10;

				switch (opcion10)
				{

				case 1:
				{
					IslaDeBerk.AccederVikingo(opcion10 - 1)->trabajar();
					break;
				}

				case 2:
				{
					int opcion11 = 0;

					cout << endl << " QUE ARMA DESEA ASIGNARLE AL VIKINGO? " << endl;
					cout << "1) Arco" << endl;
					cout << "2) Hacha" << endl;
					cout << "3) Espada" << endl;

					cin >> opcion11;

					switch (opcion11)
					{
					case 1:
					{
						IslaDeBerk.AccederVikingo(opcion9 - 1)->setArma(arko);
						break;
					}
					case 2:
					{
						IslaDeBerk.AccederVikingo(opcion9 - 1)->setArma(acha);
						break;
					}
					case 3:
					{
						IslaDeBerk.AccederVikingo(opcion9 - 1)->setArma(espadinhia);
						break;
					}
					default:
					{
						cout << endl << "Se introdujo un arma invalida" << endl;
						break;
					}

					}
					break;
				}

				case 3:
				{
					int opcion11 = 0;
					int max = 0;
					do {
						
						cout << endl << "ELIJA UN DRAGON PARA ATACAR: " << endl<<endl;
						max = IslaDeBerk.NumerarDragones();
						cout << "Ingrese su opcion: ";
						cin >> opcion11;

						if (opcion11 > max)
							cout << "Se ingreso una opcion invalida" << endl;

					} while (opcion11 > max);

					bool result;
					result = IslaDeBerk.AccederVikingo(opcion9 - 1)->atacar_dragones((IslaDeBerk.AccederDragon(opcion11 - 1)));
					
					if (result == false)
					{
						IslaDeBerk.eliminarVikingo(IslaDeBerk.AccederVikingo(opcion9 - 1));
						opcion10 = 4;
					}
					else {
						IslaDeBerk - IslaDeBerk.AccederDragon(opcion11 - 1);
					}
					break;
				}

				case 4:
				{
					break;
				}
				}
				
				if (opcion10 == 4)
					break;
			}
			break;//NO TOCAR
		}

		case 5:
		{
			break;
		}

		default:
		{
			cout << endl << "Se introdujo una opcion que no es valida" << endl;
		}
		}
		}while (opcion != 5);


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

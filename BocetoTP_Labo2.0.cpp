#include <iostream>

#include "cAtaque.h"
#include "cDragones.h"
#include "cArmas.h"
#include "cVikingos.h"
#include "cJinete.h"
#include "cIsla.h"
#include <list>


int main() {

	/*SE CREAN LOS OBJETOS */
	
		cJinete* jinete1 = new cJinete ("Ricardo","Cirne","Chirne","23/04/1950");
		cJinete* jinete2 = new cJinete("Theodore","Campos","Teo","14/11/1995");
		cJinete* jinete3 = new cJinete("Mathew","Balero","Mat","30/01/1983");

		cAtaque* aPiedra = new cPedrada();
		cAtaque* aAgua = new cHidroImpulso();
		cAtaque* aFuego = new cBolaDeFuego();

		cDragones* drake1 = new cDragonFuego("Alacambiante", "Veloz", "Rojo");
		cDragones* drake2 = new cDragonAgua("Skrill", "Cuerpo con espinas", "Violeta");
		cDragones* drake3 = new cDragonPiedra("Gronckle", "Cola en forma de roca", "Marron");

		cArmas* arko = new cArco();
		cArmas* acha = new cHacha();
		cArmas* espadinhia = new cEspada();
		
		cVikingos* vicky1 = new cVikingos("Vick", "Ingo");
		cVikingos* vicky2 = new cVikingos("Elvi", "Kingo");
		cVikingos* vicky3 = new cVikingos("Osbaldo", "Santillan");//cualquiera

		cIsla IslaDeBerk;

		


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

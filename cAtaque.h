#pragma once
#include <iostream>
#include <string>

using namespace std;

class cVikingos;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ATAQUE DE PIEDRA ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

class cAtaque
{

public:
	 virtual int getDanio() = 0;

	 cAtaque(const int danioo);
	 virtual ~cAtaque();

protected:
	 const int danio;

};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ATAQUE DE FUEGO ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

class cBolaDeFuego : public cAtaque
{
public:
	cBolaDeFuego();
	int getDanio() override;

};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ATAQUE DE AGUA ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

class cHidroImpulso : public cAtaque
{
public:
	cHidroImpulso();
	int getDanio() override;

};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ATAQUE DE PIEDRA ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

class cPedrada : public cAtaque
{
public:
	cPedrada();
	int getDanio() override;

};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MORDIDA ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

class cMordida : public cAtaque
{
public:
	cMordida();
	int getDanio() override;
};
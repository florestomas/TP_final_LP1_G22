#pragma once
#include <iostream>
#include <string>

using namespace std;

class cVikingos;

class cAtaque
{

public:
	 virtual int getDanio() = 0;

	 cAtaque(const int danioo);
	 virtual ~cAtaque();

protected:
	 const int danio;

};

class cBolaDeFuego : public cAtaque
{
public:
	cBolaDeFuego();
	int getDanio() override;

};


class cHidroImpulso : public cAtaque
{
public:
	cHidroImpulso();
	int getDanio() override;

};


class cPedrada : public cAtaque
{
public:
	cPedrada();
	int getDanio() override;

};

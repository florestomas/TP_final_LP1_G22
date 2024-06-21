#pragma once
#include <string>
using namespace std;

class cArmas
{
public:
	cArmas(const int d);
	virtual ~cArmas();

	const int getDanio();

	string toStringAr() const;

protected:
	const int danio;
};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ARCO ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

class cArco : public cArmas {
	public:
		cArco();
	
};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ HACHA ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

class cHacha : public cArmas {
	public:
		cHacha();
};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ESPADA ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

class cEspada : public cArmas {
public:
	cEspada();
};
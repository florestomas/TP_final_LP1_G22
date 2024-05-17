#pragma once

class cVikingos;

class cAtaque
{

public: 
	  enum tipo_ataque { fuego = 1, garras, muerde }; /*EN PUBLIC DECLARO MI ENUM, EN PRIVATE DECLARO QUE TENGO UNA VARIAVLE DE ESTE TIPO*/
	  //void atacar(cVikingos* vikingo_atacar);
	  int getDanio();
	  //void setTipoAtaque(tipo_ataque nuevo_ataque);

	  cAtaque(tipo_ataque ta,int danioo);
	  ~cAtaque();

private:
	tipo_ataque tAtaque;
	int danio;

};


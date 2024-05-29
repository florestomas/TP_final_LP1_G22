#pragma once

class cVikingos;

class cAtaque
{

public: 
	  //void atacar(cVikingos* vikingo_atacar);
	  virtual int getDanio();
	  
	  //void setTipoAtaque(tipo_ataque nuevo_ataque);

	  cAtaque(int danioo);
	  virtual ~cAtaque();

private:
	int danio;

};


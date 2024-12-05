//---------------------------------------------------------------------------

#ifndef Cola_SMH
#define Cola_SMH
#include "CSMemoria.h"
//---------------------------------------------------------------------------
typedef int direccion1;
class ColaSm{
private:
	CSMemoria* m;
	direccion1 ini;
	direccion1 fin;

public:
	ColaSm();
	ColaSm(CSMemoria*);
	bool vacia();
	void poner(int);
	void sacar(int&);
	int primero();
	void mostrar(int,int,TCanvas*);
	// Metodos de dicola
	int ultimo();
	void sacar_final(int&);
	void poner_frente(int);
};
#endif

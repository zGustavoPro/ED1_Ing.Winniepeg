//---------------------------------------------------------------------------

#ifndef CDicola_PilaH
#define CDicola_PilaH
#include "CP_Vector.h"
//---------------------------------------------------------------------------
class DicolaV {
private:
	Pila_Vector* K;

public:
	DicolaV();
	void poner(int);
	void Poner_Frente(int);
	void sacar(int&);
	bool vacia();
	int primero();
	void mostrar(int,int,TCanvas*);
};
#endif

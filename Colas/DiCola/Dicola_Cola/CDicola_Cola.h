//---------------------------------------------------------------------------

#ifndef CDicola_ColaH
#define CDicola_ColaH
#include "CCola_Puntero.h"
//---------------------------------------------------------------------------
class DicolaC {
private:
	Cola_Ptr* k;

public:
	DicolaC();
	void poner(int);
	void poner_frente(int);
	void sacar(int&);
	bool vacia();
	int primero();
	void  mostrar(int,int,TCanvas*);
};
#endif

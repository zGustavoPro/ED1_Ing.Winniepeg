//---------------------------------------------------------------------------

#ifndef CCola_PilaH
#define CCola_PilaH
#include "CP_Ptr.h"
#include "CP_CSMemoria.h"
//---------------------------------------------------------------------------
class ColaPila {
private:
	Pila_Ptr* p;

public:
	ColaPila();
	bool vacia();
	void poner(int);
	void sacar(int&);
	int primero();
	void  mostrar(int,int,TCanvas*);

};
#endif

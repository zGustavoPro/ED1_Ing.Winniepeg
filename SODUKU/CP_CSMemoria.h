//---------------------------------------------------------------------------

#ifndef CP_CSMemoriaH
#define CP_CSMemoriaH
#include "CSMemoria.h"
//---------------------------------------------------------------------------
using namespace std;

class Pila_CSMemoria{
private:
	int tope;
	CSMemoria* m;

public:
	Pila_CSMemoria();
	Pila_CSMemoria(CSMemoria*);
	bool vacia();
	void meter(int);
	void sacar(int&);
	int sacar();
	int cima();
	void mostrar(int,int,TCanvas*);
};
#endif

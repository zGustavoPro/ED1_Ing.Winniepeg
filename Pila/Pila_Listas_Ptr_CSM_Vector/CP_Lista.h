//---------------------------------------------------------------------------

#ifndef CP_ListaH
#define CP_ListaH
#include "CSMemoria.h"
#include "Lista.h"
#include "VecLista.h"
#include "PtrLista.h"
//---------------------------------------------------------------------------
class Pila_Listas{
private:
	 // VecLista *l;
	 PtrLista *l;
	 //Lista *l;

public:
	Pila_Listas();
	bool vacia();
	void meter(int);
	void sacar(int&);
	int sacar();
	int cima();
	void mostrar(int,int,TCanvas*);
	void meter1(int);
	void sacar1(int&);
	void mostrarLista(int,int,TCanvas*);
};
#endif

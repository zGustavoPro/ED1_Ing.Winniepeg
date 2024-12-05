//---------------------------------------------------------------------------

#ifndef CP_PtrH
#define CP_PtrH
#include <vcl.h>
//---------------------------------------------------------------------------
struct NodoPila {
	int elemento;
	NodoPila* sig;
};

class Pila_Ptr {
private:
	NodoPila* tope;
	NodoPila* ptrPila;

public:
	Pila_Ptr();
	bool vacia_Pila();
	bool vacia_Cola();   //1
	void meter_Pila(int);
	void sacar_Pila(int&);
	void meter_Cola(int);   //1
	void sacar_Cola(int&);  //1
	int sacar();
	int cima();
	void mostrar_Pila(int,int,TCanvas*);
	void mostrar_Cola(int,int,TCanvas*);
};
#endif

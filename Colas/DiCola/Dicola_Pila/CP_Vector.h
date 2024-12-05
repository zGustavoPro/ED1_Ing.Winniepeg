//---------------------------------------------------------------------------

#ifndef CP_VectorH
#define CP_VectorH
#include <vcl.h>
//---------------------------------------------------------------------------
const int maxPila=100;
class Pila_Vector{
 private :
	int* elementos;
	int tope;
	int c;

 public :
	Pila_Vector();
	bool vacia();
	void meter(int e);
	void sacar(int &e);
	void meter1(int e);
	void sacar1(int &e);
	int sacar();
	int cima();
	void mostrar_Pila(int,int,TCanvas*);
	void mostrarVector(int,int,TCanvas*);
};

#endif

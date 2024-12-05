//---------------------------------------------------------------------------

#ifndef CC_ListPtrH
#define CC_ListPtrH
#include <vcl.h>
#include "PtrLista.h"
//---------------------------------------------------------------------------
  typedef NodoL *Direccion;
  class CC_ListPtr{ // Lista con punteros
	private :
	PtrLista *lista;

	public :
	CC_ListPtr();
	bool Vacio();
	bool Pertenece(int);
	void Inserta(int);
	int cardinal();
	int Ordinal(int);
	void Suprime(int);
	int Muestrea();

	int elemento(int);
	void reiniciar();

  bool Equivalencia(CC_ListPtr *,CC_ListPtr *);
  void Interseccion (CC_ListPtr *,CC_ListPtr *);
  void Union(CC_ListPtr *,CC_ListPtr *);
  void Mostrar_Conjuntos(AnsiString,int,int,TCanvas *Canvas);

};

#endif

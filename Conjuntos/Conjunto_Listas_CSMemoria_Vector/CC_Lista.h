//---------------------------------------------------------------------------

#ifndef CC_ListaH
#define CC_ListaH
#include <vcl.h>
#include "Lista.h"
#include "VecLista.h"
#include "CSMemoria.h"
//---------------------------------------------------------------------------

 class CC_Lista{ // Lista con CSMemoria y vectores
	private :
   //Lista *elem;
  VecLista *elem;
	public :
	CC_Lista();
	CC_Lista(CSMemoria*);
	  bool Vacio();
	bool Pertenece(int);
	void Inserta(int);
	int cardinal();
	int Ordinal(int);
	void Suprime(int);
	int Muestrea();

	int elemento(int);
	void reiniciar();

	 bool Equvalencia(CC_Lista*,CC_Lista*);
  void Interseccion (CC_Lista*,CC_Lista*);
  void Union(CC_Lista*,CC_Lista*);
  void Mostrar_Conjuntos(AnsiString,int,int,TCanvas *Canvas);

};
#endif

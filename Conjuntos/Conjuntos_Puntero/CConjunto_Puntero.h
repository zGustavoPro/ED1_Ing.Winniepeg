//---------------------------------------------------------------------------

#ifndef CConjunto_PunteroH
#define CConjunto_PunteroH
#include <vcl.h>
#include <stdlib.h>
#include <time.h>
//---------------------------------------------------------------------------
   struct Nodo{
	   int dato;
	   Nodo *sig;
   };

	typedef Nodo* Direccion;
   class CC_Puntero {
     private :
	int cant;
	Direccion ptr_conj;

	public :

	CC_Puntero();

	bool Vacio();
	bool Pertenece(int);
	void Inserta(int);
	int cardinal();
	int Ordinal(int);
	void Suprime(int);
	int Muestrea();

	Direccion anterior(Direccion);
	Direccion localiza(int);
	int obt_elem(int);
	int numero_Aleatorio();
	void reiniciar();

  bool Equvalencia(CC_Puntero*,CC_Puntero*);
  void Interseccion (CC_Puntero*,CC_Puntero*);
  void Union(CC_Puntero*,CC_Puntero*);
  void Mostrar_Conjuntos(AnsiString,int,int,TCanvas *Canvas);
  void Mostrar_Memoria(int,int,TCanvas *Canvas);

   };

#endif

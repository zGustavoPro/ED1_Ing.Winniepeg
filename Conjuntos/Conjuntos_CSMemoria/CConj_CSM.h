//---------------------------------------------------------------------------

#ifndef CConj_CSMH
#define CConj_CSMH

#include <vcl.h>
#include <stdlib.h>
#include <time.h>
#include "CSMemoria.h"
//---------------------------------------------------------------------------
//CSMemoria m;
typedef int Direccion;
class Conjunto_CSM{

	private :
	int cant;
	Direccion ptr_conj;
	CSMemoria *m;

	Direccion anterior(int);
	Direccion localiza(int);

	public :

	Conjunto_CSM();
	Conjunto_CSM(CSMemoria*);

	bool Vacio();
	bool Pertenece(int);
	void Inserta(int);
	int cardinal();
	int Ordinal(int);
	int Muestrea();
	void Suprime(int);


   //	void Suprime2(int);
	int obt_elem(Direccion);
	int numero_Aleatorio();
	void reiniciar();
   //	Direccion Buscar_Termino(int);
	//void delete_conj(Direccion);

  bool Equvalencia(Conjunto_CSM*,Conjunto_CSM*);
  void Interseccion (Conjunto_CSM *,Conjunto_CSM *);
  void Union(Conjunto_CSM*,Conjunto_CSM *);
  void Mostrar_Conjuntos(AnsiString,int,int,TCanvas *Canvas);
  void Mostrar_Memoria(int,int,TCanvas *Canvas);

};



#endif

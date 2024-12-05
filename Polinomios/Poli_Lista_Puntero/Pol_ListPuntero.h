//---------------------------------------------------------------------------

#ifndef Pol_ListPunteroH
#define Pol_ListPunteroH
#include <vcl.h>
#include "PtrLista.h"
//---------------------------------------------------------------------------

PtrLista pol;      //lpolinomios Lista con Punteros
typedef NodoL *Direccion;
class Lista_Ptr{
	private :
	Direccion Buscar_Exponente(int);
	Direccion Buscar_Terminos(int);
	public :
	Lista_Ptr();
	bool Escero();
	int Grado();
	int Coeficiente(int);
	void Asignar_Coeficiente(int,int);
	void Poner_Termino(int,int);
	int Numero_Terminos();
	int Exponente(int);

	void Derivar();
	void Suma();
	void Resta();
	void Multiplicar();

	void Mostrar(int,int,TCanvas *Canvas);


};
#endif

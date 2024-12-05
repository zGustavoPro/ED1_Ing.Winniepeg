//---------------------------------------------------------------------------

#ifndef ClassPol_List_VectH
#define ClassPol_List_VectH
#include <vcl.h>
#include "VecLista.h"
//---------------------------------------------------------------------------

   typedef int Direccion;
   class Lista_Vect{
	private :
	VecLista *pol;
	Direccion Buscar_Exponente(int);
	Direccion Buscar_Terminos(int);
	public :
	Lista_Vect();
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

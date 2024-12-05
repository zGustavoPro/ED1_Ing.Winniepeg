//---------------------------------------------------------------------------

#ifndef CC_VectorH
#define CC_VectorH
#include <vcl.h>
//---------------------------------------------------------------------------
 const int max=100;
 typedef int Direccion;
 class CC_Vector {
	private :
	int cant;
	int x[max];

	public :

	CC_Vector();

	bool Vacio();
	bool Pertenece(int); //pos
	void Inserta(int);
	int cardinal();
	int Ordinal(int);  //elemento return posicion
	void Suprime(int); //elemento
	int Muestrea();

	Direccion anterior(Direccion);
	Direccion localiza(int);
	int obt_elem(int);
	int numero_Aleatorio();
	void reiniciar();

  bool Equvalencia(CC_Vector*,CC_Vector*);
  void Interseccion (CC_Vector*,CC_Vector*);
  void Union(CC_Vector*,CC_Vector*);
  void Mostrar_Conjuntos(AnsiString,int,int,TCanvas *Canvas);
  void Mostrar_Memoria(int,int,TCanvas *Canvas);


 };


#endif

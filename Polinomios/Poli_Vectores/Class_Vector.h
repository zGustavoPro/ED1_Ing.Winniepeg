//---------------------------------------------------------------------------

#ifndef Class_VectorH
#define Class_VectorH
#include <vcl.h>
//---------------------------------------------------------------------------
 int const max=100;
 int const rango=10;
class Poli_Vector {
	private :
	int coef[max];
	int exp[max];
	int nt;

	public :
	Poli_Vector();
	bool Escero();
	int Grado();
	int Coeficiente(int);
	void Asignar_Coeficiente(int,int);
	void Poner_Termino(int,int);
	int Numero_Terminos();
	int Exponente(int); // devuelve el grado o exponente
	void sumar(Poli_Vector*,Poli_Vector*);
	void Restar(Poli_Vector*,Poli_Vector*);
	void Multiplicar(Poli_Vector*,Poli_Vector*);
	int Buscar_Exponente(int);
	void Desplazar(int);
	void Derivar();
	// Canvas
	void Mostrar_Vector(int,int,TCanvas *Canvas);

	};





























#endif

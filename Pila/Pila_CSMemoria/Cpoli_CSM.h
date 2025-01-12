//---------------------------------------------------------------------------

#ifndef Cpoli_CSMH
#define Cpoli_CSMH
#include "CSMemoria.h"
#include <vcl.h>
//---------------------------------------------------------------------------

// CSMemoria m;
typedef int Direccion;
class Pol_CSM         //polinomio con CSMemoria
{
 private :
 Direccion Buscar_Exponente(int);
 Direccion Buscar_Termino(int);
 Direccion ptr_poli;
 int nt;
 CSMemoria *m;

 public :
  Pol_CSM(CSMemoria*&);
 Pol_CSM();

 bool Escero();
 int Grado();
 int Coeficiente(int);
 void Asignar_Coeficiente(int,int);
 void Poner_Termino(int,int);
 int Numero_Terminos();
 int Exponente(int);
 void Derivar();
 double Evaluar(double);
 double Potencia(double,int);
 void Delete_Pol(Direccion);

 void XY(int,int,TCanvas *Canvas);
 void CordenadasXY(int,int,TCanvas *Canvas);
 void MostrarCSM(int,int,TCanvas *Canvas);
 void MostrarPol(int,int,TCanvas *Canvas);

 void DerivarP(Pol_CSM*);
 void Sumar(Pol_CSM,Pol_CSM);
  void Restar(Pol_CSM,Pol_CSM);
   void Multiplicar(Pol_CSM,Pol_CSM);
	void punto(Pol_CSM*);




};
#endif

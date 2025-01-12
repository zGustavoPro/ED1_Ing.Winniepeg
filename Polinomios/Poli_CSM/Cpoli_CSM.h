//---------------------------------------------------------------------------

#ifndef Cpoli_CSMH
#define Cpoli_CSMH
#include "CSMemoria.h"
#include <vcl.h>
//---------------------------------------------------------------------------

 /*struct NodoP{
	 int coef;
	 int exp;
	 NodoP *sig;
 }; */
  CSMemoria m;
typedef int Direccion;
class Pol_CSM          // Polinomio con CSMemoria
{
 private :
 Direccion Buscar_Exponente(int);
 Direccion Buscar_Termino(int);
 Direccion ptr_poli;
 int nt;


 public :
 void crear_CSM();
 Pol_CSM();
 int new_espacio(AnsiString);
 void delete_espacio(Direccion);
 bool Escero(); //Vacio
 int Grado();
 int Coeficiente(int);
 void Asignar_Coeficiente(int,int);
 void Poner_Termino(int,int);
 int Numero_Terminos();
 int Exponente(int);
 void Derivar();
 double Evaluar(double); // Y=P(x)=...
 void Poner_Dato(int,AnsiString,int);
 double Potencia(double,int);
 void Delete_Pol(Direccion);

 void XY(int,int,TCanvas *Canvas);
 void CordenadasXY(int,int,TCanvas *Canvas); //plano x y
 void MostrarCSM(int,int,TCanvas *Canvas);
 void MostrarPol(int,int,TCanvas *Canvas);

 //void DerivarP(Pol_CSM&,Pol_CSM&);
 void Sumar(Pol_CSM,Pol_CSM);
  void Restar(Pol_CSM,Pol_CSM);
   void Multiplicar(Pol_CSM,Pol_CSM);





};
#endif

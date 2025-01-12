//---------------------------------------------------------------------------

#ifndef CPL_CSMH
#define CPL_CSMH
#include "Lista.h"
#include "CSMemoria.h"
#include "CPL_CSM.h"
//---------------------------------------------------------------------------

 typedef int Direccion;
class Poli_CSM{    // polinomio lista con CSMemoria

private:
 Lista *pol;
 int nt;
public:

Poli_CSM();
Poli_CSM(CSMemoria*);

   bool Escero();
   int Grado();
   void Asignar_Coeficiente(int,int);
   void Poner_Termino(int,int);
   int Numero_Terminos();
   int Exponente(int);
   int Coeficiente(int);

 Direccion Buscar_Exponente(int);
 Direccion Buscar_Termino(int);

  void Derivar();
  void Suma(Poli_CSM,Poli_CSM);
  void Resta(Poli_CSM,Poli_CSM);
  void Multiplicacion(Poli_CSM,Poli_CSM);
  void CordenadasXY(int,int,TCanvas *Canvas);
  double Evaluar(double);

 void Mostrar_Polinomio(int,int,TCanvas *Canvas);
 void Mostrar_Lista(int,int,TCanvas *Canvas);   //lista y polinomio
 void Mostrar_CSM(int,int,TCanvas *Canvas);

};


#endif

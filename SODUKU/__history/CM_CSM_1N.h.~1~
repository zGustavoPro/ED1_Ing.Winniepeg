//---------------------------------------------------------------------------

#ifndef CM_CSM_1NH
#define CM_CSM_1NH
#include "CSMemoria.h"
#include <vcl.h>
//---------------------------------------------------------------------------
 class Matriz_CSM{
 private :
   CSMemoria *m;
   int ptrMat;
   int df,dc;
   int rep;
   int nt;

   int anterior(int);
   void suprime(int);
   int existe(int,int);

 public :
   Matriz_CSM(CSMemoria*);
   Matriz_CSM();
   void dimensionar(int,int);
   int dimension_Fila();
   int dimension_Columna();
   void poner(int,int,int);
   int elemento(int,int);
   void definir_ValorRepetido(int);
   void Mostrar_Matriz(int,int,TCanvas*);

 };
 #endif

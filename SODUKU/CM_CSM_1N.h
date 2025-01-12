//---------------------------------------------------------------------------

#ifndef CM_CSM_1NH
#define CM_CSM_1NH
#include "CSMemoria.h"
#include "CP_CSMemoria.h"
#include <vcl.h>
//---------------------------------------------------------------------------

 class Matriz_CSM{
 private :
   Pila_CSMemoria* pila;
   CSMemoria *m;
   bool retroceder;
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
   //Sudoku
   bool Matriz_Llena();
   bool EsSudoku();
   void retrocederPila();
   bool backTracking_Sudoku();
   bool puede_Colocar(int,int,int);
 };
 #endif

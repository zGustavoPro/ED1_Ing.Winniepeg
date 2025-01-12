//---------------------------------------------------------------------------

#ifndef CM_CSM2NH
#define CM_CSM2NH
#include "CSMemoria.h"
#include "CP_CSMemoria.h"
//---------------------------------------------------------------------------
class Matriz_CSM2N{
private :
   bool retroceder;
   Pila_CSMemoria* pila;
   CSMemoria *m;
   int ptrMat;
   int df,dc;
   int rep;
   int nt;

	void insertar_fila(int);
	void insertar_col(int,int);
	int existe_fil(int);
	int existe_col(int,int);
	int anterior(int,int);
	void suprime(int,int);

public :
   Matriz_CSM2N(CSMemoria*);
   Matriz_CSM2N();
   void dimensionar(int,int);
   int dimension_Fila();
   int dimension_Columna();
   void poner(int,int,int);
   int elemento(int,int);
   void definir_ValorRepetido(int);
   void Mostrar_Matriz(int,int,TCanvas*);
   //soduko
   bool Matriz_Llena();
   void EsSudoku();
   void retrocederPila();
};

#endif

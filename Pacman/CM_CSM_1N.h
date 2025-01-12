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
   int rep,nt;


   int anterior(int);
   void suprime(int);
   int existe(int,int);

   //Pacman
   int muro,moneda,contador,cantMonedas,comidos;
   int pacman,pacmanF,pacmanC,cesped,puntos;
   bool rompeMuros,playIniciado;
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
   void EsSudoku();
   void retrocederPila();

   //Pacman
   void Mostrar_MapaP(int,int,TCanvas*);
   void setColPacman(int);
   void setFilPacman(int);
   int getFilPacman();
   int getColPacman();
   void recorrerArriba(int,int);
   void recorrerAbajo(int,int);
   void recorrerDerecha(int,int);
   void recorrerIzquierda(int,int);

   //Funciones extras
   void romperMuroT(int,int,int,int);
   void transportarPacman(int,int,int,int);
   int obtenerFila(int,int);   //arriba  o abajo
   int obtenerColumna(int,int); // derecha o izquierda
   bool poderActivado();
   void setScored(int);
   int Scored();
   //Nivel 0 ,prueba
   void cargarNivel_0();
   void cargarCespedNivel_0();
   void cargarMonedasNivel_0();
   void cargarMurosNivel_0();
   //Niveles de Pacman Nivel 1
   void cargarNivel1();
   void cargarMuroN1();
   void cargarMonedasN1();

   //Nivel 2


 };
 #endif

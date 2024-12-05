//---------------------------------------------------------------------------

#ifndef CM_VectorH
#define CM_VectorH
//---------------------------------------------------------------------------
class Matriz_VComprimido{
  int *vF ; int *vC; int *vD;
 int dF,dC;
 int rep;
 int nt;


 int posicion(int,int);
 bool validar(int);
 void eliminar_posicion(int*,int,int);
 public :
 Matriz_VComprimido();
 void dimensionar(int,int);
 int dimension_Fila();
 int dimension_Columna();
 void poner(int,int,int);
 int elemento(int,int);
 void definir_ValorRepetido(int);
 int numero_casillas_validas();

 void Mostrar_MComprimida(int,int,TCanvas*);
   //void eliminar_posicion(int [],int [],int);
};
#endif

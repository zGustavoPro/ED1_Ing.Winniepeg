//---------------------------------------------------------------------------

#ifndef CM_VectSCH
#define CM_VectSCH
//---------------------------------------------------------------------------
 class Matriz_VNormal{
 private :
 int *vf;
	int *vc;
	int *vd;
	int df, dc;
	int rep;
	int nt;
	int posicion_insertar(int f);
	int posicion(int f,int c);
	void insertar_en_vector(int*,int,int&,int&);
 public :
 Matriz_VNormal();
 void dimensionar(int,int);
 int dimension_Fila();
 int dimension_Columna();
 void poner(int,int,int);
 int elemento(int,int);
 void definir_ValorRepetido(int);
 int numero_casillas_validas();

 void Mostrar_Matriz(int,int,TCanvas*);
};
#endif

//---------------------------------------------------------------------------

#ifndef CM_Ptr1NH
#define CM_Ptr1NH
//---------------------------------------------------------------------------
struct NodoMat {
	int fil;
	int col;
	int dato;
	NodoMat* sig;
};
 typedef NodoMat* direccion;
class Matriz_Ptr1N{
  private :
	direccion ptrMat;
	int df, dc;
	int rep;
	int nt;

	direccion anterior(direccion);
	void suprime(direccion);
	direccion existe(int,int);
	bool esValido(int);

  public :
	Matriz_Ptr1N();
	void dimensionar(int,int);
	int dimension_fila();
	int dimension_columna();
	void poner(int,int,int);
	int elemento(int,int);
	void definir_valor_repetido(int);
	void Mostrar_Matriz(int,int,TCanvas*);
};

#endif

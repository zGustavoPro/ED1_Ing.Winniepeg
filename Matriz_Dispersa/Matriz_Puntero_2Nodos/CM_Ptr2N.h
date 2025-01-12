//---------------------------------------------------------------------------

#ifndef CM_Ptr2NH
#define CM_Ptr2NH
//---------------------------------------------------------------------------
 struct NodoCol {
	int col;
	int dato;
	NodoCol* sigC;
};

struct NodoFil {
	int fil;
	NodoFil* sigF;
	NodoFil* antF;
	NodoCol* ptrCol;
};

class Matriz_Ptr2N{
private :
	NodoFil* ptrMat;
	int df, dc;
	int rep;
	int nt;

	void insertar_fila(NodoFil*);
	void insertar_col(NodoFil*,NodoCol*);
	NodoFil* existe_fil(int);
	NodoCol* existe_col(NodoFil*,int);
	NodoCol* anterior(NodoFil*,NodoCol*);
	void suprime(NodoFil*,NodoCol*);

public :
	Matriz_Ptr2N();
	void dimensionar(int,int);
	int dimension_fila();
	int dimension_columna();
	void poner(int,int,int);
	int elemento(int,int);
	void definir_valor_repetido(int);
    void Mostrar_Matriz(int,int,TCanvas*);
};
#endif

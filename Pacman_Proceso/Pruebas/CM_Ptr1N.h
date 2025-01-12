//---------------------------------------------------------------------------

#ifndef CM_Ptr1NH
#define CM_Ptr1NH
#include <cstdlib>
#include <ctime>
#include <vcl.h>
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
   //Pacman Begin
	int muro;
	int moneda;
	int comidos;
	bool rompeMuros;
	int contador;
	int cantMonedas;
	int pacman;
	int pacmanF;
	int pacmanC;
	//Fantasmas
	int fantasma1;
	int fantasma1F;
	int fantasma1C;

	int fantasma2;
	int fantasma2F;
	int fantasma2C;

	int fantasma3;
	int fantasma3F;
	int fantasma3C;

	int fantasma4;
	int fantasma4F;
	int fantasma4C;

   //end.
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
	//Pacman    Level 1
	void cargarMuros();
	void cargarMonedas();
    void cargarFantasmas();
	void recorrerArriba(int,int);
	void recorrerAbajo(int,int);
	void recorrerDerecha(int,int);
	void recorrerIzquierda(int,int);
	void transportarPacman(int,int,int);
	void romperMuroT(int,int,int);
	void setColPacman(int);
	void setFilPacman(int);
	int getFilPacman();
	int getColPacman();
	//Fantasmas

	void recorrerFantasmaArriba(int,int,int);
	void recorrerFantasmaAbajo(int,int,int);
	void recorrerFantasmaDerecha(int,int,int);
	void recorrerFantasmaIzquierda(int,int,int);

	bool esFantasma(int);
	int numeroRandom();
	void moverFantasmas(int);
	void activarFantasmas();
	void setColFantasma1(int);
	void setFilFantasma1(int);
	int getFilFantasma1();
	int getColFantasma1();

	void setColFantasma2(int);
	void setFilFantasma2(int);
	int getFilFantasma2();
	int getColFantasma2();

	void setColFantasma3(int);
	void setFilFantasma3(int);
	int getFilFantasma3();
	int getColFantasma3();

	void setColFantasma4(int);
	void setFilFantasma4(int);
	int getFilFantasma4();
	int getColFantasma4();

};

#endif

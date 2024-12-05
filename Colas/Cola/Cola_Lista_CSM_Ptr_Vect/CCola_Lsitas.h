//---------------------------------------------------------------------------

#ifndef CCola_LsitasH
#define CCola_LsitasH
#include "CSMemoria.h"
#include "Lista.h"
#include "PtrLista.h"
#include "VecLista.h"
//---------------------------------------------------------------------------
class Cola_Lista{
private:
   Lista* L;
  // PtrLista* L;
   //  VecLista* L;
public:
    Cola_Lista();
	bool vacia();
	void poner(int);
	void sacar(int&);
	void poner1(int);
	void poner_frente1(int);
	void sacar1(int&);
	int primero();
	void mostrar(int,int,TCanvas*);
	// Metodos de dicola
	int ultimo();
	void sacar_final(int&);
	void poner_frente(int);
};
#endif

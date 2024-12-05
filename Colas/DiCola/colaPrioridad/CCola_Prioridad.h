//---------------------------------------------------------------------------

#ifndef CCola_PrioridadH
#define CCola_PrioridadH
#include "CSMemoria.h"
#include "Funciones.h"
#include "Cola_SM.h"
//---------------------------------------------------------------------------
const int maxCP=3;
class ColadePrioridad {
private:
	ColaSm** vc;//* hace referencia a que va a ser un vector
	//otro * hace referencia a que los elementos del vector van a ser punteros
	int* vf;
	int colaActual;
	int cant;

public:
	ColadePrioridad();
	ColadePrioridad(CSMemoria*);
	bool vacia();
	int primero();
	void primero(int&);
	void poner(int,int);
	void frecuencia_prioridad(int,int);
	void sacar(int&);
	void mostrar(int,int,TCanvas*);
};
#endif

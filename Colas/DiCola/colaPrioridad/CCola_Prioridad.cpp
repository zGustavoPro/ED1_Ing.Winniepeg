//---------------------------------------------------------------------------

#pragma hdrstop

#include "CCola_Prioridad.h"
//---------------------------------------------------------------------------
ColadePrioridad::ColadePrioridad() {
	colaActual = 0;
	cant = 0;
	vc = new ColaSm*[maxCP];
	vf = new int[maxCP];
	for (int i = 0; i < maxCP; i++) {
		vc[i] = new ColaSm();
		vf[i] = 1;
	}
}
//---------------------------------------------------------------------------
ColadePrioridad::ColadePrioridad(CSMemoria* m) {
	colaActual = 0;
	cant = 0;
	vc = new ColaSm*[maxCP];
	vf = new int[maxCP];
	for (int i = 0; i < maxCP; i++) {
		vc[i] = new ColaSm(m);
		vf[i] = 1;
	}
}
//---------------------------------------------------------------------------
bool ColadePrioridad::vacia() {
	for (int i = 0; i < maxCP; i++) {
		if (!vc[i]->vacia())
			return false;
	}
	return true;
}
//---------------------------------------------------------------------------
int ColadePrioridad::primero() {
	if (vacia())
		ShowMessage("Cola Vacia");
	else {
		int colaInicio = colaActual;
		bool termino = false;
		while (!termino) {
			if (!vc[colaActual]->vacia() && cant < vf[colaActual])
				return vc[colaActual]->primero();
			colaActual = (colaActual + 1) % maxCP;
			cant = 0;
			if (colaActual == colaInicio)
				termino = true;
		}
	}
}
//---------------------------------------------------------------------------
void ColadePrioridad::primero(int &e) {
	if (vacia())
		ShowMessage("Cola Vacia");
	else {
		int colaInicio = colaActual;
		bool termino = false;
		// Este ciclo da la vuelta al vector de colas
		// Para verificar si encuentra el primero o no
		while (!termino) {
			if (!vc[colaActual]->vacia() && cant < vf[colaActual]) {
				e = vc[colaActual]->primero();
				termino = true;
			}
			else {
				colaActual = (colaActual + 1) % maxCP;
				cant = 0;
				if (colaActual == colaInicio)
					termino = true;
			}
		}
	}
}
//---------------------------------------------------------------------------
void ColadePrioridad::poner(int e, int prior) {
	vc[prior]->poner(e);
}
//---------------------------------------------------------------------------
void ColadePrioridad::frecuencia_prioridad(int f, int p) {
	vf[p] = f;
}
//---------------------------------------------------------------------------
void ColadePrioridad::sacar(int& e) {
	if (!vacia()) {
		if (!vc[colaActual]->vacia()) {
			if (cant < vf[colaActual]) {
				cant++;
				vc[colaActual]->sacar(e);
				if (cant == vf[colaActual]) {
					colaActual = (colaActual + 1) % maxCP;
					cant = 0;
				}
			}
		}
		else {
			colaActual = (colaActual + 1) % maxCP;
			cant = 0;
			sacar(e);
		}
	}
}
//---------------------------------------------------------------------------
void ColadePrioridad::mostrar(int x1,int y1,TCanvas* Canvas) {
	for (int i = 0; i < maxCP; i++) {
		vc[i]->mostrar(x1,y1,Canvas);
		y1+=22;
	}
}
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------

#pragma hdrstop

#include "CDicola_Pila.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
DicolaV :: DicolaV() {
	K = new Pila_Vector();
}
//---------------------------------------------------------------------------
void DicolaV :: poner(int e) {
	Pila_Vector* aux = new Pila_Vector();
	while (!K->vacia()) {
		int s;
		K->sacar(s);
		aux->meter(s);
	}
	K->meter(e);
	while (!aux->vacia()) {
		int s;
		aux->sacar(s);
		K->meter(s);
	}
}
//---------------------------------------------------------------------------
void DicolaV :: Poner_Frente(int e) {
	K->meter(e);
}
//---------------------------------------------------------------------------
void DicolaV :: sacar(int& e) {
	if (!vacia()) {
		K->sacar(e);
	}
}
//---------------------------------------------------------------------------
bool DicolaV :: vacia() {
	return K->vacia();
}
//---------------------------------------------------------------------------
int DicolaV :: primero() {
	if (!vacia()) {
		return K->cima();
	}
}
//---------------------------------------------------------------------------
void DicolaV :: mostrar(int x1,int y1,TCanvas* Canvas) {
	DicolaV* aux = new DicolaV();
	AnsiString s = "<<";
	while (!vacia()) {
		int e;
		sacar(e);
		aux->poner(e);
		s = s + IntToStr(e);
		if (!vacia())
			s = s + ",";
	}
	s = s + "<<";
	while (!aux->vacia()) {
		int e;
		aux->sacar(e);
		poner(e);
	}
	Canvas->TextOut(x1,y1,s);
}
//---------------------------------------------------------------------------

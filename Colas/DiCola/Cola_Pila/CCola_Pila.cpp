//---------------------------------------------------------------------------

#pragma hdrstop

#include "CCola_Pila.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

 ColaPila::ColaPila() {
	p = new Pila_Ptr();
}
//---------------------------------------------------------------------------
bool ColaPila::vacia() {
	return p->vacia_Pila();
}
//---------------------------------------------------------------------------
void ColaPila::poner(int e) {
	Pila_Ptr* aux = new Pila_Ptr();
	while (!p->vacia_Pila()) {
		int e;
		p->sacar_Pila(e);
		aux->meter_Pila(e);
	}
	p->meter_Pila(e);
	while (!aux->vacia_Pila()) {
		int e;
		aux->sacar_Pila(e);
		p->meter_Pila(e);
	}
}
//---------------------------------------------------------------------------
void ColaPila::sacar(int &e) {
	if (!vacia()) {
		p->sacar_Pila(e);
	}
}
//---------------------------------------------------------------------------
int ColaPila::primero() {
	if (!vacia()) {
		return p->cima();
	}
}
//---------------------------------------------------------------------------
void ColaPila::mostrar(int x1,int y1,TCanvas* Canvas) {
	ColaPila* aux = new ColaPila();
	AnsiString s = "<<";
	while (!vacia()) {
		int e;
		sacar(e);
		aux->poner(e);
		s = s + AnsiString(e);
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


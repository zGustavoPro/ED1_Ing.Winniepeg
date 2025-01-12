//---------------------------------------------------------------------------

#pragma hdrstop

#include "CDicola_Cola.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
 DicolaC :: DicolaC() {
	k = new Cola_Ptr();
}
//---------------------------------------------------------------------------
void DicolaC :: poner(int e) {
	k->poner(e);
}
//---------------------------------------------------------------------------
void DicolaC :: poner_frente(int e) {
	Cola_Ptr* aux = new Cola_Ptr();
	while (!k->vacia()) {
		int s;
		k->sacar(s);
		aux->poner(s);
	}
	k->poner(e);
	while (!aux->vacia()) {
		int s;
		aux->sacar(s);
		k->poner(s);
	}
}
//---------------------------------------------------------------------------
void DicolaC :: sacar(int& e) {
	k->sacar(e);
}
//---------------------------------------------------------------------------
bool DicolaC :: vacia() {
	return k->vacia();
}
//---------------------------------------------------------------------------
int DicolaC :: primero() {
	return k->primero();
}
//---------------------------------------------------------------------------
void DicolaC :: mostrar(int x1,int y1,TCanvas* Canvas) {
	DicolaC* aux = new DicolaC();
	AnsiString s = "<<";
	while (!vacia()) {
		int e;
		sacar(e);
		aux->poner(e);
		s += AnsiString(e);
		if (!vacia())
			s += ",";
	}
	s += "<<";
	while (!aux->vacia()) {
		int e;
		aux->sacar(e);
		poner(e);
	}
 Canvas->TextOut(x1,y1,s);
}
//---------------------------------------------------------------------------

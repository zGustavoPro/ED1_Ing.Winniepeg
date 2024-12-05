//---------------------------------------------------------------------------

#pragma hdrstop

#include "CCola_Vector2.h"
//---------------------------------------------------------------------------
Cola_Vector2 :: Cola_Vector2() {
	v = new int[maxV2];
	ini = 0;
	fin = 0;
}
//---------------------------------------------------------------------------
bool Cola_Vector2 :: vacia() {
	return fin == 0;
}
//---------------------------------------------------------------------------
void Cola_Vector2 :: poner(int e) {
	if (fin < maxV2) {
		v[fin] = e;
		fin++;
	}
}
//---------------------------------------------------------------------------
void Cola_Vector2 :: sacar(int &e) {
	if (!vacia()) {
		e = v[0];
		for (int i = 0; i < fin - 1; i++) {
			v[i] = v[i + 1];
		}
		fin--;
	}
}
//---------------------------------------------------------------------------
int Cola_Vector2 :: primero() {
	if (!vacia()) {
		return v[0];
	}
}
//---------------------------------------------------------------------------
void Cola_Vector2 :: mostrarV2(int x1,int y1 ,TCanvas* Canvas) {
	Cola_Vector2* aux = new Cola_Vector2();
	AnsiString cad = "<<";
	while (!vacia()) {
		int e;
		sacar(e);
		aux->poner(e);
		cad += AnsiString(e);
		if (!vacia())
			cad += ",";
	}
	cad +=  "<<";
	while (!aux->vacia()) {
		int e;
		aux->sacar(e);
		poner(e);
	}
	Canvas->TextOut(x1,y1,cad);
}
//---------------------------------------------------------------------------
int Cola_Vector2 :: ultimo() {
	if (!vacia()) {
		return v[fin - 1];
	}
}
//---------------------------------------------------------------------------
void Cola_Vector2 :: sacar_final(int& e) {
	if (!vacia()) {
		e = v[fin - 1];
		fin--;
	}
}
//---------------------------------------------------------------------------
void Cola_Vector2 :: poner_frente(int e) {
	if (fin < maxV2) {
		for (int i = fin; i > 0; i--) {
			v[i] = v[i - 1];
		}
		v[0] = e;
		fin++;
	}
}
//---------------------------------------------------------------------------
#pragma package(smart_init)

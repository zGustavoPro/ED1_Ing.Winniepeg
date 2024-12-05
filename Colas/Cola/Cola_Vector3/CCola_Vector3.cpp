//---------------------------------------------------------------------------

#pragma hdrstop

#include "CCola_Vector3.h"
//---------------------------------------------------------------------------
Cola_Vector3 :: Cola_Vector3() {
	v = new int[maxV3];
	ini = 0;
	fin = 0;
}
//---------------------------------------------------------------------------
bool Cola_Vector3 :: vacia() {
	return ini == fin;
}
//---------------------------------------------------------------------------
void Cola_Vector3 :: poner(int e) {
	if (siguiente(fin) != ini) {
		v[fin] = e;
		fin = siguiente(fin);
	}
}
//---------------------------------------------------------------------------
void Cola_Vector3 :: sacar(int &e) {
	if (!vacia()) {
		e = v[ini];
		ini = siguiente(ini);
	}
}
//---------------------------------------------------------------------------
int Cola_Vector3 :: primero() {
	if (!vacia()) {
		return v[ini];
	}
}
//---------------------------------------------------------------------------
int Cola_Vector3 :: siguiente(int dir) {
	return (dir + 1) % maxV3;
}
//---------------------------------------------------------------------------
int Cola_Vector3 :: anterior(int dir) {
	if (dir > 0) {
		return dir - 1;
	}
	else {
		return maxV3 - 1;
	}
}
//---------------------------------------------------------------------------
void Cola_Vector3 :: mostrarV3(int x1,int y1,TCanvas* Canvas) {
	Cola_Vector3* aux = new Cola_Vector3();
	AnsiString cad = "<<";
	while (!vacia()) {
		int e;
		sacar(e);
		aux->poner(e);
		cad += AnsiString(e);
		if (!vacia())
			cad += ",";
	}
	cad +="<<";
	while (!aux->vacia()) {
		int e;
		aux->sacar(e);
		poner(e);
	}
  Canvas->TextOut(x1,y1,cad);
}
//---------------------------------------------------------------------------
int Cola_Vector3 :: ultimo() {
	if (!vacia()) {
		return v[anterior(fin)];
	}
}
//---------------------------------------------------------------------------
void Cola_Vector3 :: sacar_final(int& e) {
	if (!vacia()) {
		e = v[anterior(fin)];
		fin = anterior(fin);
	}
}
//---------------------------------------------------------------------------
void Cola_Vector3 :: poner_frente(int e) {
	if (siguiente(fin) != ini) {
		ini = anterior(ini);
		v[ini] = e;
	}
}
//---------------------------------------------------------------------------
#pragma package(smart_init)

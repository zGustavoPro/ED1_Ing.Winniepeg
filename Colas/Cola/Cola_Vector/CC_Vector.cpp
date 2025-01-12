//---------------------------------------------------------------------------

#pragma hdrstop

#include "CC_Vector.h"
//---------------------------------------------------------------------------
Cola_Vector1 :: Cola_Vector1() {
	v = new int[maxV1];
	ini = 0;
	fin = 0;
}
//---------------------------------------------------------------------------
bool Cola_Vector1 :: vacia() {
	return ini == fin;
}
//---------------------------------------------------------------------------
void Cola_Vector1 :: poner(int e) {
	if (fin < maxV1) {
		v[fin] = e;
		fin++;
	}
}
//---------------------------------------------------------------------------
void Cola_Vector1 :: sacar(int &e) {
	if (!vacia()) {
		e = v[ini];
		ini++;
	}
}
//---------------------------------------------------------------------------
int Cola_Vector1 :: primero() {
	if (!vacia()) {
		return v[ini];
	}
}
//---------------------------------------------------------------------------
void Cola_Vector1 :: mostrarV1(int x1,int y1,TCanvas* Canvas) {
	AnsiString cad = "<<";
	for (int i = ini; i < fin; i++) {
		cad += AnsiString(v[i]);
		if (i < fin - 1)
			cad += ",";
	}
	cad += "<<";
	Canvas->TextOut(x1,y1,cad);
}
//---------------------------------------------------------------------------
#pragma package(smart_init)

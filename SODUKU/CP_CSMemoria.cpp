//---------------------------------------------------------------------------

#pragma hdrstop

#include "CP_CSMemoria.h"
#include <cmath>
//---------------------------------------------------------------------------
Pila_CSMemoria :: Pila_CSMemoria() {
	m = new CSMemoria();
	tope = -1;
}
//---------------------------------------------------------------------------
Pila_CSMemoria :: Pila_CSMemoria(CSMemoria* mem) {
	m = mem;
	tope = -1;
}
//---------------------------------------------------------------------------
bool Pila_CSMemoria :: vacia() {
	return tope == -1;
}
//---------------------------------------------------------------------------
void Pila_CSMemoria :: meter(int e) {
	int aux = m->new_espacio("elemento,sig");
	if (aux != -1) {
		m->Poner_dato(aux, "->elemento", e);
		m->Poner_dato(aux, "->sig", tope);
		tope = aux;
	}
}
//---------------------------------------------------------------------------
void Pila_CSMemoria :: sacar(int &e) {
	if (!vacia()) {
		e = m->Obtener_Dato(tope, "->elemento");
		int sup = tope;
		tope = m->Obtener_Dato(tope, "->sig");
		m->Delete_espacio(sup);
	}
}
//---------------------------------------------------------------------------
int Pila_CSMemoria :: sacar() {
	if (!vacia()) {
		int e = m->Obtener_Dato(tope, "->elemento");
		int sup = tope;
		tope = m->Obtener_Dato(tope, "->sig");
		m->Delete_espacio(sup);
		return e;
	}
}
//---------------------------------------------------------------------------
int Pila_CSMemoria :: cima() {
	if (!vacia())  {
		return m->Obtener_Dato(tope, "->elemento");
	}
}
//---------------------------------------------------------------------------
void Pila_CSMemoria :: mostrar(int x1,int y1,TCanvas* Canvas) {
	Pila_CSMemoria* aux = new Pila_CSMemoria();
	while (!vacia()) {
		int e;
		sacar(e);
		aux->meter(e);
		Canvas->TextOut(x1,y1,"|  "+AnsiString(e)+"  |");
		y1+=25;
	}
	while (!aux->vacia()) {
		int e;
		aux->sacar(e);
		meter(e);
	}
}
#pragma package(smart_init)


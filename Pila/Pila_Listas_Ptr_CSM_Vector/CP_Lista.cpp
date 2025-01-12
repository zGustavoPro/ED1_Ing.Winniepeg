//---------------------------------------------------------------------------

#pragma hdrstop

#include "CP_Lista.h"
//---------------------------------------------------------------------------
Pila_Listas :: Pila_Listas() {
//l = new VecLista();
//l = new Lista();
  l = new PtrLista();
}
//---------------------------------------------------------------------------
bool Pila_Listas :: vacia() {
	return l->Vacio();
}
//---------------------------------------------------------------------------
void Pila_Listas :: meter(int e) {
l->Inserta(l->Primero(), e);
}
//---------------------------------------------------------------------------
void Pila_Listas :: sacar(int &e) {
	if (!vacia()) {
		e = l->Recupera(l->Primero());
		l->Suprime(l->Primero());
	}
}
//---------------------------------------------------------------------------
int Pila_Listas :: sacar() {
	if (!vacia()) {
		int e = l->Recupera(l->Primero());
		l->Suprime(l->Primero());
		return e;
	}
}
//---------------------------------------------------------------------------
int Pila_Listas :: cima() {
	if (!vacia()) {
		return l->Recupera(l->Primero());
	}
}
//---------------------------------------------------------------------------
void Pila_Listas::mostrar(int x1,int y1,TCanvas* Canvas) {
	Pila_Listas* aux = new Pila_Listas();
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
//---------------------------------------------------------------------------
void Pila_Listas :: meter1(int e) {
	if (vacia() == true) {
		l->Inserta(l->Fin(), e);
	}
	else {
		int ul = l->Recupera(l->Fin());
		l->Inserta(l->Fin(), ul);
		l->Inserta(l->Fin(), e);
		l->Suprime(l->Fin());
	}
}
//---------------------------------------------------------------------------
void Pila_Listas :: sacar1(int &e) {
	if (vacia() == false) {
		e = l->Recupera(l->Fin());
		l->Suprime(l->Fin());
	}
	else {
		ShowMessage("Lista vacia");
	}
}
//---------------------------------------------------------------------------
void Pila_Listas :: mostrarLista(int x1,int y1,TCanvas* Canvas) {
  // Lista Vector
  // l->Dibuja(x1,y1,Canvas);
  //Lista CSMemoria
  //l->Mostrar_Lista(x1,y1-20,Canvas);
 // l->Mostrar(x1+100,y1,Canvas);
 //Lista Puntero
 //l->Dibujar(x1,y1,Canvas);
}
//---------------------------------------------------------------------------
#pragma package(smart_init)

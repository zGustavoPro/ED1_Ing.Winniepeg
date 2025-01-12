//---------------------------------------------------------------------------
#pragma hdrstop

#include "CCola_Lsitas.h"
//---------------------------------------------------------------------------
Cola_Lista :: Cola_Lista() {
    L = new Lista();
	//L = new PtrLista();
	//L = new VecLista();
}
//---------------------------------------------------------------------------
bool Cola_Lista :: vacia() {
	return L->Vacio();
}
//---------------------------------------------------------------------------
void Cola_Lista :: poner(int e) {
	if (vacia()) {
		L->Inserta(L->Fin(),e);
	}
	else {
		int ul = L->Recupera(L->Fin());
		L->Inserta(L->Fin(), ul);
		L->Modifica(L->Fin(), e);
	}
}
//---------------------------------------------------------------------------
void Cola_Lista :: sacar(int &e) {
	if (!vacia()) {
		e = L->Recupera(L->Primero());
		L->Suprime(L->Primero());
	}
}
//---------------------------------------------------------------------------
void Cola_Lista :: poner1(int e) { // Metodos del ingeniero
   L->Inserta(L->Primero(), e);
}
//---------------------------------------------------------------------------
void Cola_Lista :: poner_frente1(int e) { // Metodos del ingeniero
	int p = L->Recupera(L->Fin());
	L->Inserta(L->Fin(), e);
	L->Suprime(L->Fin());
	L->Inserta(L->Fin(), p);
}
//---------------------------------------------------------------------------
void Cola_Lista :: sacar1(int &e) { // Metodos del ingeniero
	if (!vacia()) {
		e = L->Recupera(L->Fin());
		L->Suprime(L->Fin());
	}
}
//---------------------------------------------------------------------------
int Cola_Lista :: primero() {
	if (!vacia()) {
		return L->Recupera(L->Primero());
	}
}
//---------------------------------------------------------------------------
void Cola_Lista :: mostrar(int x1,int y1,TCanvas* Canvas) {
	Cola_Lista* aux = new Cola_Lista();
	AnsiString s = "<<";
	while (!vacia()) {
		int e;
		sacar1(e);
		aux->poner1(e);
		s = s + AnsiString(e);
		if (!vacia())
			s = s + ",";
	}
	s = s + "<<";
	while (!aux->vacia()) {
		int e;
		aux->sacar1(e);
		poner1(e);
	}
	Canvas->TextOut(x1,y1,s);
	L->Mostrar(x1-350,y1,Canvas);   //listas = > memoria
}
//---------------------------------------------------------------------------
int Cola_Lista :: ultimo() {
	if (!vacia()) {
		return L->Recupera(L->Fin());
	}
}
//---------------------------------------------------------------------------
void Cola_Lista :: sacar_final(int& e) {
	if (!vacia()) {
		e = L->Recupera(L->Fin());
		L->Suprime(L->Fin());
	}
}
//---------------------------------------------------------------------------
void Cola_Lista :: poner_frente(int e) {
	L->Inserta(L->Primero(), e);

}
//---------------------------------------------------------------------------
#pragma package(smart_init)


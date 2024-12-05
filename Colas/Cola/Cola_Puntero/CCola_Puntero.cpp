//---------------------------------------------------------------------------

#pragma hdrstop

#include "CCola_Puntero.h"
//---------------------------------------------------------------------------
Cola_Ptr :: Cola_Ptr() {
	ini = nullptr;
	fin = nullptr;
}
//---------------------------------------------------------------------------
bool Cola_Ptr::vacia() {
	return ini == nullptr;
}
//---------------------------------------------------------------------------
void Cola_Ptr :: poner(int e) {
	direccion aux = new NodoCola;
	if (aux != nullptr) {
		aux->elemento = e;
		aux->sig = nullptr;
		if (vacia()) {
			ini = aux;
			fin = aux;
		}
		else {
			fin->sig = aux;
			fin = aux;
		}
	}
}
//---------------------------------------------------------------------------
void Cola_Ptr :: poner1(int e) {
	NodoCola* aux = new NodoCola();
	aux->elemento = e;
	aux->sig = nullptr;
	if (vacia()) {
		ini = aux;
		fin = aux;
		ini->sig = ini;
		fin->sig = ini;
	}
	else {
		fin->sig = aux;
		fin = aux;
		fin->sig = ini;
	}
}
//---------------------------------------------------------------------------
void Cola_Ptr :: sacar1(int &e) {
	if (!vacia()) {
		e = ini->elemento;
		NodoCola* aux = ini;
		if (ini == fin) {
			ini = nullptr;
			fin = nullptr;
		}
		else {
			ini = ini->sig;
			fin->sig = ini;
		}
		delete(aux);
	}
}
//---------------------------------------------------------------------------
void Cola_Ptr :: sacar(int &e) {
	if (!vacia()) {
		e = ini->elemento;
		direccion x = ini;
		if (ini == fin) {
			ini = nullptr;
			fin = nullptr;
		}
		else {
			ini = ini->sig;
		}
		delete(x);
	}
}
//---------------------------------------------------------------------------
int Cola_Ptr :: primero() {
	if (!vacia()) {
		return ini->elemento;
	}
}
//---------------------------------------------------------------------------
void Cola_Ptr :: mostrar_Ptr(int x1,int y1,TCanvas* Canvas) {
	Cola_Ptr* aux = new Cola_Ptr();
	AnsiString cad = "<<";
	while (!vacia()) {
		int e;
		sacar(e);
		aux->poner(e);
		cad += AnsiString(e);
		if (!vacia())
			cad += ",";
	}
	cad += "<<";
	while (!aux->vacia()) {
		int e;
		aux->sacar(e);
		poner(e);
	}
	Canvas->TextOut(x1,y1,cad);
}
//---------------------------------------------------------------------------
void Cola_Ptr :: mostrar(int x1,int y1,TCanvas* Canvas) {
	direccion aux = ini;
	bool b = true;
	AnsiString cad= "";
	while (aux != ini || b) {
		cad += AnsiString(aux->elemento) + ",";
		aux = aux->sig;
		b = false;
	}
	Canvas->TextOut(x1,y1,cad);
}
//---------------------------------------------------------------------------
int Cola_Ptr :: ultimo() {
	if (!vacia()) {
		return fin->elemento;
	}
}
//---------------------------------------------------------------------------
void Cola_Ptr :: sacar_final(int& e) {
	if (!vacia()) {
		e = fin->elemento;
		direccion del = fin;
		if (ini == fin) {
			ini = nullptr;
			fin = nullptr;
		}
		else {
			direccion aux = ini;
			while (aux->sig != fin) {
				aux = aux->sig;
			}
			fin = aux;
			fin->sig = nullptr;
		}
		delete(del);
	}
}
//---------------------------------------------------------------------------
void Cola_Ptr :: poner_frente(int e) {
	direccion aux = new NodoCola;
	if (aux != nullptr) {
		aux->elemento = e;
		aux->sig = nullptr;
		if(vacia()){
			ini = aux;
			fin = aux;
		}else{
			aux->sig = ini;
			ini = aux;
		}
	}
}
//---------------------------------------------------------------------------
#pragma package(smart_init)


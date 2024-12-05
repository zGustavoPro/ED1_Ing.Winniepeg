//---------------------------------------------------------------------------
#pragma hdrstop

#include "CP_Ptr.h"
//---------------------------------------------------------------------------
Pila_Ptr :: Pila_Ptr() {
	tope = nullptr;
	ptrPila = nullptr;
}

bool Pila_Ptr :: vacia_Pila(){
	return tope == nullptr;
}

bool Pila_Ptr :: vacia_Cola() {
	return ptrPila == nullptr;
}

void Pila_Ptr :: meter_Pila(int e) {
	NodoPila* aux = new NodoPila;
	if (aux != nullptr) {
		aux->elemento = e;
		aux->sig = tope;
		tope = aux;
	}
}

void Pila_Ptr :: sacar_Pila(int &e) {
	if (!vacia_Pila()) {
		e = tope->elemento;
		NodoPila* sup = tope;
		tope = tope->sig;
		delete(sup);
	}
}

int Pila_Ptr :: sacar() {
	if (!vacia_Pila()) {
		int e = tope->elemento;
		NodoPila* sup = tope;
		tope = tope->sig;
		delete(sup);
		return e;
	}
}

int Pila_Ptr :: cima() {
	if (!vacia_Pila()) {
		return tope->elemento;
	}
}

void Pila_Ptr :: mostrar_Pila(int x1,int y1,TCanvas* Canvas) {
	Pila_Ptr* aux = new Pila_Ptr();
	while (!vacia_Pila()) {
		int e;
		sacar_Pila(e);
		aux->meter_Pila(e);
		Canvas->TextOut(x1,y1,"| "+AnsiString(e)+" |");
		y1+=25;
	}
	while (!aux->vacia_Pila()) {
		int e;
		aux->sacar_Pila(e);
		meter_Pila(e);
	}
	delete aux;
}

void Pila_Ptr :: mostrar_Cola(int x1,int y1,TCanvas* Canvas) {
	Pila_Ptr* aux = new Pila_Ptr();
	while (!vacia_Cola()) {
		int e;
		sacar_Cola(e);
		aux->meter_Cola(e);
		Canvas->TextOut(x1,y1,"| "+AnsiString(e)+" |");
		y1+=25;
	}
	while (!aux->vacia_Cola()) {
		int e;
		aux->sacar_Cola(e);
		meter_Cola(e);
	}
	delete aux;
}

void Pila_Ptr :: meter_Cola(int e) {
	if (ptrPila == nullptr) {
		NodoPila* nuevo = new NodoPila;
		nuevo->elemento = e;
		nuevo->sig = nullptr;
		ptrPila = nuevo;
	}
	else {
		NodoPila* nuevo = new NodoPila;
		nuevo->elemento = e;
		nuevo->sig = nullptr;
		NodoPila* aux = ptrPila;
		while (aux->sig != nullptr) {
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}
}

void Pila_Ptr :: sacar_Cola(int &e) {
	if (ptrPila != NULL) {
		if (ptrPila->sig == nullptr) {
			e = ptrPila->elemento;
			delete(ptrPila);
			ptrPila = nullptr;
		}
		else {
			NodoPila* aux = ptrPila;
			NodoPila* ant;
			while (aux->sig != nullptr) {
				ant = aux;
				aux = aux->sig;
			}
			e = aux->elemento;
			ant->sig = nullptr;
			delete(aux);
		}
	}
}
#pragma package(smart_init)


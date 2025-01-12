//---------------------------------------------------------------------------

#pragma hdrstop

#include "CM_Ptr1N.h"
//---------------------------------------------------------------------------
Matriz_Ptr1N :: Matriz_Ptr1N(){
 df=0; dc=0; nt=0;
 rep=0; ptrMat=nullptr;
}
//---------------------------------------------------------------------------
void Matriz_Ptr1N :: dimensionar(int f, int c){
 df=f;
 dc=c;
}
//---------------------------------------------------------------------------
int Matriz_Ptr1N :: dimension_fila(){
 return df;
}
//---------------------------------------------------------------------------
int Matriz_Ptr1N :: dimension_columna(){
 return dc;
}
//---------------------------------------------------------------------------
void Matriz_Ptr1N :: poner(int f, int c, int valor){
   if (f > 0 && f <= df && c > 0 && c <= dc) {
		direccion pos = existe(f, c);
		if (pos == nullptr && valor != rep) {
			direccion nuevo = new NodoMat;
			nuevo->fil = f;
			nuevo->col = c;
			nuevo->dato = valor;
			nuevo->sig = ptrMat;
			ptrMat = nuevo;
			nt++;
		}
		else {
			if (valor == rep) {
				if (pos == ptrMat) {
					direccion x = ptrMat;
					ptrMat = ptrMat->sig;
					delete(x);
				}
				else {
					direccion x = ptrMat;
					direccion ant = nullptr;
					while (x != nullptr) {
						if (x == pos) {
							break;
						}
						ant = x;
						x = x->sig;
					}
					ant->sig = pos->sig;
					delete(pos);
				}
				nt--;
			}
			else
				pos->dato = valor;
		}
		return;
	}
	 ShowMessage("Error de Rango");
}
//---------------------------------------------------------------------------
int Matriz_Ptr1N :: elemento(int f, int c){
  if (f > 0 && f <= df) {
		if (c > 0 && c <= dc) {
			direccion pos = existe(f, c);
			if (pos == nullptr)
				return rep;
			else
				return pos->dato;
		}
	}
	ShowMessage("Error de Rango");
}
//---------------------------------------------------------------------------
void Matriz_Ptr1N :: definir_valor_repetido(int r){
   bool sinRep = true;
	direccion aux = ptrMat;
	while(aux != nullptr){
		if(aux->dato == r){
			sinRep = false;
			break;
		}
		aux = aux->sig;
	}
	if (nt == 0 || sinRep) {
		rep = r;
	}
	else {
		for (int i = 0; i < df; i++) {
			for (int j = 0; j < dc; j++) {
				int e = elemento(i + 1, j + 1);
				if (e == rep) {
					direccion nuevo = new NodoMat;
					nuevo->fil = i + 1;
					nuevo->col = j + 1;
					nuevo->dato = e;
					nuevo->sig = ptrMat;
					ptrMat = nuevo;
					nt++;
				}
			}
		}
		direccion aux = ptrMat;
		while (aux != nullptr) {
			if (aux->dato == r) {
				direccion sup = aux;
				aux = aux->sig;
				if (sup == ptrMat) {
					direccion x = ptrMat;
					ptrMat = ptrMat->sig;
					delete(x);
				}
				else {
					direccion x = ptrMat;
					direccion ant = nullptr;
					while (x != nullptr) {
						if (x == sup) {
							break;
						}
						ant = x;
						x = x->sig;
					}
					ant->sig = sup->sig;
					delete(sup);
				}
				nt--;
			}
			else
				aux = aux->sig;
		}
		rep = r;
	}
}
//---------------------------------------------------------------------------

direccion Matriz_Ptr1N :: anterior(direccion p){
   if (nt == 0 || p == ptrMat) {
		return nullptr;
	}
	else {
		direccion x = ptrMat;
		direccion ant = nullptr;
		while (x != nullptr) {
			if (x == p) {
				return ant;
			}
			ant = x;
			x = x->sig;
		}
	}
}
//---------------------------------------------------------------------------
void Matriz_Ptr1N :: suprime(direccion p){
 if (nt > 0) {
		if (p == ptrMat) {
			direccion x = ptrMat;
			ptrMat = ptrMat->sig;
			delete(x);
		}
		else {
			direccion ant = anterior(p);
			ant->sig = p->sig;
			delete(p);
		}
	}
}
//---------------------------------------------------------------------------
direccion Matriz_Ptr1N :: existe(int f, int c){
 direccion aux = ptrMat;
	while (aux != nullptr) {
		if (aux->fil == f && aux->col == c)
			return aux;
		aux = aux->sig;
	}
	return nullptr;
}
//---------------------------------------------------------------------------
bool Matriz_Ptr1N :: esValido(int rep){
   bool vacio = true;
	bool repetidos = true;
	for (int i = 0; i < df; i++)
		for (int j = 0; j < dc; j++)
			if (elemento(i + 1, j + 1) != rep)
				vacio = false;
	for (int i = 0; i < df; i++)
		for (int j = 0; j < dc; j++)
			if (elemento(i + 1, j + 1) == rep)
				repetidos = false;
	return vacio || repetidos;
}
//---------------------------------------------------------------------------
void Matriz_Ptr1N :: Mostrar_Matriz(int x1,int y1,TCanvas* Canvas){
     Canvas->Brush->Color=clBtnFace;
	 Canvas->Rectangle(0,0,1000,1000);
	 AnsiString r = "";
	 Canvas->Font->Size=12;
	for (int i = 0; i < df; i++) {
		r += "| ";
		for (int j = 0; j < dc; j++) {
			r += AnsiString(elemento(i + 1, j + 1));
			if (j < dc - 1)
				r += " , ";
		}
		r += " |";
		Canvas->TextOut(x1,y1,r);
		r=""; y1=y1+25;
	}
	Canvas->TextOut(x1,y1,"nt : "+AnsiString(nt));
	Canvas->Font->Size=8;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)


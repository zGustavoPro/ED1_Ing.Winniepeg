//---------------------------------------------------------------------------

#pragma hdrstop

#include "CM_Ptr2N.h"
//---------------------------------------------------------------------------
Matriz_Ptr2N :: Matriz_Ptr2N(){
	ptrMat = nullptr;
	df = 0;
	dc = 0;
	rep = 0;
	nt=0;
}
//---------------------------------------------------------------------------
void Matriz_Ptr2N :: dimensionar(int f, int c){
 df=f; dc=c;
}
//---------------------------------------------------------------------------
int Matriz_Ptr2N :: dimension_fila(){
  return df;
}
//---------------------------------------------------------------------------
int Matriz_Ptr2N :: dimension_columna(){
  return dc;
}
//---------------------------------------------------------------------------
void Matriz_Ptr2N :: poner(int f, int c, int valor){
 if (f > 0 && f <= df) {
		if (c > 0 && c <= dc) {
			NodoFil* fila = existe_fil(f);
			if (fila != nullptr) {
				NodoCol* col = existe_col(fila, c);
				if (col == nullptr && valor != rep) {
					NodoCol* nuevaCol = new NodoCol;
					nuevaCol->col = c;
					nuevaCol->dato = valor;
					nuevaCol->sigC = nullptr;
					insertar_col(fila, nuevaCol);
					nt++;
				}
				else {
					if (valor == rep) {
						suprime(fila, col);
						nt--;
					}
					else
						col->dato = valor;
				}
			}
			else {
				if (valor != rep) {
					NodoFil* nuevoFil = new NodoFil;
					nuevoFil->fil = f;
					nuevoFil->sigF = nullptr;
					nuevoFil->antF = nullptr;
					nuevoFil->ptrCol = nullptr;
					insertar_fila(nuevoFil);
					NodoCol* nuevaCol = new NodoCol;
					nuevaCol->col = c;
					nuevaCol->dato = valor;
					nuevaCol->sigC = nullptr;
					insertar_col(nuevoFil, nuevaCol);
					nt++;
				}
			}
			return;
		}
	}
	ShowMessage("Error de Rango");
}
//---------------------------------------------------------------------------
int Matriz_Ptr2N :: elemento(int f, int c){
 if (f > 0 && f <= df) {
		if (c > 0 && c <= dc) {
			NodoFil* fila = existe_fil(f);
			NodoCol* col = existe_col(fila, c);
			if (fila != nullptr && col != nullptr) {
				return col->dato;
			}
			else {
				return rep;
			}
		}
	}
	ShowMessage("Error de Rango");
}
//---------------------------------------------------------------------------
void Matriz_Ptr2N :: definir_valor_repetido(int r){
 	bool vacio = nt == 0;
	bool sinRep = true;
	NodoFil* aux = ptrMat;
	while (aux != nullptr && sinRep == true) {
		NodoCol* col = aux->ptrCol;
		while (col != nullptr) {
			if (col->dato == r) {
				sinRep = false;
				break;
			}
			col = col->sigC;
		}
		aux = aux->sigF;
	}
	if (vacio || sinRep) {
		rep = r;
	}
	else {
		for (int i = 0; i < df; i++) {
			for (int j = 0; j < dc; j++) {
				int e = elemento(i + 1, j + 1);
				if (e == rep) {
					NodoFil* fila = existe_fil(i + 1);
					NodoCol* col = existe_col(fila, j + 1);
					if (fila == nullptr) {
						NodoFil* nuevoFil = new NodoFil;
						nuevoFil->fil = i + 1;
						nuevoFil->sigF = nullptr;
						nuevoFil->antF = nullptr;
						nuevoFil->ptrCol = nullptr;
						insertar_fila(nuevoFil);
						NodoCol* nuevaCol = new NodoCol;
						nuevaCol->col = j + 1;
						nuevaCol->dato = e;
						nuevaCol->sigC = nullptr;
						insertar_col(nuevoFil, nuevaCol);
						nt++;
					}
					else {
						NodoCol* nuevaCol = new NodoCol;
						nuevaCol->col = j + 1;
						nuevaCol->dato = e;
						nuevaCol->sigC = nullptr;
						insertar_col(fila, nuevaCol);
						nt++;
					}
				}
			}
		}
		aux = ptrMat;
		while (aux != nullptr) {
			NodoCol* col = aux->ptrCol;
			while (col != nullptr) {
				if (col->dato == r) {
					NodoCol* sup = col;
					col = col->sigC;
					suprime(aux, sup);
					nt--;
				}
				else
					col = col->sigC;
			}
			aux = aux->sigF;
		}
		rep = r;
	}
}
//---------------------------------------------------------------------------
void Matriz_Ptr2N :: insertar_fila(NodoFil* nf){
if (ptrMat == nullptr) {
		ptrMat = nf;
	}
	else {
		NodoFil* aux = ptrMat;
		NodoFil* antSiFinaliza;
		while (aux != nullptr) {
			antSiFinaliza = aux;
			if (nf->fil < aux->fil) {
				if (aux == ptrMat) {
					ptrMat == nf;
					nf->antF = nullptr;
					nf->sigF = aux;
					aux->antF = nf;
				}
				else {
					NodoFil* ant = aux->antF;
					ant->sigF = nf;
					aux->antF = nf;
					nf->antF = ant;
					nf->sigF = aux;
				}
				return;
			}
			aux = aux->sigF;
		}
		// Inserta al final
		antSiFinaliza->sigF = nf;
		nf->antF = antSiFinaliza;
		nf->sigF = nullptr;

	}
}
//---------------------------------------------------------------------------
void Matriz_Ptr2N :: insertar_col(NodoFil* nf, NodoCol* nc){
  if (nf->ptrCol == nullptr) {
		nf->ptrCol = nc;
	}
	else {
		nc->sigC = nf->ptrCol;
		nf->ptrCol = nc;
	}
}
//---------------------------------------------------------------------------
NodoFil* Matriz_Ptr2N :: existe_fil(int f){
 NodoFil* aux = ptrMat;
	while (aux != nullptr) {
		if (aux->fil == f)
			return aux;
		aux = aux->sigF;
	}
	return nullptr;
}
//---------------------------------------------------------------------------
NodoCol* Matriz_Ptr2N :: existe_col(NodoFil* f, int c){
   if (f == nullptr)
		return nullptr;
	NodoCol* aux = f->ptrCol;
	while (aux != nullptr) {
		if (aux->col == c)
			return aux;
		aux = aux->sigC;
	}
	return nullptr;
}
//---------------------------------------------------------------------------
NodoCol* Matriz_Ptr2N :: anterior(NodoFil* nf,NodoCol* p){
   if (p == nf->ptrCol) {
		return nullptr;
	}
	else {
		NodoCol* x = nf->ptrCol;
		NodoCol* ant = nullptr;
		while (x != nullptr) {
			if (x == p) {
				return ant;
			}
			ant = x;
			x = x->sigC;
		}
	}
}
//---------------------------------------------------------------------------
void Matriz_Ptr2N :: suprime(NodoFil* nf,NodoCol* p){
if (p == nf->ptrCol) {
		NodoCol* x = nf->ptrCol;
		nf->ptrCol = nf->ptrCol->sigC;
		delete(x);
	}
	else {
		NodoCol* ant = anterior(nf, p);
		ant->sigC = p->sigC;
		delete(p);
	}
	if (nf->ptrCol == nullptr) {
		if (nf == ptrMat) {
			ptrMat = ptrMat->sigF;
			ptrMat->antF = nullptr;
			delete(nf);
		}
		else {
			NodoFil* ant = nf->antF;
			NodoFil* sig = nf->sigF;
			ant->sigF = sig;
			if (sig != nullptr)
				sig->antF = ant;
			delete(nf);
		}
	}
}
//---------------------------------------------------------------------------
void Matriz_Ptr2N :: Mostrar_Matriz(int x1,int y1,TCanvas* Canvas){
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


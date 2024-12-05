//---------------------------------------------------------------------------

#pragma hdrstop
#include "CP_Vector.h"
//---------------------------------------------------------------------------
Pila_Vector :: Pila_Vector(){
 elementos = new int [maxPila];
 tope=0; c=0;
}
//---------------------------------------------------------------------------
bool Pila_Vector :: vacia(){
 return tope==0;
}
//---------------------------------------------------------------------------
void Pila_Vector :: meter(int e){
 if (tope < maxPila) {
		elementos[tope] = e;
		tope++;
	}
}
//---------------------------------------------------------------------------
void Pila_Vector :: sacar(int &e){
 if (!vacia()) {
		e = elementos[tope - 1];
		tope--;
	}
	else
		ShowMessage("Error de Rango");
}
//---------------------------------------------------------------------------
void Pila_Vector :: meter1(int e){
   if (c == 0) {
		elementos[0] = e;
		c++;
	}
	else {
		for (int i = c; i > 0; i--) {
			elementos[i] = elementos[i - 1];
		}
		elementos[0] = e;
		c++;
	}
}
//---------------------------------------------------------------------------
void Pila_Vector :: sacar1(int &e){
  if (c > 0) {
		e = elementos[0];
		for (int i = 0; i < c - 1; i++) {
			elementos[i] = elementos[i + 1];
		}
		c--;
	}
}
//---------------------------------------------------------------------------
int Pila_Vector :: sacar(){
 if (!vacia()) {
		int e = elementos[tope - 1];
		tope--;
		return e;
	}
	else
   ShowMessage("Fuera de Rango");
}
//---------------------------------------------------------------------------
int Pila_Vector :: cima(){
if (!vacia()) {
		return elementos[tope - 1];
	}
}
//---------------------------------------------------------------------------
void Pila_Vector :: mostrar_Pila(int x1 , int y1 , TCanvas* Canvas){
 Pila_Vector* aux = new Pila_Vector();
	while (!vacia()) {
		int e;
		sacar(e);
		aux->meter(e);
		AnsiString cad= "| "+AnsiString(e)+" |";
		Canvas->TextOut(x1,y1,cad);
		y1+=25;
	}
	while (!aux->vacia()) {
		int e;
		aux->sacar(e);
		meter(e);
	}
}
//---------------------------------------------------------------------------;
void Pila_Vector :: mostrarVector(int x1,int y1,TCanvas* Canvas){
AnsiString cad="[   ";
 for (int i = 0; i < tope; i++) {
		cad = cad + AnsiString(elementos[i])+ " , ";
	}
	cad.Delete(cad.Length()-2,2);
	Canvas->TextOut(x1,y1,cad+" ]");
}
//---------------------------------------------------------------------------


#pragma package(smart_init)

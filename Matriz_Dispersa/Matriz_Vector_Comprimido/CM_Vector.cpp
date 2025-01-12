//---------------------------------------------------------------------------

#pragma hdrstop

#include "CM_Vector.h"
#include <vcl.h>
//---------------------------------------------------------------------------
Matriz_VComprimido :: Matriz_VComprimido(){
  rep=0; dF=0; dC=0; nt=0;
  vF=new int [ dF * dC];
	vC=new int [ dF * dC];
	  vD=new int [ dF * dC];
 }
 //---------------------------------------------------------------------------
 void Matriz_VComprimido :: dimensionar(int nf,int nc){
	 dF=nf; dC=nc;
	   vF=new int [ dF * dC];
		vC=new int [ dF * dC];
		 vD=new int [ dF * dC];
 }
 //---------------------------------------------------------------------------
 int Matriz_VComprimido :: dimension_Fila(){
   return dF;
 }
 //---------------------------------------------------------------------------
 int Matriz_VComprimido :: dimension_Columna(){
   return dC;
 }
 //---------------------------------------------------------------------------
 void Matriz_VComprimido :: poner(int f,int c,int valor){
	   if (f>0 && f<dF) {
			   if (c>0 && c<dC) {
				int pos = posicion(f, c);
					if (pos == -1 && valor != rep) {
					 vF[nt] = f;
					 vC[nt] = c;
					 vD[nt] = valor;
					 nt++;
					}
			 else {
					if (valor == rep) {
					eliminar_posicion(vD, pos, nt);
					eliminar_posicion(vF, pos, nt);
					eliminar_posicion(vC, pos, nt);
					nt--;
				   }
					else {
					vD[pos] = valor;
				   }
			}
				return;
			   }
		   }
		   ShowMessage("Error de Rango");
 }
 //---------------------------------------------------------------------------

 //---------------------------------------------------------------------------
 int Matriz_VComprimido :: elemento(int f,int c){
  if (f > 0 && f <= dF) {
		if (c > 0 && c <= dC) {
			int pos = posicion(f, c);
			if (pos == -1)
				return rep;
			else
				return vD[pos];
		}
	}
	ShowMessage("Error de Rango");
 }
 //---------------------------------------------------------------------------
 void Matriz_VComprimido :: definir_ValorRepetido(int r){
	bool sinRep = true;
	for (int i = 0; i < nt; i++) {
		if (vD[i] == r) {
			sinRep = false;
			break;
		}
	}
	if (nt == 0 || sinRep == true) {
		rep = r;
	}
	else {
		for (int i = 1; i <= dF; i++) {
			for (int j = 1; j <= dC; j++) {
				int d = elemento(i, j);
				if (d == rep) {
					vF[nt] = i;
					vC[nt] = j;
					vD[nt] = d;
					nt = nt + 1;
				}
			}
		}
		for (int i = 1; i <= nt; i++) {
			if (vD[i - 1] == r) {
				int posicion = i - 1;
				for (int j = posicion; j < nt - 1; j++) {
					vF[j] = vD[j + 1];
					vC[j] = vD[j + 1];
					vD[j] = vD[j + 1];
				}
				i = i - 1;
				nt = nt - 1;
			}
		}
		rep = r;
	}
 }
 //---------------------------------------------------------------------------
 int Matriz_VComprimido :: posicion(int f,int c){
	for (int i = 0; i < nt; i++) {
		if (vF[i] == f && vC[i] == c)
			return i;
	}
	return -1;
 }
 //---------------------------------------------------------------------------
 bool Matriz_VComprimido :: validar(int repe){
	 bool vacio = nt == 0;
	bool repetidos = true;
	for (int i = 0; i < nt; i++) {
		if (vD[i] == rep) {
			repetidos = false;
			break;
		}
	}
	return vacio || repetidos;
 }
 //---------------------------------------------------------------------------
 int Matriz_VComprimido :: numero_casillas_validas(){
 int c = 0;
	int n = dF * dC;
	for (int i = 0; i < n; i++) {
		if (vF[i] == 0)
			break;
		c++;
	}
	return c;
 }
 //---------------------------------------------------------------------------
 void Matriz_VComprimido :: Mostrar_MComprimida(int x1,int y1,TCanvas* Canvas){
	 Canvas->Brush->Color=clBtnFace;
	 Canvas->Rectangle(0,0,1000,1000);
	 Canvas->Font->Size=10;
	 AnsiString r = "";
	for (int i = 0; i < dF; i++) {
		r += "| ";
		for (int j = 0; j < dC; j++) {
			r += IntToStr(elemento(i + 1, j + 1));
			if (j < dC - 1)
				r += " , ";
		}
		r += " |";
		Canvas->TextOut(x1,y1,r);
		y1=y1+30;
		r="";
	}

	Canvas->TextOut(x1,y1,"nt : "+IntToStr(nt));
	Canvas->Font->Size=7;
 }
  //---------------------------------------------------------------------------
   void Matriz_VComprimido :: eliminar_posicion(int* v,int k,int n){
   for (int i = k; i < n - 1; i++) {
		v[i] = v[i + 1];
	}
   }
  //---------------------------------------------------------------------------
#pragma package(smart_init)

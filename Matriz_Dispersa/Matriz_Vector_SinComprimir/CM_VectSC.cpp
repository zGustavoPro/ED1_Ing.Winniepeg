//---------------------------------------------------------------------------

#pragma hdrstop

#include "CM_VectSC.h"
//---------------------------------------------------------------------------
Matriz_VNormal :: Matriz_VNormal(){
    df = 0;
	dc = 0;
	rep = 0;
	nt = 0;
	vf = new int[df + 1];
	vc = new int[df * dc];
	vd = new int[df * dc];
	for (int i = 0; i < df + 1; i++)
		vf[i] = 1;
 }
 //---------------------------------------------------------------------------
 void Matriz_VNormal :: dimensionar(int f,int c){
		   df = f;
	dc = c;
	vf = new int[df + 1];
	vc = new int[df * dc];
	vd = new int[df * dc];
	for (int i = 0; i < df + 1; i++)
		vf[i] = 1;
 }
 //---------------------------------------------------------------------------
 int Matriz_VNormal :: dimension_Fila(){
   return df;
 }
 //---------------------------------------------------------------------------
 int Matriz_VNormal :: dimension_Columna(){
   return dc;
 }
 //---------------------------------------------------------------------------
 void Matriz_VNormal :: poner(int f,int c,int valor){
	if (f > 0 && f <= df) {
		if (c > 0 && c <= dc) {
			int existe = posicion(f, c);
			if (existe == -1) {
				int pos = posicion_insertar(f);
				insertar_en_vector(vc, nt, pos, c);
				insertar_en_vector(vd, nt, pos, valor);
				nt++;
				for (int i = f; i < df + 1; i++)
					vf[i]++;
			}
			else {
				vd[existe] = valor;
			}
			return;
		}
	}
		ShowMessage("Fuera de Rango");
 }
 //---------------------------------------------------------------------------
   void Matriz_VNormal :: insertar_en_vector(int* vector,int n,int &k,int &elemento){
		for (int i = n; i > k; i--) {
		vector[i] = vector[i - 1];
	}
	vector[k] = elemento;
   }
 //---------------------------------------------------------------------------
 int Matriz_VNormal :: elemento(int f,int c){
     if (f > 0 && f <= df) {
		if (c > 0 && c <= dc) {
			int pos = posicion(f, c);
			if (pos == -1)
				return rep;
			else
				return vd[pos];
		}
	}
	ShowMessage("Error de Rango");
 }
 //---------------------------------------------------------------------------
 void Matriz_VNormal :: definir_ValorRepetido(int r){
	rep=r;
 }
 //---------------------------------------------------------------------------
 int Matriz_VNormal :: posicion(int f,int c){
   int pos_inicial = 0;
	for (int i = 0; i < f - 1; i++) {
		pos_inicial += (vf[i + 1] - vf[i]);
	}
	int max = vf[f] - vf[f - 1];
	for (int i = 0; i < max; i++) {
		if (vc[pos_inicial + i] == c)
			return pos_inicial + i;
	}
	return -1;
 }
 //---------------------------------------------------------------------------
 int Matriz_VNormal :: numero_casillas_validas(){
      int c = 0;
	int n = df * dc;
	for (int i = 0; i < n; i++) {
		if (vf[i] == 0)
			break;
		c++;
	}
	return c;
 }
 //---------------------------------------------------------------------------
 void Matriz_VNormal :: Mostrar_Matriz(int x1,int y1,TCanvas* Canvas){
	 Canvas->Brush->Color=clBtnFace;
	 Canvas->Rectangle(0,0,1000,1000);
	 Canvas->Font->Size=10;
	 AnsiString r = "";
	for (int i = 0; i < df; i++) {
		r += "| ";
		for (int j = 0; j < dc; j++) {
			r += IntToStr(elemento(i + 1, j + 1));
			if (j < dc - 1)
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
	int Matriz_VNormal :: posicion_insertar(int f){
     int suma = 0;
	for (int i = 0; i < f; i++) {
		suma = suma + (vf[i + 1] - vf[i]);
	}
	return suma;
	}
 //---------------------------------------------------------------------------
#pragma package(smart_init)

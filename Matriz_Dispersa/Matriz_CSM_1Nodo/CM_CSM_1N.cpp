   //---------------------------------------------------------------------------

#pragma hdrstop

#include "CM_CSM_1N.h"
//---------------------------------------------------------------------------
Matriz_CSM :: Matriz_CSM(CSMemoria* mem){
 nt=0;
 df=0; dc=0; rep=0;
 m=mem; ptrMat=-1;
}
//---------------------------------------------------------------------------
Matriz_CSM :: Matriz_CSM(){
 nt=0; m=new CSMemoria();
 df=0; dc=0; rep=0;
 ptrMat=-1;
}
//---------------------------------------------------------------------------
void Matriz_CSM :: dimensionar(int f,int c){
 df=f; dc=c;
}
//---------------------------------------------------------------------------
int Matriz_CSM :: dimension_Fila(){
 return df;
}
//---------------------------------------------------------------------------
int Matriz_CSM :: dimension_Columna(){
 return dc;
}
//---------------------------------------------------------------------------
void Matriz_CSM :: poner(int f,int c,int valor){
  if (f > 0 && f <= df) {
		if (c > 0 && c <= dc) {
			int pos = existe(f,c);
			if (pos == -1 && valor != rep) {
				int nuevo = m->new_espacio("fil,col,dato,sig");
				m->Poner_dato(nuevo, "->fil", f);
				m->Poner_dato(nuevo, "->col", c);
				m->Poner_dato(nuevo, "->dato", valor);
				m->Poner_dato(nuevo, "->sig", ptrMat);
				ptrMat = nuevo;
				nt++;
			}
			else {
				m->Poner_dato(pos,"->dato", valor);
				if (valor == rep) {
					suprime(pos);
					nt--;
				}
			}
			return;
		}
	}
	ShowMessage("Error de Rango");
}
//---------------------------------------------------------------------------
int Matriz_CSM :: elemento(int f,int c){
if (f > 0 && f <= df) {
		if (c > 0 && c <= dc) {
			int pos = existe(f, c);
			if (pos == -1)
				return rep;
			else{
				int pos_dato = m->Obtener_Dato(pos,"->dato");
				return pos_dato;
			}
		}
	}
	ShowMessage("Error de Dimension");
}
//---------------------------------------------------------------------------
void Matriz_CSM :: definir_ValorRepetido(int r){
   rep=r;
}
//---------------------------------------------------------------------------
void Matriz_CSM :: Mostrar_Matriz(int x1,int y1,TCanvas* Canvas){
	 Canvas->Brush->Color=clBtnFace;

	 TRect area(x1+30,y1-20,x1+400,y1+500);
	 Canvas->FillRect (area);

	 Canvas->Font->Size=10;
	 AnsiString r = "";

	for (int i = 0; i < df; i++) {
		r += "| ";
		for (int j = 0; j < dc; j++) {
			r +=IntToStr(elemento(i + 1, j + 1));
			if (j < dc - 1)
				r += " , ";
		}
		r += " |";
		Canvas->TextOut(x1,y1,r);
		y1=y1+30;
		r="";
	}
   //	Canvas->TextOut(x1,y1,"nt : "+IntToStr(nt));
	Canvas->Font->Size=10;

}
//---------------------------------------------------------------------------
int Matriz_CSM :: anterior(int p){
   if (nt == 0 || p == ptrMat) {
		return -1;
	}
	else {
		int x = ptrMat;
		int ant = -1;
		while (x != -1) {
			if (x == p) {
				return ant;
			}
			ant = x;
			int x_sig = m->Obtener_Dato(x,"->sig");
			x = x_sig;
		}
	}
}
//---------------------------------------------------------------------------
void Matriz_CSM :: suprime(int p){
   if (nt == 0) {
		return;
	}
	else if (p == ptrMat) {
		int x = ptrMat;
		int ptrMat_sig = m->Obtener_Dato(ptrMat,"->sig");
		ptrMat = ptrMat_sig;
		m->Delete_espacio(x);
	}
	else {
		int ant = anterior(p);
		int p_sig = m->Obtener_Dato(p,"->sig");
		m->Poner_dato(ant,"->sig", p_sig);
		m->Delete_espacio(p);
	}
}
//---------------------------------------------------------------------------
int Matriz_CSM :: existe(int f,int c){
  int aux = ptrMat;
	while (aux != -1) {
		int aux_fil = m->Obtener_Dato(aux,"->fil");
		int aux_col = m->Obtener_Dato(aux,"->col");
		if (aux_fil == f && aux_col == c)
			return aux;
		int aux_sig = m->Obtener_Dato(aux,"->sig");
		aux = aux_sig;
	}
	return -1;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)


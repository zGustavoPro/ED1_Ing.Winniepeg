   //---------------------------------------------------------------------------

#pragma hdrstop

#include "CM_CSM_1N.h"
//---------------------------------------------------------------------------
Matriz_CSM :: Matriz_CSM(CSMemoria* mem){
 nt=0;
 df=0; dc=0; rep=0;
 m=mem; ptrMat=-1;
 retroceder = false;
 pila=new Pila_CSMemoria(m);
}
//---------------------------------------------------------------------------
Matriz_CSM :: Matriz_CSM(){
 nt=0; m=new CSMemoria();
 df=0; dc=0; rep=0;
 ptrMat=-1;
 retroceder = false;
 pila=new Pila_CSMemoria(m);
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
			int anterior=this->elemento(f,c);
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
			if(!retroceder){
			pila->meter(anterior);
			pila->meter(c);
			pila->meter(f);
			}else{
				retroceder=false;
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

	 TRect area(x1-30,y1-20,x1+30+df*25,y1+20+dc*25);
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
bool Matriz_CSM :: EsSudoku() {
		for (int f = 1; f <= df; f++) {
			for (int c = 1; c <= dc; c++) {
				int datoM = elemento(f, c);
				for (int fb = 1; fb <= df; fb++) {
					if ((fb != f && elemento(fb, c) == datoM) || elemento(fb,c)==rep) {
					   //	ShowMessage("No es Sudoku Error en la fila :"+AnsiString(fb)+" y Error en la Columna :"+AnsiString(c));
						return false;
					}
				}
				for (int cb = 1; cb <= dc; cb++) {
					if ((cb != c && elemento(f, cb) == datoM)||elemento(f,cb)==rep) {
						 //	ShowMessage("No es Sudoku Error en la fila :"+AnsiString(f)+" y Error en la Columna :"+AnsiString(cb));
						return false;
					}
				}
			}
		}
		// Verificación de subcuadros 3x3
		if(dc==9 && df==9) {
		for (int startRow = 1; startRow <= 9; startRow += 3) {
			for (int startCol = 1; startCol <= 9; startCol += 3) {
				bool seen[10] = {false};
				for (int r = startRow; r < startRow + 3; r++) {
					for (int c = startCol; c < startCol + 3; c++) {
						int datoM = elemento(r, c);
						if (seen[datoM]) {
						   //	ShowMessage("No es Sudoku");
							return false;
						}
						seen[datoM] = true;
					}
				}
			}
		}
	}
	   //	ShowMessage("Es Sudoku , Ganaste!!");
		return true;
}
//---------------------------------------------------------------------------
 void Matriz_CSM :: retrocederPila(){
 if(!pila->vacia()){
 retroceder=true;
 int f,c,e;
  pila->sacar(f);
  pila->sacar(c);
  pila->sacar(e);
  this->poner(f,c,e);
 }
 }
//---------------------------------------------------------------------------
bool Matriz_CSM :: Matriz_Llena(){
for (int f=1; f <=df; f++) {
 for (int c=1; c <=dc; c++) {
   if(this->elemento(f,c)==rep)
   return false;
 }
}
return true;
}
//---------------------------------------------------------------------------
bool Matriz_CSM::backTracking_Sudoku() {
	if (this->EsSudoku()) {
		ShowMessage("Sudoku Resuelto!");
		return true;
	}

	for (int f = 1; f <= df; f++) {
		for (int c = 1; c <= dc; c++) {
			if (elemento(f, c) == rep) {
				for (int valor = 1; valor <= 9; valor++) {
					if (puede_Colocar(f, c, valor)) {
						poner(f, c, valor);
						if (backTracking_Sudoku()) {
							return true;
						}
						retrocederPila();
					}
				}
				return false;
			}
		}
	}
	ShowMessage("No se Pudo resolver el Sudoku");
	return false;
}
//---------------------------------------------------------------------------
bool Matriz_CSM :: puede_Colocar(int f, int c, int num) {
	   for (int i = 1; i <= df; i++) {
		if (elemento(i, c) == num || elemento(f, i) == num) {
			return false;
		}
	  }

	int startRow = (f - 1) / 3 * 3 + 1;
	int startCol = (c - 1) / 3 * 3 + 1;
	for (int i = startRow; i < startRow + 3; i++) {
		for (int j = startCol; j < startCol + 3; j++) {
			if (elemento(i, j) == num) {
				return false;
			}
		}
	}
	return true;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)


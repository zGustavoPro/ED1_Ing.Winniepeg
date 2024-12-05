//---------------------------------------------------------------------------

#pragma hdrstop

#include "CM_CSM2N.h"
//---------------------------------------------------------------------------
Matriz_CSM2N :: Matriz_CSM2N(CSMemoria* mem){
	m=mem;
	ptrMat = -1;
	df = 0; dc = 0;
	rep = 0; nt=0;
	retroceder = false;
	pila=new Pila_CSMemoria(m);
}
//---------------------------------------------------------------------------
Matriz_CSM2N :: Matriz_CSM2N(){
	m = new CSMemoria();
	ptrMat = -1;
	df = 0; dc = 0;
	rep = 0; nt=0;
    retroceder = false;
	pila=new Pila_CSMemoria(m);
}
//---------------------------------------------------------------------------
void Matriz_CSM2N :: dimensionar(int f,int c){
  df=f; dc=c;
}
//---------------------------------------------------------------------------
int Matriz_CSM2N :: dimension_Fila(){
 return df;
}
//---------------------------------------------------------------------------
int Matriz_CSM2N :: dimension_Columna(){
 return dc;
}
//---------------------------------------------------------------------------
void Matriz_CSM2N :: poner(int f,int c,int valor){
if (f > 0 && f <= df) {
		if (c > 0 && c <= dc) {
			int fila = existe_fil(f);
			int anterior=this->elemento(f,c);
			if (fila != -1) {
				int col = existe_col(fila, c);
				if (col == -1) {
					int nuevaCol = m->new_espacio("col,dato,sigC");
					m->Poner_dato(nuevaCol, "->col", c);
					m->Poner_dato(nuevaCol, "->dato", valor);
					m->Poner_dato(nuevaCol, "->sigC", -1);
					insertar_col(fila, nuevaCol);
					nt++;
				}
				else {
					m->Poner_dato(col, "->dato", valor);
				  /*	if (valor==rep) {
					   suprime(fila,col);
					}*/
				}
			}
			else {
				if (valor != rep) {
					int nuevoFil = m->new_espacio("fil,sigF,antF,ptrCol");
					m->Poner_dato(nuevoFil, "->fil", f);
					m->Poner_dato(nuevoFil, "->sigF", -1);
					m->Poner_dato(nuevoFil, "->antF", -1);//->sigF
					m->Poner_dato(nuevoFil, "->ptrCol", -1);
					insertar_fila(nuevoFil);
					int nuevaCol = m->new_espacio("col,dato,sigC");
					m->Poner_dato(nuevaCol, "->col", c);
					m->Poner_dato(nuevaCol, "->dato", valor);
					m->Poner_dato(nuevaCol, "->sigC", -1);
					insertar_col(nuevoFil, nuevaCol);
					nt++;
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
	ShowMessage("Fuera de Rango");
}
//---------------------------------------------------------------------------
int Matriz_CSM2N :: elemento(int f,int c){
 if (f > 0 && f <= df) {
		if (c > 0 && c <= dc) {
			int fila = existe_fil(f);
			int col = existe_col(fila, c);
			if (fila != -1 && col != -1) {
				return m->Obtener_Dato(col, "->dato");
			}
			else {
				return rep;
			}
		}
	}
	  throw "Fuera de Rango";
}
//---------------------------------------------------------------------------
void Matriz_CSM2N :: definir_ValorRepetido(int r){
 rep=r;
}
//---------------------------------------------------------------------------
void Matriz_CSM2N :: Mostrar_Matriz(int x1,int y1,TCanvas* Canvas){
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
void Matriz_CSM2N :: insertar_fila(int nf){
  if (ptrMat == -1) {
		ptrMat = nf;
	}
	else {
		int aux = ptrMat;
		int antSiFinaliza;
		while (aux != -1) {
			antSiFinaliza = aux;
			int nf_fil = m->Obtener_Dato(nf, "->fil");
			int aux_fil = m->Obtener_Dato(aux, "->fil");
			if (nf_fil < aux_fil) {
				if (aux == ptrMat) {
					ptrMat = nf; //ptrMat==nf;
					m->Poner_dato(nf, "->antF", -1);
					m->Poner_dato(nf, "->sigF", aux);
					m->Poner_dato(aux, "->antF", nf);
				}
				else {
					int aux_antF = m->Obtener_Dato(aux, "->antF");
					int ant = aux_antF;
					m->Poner_dato(ant, "->sigF", nf);
					m->Poner_dato(aux, "->antF", nf);
					m->Poner_dato(nf, "->antF", ant);
					m->Poner_dato(nf, "->sigF", aux);
				}
				return;
			}
			aux = m->Obtener_Dato(aux, "->sigF");
		}
		m->Poner_dato(antSiFinaliza, "->sigF", nf);
		m->Poner_dato(nf, "->antF", antSiFinaliza);
		m->Poner_dato(nf, "->sigF", -1);
	}

}
//---------------------------------------------------------------------------
void Matriz_CSM2N :: insertar_col(int nf, int nc){
   int nf_ptrCol = m->Obtener_Dato(nf, "->ptrCol");
	if (nf_ptrCol == -1) {
		m->Poner_dato(nf, "->ptrCol", nc);
	}
	else {
		m->Poner_dato(nc, "->sigC", nf_ptrCol);
		m->Poner_dato(nf, "->ptrCol", nc);
	}

}
//---------------------------------------------------------------------------
int Matriz_CSM2N :: existe_fil(int f){
  int aux = ptrMat;
	while (aux != -1) {
		int aux_fil = m->Obtener_Dato(aux, "->fil");
		if (aux_fil == f)
			return aux;
		aux = m->Obtener_Dato(aux, "->sigF");
	}
	return -1;
}
//---------------------------------------------------------------------------
int Matriz_CSM2N :: existe_col(int f, int c){
   if (f == -1)
		return -1;
	int f_ptrCol = m->Obtener_Dato(f, "->ptrCol");
	int aux = f_ptrCol;
	while (aux != -1) {
		int aux_col = m->Obtener_Dato(aux, "->col");
		if (aux_col == c)
			return aux;
		aux = m->Obtener_Dato(aux, "->sigC");
	}
	return -1;
}
//---------------------------------------------------------------------------
int Matriz_CSM2N :: anterior(int nf, int p){
 int nf_ptrCol= m->Obtener_Dato(nf, "->ptrCol");
	if (p == nf_ptrCol) {
		return -1;
	}
	else {
		int x = nf_ptrCol;
		int ant = -1;
		while (x != -1) {
			if (x == p) {
				return ant;
			}
			ant = x;
			x = m->Obtener_Dato(x, "->sigC");
		}
	}
}
//---------------------------------------------------------------------------
void Matriz_CSM2N :: suprime(int nf, int p){
  int nf_ptrCol = m->Obtener_Dato(nf, "->ptrCol");
	if (p == nf_ptrCol) {
		int x = nf_ptrCol;
		int nf_ptrCol_sigC = m->Obtener_Dato(nf_ptrCol, "->sigC");
		m->Poner_dato(nf, "->ptrCol", nf_ptrCol_sigC);
		m->Delete_espacio(x);
	}
	else {
		int ant = anterior(nf, p);
		int p_sigC = m->Obtener_Dato(p, "->sigC");
		m->Poner_dato(ant, "->sigC", p_sigC);
		m->Delete_espacio(p);
	}
	int nt_ptrCol = m->Obtener_Dato(nf, "->ptrCol");
	if (nt_ptrCol == -1) {
		if (nf == ptrMat) {
			ptrMat = m->Obtener_Dato(ptrMat, "->sigF");
			m->Poner_dato(ptrMat, "->antF", -1);
			m->Delete_espacio(nf);
		}
		else {
			int ant = m->Obtener_Dato(nf, "->antF");
			int sig = m->Obtener_Dato(nf, "->sigF");
			m->Poner_dato(ant, "->sigF", sig);
			if (sig != -1)
				m->Poner_dato(sig, "->antF", ant);
			m->Delete_espacio(nf);
		}
	}
}
//---------------------------------------------------------------------------
bool Matriz_CSM2N :: EsSudoku() {
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
		/*
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
		} */
	   //	ShowMessage("Es Sudoku , Ganaste!!");
		return true;
}

//---------------------------------------------------------------------------
 void Matriz_CSM2N :: retrocederPila(){
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
bool Matriz_CSM2N :: Matriz_Llena(){
for (int f=1; f <=df; f++) {
 for (int c=1; c <=dc; c++) {
   if(this->elemento(f,c)==rep)
   return false;
 }
}
return true;
}
//---------------------------------------------------------------------------
bool Matriz_CSM2N :: backTracking_Sudoku() {
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
bool Matriz_CSM2N :: puede_Colocar(int f, int c, int num ) {
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



//---------------------------------------------------------------------------

#pragma hdrstop

#include "CM_Ptr1N.h"
//---------------------------------------------------------------------------
Matriz_Ptr1N :: Matriz_Ptr1N(){
 df=0; dc=0; nt=0;
 rep=0; ptrMat=nullptr;

	retroceder = false;
	pila=new Pila_CSMemoria();
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
		int anterior=elemento(f,c);
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

		if(!retroceder){
			pila->meter(anterior);
			pila->meter(c);
			pila->meter(f);
			}else{
				retroceder=false;
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
bool Matriz_Ptr1N :: EsSudoku() {
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
 void Matriz_Ptr1N :: retrocederPila(){
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
bool Matriz_Ptr1N :: Matriz_Llena(){
for (int f=1; f <=df; f++) {
 for (int c=1; c <=dc; c++) {
   if(this->elemento(f,c)==rep)
   return false;
 }
}
return true;
}
//---------------------------------------------------------------------------
bool Matriz_Ptr1N :: backTracking_Sudoku() {
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
bool Matriz_Ptr1N :: puede_Colocar(int f, int c, int num) {
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


//---------------------------------------------------------------------------

#pragma hdrstop

#include "CM_CSM_1N.h"
//---------------------------------------------------------------------------
Matriz_CSM :: Matriz_CSM(CSMemoria* mem){
   nt=0;  df=0; dc=0;  ptrMat=-1;
   m=mem; dc=0; rep=0;
	  //sudoku
   retroceder = false;
   pila=new Pila_CSMemoria(m);
	  //Pacman
   pacman=1;     pacmanF=-1;    pacmanC=-1;  cesped=4;
   muro=2;       moneda=3;      cantMonedas=-1;
   comidos=0;    contador=0;    rompeMuros=false;
   playIniciado=false;          puntos=0;
}
//---------------------------------------------------------------------------
Matriz_CSM :: Matriz_CSM(){
   nt=0; m=new  CSMemoria(); df=0;
   dc=0; rep=0; ptrMat=-1;
	  //Sudoku
   retroceder = false;
   pila=new Pila_CSMemoria(m);
	  //Pacman
   pacman=1;    pacmanF=-1;   pacmanC=-1; cesped=4;
   muro=2;      moneda=3;     cantMonedas=-1;
   comidos=0;   contador=0;   rompeMuros=false;
   playIniciado=false;        puntos=0;
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
				int anterior;
				if (playIniciado==true) {
				 anterior=this->elemento(f,c);
				}
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
			if(playIniciado==true){
			if(!retroceder){
			pila->meter(anterior);
			pila->meter(c);
			pila->meter(f);
			} else{
				retroceder=false;
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
}
//---------------------------------------------------------------------------
void Matriz_CSM :: definir_ValorRepetido(int r){
   rep=r;
}
//---------------------------------------------------------------------------
void Matriz_CSM :: Mostrar_Matriz(int x1,int y1,TCanvas* Canvas){
	 Canvas->Brush->Color=clAqua;

	 TRect area(x1-30,y1-20,x1+30+df*25,y1+50+dc*25);
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

   //Canvas->TextOut(x1,y1,"nt : "+IntToStr(nt));
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
void Matriz_CSM :: EsSudoku() {
	  if (Matriz_Llena()) {
		for (int f = 1; f <= df; f++) {
			for (int c = 1; c <= dc; c++) {
				int datoM = elemento(f, c);
				for (int fb = 1; fb <= df; fb++) {
					if (fb != f && elemento(fb, c) == datoM) {
						ShowMessage("No es Sudoku Error en la fila :"+AnsiString(fb)+" y Error en la Columna :"+AnsiString(c));
						return;
					}
				}
				for (int cb = 1; cb <= dc; cb++) {
					if (cb != c && elemento(f, cb) == datoM) {
							ShowMessage("No es Sudoku Error en la fila :"+AnsiString(f)+" y Error en la Columna :"+AnsiString(cb));
						return;
					}
				}
			}
		}
		for (int startRow = 1; startRow <= 9; startRow += 3) {
			for (int startCol = 1; startCol <= 9; startCol += 3) {
				bool seen[10] = {false};
				for (int r = startRow; r < startRow + 3; r++) {
					for (int c = startCol; c < startCol + 3; c++) {
						int datoM = elemento(r, c);
						if (seen[datoM]) {
							ShowMessage("No es Sudoku");
							return;
						}
						seen[datoM] = true;
					}
				}
			}
		}
		ShowMessage("Es Sudoku , Ganaste!!");
	} else {
		ShowMessage("Falta Rellenar La matriz");
	}
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


//Pacman


//---------------------------------------------------------------------------
void Matriz_CSM :: Mostrar_MapaP(int x1, int y1, TCanvas* Canvas) {

 AnsiString Imuro = "C:\\Universidad_Gustavo\\2-2024\\E.Datos l\\Pacman\\IMagenesPacman\\roca.bmp";
 AnsiString Ipacman = "C:\\Universidad_Gustavo\\2-2024\\E.Datos l\\Pacman\\IMagenesPacman\\pacman.bmp";
 AnsiString Imoneda = "C:\\Universidad_Gustavo\\2-2024\\E.Datos l\\Pacman\\IMagenesPacman\\Comida.bmp";
 AnsiString Icesped = "C:\\Universidad_Gustavo\\2-2024\\E.Datos l\\Pacman\\IMagenesPacman\\cesped1.bmp";

   TBitmap* bitmap=new TBitmap();
   Canvas->TextOut(x1+40,y1-50,"Score : "+IntToStr(puntos));
   int tileSize = 25;

	for (int i = 1; i <= df; i++) {
		for (int j = 1; j <= dc; j++) {
			int valor = elemento(i, j);
			int x = x1 + (j - 1) * tileSize;
			int y = y1 + (i - 1) * tileSize;
			AnsiString imagePath;
			switch (valor) {
				case 1: // Pacman
					imagePath = Ipacman;
					break;
				case 2: // Muro
					imagePath = Imuro;
					break;
				case 3: // Moneda
					imagePath = Imoneda;
					break;
				case 4: // C�sped
				  imagePath = Icesped;
					break;
				default:
					continue;
			}
		  if (FileExists(imagePath)) {
			 bitmap->LoadFromFile(imagePath);
			 TRect destRect(x, y, x + tileSize, y + tileSize);
			 Canvas->StretchDraw(destRect, bitmap);
		  }
		}
	}
	delete bitmap;
}
//---------------------------------------------------------------------------
void Matriz_CSM :: setColPacman(int c){
  pacmanC=c;
}
//---------------------------------------------------------------------------
void Matriz_CSM :: setFilPacman(int f){
pacmanF=f;
}
//---------------------------------------------------------------------------
int Matriz_CSM :: getFilPacman(){
return pacmanF;
}
//---------------------------------------------------------------------------
int Matriz_CSM :: getColPacman(){
return pacmanC;
}
//---------------------------------------------------------------------------
void Matriz_CSM ::setScored(int n){
 puntos=n;
}

int Matriz_CSM :: Scored(){
return puntos;
}
//---------------------------------------------------------------------------
void Matriz_CSM::recorrerArriba(int f, int c) {   // 1 arriba -> abajo
	if (f == 0 || elemento(f, c) == rep) {
		int fila = this->obtenerFila(c, 1);
		transportarPacman(fila, c, f + 1, c);
	}
	else if (this->elemento(f, c) == muro) {
		if (this->poderActivado()) {
			romperMuroT(f, c, f + 1, c);
		}
	}
	else {
		this->setFilPacman(f);
		int m = this->elemento(f, c);
		poner(f, c, pacman);
		poner(f + 1, c, cesped);
		if (m == moneda) {
			puntos += 10;
			comidos++;
			contador++;
			if (comidos == cantMonedas) {
				ShowMessage("Ganaste");
				// exit(0);
			}
		}
	}
}

//---------------------------------------------------------------------------
void Matriz_CSM::recorrerAbajo(int f, int c) { // 2 abajo -> arriba
	if (f == df + 1 || elemento(f, c) == rep) {
		int fila = this->obtenerFila(c, 2);
		transportarPacman(fila, c, f - 1, c);
	}
	else if (this->elemento(f, c) == muro) {
		if (poderActivado()) {
			romperMuroT(f, c, f - 1, c);
		}
	}
	else {
		this->setFilPacman(f);
		int m = this->elemento(f, c);
		poner(f, c, pacman);
		poner(f - 1, c, cesped);
		if (m == moneda) {
			puntos += 10;
			comidos++;
			contador++;
			if (comidos == cantMonedas) {
				ShowMessage("Ganaste");
				// exit(0);
			}
		}
	}
}
//---------------------------------------------------------------------------
void Matriz_CSM::recorrerIzquierda(int f, int c) { // 3 izquierda -> Derecha
	if (c == 0 || elemento(f, c) == rep) {
		int columna = this->obtenerColumna(f, 3);
		transportarPacman(f, columna, f, c + 1);
	}
	else if (this->elemento(f, c) == muro) {
		if (poderActivado()) {
			romperMuroT(f, c, f, c + 1);
		}
	}
	else {
		this->setColPacman(c);
		int m = this->elemento(f, c);
		poner(f, c, pacman);
		poner(f, c + 1, cesped);
		if (m == moneda) {
			puntos += 10;
			comidos++;
			contador++;
			if (comidos == cantMonedas) {
				ShowMessage("Ganaste");
				// exit(0);
			}
		}
	}
}
//---------------------------------------------------------------------------
void Matriz_CSM::recorrerDerecha(int f, int c) { // 4 Derecha -> izquierda
	if (c == dc + 1 || elemento(f, c) == rep) {
		int col = this->obtenerColumna(f, 4);
		transportarPacman(f, col, f, c - 1);
	}
	else if (this->elemento(f, c) == muro) {
		if (poderActivado()) {
			romperMuroT(f, c, f, c - 1);
		}
	}
	else {
		this->setColPacman(c);
		int m = this->elemento(f, c);
		poner(f, c, pacman);
		poner(f, c - 1, cesped);
		if (m == moneda) {
			puntos += 10;
			comidos++;
			contador++;
			if (comidos == cantMonedas) {
				ShowMessage("Ganaste");
				// exit(0);
			}
		}
	}
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void Matriz_CSM::romperMuroT(int f, int c, int antF, int antC) {
	this->setFilPacman(f);
	this->setColPacman(c);
	poner(f, c, pacman);
	poner(antF, antC, cesped);
	contador -= 2;
}
//---------------------------------------------------------------------------
void Matriz_CSM::transportarPacman(int f, int c, int antF, int antC) {
	if (elemento(f, c) != muro || poderActivado()) {
		if (elemento(f, c) == muro) {
			contador -= 2;
		}
		this->setFilPacman(f);
		this->setColPacman(c);
		poner(f, c, pacman);
		poner(antF, antC, cesped);
	}
	return;
}
//---------------------------------------------------------------------------
int Matriz_CSM::obtenerFila(int c, int direccion) {
	switch (direccion) {
        case 1: // arriba -> abajo
            for (int f2 = df; f2 >= 1; f2--) {
                if (elemento(f2, c) == cesped || elemento(f2, c) == muro) {
                    return f2;
                }
            }
            break;
        case 2: // abajo -> arriba
            for (int f = 1; f <= df; f++) {
                if (elemento(f, c) == cesped || elemento(f, c) == muro) {
                    return f;
                }
            }
            break;
        default:
            break;
    }
	return -1;
}
//---------------------------------------------------------------------------
int Matriz_CSM::obtenerColumna(int f, int direccion) {
	switch (direccion) {
		case 4: // derecha -> izquierda
			for (int c = 1; c <= dc; c++) {
				if (elemento(f, c) == cesped || elemento(f, c) == muro) {
					return c;
				}
			}
			break;
		case 3: // izquierda -> derecha
			for (int c2 = dc; c2 >= 1; c2--) {
				if (elemento(f, c2) == cesped || elemento(f, c2) == muro) {
					return c2;
				}
			}
			break;
		default:
			throw "Error";
	}
	return -1;
}
//---------------------------------------------------------------------------
bool Matriz_CSM::poderActivado() {
	return contador >= 2;
}
//---------------------------------------------------------------------------
void Matriz_CSM::cargarNivel_0() {
	this->dimensionar(9, 9);
	cargarCespedNivel_0();
	cargarMonedasNivel_0();
	cargarMurosNivel_0();
	this->setFilPacman(3);
	this->setColPacman(2);
	poner(3, 2, pacman);
	contador = 0;
	playIniciado = true;
	puntos = 0;
}
//---------------------------------------------------------------------------
void Matriz_CSM::cargarCespedNivel_0() {
	for (int i = 0; i < df; i++) {
		for (int j = 0; j < dc; j++) {
			this->poner(i + 1, j + 1, cesped);
		}
	}
}
//---------------------------------------------------------------------------
void Matriz_CSM::cargarMonedasNivel_0() {
	this->poner(3, 3, moneda);
	this->poner(3, 4, moneda);
	this->poner(4, 4, moneda);
	this->poner(4, 5, moneda);
	this->cantMonedas = 4;
}
//---------------------------------------------------------------------------
void Matriz_CSM::cargarMurosNivel_0() {
	for (int i = 0; i < df; i++){
		this->poner(i + 1, 1, muro);
		this->poner(i + 1, dc, muro);
	}
	for (int j = 2; j <= dc - 1; j++) {
		this->poner(1, j, muro);
		this->poner(df, j, muro);
	}
}
//---------------------------------------------------------------------------
#pragma package(smart_init)



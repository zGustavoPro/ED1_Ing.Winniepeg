//---------------------------------------------------------------------------

#pragma hdrstop

#include "CM_Ptr1N.h"
//---------------------------------------------------------------------------
Matriz_Ptr1N :: Matriz_Ptr1N(){
 df=0; dc=0; nt=0;
 rep=0; ptrMat=nullptr;
 //Pacman
  pacman=2;
  pacmanF=2;
  pacmanC=2;
  muro=3;
  moneda=1;
  cantMonedas=0;
  comidos=0;
  contador=0;
  rompeMuros=false;
  //Fantasmas
  fantasma1=4; //rojo
  fantasma1F=3;
  fantasma1C=14;

  fantasma2=5;       //azul
  fantasma2F=14;
  fantasma2C=5;

  fantasma3=6;    //verde
  fantasma3F=14;
  fantasma3C=8;

  fantasma4=7;    //amarillo
  fantasma4F=13;
  fantasma4C=10;
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
	 TRect area(x1+30,y1-20,x1+400,y1+500);
	 Canvas->FillRect (area);
	 //Canvas->Rectangle(0,0,1000,1000);
	 AnsiString r = "";
	 Canvas->Font->Size=12;
	for (int i = 0; i < df; i++) {
		r += "| ";
		for (int j = 0; j < dc; j++) {
			r += AnsiString(elemento(i + 1, j + 1));
			if (j < dc - 1)
				r += "  ";
		}
		r += " |";
		Canvas->TextOut(x1,y1,r);
		r=""; y1=y1+25;
	}
	//Canvas->TextOut(x1,y1,"nt : "+AnsiString(nt));
	Canvas->Font->Size=8;
}
//---------------------------------------------------------------------------
void Matriz_Ptr1N :: cargarMuros(){
this->poner(pacmanF,pacmanC,pacman);
 for(int c=1; c<=dc; c++) {//fila 1
 this->poner(1,c,muro);
 this->poner(df,c,muro);
 }
 for(int f=2; f<df; f++){ //columna 1
 this->poner(f,1,muro);
 this->poner(f,dc,muro);
 }
}
//---------------------------------------------------------------------------
void Matriz_Ptr1N :: cargarMonedas(){
 poner( 4,3,moneda);
 poner(3,5,moneda);
 poner(7,9,moneda);
 poner(9,3,moneda);
 poner(13,14,moneda);
 poner(11,7,moneda);
 this->cantMonedas=6;
}
//---------------------------------------------------------------------------
void Matriz_Ptr1N :: cargarFantasmas(){
 poner(fantasma1F,fantasma1C,fantasma1);
 poner(fantasma2F,fantasma2C,fantasma2);
 poner(fantasma3F,fantasma3C,fantasma3);
 poner(fantasma4F,fantasma4C,fantasma4);
}
//---------------------------------------------------------------------------
void Matriz_Ptr1N :: transportarPacman(int f,int c,int direccion){
 switch(direccion){
	 case 1: //arriba  pa abajo
	  if(elemento(df,c)!=muro ) {
			this->setFilPacman(df);
			 poner(df,c,pacman);
			 poner(1,c,rep);
		  //	rompeMuros=false;
		   contador=0;
		  }
		  break;
	  case 2: // abajo   pa arriba
	   if(elemento(1,c)!=muro) {
			this->setFilPacman(1);
			 poner(1,c,pacman);
			 poner(df,c,rep);
		   //	rompeMuros=false;
		   contador=0;
		  }
		  break;
	  case 3: // izquierda pa derecha
		if(elemento(f,dc)!=muro){
			this->setColPacman(dc);
			 poner(f,dc,pacman);
			 poner(f,1,rep);
		   //	rompeMuros=false;
		   contador=0;
		  }
		  break;
	  case 4: //Derecha  pa izquierda
	   if(elemento(f,1)!=muro ){
			this->setColPacman(1);
			 poner(f,1,pacman);
			 poner(f,dc,rep);
		   //	rompeMuros=false;
		   contador=0;
		  }
		  break;
	  default :
	  break;
	 }
}
//---------------------------------------------------------------------------
void Matriz_Ptr1N :: romperMuroT(int f,int c,int direccion){
	 switch(direccion){
	 case 1: //arriba
		  this->setFilPacman(f);
		  poner(f,c,pacman);
		  poner(f+1,c,rep);
		  contador=0;
		  rompeMuros=false;
		  break;
	  case 2: // abajo
		  this->setFilPacman(f);
		  poner(f,c,pacman);
		  poner(f-1,c,rep);
		  rompeMuros=false;
		  contador=0;
		  break;
	  case 3: // izquierda
		  this->setColPacman(c);
		  poner(f,c,pacman);
		  poner(f,c+1,rep);
		  contador=0;
		  rompeMuros=false;
		  break;
	  case 4: //Derecha
		  this->setColPacman(f);
		  poner(f,c,pacman);
		  poner(f,c-1,rep);
		  contador=0;
		  rompeMuros=false;
		  break;
	  default :
	  break;
	 }
 }
//---------------------------------------------------------------------------
void Matriz_Ptr1N :: recorrerArriba(int f,int c){   // 1 arriba
 if(f<1){
  transportarPacman(f,c,1);
 }
 else if(this->elemento(f,c)==muro){
   if(rompeMuros==true){
		romperMuroT(f,c,1);
   }
  } else if(esFantasma(elemento(f,c))) {
		 ShowMessage("Perdiste");
		   exit(0);
   }  else{
		this->setFilPacman(f);
		  int m=this->elemento(f,c);
		   poner(f,c,pacman);
		  poner(f+1,c,rep);
		if(m==moneda){
		  comidos++;
		  contador++;
	   if(comidos==cantMonedas) {
		 ShowMessage("Ganaste");
		 exit(0);
	   }
	   if(contador==2){
	   rompeMuros=true;
	   }
   }
  }
}
//---------------------------------------------------------------------------
void Matriz_Ptr1N :: recorrerAbajo(int f,int c){// 2 abajo
  if(f>df){
  transportarPacman(f,c,2);
 }
 else if(this->elemento(f,c)==muro){
   if(rompeMuros==true){
		romperMuroT(f,c,2);
   }
  } else if(esFantasma(elemento(f,c))){
		ShowMessage("Perdiste");
		  exit(0);
	}  else {
		 this->setFilPacman(f);
		   int m=this->elemento(f,c);
			 poner(f,c,pacman);
			   poner(f-1,c,rep);
	if(m==moneda){
		comidos++;
		contador++;
		 if(comidos==cantMonedas){
		   ShowMessage("Ganaste");
		 exit(0);
		 }
	   if(contador==2){
	   rompeMuros=true;
	   }
  }
  }
}
//---------------------------------------------------------------------------
void Matriz_Ptr1N :: recorrerIzquierda(int f,int c){// 3 izquierda
  if(c<1){
  transportarPacman(f,c,3);
 }
 else if(this->elemento(f,c)==muro){
   if(rompeMuros==true)
		romperMuroT(f,c,3);
  }else if(esFantasma(elemento(f,c))){
	  ShowMessage("Perdiste");
	   exit(0);
   } else {
	   this->setColPacman(c);
		int m=this->elemento(f,c);
	   poner(f,c,pacman);
	 poner(f,c+1,rep);
   if(m==moneda){
		comidos++;
		contador++;
	   if(comidos==cantMonedas){
		   ShowMessage("Ganaste");
	   exit(0);
	   }
	   if(contador==2){
	   rompeMuros=true;
	   }
  }
  }
}
//---------------------------------------------------------------------------
void Matriz_Ptr1N :: recorrerDerecha(int f,int c){   // 4 Derecha
 if(c>dc){
  transportarPacman(f,c,4);
 }
 else if(this->elemento(f,c)==muro){
   if(rompeMuros==true)
		romperMuroT(f,c,4);

  } else if(esFantasma(elemento(f,c))){
	 ShowMessage("Perdiste");
	 exit(0);
  }else{
  this->setColPacman(c);
   int m=this->elemento(f,c);
  poner(f,c,pacman);
  poner(f,c-1,rep);
  if(m==moneda){
		comidos++;
		contador++;
		 if(comidos==cantMonedas) {
		   ShowMessage("Ganaste");
		 exit(0);
		 }
	   if(contador==2){
	   rompeMuros=true;
	   }
  }
  }
}
//---------------------------------------------------------------------------
void Matriz_Ptr1N :: setColPacman(int c){
  pacmanC=c;
}
//---------------------------------------------------------------------------
void Matriz_Ptr1N :: setFilPacman(int f){
pacmanF=f;
}
//---------------------------------------------------------------------------
int Matriz_Ptr1N :: getFilPacman(){
return pacmanF;
}
//---------------------------------------------------------------------------
int Matriz_Ptr1N :: getColPacman(){
return pacmanC;
}
//---------------------------------------------------------------------------
int Matriz_Ptr1N :: numeroRandom(){
 srand(time(0));
 return rand()%4+1;
}
//---------------------------------------------------------------------------
 bool Matriz_Ptr1N :: esFantasma(int x){
   if(x==fantasma1 || x==fantasma2 ||
	x==fantasma3 || x==fantasma4)
	return true; else
	return false;
 }
//---------------------------------------------------------------------------
void Matriz_Ptr1N :: moverFantasmas(int x){
  int r=numeroRandom();
  switch(r) {
  case 1:          //arriba
  if(x == fantasma1)
   this->recorrerFantasmaArriba(getFilFantasma1()-1,getColFantasma1(),x);
  else if(x == fantasma2)
   this->recorrerFantasmaArriba(getFilFantasma2()-1,getColFantasma2(),x);
  else if(x == fantasma3)
   this->recorrerFantasmaArriba(getFilFantasma3()-1,getColFantasma3(),x);
  else if(x == fantasma4)
   this->recorrerFantasmaArriba(getFilFantasma4()-1,getColFantasma4(),x);
  else break;

  case 2 :        //abajo
   if(x == fantasma1)
   this->recorrerFantasmaAbajo(getFilFantasma1()+1,getColFantasma1(),x);
  else if(x == fantasma2)
   this->recorrerFantasmaAbajo(getFilFantasma2()+1,getColFantasma2(),x);
  else if(x == fantasma3)
   this->recorrerFantasmaAbajo(getFilFantasma3()+1,getColFantasma3(),x);
  else if(x == fantasma4)
   this->recorrerFantasmaAbajo(getFilFantasma4()+1,getColFantasma4(),x);
  else break;

  case 3:         //Derecha
   if(x == fantasma1)
   this->recorrerFantasmaDerecha(getFilFantasma1(),getColFantasma1()+1,x);
  else if(x == fantasma2)
   this->recorrerFantasmaDerecha(getFilFantasma2(),getColFantasma2()+1,x);
  else if(x == fantasma3)
   this->recorrerFantasmaDerecha(getFilFantasma3(),getColFantasma3()+1,x);
  else if(x == fantasma4)
   this->recorrerFantasmaDerecha(getFilFantasma4(),getColFantasma4()+1,x);
  else break;

  case 4:        //izquierda
   if(x == fantasma1)
   this->recorrerFantasmaIzquierda(getFilFantasma1(),getColFantasma1()-1,x);
  else if(x == fantasma2)
   this->recorrerFantasmaIzquierda(getFilFantasma2(),getColFantasma2()-1,x);
  else if(x == fantasma3)
   this->recorrerFantasmaIzquierda(getFilFantasma3(),getColFantasma3()-1,x);
  else if(x == fantasma4)
   this->recorrerFantasmaIzquierda(getFilFantasma4(),getColFantasma4()-1,x);
  else break;
  default :
  break;
  }
}
//---------------------------------------------------------------------------
void Matriz_Ptr1N :: activarFantasmas(){
this->moverFantasmas(fantasma1);
this->moverFantasmas(fantasma2);
this->moverFantasmas(fantasma3);
this->moverFantasmas(fantasma4);
}
//---------------------------------------------------------------------------
 void Matriz_Ptr1N :: recorrerFantasmaArriba(int f, int c, int fantasma){
  int ele = elemento(f,c);
  if (ele == muro) {
	return;
  } else if (ele == pacman) {
	ShowMessage("Perdiste");
	exit(0);
  } else {
	if (fantasma == fantasma1) {
	  if ((ele == moneda) && (elemento(f-1,c)!=muro) && (f-1>1) && (!esFantasma(elemento(f-1,c)))){
			  this->setFilFantasma1(f - 1);
			  poner(f-1, c, fantasma1);
			  poner(f + 1, c, rep);
	  } else if (esFantasma(ele)) {
		return;
	  } else {
		this->setFilFantasma1(f);
		poner(f, c, fantasma1);
		poner(f + 1, c, rep);
	  }
	} else if (fantasma == fantasma2) {
	  if ((ele == moneda) && (elemento(f-1,c)!=muro) && (f-1>1) && (!esFantasma(elemento(f-1,c)))){
			  this->setFilFantasma2(f - 1);
			  poner(f-1, c, fantasma2);
			  poner(f + 1, c, rep);
	  } else if (esFantasma(ele)) {
		return;
	  } else {
		this->setFilFantasma2(f);
		poner(f, c, fantasma2);
		poner(f + 1, c, rep);
	  }
	} else if (fantasma == fantasma3) {
       if ((ele == moneda) && (elemento(f-1,c)!=muro) && (f-1>1) && (!esFantasma(elemento(f-1,c)))){
			  this->setFilFantasma3(f - 1);
			  poner(f-1, c, fantasma3);
			  poner(f + 1, c, rep);
	  } else if (esFantasma(ele)) {
		return;
	  } else {
		this->setFilFantasma3(f);
		poner(f, c, fantasma3);
		poner(f + 1, c, rep);
	  }
	} else if (fantasma == fantasma4) {
	  if ((ele == moneda) && (elemento(f-1,c)!=muro) && (f-1>1) && (!esFantasma(elemento(f-1,c)))){
			  this->setFilFantasma4(f - 1);
			  poner(f-1, c, fantasma4);
			  poner(f + 1, c, rep);
	  } else if (esFantasma(ele)) {
		return;
	  } else {
		this->setFilFantasma4(f);
		poner(f, c, fantasma4);
		poner(f + 1, c, rep);
	  }
	}
  }
}

//---------------------------------------------------------------------------
 void Matriz_Ptr1N :: recorrerFantasmaAbajo(int f, int c, int fantasma){
  int ele = elemento(f, c);
  if (ele == muro) {
	return;
  } else if (ele == pacman) {
	ShowMessage("Perdiste");
	exit(0);
  } else {
	if (fantasma == fantasma1) {
	  if ((ele == moneda) && (elemento(f+1,c)!=muro) && (f+1<df) && (!esFantasma(elemento(f+1,c)))){
		this->setFilFantasma1(f + 1);
		poner(f + 1, c, fantasma1);
		poner(f - 1, c, rep);
	  } else if (esFantasma(ele)) {
			return;
	  } else {
		this->setFilFantasma1(f);
		poner(f, c, fantasma1);
		poner(f - 1, c, rep);
	  }
	} else if (fantasma == fantasma2) {
	 if ((ele == moneda) && (elemento(f+1,c)!=muro) && (f+1<df) && (!esFantasma(elemento(f+1,c)))){
		this->setFilFantasma2(f + 1);
		poner(f + 1, c, fantasma2);
		poner(f - 1, c, rep);
	  } else if (esFantasma(ele)) {
		return;
	  } else {
		this->setFilFantasma2(f);
		poner(f, c, fantasma2);
		poner(f - 1, c, rep);
	  }
	} else if (fantasma == fantasma3) {
	  if ((ele == moneda) && (elemento(f+1,c)!=muro) && (f+1<df) && (!esFantasma(elemento(f+1,c)))){
		this->setFilFantasma3(f + 1);
		poner(f + 1, c, fantasma3);
		poner(f - 1, c, rep);
	  } else if (esFantasma(ele)) {
		return;
	  } else {
		this->setFilFantasma3(f);
		poner(f, c, fantasma3);
		poner(f - 1, c, rep);
	  }
	} else if (fantasma == fantasma4) {
	  if ((ele == moneda) && (elemento(f+1,c)!=muro) && (f+1<df) && (!esFantasma(elemento(f+1,c)))){
		this->setFilFantasma4(f + 1);
		poner(f + 1, c, fantasma4);
		poner(f - 1, c, rep);
	  } else if (esFantasma(ele)) {
		return;
	  } else {
		this->setFilFantasma4(f);
		poner(f, c, fantasma4);
		poner(f - 1, c, rep);
	  }
	}
  }
}

//---------------------------------------------------------------------------
 void Matriz_Ptr1N :: recorrerFantasmaDerecha(int f, int c, int fantasma){
  int ele = elemento(f, c);
  if (ele == muro) {
	return;
  } else if (ele == pacman) {
	ShowMessage("Perdiste");
	exit(0);
  } else {
	if (fantasma == fantasma1) {
		if ((ele == moneda) && (elemento(f,c+1)!=muro) && (c+1<dc) && (!esFantasma(elemento(f,c+1)))){
		 this->setColFantasma1(c + 1);
		  poner(f, c + 1, fantasma1);
		poner(f, c - 1, rep);
	  } else if (esFantasma(ele)) {
		return;
	  } else {
		this->setColFantasma1(c);
		  poner(f, c, fantasma1);
		poner(f, c - 1, rep);
	  }
	} else if (fantasma == fantasma2) {
	   if ((ele == moneda) && (elemento(f,c+1)!=muro) && (c+1<dc) && (!esFantasma(elemento(f,c+1)))){
		this->setColFantasma2(c + 1);
		 poner(f, c + 1, fantasma2);
		poner(f, c - 1, rep);
	  } else if (esFantasma(ele)) {
		return;
	  } else {
		this->setColFantasma2(c);
		poner(f, c, fantasma2);
		poner(f, c - 1, rep);
	  }
	} else if (fantasma == fantasma3) {
	   if ((ele == moneda) && (elemento(f,c+1)!=muro) && (c+1<dc) && (!esFantasma(elemento(f,c+1)))){
		this->setColFantasma3(c + 1);
		poner(f, c + 1, fantasma3);
		poner(f, c - 1, rep);
	  } else if (esFantasma(ele)) {
		return;
	  } else {
		this->setColFantasma3(c);
		poner(f, c, fantasma3);
		poner(f, c - 1, rep);
	  }
	} else if (fantasma == fantasma4) {
	   if ((ele == moneda) && (elemento(f,c+1)!=muro) && (c+1<dc) && (!esFantasma(elemento(f,c+1)))){
		this->setColFantasma4(c + 1);
		poner(f, c + 1, fantasma4);
		poner(f, c - 1, rep);
	  } else if (esFantasma(ele)) {
		return;
	  } else {
		this->setColFantasma4(c);
		poner(f, c, fantasma4);
		poner(f, c - 1, rep);
	  }
	}
  }
}

//---------------------------------------------------------------------------
 void Matriz_Ptr1N :: recorrerFantasmaIzquierda(int f, int c, int fantasma){
  int ele = elemento(f, c);
  if (ele == muro) {
	return;
  } else if (ele == pacman) {
	ShowMessage("Perdiste");
	exit(0);
  } else {
	if (fantasma == fantasma1) {
	   if ((ele == moneda) && (elemento(f,c-1)!=muro) && (c-1>1) && (!esFantasma(elemento(f,c-1)))){
		this->setColFantasma1(c - 1);
		poner(f, c - 1, fantasma1);
		poner(f, c + 1, rep);
	  } else if (esFantasma(ele)) {
		return;
	  } else {
		this->setColFantasma1(c);
		poner(f, c, fantasma1);
		poner(f, c + 1, rep);
	  }
	} else if (fantasma == fantasma2) {
	   if ((ele == moneda) && (elemento(f,c-1)!=muro) && (c-1>1) && (!esFantasma(elemento(f,c-1)))){
		this->setColFantasma2(c - 1);
		poner(f, c - 1, fantasma2);
		poner(f, c + 1, rep);
	  } else if (esFantasma(ele)) {
		return;
	  } else {
		this->setColFantasma2(c);
		poner(f, c, fantasma2);
		poner(f, c + 1, rep);
	  }
	} else if (fantasma == fantasma3) {
	   if ((ele == moneda) && (elemento(f,c-1)!=muro) && (c-1>1) && (!esFantasma(elemento(f,c-1)))){
		this->setColFantasma3(c - 1);
		poner(f, c - 1, fantasma3);
		poner(f, c + 1, rep);
	  } else if (esFantasma(ele)) {
		return;
	  } else {
		this->setColFantasma3(c);
		poner(f, c, fantasma3);
		poner(f, c + 1, rep);
	  }
	} else if (fantasma == fantasma4) {
	   if ((ele == moneda) && (elemento(f,c-1)!=muro) && (c-1>1) && (!esFantasma(elemento(f,c-1)))){
		this->setColFantasma4(c - 1);
		poner(f, c - 1, fantasma4);
		poner(f, c + 1, rep);
	  } else if (esFantasma(ele)) {
		return;
	  } else {
		this->setColFantasma4(c);
		poner(f, c, fantasma4);
		poner(f, c + 1, rep);
	  }
	}
  }
}

//---------------------------------------------------------------------------
void Matriz_Ptr1N :: setColFantasma1(int c){
  fantasma1C=c;
}
//---------------------------------------------------------------------------
void Matriz_Ptr1N :: setFilFantasma1(int f){
fantasma1F=f;
}
//---------------------------------------------------------------------------
int Matriz_Ptr1N :: getFilFantasma1(){
return fantasma1F;
}
//---------------------------------------------------------------------------
int Matriz_Ptr1N :: getColFantasma1(){
return fantasma1C;
}


//---------------------------------------------------------------------------
void Matriz_Ptr1N :: setColFantasma2(int c){
  fantasma2C=c;
}
//---------------------------------------------------------------------------
void Matriz_Ptr1N :: setFilFantasma2(int f){
fantasma2F=f;
}
//---------------------------------------------------------------------------
int Matriz_Ptr1N :: getFilFantasma2(){
return fantasma2F;
}
//---------------------------------------------------------------------------
int Matriz_Ptr1N :: getColFantasma2(){
return fantasma2C;
}


//---------------------------------------------------------------------------
void Matriz_Ptr1N :: setColFantasma3(int c){
  fantasma3C=c;
}
//---------------------------------------------------------------------------
void Matriz_Ptr1N :: setFilFantasma3(int f){
fantasma3F=f;
}
//---------------------------------------------------------------------------
int Matriz_Ptr1N :: getFilFantasma3(){
return fantasma3F;
}
//---------------------------------------------------------------------------
int Matriz_Ptr1N :: getColFantasma3(){
return fantasma3C;
}


//---------------------------------------------------------------------------
void Matriz_Ptr1N :: setColFantasma4(int c){
  fantasma4C=c;
}
//---------------------------------------------------------------------------
void Matriz_Ptr1N :: setFilFantasma4(int f){
fantasma4F=f;
}
//---------------------------------------------------------------------------
int Matriz_Ptr1N :: getFilFantasma4(){
return fantasma4F;
}
//---------------------------------------------------------------------------
int Matriz_Ptr1N :: getColFantasma4(){
return fantasma4C;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)


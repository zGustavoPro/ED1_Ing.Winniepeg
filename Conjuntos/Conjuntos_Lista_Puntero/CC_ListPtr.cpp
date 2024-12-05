//---------------------------------------------------------------------------

#pragma hdrstop

#include "CC_ListPtr.h"
//---------------------------------------------------------------------------
	CC_ListPtr :: CC_ListPtr (){
		 lista=new PtrLista();
	}
//---------------------------------------------------------------------------
	bool CC_ListPtr :: Vacio(){
	 return lista->Vacio();
	}
//---------------------------------------------------------------------------
	bool CC_ListPtr :: Pertenece(int e){
	   NodoL* existe = lista->Localiza(e);
	if (existe == nullptr)
		return false;
	else
		return true;
}
//---------------------------------------------------------------------------
	void CC_ListPtr :: Inserta(int e){
	  if (!Pertenece(e)) {
		lista->Inserta(lista->Primero(), e);
	}
	}
//---------------------------------------------------------------------------
	int CC_ListPtr :: cardinal(){
		 return lista->Longitud();
	}
//---------------------------------------------------------------------------
	int CC_ListPtr :: Ordinal(int e){
		int c = 0;
	Direccion aux = lista->Primero();
	while (aux != nullptr) {
		c++; // empieza en 1
		if (lista->Recupera(aux) == e) {
			return c;
		}
		aux = lista->Siguiente(aux);
	}
	return -1;
	}
//---------------------------------------------------------------------------
	void CC_ListPtr :: Suprime(int e){
		   if (Pertenece(e)) {
		Direccion nodo = lista->Localiza(e);
		lista->Suprime(nodo);
	}
	}
//---------------------------------------------------------------------------
	int CC_ListPtr :: Muestrea(){
		 if (!Vacio()) {
		srand(time(NULL));
		int pos = rand() % cardinal();
		return elemento(pos);
	}
	else
		return 0;
	}
//---------------------------------------------------------------------------

	int CC_ListPtr :: elemento(int pos){
	   int c = 0;
	Direccion aux = lista->Primero();
	while (aux != nullptr) {
		if (c == pos) {
			return lista->Recupera(aux);
		}
		c++;
		aux = lista->Siguiente(aux);
	}
	return 0;
	}
//---------------------------------------------------------------------------
	void CC_ListPtr :: reiniciar(){
		  while (Vacio() == false) {
		int r = Muestrea();
		Suprime(r);
	}
	}
//---------------------------------------------------------------------------

  bool CC_ListPtr :: Equivalencia(CC_ListPtr *a,CC_ListPtr *b){
	   return a->cardinal()==b->cardinal();
	}
//---------------------------------------------------------------------------
  void CC_ListPtr :: Interseccion (CC_ListPtr *b,CC_ListPtr *c){
		c->reiniciar();
	CC_ListPtr *aux = new CC_ListPtr();
	// Inserto si el elemento pertenece a A y a B
	while (this->Vacio() == false) {
		int r = this->Muestrea();
		if (this->Pertenece(r) && b->Pertenece(r)) {
			c->Inserta(r);
		}
		this->Suprime(r);
		aux->Inserta(r);
	}
	// Recupero los elementos de a
	while (aux->Vacio() == false) {
		int r = aux->Muestrea();
		aux->Suprime(r);
		this->Inserta(r);
	}
	}
//---------------------------------------------------------------------------
  void CC_ListPtr :: Union(CC_ListPtr *b,CC_ListPtr *c){
	 c->reiniciar();
	CC_ListPtr *aux = new CC_ListPtr();

	// Para insertar a en c
	while (this->Vacio() == false) {
		int r = this->Muestrea();
		c->Inserta(r);
		this->Suprime(r);
		aux->Inserta(r);
	}
	// Para recuperar los datos de a
	while (aux->Vacio() == false) {
		int r = aux->Muestrea();
		aux->Suprime(r);
		this->Inserta(r);
	}
	// Para insertar b en c
	while (b->Vacio() == false) {
		int r = b->Muestrea();
		c->Inserta(r);
		b->Suprime(r);
		aux->Inserta(r);
	}
	// Para recuperar los datos de b
	while (aux->Vacio() == false) {
		int r = aux->Muestrea();
		aux->Suprime(r);
		b->Inserta(r);
	}
	}
//---------------------------------------------------------------------------
  void CC_ListPtr :: Mostrar_Conjuntos(AnsiString cad,int x1,int y1,TCanvas *Canvas){
	   TRect area(x1,y1,x1+200,y1+25);
		  Canvas->Brush->Color=clBtnFace;
		  Canvas->FillRect(area);

		  AnsiString aux = "  ";
		  Direccion Dir=lista->Primero();
	 for (int i=1; i <=cardinal(); i++) {
		 if (Dir != nullptr) {
		  aux=aux+IntToStr(lista->Recupera(Dir))+",";
		 }
		 Dir=lista->Siguiente(Dir);
	 }
	 aux=aux.Delete(aux.Length(),1);
	 aux="Conjunto : "+cad+"  { "+ aux +"  } ";
	 Canvas->TextOut(x1,y1,aux);
	}
//---------------------------------------------------------------------------

  #pragma package(smart_init)  //end.

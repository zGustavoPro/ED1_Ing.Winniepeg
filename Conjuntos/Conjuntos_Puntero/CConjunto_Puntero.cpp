//---------------------------------------------------------------------------

#pragma hdrstop
 #include <vcl.h>
#include "CConjunto_Puntero.h"
//---------------------------------------------------------------------------

  CC_Puntero :: CC_Puntero () {
   cant=0;
   ptr_conj=nullptr;
  }

	bool CC_Puntero :: Vacio() {
	  return cant==0;
  }
	bool CC_Puntero :: Pertenece(int e) {
	 bool resp=false;
	 Direccion pc=ptr_conj;
	 while(pc != nullptr) {
		 if (pc->dato==e) {
		 resp=true;
		 pc=nullptr;
		 }else pc=pc->sig;
	 }
	 return resp;
  }
	void CC_Puntero :: Inserta(int e) {
	   if (!Pertenece(e)) {
		   Direccion dir=new Nodo();
		   if (dir !=nullptr) {
			   dir->dato=e;
			   dir->sig=ptr_conj;
			   ptr_conj=dir;
			   cant++;
		   } else ShowMessage("No Existe Espacio en la Memoria");
	   }else ShowMessage("Elemento ya Existe");
  }
	int CC_Puntero :: cardinal() {
	  return cant;
  }
	int CC_Puntero :: Ordinal(int e) { //devuelve posicion del elemento
	   int resp=0;
	   Direccion pc=ptr_conj;
	   while (pc != nullptr){
		resp++;
		if (pc->dato==e) {
		return resp;
		pc=nullptr;
		}else pc=pc->sig;
	   }
	   return resp;
  }
	void CC_Puntero :: Suprime(int e) {
	  Direccion p=localiza(e);
	  if (cant==0)
		  return;
	  else  if (p == ptr_conj) {
				Direccion x=ptr_conj;
				ptr_conj=ptr_conj->sig;
				delete(x);
			} else  {
			Direccion ant=anterior(p);
			ant->sig=p->sig;
			delete(p);
			}
			cant--;
  }

	int CC_Puntero :: Muestrea() {
	   if (!Vacio()) {
  return obt_elem(numero_Aleatorio());
 } else return 0;
  }

	Direccion CC_Puntero :: anterior(Direccion e) {

	 if (!Vacio()) {
	if (e==ptr_conj) {
		 throw "No hay Anterior";
	}else{
	 Direccion dir=ptr_conj;
	 Direccion ant=nullptr;
	   while ( dir != nullptr){
		  if (dir==e) {
				  return ant;
		  }
		  ant=dir;
		  dir=dir->sig;
	   }
	  } throw "Elemento no Encontrado";
	}else throw "lista Vacia";
  }
		Direccion CC_Puntero :: localiza(int e) {
				 Direccion dir=ptr_conj;
				 while (dir != nullptr){
				  if (dir->dato==e) {
					  return dir;
				  } else dir=dir->sig;
				 }
				 return nullptr;
  }
	int CC_Puntero :: obt_elem(int pos) {      //envia posicion
		int c=0;
	Direccion x=ptr_conj;
	  while (x != nullptr){
		if (c==pos) {
		  return x->dato;
		   } else {
		  c++;
		   x=x->sig;
		  }
	  }
	return 0;
  }
	int CC_Puntero :: numero_Aleatorio() {
	 srand (time(NULL));
	 return rand()%(cant);
  }
	void CC_Puntero :: reiniciar() {
	  while(!Vacio()) {
	Suprime(Muestrea());
  }
  }

  bool CC_Puntero :: Equvalencia(CC_Puntero *a,CC_Puntero *b) {
	  return a->cardinal()==b->cardinal();
  }
  void CC_Puntero :: Interseccion (CC_Puntero *b,CC_Puntero *c) {
		 c->reiniciar();
	  CC_Puntero *aux=new CC_Puntero();

	 while (!this->Vacio()){
	 int e=this->Muestrea();
	 if (this->Pertenece(e) && b->Pertenece(e)) {
	 c->Inserta(e);
	 }
	 this->Suprime(e);
	 aux->Inserta(e);
   }
   //	recuperando
	while (!aux->Vacio()){
	 int e=aux->Muestrea();
	 aux->Suprime(e);
	 this->Inserta(e);
   }
  }
  void CC_Puntero :: Union(CC_Puntero *b,CC_Puntero *c) {
	   c->reiniciar();
   CC_Puntero *aux=new CC_Puntero();

	 while (!this->Vacio()){
	 int e=this->Muestrea();
	 c->Inserta(e);
	 this->Suprime(e);
	 aux->Inserta(e);
   }
  //recuperando
	while (!aux->Vacio()){
	 int e=aux->Muestrea();
	 aux->Suprime(e);
	 this->Inserta(e);
   }

   while (!b->Vacio()){
	 int e=b->Muestrea();
	 c->Inserta(e);
	 b->Suprime(e);
	 aux->Inserta(e);
   }
  // REcuperando
	while (!aux->Vacio()){
	 int e=aux->Muestrea();
	 aux->Suprime(e);
	 b->Inserta(e);
   }
  }
  void CC_Puntero :: Mostrar_Conjuntos(AnsiString cad,int x1, int y1,TCanvas *Canvas) {

		  TRect area(x1,y1,x1+200,y1+25);
		  Canvas->Brush->Color=clBtnFace;
		  Canvas->FillRect(area);

	      AnsiString aux = "  ";
		  Direccion Dir=ptr_conj;
	 for (int i=1; i <=cardinal(); i++) {
		 if (Dir != nullptr) {
		  aux=aux+IntToStr(Dir->dato)+",";
		 }
		 Dir=Dir->sig;
	 }
	 aux=aux.Delete(aux.Length(),1);
	 aux="Conjunto : "+cad+"  { "+ aux +"  } ";
	 Canvas->TextOut(x1,y1,aux);
  }


#pragma package(smart_init)

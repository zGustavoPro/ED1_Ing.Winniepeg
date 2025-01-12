//---------------------------------------------------------------------------

#pragma hdrstop

#include "CC_Lista.h"
//---------------------------------------------------------------------------
	 CC_Lista :: CC_Lista(CSMemoria *m){
	  //elem=new Lista(m);
	 }

	   CC_Lista :: CC_Lista(){
		 elem = new VecLista();
	   //elem= new Lista();
	  }
  //---------------------------------------------------------------------------

	  bool CC_Lista :: Vacio(){
	  return elem->Vacio();
	  }
   //---------------------------------------------------------------------------
	   bool CC_Lista :: Pertenece(int e){
		   int existe = elem->localiza(e);
	if (existe == -1)
		return false;
	else
		return true;
	   }
  //---------------------------------------------------------------------------
	   void CC_Lista :: Inserta(int e){
	   if (!Pertenece(e)) {
		   elem->Inserta(elem->Primero(),e);
	   }
	  }
  //---------------------------------------------------------------------------
	int CC_Lista :: cardinal(){
	return elem->Longitud();
	  }
 //---------------------------------------------------------------------------
	int CC_Lista :: Ordinal(int e){
		   int c = 0;
	int aux = elem->Primero();
	while (aux != -1) {
		c++; // empieza en 1
		if (elem->Recupera(aux) == e) {
			return c;
		}
		aux = elem->Siguiente(aux);
	}
	return -1;
	  }
   //---------------------------------------------------------------------------
	void CC_Lista :: Suprime(int e){
   if (Pertenece(e)) {
		int nodo = elem->localiza(e);
		elem->Suprime(nodo);
	}
	  }
   //---------------------------------------------------------------------------
	  int CC_Lista :: elemento(int pos){
	  int c = 0;
	int aux = elem->Primero();
	while (aux != -1) {
		if (c == pos) {
			return elem->Recupera(aux);
		}
		c++;
		aux = elem->Siguiente(aux);
	}
	return 0;
	  }
   //---------------------------------------------------------------------------
	int CC_Lista :: Muestrea(){
		if (!Vacio()) {
		srand(time(NULL));
		int pos = rand() % cardinal();
		return elemento(pos);
	}
	else
		return 0;
	  }
   //---------------------------------------------------------------------------
	 bool CC_Lista :: Equvalencia(CC_Lista *a,CC_Lista *b){
		return a->cardinal()==b->cardinal();
	  }
   //---------------------------------------------------------------------------
	  void CC_Lista :: reiniciar(){
	  while (!Vacio()){
		  Suprime(Muestrea());
		  }
	  }
   //---------------------------------------------------------------------------
	  void CC_Lista :: Interseccion (CC_Lista *b,CC_Lista *c){
		   c->reiniciar();
		 CC_Lista *aux=new CC_Lista();

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
  //---------------------------------------------------------------------------
  void CC_Lista :: Union(CC_Lista *b,CC_Lista *c){
   c->reiniciar();
   CC_Lista *aux=new CC_Lista();

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
   //---------------------------------------------------------------------------
	 void CC_Lista :: Mostrar_Conjuntos(AnsiString cad,int x1,int y1,TCanvas *Canvas){
			AnsiString aux = "  ";
		  int Dir=elem->Primero();
	 for (int i=1; i <=cardinal(); i++) {
		 if (Dir != -1) { //con lista
		  aux=aux+IntToStr(elem->Recupera(Dir))+",";
		 }
		 Dir=elem->Siguiente(Dir);
	 }
	 aux=aux.Delete(aux.Length(),1);
	 aux="Conjunto : "+cad+"  { "+ aux +"  } ";
	 Canvas->TextOut(x1,y1,aux);

	  }


#pragma package(smart_init)

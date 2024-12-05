//---------------------------------------------------------------------------

#pragma hdrstop
 #include <stdlib.h>
 #include <time.h>
#include "CC_Vector.h"
//---------------------------------------------------------------------------
	CC_Vector :: CC_Vector() {
	   cant=0;
	   for (int i=1; i <= max; i++) {
		   x[i]=0;
	   }
	}
//---------------------------------------------------------------------------
	bool CC_Vector :: Vacio(){
	   return cant==0;
	}
//---------------------------------------------------------------------------
	bool CC_Vector :: Pertenece(int e){
		for (int i=1; i <=cant; i++) {
			   if (x[i]==e) {
						  return true;
			   }
		}
		return false;
	}
//---------------------------------------------------------------------------
	void CC_Vector :: Inserta(int e){
		  if (!Pertenece(e)) {
		   cant++;
		   x[cant]=e;
		  }
	}
//---------------------------------------------------------------------------
	int CC_Vector :: cardinal(){
		  return cant;
	}
//---------------------------------------------------------------------------
	int CC_Vector :: Ordinal(int e){
		int resp=0;
		for (int i=1; i <=max; i++) {
			if (x[i] !=0) {
					resp++;
				   if (x[i]==e) {
					 return resp;
			       }
			}
		}
		return resp;
	}
 //---------------------------------------------------------------------------
	void CC_Vector :: Suprime(int e){
	   for (int i=1; i <=cant; i++) {
		   if (x[i]==e) {
					  for (int j=i; j<=cant; j++) {
						  x[j]=x[j+1];
					  }
					  cant--;
					  return;
		   }
	   }
	}
  //---------------------------------------------------------------------------
	int CC_Vector :: Muestrea(){
	   if (cant>0) {
		srand(time(0));
		return x[rand()%cant+1];
					}else return 0;
	}
//---------------------------------------------------------------------------
	void CC_Vector :: reiniciar(){
		cant=0;
		for(int i=1; i<=max; i++){
		x[i]=0;
		}
	}
 //---------------------------------------------------------------------------
  bool CC_Vector :: Equvalencia(CC_Vector *a,CC_Vector *b){
	   return a->cant==b->cant;
	}
 //---------------------------------------------------------------------------
  void CC_Vector :: Interseccion (CC_Vector *b,CC_Vector *c){
        c->reiniciar();
	  CC_Vector *aux=new CC_Vector();

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
  void CC_Vector :: Union(CC_Vector *b,CC_Vector *c){
		 c->reiniciar();
   CC_Vector *aux=new CC_Vector();

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
  void CC_Vector :: Mostrar_Conjuntos(AnsiString cad,int x1,int y1,TCanvas *Canvas){
		AnsiString aux = "  ";
	 for (int i=1; i <=cant; i++) {
		  aux=aux+IntToStr(x[i])+",";
	 }
	 aux=aux.Delete(aux.Length(),1);
	 aux="Conjunto : "+cad+"  { "+ aux +"  } ";
	 Canvas->TextOut(x1,y1,aux);
	}
 //---------------------------------------------------------------------------
#pragma package(smart_init)

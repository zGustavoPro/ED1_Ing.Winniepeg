//---------------------------------------------------------------------------

#pragma hdrstop
 #include "CConj_CSM.h"
//---------------------------------------------------------------------------

Conjunto_CSM :: Conjunto_CSM(){
m=new CSMemoria();
 cant=0;
 ptr_conj=-1;
}
Conjunto_CSM :: Conjunto_CSM(CSMemoria *men) {
m=men;
cant=0;
ptr_conj=-1;
}
//---------------------------------------------------------------------------
bool Conjunto_CSM :: Vacio() {
	return  cant==0;
}
//---------------------------------------------------------------------------
bool Conjunto_CSM :: Pertenece(int e){
Direccion pc=ptr_conj;
while (pc != -1)
 {
 if (m->Obtener_Dato(pc,"->dato")== e) {
 return true;
 }
 pc=m->Obtener_Dato(pc,"->sgt");
 }
 return false;
}
//---------------------------------------------------------------------------
void Conjunto_CSM :: Inserta(int e){
if (!Pertenece(e)) {
   Direccion Dir=m->new_espacio("dato,sgt");
if (Dir!= -1) {
   m->Poner_dato(Dir,"->dato",e);
   m->Poner_dato(Dir,"->sgt",ptr_conj);
   ptr_conj=Dir;
   cant++;
}else ShowMessage("No hay Espacio en la Memoria");
}else ShowMessage("El Elemento ya Existe");
}
//---------------------------------------------------------------------------
int Conjunto_CSM :: Ordinal(int e){  //devuelve posicion
int resp = 0;
Direccion pc = ptr_conj;
while (pc != -1) {
	resp++;
	if (m->Obtener_Dato(pc,"->dato")== e) {
   return resp;                            }
	pc=m->Obtener_Dato(pc,"->sgt");
}
return -1;
}
//---------------------------------------------------------------------------
int Conjunto_CSM :: cardinal(){
return cant;
}
//---------------------------------------------------------------------------
void Conjunto_CSM :: Suprime(int e){
  Direccion p=localiza(e);
  if (cant==0) {
	  return;
  } else if (p==ptr_conj) {
			 int x=ptr_conj;
			ptr_conj=m->Obtener_Dato(ptr_conj,"->sgt");
			m->Delete_espacio(x);
			 }
		 else {
			 Direccion ant=anterior(p);
			 int x=m->Obtener_Dato(p,"->sgt");
			 m->Poner_dato(ant,"->sgt",x);
			 m->Delete_espacio(p);
		 }
		 cant--;

}
//---------------------------------------------------------------------------
int Conjunto_CSM :: Muestrea(){
	   if (!Vacio()) {
		srand(time(NULL));
		int pos = (rand() % cant);
		return obt_elem(pos);
	}
	else
		return 0;
}
//---------------------------------------------------------------------------
 void Conjunto_CSM :: Interseccion (Conjunto_CSM *b,Conjunto_CSM *c){
	 c->reiniciar();
   Conjunto_CSM *aux=new Conjunto_CSM();

	 while (!this->Vacio()){
	 int e=this->Muestrea();
	 if (this->Pertenece(e) && b->Pertenece(e)) {
	 c->Inserta(e);
	 }
	 this->Suprime(e);
	 aux->Inserta(e);
   }
	//recuperando
	while (!aux->Vacio()){
	 int e=aux->Muestrea();
	 aux->Suprime(e);
	 this->Inserta(e);
   }

   }

 //---------------------------------------------------------------------------
 void Conjunto_CSM :: Union(Conjunto_CSM *b,Conjunto_CSM *c){
   c->reiniciar();
   Conjunto_CSM *aux=new Conjunto_CSM();

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
  bool Equivalencia(Conjunto_CSM *a,Conjunto_CSM *b){
  return a->cardinal()==b->cardinal();
  }
  //---------------------------------------------------------------------------
  void Conjunto_CSM :: Mostrar_Memoria(int x1,int y1,TCanvas *Canvas){
  m->Mostrar(x1,y1,Canvas);
  }
	//---------------------------------------------------------------------------
 void Conjunto_CSM :: Mostrar_Conjuntos(AnsiString cad,int x1,int y1,TCanvas *Canvas){
		  TRect area(x1,y1,x1+200,y1+25);
		  Canvas->Brush->Color=clBtnFace;
		  Canvas->FillRect(area);

		  AnsiString aux = "  ";
		  Direccion Dir=ptr_conj;
	 for (int i=1; i <=cardinal(); i++) {

		 if (Dir != -1) {
		  aux=aux+IntToStr(m->Obtener_Dato(Dir,"->dato"))+",";
		 }
		 Dir=m->Obtener_Dato(Dir,"->sgt");
	 }
	 aux=aux.Delete(aux.Length(),1);
	 aux="Conjunto : "+cad+"  { "+ aux +"  } ";
	 Canvas->TextOut(x1,y1,aux);
	}
 //---------------------------------------------------------------------------
   Direccion Conjunto_CSM :: anterior(int p){
   if (this->Vacio()) {
   } else if (p==ptr_conj) {
	   } else {
		   Direccion x=ptr_conj;
		   Direccion ant=-1;
		   while (x != -1){
			if (x==p) {
					return ant;
			}
			ant=x;
			x=m->Obtener_Dato(x,"->sgt");
		   }
	   }throw "No Hay Anterior";
   }

 //---------------------------------------------------------------------------
 Direccion Conjunto_CSM :: localiza(int e){
 Direccion Dir=ptr_conj;
 while (Dir != -1){
  if (m->Obtener_Dato(Dir,"->dato")==e) {
	  return Dir;
  }
  Dir=m->Obtener_Dato(Dir,"->sgt");
 }
 return -1;
 }
 //---------------------------------------------------------------------------
 int Conjunto_CSM :: obt_elem(Direccion pos){   //obtener elemento  envia posicion del elemento
 int c=0;
 Direccion x=ptr_conj;
 while (x != -1){
  if (c==pos)
	  return m->Obtener_Dato(x,"->dato");
   c++;
  x=m->Obtener_Dato(x,"->sgt");
 }
 return 0;
 }
 //---------------------------------------------------------------------------
  void Conjunto_CSM :: reiniciar(){

  while(!Vacio()) {
	 int r=Muestrea();
	Suprime(r);
  }

  }
 //---------------------------------------------------------------------------


#pragma package(smart_init)

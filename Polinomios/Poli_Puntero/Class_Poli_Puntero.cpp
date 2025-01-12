//---------------------------------------------------------------------------

#pragma hdrstop
 #include <vcl.h>
#include "Class_Poli_Puntero.h"
//---------------------------------------------------------------------------

Poli_Puntero :: Poli_Puntero(){
nt=0;
ptr_poli=NULL;
}
//---------------------------------------------------------------------------
Direccion Poli_Puntero :: Buscar_Exponente(int expo)
{
	Direccion Dir= ptr_poli;
	if (Dir != NULL) {
		Direccion dir_ex=NULL;
		while (Dir != NULL && dir_ex == NULL)
			{
			if (Dir->exp==expo) {
			 dir_ex=Dir;
			}
			Dir=Dir->sgt;
			}
			return dir_ex;
	} return NULL;
}
//---------------------------------------------------------------------------
Direccion Poli_Puntero :: Buscar_Terminos(int i)
{
 Direccion Dir = ptr_poli;
 if (Dir != NULL) {
	 Direccion dir_ter=NULL;
	 int n=0;
	 while (Dir != NULL  && dir_ter == NULL )  {
	   n++;
	   if (nt==i) {
		 dir_ter=Dir;
	   }
	   Dir=Dir->sgt;
	 }
	 return dir_ter;

 } else return NULL;
}
//---------------------------------------------------------------------------
bool Poli_Puntero :: Escero ()
{
	return nt==0;
}
//---------------------------------------------------------------------------
int Poli_Puntero :: Grado (){
Direccion Dir = ptr_poli;
if (Dir != NULL) {
	int MaxG = Dir->exp;
	while (Dir != NULL){
	 if (Dir->exp>MaxG) {
		 MaxG=Dir->exp;
	 }
	 Dir=Dir->sgt;
	} return MaxG;
} else return NULL;
}
//---------------------------------------------------------------------------
int Poli_Puntero :: Coeficiente (int expo) {
Direccion Dir = Buscar_Exponente(expo);
if (Dir != NULL) {
	return Dir->coef;
}  else return -1;
}
//---------------------------------------------------------------------------
void Poli_Puntero :: Asignar_Coeficiente(int coe,int expo){
 Direccion Dir= Buscar_Exponente(expo);
 if (Dir != NULL) {
	 Dir->coef=coe;
	 if (coe==0) {
	 Direccion ant=Anterior(expo);
	 if (ant != NULL) {
				ant->sgt = Dir->sgt;
			} else {
				ptr_poli = Dir->sgt;
			}
			delete Dir;
			nt--;
	 }
 } else ShowMessage("No Existe ese Termino");
}
//---------------------------------------------------------------------------
 int Poli_Puntero :: Exponente(int nroter){
  Direccion Dir = Buscar_Terminos(nroter);
  if (Dir != NULL ) {
	  return Dir->exp;
  } return -1;
 }
 //---------------------------------------------------------------------------
 void Poli_Puntero :: Poner_Termino (int coe,int expo)
 {
 Direccion Existe = Buscar_Exponente(expo);
 if (Existe == NULL) {
  Direccion aux = new NodoP();
  if (aux != NULL) {
	  aux->coef=coe;
	  aux->exp=expo;
	  aux->sgt=ptr_poli;
	  ptr_poli=aux;
	  nt++;
  } else ShowMessage("Memoria Llena");
 } else {
	 int Nuevo_Coe=Existe->coef+coe;
	 Existe->coef=Nuevo_Coe;
	 if (Nuevo_Coe == 0) {
	 Direccion ant=Anterior(expo);
	 if (ant != NULL) {
				ant->sgt = Existe->sgt;
			} else {
				ptr_poli = Existe->sgt;
			}
			delete Existe;
			nt--;
	 }
 }
 }
 //---------------------------------------------------------------------------
 int Poli_Puntero :: Numero_Terminos (){
 return nt;
 }
 //---------------------------------------------------------------------------
  void Poli_Puntero ::  Suma(Poli_Puntero *p1,Poli_Puntero *p2){

  }
  //---------------------------------------------------------------------------
  Direccion Poli_Puntero :: Anterior(int expo){
		Direccion Dir= ptr_poli;
		Direccion Ant=NULL;
	if (Dir != NULL) {
		while (Dir != NULL )
			{
			if (Dir->exp==expo) {
			 return Ant;
			}
			Ant=Dir;
			Dir=Dir->sgt;
			}
	} return NULL;
  }
 //---------------------------------------------------------------------------
 void Poli_Puntero :: Mostrar_Puntero (int x1,int y1, TCanvas *Canvas)
 {
 Canvas->Brush->Color=clAqua;
 Canvas->Rectangle(0,0,1600,1080);
 AnsiString aux="";
 Direccion Dir=ptr_poli;
  for (int i=1; i<=nt; i++) {
	  aux =aux+IntToStr(Dir->coef)+"X^"+IntToStr(Dir->exp)+" + ";
	  Dir=Dir->sgt;
  }
  aux= aux.Delete(aux.Length()-2,2);
  aux= "P = "+ aux;
  Canvas->Font->Size= 16;
  Canvas->TextOut(x1,y1,aux);
  Canvas->TextOut(x1,y1+50,"nt = "+IntToStr(nt));
 }
 //---------------------------------------------------------------------------
 void Poli_Puntero :: Derivar ()
 {

 Direccion Dir=ptr_poli;
 int i=1;
  while (i<=nt){
   int coe=Dir->coef; int expo=Dir->exp;
   Direccion ant=Anterior(expo);
   coe=coe*expo;
   expo=expo-1;
   if (expo !=-1) {
   Dir->coef=coe;
   Dir->exp=expo;
   Dir=Dir->sgt;
   i++;
   } else {
		  if (ant != NULL) {
				ant->sgt = Dir->sgt;
			} else {
				ptr_poli = Dir->sgt;
			}
			Dir=Dir->sgt;
			nt--;
   }
  }
 }
#pragma package(smart_init)

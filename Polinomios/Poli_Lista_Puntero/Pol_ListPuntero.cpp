//---------------------------------------------------------------------------

#pragma hdrstop

#include "Pol_ListPuntero.h"
#include "PtrLista.h"
//---------------------------------------------------------------------------

Lista_Ptr :: Lista_Ptr()
{
pol.~PtrLista();
}
//---------------------------------------------------------------------------
Direccion Lista_Ptr :: Buscar_Exponente(int expo) {
   Direccion Dir = pol.Siguiente(pol.Primero());
   if (Dir != NULL) {
   Direccion dir_exp=NULL;
   while (Dir != NULL && dir_exp==NULL){
	if (pol.Recupera(Dir)==expo) {
		dir_exp=Dir;
	}
	Dir=pol.Siguiente(pol.Siguiente(Dir));
   }
   return dir_exp;
   }else return NULL;
}
//---------------------------------------------------------------------------
Direccion Lista_Ptr :: Buscar_Terminos(int i){
  Direccion Dir = pol.Primero();
  int nt=0;
  if (Dir != NULL) {
	  Direccion dir_exp=NULL;
	  while (Dir != NULL && dir_exp==NULL){
	  nt++;
	  if (nt==i) {
		  dir_exp=Dir;
	  }
	  Dir=pol.Siguiente(pol.Siguiente(Dir));
	  } return dir_exp;
  } else
  return NULL;
}
//---------------------------------------------------------------------------
 int Lista_Ptr :: Grado(){
  Direccion Dir =pol.Siguiente(pol.Primero());
  if (Dir != NULL) {
	  int MaxG=pol.Recupera(Dir);
	  while(Dir != NULL) {
		  if (pol.Recupera(Dir)>MaxG) {
			  MaxG=pol.Recupera(Dir);
		  }
		  Dir=pol.Siguiente(pol.Siguiente(Dir));
	  }
	  return MaxG;
  } else return -1;
 }
 //---------------------------------------------------------------------------
  bool Lista_Ptr :: Escero(){
  return pol.Longitud==0;
  }
 //---------------------------------------------------------------------------
 int Lista_Ptr :: Coeficiente (int expo) {
	 Direccion Dir = Buscar_Exponente(expo);
	 if (Dir != NULL) {
	  return  pol.Recupera(pol.Anterior(Dir));
	 } else return -1;
 }
//---------------------------------------------------------------------------
void Lista_Ptr :: Asignar_Coeficiente(int coe,int expo) {
	Direccion Dir= Buscar_Exponente(expo);
	if (Dir != NULL) {
	Direccion dir_coef=pol.Anterior(Dir);
	pol.Modifica(dir_coef,coe);
	}else ShowMessage("No se Existe ese Exponente");
}
//---------------------------------------------------------------------------
void Lista_Ptr :: Poner_Termino (int coe,int expo) {
	Direccion dir_exp=Buscar_Exponente(expo);
	if (dir_exp != NULL) {
	Direccion dir_coe=pol.Anterior(dir_exp);
	pol.Modifica(dir_coe,pol.Recupera(dir_coe)+coe);
	if (pol.Recupera(dir_coe)==0) {
		pol.Suprime(dir_coe);
		pol.Suprime(dir_exp);
	}
	} else {
		//pol.Insertar_Ultimo(dir_coe);
		//pol.Insertar_Ultimo(dir_exp);
		pol.Inserta_Ultimo(expo);
		pol.Inserta(pol.Fin(),coe);
	}
}
//---------------------------------------------------------------------------
int Lista_Ptr :: Numero_Terminos () {
	return pol.Longitud()/ 2;
}
//---------------------------------------------------------------------------
int Lista_Ptr :: Exponente(int nroter) {
Direccion Dir = Buscar_Terminos(nroter);
if (Dir != NULL)
   return pol.Recupera(Dir);
   else return -1;
}
//---------------------------------------------------------------------------
void Lista_Ptr :: Derivar()
{
  int i=1;
  Direccion Dir=pol.Primero();
  while (i<=Numero_Terminos()) {
  int coef= pol.Recupera(Dir);  Dir=pol.Siguiente(Dir);
  int expo=pol.Recupera(Dir);
  coef=coef*expo;
  expo=expo-1;
  if (expo==-1) {
   pol.Suprime(Dir);
   pol.Suprime(pol.Anterior(Dir));
  }else {
	  pol.Modifica(pol.Anterior(Dir),coef);
	  pol.Modifica(Dir,expo);
	  i++;
  }
  Dir=pol.Siguiente(Dir);
  }
}
//---------------------------------------------------------------------------
void Lista_Ptr :: Mostrar(int x1,int y1,TCanvas *Canvas){
pol.Dibujar(x1,y1,Canvas);
AnsiString aux= "";
Direccion Dir=pol.Primero();
for (int i=1; i <= Numero_Terminos(); i++) {
if (pol.Recupera(Dir)) {
 aux=aux+IntToStr(pol.Recupera(Dir))+"X^"+IntToStr(pol.Recupera(pol.Siguiente(Dir)))+" + ";
}
 Dir=pol.Siguiente(pol.Siguiente(Dir));
}
aux=aux.Delete(aux.Length()-2,2);
aux=" P = "+aux;
//Canvas->Font->Size=16;
Canvas->TextOut(x1,y1+80,aux);
}





















#pragma package(smart_init)

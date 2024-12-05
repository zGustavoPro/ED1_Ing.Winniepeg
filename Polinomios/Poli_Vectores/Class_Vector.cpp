//---------------------------------------------------------------------------

#pragma hdrstop

#include "Class_Vector.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Poli_Vector :: Poli_Vector ()
{
nt=0;
}
//---------------------------------------------------------------------------
 bool Poli_Vector :: Escero()
{
  return nt==0;
}
//---------------------------------------------------------------------------
 int Poli_Vector :: Grado()
{
	if (nt>0) {
		   int max = exp[1];
	   for (int i=1; i <= nt; i++) {
					if ( exp[i]>max) {
						max = exp[i];
					}
	   }
	   return max;
	}else return -1;
}
//---------------------------------------------------------------------------
void Poli_Vector :: Asignar_Coeficiente(int coe,int expo){

  int lug=Buscar_Exponente(expo);
  if (lug != -1 ) {
				coef[lug]=coe;
				if (coef[lug]==0) {
				Desplazar(lug);
				}

  }   else throw "No Existe ese Termino";
}
//---------------------------------------------------------------------------
int Poli_Vector :: Buscar_Exponente(int expo){
for (int i=1; i<=Numero_Terminos(); i++) {
if (exp[i]==expo) {
	return i;      }
}
return -1;
}
//---------------------------------------------------------------------------
void Poli_Vector :: Desplazar (int pos){
for (int i = pos ; i<=nt ;i++) {
	 coef[i]= coef[i+1];
	 exp[i]=exp[i+1];
}
nt--;
}
//---------------------------------------------------------------------------
void Poli_Vector :: Poner_Termino(int coe,int expo)
{
 int lug = Buscar_Exponente(expo);
 if (lug != -1) {
	 coef[lug]=coef[lug]+coe;
	 if (coef[lug]== 0) {
		   Desplazar(lug);
	 }
 } else {
	 nt++;
	 coef[nt]=coe;
	 exp[nt]=expo;
 }
}
//---------------------------------------------------------------------------
int Poli_Vector :: Numero_Terminos()
{
	return nt;
}
//---------------------------------------------------------------------------
int Poli_Vector :: Coeficiente (int expo)
{
 if (expo>0 && expo<=Grado()) {
  for (int i=1; i <=nt; i++) {
	  if (exp[i]==expo) {
		  return coef[i];
	  }
  }
 }  else -1;
}
//---------------------------------------------------------------------------
 int Poli_Vector :: Exponente(int nroter)
 {
  return exp[nroter];
 }
 //---------------------------------------------------------------------------
 void Poli_Vector :: Mostrar_Vector (int x1,int y1,TCanvas *Canvas){
 int x=50;
 int y=26;
 int a=x1;
 int h=y1;
 AnsiString aux="";
 Canvas->Brush->Color=clAqua;
 Canvas->Rectangle(0,0,1600,1080);
 Canvas->Brush->Color=clYellow;
 Canvas->Font->Size=9;
 for (int i=1; i <= nt; i++) {
  Canvas->Rectangle(x1,y1,x1+x,y1+y);
  Canvas->TextOut(x1+20,y1+2,IntToStr(coef[i]));

  Canvas->Rectangle(x1,y1+y+20,x1+x,y1+2*y+20);
	Canvas->TextOut(x1+20,y1+y+22,IntToStr(exp[i]));

  x1=x1+50;
	   aux=aux+IntToStr(coef[i])+"X^"+IntToStr(exp[i])+" + ";
 }
 Canvas->Rectangle(a,y1+2*y+40,a+x,y1+2*y+70);
 Canvas->TextOut(a+10,y1+2*y+42,"nt : "+ IntToStr(nt));
 Canvas->Font->Size=16;
 aux=aux.Delete(aux.Length()-2,2);
 aux= " P = " + aux;
 Canvas->TextOut(x1,y1*2+60,aux);
 }
  //---------------------------------------------------------------------------
  void Poli_Vector :: Derivar (){
  int i=1;
  while (i<=Numero_Terminos()) {
	  int coe=coef[i];   int expo=exp[i];
	   coe=expo*coe; expo=expo-1;
	   if (expo==-1) {
					  Desplazar(i);
	   }  else {
		   coef[i]=coe;
		   exp[i]=expo;
		   i++;
	   }
  }
  }

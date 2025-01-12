//---------------------------------------------------------------------------

#pragma hdrstop
#include <iostream>
 #include<string>
#include "Cpoli_CSM.h"
//---------------------------------------------------------------------------
Pol_CSM :: Pol_CSM ()
{
   m=new CSMemoria();
	nt=0;    ptr_poli=-1;
}
//---------------------------------------------------------------------------
 Pol_CSM :: Pol_CSM (CSMemoria *&cm)
 {
 m=cm;
 nt=0; ptr_poli=-1;
 }
//---------------------------------------------------------------------------
 bool Pol_CSM :: Escero()
 {
	 return nt==0;
 }
 //---------------------------------------------------------------------------
 Direccion Pol_CSM :: Buscar_Exponente(int expo){
   Direccion Dir =ptr_poli;
if (Dir != -1) {
	 Direccion dir_ex=-1;
	 while ((Dir != -1) && (dir_ex==-1))
	 {
		 if (m->Obtener_Dato(Dir,"->exp")==expo)  {
		 dir_ex=Dir;                            }
		 Dir=m->Obtener_Dato(Dir,"->sgt");
	 }
	 return dir_ex;
}else return -1;
 }
 //---------------------------------------------------------------------------
 Direccion Pol_CSM :: Buscar_Termino (int i)
 {

Direccion Dir = ptr_poli;
if (Dir != -1) {
Direccion dir_ter = -1 ;
Direccion Nt=0;
while(Dir != -1 && dir_ter==-1 )
{
 Nt=Nt+1;
 if (Nt==i) {
	  dir_ter=Dir; }
		   Dir=m->Obtener_Dato(Dir,"->sgt");
}
return dir_ter;
} else return -1;
 }
 //---------------------------------------------------------------------------
 int Pol_CSM :: Grado ()
 {
 Direccion Dir =ptr_poli;

 if (Dir != -1) {
	 int MaxG = m->Obtener_Dato(Dir,"->exp");
	 while(Dir != -1)
	 {
	   if (m->Obtener_Dato(Dir,"->exp")>MaxG) {
		   MaxG=m->Obtener_Dato(Dir,"->exp");
	   }
	   Dir=m->Obtener_Dato(Dir,"->sgt");
	 }
	 return MaxG;
 } else return -1;
 }
  //---------------------------------------------------------------------------
  int Pol_CSM :: Coeficiente(int expo){
   Direccion Dir= Buscar_Exponente(expo);
	 if (Dir != -1)
		  return m->Obtener_Dato(Dir,"->coef") ;
   else return -1;
  }
  //---------------------------------------------------------------------------
  void Pol_CSM :: Asignar_Coeficiente(int coe,int expo){
	 Direccion Dir = Buscar_Exponente(expo);
		if (Dir != -1) {
		m->Poner_dato(Dir,"->coef",coe);
		if (coe==0){
			Delete_Pol(Dir);
			m->Delete_espacio(Dir);
		}
   }// throw "No Existe ese Termino";
  }
   //---------------------------------------------------------------------------
   void Pol_CSM :: Poner_Termino (int coe,int expo) {

	 Direccion Existe = Buscar_Exponente(expo);  // devuelve Direccion

	 if (Existe == -1) {// -1 No Existe
	Direccion aux = m->new_espacio("coef,exp,sgt");
	 if (aux != -1)
	 {
	 m->Poner_dato(aux,"->coef",coe);
	 m->Poner_dato(aux,"->exp",expo);
	 m->Poner_dato(aux,"->sgt",ptr_poli);
	 ptr_poli=aux;
	 nt++;
	 } else ShowMessage("Memoria llena");//throw "Error Memoria LLena";
	 } else {
	 int Nuevo_Coef= m->Obtener_Dato(Existe,"->coef")+coe;
	 m->Poner_dato(Existe,"->coef",Nuevo_Coef);
	 if (Nuevo_Coef==0)
	 {
	 Delete_Pol(Existe);
	 m->Delete_espacio(Existe);
	 }
		}
   }
   //---------------------------------------------------------------------------
  int Pol_CSM :: Numero_Terminos(){
  return nt;
  }
   //---------------------------------------------------------------------------
 int Pol_CSM :: Exponente(int nroter){
 Direccion Dir = Buscar_Termino(nroter);
  if (Dir != -1)
	  return m->Obtener_Dato(Dir,"->exp");
  else  return  -1;
 }
 //---------------------------------------------------------------------------
 void Pol_CSM :: MostrarCSM(int x1,int y1,TCanvas *Canvas){
 m->Mostrar(x1,y1,Canvas);
 }
 //---------------------------------------------------------------------------
 void Pol_CSM :: MostrarPol (int x1,int y1,TCanvas *Canvas){
 AnsiString auxp="  ";
  AnsiString auxl="   ";

   Canvas->Brush->Color=clBtnFace;
   for(int i=1; i<=nt;i++){
   int Dir= Buscar_Termino(i);
   int coe=m->Obtener_Dato(Dir,"->coef");
   int expo=m->Obtener_Dato(Dir,"->exp");
   auxp=auxp+IntToStr(coe)+"X^"+IntToStr(expo)+" + ";
   auxl=auxl+IntToStr(coe)+","+IntToStr(expo)+"  , ";
   }
   auxp=auxp.Delete(auxp.Length()-2,2);
   auxl=auxp.Delete(auxl.Length()-2,2);
   auxp=" P(x) = "+auxp;
   auxl="< "+auxl+" >";
   Canvas->TextOut(x1,y1,auxp);
 }

  //---------------------------------------------------------------------------
  void Pol_CSM :: Derivar(){
	int i = 1;
	while (i <= nt) {
		Direccion Dir = Buscar_Termino(i);
		if (Dir != -1) {
			int coef = m->Obtener_Dato(Dir, "->coef");
			int exp = m->Obtener_Dato(Dir, "->exp");
			if (exp != 0) {
				coef = coef * exp;
				exp = exp - 1;
				m->Poner_dato(Dir, "->coef", coef);
				m->Poner_dato(Dir, "->exp", exp);
				i++;
			} else {
				Delete_Pol(Dir);
				m->Delete_espacio(Dir);
			}
		}
		}
	}
   //---------------------------------------------------------------------------
  double Pol_CSM :: Evaluar(double x){
  double y=0;
	for (int i=1; i <=nt; i++) {
	  Direccion Dir = Buscar_Termino(i);
	  int coef=m->Obtener_Dato(Dir,"->coef");
	  int exp=m->Obtener_Dato(Dir,"->exp");
	  y +=pow(x,exp)*coef;
  } return y;
  }

  //---------------------------------------------------------------------------
  double Pol_CSM :: Potencia(double base,int expo){
  double n=base;
  if (expo==0) {
	  return 1;
   } else{
  for (int i=1; i < expo; i++)
   n *= base;
   }
  return n;
  }
 //---------------------------------------------------------------------------
 void Pol_CSM :: CordenadasXY(int a,int b,TCanvas *Canvas){

   int n=20;

   int x1 = 1150;
	int y1 = 20;
	int ox = 1150; // Origen en (0,0)
	int oy = 270;

	 a=ox+(a*n);
	 b=ox+(b*n);

   //Canvas->Brush->Color = clBtnFace;
	//TRect area(x1 - 200, 0, x1 + 200, y1 + 500);
	//Canvas->FillRect(area);

	if (nt != 0) {
	Canvas->Brush->Color=clRed;
		for (double i =-1600; i <=1600; i += 0.03) {
			double pol = Evaluar(i)*n;   double x=i*n;

			if ((pol>=0 && oy-pol>=20 ) && ( ox+x>=a && ox+x<=b ))
			   //	Canvas->Pixels[ox+x][oy-pol]=clRed;
				Canvas->Ellipse(ox + x - 2, oy - pol - 2, ox + x + 2, oy - pol +2 );
			 else if ((pol<=0 && oy-pol<=520 ) && ( ox+x>=a && ox+x<=b ))
			//Canvas->Pixels[ox+x][oy-pol]=clRed;
			 Canvas->Ellipse(ox + x - 2, oy - pol - 2, ox + x + 2, oy - pol + 2);
		}
		}


	Canvas->Font->Color = clBlack;
	Canvas->MoveTo(x1, y1); // Eje Y
	Canvas->LineTo(x1, y1 +500);

	Canvas->MoveTo(x1 - 200, 270); // Eje X
	Canvas->LineTo(x1 + 200, 270);


 }
 //---------------------------------------------------------------------------
 //---------------------------------------------------------------------------
  void Pol_CSM :: Delete_Pol(Direccion Dir){
   if (Numero_Terminos()>1) {
   if (Dir==ptr_poli) {
	ptr_poli=m->Obtener_Dato(Dir,"->sgt");
   nt--;
   } else {  int fin=Buscar_Termino(nt);
	int ant=Buscar_Termino(nt-1);
			 if ( Dir==fin) {
			  m->Poner_dato(ant,"->sgt",-1);
			  nt--;
		   } else {
		   int siguiente=m->Obtener_Dato(Dir,"->sgt");
			 m->Poner_dato(ant,"->sgt",siguiente);
			 nt--;
		   }
   }
   }else if (nt==1){ ptr_poli=-1;
		nt--;
   }
  }
  //---------------------------------------------------------------------------
  void Pol_CSM :: DerivarP(Pol_CSM *p) {
    int i = 1;
	while (i <= nt) {
		Direccion Dir = Buscar_Termino(i);
		if (Dir != -1) {
			int coef = m->Obtener_Dato(Dir, "->coef");
			int exp = m->Obtener_Dato(Dir, "->exp");
			if (exp != 0) {
				coef = coef * exp;
				exp = exp - 1;
				p->Poner_Termino(coef,exp);
			  // m->Poner_dato(Dir, "->coef", coef);
			   //	m->Poner_dato(Dir, "->exp", exp);
				i++;
			} else {
				p->Delete_Pol(Dir);
				m->Delete_espacio(Dir);
			}
		}
		}
  }
	//---------------------------------------------------------------------------


	void Pol_CSM :: punto (Pol_CSM *p){
	 double y=0;
	 AnsiString cad="";
	 for (double x =-30; x <=30; x+=0.5) {
	  if (Evaluar(x)==p->Evaluar(x)) {
	   ShowMessage("["+AnsiString(x)+","+AnsiString(Evaluar(x))+"]");
	  }
		 }

	}
#pragma package(smart_init)

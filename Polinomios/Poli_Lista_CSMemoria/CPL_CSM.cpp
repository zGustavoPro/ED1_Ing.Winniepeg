//---------------------------------------------------------------------------

#pragma hdrstop

#include "CPL_CSM.h"
#include <vcl.h>
#include <string.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)

 Poli_CSM :: Poli_CSM()   //creando la clase lista con CSM
{
nt=0;
pol=new Lista();
}
//---------------------------------------------------------------------------
Poli_CSM :: Poli_CSM(CSMemoria *men){
pol=new Lista(men);
nt=0;
}
//---------------------------------------------------------------------------
Direccion Poli_CSM :: Buscar_Exponente(int expo) {
  int aux = pol->Primero();
	while (aux != -1) {
		int aux_sig = pol->Siguiente(aux); // aux->sig
		int aux_sig_elem = pol->Recupera(aux_sig); // aux->sig->elemento
		if (aux_sig_elem == expo) {
			return aux;
		}
		aux = pol->Siguiente(aux_sig);
	}
	return -1;
}
//---------------------------------------------------------------------------
Direccion Poli_CSM :: Buscar_Termino(int i){
  Direccion Dir = pol->Primero();
  if (Dir != -1) {
	  Direccion dir_ter=-1;
	  int n=0;
	  while (Dir != -1  && dir_ter==-1){
	  n++;
	  if (n==i) {
		  dir_ter=Dir;
	  }
	  Dir=pol->Siguiente(pol->Siguiente(Dir));
	  } return dir_ter;
  } else return -1;

}
//---------------------------------------------------------------------------
 int Poli_CSM :: Grado(){
  Direccion Dir =pol->Siguiente(pol->Primero());
  if (Dir != -1) {
	  int MaxG=pol->Recupera(Dir);
	  while(Dir != -1 && Dir <=pol->Fin()) {
		  if (pol->Recupera(Dir)>MaxG) {
			  MaxG=pol->Recupera(Dir);
		  }
		  Dir=pol->Siguiente(pol->Siguiente(Dir));
	  }
	  return MaxG;
  } else return -1;
 }
 //---------------------------------------------------------------------------
  bool Poli_CSM :: Escero(){
  return nt==0;//pol->Longitud()==0;
  }
 //---------------------------------------------------------------------------
 int Poli_CSM :: Coeficiente (int expo) {
	 Direccion Dir = Buscar_Exponente(expo);
	 if (Dir != -1) {
	  return  pol->Recupera(pol->Anterior(Dir));
	 } else return -1;
 }
//---------------------------------------------------------------------------
void Poli_CSM :: Asignar_Coeficiente(int coe,int expo) {
	Direccion Dir= Buscar_Exponente(expo);
	if (Dir != -1) {
	Direccion dir_coef=pol->Anterior(Dir);
	pol->Modifica(dir_coef,coe);
	if(coe==0){
	pol->Suprime(Dir);
	pol->Suprime(dir_coef);
	}
	}
}
//---------------------------------------------------------------------------
void Poli_CSM :: Poner_Termino (int coe,int expo) {
int existe = Buscar_Exponente(expo);
	if (existe == -1) {
		if (coe != 0 && expo >= 0) {
			pol->Inserta_ultimo(coe);
			pol->Inserta_ultimo(expo);
			nt++;
		}
	}
	else {
		int existe_elem = pol->Recupera(existe);
		pol->Modifica(existe, existe_elem + coe);
		// existe->elemento = existe->elemento + coef;
		if (existe_elem == 0) {
			int exp_elim = pol->Siguiente(existe);
			pol->Suprime(existe);
			pol->Suprime(exp_elim);
			nt--;
		}
	}
}
//---------------------------------------------------------------------------
int Poli_CSM :: Numero_Terminos () {
	return nt;//pol->Longitud()/ 2;
}
//---------------------------------------------------------------------------
int Poli_CSM :: Exponente(int nroter) {
Direccion Dir = Buscar_Termino(nroter);
if (Dir != -1)
   return pol->Recupera(pol->Siguiente(Dir));
   else return -1;
}
//---------------------------------------------------------------------------
void Poli_CSM :: Derivar()
{
  int i=1;
  Direccion Dir=pol->Primero();
  while (i<=Numero_Terminos()) {
  int coef= pol->Recupera(Dir);  Dir=pol->Siguiente(Dir);
  int expo=pol->Recupera(Dir);
  coef=coef*expo;
  expo=expo-1;
  if (expo==-1) {
   pol->Suprime(Dir);
   pol->Suprime(pol->Anterior(Dir));
  }else {
	  pol->Modifica(pol->Anterior(Dir),coef);
	  pol->Modifica(Dir,expo);
	  i++;
  }
  Dir=pol->Siguiente(Dir);
  }
}
//---------------------------------------------------------------------------
void Poli_CSM :: Mostrar_Polinomio(int x1,int y1,TCanvas *Canvas){
Canvas->Font->Color=clBlack;
AnsiString aux= "  ";
Direccion Dir=pol->Primero();
//if (pol->Vacio()) { ShowMessage("Polinomio vacio");}
for (int i=1; i <= Numero_Terminos(); i++) {
if (Dir != -1) {
 aux=aux+IntToStr(pol->Recupera(Dir))+"X^"+IntToStr(pol->Recupera(pol->Siguiente(Dir)))+" + ";
}
 Dir=pol->Siguiente(pol->Siguiente(Dir));
}
aux=aux.Delete(aux.Length()-2,2);
aux=" P = "+aux;
//Canvas->Font->Size=16;
Canvas->TextOut(x1,y1+80,aux);
}
//---------------------------------------------------------------------------
void Poli_CSM :: Mostrar_Lista(int x1,int y1,TCanvas *Canvas){
Canvas->Font->Color=clBlack;
pol->Mostrar_Lista(x1,y1,Canvas);
}
//---------------------------------------------------------------------------
void Poli_CSM :: Mostrar_CSM(int x1,int y1,TCanvas *Canvas){
pol->Mostrar(x1+200,y1,Canvas);
}

 void Poli_CSM :: CordenadasXY(int a,int b,TCanvas *Canvas){

   int n=20;

   int x1 = 1150;
	int y1 = 20;
	int ox = 1150; // Origen en (0,0)
	int oy = 270;

	 a=ox+(a*n);
	 b=ox+(b*n);

   Canvas->Brush->Color = clBtnFace;
	TRect area(x1 - 200, 0, x1 + 200, y1 + 500);
	Canvas->FillRect(area);

	if (Numero_Terminos() != 0) {
	Canvas->Brush->Color=clRed;
		for (double i =-300; i <=300; i += 0.03) {
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
 double Poli_CSM :: Evaluar(double x){
  double y=0;
	for (int i=1; i <=Numero_Terminos(); i++) {
	  Direccion Dir = Buscar_Termino(i);
	  int coef=pol->Recupera(Dir);
	  int exp=pol->Recupera(pol->Siguiente(Dir));
	  y +=pow(x,exp)*coef;
  } return y;
  }

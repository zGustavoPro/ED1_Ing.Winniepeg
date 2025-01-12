//---------------------------------------------------------------------------

#pragma hdrstop

#include "VecLista.h"
#include <vcl.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
	VecLista::VecLista()
{
	longitud=0;
}

direccion VecLista::Fin()
{
 if(Vacio()) {
 //throw"Lista vacia";
 }
 else
	return longitud-1;
}

 direccion VecLista::Primero()
 {
  if(Vacio()){
 //throw"Lista vacia";
 }
 else
	return 0;
 }

 direccion VecLista::Siguiente(direccion p )
 {
   if (Vacio())
	  throw "Lista Vacia";
	  else
	  {
		if (p+1==longitud)
	   return -1;
		else
		return p+1;
	  }
 }

 direccion  VecLista::Anterior( direccion p)
 {
	  if (Vacio())
	  throw "Lista Vacia";
	  else
	  {
		if (p==0)
		throw "No hay Anterior";
		else
		return p-1;
	  }
 }

  bool VecLista:: Vacio()
  {
	  return (longitud==0);
  }

int VecLista::Recupera(direccion p)
   {
	 if (Vacio())
	  throw "Lista Vacia";
	  else if(p>=0 && p<longitud)
		  return lista[p];
		  else throw "Error de Rango";
   }

int VecLista::Longitud ()
	{
		return longitud;
	}

void VecLista::Inserta( direccion p, int dato){
		if (longitud == Max) {
		ShowMessage( "Lista LLena");
	}
	else if (this->Vacio()) {
		lista[0] = dato;
		longitud++;
	}
	else if (p >= 0 && p <= longitud) {
		for (int i = longitud; i > p; i--) {
			this->lista[i] = this->lista[i - 1];
		}
		this->lista[p] = dato;
		this->longitud++;
	}
	else {
	ShowMessage( "Posicion Incorrecta" );
	}
}

void  VecLista::Inserta_Primero( int dato)
{
	this->Inserta(0,dato);
}
void VecLista::Inserta_Ultimo(int dato)
{
 this->Inserta(longitud,dato);
}
void VecLista::Suprime(direccion p)
{
if (longitud == 0) {
		ShowMessage("Lista Vacia");
	}
	else if (p >= 0 && p <= longitud - 1) {
		for (int i = p; i < longitud - 1; i++) {
			this->lista[i] = this->lista[i + 1];
		}
		longitud--;
	}
	else {
		throw "POSICION INCORRECTA";
	}
}
void VecLista::Modifica( direccion p, int dato)
{
  if (longitud == 0) {
		ShowMessage("LISTA VACIA");
	}
	else if (p >= 0 && p <= longitud - 1) {
		lista[p] = dato;
	}
	else {
		throw "POSICION INCORRECTA";
	}
}

	void  VecLista :: anula() {
	   longitud=0;
	}

void VecLista:: Dibuja(int x1, int y1, TCanvas* Canvas)
{
 int x=30;
  Canvas->Brush->Color=clAqua;
 Canvas->Rectangle(0,0,1600,1080);
 //TRect area(x1,y1,x1+1000,y1+50);
 //Canvas->FillRect(area);

AnsiString aux=" ";
	Canvas->Font->Size = 17;
		Canvas->Font->Color = clBlack;
  for (int i=0; i <longitud; i++) {
	 aux=aux+StrToInt(lista[i])+" ,";
  }
   aux=aux.Delete(aux.Length(),1);
	aux = "<" +aux + " >";
	 Canvas->TextOut(x1,y1,aux);
}

direccion VecLista:: localiza(int e){
for (int i = 0; i < longitud; i++) {
		if (lista[i] == e)
			return i;
	}
	return -1;
}
void VecLista:: elimina_Dato(int e){
 int i = 0;
	while (i < longitud) {
		if (e == lista[i]) {
			for (int j = i; j < longitud - 1; j++) {
				this->lista[j] = this->lista[j + 1];
			}
			longitud--;
		}
		else {
			i++;
		}

	}
}

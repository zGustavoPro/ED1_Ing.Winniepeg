//---------------------------------------------------------------------------

#pragma hdrstop
 #include <string.h>
 #include <vcl.h>
#include "PtrLista.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
   PtrLista::PtrLista()
{
	longitud=0; ptrElementos = NULL;
}

bool PtrLista::Vacio()
{
	return (longitud==0);
}
 int PtrLista::Longitud()
 {
	 return longitud;
 }
 Direccion PtrLista::Primero()
 {   if (Vacio())
	 {
	 ShowMessage("Lista Vac�a");
	 return NULL;
	 }
	 else
	 {
	 return ptrElementos;
	 }
 }

 Direccion PtrLista::Fin()
 {
	 if (Vacio())
	 {
	 ShowMessage("Lista Vac�a");
	 return NULL;
	 }
	 else
	 {
	 Direccion x = ptrElementos;
	 Direccion ptrFin;
	 while (x!=NULL)
		 {
					  ptrFin=x;
					  x =x->sig;
		 }
		 return ptrFin;

	 }
 }
 Direccion PtrLista::Siguiente(Direccion p)
 {
   if (Vacio())
   {
	 ShowMessage("Lista Vac�a");
	 return NULL;
   }
   else
   {
	   if (p==Fin()) {
		//ShowMessage("direccion no v�lida");
	   return NULL;
	   }
	   else
	   {
	   return  p->sig;
	   }
   }
 }
 Direccion PtrLista::Anterior(Direccion p)
 {
	 if (Vacio())
	 {
		ShowMessage("Lista Vac�a");
	 return NULL;
	 }
	 else
	 {
	   if (p==Primero())
	   {
	   //ShowMessage("direccion no v�lida");
	   return NULL;
	   }
	   else
	   {
	   Direccion x=ptrElementos;
	   Direccion ant=NULL;
	   while (x!=NULL)
		   {
			ant=x;
			x=x->sig;
			if (x==p)
			{
			 return ant;
			}
		   }
	   }
	 }
 }
 void PtrLista::Inserta(Direccion p,int dato)
 {
   NodoL* x = new NodoL ;
   if (x!=NULL)
   {
	 x->elemento = dato;
	 x->sig = NULL;
	 if (Vacio())
	 {
	  ptrElementos = x;
	  longitud=1;
	 }
	 else
	 {
	  longitud++;
	  if (p==Primero())
	  {
	   x->sig=p;
	   ptrElementos=x;
	  }
	  else
	  {
			Direccion ant=Anterior(p);
			ant->sig=x;
			x->sig=p;
	  }
	 }
   }
   else
   {
	   ShowMessage("existe espacio memoria");
   }
 }
  void PtrLista::Inserta_Primero(int dato)
  {
	  NodoL* x=new NodoL;
	  if (x!=NULL)
	  {
		x->elemento=dato;
		x->sig=ptrElementos;
		ptrElementos=x;
		longitud++;
	  }
	  else
   {
	   ShowMessage("existe espacio memoria");
   }
  }

  void PtrLista::Inserta_Ultimo(int dato)
   {
	 NodoL* x= new NodoL;
	 if (x!=NULL)
	 {
	  x->elemento=dato;
	  x->sig=NULL;
	   if (longitud!=0)
		{
		 Fin()->sig=x;
		}
		else
		{
		  ptrElementos=x;
		}
	  longitud++;
	 }
   }
   int PtrLista::Recupera(Direccion p)
   {
	   if (Vacio())
	   {
		   //ShowMessage("Lista vac�a");
		   return NULL;
	   }
	   else
	   {
		  return p->elemento;
	   }
   }
   void PtrLista::Suprime(Direccion p)
   {
	   if (Vacio())
	   {
			ShowMessage("Lista vac�a");
	   }
	   else
	   {
		   if (p==Primero())
		   {
			Direccion x=ptrElementos;
			ptrElementos=ptrElementos->sig;
			delete x;
		   }
		   else
		   {
			   Direccion ant=Anterior(p);
			   ant->sig=Siguiente(p);
			   delete p;
		   }
		   longitud--;
	   }
   }
   void PtrLista::Modifica(Direccion p,int dato)
   {
	   if (Vacio()) {
		  ShowMessage("Lista vac�a");
	   }
	   else
	   {
		   p->elemento=dato;
	   }
   }
   void PtrLista::Dibujar(int x1,int y1, TCanvas *Canvas)
   {
		Canvas->Brush->Color=clAqua;
		Canvas->Rectangle(0,0,1600,1080);
		  AnsiString aux="<  ";
		  for (Direccion p=Primero(); p != NULL; p=Siguiente(p)) {
			   if (Recupera(p)!=NULL) {
				 aux = aux+ AnsiString(IntToStr(Recupera(p)))+ ", ";
			   }
		  }
		  aux=aux.Delete(aux.Length()-1,2);
		  aux =aux + " > ";
		  // Canvas->Font->Size=30;
		   Canvas->TextOut(x1,y1,aux);

   }
//---------------------------------------------------------------------------

#pragma hdrstop
 #include <string.h>
 #include <vcl.h>
#include "PtrLista.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
   PtrLista::PtrLista()
{
	longitud=0; ptrElementos = nullptr;
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
	// ShowMessage("Lista Vac�a");
	 return nullptr;
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
	// ShowMessage("Lista Vac�a");
	 return nullptr;
	 }
	 else
	 {
	 Direccion x = ptrElementos;
	 Direccion ptrFin;
	 while (x!=nullptr)
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
	 return nullptr;
   }
   else
   {
	   if (p==Fin()) {
	  // ShowMessage("direccion no v�lida");
	   return nullptr;
	   }
	   else
	   {
	   return  p->sig;
	   }
   } //return nullptr;
 }
 Direccion PtrLista::Anterior(Direccion p)
 {
	 if (Vacio())
	 {
		ShowMessage("Lista Vac�a");
	 return nullptr;
	 }
	 else
	 {
	   if (p==Primero())
	   {
	   //ShowMessage("direccion no v�lida");
	   return nullptr;
	   }
	   else
	   {
	   Direccion x=ptrElementos;
	   Direccion ant=nullptr;
	   while (x!=nullptr)
		   {
		   if (x==p) {
				   return ant;
			   }
			   else
			   {
				ant = x;
				x = x->sig;
			   }
		   }
	   }
	 } throw "Error";
 }
 void PtrLista::Inserta(Direccion p,int dato)
 {
   NodoL* x = new NodoL ;
   if (x!=nullptr)
   {
	 x->elemento = dato;
	 x->sig = nullptr;
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
	  if (x!=nullptr)
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
  Direccion PtrLista :: Localiza(int e){
  Direccion x = ptrElementos;
	while (x != NULL) {
		if (x->elemento == e)
			return x;
		x = x->sig;
	}
	return nullptr;
  }

  void PtrLista::Inserta_Ultimo(int dato)
   {
	 NodoL* x= new NodoL;
	 if (x!=nullptr)
	 {
	  x->elemento=dato;
	  x->sig=nullptr;
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
		   ShowMessage("Lista vac�a");
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
		  AnsiString aux=" ";
		//  for (Direccion p=Primero(); p != NULL; p=Siguiente(p)) {
		  //	   if (Recupera(p)!=NULL) {
			//	 aux = aux+ AnsiString(IntToStr(Recupera(p)))+ ",";
			  // } }
			  Direccion x=Primero();
			  for (int i=1; i <=longitud; i++) {
				  if (x != nullptr) {
				  aux=aux +IntToStr(Recupera(x))+ ",";
				  }
				  x=Siguiente(x);
			  }
		  aux=aux.Delete(aux.Length(),1);
		  aux = "<" + aux + " > ";
		   Canvas->Font->Size=30;
		   Canvas->TextOut(x1,y1,aux);

   }
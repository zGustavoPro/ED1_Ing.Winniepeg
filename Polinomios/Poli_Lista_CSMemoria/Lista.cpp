//---------------------------------------------------------------------------

#pragma hdrstop
#include "Lista.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
  Lista::Lista()
 {   m=new CSMemoria();
	 longitud=0;
	 ptrElementos=-1;
 }
  Lista::Lista(CSMemoria *mem)
 {   m=mem;
	 longitud=0;
	 ptrElementos=-1;
 }
 bool Lista::Vacio()
 {
	 return  longitud == 0;
 }
 int Lista::Longitud()
 {
	 return longitud;
 }
 direccion  Lista::Fin()
 {
	 if (Vacio())
	 {
	 throw "Lista vacia";
	 }
	 else
	 {
	 direccion ptrFin=-1;
	 direccion x = ptrElementos;

		 while (x != -1)
		 {
			 ptrFin=x;
			 x = m->Obtener_Dato(x,"->sig");
		 }
		return ptrFin;
	 }
 }
 direccion Lista::Primero()
 {
	 return ptrElementos;
 }
  direccion Lista::Siguiente(direccion p)
  {  if (Vacio())
	 {
	  return -1;
	 }
		 else
		 {
		 return m->Obtener_Dato(p,"->sig");
		 }
	 }
	direccion Lista::Anterior(direccion p)
	{
	 if (Vacio())
	 {
	 throw "No hay Anterior";
	 }
	 else
	 {
		 if (p==ptrElementos)
		 {
		// throw "No hay Anterior";
		return -1;
		 }
		 else
		 {
		   direccion x=ptrElementos;
		   direccion ant=-1;
		   while (x!=-1)
			   {
				 if (x==p)
				 {
					 return ant;
				 }
				 ant=x;
				 x=m->Obtener_Dato(x,"->sig");

			   }
		 }
	 }throw "No hay anterior" ;
	}
 void Lista::Inserta(direccion p , int dato)
 {
	 direccion x=m->new_espacio("elemento,sig");
	 if (x!=-1)
		 {
				 m->Poner_dato(x,"->elemento",dato);
				 m->Poner_dato(x,"->sig",-1);
				 if (Vacio()) {
					 ptrElementos=x;
					 longitud=1;
				 }
				 else
				 {
					 longitud++;
					 if (p==Primero())
					 {
					   m->Poner_dato(x,"->sig",p);
					   ptrElementos=x;
					 }
					 else
					 {
					  direccion ant= Anterior(p);
					  m->Poner_dato(ant,"->sig",x);
					  m->Poner_dato(x,"->sig",p);
					 }
				 }
		 }
 }
 void Lista::Inserta_primero(int dato)
 {
   //Inserta(ptrElementos,dato);
	  direccion x=m->new_espacio("elemento,sig");
   if (x!=-1)
   {
	  m->Poner_dato(x,"->elemento",dato);
	  m->Poner_dato(x,"->sig",ptrElementos);
	  longitud++;
	  ptrElementos=x;
   }
 }
 void Lista::Inserta_ultimo(int dato)
 {
   direccion x=m->new_espacio("elemento,sig");
	   if(x != -1){
	   m->Poner_dato(x,"->elemento",dato);
	   m->Poner_dato(x,"->sig",-1);
	   if (longitud==0)
	   {
		  ptrElementos=x;
	   }
	   else
	   {
	   direccion final=Fin();
	   m->Poner_dato(final,"->sig",x);
	   }
	   longitud++;
	   }else{
		   throw "Lista Vacia";
	   }
 }
 void Lista::Mostrar(int x,int y,TCanvas *Canvas)
 {
	 m->Mostrar(x,y,Canvas);
 }
 void Lista::Suprime(direccion p)
 {
  if (Vacio())
  {
	 //ShowMessage("Lista vac�a");
	 return;
  }
  else if (p==ptrElementos)
	{
		direccion x=ptrElementos;
		ptrElementos=m->Obtener_Dato(ptrElementos,"->sig");
		m->Delete_espacio(x);
	}
	else
	{
	 direccion ant=Anterior(p);
	 int sig=m->Obtener_Dato(p,"->sig");
	 m->Poner_dato(ant,"->sig",sig);
	 m->Delete_espacio(p);
  }
	longitud--;
 }
 void Lista::Modifica(direccion p,int dato)
 {
	 if (Vacio())
	 {
	   ShowMessage("Lista vac�a");
	 }
	 else
	 {
	   m->Poner_dato(p,"->elemento",dato);
	 }
 }

  int Lista::new_espacio(AnsiString variable){
	int x = m->new_espacio(variable);
	return x;
  }

  void Lista::Delete_espacio(int direccion){
	 m->Delete_espacio(direccion);
	 }

	 void Lista :: Mostrar_Lista(int x1, int y1,TCanvas *Canvas)
	 {
		AnsiString  aux ="";
		direccion x=Primero();
			for (int i=1;i<=longitud;i++) {
		  if(x != -1){
		  aux=aux+IntToStr(m->Obtener_Dato(x,"->elemento"))+",";
		   }
		  x=Siguiente(x);
		}
		aux=aux.Delete(aux.Length(),1);
		aux= " < " + aux + ">";
		Canvas->TextOut(x1,y1,aux) ;
	 }
	  int Lista :: Recupera(direccion x){
	  if (Vacio())
				 return 0;
	  else
	   return m->Obtener_Dato(x,"->elemento");
	 }
	 //-------------------------------------------------------------------------
		direccion  Lista :: Localiza (int e){
	  direccion x = ptrElementos;
	while (x != -1) {
		int x_elem = m->Obtener_Dato(x,"->elemento");
		if (x_elem == e)
				return x;
		x = m->Obtener_Dato(x,"->sig");
	}
	return -1;
	  }



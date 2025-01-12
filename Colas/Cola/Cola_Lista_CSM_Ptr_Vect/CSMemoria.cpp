//---------------------------------------------------------------------------

#pragma hdrstop

#include "CSMemoria.h"
#include<string>
//---------------------------------------------------------------------------
#pragma package(smart_init)

 CSMemoria::CSMemoria()
{
 for (int i=0; i < MAX ; i++) {
   MEM[i].Asignado=false;
   MEM[i].Link = i+1;
   MEM[i].Dato = 0;
 }
 MEM[MAX].Dato = 0;
 MEM[MAX].Link=-1;
 MEM[MAX].Asignado=false;
 libre=0;
}

int CSMemoria::cant_id(AnsiString ids)
{
int cant=0;
int pos;
	if (ids!="")
	{
	  ids=ids+",";
	 while (ids!="")
		 {
			 cant++;
			 pos=ids.Pos(",");
			 ids=ids.Delete(1,pos);

         }
	}
	return cant;
}
bool   CSMemoria::Dir_Libre(int direccion)
{
	int x=libre;
	bool b=false;
	while (x != -1 && b==false)
	{
	  if (x==direccion)
	  {
		  b=true;
	  }
      x=MEM[x].Link;
    }
 return b;
}
AnsiString CSMemoria:: obtener_id(AnsiString ids,int num)
{
AnsiString ID="";
if (ids!="")
  {
	ids=ids+",";
	for (int i=1; i < num; i++) {
		ids.Delete(1,ids.Pos(","));
	}
	ID=ids.SubString(1,ids.Pos(",")-1);
  }
return ID ;
}

void CSMemoria::EliminarFlecha( AnsiString& cad)
{
    cad.Delete(1,2);
}
int CSMemoria::new_espacio(AnsiString cadena)
{

   if (cant_id(cadena) > Espacio_Disponible())
   {
   ShowMessage("Espacio no disponible");
   return -1;
   }
   else
   {
    int num_id = cant_id(cadena);
	int dir=libre;
	int d=libre;
	for (int i=1; i < num_id; i++) {
	MEM[d].id=obtener_id(cadena,i);
	d=MEM[d].Link;
	}
	libre=MEM[d].Link;
	MEM[d].Link=-1;
	MEM[d].id=obtener_id(cadena,num_id);
	return dir;
   }
}


void CSMemoria::Delete_espacio(int _dir)
{
   int x =_dir;
   while (MEM[x].Link != -1)
	   {

		//MEM[x].Asignado = false;   //
		//MEM[x].id ="";                  //
			x=MEM[x].Link;
	   }
	   MEM[x].Link=libre;
	  // MEM[x].Asignado = false;    //
	  // MEM[x].id ="";             //
	   libre= _dir;
}
void CSMemoria::Poner_dato(int _dir,AnsiString _id,int _dato)
{
int x=_dir;
EliminarFlecha( _id);
 while (x!= -1)
	 {
		 if (MEM[x].id == _id)
		 {
		   MEM[x].Asignado = true;
		   MEM[x].Dato = _dato;
		 }
         x=MEM[x].Link;
	 }

}
int CSMemoria::Obtener_Dato(int _dir ,AnsiString ids)
{
	int x = _dir;
	EliminarFlecha(ids);
	if (!Dir_Libre(x)) {


	while (x != -1)
	{
		if (MEM[x].id == ids) {
			return MEM[x].Dato;
		}
		x=MEM[x].Link;
	}
			}else throw "No Existe";
}
int CSMemoria ::Espacio_Disponible()
{
	int c=0;
	int x=libre;
	while ( x!= -1)
		{
		  c++;
		  x=MEM[x].Link;
		}
	return c;

}
int CSMemoria ::Espacio_Ocupado()
{
  int d=MAX-Espacio_Disponible()+1;
  return d;
}


int CSMemoria::Mayor_Tam(int direccion)
{
int tam_id = MEM[direccion].id.Length()*10;
AnsiString dato = MEM[direccion].Dato;
int tam_dato = dato.Length()*13;
 if (tam_id > tam_dato)
	 return tam_id;
 else
     return tam_dato;

}


void CSMemoria::Mostrar(int x1,int y1,TCanvas *Canvas)
{    AnsiString Libre=libre;
	Canvas->Brush->Color=clBtnFace;
	int x=100;
	int h=30;
	Canvas->TextOut(x1-25,y1-20,"dir");
	Canvas->TextOut(x1+25,y1-20,"dato");
	Canvas->TextOut(x1+x+25,y1-20,"id");
	Canvas->TextOut(x1+2*x+25,y1-20,"link");
  for (int i=1; i <=MAX+1; i++)
  {   Canvas->TextOut(x1-20,y1+8,i-1);
	  Canvas->Brush->Color=clAqua;
	  Canvas->Rectangle(x1,y1,x1+x,y1+h);
	  if (MEM[i-1].Asignado)
				   {
				   Canvas->TextOut(x1+5,y1+8,MEM[i-1].Dato);
				   }
	  Canvas->Brush->Color=clYellow;
	  Canvas->Rectangle(x1+x,y1,x1+2*x,y1+h);
	  Canvas->TextOut(x1+x+5,y1+8,MEM[i-1].id);
	  Canvas->Rectangle(x1+2*x,y1,x1+3*x,y1+h);
	  Canvas->TextOut(x1+2*x+5,y1+8,MEM[i-1].Link);
	  y1=y1+h;
	  Canvas->Brush->Color=clBtnFace;
  }
	Canvas->TextOut(x1,y1+10,"LIBRE : " + Libre +"  " );


}

void CSMemoria::MostrarRango(int x1,int y1,int inicio,int fin,TCanvas *Canvas)
{
  AnsiString Libre=libre;
	Canvas->Brush->Color=clSkyBlue;
	int rango = fin-inicio+1;
	int x=100;
	int h=30;
	Canvas->Rectangle(0,0,1600,1080);
	Canvas->TextOut(x1-25,y1-20,"dir");
	Canvas->TextOut(x1+25,y1-20,"dato");
	Canvas->TextOut(x1+x+25,y1-20,"id");
	Canvas->TextOut(x1+2*x+25,y1-20,"link");
    Canvas->Brush->Color=clWhite;
	Canvas->Rectangle(x1-40,y1,x1,y1+rango*h);
  for (int i=1; i <=rango; i++)
  {  Canvas->Brush->Color=clWhite;
	 Canvas->TextOut(x1-20,y1+8,inicio);
	  Canvas->Brush->Color=clGreen;
	  Canvas->Rectangle(x1,y1,x1+x,y1+h);
	  if (MEM[inicio].Asignado)
				   {
				   Canvas->TextOut(x1+5,y1+8,MEM[inicio].Dato);
				   }
	  Canvas->Brush->Color=clYellow;
	  Canvas->Rectangle(x1+x,y1,x1+2*x,y1+h);
	  Canvas->TextOut(x1+x+5,y1+8,MEM[inicio].id);
	  Canvas->Rectangle(x1+2*x,y1,x1+3*x,y1+h);
	  Canvas->TextOut(x1+2*x+5,y1+8,MEM[inicio].Link);
	  y1=y1+h;
	  Canvas->Brush->Color=clBtnFace;
	  inicio++;
  }
		Canvas->Brush->Color=clSkyBlue;
	Canvas->TextOut(x1,y1+10,"LIBRE : " + Libre +"  " );
}
void CSMemoria::Mostrar_Direccion(int x1,int y1,int direccion,TCanvas *Canvas)
{

 if (!Dir_Libre(direccion))

 {
   Canvas->Brush->Color=clBtnFace;
	 Canvas->TextOut(x1,y1-19,direccion);
	 int x=direccion;
	 int d;
	 int h=30;
	 while (x !=-1)
		 {   d=Mayor_Tam(x);
			 Canvas->Brush->Color=clAqua;
			 Canvas->Rectangle(x1,y1,x1+d,y1+h);
			 if (MEM[x].Asignado)
			 Canvas->TextOut(x1+3,y1+8,MEM[x].Dato);
             Canvas->Brush->Color=clBtnFace;
			 Canvas->TextOut(x1+2,y1+h+3,MEM[x].id);
			 x1=x1+d;
             x=MEM[x].Link;
		 }
 }
}









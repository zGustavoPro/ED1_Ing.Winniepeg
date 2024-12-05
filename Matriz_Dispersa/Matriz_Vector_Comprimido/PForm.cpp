//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
 v=new Matriz_VComprimido();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
 int f = StrToInt(InputBox("Cantidad de Filas","",""));
 int c = StrToInt(InputBox("Cantidad de Columnas","",""));
 v->dimensionar(f,c);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
  int dato = StrToInt(InputBox(" Ingrese Valor","",""));
  v->definir_ValorRepetido(dato);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
 int f = StrToInt(InputBox("Fila","",""));
 int c = StrToInt(InputBox("Columna","",""));
 int dato = StrToInt(InputBox(" Ingrese Valor","",""));
 v->poner(f,c,dato);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
  v->Mostrar_MComprimida(200,60,Canvas);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------


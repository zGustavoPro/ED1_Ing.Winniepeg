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
mat = new Matriz_Ptr2N();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
int f=StrToInt(InputBox("Cantidad de Filas","",""));
int c=StrToInt(InputBox("Cantidad de Columnas","",""));
mat->dimensionar(f,c);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
 int valor=StrToInt(InputBox("Asignar Valor ","",""));
 mat->definir_valor_repetido(valor);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
int f=StrToInt(InputBox("Fila","",""));
int c=StrToInt(InputBox("Columna","",""));
int valor=StrToInt(InputBox("Valor ","",""));
mat->poner(f,c,valor);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
 mat->Mostrar_Matriz(300,80,Canvas);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------

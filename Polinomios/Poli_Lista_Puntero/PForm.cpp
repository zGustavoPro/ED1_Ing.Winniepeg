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
void __fastcall TForm1::Button5Click(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
pol = new Lista_Ptr();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
int coef=StrToInt(InputBox("Ingrese Coeficiente","",""));
int expo=StrToInt(InputBox("Ingrese Exponente","",""));
pol->Poner_Termino(coef,expo);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
//int x=StrToInt(InputBox("posicion en X","",""));
//int y=StrToInt(InputBox("posicion en Y","",""));
pol->Mostrar(400,80,Canvas);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
pol->Derivar();
}
//---------------------------------------------------------------------------

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
v=new Pila_Vector();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
int e=StrToInt(InputBox("Elemento","",""));
v->meter(e);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
v->mostrar_Pila(200,60,Canvas);
v->mostrarVector(300,60,Canvas);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------

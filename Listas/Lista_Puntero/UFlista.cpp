//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFlista.h"
#include "PtrLista.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
    l1=new PtrLista;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
l1->Inserta_Primero(StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{
l1->Inserta_Ultimo(StrToInt(Edit2->Text));
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button4Click(TObject *Sender)
{
l1->Dibujar(200,400,Canvas);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button5Click(TObject *Sender)
{
Form2->Close();
}
//---------------------------------------------------------------------------


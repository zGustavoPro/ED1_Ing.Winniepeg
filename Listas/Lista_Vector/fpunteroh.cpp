//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "fpunteroh.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
l1 = new VecLista ;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button2Click(TObject *Sender)
{
  l1->Inserta_Primero(StrToInt(Edit1->Text));
 // Edit1->Text="";

}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button3Click(TObject *Sender)
{
l1->Inserta_Ultimo(StrToInt(Edit2->Text));
  //Edit2->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button4Click(TObject *Sender)
{
l1->Dibuja(200,400,Canvas);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button5Click(TObject *Sender)
{
 Form3->Close();
 //l1->anula();
}
//---------------------------------------------------------------------------


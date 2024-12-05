//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Practico_Memoria.h"
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
 memory= new CSMemoria();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
  memory->new_espacio(Edit1->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
  memory->Delete_espacio(StrToInt(Edit2->Text));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
  memory->MostrarRango(700,50,StrToInt(Edit3->Text),StrToInt(Edit4->Text),Canvas);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
 memory->Poner_dato(StrToInt(Edit5->Text),Edit6->Text,StrToInt(Edit7->Text));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
int n=memory->Obtener_Dato(StrToInt(Edit8->Text),Edit9->Text)+5;
   memory->Poner_dato(StrToInt(Edit8->Text),Edit9->Text,n);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------


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
void __fastcall TForm1::Button8Click(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
pol->crear_CSM();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
pol= new Pol_CSM();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
pol->new_espacio(Edit1->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
pol->delete_espacio(StrToInt(Edit2->Text));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
int coe=StrToInt(Edit3->Text);
int exp=StrToInt(Edit4->Text);
pol->Poner_Termino(coe,exp);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
 int a=StrToInt(InputBox("Rango a","",""));
 int b=StrToInt(InputBox("Rango b","",""));
  pol->MostrarPol(500,80,Canvas);
 pol->CordenadasXY(a,b,Canvas);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
pol->Derivar();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
int dir=StrToInt(StrToInt(Edit5->Text));
AnsiString id=Edit6->Text;
int dato= StrToInt(StrToInt(Edit7->Text));
pol->Poner_Dato(dir,id,dato);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
 pol->MostrarCSM(500,80,Canvas);
}
//---------------------------------------------------------------------------


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
m=new CSMemoria();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
colaP=new ColadePrioridad(m);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
int e=StrToInt(InputBox("Elemento","",""));
int prio=StrToInt(InputBox("cola ?","",""));
colaP->poner(e,prio);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
   Form1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
colaP->mostrar(200,60,Canvas);
//m->MostrarRango(450,60,0,10,Canvas);
}
//---------------------------------------------------------------------------
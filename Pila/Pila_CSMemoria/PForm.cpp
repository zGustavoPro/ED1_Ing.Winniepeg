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
m = new CSMemoria();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
int e=StrToInt(InputBox("Nuevo Espacio","",""));
m->new_espacio(e);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
pila=new Pila_CSMemoria(m);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
 int e=StrToInt(InputBox("elemento","",""));
 pila->meter(e);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
int a=StrToInt(InputBox("desde","",""));
int b=StrToInt(InputBox("hasta","",""));
m->MostrarRango(300,80,a,b,Canvas);
//pila->mostrar(650,80,Canvas);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
conj=new Conjunto_CSM(m);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
int e=StrToInt(InputBox("elemento","",""));
conj->Inserta(e);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
conj->Mostrar_Conjuntos("A",700,80,Canvas);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button10Click(TObject *Sender)
{
AnsiString cad=InputBox("ingrese el ejercicio a resolver","","");
AnsiString cad2=pila->postfija(cad.c_str()).c_str();
ShowMessage(cad2);
ShowMessage(pila->evaluar_PosFija(cad2));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button11Click(TObject *Sender)
{
  AnsiString cad=InputBox("ingrese el ejercicio a resolver","","");
  AnsiString cad2=pila->prefija(cad.c_str()).c_str();
  ShowMessage(cad2);
  ShowMessage(pila->evaluar_PreFija(cad2));
}
//---------------------------------------------------------------------------


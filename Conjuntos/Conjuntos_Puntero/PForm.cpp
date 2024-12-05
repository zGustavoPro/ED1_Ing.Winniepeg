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
 A = new CC_Puntero();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
B = new CC_Puntero();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
 C=new CC_Puntero();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
   int conj=StrToInt(InputBox("A que Conjuno desea Agregar","Conjunto A=1,B=2,C=3 ?",""));
int ele=StrToInt(InputBox("Ingrese el Elemento","",""));
switch (conj) {
  case 1:
   A->Inserta(ele);
  break;
  case 2:
  B->Inserta(ele);
  break;
  case 3:
  C->Inserta(ele);
  break;
  default:
   ShowMessage("Número de conjunto no válido. Por favor, ingrese 1, 2 o 3.");
	break;
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
   int conj=StrToInt(InputBox("Que Conjunto Desea Ver ?","Conjunto : A=1,B=2,C=3 ?",""));
	switch (conj) {
  case 1:
   A->Mostrar_Conjuntos("A",200,80,Canvas);
  break;
  case 2:
  B->Mostrar_Conjuntos("B",200,120,Canvas);
  break;
  case 3:
  C->Mostrar_Conjuntos("C",200,160,Canvas);
  break;
  default:
   ShowMessage("Número de conjunto no válido. Por favor, ingrese 1, 2 o 3.");
	break;
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
  A->Union(B,C);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
    A->Interseccion(B,C);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
 Form1->Close();
}
//---------------------------------------------------------------------------

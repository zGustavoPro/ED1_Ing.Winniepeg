//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PFUnid.h"
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
  m=new CSMemoria();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
 poli=new Poli_CSM(m);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
 poli->Poner_Termino(StrToInt(InputBox("ingrese coex","","")),StrToInt(InputBox("ingrese expo","","")));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
 poli->Derivar();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
 int a=StrToInt(InputBox("Rango a","",""));
 int b=StrToInt(InputBox("Rango b","",""));
 poli->CordenadasXY(a,b,Canvas);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
  m->Mostrar(200,80,Canvas);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
   poli->Mostrar_Polinomio(200,400,Canvas);
   poli->Mostrar_Lista(200,550,Canvas);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button10Click(TObject *Sender)
{
 Form1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
 int dir=StrToInt(InputBox("Liberar Espacio","",""));
 m->Delete_espacio(dir);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
 m->new_espacio(InputBox("pedir espacio","",""));
}
//---------------------------------------------------------------------------

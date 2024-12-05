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
 m = new CSMemoria();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
pol = new Pol_CSM(m);
//pol2 = new Pol_CSM(m);
//pol3=new Pol_CSM(m);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
m->new_espacio(Edit1->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
m->Delete_espacio(StrToInt(Edit2->Text));
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
 //polinomio dos
 //pol2->Poner_Termino(1,3);
 //  pol2->MostrarPol(500,120,Canvas);
   //pol2->CordenadasXY(-4,5,Canvas);
   //polinomio 3
   //pol3->Poner_Termino(-1,8);
   //pol3->MostrarPol(500,160,Canvas);
   //pol3->CordenadasXY(-4,5,Canvas);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
 int x1 = 1150;
	int y1 = 20;
    Canvas->Brush->Color = clBtnFace;
	TRect area(x1 - 200, 0, x1 + 200, y1 + 500);
	Canvas->FillRect(area);
	 pol->Derivar();
  //pol->DerivarP(pol2);
 //pol2->Derivar();
 //pol3->Derivar();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
int dir=StrToInt(StrToInt(Edit5->Text));
AnsiString id=Edit6->Text;
int dato= StrToInt(StrToInt(Edit7->Text));
m->Poner_dato(dir,id,dato);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
 m->Mostrar(500,80,Canvas);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
 pol2 = new Pol_CSM(m);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{
int coef=StrToInt(InputBox("ingrese coeficiente","",""));
int expo=StrToInt(InputBox("ingrese expo","",""));
pol2->Poner_Termino(coef,expo);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
 int a=StrToInt(InputBox("Rango a","",""));
 int b=StrToInt(InputBox("Rango b","",""));
 pol2->CordenadasXY(a,b,Canvas);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button14Click(TObject *Sender)
{
pol->Poner_Termino(1,1);
pol2->Poner_Termino(-1,1);
pol->punto(pol2);
}
//---------------------------------------------------------------------------


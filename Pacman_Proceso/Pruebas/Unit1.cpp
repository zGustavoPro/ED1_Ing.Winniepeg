//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
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
mat = new Matriz_Ptr1N();
//Edit1->Text=StrToInt(mat->numeroRandom());
}
//---------------------------------------------------------------------------
bool pertenece(int n){
   AnsiString s="34,2,6";
  if (s=="") {
	 throw "Cadena vacia";
  } else { AnsiString cad=s+",";
  while(cad != ""){
  int x=StrToInt(cad.SubString(1,cad.Pos(",")-1));
  cad.Delete(1,cad.Pos(","));
  if (x==n) {
  return true;
  }
  }
   return false;
  }
  }
void __fastcall TForm1::Button2Click(TObject *Sender)
{
//mat->cargarFantasmas();
 // mat->recorrerFantasmaIzquierda(mat->getFilFantasma1(),mat->getColFantasma1()-1,4);
 mat->moverFantasmas(4);
 mat->Mostrar_Matriz(300,80,Canvas);
 mat->moverFantasmas(5);
 mat->Mostrar_Matriz(300,80,Canvas);
  mat->moverFantasmas(6);
  mat->Mostrar_Matriz(300,80,Canvas);
  mat->moverFantasmas(7);
  mat->Mostrar_Matriz(300,80,Canvas);
//mat->activarFantasmas();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
mat->dimensionar(15,15);
mat->setColPacman(4);
mat->setFilPacman(4);
mat->cargarMuros();
mat->cargarMonedas();
mat->cargarFantasmas();
mat->Mostrar_Matriz(300,80,Canvas);
//Timer1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)    //Arriba
{
int fil=mat->getFilPacman()-1;
int col=mat->getColPacman();
mat->recorrerArriba(fil,col);
mat->Mostrar_Matriz(300,80,Canvas);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)     //Abajo
{
int fil=mat->getFilPacman()+1;
int col=mat->getColPacman();
mat->recorrerAbajo(fil,col);
mat->Mostrar_Matriz(300,80,Canvas);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)    //Izquierda
{
int fil=mat->getFilPacman();
int col=mat->getColPacman()-1;
mat->recorrerIzquierda(fil,col);
mat->Mostrar_Matriz(300,80,Canvas);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)   //Derecha
{
int fil=mat->getFilPacman();
int col=mat->getColPacman()+1;
mat->recorrerDerecha(fil,col);
mat->Mostrar_Matriz(300,80,Canvas);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
mat->activarFantasmas();
}
//---------------------------------------------------------------------------


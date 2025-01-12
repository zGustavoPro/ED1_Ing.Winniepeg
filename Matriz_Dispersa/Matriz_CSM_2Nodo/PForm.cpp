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
   m->new_espacio(InputBox("Nuevo Espacio","",""));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
   int dir= StrToInt(InputBox("Ingrese la direcion a eliminar",""," "));
   m->Delete_espacio(dir);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
   mat=new Matriz_CSM2N(m);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
  int f= StrToInt(InputBox("Cantidad de Filas",""," "));
  int c= StrToInt(InputBox("Cantidad de Columnas",""," "));
  mat->dimensionar(f,c);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
 int valor= StrToInt(InputBox("Asignar Valor Repetido",""," "));
 mat->definir_ValorRepetido(valor);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
   int f= StrToInt(InputBox("Fila",""," "));
   int c= StrToInt(InputBox("Columna",""," "));
   int valor= StrToInt(InputBox("Valor",""," "));

   mat->poner(f,c,valor);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
	mat->Mostrar_Matriz(200,60,Canvas);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
  Form1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button10Click(TObject *Sender)
{
mat->EsSudoku();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
mat->retrocederPila();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
 int a=StrToInt(InputBox("Mostrar  Memoria desde","",""));
int b=StrToInt(InputBox("Hasta","",""));
m->MostrarRango(550,60,a,b,Canvas);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
   if (Shift.Contains(ssCtrl) && Key == 'Z')
	{
		Button11Click(Sender);
		mat->Mostrar_Matriz(200,60,Canvas);
	}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button13Click(TObject *Sender)
{
mat->backTracking_Sudoku();
}
//---------------------------------------------------------------------------


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
int dir=StrToInt(InputBox("Liberar Espacio","",""));
m->Delete_espacio(dir);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
mat = new Matriz_CSM(m);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
 int rep=StrToInt(InputBox("Definir Valor Repetido","",""));
 mat->definir_ValorRepetido(rep);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
int f=StrToInt(InputBox("Dimensionar Fila","",""));
int c=StrToInt(InputBox("Dimensionar Columna","",""));
mat->dimensionar(f,c);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
int f=StrToInt(InputBox("Fila","",""));
int c=StrToInt(InputBox("Columna","",""));
int e=StrToInt(InputBox("Elemento","",""));
mat->poner(f,c,e);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
mat->Mostrar_Matriz(200,60,Canvas);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
int a=StrToInt(InputBox("Mostrar  Memoria desde","",""));
int b=StrToInt(InputBox("Hasta","",""));
m->MostrarRango(550,60,a,b,Canvas);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
if(mat->EsSudoku())
ShowMessage("Es Sudoku , Ganaste !!");
else ShowMessage("No es Sudoku,Perdiste!!");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
mat->retrocederPila();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
Form1->Close();
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
mat->Mostrar_Matriz(200,60,Canvas);
}
//---------------------------------------------------------------------------


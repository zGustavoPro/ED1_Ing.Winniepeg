//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Menu_Principal.h"
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
	Form2->Show();
	Form2->cargarNivel_0();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
Form2->Show();
Form2->nombre_Nivel_Abrir("C:\\Universidad_Gustavo\\2-2024\\E.Datos l\\Pacman\\Niveles_Guardados\\Nivel_0.txt");
}
//---------------------------------------------------------------------------


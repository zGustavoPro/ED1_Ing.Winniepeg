//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MenuPCM.h"
#include "Play_Niveles.h"
#include "Menu_Principal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button3Click(TObject *Sender)
{
Form3->Close();
Form2->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button4Click(TObject *Sender)
{
Form3->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button2Click(TObject *Sender)
{
Form2->reiniciar();
Form3->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button1Click(TObject *Sender)
{
Form2->Guardar("C:\\Universidad_Gustavo\\2-2024\\E.Datos l\\Pacman\\Niveles_Guardados\\Nivel_0.txt");
}
//---------------------------------------------------------------------------


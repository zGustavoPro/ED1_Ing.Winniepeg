//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Play_Niveles.h"
#include "MenuPCM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
m=new CSMemoria();
mat=new Matriz_CSM(m);
nivel=new GuardarNiveles(m,mat);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Menu1Click(TObject *Sender)
{
Form3->Show();
}
//---------------------------------------------------------------------------
void TForm2 :: cargarNivel_0(){
mat->cargarNivel_0();
//mat->Mostrar_Matriz(200,80,Canvas);
mat->Mostrar_MapaP(50,80,Canvas);
}

void TForm2 :: nombre_Nivel_Abrir(AnsiString nom){
nivel->setNom(nom);
nivel->abrir();
mat->Mostrar_MapaP(50,80,Canvas);
}

void TForm2 :: Guardar(AnsiString nom){
nivel->setNom(nom);
 nivel->Guardar();
}
//---------------------------------------------------------------------------
void TForm2 :: reiniciar(){
 m=new CSMemoria();
  mat=new Matriz_CSM();
   mat->cargarNivel_0();
	mat->Mostrar_MapaP(50,80,Canvas);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{


 if (Shift.Contains(ssCtrl) && Key=='Z') {
	mat->retrocederPila();
	  //	mat->Mostrar_Matriz(200,80,Canvas);
	  mat->Mostrar_MapaP(50,80,Canvas);
 } else if(Key==27){
 Form3->Show();

 }

		 switch (Key) {
			case  33 ://VK_UP:
			case  'W' :
				mat->recorrerArriba(mat->getFilPacman() - 1, mat->getColPacman());
				 //	mat->Mostrar_Matriz(200,80,Canvas);
				 mat->Mostrar_MapaP(50,80,Canvas);
				break;

			case  34  : // VK_DOWN:
			case  'S' :
				mat->recorrerAbajo(mat->getFilPacman() + 1, mat->getColPacman());
				   //	mat->Mostrar_Matriz(200,80,Canvas);
                mat->Mostrar_MapaP(50,80,Canvas);
				break;

			case 36  :   //VK_LEFT:
			case 'A' :
				mat->recorrerIzquierda(mat->getFilPacman(), mat->getColPacman() - 1);
				  //	mat->Mostrar_Matriz(200,80,Canvas);
				  mat->Mostrar_MapaP(50,80,Canvas);
				break;

			case 35  ://VK_RIGHT:
			case 'D' :
				mat->recorrerDerecha(mat->getFilPacman(), mat->getColPacman() + 1);
					//mat->Mostrar_Matriz(200,80,Canvas);
					mat->Mostrar_MapaP(50,80,Canvas);
				break;

			default:
				break;
		}

}
//---------------------------------------------------------------------------


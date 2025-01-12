//---------------------------------------------------------------------------

#ifndef Play_NivelesH
#define Play_NivelesH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>

#include "CSMemoria.h"
#include "CM_CSM_1N.h"
#include "Guardar.h"
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *Menu1;
	void __fastcall Menu1Click(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
private:	// User declarations
Matriz_CSM* mat;
CSMemoria* m;
GuardarNiveles* nivel;
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
	void cargarNivel_0();
	void reiniciar();
	void nombre_Nivel_Abrir(AnsiString);
	void Guardar(AnsiString);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif

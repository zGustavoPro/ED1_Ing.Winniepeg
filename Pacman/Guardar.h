//---------------------------------------------------------------------------

#ifndef GuardarH
#define GuardarH

#include <fstream>
#include "CSMemoria.h"
#include "CM_CSM_1N.h"
//---------------------------------------------------------------------------
class GuardarNiveles{
  private :
	CSMemoria* m;
	Matriz_CSM* mat;
	AnsiString nom;
  public :
	GuardarNiveles(CSMemoria*,Matriz_CSM*);
	void setNom(AnsiString);
	AnsiString getNom();
	void Guardar();
	void eliminar();
	void abrir();
};
#endif

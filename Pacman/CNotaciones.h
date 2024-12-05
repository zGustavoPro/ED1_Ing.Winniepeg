//---------------------------------------------------------------------------

#ifndef CNotacionesH
#define CNotacionesH
#include "CP_CSMemoria.h"
#include "CSMemoria.h"
//---------------------------------------------------------------------------
class Notaciones{
	private :
	Pila_CSMemoria *pila;
	public :
	Notaciones(CSMemoria*);
	Notaciones();
	double evaluar_PosFija(AnsiString);
	double evaluar_PreFija(AnsiString);
	double evaluar(int,char,int);
	bool esOperador(char);
	int prioridad(char);
	string invertido(string);
	string postfija(string);
	string prefija(string);
	bool parentesisOk(string);
};
#endif

//---------------------------------------------------------------------------

#ifndef PtrListaH
#define PtrListaH
#include "vcl.h"
//---------------------------------------------------------------------------

struct NodoL
{
	int elemento;
	NodoL* sig;
};
typedef NodoL* Direccion;
class PtrLista{
private:
Direccion ptrElementos;
int longitud;

public:
PtrLista();
Direccion Fin();
Direccion Primero();
Direccion Siguiente(Direccion);
Direccion Anterior(Direccion);

Direccion  Localiza(int);
bool Vacio();
int Recupera(Direccion);
int Longitud();
void Inserta(Direccion,int);
void Inserta_Primero(int);
void Inserta_Ultimo(int);
void Suprime(Direccion);
void Modifica(Direccion,int);


void Dibujar(int,int,TCanvas* Canvas);

};
#endif

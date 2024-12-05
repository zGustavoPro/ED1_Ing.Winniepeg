//---------------------------------------------------------------------------

#ifndef ListaH
#define ListaH
#include <CSMemoria.h>
#include <vcl.h>
//---------------------------------------------------------------------------
typedef int direccion ;
class Lista
{
   private:
   CSMemoria *m;
   direccion ptrElementos ;
   int longitud;

   public:
	Lista();
	Lista(CSMemoria*);

	direccion Fin();
	direccion Primero();
	direccion Siguiente(direccion);
	direccion Anterior(direccion);

	 int new_espacio(AnsiString);
	 void Delete_espacio(int);

	direccion Localiza(int);
	bool Vacio();
	int Recupera(direccion);
	int Longitud();
	void Inserta(direccion,int);
	void Inserta_primero(int);
	void Inserta_ultimo(int);
	void Suprime(direccion);
	void Modifica(direccion,int);
	void Mostrar_Lista(int,int,TCanvas *Canvas);
	void Mostrar(int,int,TCanvas *Canvas);

};
#endif

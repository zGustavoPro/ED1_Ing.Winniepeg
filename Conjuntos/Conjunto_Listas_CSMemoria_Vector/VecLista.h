//---------------------------------------------------------------------------

#ifndef VecListaH
#define VecListaH
#include <vcl.h>
//---------------------------------------------------------------------------
 const int Max=100;
 typedef int direccion;

	class VecLista{
		private:
	int longitud;
	int lista[Max];
	public :
	VecLista();
	direccion Fin() ;
	direccion Primero() ;
	direccion Siguiente( direccion)   ;
	direccion Anterior( direccion) ;
	bool Vacio()   ;
	int Recupera(direccion)  ;
	int Longitud ()   ;
	void Inserta( direccion, int) ;
	void Inserta_Primero( int) ;
	void Inserta_Ultimo(int) ;
	void Suprime( direccion) ;
	void Modifica( direccion, int) ;
	void anula();
	direccion localiza(int);
	void elimina_Dato(int);

	void Dibuja(int,int,TCanvas *Canvas);
	};




#endif

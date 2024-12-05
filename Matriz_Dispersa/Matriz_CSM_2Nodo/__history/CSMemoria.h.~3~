//---------------------------------------------------------------------------
  #include <vcl.h>
#ifndef CSMemoriaH
#define CSMemoriaH
//---------------------------------------------------------------------------
const int MAX = 100;
 struct NodoM
  {
	  int Dato;
	  AnsiString id;
	  int Link;
	  bool Asignado;

  };
class CSMemoria
{
  private :
	NodoM  MEM [MAX] ;
	int libre;
	int dir;

	int cant_id(AnsiString);
	 void EliminarFlecha(AnsiString &);
	AnsiString obtener_id(AnsiString,int);

	public:
	 CSMemoria();
	 int new_espacio(AnsiString);
	 void Delete_espacio(int);
	 void Poner_dato(int,AnsiString,int);
	 int Obtener_Dato(int , AnsiString);
	 int Espacio_Disponible();
	 int Espacio_Ocupado();
	 int Mayor_Tam(int);
	 void Mostrar( int ,int ,TCanvas *Canvas);
	 void MostrarRango(int ,int ,int,int,TCanvas *Canvas);
	 bool Dir_Libre(int);
	 void Mostrar_Direccion( int ,int ,int,TCanvas *Canvas);



};

#endif

//---------------------------------------------------------------------------

#ifndef Class_Poli_PunteroH
#define Class_Poli_PunteroH
//---------------------------------------------------------------------------
struct NodoP {
	int coef;
	int exp;
	NodoP * sgt;
};
typedef NodoP *Direccion;

 class Poli_Puntero{
private :
 Direccion ptr_poli;
 int nt;

 Direccion Buscar_Exponente(int);
 Direccion Buscar_Terminos(int);

 public :
  Poli_Puntero();
  bool Escero();
  int Grado();
  int Coeficiente (int);
  void Asignar_Coeficiente(int,int);
  void Poner_Termino(int,int);
  int Numero_Terminos();
  int Exponente(int);
  void Suma(Poli_Puntero*,Poli_Puntero*);
  void Resta(Poli_Puntero*,Poli_Puntero*);
  void Multiplicar(Poli_Puntero*,Poli_Puntero*);
  void Derivar();
  Direccion Anterior(int);// devuelve la direccion anterior al exponente

  void Mostrar_Puntero(int,int,TCanvas *Canvas);




};

#endif

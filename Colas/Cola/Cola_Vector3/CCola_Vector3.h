//---------------------------------------------------------------------------

#ifndef CCola_Vector3H
#define CCola_Vector3H
//---------------------------------------------------------------------------
const int maxV3 = 10;

class Cola_Vector3 {
private:
	int* v;
	int ini, fin;
	int siguiente(int);
	int anterior(int);
public:
	Cola_Vector3();
	bool vacia();
	void poner(int);
	void sacar(int&);
	int primero();
	void mostrarV3(int,int,TCanvas*);
	// Metodos de dicola
	int ultimo();
	void sacar_final(int&);
	void poner_frente(int);
};
#endif

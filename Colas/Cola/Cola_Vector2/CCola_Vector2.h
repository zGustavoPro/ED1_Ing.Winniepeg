//---------------------------------------------------------------------------

#ifndef CCola_Vector2H
#define CCola_Vector2H
//---------------------------------------------------------------------------
const int maxV2 = 20;
class Cola_Vector2 {
private:
	int* v;
	int ini, fin;

public:
	Cola_Vector2();
	bool vacia();
	void poner(int);
	void sacar(int&);
	int primero();
	void mostrarV2(int,int,TCanvas*);
	// Metodos de dicola
	int ultimo();
	void sacar_final(int&);
	void poner_frente(int);

};
#endif

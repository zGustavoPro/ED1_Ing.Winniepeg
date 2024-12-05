//---------------------------------------------------------------------------

#ifndef CCola_PunteroH
#define CCola_PunteroH
//---------------------------------------------------------------------------
struct NodoCola {
	int elemento;
	NodoCola* sig;
};

typedef NodoCola* direccion;

class Cola_Ptr {
private:
	direccion ini;
	direccion fin;

public:
	Cola_Ptr();
	bool vacia();
	void poner(int e);
	void poner1(int e);
	void sacar(int &e);
	void sacar1(int &e);
	int primero();
	void mostrar_Ptr(int,int,TCanvas*);
	void mostrar(int,int,TCanvas*);
	// Metodos de dicola
	int ultimo();
	void sacar_final(int& e);
	void poner_frente(int e);
};
#endif

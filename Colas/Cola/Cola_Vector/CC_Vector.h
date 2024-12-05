//---------------------------------------------------------------------------

#ifndef CC_VectorH
#define CC_VectorH
//---------------------------------------------------------------------------
int const maxV1=10;
class Cola_Vector1{
private:
	int* v;
	int ini, fin;

public:
	Cola_Vector1();
	bool vacia();
	void poner(int);
	void sacar(int&);
	int primero();
	void mostrarV1(int,int,TCanvas*);
};
#endif

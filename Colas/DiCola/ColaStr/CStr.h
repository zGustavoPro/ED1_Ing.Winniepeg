//---------------------------------------------------------------------------

#ifndef CStrH
#define CStrH
#include "Funciones.h"
#include <string>
//---------------------------------------------------------------------------
using namespace std;
class ColaStr {
private:
	string s;
public:
	ColaStr();
	bool vacia();
	void poner(int e);
	void sacar(int &e);
	int primero();
	string toStr();
};
#endif

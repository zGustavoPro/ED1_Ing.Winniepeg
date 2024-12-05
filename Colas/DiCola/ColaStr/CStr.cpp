//---------------------------------------------------------------------------
#pragma hdrstop

#include "CStr.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
ColaStr::ColaStr() {
	s = "";
}
//---------------------------------------------------------------------------
bool ColaStr::vacia() {
	return s == "";
}
//---------------------------------------------------------------------------
void ColaStr::poner(int e) {
	s = s + to_string(e) + "_";
}
//---------------------------------------------------------------------------
void ColaStr::sacar(int &e) {
	if (!vacia()) {
		int pos = s.find_first_of("_");
		string ss = s.substr(0, pos);
		e = atoi(ss.c_str());
		s.erase(0, pos + 1);
	}
}
//---------------------------------------------------------------------------
int ColaStr::primero() {
	if (!vacia()) {
		int pos = s.find_first_of("_");
		string ss = s.substr(0, pos);
		return atoi(ss.c_str());
	}
}
//---------------------------------------------------------------------------
string ColaStr::toStr() {
	ColaStr* aux = new ColaStr();
	string s = "<<";
	while (!vacia()) {
		int e;
		sacar(e);
		aux->poner(e);
		s = s + to_string(e);
		if (!vacia())
			s = s + ",";
	}
	s = s + "<<";
	while (!aux->vacia()) {
		int e;
		aux->sacar(e);
		poner(e);
	}
	return s;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

#pragma hdrstop

#include "Cola_SM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
 //---------------------------------------------------------------------------
ColaSm::ColaSm() {
	m = new CSMemoria();
	ini = -1;
	fin = -1;
}
//---------------------------------------------------------------------------
ColaSm::ColaSm(CSMemoria* mem) {
	m = mem;
	ini = -1;
	fin = -1;
}
//---------------------------------------------------------------------------
bool ColaSm::vacia() {
	return ini == -1;
}
//---------------------------------------------------------------------------
void ColaSm::poner(int e) {
	direccion1 aux = m->new_espacio("elemento,sig");
	if (aux != -1) {
		m->Poner_dato(aux, "->elemento", e);
		m->Poner_dato(aux, "->sig", -1);
		if (vacia()) {
			ini = aux;
			fin = aux;
		}
		else {
			m->Poner_dato(fin, "->sig", aux);
			fin = aux;
		}
	}
}
//---------------------------------------------------------------------------
void ColaSm::sacar(int &e) {
	if (!vacia()) {
		e = m->Obtener_Dato(ini, "->elemento");
		direccion1 x = ini;
		if (ini == fin) {
			ini = -1;
			fin = -1;
		}
		else {
			ini = m->Obtener_Dato(ini, "->sig");
		}
		m->Delete_espacio(x);
	}
}
//---------------------------------------------------------------------------
int ColaSm::primero() {
	if (!vacia()) {
		return m->Obtener_Dato(ini, "->elemento");
	}
}
//---------------------------------------------------------------------------
void ColaSm :: mostrar(int x1,int y1,TCanvas* Canvas) {
	ColaSm* aux = new ColaSm();
	AnsiString s = "<<";
	while (!vacia()) {
		int e;
		sacar(e);
		aux->poner(e);
		s = s + AnsiString(e);
		if (!vacia())
			s = s + ",";
	}
	s = s + "<<";
	while (!aux->vacia()) {
		int e;
		aux->sacar(e);
		poner(e);
	}
    Canvas->TextOut(x1,y1,s);
}
//---------------------------------------------------------------------------
int ColaSm::ultimo() {
	if (!vacia()) {
		return m->Obtener_Dato(fin, "->elemento");
	}
}
//---------------------------------------------------------------------------
void ColaSm::sacar_final(int& e) {
	if (!vacia()) {
		e = m->Obtener_Dato(fin, "->elemento");
		direccion1 del = fin;
		if (ini == fin) {
			ini = -1;
			fin = -1;
		}
		else {
			direccion1 aux = ini;
			while (m->Obtener_Dato(aux, "->sig") != fin) {
				aux = m->Obtener_Dato(aux, "->sig");
			}
			fin = aux;
			m->Poner_dato(fin, "->sig", -1);
		}
		m->Delete_espacio(del);
	}
}
//---------------------------------------------------------------------------
void ColaSm::poner_frente(int e) {
	direccion1 aux = m->new_espacio("elemento,sig");
	if (aux != -1) {
		m->Poner_dato(aux, "->elemento", e);
		m->Poner_dato(aux, "->sig", -1);
		if (vacia()) {
			ini = aux;
			fin = aux;
		}
		else {
			m->Poner_dato(aux, "->sig", ini);
			ini = aux;
		}
	}
}
//---------------------------------------------------------------------------



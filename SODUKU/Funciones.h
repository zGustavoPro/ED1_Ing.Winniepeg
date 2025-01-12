//---------------------------------------------------------------------------

#ifndef FuncionesH
#define FuncionesH
//---------------------------------------------------------------------------
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int to_int(string s) {
	return atoi(s.c_str());
}

string to_stringg(int value) {
	if (value == 0)
		return "0";
	bool es_negativo = value < 0;
	string r = "";
	if (es_negativo)
		value *= -1;
	while (value != 0) {
		char c = value % 10 + 0x30;
		r = c + r;
		value = value / 10;
	}
	return es_negativo ? "-" + r : r;
}

void insertar_en_vector(int *vector, int n, int &k, int &elemento) {
	for (int i = n; i > k; i--) {
		vector[i] = vector[i - 1];
	}
	vector[k] = elemento;
}

void eliminar_posicion(int *v, int k, int nt) {
	for (int i = k; i < nt - 1; i++) {
		v[i] = v[i + 1];
	}
}

string toString(int *v, int n) {
	string r = "";
	for (int i = 0; i < n; i++)
		r += to_stringg(v[i]) + "\t";
	return r;
}
#endif

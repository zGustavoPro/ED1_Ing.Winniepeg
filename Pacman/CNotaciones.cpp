//---------------------------------------------------------------------------

#pragma hdrstop

#include "CNotaciones.h"
#include <cmath>
//---------------------------------------------------------------------------
#pragma package(smart_init)

Notaciones :: Notaciones(CSMemoria* mem){
pila=new Pila_CSMemoria(mem);
}

Notaciones :: Notaciones(){
pila=new Pila_CSMemoria();
}
//---------------------------------------------------------------------------
 double Notaciones::evaluar_PreFija(AnsiString expPreFija) {
	AnsiString signo = "+-/*^%";
	AnsiString cad = "0123456789";
	for (int i = expPreFija.Length(); i > 0; i--) {
		char c = expPreFija[i];
		if (cad.Pos(c) > 0) {
			pila->meter(StrToInt(c));
		} else if (esOperador(c)) {
			int op1, op2;
			pila->sacar(op1);
			pila->sacar(op2);
			double resultado = evaluar(op1, c, op2);
			pila->meter(resultado);
		}
	}
	int p;
	pila->sacar(p);
	return p;
}

//---------------------------------------------------------------------------
double Notaciones::evaluar_PosFija(AnsiString expPosFija) {
	AnsiString signo = "+-/*^%";
	AnsiString cad = "0123456789";
	for (int i = 1; i <= expPosFija.Length(); i++) {
		char c = expPosFija[i];
		if (cad.Pos(c) > 0) {
			pila->meter(StrToInt(c));
		} else if (esOperador(c)) {
			int op2, op1;
			pila->sacar(op2);
			pila->sacar(op1);
			double resultado = evaluar(op1, c, op2);
			pila->meter(resultado);
		}
	}
	int p;
	pila->sacar(p);
	return p;
}

//---------------------------------------------------------------------------
double Notaciones::evaluar(int x1, char signo, int x2) {
	switch (signo) {
		case '^': return pow(x1,x2);  //por si las moscas
		case '+': return x1 + x2;
		case '-': return x1 - x2;
		case '*': return x1 * x2;
		case '%': return x1 % x2;
		case '/':
			if (x2 != 0)
				return x1 / x2;
			else
				throw "Error: División por cero";
		default:
			throw "Error: Operador desconocido";
	}
}
//---------------------------------------------------------------------------
bool Notaciones :: esOperador(char c) {
	string op = "+-%*/^";
	int pos = op.find_first_of(c);
	return pos >= 0;
}
//---------------------------------------------------------------------------
int Notaciones :: prioridad(char operador) {
	switch (operador) {
	case '^':
		return 5;
	case '*':
	case '/':
		return 4;
	case '%':
		return 3;
	case '+':
	case '-':
		return 2;
	case '(':
	case ')':
		return 1;
	}
	return 0;
}
//---------------------------------------------------------------------------
string Notaciones :: postfija(string exp) {
	string res = "";
	for (int i = 0; i < exp.length(); i++) {
		char c = exp[i];
		if (c == '(')
			pila->meter(c);
		else if (c == ')') {
			int s;
			while (pila->cima() != '(') {
				pila->sacar(s);
				res += s;
			}
			pila->sacar(s);
		}
		else if (!esOperador(c)) // si es letra
				res += c;
		else {
			while (!pila->vacia() && prioridad(c) < prioridad(pila->cima())) {
				int s;
				pila->sacar(s);
				res += s;
			}
			pila->meter(c);
		}
	}
	while (!pila->vacia()) {
		int s;
		pila->sacar(s);
		res += s;
	}
	return res;
}
//---------------------------------------------------------------------------
string Notaciones :: invertido(string s) {
	string r = "";
	for (int i = 0; i < s.length(); i++)
		r = s[i] + r;
	return r;
}
//---------------------------------------------------------------------------
string Notaciones :: prefija(string exp) {
	string res = "";
	for (int i = exp.length() - 1; i >= 0; i--) {
		char c = exp[i];
		if (c == ')')
			pila->meter(c);
		else if (c == '(') {
			int s;
			while (pila->cima() != ')') {
				pila->sacar(s);
				res += s;
			}
			pila->sacar(s);
		}
		else if (!esOperador(c))
				res += c;
		else {
			while (!pila->vacia() && prioridad(c) < prioridad(pila->cima())) {
				int s;
				pila->sacar(s);
				res += s;
			}
			pila->meter(c);
		}
	}
	while (!pila->vacia()) {
		int s;
		pila->sacar(s);
		res += s;
	};
	return invertido(res);
}
//---------------------------------------------------------------------------
bool Notaciones :: parentesisOk(string cad){
 bool correcto = true;
	for (int i = 0; i < cad.length(); i++) {
		int s;
		char c = cad[i];
		if (c == '(')
			pila->meter(c);
		else if (c == ')') {
			if (pila->vacia()) {
				correcto = false;
				break;
			}
			pila->sacar(s);
		}
	}
	if (correcto && pila->vacia()) {
		ShowMessage("Parentesis corecto");
		return true;
   }	else  {
		ShowMessage("Parentesis incorrectos");
		return false;
   }
}
//---------------------------------------------------------------------------

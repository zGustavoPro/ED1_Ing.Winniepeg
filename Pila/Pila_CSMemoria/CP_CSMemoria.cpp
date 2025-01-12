//---------------------------------------------------------------------------

#pragma hdrstop

#include "CP_CSMemoria.h"
//---------------------------------------------------------------------------
Pila_CSMemoria :: Pila_CSMemoria() {
	m = new CSMemoria();
	tope = -1;
}
//---------------------------------------------------------------------------
Pila_CSMemoria :: Pila_CSMemoria(CSMemoria* mem) {
	m = mem;
	tope = -1;
}
//---------------------------------------------------------------------------
bool Pila_CSMemoria :: vacia() {
	return tope == -1;
}
//---------------------------------------------------------------------------
void Pila_CSMemoria :: meter(int e) {
	int aux = m->new_espacio("elemento,sig");
	if (aux != -1) {
		m->Poner_dato(aux, "->elemento", e);
		m->Poner_dato(aux, "->sig", tope);
		tope = aux;
	}
}
//---------------------------------------------------------------------------
void Pila_CSMemoria :: sacar(int &e) {
	if (!vacia()) {
		e = m->Obtener_Dato(tope, "->elemento");
		int sup = tope;
		tope = m->Obtener_Dato(tope, "->sig");
		m->Delete_espacio(sup);
	}
}
//---------------------------------------------------------------------------
int Pila_CSMemoria :: sacar() {
	if (!vacia()) {
		int e = m->Obtener_Dato(tope, "->elemento");
		int sup = tope;
		tope = m->Obtener_Dato(tope, "->sig");
		m->Delete_espacio(sup);
		return e;
	}
}
//---------------------------------------------------------------------------
int Pila_CSMemoria :: cima() {
	if (!vacia()) {
		return m->Obtener_Dato(tope, "->elemento");
	}
}
//---------------------------------------------------------------------------
void Pila_CSMemoria :: mostrar(int x1,int y1,TCanvas* Canvas) {
	Pila_CSMemoria* aux = new Pila_CSMemoria();
	while (!vacia()) {
		int e;
		sacar(e);
		aux->meter(e);
		Canvas->TextOut(x1,y1,"|  "+AnsiString(e)+"  |");
		y1+=25;
	}
	while (!aux->vacia()) {
		int e;
		aux->sacar(e);
		meter(e);
	}
}
//---------------------------------------------------------------------------

//Notaciones

//---------------------------------------------------------------------------
 double Pila_CSMemoria ::evaluar_PreFija(AnsiString expPreFija) {
	string num="";
	for (int i = expPreFija.Length(); i >=1; i--) {
		char c = expPreFija[i];
		if (isdigit(c)){
		num+=c;
	   } else if(!esOperador(c) && !isdigit(c) && !num.empty()){
			meter(stoi(num));
			num="";
		} else if (esOperador(c)) {
			int op1, op2;
			sacar(op1);
			sacar(op2);
			double resultado = evaluar(op1, c, op2);
			meter(resultado);
		}
	}
	int p;
	sacar(p);
	return p;
}

//---------------------------------------------------------------------------
 double Pila_CSMemoria ::evaluar_PosFija(AnsiString expPosFija) {
	string num="";
	for (int i = 1; i <= expPosFija.Length(); i++) {
		char c = expPosFija[i];
		if (isdigit(c)){
		num+=c;
	   } else if(!esOperador(c) && !isdigit(c) && !num.empty()){
			meter(stoi(num));
			num="";
		} else if (esOperador(c)) {
			int op2, op1;
			sacar(op2);
			sacar(op1);
			double resultado = evaluar(op1, c, op2);
			meter(resultado);
		}
	}
	int p;
	sacar(p);
	return p;
}
//---------------------------------------------------------------------------
double Pila_CSMemoria :: evaluar(int x1, char signo, int x2) {
	switch (signo) {
		case '^': return pow(x1,x2);
		case '+': return x1 + x2;
		case '-': return x1 - x2;
		case '*': return x1 * x2;
		case '%': return (x1) % (x2);
		case '/':
			if (x2 != 0)
				return x1 / x2;
			else
				throw "Error: Divisi�n por cero";
		default:
			throw "Error: Operador desconocido";
	}
}
//---------------------------------------------------------------------------
bool Pila_CSMemoria :: esOperador(char c) {
	string op = "+-%*/^";
	int pos = op.find_first_of(c);
	return pos >= 0;
}
//---------------------------------------------------------------------------
int Pila_CSMemoria :: prioridad(char operador) {
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
 string Pila_CSMemoria ::postfija(string exp) {
	string res = "",num = "";   int s;

	for (int i = 0; i < exp.length(); i++) {
		char c = exp[i];
		if (c == '(') {
			meter(c);
		} else if (c == ')') {
			while (!vacia() && cima() != '(') {
				sacar(s);
				res += s;
			}
			sacar(s);
		} else if (!esOperador(c)) {
			num += c;
		} else {
			if (!num.empty()) {
				res += num + ",";
				num = "";
			}
			while (!vacia() && prioridad(c) <= prioridad(cima())) {
				sacar(s);
				res += s;
				res += ",";
			}
			meter(c);
		}
	}
		if (!num.empty()) {
		res += num + ",";
		}

	while (!vacia()) {
		sacar(s);
		res += s;
		res += ",";
	}

	if (!res.empty() && res.back() == ',') {
		res.pop_back();
	}

	return res;
}

	/*
  string Pila_CSMemoria :: postfija(string infija) {
	string PostFija = "";
	string num = "";
	int aux;
	for (int i = 0; i < infija.length(); i++) {
		char c = infija[i];
		if (isdigit(c)) {
			num += c;
		} else {
			if (!num.empty()) {
				PostFija += num + ",";
				num = "";
			}
			if (esOperador(c)) {
				bool salir = false;
				aux = cima();
				while (!salir) {
					if (vacia() || prioridad(c) > prioridad(aux)) {
						meter(c);
						salir = true;
					} else {
						sacar(aux);
						PostFija += aux;
						PostFija += ",";
					}
				}
			} else if (c == ')') {
				do {
					sacar(aux);
					if (aux != '(') {
						PostFija += aux;
						PostFija += ",";
					}
				} while (aux != '(');
			} else if (c == '(') {
				meter(c);
			}
		}
	}
	if (!num.empty()) {
		PostFija += num + ",";
	}
	while (!vacia()) {
		sacar(aux);
		PostFija += aux;
		PostFija += ",";
	}
	if (!PostFija.empty() && PostFija.back() == ',') {
		PostFija.pop_back();
	}
	return PostFija;
}
	 */
//---------------------------------------------------------------------------
string Pila_CSMemoria :: invertido(string s) {
	string r = "";
	for (int i = 0; i < s.length(); i++)
		r = s[i] + r;
	return r;
}

//---------------------------------------------------------------------------
string Pila_CSMemoria::prefija(string exp) {
	string res = "";
	string num = "";
	for (int i = exp.length() - 1; i >= 0; i--) {
		char c = exp[i];
		if (isdigit(c)) {
			num = c+num;
		} else {
			if (!num.empty()) {
				res += num + ",";
				num = "";
			}
			if (c == ')') {
				meter(c);
			} else if (c == '(') {
				int s;
				while (cima() != ')') {
					sacar(s);
					res += (char)s;
					res += ",";
				}
				sacar(s);
			} else if (esOperador(c)) {
				while (!vacia() && prioridad(c) < prioridad(cima())) {
					int s;
					sacar(s);
					res += (char)s;
					res += ",";
				}
				meter(c);
			}
		}
	}
	if (!num.empty()) {
		res += num + ",";
	}
	while (!vacia()) {
		int s;
		sacar(s);
		res += (char)s;
		res += ",";
	}
	if (!res.empty() && res.back() == ',') {
		res.pop_back();
	}
	return invertido(res);
}

//---------------------------------------------------------------------------
bool Pila_CSMemoria :: parentesisOk(string cad){
 bool correcto = true;
	for (int i = 0; i < cad.length(); i++) {
		int s;
		char c = cad[i];
		if (c == '(')
			meter(c);
		else if (c == ')') {
			if (vacia()) {
				correcto = false;
				break;
			}
			sacar(s);
		}
	}
	if (correcto && vacia()) {
		ShowMessage("Parentesis corecto");
		return true;
   }	else  {
		ShowMessage("Parentesis incorrectos");
		return false;
   }
}
//---------------------------------------------------------------------------
#pragma package(smart_init)


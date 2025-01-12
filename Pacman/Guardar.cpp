//---------------------------------------------------------------------------

#pragma hdrstop

#include "Guardar.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

GuardarNiveles :: GuardarNiveles(CSMemoria* mem,Matriz_CSM* ma){
m=mem;  mat=ma;   nom="nivel.txt";
}
//---------------------------------------------------------------------------
void GuardarNiveles :: setNom(AnsiString archivo){
nom=archivo;
}
//---------------------------------------------------------------------------
AnsiString GuardarNiveles :: getNom(){
 return nom;
}
//---------------------------------------------------------------------------
void GuardarNiveles :: Guardar(){

   if (FileExists(nom)) {
		eliminar();
	}

 ofstream archivo(nom.c_str());
	if (!archivo) {
		ShowMessage("Error al abrir el archivo para guardar.");
		return;
	}
	 int FPacman=mat->getFilPacman();
	 int CPacman=mat->getColPacman();
	int puntos=mat->Scored();
	int filas = mat->dimension_Fila();
	int columnas = mat->dimension_Columna();
	archivo << filas << " " << columnas<<" "<<puntos<<" "<<FPacman<<" "<<CPacman<<" "<<endl;

	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			archivo << mat->elemento(i+1,j+1) << " ";
		}
		archivo << endl;
	}

	archivo.close();
	ShowMessage("Nivel guardado exitosamente.");
}
//---------------------------------------------------------------------------
void GuardarNiveles :: eliminar(){
  if (DeleteFile(nom)) {
		//ShowMessage("Archivo eliminado exitosamente.");
	} else {
		ShowMessage("Error al intentar eliminar el archivo.");
	}
}
//---------------------------------------------------------------------------
void GuardarNiveles :: abrir(){

	ifstream archivo(nom.c_str());
	if (!archivo) {
		ShowMessage("Error al abrir el archivo para cargar.");
		return;
	}

	int filas, columnas,puntos,FPacman,CPacman;
	archivo >> filas >> columnas>>puntos>>FPacman>>CPacman;

	mat->dimensionar(filas,columnas);
	mat->setColPacman(CPacman);
	mat->setFilPacman(FPacman);
	mat->setScored(puntos);

	for (int i = 1; i <=filas; i++) {
		for (int j = 1; j <=columnas; j++) {
			int elemento;
			archivo >> elemento;
			if(elemento != 0){
			mat->poner(i, j, elemento);
			}
		}
	}

	archivo.close();
	ShowMessage("Nivel cargado exitosamente.");
}
//---------------------------------------------------------------------------

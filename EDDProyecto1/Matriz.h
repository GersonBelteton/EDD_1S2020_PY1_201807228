#pragma once
#include "NodoMatriz.h";

class Matriz
{
private:

	NodoMatriz* raiz;

public:

	Matriz();
	void insertar(int x, int y, int puntaje, char letra);
	NodoMatriz* insertarFilaOrdenada(NodoMatriz* cabezaFila, NodoMatriz* nuevo);
	NodoMatriz* insertarColumnaOrdenada(NodoMatriz* cabezaColumna, NodoMatriz* nuevo);
	NodoMatriz* buscarFila(int y);
	NodoMatriz* buscarColumna(int x);
	NodoMatriz* crearColumna(int x);
	NodoMatriz* crearFila(int y);
	void mostrarMatriz();





};


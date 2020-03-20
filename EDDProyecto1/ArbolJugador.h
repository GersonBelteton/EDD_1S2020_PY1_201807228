#pragma once
#include "NodoJugador.h";
class ArbolJugador
{

private:
	NodoJugador* raiz;

public:
	ArbolJugador();
	bool isEmpty();
	NodoJugador* getRaiz();
	NodoJugador* insertar(string nombre_, NodoJugador* n);
	int isMayor(string mayor, string menor);
	void inOrden(NodoJugador* n);
	void preOrden(NodoJugador* n);
	void posOrden(NodoJugador* n);
	NodoJugador* buscar(string nombre);
};


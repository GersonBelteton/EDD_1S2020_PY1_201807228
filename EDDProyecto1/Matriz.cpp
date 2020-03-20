#include "Matriz.h";
#include <cstddef>;
#include <iostream>;

using namespace std;
Matriz::Matriz()
{
	raiz = new NodoMatriz(-1, -1, 0, 'o');
}

void Matriz::insertar(int x, int y ,int puntaje, char letra)
{

	NodoMatriz* fila = buscarFila(y);
	NodoMatriz* columna = buscarColumna(x);
	NodoMatriz* nuevo = new NodoMatriz(x, y, puntaje, letra);
	
	if (fila == NULL && columna == NULL) {
		//No hay fila, no hay columna

		//cout << "null null" << endl;
		fila = crearFila(y);
		columna = crearColumna(x);
		nuevo = insertarColumnaOrdenada(columna, nuevo);
		nuevo = insertarFilaOrdenada(fila, nuevo);
	}
	else if (fila != NULL && columna == NULL) {
		// existe fila, no hay columna
		//cout << " no null null" << endl;
		columna = crearColumna(x);
		nuevo = insertarColumnaOrdenada(columna, nuevo);
		nuevo = insertarFilaOrdenada(fila, nuevo);
		//cout << "hola";
	}
	else if (fila == NULL && columna != NULL) {
		//no hay fila, existe columna
		//cout << "null no null" << endl;
		fila = crearFila(y);
		nuevo = insertarColumnaOrdenada(columna, nuevo);
		nuevo = insertarFilaOrdenada(fila, nuevo);
	}
	else if (fila != NULL && columna != NULL) {
		//existe fila, existe columna
		//cout << "no null no null" << endl;
		nuevo = insertarColumnaOrdenada(columna, nuevo);
		nuevo = insertarFilaOrdenada(fila, nuevo);
	}
}

NodoMatriz* Matriz::insertarFilaOrdenada(NodoMatriz* cabezaFila, NodoMatriz* nuevo)
{
	NodoMatriz* aux = cabezaFila;

	while (aux != NULL) {
		//cout << aux->getLetra() << " "<< aux->getX() << aux->getY()<<endl;
		if (aux->getX() == nuevo->getX()) {
			//sobrescribir
			aux->setX(nuevo->getX());
			aux->setLetra(nuevo->getLetra());
			aux->setPuntaje(nuevo->getPuntaje());
			return nuevo;

		}
		else if (aux->getX() > nuevo->getX()) {
			aux->getAnterior()->setSiguiente(nuevo);
			nuevo->setAnterior(aux->getAnterior());
			nuevo->setSiguiente(aux);
			aux->setAnterior(nuevo);
			return nuevo;
		}
		else if (aux->getSiguiente() == NULL) {
			aux->setSiguiente(nuevo);
			nuevo->setAnterior(aux);
			return nuevo;
		}
		else if (aux->getX() < nuevo->getX()) {
			aux = aux->getSiguiente();
		}
		


	}


	return nuevo;
}

NodoMatriz* Matriz::insertarColumnaOrdenada(NodoMatriz* cabezaColumna, NodoMatriz* nuevo)
{
	NodoMatriz* aux = cabezaColumna;

	while (aux != NULL) {
		//cout << aux->getLetra() << " " << aux->getX()<<aux->getY()<< endl;
		if (aux->getY() == nuevo->getY()) {
			//sobrescribir
			aux->setY(nuevo->getY());
			aux->setLetra(nuevo->getLetra());
			aux->setPuntaje(nuevo->getPuntaje());
			return nuevo;

		}
		else if (aux->getY() > nuevo->getY()) {
			aux->getArriba()->setAbajo(nuevo);
			nuevo->setArriba(aux->getArriba());
			nuevo->setAbajo(aux);
			aux->setArriba(nuevo);
			return nuevo;
		}
		else if (aux->getAbajo() == NULL) {
			aux->setAbajo(nuevo);
			nuevo->setArriba(aux);
			return nuevo;
		}
		else if (aux->getY() < nuevo->getY()) {
			aux = aux->getAbajo();
		}



	}
	return nuevo;
}

NodoMatriz* Matriz::buscarFila(int y)
{

	NodoMatriz* aux = raiz;

	while (aux != NULL) {
		if (aux->getY() == y) {
			return aux;
		}

		aux = aux->getAbajo();
	}
	return NULL;
}

NodoMatriz* Matriz::buscarColumna(int x)
{
	NodoMatriz* aux = raiz;

	while (aux != NULL) {
		if (aux->getX() == x) {
			return aux;
		}

		aux = aux->getSiguiente();
	}
	return NULL;
}

NodoMatriz* Matriz::crearColumna(int x)
{
	NodoMatriz* aux = raiz;
	NodoMatriz* columna = insertarFilaOrdenada(aux, new NodoMatriz(x, -1, 0, 'f'));

	return columna;

}

NodoMatriz* Matriz::crearFila(int y)
{
	NodoMatriz* aux = raiz;
	NodoMatriz* fila = insertarColumnaOrdenada(aux, new NodoMatriz(-1, y, 0, 'c'));

	return fila;
}

void Matriz::mostrarMatriz()
{
	NodoMatriz* aux = raiz;
	int contador = 0;

	while (aux != NULL) {
		while (aux != NULL) {

			cout << aux->getLetra() << " "<<aux->getX()<<aux->getY() ;
			aux = aux->getSiguiente();
		}
		cout << endl;
		aux = raiz;
		contador++;
		for (int i = 0; i < contador; i++) {
			aux = aux->getAbajo();
		}
		
		
	}

}






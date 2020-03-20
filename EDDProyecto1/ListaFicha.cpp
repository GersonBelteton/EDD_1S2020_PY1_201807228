#include "ListaFicha.h"

ListaFicha::ListaFicha()
{
	primero = NULL;
	ultimo = NULL;
	size = 0;
	id = 0;
}

bool ListaFicha::isEmpty()
{
	return primero == NULL;
}

int ListaFicha::Size()
{
	return size;
}

void ListaFicha::insertarInicio(char letra, int puntaje)
{
	
	Ficha* nuevo = new Ficha(letra, puntaje, id);
	if (isEmpty()) {
		primero = nuevo;
		ultimo = nuevo;
	}
	else {
		nuevo->setSiguiente(primero);
		primero->setAnterior(nuevo);
		primero = nuevo;
	}

	size++;
	id++;
}

void ListaFicha::insertarFinal(char letra, int puntaje)
{
	
	Ficha* nuevo = new Ficha(letra, puntaje, id);
	if (isEmpty()) {
		primero = nuevo;
		ultimo = nuevo;
	}
	else {
		ultimo->setSiguiente(nuevo);
		nuevo->setAnterior(ultimo);
		ultimo = nuevo;
		
	}
	size++;
	id++;
	
}

Ficha* ListaFicha::buscar(int id)
{
	if (isEmpty()) {
		cout << "lista vacia" << endl;

	}
	else {
		Ficha* aux = primero;

		while (aux != NULL) {
			
			if (aux->getId() == id) {
				return aux;
			}

			aux = aux->getSiguiente();
		}


	}

	return NULL;
}

void ListaFicha::eliminarInicio()
{
	if (isEmpty()) {
		cout << "lista vacia" << endl;
	}
	else {
		primero->getSiguiente()->setAnterior(NULL);
		primero = primero->getSiguiente();
	}
}

void ListaFicha::eliminarFinal()
{
	if (isEmpty()) {
		cout << "Lista vacia" << endl;
	}
	else {
		ultimo->getAnterior()->setSiguiente(NULL);
		ultimo = ultimo->getAnterior();
	}
}

void ListaFicha::eliminar(int id)
{
	if (isEmpty()) {
		cout << "Lista vacia" << endl;
	}
	else {
		if (primero->getId() == id) {
			eliminarInicio();
		}
		else if (ultimo->getId() == id) {
			eliminarFinal();
		}
		else {
			Ficha* aux = buscar(id);
			aux->getAnterior()->setSiguiente(aux->getSiguiente());
			aux->getSiguiente()->setAnterior(aux->getAnterior());

		}
	}
}

void ListaFicha::mostrarLista()
{
	if (isEmpty()) {
		cout << "Lista vacia" << endl;
	}
	else {
		Ficha* aux = primero;
		while (aux != NULL) {
			cout << aux->getId() << " " << aux->getLetra() << " " << aux->getPuntaje() << endl;
			aux = aux->getSiguiente();
		}
	}
}

#include "ListaPuntaje.h"
#include <iostream>;
#include <stdio.h>;
#include <stdlib.h>;
#include <conio.h>;
#include <windows.h>;
#include <string.h> ;

using namespace std;
ListaPuntaje::ListaPuntaje()
{
	primero = NULL;
	ultimo = NULL;
	size = 0;
}

bool ListaPuntaje::isEmpty()
{
	return primero == NULL;
}

int ListaPuntaje::Size()
{
	return size;
}

void ListaPuntaje::insertarOrdenado(int puntaje)
{

	NodoPuntaje* nuevo = new NodoPuntaje(puntaje);
	NodoPuntaje* aux = primero;
	NodoPuntaje* temp = aux;
	if (isEmpty()) {
		primero = nuevo;
		ultimo = nuevo;
	}
	else {

		while (aux != NULL) {

			if (puntaje > primero->getPuntaje()) {
				nuevo->setSiguiente(primero);
				primero = nuevo;
				break;
			}
			else if (puntaje < ultimo->getPuntaje()) {
				ultimo->setSiguiente(nuevo);
				ultimo = nuevo;
				break;
			}

			else {

				
				if (puntaje < aux->getPuntaje()) {
					temp = aux;
					aux = aux->getSiguiente();
				}
				else {
				
						temp->setSiguiente(nuevo);
						nuevo->setSiguiente(aux);
			
						break;
					
				}
			}


		}


	}
}

void ListaPuntaje::mostrarLista()
{
	NodoPuntaje* aux = primero;

	if (isEmpty()) {
		cout << "lista vacia" << endl;
	}
	else {
		while (aux != NULL) {


			cout << aux->getPuntaje()<< " puntaje" << endl;
			aux = aux->getSiguiente();
		}
	}


}





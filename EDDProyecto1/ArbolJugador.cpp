#include "ArbolJugador.h"

ArbolJugador::ArbolJugador()
{
	raiz = NULL;
}

bool ArbolJugador::isEmpty()
{
	return raiz == NULL;
}

NodoJugador* ArbolJugador::getRaiz()
{
	return raiz;
}



NodoJugador* ArbolJugador::insertar(string nombre_, NodoJugador* n)
{

	if (n == NULL) {
		n = new NodoJugador(nombre_);
		if (isEmpty()) {
			raiz = n;
		}
		
		cout << "null";
	}
	else if (isMayor(nombre_, n->getNombre()) == 1) {
		cout << "derecha";
		n->setDerecha(insertar(nombre_, n->getDerecha()));
	}
	else if(isMayor(nombre_, n->getNombre())==-1){
		cout << "izquierda";
		n->setIzquierda(insertar(nombre_, n->getIzquierda()));
	}
	else {
		// iguales 
		cout << "error, ya existe ese nombre"<<endl;
	}
	return n ;
}





int ArbolJugador::isMayor(string mayor, string menor)
{
	//0 iguales, 1 mayor, -1 menor
	
	int asciiMayor = 0;
	int asciiMenor = 0;
	int limite;
	
	if (mayor.length() <= menor.length()) {
		limite = mayor.length();
	}
	else {
		limite = menor.length();
	}
		
		for (int j = 0; j < limite; j++) {
			asciiMayor = mayor[j];
			asciiMenor = menor[j];

			if (asciiMayor > asciiMenor) {
				return 1;
			}
			else if (asciiMayor < asciiMenor) {
				return -1;
			}
			else {
				
			}
		}
	if (mayor.length() > menor.length()) {
		return 1;
	}
	else if(mayor.length() < menor.length()){
		return -1;
	}
	else {
		return 0;
	}
}

void ArbolJugador::inOrden(NodoJugador* n)
{
	if (n != NULL) {
		inOrden(n->getIzquierda());
		cout << n->getNombre() << endl;
		inOrden(n->getDerecha());
	}

}

void ArbolJugador::preOrden(NodoJugador* n)
{
	if (n != NULL) {
		cout << n->getNombre()<<endl;
		preOrden(n->getIzquierda());
		preOrden(n->getDerecha());
	}

}

void ArbolJugador::posOrden(NodoJugador* n)
{
	if (n != NULL) {
		posOrden(n->getIzquierda());
		posOrden(n->getDerecha());
		cout << n->getNombre() << endl;

	}
}

NodoJugador* ArbolJugador::buscar(string nombre)
{
	if (isEmpty()) {
		cout << "Arbol de jugadores vacio";
	}
	else {
		NodoJugador* aux = raiz;

		while (aux != NULL) {
			if (nombre == aux->getNombre()) {
				return aux;
			}
		
			if (isMayor(nombre, aux->getNombre())) {
				aux = aux->getDerecha();
			}
			else {
				aux = aux->getDerecha();
			}

		}

	}


	return NULL;
}

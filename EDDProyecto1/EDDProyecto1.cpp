
#include <iostream>
#include "ColaFicha.h";
#include "ListaPalabras.h";
#include "ListaPuntaje.h";
#include "ListaFicha.h";
#include "ArbolJugador.h";
#include "Matriz.h";
int main()
{
    std::cout << "Hello World!\n";
	

	ArbolJugador aj = ArbolJugador();

	aj.insertar("gerson", aj.getRaiz());
	aj.insertar("juan", aj.getRaiz());
	aj.insertar("pedro", aj.getRaiz());
	aj.insertar("alejandro", aj.getRaiz());
	aj.insertar("carlos", aj.getRaiz());
	aj.insertar("carlos", aj.getRaiz());
	aj.insertar("alex", aj.getRaiz());
	aj.insertar("juanita", aj.getRaiz());
	aj.preOrden(aj.getRaiz());

	cout << endl << endl;

	aj.inOrden(aj.getRaiz());

	cout << endl << endl;

	aj.posOrden(aj.getRaiz());

	
	cout<< aj.buscar("gerson")->getNombre()<<endl<<endl;

	cout << "----------------------- Matriz-----------------------------"<<endl<<endl;


	Matriz m = Matriz();

	m.insertar(0, 0, 1, 'Y');
	m.insertar(0, 5, 1, 'A');
	m.insertar(1, 5, 1, 'Z');

	m.mostrarMatriz();


	ColaFicha cf = ColaFicha();

	cf.enqueue('a', 9);
	cf.enqueue('b', 9);
	cf.enqueue('c', 9);
	cf.enqueue('d', 9);

	cf.mostrarCola();
	cf.generarReporte();
}




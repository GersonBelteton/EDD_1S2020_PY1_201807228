#pragma once
class NodoMatriz
{
private:
	char letra;
	int puntaje;
	int x;
	int y;
	NodoMatriz* siguiente;
	NodoMatriz* anterior;
	NodoMatriz* arriba;
	NodoMatriz* abajo;

public:
	NodoMatriz(int x, int y, int puntaje, char letra);
	char getLetra();
	int getPuntaje();
	int getX();
	int getY();
	NodoMatriz* getSiguiente();
	NodoMatriz* getAnterior();
	NodoMatriz* getArriba();
	NodoMatriz* getAbajo();

	void setLetra(char letra_);
	void setPuntaje(int puntaje_);
	void setX(int x_);
	void setY(int y_);
	void setSiguiente(NodoMatriz* siguiente_);
	void setAnterior(NodoMatriz* anterior_);
	void setArriba(NodoMatriz* arriba_);
	void setAbajo(NodoMatriz* abajo_);


};


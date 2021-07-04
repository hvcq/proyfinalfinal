#include <iostream>
#include <vector>

using namespace std;

struct celda {
	celda * padre ;
	int rank;
	int x;
	int y;
};

struct vertice {
	//Quiza se podria separar padre y rank uwu
	vertice * padre ;
	int rank;
	vertice * arriba;
    vertice * abajo;
    vertice * izquierda;
    vertice * derecha;
	int num;
};

struct arista {
	vertice * a;
	vertice * b;
	arista * siguiente;
	int peso;
	//c1 puede ser una celda de arriba o de la izquierda
	celda * c1;
	//c1 puede ser una celda de abajo o de la derecha
	celda * c2;
	//Saber si la arista forma parte de la pared del laberinto
	bool pared;
	//Para aplicar borrado lógico de la arista en el laberinto
	bool eliminada;
};

class Union_find{
    private:

    public:
    	Union_find();
		~Union_find();
		//Para vertices
    	void Makeset(vertice * x);
		void Link(vertice * x,vertice * y);
    	vertice * Find(vertice * x);
    	void Union(vertice * x, vertice * y);
		//Para celdas
		void Makeset(celda * x);
		void Link(celda * x,celda * y);
    	celda * Find(celda * x);
    	void Union(celda * x, celda * y);
};
#include <bits/stdc++.h>

using namespace std;

struct vertice {
	int num;
	vertice * arriba;
    vertice * abajo;
    vertice * izquierda;
    vertice * derecha;
};

struct arista {
	vertice * a;
	vertice * b;
	arista * siguiente;
	int peso;
};

struct vertice_UF{
	vertice * representante;
	vertice * vertice_grilla;
};

class Union_find{
    private:
    	vector<vertice_UF> nube;
    public:
    	Union_find();
		~Union_find();
    	void Makeset(vertice * repre);
    	vertice * Find(vertice * aux);
    	void Union(vertice * a, vertice *b);
};
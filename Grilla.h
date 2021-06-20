#include <bits/stdc++.h>
#include "Union_find.h"

using namespace std;

class Grilla{
	private:
		struct vertice * head_v;
        struct arista * head_a;
		vector <vertice_UF> vertices_MST;
		vector <arista> aristas_MST;
		int mysize;
	public:
		Grilla(int n,int m);
		Grilla(int n,int m,int aa,int bb);
		~Grilla();
		void dibuja_grilla();
		int funcion_random(int a, int b); 
		void pesos_aristas();
        vertice * head_vertice();
        arista * head_arista();
		vector<arista> kruskal();
		int size();
};
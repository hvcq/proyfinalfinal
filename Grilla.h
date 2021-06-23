#include <iostream>
#include <vector>
#include <queue>
#include "Union_find.h"

using namespace std;

class myComparator
{
public:
    int operator() (const arista * n1, const arista * n2)
    {
        return n1->peso > n2->peso;
    }
};

class Grilla{
	private:
		struct vertice * head_v;
        struct arista * head_a;
		
		vector <arista> aristas_MST;
		int mysize;
	public:
		priority_queue <arista *, vector<arista *>, myComparator> minHeap;
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
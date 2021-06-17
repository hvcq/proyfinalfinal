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

class Grilla{
	private:
		struct vertice * head_v;
        struct arista * head_a;
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
		int size();
};
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
	int num;
};

class Grilla{
	private:
		struct vertice * head_v;
        struct arista * head_a;
		int mysize;
	public:
		Grilla(int n,int m);
		~Grilla();
		void dibuja_grilla();
		int funcion_random(int a, int b); 
		void pesos_aristas();
        vertice * head_vertice();
        arista * head_arista();
		int size();
};
#include "Grilla.h"
Grilla::Grilla(int n,int m){
    ene = n;
    eme = m;
	mysize = 0;
    nubes = new Union_find();
    head_v = new vertice();
    head_a = new arista();
    if((n < 0)||(m < 0)){
        cout<<"Ingrese valores de n y m validos"<<endl;
        throw;
    }else{
        //aux_v manejan los vértices en dirección vertical
        //aux_h manejan los vértices en dirección horizontal
        vertice * aux_v2 = head_v;
        vertice * aux_v1;
        vertice * aux_h2;
        vertice * aux_h1;
        arista * aux_arista = head_a;
        // Forma primera parte de la Grilla
        // Esto incluye todos los vertices, n*m/2 aristas necesarias para completar la Grilla
        for(int i = 0; i<n; ++i){
            aux_h2 = aux_v2;
            for(int j = 0; j<m; ++j){
                aux_h2->derecha = new vertice();
                aux_h1 = aux_h2;
                aux_h2 = aux_h2->derecha;
                aux_h2->izquierda = aux_h1;
                aux_arista->siguiente = new arista();
                aux_arista->siguiente->peso = 1;
                minHeap.push(aux_arista->siguiente);
                aux_arista->siguiente->a = aux_h1;
                aux_arista->siguiente->b = aux_h2;
                aux_arista = aux_arista->siguiente;
            }
            aux_v2->abajo = new vertice();
            aux_v1 = aux_v2;
            aux_v2 = aux_v2->abajo;
            aux_v2->arriba = aux_v1;
            aux_arista->siguiente = new arista();
            aux_arista->siguiente->peso = 1;
            minHeap.push(aux_arista->siguiente);
            aux_arista->siguiente->a = aux_v1;
            aux_arista->siguiente->b = aux_v2;
            aux_arista = aux_arista->siguiente;
        }
        // Termina de formar las aristas aux_h2es finales faltantes
        aux_h2 = aux_v2;
        for(int i = 0; i<m; ++i){
                aux_h2->derecha = new vertice();
                aux_h1 = aux_h2;
                aux_h2 = aux_h2->derecha;
                aux_h2->izquierda = aux_h1;
                aux_arista->siguiente = new arista();
                aux_arista->siguiente->peso = 1;
                minHeap.push(aux_arista->siguiente);
                aux_arista->siguiente->a = aux_h1;
                aux_arista->siguiente->b = aux_h2;
                aux_arista = aux_arista->siguiente;
        }
        // Termina de formar las aristas aux_v2es intermedias y finales faltantes
        aux_v1 = head_v; 
        aux_v2 = head_v->abajo;
        for(int i = 0; i<n; ++i){
            aux_h1 = aux_v1->derecha;
            aux_h2 = aux_v2->derecha;
            for(int j = 0; j<m; ++j){
                aux_h1->abajo = aux_h2;
                aux_h2->arriba = aux_h1;
                aux_arista->siguiente = new arista();
                aux_arista->siguiente->peso = 1;
                minHeap.push(aux_arista->siguiente);
                aux_arista->siguiente->a = aux_h1;
                aux_arista->siguiente->b = aux_h2;
                aux_arista = aux_arista->siguiente;
                aux_h1 = aux_h1->derecha;
                aux_h2 = aux_h2->derecha;
            }
            aux_v1 = aux_v2;
            aux_v2 = aux_v2->abajo;
        }
    }
}

Grilla::Grilla(int n,int m,int aa,int bb){
    int uuu = 0;
    ene = n;
    eme = m;
    int a = aa;
    int b = bb;
	mysize = 0;
    nubes = new Union_find();
    head_v = new vertice();
    head_v->num = uuu;
    ++uuu;
    head_a = new arista();
    if((n < 0)||(m < 0)){
        cout<<"Ingrese valores de n y m validos"<<endl;
        throw;
    }else{
        //aux_v manejan los vértices en dirección vertical
        //aux_h manejan los vértices en dirección horizontal
        vertice * aux_v2 = head_v;
        vertice * aux_v1;
        vertice * aux_h2;
        vertice * aux_h1;
        arista * aux_arista = head_a;
        // Forma primera parte de la Grilla
        // Esto incluye todos los vertices, n*m/2 aristas necesarias para completar la Grilla
        for(int i = 0; i<n; ++i){
            aux_h2 = aux_v2;
            for(int j = 0; j<m; ++j){
                aux_h2->derecha = new vertice();
                aux_h2->derecha->num = uuu;
                ++uuu;
                aux_h1 = aux_h2;
                aux_h2 = aux_h2->derecha;
                aux_h2->izquierda = aux_h1;
                aux_arista->siguiente = new arista();
                aux_arista->siguiente->peso = funcion_random(a,b);
                cout<<"arista: "<<aux_arista->siguiente->peso<<endl;
                minHeap.push(aux_arista->siguiente);
                aux_arista->siguiente->a = aux_h1;
                aux_arista->siguiente->b = aux_h2;
                aux_arista = aux_arista->siguiente;
            }
            aux_v2->abajo = new vertice();
            aux_v2->abajo->num = uuu;
            ++uuu;
            aux_v1 = aux_v2;
            aux_v2 = aux_v2->abajo;
            aux_v2->arriba = aux_v1;
            aux_arista->siguiente = new arista();
            aux_arista->siguiente->peso = funcion_random(a,b);
            minHeap.push(aux_arista->siguiente);
            aux_arista->siguiente->a = aux_v1;
            aux_arista->siguiente->b = aux_v2;
            aux_arista = aux_arista->siguiente;
        }
        // Termina de formar las aristas aux_h2es finales faltantes
        aux_h2 = aux_v2;
        for(int i = 0; i<m; ++i){
                aux_h2->derecha = new vertice();
                aux_h2->derecha->num = uuu;
                ++uuu;
                aux_h1 = aux_h2;
                aux_h2 = aux_h2->derecha;
                aux_h2->izquierda = aux_h1;
                aux_arista->siguiente = new arista();
                aux_arista->siguiente->peso = funcion_random(a,b);
                minHeap.push(aux_arista->siguiente);
                aux_arista->siguiente->a = aux_h1;
                aux_arista->siguiente->b = aux_h2;
                /*if(i == 0){
                    cout<<"---datitos--"<<endl;
                    cout<<"v1: "<<aux_h1->num<<endl;
                    cout<<"v2:"<<aux_h2->num<<endl;
                    cout<<"arista_actual->peso: "<<aux_arista->peso<<endl;
                    cout<<"a: "<<aux_arista->a->num<<endl;
                    cout<<"b: "<<aux_arista->b->num<<endl;
                    cout<<"arista_sig->peso: "<<aux_arista->siguiente->peso<<endl;
                    cout<<"a_sig: "<<aux_arista->siguiente->a->num<<endl;
                    cout<<"b_sig: "<<aux_arista->siguiente->b->num<<endl;
                }*/
                aux_arista = aux_arista->siguiente;
        }
        // Termina de formar las aristas aux_v2 es intermedias y finales faltantes
        aux_v1 = head_v; 
        aux_v2 = head_v->abajo;
        for(int i = 0; i<n; ++i){
            aux_h1 = aux_v1->derecha;
            aux_h2 = aux_v2->derecha;
            for(int j = 0; j<m; ++j){
                aux_h1->abajo = aux_h2;
                aux_h2->arriba = aux_h1;
                aux_arista->siguiente = new arista();
                aux_arista->siguiente->peso = funcion_random(a,b);
                minHeap.push(aux_arista->siguiente);
                aux_arista->siguiente->a = aux_h1;
                aux_arista->siguiente->b = aux_h2;
                aux_arista = aux_arista->siguiente;
                aux_h1 = aux_h1->derecha;
                aux_h2 = aux_h2->derecha;
            }
            aux_v1 = aux_v2;
            aux_v2 = aux_v2->abajo;
        }
    }
}

Grilla::~Grilla(){
    //Borra Vértices
    vertice * aux_v = head_v;
    vertice * aux_h;
    vertice * aux_v2;
    vertice * aux_h2;
    while(aux_v != NULL) {
        aux_h = aux_v->derecha;
        while(aux_h != NULL){
            aux_h2 = aux_h->derecha;
            delete aux_h;
            aux_h = aux_h2;
        }
        aux_v2 = aux_v->abajo;
        delete aux_v;
        aux_v = aux_v2;
    }  
    //Borra Aristas
    arista * aux_arista = head_a->siguiente;
    arista * aux_arista2 = head_a->siguiente;
    while(aux_arista != NULL){
        aux_arista2 = aux_arista->siguiente;
        delete aux_arista;
        aux_arista = aux_arista2;
    }
    delete head_a;
}

arista * Grilla::arista_asociada(vertice * x, vertice * y){
    arista * arista_aux = head_a->siguiente;
    while(arista_aux != NULL){
        if((arista_aux->a == x)&&(arista_aux->b == y))
            return arista_aux;
        else{
            if((arista_aux->a == y)&&(arista_aux->b == x))
                return arista_aux;
            else
                arista_aux = arista_aux->siguiente;
        }
    }
    return arista_aux;
}

void Grilla::dibuja_grilla(){
    vertice * aux_v2;
    vertice * aux_v1;
    vertice * aux_h2;
    vertice * aux_h1;
    arista * aux_arista;
    aux_v1 = head_v; 
    aux_v2 = head_v->abajo;
    if((ene == 0)&&(eme == 0)){
        cout<<"O"<<endl;
    }else{
        if((ene == 1)&&(eme == 0)){
            aux_arista = arista_asociada(head_v,head_v->abajo);
            cout<<"O"<<endl<<"|"<<endl<<aux_arista->peso<<endl<<"|"<<endl<<"O"<<endl;
        }else{
            if((ene == 0)&&(eme == 1)){
                aux_arista = arista_asociada(head_v,head_v->derecha);
                cout<<"O -"<<aux_arista->peso<<"- O"<<endl;
            }else{
                for(int i = 0; i<ene; ++i){
                    if(i == 0){
                        aux_h1 = aux_v1;
                        for(int j = 0; j<eme; ++j){
                            if(j == 0){
                                aux_arista = arista_asociada(aux_h1,aux_h1->derecha);
                                cout<<"O -"<<aux_arista->peso<<"- O";
                            }else{
                                aux_arista = arista_asociada(aux_h1,aux_h1->derecha);
                                cout<<" -"<<aux_arista->peso<<"- O";
                            }
                            aux_h1 = aux_h1->derecha;
                        }
                        cout<<endl;
                    }
                    aux_h1 = aux_v1;
                    for(int j = 0; j<=eme; ++j){
                        cout<<"|      ";
                        aux_h1 = aux_h1->derecha;
                    }
                    cout<<endl;
                    aux_h1 = aux_v1;
                    aux_h2 = aux_v2;
                    for(int j = 0; j<=eme; ++j){
                        aux_arista = arista_asociada(aux_h1,aux_h2);
                        cout<<aux_arista->peso<<"     ";
                        aux_h1 = aux_h1->derecha;
                        aux_h2 = aux_h2->derecha;
                    }
                    cout<<endl;
                    aux_h1 = aux_v2;
                    for(int j = 0; j<=eme; ++j){
                        cout<<"|      ";
                        aux_h1 = aux_h1->derecha;
                    }
                    cout<<endl;
                    aux_h1 = aux_v2;
                    for(int j = 0; j<eme; ++j){
                        if(j == 0){
                            aux_arista = arista_asociada(aux_h1,aux_h1->derecha);
                            cout<<"O -"<<aux_arista->peso<<"- O";
                        }else{
                            aux_arista = arista_asociada(aux_h1,aux_h1->derecha);
                            cout<<" -"<<aux_arista->peso<<"- O";
                        }
                        aux_h1 = aux_h1->derecha;
                    }
                    cout<<endl;
                    aux_v1 = aux_v2;
                    aux_v2 = aux_v2->abajo;
                }
            }
        }
    }
}

int Grilla::funcion_random(int a, int b){
    if(a > b){
        cout<<"a y b no representan un intervalo [a,b] correcto"<<endl;
        throw;
    }
    int aux;
    aux = rand()&1;
    if(aux == 0){
        if((b == 1) && (a == 0)){
            aux = rand()%(b+1);
        }else{
            if(a == b){
                aux = a;
            }else{
                aux = a + rand()%(((b+1)/2)-a);
            }
        }
    }else{
       if((b == 1) && (a == 0)){
            aux = rand()%(b+1);
        }else{
            if(a == b){
                aux = a;
            }else{
                aux = (b/2) + rand()%((b+1)/2);
            }
        }
    }
    return aux;
}

void Grilla::pesos_aristas(){
    while(head_a->siguiente != NULL){
        head_a;
    }
}

vertice * Grilla::head_vertice(){
    return head_v;
}


arista * Grilla::head_arista(){
    return head_a;
}

vector<arista *> Grilla::kruskal(){
    // Pasamos los vértices a la estructura Union-Find
    vertice * aux_v = head_v;
    vertice * aux_h = aux_v;
    while(aux_v != NULL){
        while(aux_h != NULL){
            if(aux_h->derecha != NULL){
                nubes->Makeset(aux_h->derecha);
            }
            aux_h = aux_h->derecha;
        }
        aux_v = aux_v->abajo;
        aux_h = aux_v;
    }
    //En el constructor de Grilla pasamos las aristas
    vector<arista *> MST;
    arista * arista_aux;
    while (minHeap.empty() == false)
    {
        arista_aux = minHeap.top();
        minHeap.pop();
        if((nubes->Find(arista_aux->a)) != (nubes->Find(arista_aux->b))){
            MST.push_back(arista_aux);
            nubes->Union(arista_aux->a,arista_aux->b);
        }
        
    }
    return MST;
}

int Grilla::size(){
    //(n+1)*(m+1)
    return -1;
}
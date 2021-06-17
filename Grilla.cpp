#include "Grilla.h"
#include <iostream>

using namespace std;

Grilla::Grilla(int n,int m){
	mysize = 0;
    head_v = new vertice();
    head_a = new arista();
    if((n < 0)||(m < 0)){
        //error-, lo hace yerko
    }else{
        //aux_v manejan los vértices en dirección vertical
        //aux_h manejan los vértices en dirección horizontal
        vertice * aux_v2 = head_v;
        vertice * aux_v1;
        vertice * aux_h2;
        vertice * aux_h1;
        arista * aux_arista = head_a;
        int k = 0;
        // Forma primera parte de la grilla
        // Esto incluye todos los vertices, n*m/2 aristas necesarias para completar la grilla
        for(int i = 0; i<n; ++i){
            aux_h2 = aux_v2;
            for(int j = 0; j<m; ++j){
                aux_h2->derecha = new vertice();
                aux_h2->derecha->num = j + 1;
                aux_h1 = aux_h2;
                aux_h2 = aux_h2->derecha;
                aux_h2->izquierda = aux_h1;
                aux_arista->siguiente = new arista();
                ++k;
                aux_arista->siguiente->num = k;
                aux_arista->siguiente->a = aux_h1;
                aux_arista->siguiente->b = aux_h2;
                aux_arista = aux_arista->siguiente;
            }
            aux_v2->abajo = new vertice();
            aux_v2->abajo->num = i + 1;
            aux_v1 = aux_v2;
            aux_v2 = aux_v2->abajo;
            aux_v2->arriba = aux_v1;
            aux_arista->siguiente = new arista();
            ++k;
            aux_arista->siguiente->num = k;
            aux_arista->siguiente->a = aux_v1;
            aux_arista->siguiente->b = aux_v2;
            aux_arista = aux_arista->siguiente;
        }
        // Termina de formar las aristas aux_h2es finales faltantes
        aux_h2 = aux_v2;
        for(int i = 0; i<m; ++i){
                aux_h2->derecha = new vertice();
                aux_h2->derecha->num = i + 1;
                aux_h1 = aux_h2;
                aux_h2 = aux_h2->derecha;
                aux_h2->izquierda = aux_h1;
                aux_arista->siguiente = new arista();
                ++k;
                aux_arista->siguiente->num = k;
                aux_arista->a = aux_h1;
                aux_arista->b = aux_h2;
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
                ++k;
                aux_arista->siguiente->num = k;
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
    vertice * aux_v = head_v;
    vertice * aux_h = aux_v;
    vertice * aux_h2;
    while(aux_v != NULL){
        while(aux_h != NULL){
            if(aux_h->derecha != NULL){
                if(aux_h != aux_v){
                    aux_h2 = aux_h->derecha;
                    delete aux_h;
                    aux_h = aux_h2;
                }else{
                    aux_h = aux_h->derecha;
                }
            }else{
                delete aux_h;
                aux_h = NULL;
            }
        }
        aux_v = aux_v->abajo;
        aux_h = aux_v;
    }
}

void Grilla::dibuja_grilla(){
    vertice * aux_v = head_v;
    vertice * aux_h = aux_v;
    vertice * aux_h2;
    while(aux_v != NULL){
        cout<<"O";
        while(aux_h != NULL){
            if(aux_h->derecha != NULL){
                cout<<" -- O";
            }
            aux_h = aux_h->derecha;
        }
        cout<<endl;
        aux_v = aux_v->abajo;
        aux_h = aux_v;
        if(aux_v != NULL){
            aux_h2 = aux_v;
            cout<<"|";
            while(aux_h2 != NULL){
                if(aux_h2->derecha != NULL){
                    cout<<"    |";
                }
                aux_h2 = aux_h2->derecha;
            }
            cout<<endl;
        }
    }
}

vertice * Grilla::head_vertice(){
    return head_v;
}
arista * Grilla::head_arista(){
    return head_a;
}
int Grilla::size(){
    return -1;
}
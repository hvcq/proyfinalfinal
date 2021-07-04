#include <iostream>
#include <vector>
#include <string>
#include "Grilla.h"
using namespace std;

int main(){
    srand(time(NULL));
    Grilla * g; 
    int n,m;
    cout<<"Ingrese los valores de n y m"<<endl;
    cin>>n;
    cin>>m;
    int agrega;
    cout<<"¿Desea agregar vec_aristas->pesos a las aristas? [1] si [otro numero] no"<<endl;
    cin>>agrega;
    if(agrega == 1){
        cout<<"ingrese los valores de a y b"<<endl;
        int a,b;
        cin>>a;
        cin>>b;
        g = new Grilla(n,m,a,b);
        g->dibuja_grilla_cp();
    }else{
        g = new Grilla(n,m);
        g->dibuja_grilla_sp();
    }
    
    vector<arista *> arbol = g->kruskal();

    g->laberinto();
    g->lee_celdas();
    cout<<endl;
    arista * aux_a = g->head_arista()->siguiente;
    int contador = 0;
    while(aux_a != NULL){
        if((aux_a->pared != true)&&(aux_a->eliminada != true)){
            cout<<"la arista ("<<contador<<") : c1("<<aux_a->c1->x<<","<<aux_a->c1->y<<")";
            cout<<" - c2("<<aux_a->c2->x<<","<<aux_a->c2->y<<")"<<endl;
        }
        ++contador;
        aux_a = aux_a->siguiente;
    }
    /*
    cout<<"-----------"<<endl;
    int jj = 0;
    arista * head_arista = g->head_arista()->siguiente;
    cout<<"(a , b)"<<endl;
    while(head_arista != NULL){
        cout<<"("<<head_arista->a->num<<" , "<<head_arista->b->num<<") "<<"vec_aristas->peso arista ("<<jj<<") :"<<head_arista->peso<<endl;
        head_arista = head_arista->siguiente;
        ++jj;
    }
    cout<<"-----------"<<endl;*/
    //cout<<"num arista: "<<aaa->peso<<endl;
    /*
    while (g->minHeap.empty() == false)
    {
        cout << g->minHeap.top()->peso<< " "<<endl;
        g->minHeap.pop();
    }
    */
    //cout<<g->head_vertice()->derecha->derecha->abajo->abajo->abajo->num<<endl;
    delete g;
    return 0;
}
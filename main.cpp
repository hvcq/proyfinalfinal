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
    }else{
        g = new Grilla(n,m);
    }
    g->dibuja_grilla();
    int jj = 0;
    arista * head_arista = g->head_arista()->siguiente;
    while(head_arista != NULL){
        cout<<"vec_aristas->peso arista ("<<jj<<") :"<<head_arista->peso<<endl;
        head_arista = head_arista->siguiente;
        ++jj;
    }
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
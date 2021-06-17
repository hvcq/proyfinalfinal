#include <iostream>
#include <vector>
#include "Grilla.h"
using namespace std;

int main(){
    srand(time(NULL));
    int n,m;
    cout<<"ingrese los valores de n y m"<<endl;
    cin>>n;
    cin>>m;
    Grilla * g = new Grilla(n,m);
    g->dibuja_grilla();
    //cout<<g->head_vertice()->derecha->derecha->abajo->abajo->abajo->num<<endl;
    cout<<g->funcion_random(0,1)<<endl;
    cout<<g->funcion_random(0,1)<<endl;
    cout<<g->funcion_random(0,1)<<endl;
    cout<<g->funcion_random(0,1)<<endl;
    cout<<g->funcion_random(0,10)<<endl;
    cout<<g->funcion_random(0,10)<<endl;
    cout<<g->funcion_random(0,10)<<endl;
    cout<<g->funcion_random(0,10)<<endl;
    cout<<g->funcion_random(0,100)<<endl;
    cout<<g->funcion_random(0,100)<<endl;
    cout<<g->funcion_random(0,100)<<endl;
    cout<<g->funcion_random(0,100)<<endl;
    delete g;
    return 0;

}
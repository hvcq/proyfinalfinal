#include <iostream>
#include <vector>
#include "Grilla.h"
using namespace std;

int main(){
    int n,m;
    cout<<"ingrese los valores de n y m"<<endl;
    cin>>n;
    cin>>m;
    Grilla * g = new Grilla(n,m);
    g->dibuja_grilla();
    //cout<<g->head_vertice()->derecha->derecha->abajo->abajo->abajo->num<<endl;
    return 0;

}
#include <iostream>
#include <vector>
#include "Grilla.h"
using namespace std;

int main(){
    srand(time(NULL));
    Grilla * g; 
    int n,m;
    cout<<"Ingrese los valores de n y m"<<endl;
    cin>>n;
    cin>>m;
    int agregaPesos;
    cout<<"¿Desea agregar pesos a las aristas? [1] si [otro numero] no"<<endl;
    cin>>agregaPesos;
    if(agregaPesos == 1){
        cout<<"ingrese los valores de a y b"<<endl;
        int a,b;
        cin>>a;
        cin>>b;
        g = new Grilla(n,m,a,b);
    }else{
        g = new Grilla(n,m);
    }
    g->dibuja_grilla();
    //cout<<g->head_vertice()->derecha->derecha->abajo->abajo->abajo->num<<endl;
    delete g;
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include "Grilla.h"
using namespace std;

int main(){
    srand(time(NULL));
    Grilla * g; 
    int a,b,aa,bb,n,m;
    vector<arista *> arbol;
    cout<<"Ingrese los valores de n y m de la Grilla"<<endl;
    cin>>n;
    cin>>m;
    bool salir = false;
    int seleccion;
    do{
        cout<<endl;
        cout<<"--------------------------------------------------"<<endl;
        cout<<"Seleccion:"<<endl;
        cout<<"           Dibuja Grilla con pesos             [1]"<<endl;
        cout<<"           Dibuja Grilla sin pesos             [2]"<<endl;
        cout<<"           Crea y dibuja laberinto             [3]"<<endl;
        cout<<"           Ejecutar Kruskal y retornar aristas [4]"<<endl; 
        cout<<"           Llamar a funcion random             [5]"<<endl;  
        cout<<"           Salir                               [0]"<<endl;
        cout<<"--------------------------------------------------"<<endl;
        cin>>seleccion;
        switch(seleccion){
            case 0:
            salir = true;
            break;
            case 1:
                cout<<"Ingrese los valores de [a,b]"<<endl;
                cin>>a;
                cin>>b;
                g = new Grilla(n,m,a,b);
                g->dibuja_grilla_cp();
                delete g;
            break;
            case 2:
                g = new Grilla(n,m);
                g->dibuja_grilla_sp();
                delete g;
            break;
            case 3:
                g = new Grilla(n,m);
                g->dibuja_grilla_sp();
                cout<<"---- Laberinto ----"<<endl;
                g->laberinto();
                g->dibuja_laberinto();
                delete g;
            break;
            case 4:
                cout<<"Ingrese los valores de [a,b]"<<endl;
                cin>>a;
                cin>>b;
                g = new Grilla(n,m,a,b);
                g->dibuja_grilla_cp();
                cout<<"---- Aristas ----"<<endl;
                arbol = g->kruskal();
                delete g;
            break;
            case 5:
                cout<<"Ingrese los valores de [a,b]"<<endl;
                cin>>aa;
                cin>>bb;
                cout<<"Valor obtenido de funcion_random(a,b) : "<<g->funcion_random(aa,bb)<<endl;
            break;
            default:
                cout<<"Selección inválida, ingrese una opción correcta."<<endl<<endl;
        }
    }while(salir != true);
    return 0;
}
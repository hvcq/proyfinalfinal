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
    cout<<"Seleccion: Grilla sin pesos[0]"<<endl;
    cout<<"           Grilla con pesos[otro]"<<endl;
    cin>>agrega;
    bool salir = false;
    int seleccion;
    do{
        cout<<"Seleccion: Dibuja Grilla     [0]"<<endl;
        if(agrega == 0){
            cout<<"           Crea y dibuja laberinto     [0]"<<endl; 
        }else{
            
        }
        cout<<"           Salir     [-1]"<<endl;
        cin>>seleccion;
    }while(salir != true);
    if(agrega == 1){
        cout<<"ingrese los valores de a y b"<<endl;
        int a,b;
        cin>>a;
        cin>>b;
        g = new Grilla(n,m,a,b);
        g->dibuja_grilla_cp();
    }else{
        g = new Grilla(n,m);
        //g->dibuja_grilla_sp();
    }
    
    vector<arista *> arbol = g->kruskal();
    g->laberinto(); //falla en algun random
    cout<<"Laberinto formado exitosamente"<<endl;
    //g->lee_celdas();
    /*cout<<endl;
    arista * aux_a = g->head_arista()->siguiente;
    int contador = 0;
    while(aux_a != NULL){
        if((aux_a->pared != true)&&(aux_a->eliminada != true)){
            cout<<"la arista ("<<contador<<") : c1("<<aux_a->c1->x<<","<<aux_a->c1->y<<")";
            cout<<" - c2("<<aux_a->c2->x<<","<<aux_a->c2->y<<")"<<endl;
        }
        ++contador;
        aux_a = aux_a->siguiente;
    }*/
    //g->dibuja_laberinto();

    delete g;
    return 0;
}
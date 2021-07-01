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
void Grilla::dibuja_grilla_sp(){
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
                cout<<"O--"<<aux_arista->peso<<"--O"<<endl;
            }else{
                for(int i = 0; i<ene; ++i){
                    if(i == 0){
                        aux_h1 = aux_v1;
                        for(int j = 0; j<eme; ++j){
                            if(j == 0){
                                aux_arista = arista_asociada(aux_h1,aux_h1->derecha);
                                cout<<"O--"<<aux_arista->peso<<"--O";
                            }else{
                                aux_arista = arista_asociada(aux_h1,aux_h1->derecha);
                                cout<<"--"<<aux_arista->peso<<"--O";
                            }
                            aux_h1 = aux_h1->derecha;
                        }
                        cout<<endl;
                    }
                    aux_h1 = aux_v1;
                    for(int j = 0; j<=eme; ++j){
                        cout<<"|     ";
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
                        cout<<"|     ";
                        aux_h1 = aux_h1->derecha;
                    }
                    cout<<endl;
                    aux_h1 = aux_v2;
                    for(int j = 0; j<eme; ++j){
                        if(j == 0){
                            aux_arista = arista_asociada(aux_h1,aux_h1->derecha);
                            cout<<"O--"<<aux_arista->peso<<"--O";
                        }else{
                            aux_arista = arista_asociada(aux_h1,aux_h1->derecha);
                            cout<<"--"<<aux_arista->peso<<"--O";
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

void Grilla::dibuja_grilla_cp(){
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
                cout<<"O--"<<aux_arista->peso<<"--O"<<endl;
            }else{
                for(int i = 0; i<ene; ++i){
                    if(i == 0){
                        aux_h1 = aux_v1;
                        for(int j = 0; j<eme; ++j){
                            if(j == 0){
                                aux_arista = arista_asociada(aux_h1,aux_h1->derecha);
                                cout<<"O--"<<aux_arista->peso<<"--O";
                            }else{
                                aux_arista = arista_asociada(aux_h1,aux_h1->derecha);
                                cout<<"--"<<aux_arista->peso<<"--O";
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
                            cout<<"O--"<<aux_arista->peso<<"--O";
                        }else{
                            aux_arista = arista_asociada(aux_h1,aux_h1->derecha);
                            cout<<"--"<<aux_arista->peso<<"--O";
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

char Grilla::enteroACaracter(int numero){
    return numero + '0';
}

void Grilla::convertToBinary(string & str,int n){
    if (n / 2 != 0) {
        convertToBinary(str,(n / 2));
    }
    char c = enteroACaracter(n%2);
    str.push_back(c);
}

int Grilla::funcion_random(int a,int b){
    if(a > b){
        cout<<"a y b no representan un intervalo [a,b] correcto"<<endl;
        throw;
    }
    if((a == 0)&&(b == 0)){
        return 0;
    }else{
        if((a == 0)&&(b == 1)){
            return rand()&1;
        }
    }
    string str_a;
    string str_b;
    // Pasa los enteros a string
    convertToBinary(str_a,a);
    convertToBinary(str_b,b);
    // Pasa los string de los enteros a una representacion binaria contenida en
    // las cadenas de caracteres cadena_a y cadena_b
    char cadena_a [9];
    char cadena_b [9];
    cadena_a[8] = '\0';
    cadena_b[8] = '\0';
    memset(cadena_a,'0',8);
    memset(cadena_b,'0',8);
    for(int i = 0; i < str_a.length(); ++i){
        cadena_a[8 - str_a.length() + i] = str_a.at(i);
    }
    for(int i = 0; i < str_b.length(); ++i){
        cadena_b[8 - str_b.length() + i] = str_b.at(i);
    }
    //Verifica hasta que posicion los bit no varian en el entero b
    int pos_b = 0;
    while(cadena_b[pos_b] == '0'){
        ++pos_b;
    }
    //Le asigna un bit aleatorio a las columnas que siguen de la posicion antes mencionada
    //Esto nos devolvera una representacion binaria de un entero que esta en el rango [a,b]
    char cadena_random [9];
    cadena_random[8] = '\0';
    memset(cadena_random,'0',8);
    int random;
    for(int i = pos_b; i< 8; ++i){
        random = rand()&1;
        cadena_random[i] = enteroACaracter(random);
    }
    int aux_int = stoi(cadena_random, nullptr, 2);
    if((aux_int < a) || (aux_int > b)){
        int aproxima = rand()&1;
        if(aproxima == 0){
            //Acota el entero asemejandolo a 'a', hasta que este en el rango [a,b]
            int pos_a = pos_b;
            while((aux_int < a) || (aux_int > b)){
                cadena_random[pos_a] = cadena_a[pos_a]; 
                aux_int = stoi(cadena_random, nullptr, 2);
                ++pos_a;
            }
        }else{
            //Acota el entero asemejandolo a 'b', hasta que este en el rango [a,b]
            while((aux_int < a) || (aux_int > b)){
                cadena_random[pos_b] = cadena_b[pos_b]; 
                aux_int = stoi(cadena_random, nullptr, 2);
                ++pos_b;
            }
        }
    }
    return aux_int;
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
            nubes->Makeset(aux_h);
            aux_h = aux_h->derecha;
        }
        aux_v = aux_v->abajo;
        aux_h = aux_v;
    }
    //En el constructor de Grilla pasamos las aristas
    vector<arista *> MST;
    arista * arista_aux;
    int vueltas = 0;
    while (minHeap.empty() == false){
        arista_aux = minHeap.top();
        minHeap.pop();
        ++vueltas;
        if((nubes->Find(arista_aux->a)) != (nubes->Find(arista_aux->b))){
            MST.push_back(arista_aux);
            nubes->Union(arista_aux->a,arista_aux->b);
        }
    }
    /*cout<<"pase el find y union"<<endl;
    for(int i = 0 ; i < MST.size(); i++){
         cout<<"("<<MST.at(i)->a->num<<" , "<<MST.at(i)->b->num<<") "<<" Peso arista:"<<MST.at(i)->peso<<endl;
    }*/
    return MST;
}

int Grilla::size(){
    //(n+1)*(m+1)
    return -1;
}
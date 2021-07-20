 #include <iostream>
#include <bits/stdc++.h>
#include <chrono>

using namespace std;

/*
struct nodo{
    int key;
    int num;
};

class myComparator
{
public:
    int operator() (const nodo n1, const nodo n2)
    {
        return n1.key > n2.key;
    }
};
*/

/*
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
}*/

char enteroACaracter(int numero){
    return numero + '0';
}

void convertToBinary(string & str,int n){
    if (n / 2 != 0) {
        convertToBinary(str,(n / 2));
    }
    char c = enteroACaracter(n%2);
    str.push_back(c);
}

int random(int a,int b){
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
    char cadena_a [33];
    char cadena_b [33];
    cadena_a[32] = '\0';
    cadena_b[32] = '\0';
    memset(cadena_a,'0',32);
    memset(cadena_b,'0',32);
    for(int i = 0; i < str_a.length(); ++i){
        cadena_a[32 - str_a.length() + i] = str_a.at(i);
    }
    for(int i = 0; i < str_b.length(); ++i){
        cadena_b[32 - str_b.length() + i] = str_b.at(i);
    }
    //Verifica hasta que posicion los bit no varian en el entero b
    int pos_b = 0;
    while(cadena_b[pos_b] == '0'){
        ++pos_b;
    }
    //Le asigna un bit aleatorio a las columnas que siguen de la posicion antes mencionada
    //Esto nos devolvera una representacion binaria de un entero que esta en el rango [a,b]
    char cadena_random [33];
    cadena_random[32] = '\0';
    memset(cadena_random,'0',32);
    int random;
    for(int i = pos_b; i< 32; ++i){
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


int main(){
    srand(time(NULL));
    // Creates a min heap
    cout<<"ingresa los valores de a y b"<<endl;
    int a,b;
    cin>>a;
    cin>>b;
    for(int i = 0; i < 20 ; i++){
        auto start = chrono::high_resolution_clock::now();
        int p = random(a,b);
        auto finish = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds> (finish - start).count();
        cout <<"total time "<< duration << " [ns]" << " \n";
    }
    /*
    vector<int> letras;
    for(int i = 0;i<640;++i)
        letras.push_back(i);
    /*for(int i = 0;i<10;++i)
        cout<<letras.at(i)<<" ";
    cout<<endl;*/
    /*cout<<"--------"<<endl;
    char aux_c;
    int num_random;
    int pos_random;
    while(letras.size() != 0){
        if(letras.size() == 1){
            num_random = 0;
        }else{
            num_random = random(0,letras.size() - 1);
        }
        aux_c = letras.at(num_random);
        /*cout<<"letra: "<<aux_c<<endl;*/
        /*
        letras.erase(letras.begin()+num_random);
    }
    */
    
    /*
    int i = stoi("11110", nullptr, 2);
    cout<<"imprime binario to int :"<<i<<endl;
    */
    /*priority_queue <nodo *, vector<nodo *>, myComparator> pq;
    nodo * aux = new nodo();
    aux->key = 5;
    aux->num = 1;
    pq.push(aux);
    aux->key = 1;
    aux->num = 5;
    pq.push(aux);
    aux->key = 2;
    aux->num = 4;
    pq.push(aux);
    aux->key = 3;
    aux->num = 2;
    pq.push(aux);
    aux->key = 500;
    aux->num = 3;
    pq.push(aux);
 
    // One by one extract items from min heap
    while (pq.empty() == false)
    {
        cout << pq.top()->key << " ";
        pq.pop();
    }
 
    return 0;
    */
    /*srand(time(NULL));
    cout<<(rand()&1)<<endl;
    cout<<(rand()&1)<<endl;
    cout<<(rand()&1)<<endl;
    cout<<(rand()&1)<<endl;
    cout<<(rand()&1)<<endl;
    */
}


// C++ program to use priority_queue to implement Min Heap
// for user defined class
/*
#include <bits/stdc++.h>
using namespace std;
 
// User defined class, Point
class Point
{
   int x;
   int y;
public:
   Point(int _x, int _y)
   {
      x = _x;
      y = _y;
   }
   int getX() const { return x; }
   int getY() const { return y; }
};
 
// To compare two points
class myComparator
{
public:
    int operator() (const Point& p1, const Point& p2)
    {
        return p1.getX() > p2.getX();
    }
};
 
// Driver code
int main ()
{
    // Creates a Min heap of points (order by x coordinate)
    priority_queue <Point, vector<Point>, myComparator > pq;
 
    // Insert points into the min heap
    pq.push(Point(10, 2));
    pq.push(Point(2, 1));
    pq.push(Point(1, 5));
 
    // One by one extract items from min heap
    while (pq.empty() == false)
    {
        Point p = pq.top();
        cout << "(" << p.getX() << ", " << p.getY() << ")";
        cout << endl;
        pq.pop();
    }
 
    return 0;
}
*/
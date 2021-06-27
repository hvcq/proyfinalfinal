#include <iostream>
#include <bits/stdc++.h>

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
    string str_a;
    string str_b;
    convertToBinary(str_a,a);
    convertToBinary(str_b,b);
    cout<<"str_a: "<<str_a<<endl;
    cout<<"str_b: "<<str_b<<endl;
    return 0;
}

int main(){
    srand(time(NULL));
    // Creates a min heap
    int p = random(0,3);
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
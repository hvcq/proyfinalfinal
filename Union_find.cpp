#include "Union_find.h"

Union_find::Union_find(){
    
}

Union_find::~Union_find(){
    
}
/*
Para vertices
*/
void Union_find::Makeset(vertice * x){
    x->padre = x;
    x->rank = 0;
}

void Union_find::Link(vertice * x, vertice * y){
    if(x->rank == y->rank){
        y->padre = x;
        x->rank = x->rank + 1;
    }else{
        if(x->rank > y->rank){
            y->padre = x;
        }else{
            x->padre = y;
        }
    }
}

vertice * Union_find::Find(vertice * x){
    if (x != x->padre){
        x->padre = Find(x->padre);
    }
    return x->padre;
}

void Union_find::Union(vertice * x, vertice *y){
    Link(Find(x),Find(y));
}

/*
Para celdas
*/

void Union_find::Makeset(celda * x){
    x->padre = x;
    x->rank = 0;
}
void Union_find::Link(celda * x,celda * y){
    if(x->rank == y->rank){
        y->padre = x;
        x->rank = x->rank + 1;
    }else{
        if(x->rank > y->rank){
            y->padre = x;
        }else{
            x->padre = y;
        }
    }
}

celda * Union_find::Find(celda * x){
    if (x != x->padre){
        x->padre = Find(x->padre);
    }
    return x->padre;
}

void Union_find::Union(celda * x, celda * y){
    Link(Find(x),Find(y));
}
#include <stdlib.h>
#include "nodocircular.h"

NodoC* nodo_crear(int dato){
    NodoC *nodo = (NodoC*)malloc(sizeof(NodoC));
    if(nodo!=NULL){
        nodo->dato=dato;
        nodo->siguiente = nodo;
    }
    return nodo;
}

void nodo_destruir(NodoC* nodo){
    free(nodo);
    nodo=NULL;
}
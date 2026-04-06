#include <stdlib.h>
#include "nododoble.h"

NodoD* nodo_crear(int dato){
    NodoD *nodo = (NodoD*)malloc(sizeof(NodoD));
    if(nodo!=NULL){
        nodo->dato=dato;
        nodo->siguiente=NULL;
        nodo->atras=NULL;
    }
    return nodo;
}

void nodo_destruir(NodoD* nodo){
    free(nodo);
    nodo=NULL;
}
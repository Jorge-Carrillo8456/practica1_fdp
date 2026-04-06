#ifndef NODODOBLE_H
#define NODODOBLE_H

typedef struct NodoD {
    int dato;
    struct NodoD* siguiente;
    struct NodoD* atras;
} NodoD;

NodoD* nodo_crear(int dato);
void nodo_destruir(NodoD* nodo);

#endif
#ifndef NODOCIRCULAR_H
#define NODOCIRCULAR_H

typedef struct NodoC {
    int dato;
    struct NodoC* siguiente;
} NodoC;

NodoC* nodo_crear(int dato);
void nodo_destruir(NodoC* nodo);

#endif
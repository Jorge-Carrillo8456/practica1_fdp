#include "piladoble.h"
#include <stdio.h>

Pila* pila_crear(){
    return lista_crear();
}

int pila_vacia(Pila* pila){
    return lista_vacia(pila);
}

void pila_push(Pila* pila, int dato){
    lista_insertar_head(pila, dato);
}

int pila_pop(Pila* pila){
    return lista_eliminar_head(pila);
}

int pila_top(Pila* pila){
    if(lista_vacia(pila)==1){
        return -1;
        //esto lo vi en un foro, para evitar errores de vulneraibilidad
    }
    return pila->head->dato;
}

void pila_destruir(Pila* pila){
    lista_destruir(pila);
}
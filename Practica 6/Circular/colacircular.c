#include "colacircular.h"
#include <stdio.h>

Cola* cola_crear(){
    return lista_crear();
}

int cola_vacia(Cola* cola){
    return lista_vacia(cola);
}

void cola_enqueue(Cola* cola, int dato){
    lista_insertar_tail(cola, dato);
}

int cola_dequeue(Cola* cola){
    return lista_eliminar_head(cola);
}

int cola_frente(Cola* cola){
    if(lista_vacia(cola)==1){
        return -1;
        //esto lo vi en un foro, para evitar errores de vulneraibilidad
    }
    return  cola->head->dato;
}

void cola_destruir(Cola* cola){
    lista_destruir(cola);
}
#ifndef COLACIRCULAR_H
#define COLACIRCULAR_H

#include "listacircular.h"

typedef ListaC Cola;

Cola* cola_crear();

int cola_vacia(Cola* cola);

/*
TODO
insertar por tail
*/
void cola_enqueue(Cola* cola, int dato);

/*
TODO
eliminar por head
*/
int cola_dequeue(Cola* cola);

/*
TODO
regresar frente (head)
*/
int cola_frente(Cola* cola);

void cola_destruir(Cola* cola);

#endif
#ifndef PILACIRCULAR_H
#define PILACIRCULAR_H

#include "listacircular.h"

typedef ListaC Pila;

Pila* pila_crear();

int pila_vacia(Pila* pila);

/*
TODO
push debe insertar por tail
*/
void pila_push(Pila* pila, int dato);

/*
TODO
pop debe eliminar por tail
*/
int pila_pop(Pila* pila);

/*
TODO
regresa elemento superior (tail)
*/
int pila_top(Pila* pila);

void pila_destruir(Pila* pila);

#endif
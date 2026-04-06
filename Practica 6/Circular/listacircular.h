#ifndef LISTA_H
#define LISTA_H

#include "nodocircular.h"

typedef struct {
    NodoC* head;
    NodoC* tail;
} ListaC;

ListaC* lista_crear();

int lista_vacia(ListaC* lista);

void lista_insertar_head(ListaC* lista, int dato);

void lista_insertar_tail(ListaC* lista, int dato);

int lista_eliminar_head(ListaC* lista);

int lista_eliminar_tail(ListaC* lista);

void lista_imprimir(ListaC* lista);

void lista_destruir(ListaC* lista);

#endif
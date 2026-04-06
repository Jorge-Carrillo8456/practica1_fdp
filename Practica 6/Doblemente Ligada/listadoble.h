#ifndef LISTA_H
#define LISTA_H

#include "nododoble.h"

typedef struct {
    NodoD* head;
    NodoD* tail;
} ListaD;

ListaD* lista_crear();

int lista_vacia(ListaD* lista);

void lista_insertar_head(ListaD* lista, int dato);

void lista_insertar_tail(ListaD* lista, int dato);

int lista_eliminar_head(ListaD* lista);

int lista_eliminar_tail(ListaD* lista);

void lista_imprimir(ListaD* lista);

void lista_destruir(ListaD* lista);

#endif
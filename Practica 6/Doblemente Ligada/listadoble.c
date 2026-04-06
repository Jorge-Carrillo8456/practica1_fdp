#include <stdio.h>
#include <stdlib.h>
#include "listadoble.h"

ListaD* lista_crear(){
    ListaD *lista=(ListaD*)malloc(sizeof(ListaD));
    if(lista!=NULL){
        lista->head = NULL;
        lista->tail = NULL;
        return lista;
    }
}

int lista_vacia(ListaD* lista){
    if((lista->head==NULL)){
        return 1; //Si esta vacia 
    } else{
        return 0; //No esta vacia 
    }
}

void lista_insertar_head(ListaD* lista, int dato){
        NodoD *nuevo_nodo = nodo_crear(dato);
    if(lista_vacia(lista)==1){
        lista->head = nuevo_nodo;
        lista->tail = nuevo_nodo;
    } else if(lista_vacia(lista)==0){
        lista->head->atras=nuevo_nodo;
        nuevo_nodo->siguiente = lista->head;
        lista->head = nuevo_nodo;
    }
}

void lista_insertar_tail(ListaD* lista, int dato){
    NodoD *nuevo_nodo = nodo_crear(dato);
    if(lista_vacia(lista)==1){
        lista->head = nuevo_nodo;
        lista->tail = nuevo_nodo;
    } else if(lista_vacia(lista)==0){
        nuevo_nodo->atras=lista->tail;
        lista->tail->siguiente = nuevo_nodo;
        lista->tail = nuevo_nodo;
    }
}

int lista_eliminar_head(ListaD* lista){
    if(lista_vacia(lista)==1){
        return -1;
    } else if(lista_vacia(lista)==0) {
        NodoD *nodo_eliminar = lista->head;
        int dato_eliminado = nodo_eliminar->dato;
        lista->head = lista->head->siguiente;
        if (lista->head != NULL) {
            lista->head->atras = NULL;
        } else {
            lista->tail = NULL; 
        } 
        nodo_destruir(nodo_eliminar);
        return dato_eliminado;
    }
    return -1;
}

int lista_eliminar_tail(ListaD* lista){
    if(lista_vacia(lista)==1){
        return -1;
    } else if(lista_vacia(lista)==0) {
        NodoD *nodo_eliminar = lista->tail;
        int dato = nodo_eliminar->dato;
        lista->tail = lista->tail->atras; 
        if (lista->tail != NULL) {
            lista->tail->siguiente = NULL; 
        } else {
            lista->head = NULL; 
        }
        nodo_destruir(nodo_eliminar);
        return dato;
    }
    return -1;
}

void lista_imprimir(ListaD* lista){
        NodoD* actual = lista->head;

    while(actual != NULL)
    {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }

    printf("NULL\n");
}

void lista_destruir(ListaD* lista){
        if(lista->head==NULL){
        free(lista);
        return ;
    } else {
        while (lista->head != NULL ){
        NodoD *nodo_eliminar = lista->head;
        lista->head=lista->head->siguiente;
        free(nodo_eliminar);
        nodo_eliminar=NULL;  
        }
        free(lista);
        return ;
    }
}

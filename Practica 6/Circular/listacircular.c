#include <stdio.h>
#include <stdlib.h>
#include "listacircular.h"

ListaC* lista_crear(){
    ListaC *lista=(ListaC*)malloc(sizeof(ListaC));
    if(lista!=NULL){
        lista->head = NULL;
        lista->tail = NULL;
        return lista;
    }
}

int lista_vacia(ListaC* lista){
    if((lista->head==NULL)){
        return 1; //Si esta vacia 
    } else{
        return 0; //No esta vacia 
    }
}

void lista_insertar_head(ListaC* lista, int dato){
    NodoC *nuevo_nodo = nodo_crear(dato);
    if(lista_vacia(lista)==1){
        lista->head = nuevo_nodo;
        lista->tail = nuevo_nodo;
    } else if(lista_vacia(lista)==0){
        nuevo_nodo->siguiente = lista->head;
        lista->head = nuevo_nodo;
        lista->tail->siguiente=lista->head;
    }
}

void lista_insertar_tail(ListaC* lista, int dato){
    NodoC *nuevo_nodo = nodo_crear(dato);
    if(lista->head==NULL){
        lista->head = nuevo_nodo;
        lista->tail = nuevo_nodo;
    } else {
        lista->tail->siguiente = nuevo_nodo;
        lista->tail = nuevo_nodo;
        nuevo_nodo->siguiente=lista->head;
    }
}

int lista_eliminar_head(ListaC* lista) {
    if (lista_vacia(lista)) return -1;
    NodoC *nodo_eliminar = lista->head;
    int dato = nodo_eliminar->dato;
    if (lista->head == lista->tail) { 
        lista->head = NULL;
        lista->tail = NULL;
    } else {
        lista->head = lista->head->siguiente;
        lista->tail->siguiente = lista->head;
    }

    free(nodo_eliminar);
    return dato;
}

int lista_eliminar_tail(ListaC* lista){
if(lista->head==NULL){
        return -1;
    } else if((lista->head)==(lista->tail)){
        int dato_eliminado = lista->head->dato;
        //en teoria tambien se puede int dato_eliminado = lista->tail->dato;
        //ya que es el mismo
        free(lista->head);
        //como solo hay un nodo, tambien se puede hacer free(lista->tail);
        lista->head=NULL;
        lista->tail=NULL;
        return dato_eliminado;
    } else {
        int dato_eliminado = lista->tail->dato;
        NodoC *recorredor = lista->head;
        while(recorredor->siguiente!=(lista->tail)){
            recorredor = recorredor->siguiente;
        }
        free(lista->tail);
        lista->tail=recorredor;
        lista->tail->siguiente=lista->head;
        return dato_eliminado;
    }
    return -1;
}

void lista_imprimir(ListaC* lista){
    if (lista_vacia(lista)) {
        printf("Lista vacía\n");
        return;
    }
    NodoC* actual = lista->head;
    do {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    } while (actual != lista->head); 
    //supongo que pude haber utilizado un ciclo while, que sea, while(actual!=lista->tail->siguiente->head)
    //pero por seguridad y practicidad, lo hice con el ciclo do while 
    printf("(Vuelve al inicio: %d)\n", lista->head->dato);
}


void lista_destruir(ListaC* lista) {
    if (lista_vacia(lista)) {
        free(lista);
        return;
    }
    lista->tail->siguiente = NULL; 
    while (lista->head != NULL) {
        NodoC *temp = lista->head;
        lista->head = lista->head->siguiente;
        free(temp);
    }
    free(lista);
}
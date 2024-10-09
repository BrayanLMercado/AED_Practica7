/*
Nombre: Brayan López Mercado
Matrícula: 1280838
Fecha De Entrega: 9 De Octubre De 2024
Materia: Algoritmos y Estructura De Datos
Grupo: 552
Practica 7: Estrategias De Recorridos En Arboles Binarios
*/

#include <stdio.h>
#include <stdlib.h>

struct Nodo{
    int dato;
    struct Nodo* hijoIzq;
    struct Nodo* hijoDer;
};

void recorridoPreOrden(struct Nodo* raiz);
void recorridoInOrden(struct Nodo* raiz);
void recorridoPostOrden(struct Nodo* raiz);
void insertar(struct Nodo* raiz,int dato);
struct Nodo* crearNodo(int dato);
struct Nodo* eliminar(struct Nodo* raiz, int dato);

int main(){
    struct Nodo* raiz=NULL;
    int opt=0;
    int dato;
    do{
        printf("1) Insertar Nodo\n");
        printf("2) Eliminar Nodo\n");
        printf("   Recorrer El Arbol\n");
        printf("\t3) Recorrido Pre-Orden\n");
        printf("\t4) Recorrido In-Orden\n");
        printf("\t5) Recorrido Post-Orden\n");
        printf("6) Salir\n");
        printf("Selecciona Una Opcion: ");
        scanf("%d",&opt);
        printf("\n");
        switch(opt){
            case 1:
                printf("Numero a Insertar: ");
                scanf("%d",&dato);
                if(raiz==NULL)
                    raiz=crearNodo(dato);
                else
                    insertar(raiz,dato);
                printf("\n");
                break;
            case 2:
                if(raiz==NULL)
                    printf("No Hay Nodos En El Arbol\n");
                else{
                    printf("Numero a Borrar: ");
                    scanf("%d",&dato);
                    raiz=eliminar(raiz,dato);
                }
                break;
            case 3:
                if(raiz==NULL)
                    printf("No Hay Nodos En El Arbol\n");
                else
                    recorridoPreOrden(raiz);
                printf("\n");
                break;
            case 4:
                if(raiz==NULL)
                    printf("No Hay Nodos En El Arbol\n");
                else
                    recorridoInOrden(raiz);  
                printf("\n");
                break;
            case 5:
                if(raiz==NULL)
                    printf("No Hay Nodos En El Arbol\n");
                else
                    recorridoPostOrden(raiz);  
                printf("\n");
                break;
        };
    }while(opt!=6);
    free(raiz);
    return 0;
}


struct Nodo* crearNodo(int dato){
    struct Nodo* nuevoNodo=(struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato=dato;
    nuevoNodo->hijoIzq=NULL;
    nuevoNodo->hijoDer=NULL;
    return nuevoNodo;

}

void insertar(struct Nodo* raiz,int dato){
    struct Nodo* nodoActual=raiz;
    if(dato==nodoActual->dato){
        printf("El Numero Ya Existe Dentro Del Arbol");
        return;
    }
    struct Nodo* nuevoNodo=crearNodo(dato);
    if(nodoActual->hijoIzq==NULL && dato<nodoActual->dato){
        nodoActual->hijoIzq=nuevoNodo;
    }
    else if(nodoActual->hijoDer==NULL && dato>nodoActual->dato){
        nodoActual->hijoDer=nuevoNodo;
    }
    else{
        if (dato<nodoActual->dato)
            insertar(nodoActual->hijoIzq, dato);
        else 
            insertar(nodoActual->hijoDer,dato);
    }
}

struct Nodo* eliminar(struct Nodo* raiz, int dato){
    struct Nodo* nodoActual=raiz;
    if(nodoActual==NULL){
        printf("No Se Encontro El Numero Dentro Del Arbol\n");
        return raiz;
    }
    if(dato<nodoActual->dato)
        nodoActual->hijoIzq=eliminar(nodoActual->hijoIzq,dato);
    else if(dato>raiz->dato)
        nodoActual->hijoDer=eliminar(nodoActual->hijoDer,dato);
    else{
        struct Nodo* auxiliar;
        if(nodoActual->hijoIzq==NULL){
            auxiliar=nodoActual->hijoDer;
            free(nodoActual);
            return auxiliar;
        }
        else if(nodoActual->hijoDer==NULL){
            auxiliar=nodoActual->hijoIzq;
            free(nodoActual);
            return auxiliar;
        }
        else{
            struct Nodo* nodoSucesor=nodoActual->hijoDer;
            while(nodoSucesor->hijoIzq!=NULL)
                nodoSucesor=nodoSucesor->hijoDer;
            nodoSucesor->hijoIzq=nodoActual->hijoIzq;
            free(nodoActual);
            return nodoSucesor;
        }
    }
    return nodoActual;
}

void recorridoPreOrden(struct Nodo* raiz){
    if(raiz==NULL)
        return;
    else{
        printf("%d ",raiz->dato);
        recorridoPreOrden(raiz->hijoIzq);
        recorridoPreOrden(raiz->hijoDer);
    }
}

void recorridoInOrden(struct Nodo* raiz){
    if(raiz==NULL)
        return;
    else{
        recorridoInOrden(raiz->hijoIzq);
        printf("%d ",raiz->dato);
        recorridoInOrden(raiz->hijoDer);
    }
}

void recorridoPostOrden(struct Nodo* raiz){
    if(raiz==NULL)
        return;
    else{
        recorridoPostOrden(raiz->hijoIzq);
        recorridoPostOrden(raiz->hijoDer);
        printf("%d ",raiz->dato);
    }
}

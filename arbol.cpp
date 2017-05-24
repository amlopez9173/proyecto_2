#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int dato;
    nodo *izq;
    nodo *der;
};

void menu(nodo *&);
void insertar_nodo(nodo *&,int);
void mostrar_preorden(nodo *);
void mostrar_inorden(nodo *);
void mostrar_posorden(nodo *);
bool buscar_nodo(nodo *,int);
void modificar_nodo(nodo *&, int );

int main(){
    nodo *arbol=NULL;
    menu(arbol);
}

void menu(nodo *&arbol){
    int x, y, a;

    system("cls");
    printf("******ARBOLES BINARIOS*********\n");
    printf("1. Insertar elementos\n");
    printf("2. Mostrar arbol\n");
    printf("3. Buscar nodo\n");
    printf("4. Modificar nodo\n");
    printf("5. Salir\n");
    printf("Digite opcion: ");
    scanf("%d",&x);

    switch(x){
        case 1:{
            do{
               printf("Ingrese dato: ");
               scanf("%d",&a);
               insertar_nodo(arbol,a);
               printf("Ingresar mas datos 1.SI  2.NO: ");
               scanf("%d",&y);
            }while(y==1);
        }break;
        case 2:{
            system("cls");
            printf("1. Mostrar arbol en preorden\n");
            printf("2. Mostrar arbol en inorden\n");
            printf("3. Mostrar arbol en posorden\n");
            printf("Digite opcion: ");
            scanf("%d",&a);
            switch(a){
                case 1:{
                    mostrar_preorden(arbol);
                    printf("\n");
                }break;
                case 2:{
                    mostrar_inorden(arbol);
                    printf("\n");
                }break;
                case 3:{
                    mostrar_posorden(arbol);
                    printf("\n");
                }break;
                default: printf("Opcion incorrecta\n");
            }
        }break;
        case 3:{
            printf("Ingrese dato que desea buscar: ");
            scanf("%d",&a);
            if(buscar_nodo(arbol,a)==true){
                printf("dato encontrado\n");
            }else{
                printf("dato no encontrado\n");
            }
        }break;
        case 4:{
            printf("Ingrese dato que desea modificar: ");
            scanf("%d",&a);
            modificar_nodo(arbol,a);
        }break;
        case 5:{
            exit(5);
        }
    }
    system("pause");
    menu(arbol);
}

nodo *crear_nodo(int a){
    nodo *nuevo_nodo=(nodo*)malloc(sizeof(nodo));
    nuevo_nodo->dato=a;
    nuevo_nodo->izq=NULL;
    nuevo_nodo->der=NULL;

    return nuevo_nodo;
}

void insertar_nodo(nodo *&arbol, int a){
    int x;
    if(arbol==NULL){
        nodo *nuevo_nodo=crear_nodo(a);
        arbol=nuevo_nodo;
    }else{
        printf("Insertar 1.Izquierda  2.Derecha: ");
        scanf("%d",&x);
        if(x==1){
            insertar_nodo(arbol->izq,a);
        }else{
            insertar_nodo(arbol->der,a);
        }
    }
}

void mostrar_preorden(nodo *arbol){
    if(arbol==NULL){
        return;
    }else{
        printf("%d ",arbol->dato);
        mostrar_preorden(arbol->izq);
        mostrar_preorden(arbol->der);
    }
}

void mostrar_inorden(nodo *arbol){
    if(arbol==NULL){
        return;
    }else{
        mostrar_inorden(arbol->izq);
        printf("%d ",arbol->dato);
        mostrar_inorden(arbol->der);
    }
}

void mostrar_posorden(nodo *arbol){
    if(arbol==NULL){
        return;
    }else{
        mostrar_posorden(arbol->izq);
        mostrar_posorden(arbol->der);
        printf("%d ",arbol->dato);
    }
}

bool buscar_nodo(nodo *arbol, int a){
    if(arbol==NULL){
        return false;
    }else if(arbol->dato==a){
        return true;
    }else if(a< arbol->dato){
        return buscar_nodo(arbol->izq,a);
    }
    else{
        return buscar_nodo(arbol->der,a);
    }
}

void modificar_nodo(nodo *&arbol, int a){
    int x;
    if(arbol==NULL){
        return;
    }else if(arbol->dato==a){
       printf("Ingrese nuevo dato: ");
            scanf("%d",&x);
            arbol->dato=x;
    }else if(a < arbol->dato){
        modificar_nodo(arbol->izq,a);
    }
    else{
        modificar_nodo(arbol->der,a);
    }
}

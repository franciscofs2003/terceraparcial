#include<stdio.h>
#include<stdlib.h>

struct nodo{
	struct nodo* hijo_izq;
	struct nodo* hijo_der;
	int dato;
};

struct nodo* nuevoNodo(int dato){
		size_t tam_nodo = sizeof(struct nodo);
			struct nodo* nuevo_nodo = (struct nodo*) malloc(tam_nodo);
			nuevo_nodo->dato = dato;
			nuevo_nodo->hijo_izq = NULL;
			nuevo_nodo->hijo_der = NULL;

	return nuevo_nodo;
}

void insertarNodo(struct nodo* nd, int dato){
	if(dato > nd->dato){
		if(nd->hijo_der == NULL){
			nd->hijo_der = nuevoNodo(dato);
		}else{
			insertarNodo(nd->hijo_der, dato);
		}
	}else{
		if(nd->hijo_izq == NULL){
			nd->hijo_izq = nuevoNodo(dato);
		}else{
			insertarNodo(nd->hijo_izq, dato);
		}
	}
}

	int rmd = 0;
void busqueda(struct nodo* nd, int m){
	rmd++;
	if(m == nd->dato){
		printf("\n%d se encontro en el nivel %d\n", m, rmd);
	}else if(m < nd->dato && nd->hijo_izq != NULL){
		busqueda(nd->hijo_izq, m);
	}else if(m > nd->dato && nd->hijo_der != NULL){
		busqueda(nd->hijo_der, m);
	}else{
		printf("\n%d el dato que ingreso no se encontro\n", m);
	}
}

int main(){
	int m = 0;
	struct nodo* raiz = NULL;
	raiz = nuevoNodo(9);
	insertarNodo(raiz, 8);
	insertarNodo(raiz, 12);
	insertarNodo(raiz, 13);
	insertarNodo(raiz, 15);
	insertarNodo(raiz, 19);
	insertarNodo(raiz, 13);
	insertarNodo(raiz, 21);
	insertarNodo(raiz, 25);
		printf("\ningrese el numero que desea buscar\n");
		scanf("%d", &m);

	busqueda(raiz, m);

	return 0;
}

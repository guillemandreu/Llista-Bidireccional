#ifndef _LISTA_ORD_H
#define _LISTA_ORD_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo {
	int e;
	struct _nodo * sig;
} Nodo;

typedef struct {
	Nodo * pri;
	Nodo * ant;
} ListaOrd;

void     LISTAORD_crea (ListaOrd * l);
//ListaOrd LISTAORD_crea ();

//NO EXISTE PARA EL USUARIO!
void     LISTAORD_anadir (ListaOrd * l, int e);
//ListaOrd LISTAORD_anadir (ListaOrd l, int e);

void LISTAORD_anadirOrdenado (ListaOrd * l, int e);

void     LISTAORD_eliminar (ListaOrd * l);
//ListaOrd LISTAORD_eliminar (ListaOrd l);

void LISTAORD_consultar (ListaOrd l, int * e);
//int  LISTAORD_consultar (ListaOrd l);

int LISTAORD_vacia (ListaOrd l);

void     LISTAORD_avanzar (ListaOrd * l);
//ListaOrd LISTAORD_avanzar (ListaOrd l);

int LISTAORD_final (ListaOrd l);

void     LISTAORD_irPrincipio (ListaOrd * l);
//ListaOrd LISTAORD_irPrincipio (ListaOrd l);

void     LISTAORD_destruye (ListaOrd * l);
//ListaOrd LISTAORD_destruye (ListaOrd l);


#endif

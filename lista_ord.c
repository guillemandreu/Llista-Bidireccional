#include "lista.h"

void LISTA_crea (Lista * l) {
	l->pri = (Nodo*) malloc (sizeof(Nodo));
	if (l->pri == NULL) {
		printf("Error al pedir memoria para el fantasma.\n");
	}
	else {
		l->ant = l->pri;
		l->pri->sig = NULL;
	}
}
void LISTA_anadir (Lista * l, int e) {
	Nodo * aux = (Nodo*) malloc (sizeof(Nodo));
	if (aux == NULL) {
		printf("Error al pedir memoria para inserir.\n");
	}
	else {
		aux->e = e;
		aux->sig = l->ant->sig;
		l->ant->sig = aux;
		l->ant = l->ant->sig;
	}
}

void LISTAORD_anadirOrdenado (ListaOrd * l, int e) {
	Nodo * aux;
	aux = l->ant;
	int encontrado = 0;
	int elem_consulta;

	LISTAORD_irPrincipio(l);
	while (!LISTAORD_final(*l) && !encontrado) { //encontrado == 0
		LISTAORD_consultar(*l, &elem_consulta);
		if (e < elem_consulta) {
			encontrado = 1;
		}
		else {
			LISTAORD_avanzar(l);
		}
	}
	LISTAORD_anadir(l, e);
}

void LISTA_eliminar (Lista * l) {
	Nodo * aux;
	if (l->ant->sig == NULL) {
		printf("Error. El pdi esta al final de la lista.\n");
	}
	else {
		aux = l->ant->sig;
		l->ant->sig = l->ant->sig->sig;
		//l->ant->sig = aux->sig;
		free(aux);
	}
}

void LISTA_consultar (Lista l, int * e) { 
	if (l.ant->sig == NULL) {
		printf("Error, estamos en el final de la lista.\n");
		*e = -1;
	}
	else {
		*e = l.ant->sig->e;
	}
}

int  LISTA_vacia (Lista l) {
	return l.pri->sig == NULL;
}

void LISTA_avanzar (Lista * l) {
	if (l->ant->sig == NULL) {
		printf("Error al avanzar. La lista esta al final.\n");
	}
	else {
		l->ant = l->ant->sig;
	}
}

int  LISTA_final (Lista l) {
	return l.ant->sig == NULL;
}

void LISTA_irPrincipio (Lista * l) {
	l->ant = l->pri;
}

void LISTA_destruir (Lista * l) {
	//Vaciar la lista de elementos validos
	LISTA_irPrincipio(l);
	while (!LISTA_final(*l)) {
		LISTA_eliminar(l);
	}
	//Liberar fantasma
	free(l->pri); //free(l->ant);
	l->pri = NULL;
	l->ant = NULL;
}


/*void LISTA_destruir (Lista * l) {
	Nodo * aux;

	while (l->pri != NULL) {
		aux = l->pri;
		l->pri = l->pri->sig;
		free(aux);
	}
	
	l->pri = NULL;
	l->ant = NULL;
}*/

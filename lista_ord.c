#include "lista_bid.h"

ListaBid LISTABID_crea () {
	ListaBid l;

	l.pri = NULL;
	l.pri = (Nodo*) malloc (sizeof(Nodo));
	if (l.pri == NULL) {
		printf("Error al pedir memoria para el primer fantasma.\n");
	}
	else {
		l.ult = NULL;
		l.ult = (Nodo*) malloc (sizeof(Nodo));
		if (l.ult == NULL) {
			printf("Error al pedir memoria para el segundo fantasma.\n");
			free(l.pri);
		}
		else {
			l.pri->sig = l.ult;
			l.pri->ant = NULL;
			
			l.ult->sig = NULL;
			l.ult->ant = l.pri;

			l.pdi = l.pri;
		}
	}

	return l;
}


ListaBid LISTABID_anadirDerecha (ListaBid l, int e) {
	Nodo * aux;
	
	if (l.pdi->sig == NULL) {
		printf("Error estoy en el ultimo fantasma.\n");
	}
	else {
		aux = (Nodo*) malloc (sizeof(Nodo));
		if (aux == NULL) {
			printf("Erro al pedir memoria.\n");
		}
		else {
			aux->e = e;
			aux->sig = l.pdi->sig;
			aux->ant = l.pdi;
			
			l.pdi->sig->ant = aux;
			l.pdi->sig = aux;
		}
	}

	return l;
}

ListaBid LISTABID_anadirIzquierda (ListaBid l, int e) {
	Nodo * aux;

	if (l.pdi->ant == NULL) {
		printf("Error, no puedo añadir a la izquierda del primer fantasma.\n");
	}
	else {
		aux = (Nodo*) malloc (sizeof(Nodo));
		if (aux == NULL) {
			printf("Error al pedir memoria.\n");
		}
		else {
			aux->e = e;
			aux->sig = l.pdi;
			aux->ant = l.pdi->ant;

			l.pdi->ant->sig = aux;
			//(*(*l.pdi).ant).sig = aux;

			l.pdi->ant = aux;
		}
	}
	return l;
}


ListaBid LISTABID_eliminar (ListaBid l) {
	Nodo * aux;

	if (l.pdi == l.pri || l.pdi == l.ult) {
		printf("Error, estoy apuntando a un fantasma.\n");
	}
	else {
		aux = l.pdi;

		l.pdi->ant->sig = l.pdi->sig;
		l.pdi->sig->ant = l.pdi->ant;
		l.pdi = l.pdi->sig;

		free(aux);
	}

	return l;
}

int      LISTABID_consultar (ListaBid l) {
	int e = -1;

	if (l.pdi == l.pri || l.pdi == l.ult) {
		printf("Error, estoy apuntando a un fantasma.\n ");
	}
	else {
		e = l.pdi->e;
	}

	return e;
}

int      LISTABID_vacia (ListaBid l) {
	return l.pri->sig == l.ult;	
	//return l.ult->ant == l.pri;
}

int      LISTABID_final (ListaBid l) {
	return l.pdi == l.ult;
}

int      LISTABID_principio (ListaBid l) {
	return l.pdi == l.pri;
}

ListaBid LISTABID_irPrincipio (ListaBid l) {
	l.pdi = l.pri->sig;

	return l;
}

ListaBid LISTABID_irFinal (ListaBid l) {
	l.pdi = l.ult->ant;

	return l;
}

ListaBid LISTABID_avanzar (ListaBid l) {
	if (l.pdi->sig == NULL) {
		printf("Error, estoy en el ultimo fantasma.\n");
	}
	else {
		l.pdi = l.pdi->sig;
	}

	return l;
}

ListaBid LISTABID_retroceder (ListaBid l) {
	if (l.pdi->ant == NULL) {
		printf("Error, estoy en el primer fantasma.\n");
	}
	else {
		l.pdi = l.pdi->ant;
	}

	return l;
}

ListaBid LISTABID_destruye (ListaBid l) {
	Nodo * aux;

	while (l.pri != NULL) {
		aux = l.pri;
		l.pri = l.pri->sig;
		free(aux);
	}

	l.pri = NULL;
	l.ult = NULL;
	l.pdi = NULL;

	return l;
}


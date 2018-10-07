#include <stdio.h>
#include <lista_ord.h>



void main (ListaBid * l) {
	ListaBid l_aux;
	 
	int opcio = 0;
	
		printf ("Benvingut!\n");
		while (opcio != 2 ) {

			printf ("\n 1.-Inserir element ordenadament.");
			printf ("\n 2.-Sortir ");
			printf ("\n Opcio:");
			scanf ("%d, &opcio ");

			if ( opcio = 1 ) {

				printf ( "Insereix el element que es vol ordenar:\n  ");
				scanf ("%d",&l_aux.e);

				if ( LISTABID_vacia(ListaBid l) ) {

					LISTABID_crea( ListaBid * l );
					LISTABID_anadir ( ListaBid l, l_aux ); 

				} else {
	
					LISTABID_anadirOrdenado ( ListaBid * l, l_aux );

				}

			} else { 
				
				printf ("\nGracies per utilitzar el nostre programa!");

			}

		}



}



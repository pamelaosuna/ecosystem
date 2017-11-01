#include "ecosys.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_PROIES 20
#define NB_PREDATEURS 20

  /* Parametres globaux de l'ecosysteme (externes dans le ecosys.h)*/
float p_ch_dir=0.01;
float d_proie=1;
float d_predateur=1;
float p_manger=0.2;
float p_reproduce=0.01;
float energie=50;


int main(void) {
	int i,x,y;

	srand(time(NULL));


	Animal *liste_proies=(Animal *)malloc(sizeof(Animal)*(NB_PROIES));
	Animal *liste_predateurs=(Animal *)malloc(sizeof(Animal)*(NB_PREDATEURS));

	printf("tout se passe bien avant la boucle for\n");

	printf("\nPROIES\n");
	for (i=0; i<NB_PROIES; i++) {
		x=rand()%SIZE_X;
		y=rand()%SIZE_Y;
		printf("---------------------------\n");
		printf("OK pour creer animal, i = %d\n", i);
		printf("Ses coordoonnees sont (%d,%d)\n", x,y);
		printf("---------------------------\n");
		ajouter_animal(x,y,&liste_proies);
		if (i==0) liste_proies->suivant=NULL;
		printf("OK pour l'ajouter a la liste\n");

	}


	printf("\nPREDATEURS\n");
	for (i=0; i<NB_PREDATEURS; i++) {
		x=rand()%SIZE_X;
		y=rand()%SIZE_Y;
		printf("---------------------------\n");
		printf("OK pour creer animal, i = %d\n", i);
		printf("Ses coordoonnees sont (%d,%d)\n", x,y);
		printf("---------------------------\n");

		ajouter_animal(x,y,&liste_predateurs);
		if (i==0) liste_predateurs->suivant=NULL;
		printf("OK pour l'ajouter a la liste\n");


	}
	afficher_ecosys(liste_proies,liste_predateurs);
	printf("OK pour afficher ecosysteme\n");


	liberer_liste_animaux(liste_proies);
	liberer_liste_animaux(liste_predateurs);

  return 0;
}

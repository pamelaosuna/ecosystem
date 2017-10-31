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
	int i;

	srand(time(NULL));
	Animal *liste_proies[NB_PROIES];
	Animal *liste_predateurs[NB_PREDATEURS];
	Animal *anim;
	printf("tout se passe bien avant la boucle for\n");
	for (i=0; i<NB_PROIES; i++) {
		//liste_proies[i]=creer_animal(rand()%SIZE_X, rand()%SIZE_Y, energie);
		anim=creer_animal(rand()%SIZE_X, rand()%SIZE_Y, energie);
		printf("OK pour creer animal, i = %d\n", i);
		ajouter_en_tete_animal(*liste_proies,anim);
		printf("OK pour l'ajouter a la liste\n");
	}
	for (i=0; i<NB_PREDATEURS; i++) {
		//liste_predateurs[i]=creer_animal(rand()%SIZE_X, rand()%SIZE_Y, energie);
		anim=creer_animal(rand()%SIZE_X, rand()%SIZE_Y, energie);
		printf("OK pour creer animal, i = %d\n", i);
		ajouter_en_tete_animal(*liste_predateurs,anim);
		printf("OK pour l'ajouter a la liste\n");
	}
	afficher_ecosys(*liste_proies,*liste_predateurs);
	printf("OK pour afficher ecosysteme\n");

	liberer_liste_animaux(liste_proies);
	liberer_liste_animaux(liste_predateurs);

  return 0;
}

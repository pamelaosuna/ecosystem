
#include <stdio.h>
#include <stdlib.h>
#include "ecosys.h"
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define NB_PROIES 20
#define NB_PREDATEURS 20

/* Pour utiliser la correction automatique:
cavecorrector 6-7 repertoire
 */


Animal *creer_animal(int x, int y, float energie) {

	Animal *animal = (Animal*)malloc(sizeof(Animal));
	assert (animal!= NULL);
	animal->x=x;
	animal->y=y;
	animal->energie=energie;
	animal->suivant=NULL;
	animal->precedent=NULL;
	animal->dir[0]=(rand()%3)-1;
	animal->dir[1]=-1+rand()%3;

  	return animal;
}

Animal *ajouter_en_tete_animal(Animal *liste, Animal *animal) {
	assert(animal);
	if (liste==NULL) {
		return animal;
	}
	animal->suivant=liste;
	liste->precedent=animal;
	return animal;

}

void ajouter_animal(int x, int y, Animal **liste_animal) {
	Animal *np = NULL;
	if (x<0 || y<0 || x>= SIZE_X || y>=SIZE_Y) {
		printf("Erreur de coordonnees\n");
	}else{
		np=creer_animal(x, y, energie);
		*liste_animal=ajouter_en_tete_animal(*liste_animal,np);
	}
}


void enlever_animal(Animal **liste, Animal *animal) {
	assert(animal);
	assert(*liste);
	Animal *p=*liste;
	int liste_deja_parcourue=0;

	while ((p!=animal) && (!liste_deja_parcourue)){
		p++;
		if (p==*liste){
			liste_deja_parcourue=1;
		}
	}
	if (p==animal){
		(animal->precedent)->suivant=animal->suivant;
		(animal->suivant)->precedent=animal->precedent;
		free(animal->dir);
		free(animal);
	}
}

unsigned int compte_animal_rec(Animal *la) {
	if (la==NULL){
		return 0;
	}
	else{
		return 1+ compte_animal_rec(la->suivant);
	}

}

unsigned int compte_animal_it(Animal *la) {
	assert(la);
	int k=0;

	while(!la){
		k++;
	}
  return k;
}

void bouger_animaux(Animal *la) {

}

void reproduce(Animal **liste_animal) {
  /* a completer */
}

void rafraichir_proies(Animal **liste_proie) {
  /* a completer */
}

Animal *animal_en_XY(Animal *l, int x, int y) {
  /* a completer */
  return NULL;
}

void rafraichir_predateurs(Animal **liste_predateur, Animal **liste_proie) {
  /* a completer */

}

void afficher_ecosys(Animal *liste_proie,Animal *liste_predateur) {

	// creation tableau
	char tab[SIZE_X][SIZE_Y];
	int i,j,k=0;
	Animal *p=liste_proie;

	for (i=0;i<SIZE_X;i++){
		for (j=0;j<SIZE_Y;j++){
			tab[i][j]='-';
		}
	}
	printf("OK pour le remplisage vide du tableau a deux dimensions\n");
  while (p) {
		printf("Iteration %d dans la boucle while\n ",k);
		k++;
		if (p->x>=SIZE_X || p->y>=SIZE_Y){
				printf("Erreur dans les coordonnees d'une proie");
		}
		printf("x = %d, y = %d\n", p->x,p->y);
		if (tab[p->x][p->y]=='*') printf("Plus d'une proie dans la case (%d,%d)\n", p->x,p->y);
		tab[p->x][p->y]='*';

		p=p->suivant;
	}
	printf("OK pour la liste des proies\n");
	p=liste_predateur;
	k=0;
	while (p) {
		printf("Iteration %d dans la boucle while\n ",k);
		k++;
		if (p->x>=SIZE_X || p->y>=SIZE_Y){
				printf("Erreur dans les coordonnees d'une predateur");
		}
		printf("x = %d, y = %d\n", p->x,p->y);
		if ((tab[p->x][p->y]=='*') || (tab[p->x][p->y]=='@')) {
			tab[p->x][p->y]='@';
			p=p->suivant;

		}else{
			if (tab[p->x][p->y]=='0') printf("Plus d'un predateur dans la case (%d,%d)\n", p->x,p->y);
			tab[p->x][p->y]='O';
			p=p->suivant;
		}
	}



	for (i=0;i<SIZE_X;i++){
		printf("\n");
		for (j=0;j<SIZE_Y;j++){
			printf("%c ",tab[i][j]);
		}printf("\n");
	}

}

void clear_screen() {
  printf("\x1b[2J\x1b[1;1H");  /* code ANSI X3.4 pour effacer l'ecran */
}

void liberer_liste_animaux(Animal *liste) {
	Animal *np = liste;
	if (!liste) return;
	assert(!liste->precedent);
	do {
		np = liste->suivant;
		free(liste);
		//free(liste->dir); // validation? Pas necessaire car c etait pas alloue dynamiquement
		liste=np;
	} while (liste);


}

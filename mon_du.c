/********************************************************************************************/
/* mon_du : Affiche la sommes des éléments du répertoire passé en paramètre					*/
/*																							*/
/* C. Collet 2013 ® Université Paul Sabatier, Toulouse										*/
/********************************************************************************************/

#include "mon_SGF.h"

int tailleSousRep(int inoeud, SGF_t* mon_SGF);
int tailleTotalRepertoire(char* chemin, SGF_t* mon_SGF);
int main(int argc, char * argv[])
{
    SGF_t * mon_SGF;		/* ma structure de SGF */
    int inoeud_rep;
	char* chemin;
    dir_element_t * liste_rep = NULL;
    int i;
	int list=0;

    if (argc != 2) {
		fprintf(stderr,"Usage: %s dir\n", argv[0]);
		exit (EXIT_PARAM);
    } else {
		chemin = argv[1];
	}

    if (chemin[0]!='/') {
		fprintf(stderr,"%s: erreur de designation \"%s\" doit commencer par '/' (chemin absolu).\n", argv[0], argv[1]);
		exit (EXIT_PARAM);
    }

    mon_SGF = ouvrir_SGF();
    if (mon_SGF == NULL ) {
		fprintf(stderr,"%s: ", argv[0]);
		perror (DEVICE_NAME);
		exit (EXIT_DEVICE);
    }

	printf("%d o", tailleTotalRepertoire(chemin, mon_SGF));
    mon_SGF=fermer_SGF(mon_SGF);

    exit (0);
}

int tailleSousRep(int inoeud, SGF_t* mon_SGF) {
	return mon_SGF->table_inoeuds[inoeud].taille;
}

int tailleTotalRepertoire(char* chemin, SGF_t* mon_SGF) {
    int inoeud_rep=inoeud_designation_element(chemin, 0, mon_SGF);
	int i;
    dir_element_t * liste_rep = NULL;
	int taille = 0;
	char sousChemin[256];

    if (inoeud_rep == NO_INOEUD) {
		fprintf(stderr,"%s: chemin \"%s\" inexistant !\n", "mon_du", chemin);
		exit (EXIT_PARAM);
    }

    if ((liste_rep =lire_liste_rep_dans_inoeud ( inoeud_rep, mon_SGF)) == NULL) {
		affiche_erreur( EXIT_DEVICE , "mon_du");
		exit (EXIT_DEVICE);
    }

	taille += tailleSousRep(inoeud_rep, mon_SGF);
	if((strcmp(liste_rep[1].elt_name, "..") == 0 && liste_rep[2].elt_inoeud != NO_INOEUD) ||
			(liste_rep[1].elt_inoeud != NO_INOEUD && strcmp(liste_rep[1].elt_name, "..") != 0)) {

		/* Si le dossier est / il n'y a pas de .. */
		if(strcmp(chemin, "/") == 0) {
		  i=1;
		} else {
		  i=2;
		}

		while(liste_rep[i].elt_inoeud != NO_INOEUD) {
			strcpy(sousChemin, chemin);
			if(strcmp(chemin, "/") != 0) {
				strcat(sousChemin, "/");
			}
			strcat(sousChemin, liste_rep[i].elt_name);
			taille += tailleTotalRepertoire(sousChemin, mon_SGF);
			strcpy(sousChemin, "");	
			++i;
		}
	}

	return taille;
}

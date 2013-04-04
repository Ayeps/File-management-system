/************************************************************************************************************************/
/* mon_ls : affiche le contenu du répertoire passé en paramètre. Le chemin doit obligatoirement être absolu.		*/
/*															*/
/* C. Collet 2013 ® Université Paul Sabatier, Toulouse									*/
/************************************************************************************************************************/

#include "mon_SGF.h"

void affichierInoeud(int inoeud, char* chemin, int taille);
int main(int argc, char * argv[])
{
    SGF_t * mon_SGF;		/* ma structure de SGF */
    int inoeud_rep;
	char* chemin;
    dir_element_t * liste_rep = NULL;
    int i;
	int list=0;

    if ( argc != 2 && argc != 3)
    {
		fprintf(stderr,"Usage: %s [-l] dir\n", argv[0]);
		exit (EXIT_PARAM);
    }
	if(argc == 3) {
		if(strcmp(argv[1], "-l") != 0) {
			fprintf(stderr,"Usage: %s [-l] dir\n", argv[0]);
			exit (EXIT_PARAM);
		}
		chemin = argv[2];
		list = 1;
	} else {
		chemin = argv[1];
	}

    if (chemin[0]!='/')
    {
	fprintf(stderr,"%s: erreur de designation \"%s\" doit commencer par '/' (chemin absolu).\n", argv[0], argv[1]);
	exit (EXIT_PARAM);
    }

    mon_SGF = ouvrir_SGF();
    if (mon_SGF == NULL )
    {
	fprintf(stderr,"%s: ", argv[0]);
	perror (DEVICE_NAME);
	exit (EXIT_DEVICE);
    }

    inoeud_rep=inoeud_designation_element(chemin, 0, mon_SGF);

    if (inoeud_rep == NO_INOEUD)
    {
	fprintf(stderr,"%s: chemin \"%s\" inexistant !\n", argv[0], chemin);
	exit (EXIT_PARAM);
    }

    if ((liste_rep =lire_liste_rep_dans_inoeud ( inoeud_rep, mon_SGF)) == NULL)
    {
	affiche_erreur( EXIT_DEVICE , argv[0]);
	exit (EXIT_DEVICE);
    }

	affichierInoeud(inoeud_rep, chemin, (list) ? mon_SGF->table_inoeuds[inoeud_rep].taille : -1);
    i=0;
    while( liste_rep[i].elt_inoeud != NO_INOEUD)
    {
		affichierInoeud(liste_rep[i].elt_inoeud, liste_rep[i].elt_name, (list) ? mon_SGF->table_inoeuds[liste_rep[i].elt_inoeud].taille : -1);
		i++;
    }

    mon_SGF=fermer_SGF(mon_SGF);

    exit (0);
}

/* 
 * Afficher les informations d'un inoeud
 * @param taille La taille du fichier, si celle-ci est -1, la taille ne sera pas affiché.
 */
void affichierInoeud(int numInoeud, char* chemin, int taille) {
	if(taille == -1) {
		printf("%3d '%s' :\n", numInoeud, chemin);
	} else {
		printf("%3d\t %4d o \t'%s' :\n", numInoeud, taille, chemin);
	}
}

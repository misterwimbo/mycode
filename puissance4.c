#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define VIDER_ECRAN  system("cls");  // sytem("clear") pour linux, system("cls") pour windows


void mise_a_zero_de_la_grille(char tab[][7]);
void aficherGrille(char tab[][7]);
void placement_pion(int player,int colonne,char tab[][7]);
void verif_si_grille_pleine(char tab[][7],int *player);
void alignement_vertical_ok(char tab[][7],int *player);
void alignement_horizontal_ok(char tab[][7],int *player);
void alignement_diagonale_montante(char tab[][7],int *player);
void alignement_diagonale_descendante(char tab[][7],int *player);

int anti_deborde_haut(int position_y);
int anti_deborde_droite(int position_x);




main()
{


    char grille_de_jeu[6][7]= {" "};
    int choix=0,jeu=1,joueur=1;
    int position_x,position_y;
    mise_a_zero_de_la_grille(grille_de_jeu);

    do
    {

        do // boucle de forçage de choix entre 1 et 7
        {
            aficherGrille(grille_de_jeu);
            printf("\n\tJoueur %d a vous de jouer\n",joueur);
            printf("\n\tIndiquez la colonne ou mettre\n\tle pion:");
            scanf("%d",&choix);
            //getchar();

        }
        while  (choix!=1 && choix!=2 &&      // on force le choix
                choix!=3 && choix!=4 &&
                choix!=5 && choix!=6 && choix!=7);

        placement_pion(joueur,choix,grille_de_jeu);
        aficherGrille(grille_de_jeu);
        verif_si_grille_pleine(grille_de_jeu,&joueur);
        alignement_vertical_ok(grille_de_jeu,&joueur);
        alignement_horizontal_ok(grille_de_jeu,&joueur);
        alignement_diagonale_montante(grille_de_jeu,&joueur);
        alignement_diagonale_descendante(grille_de_jeu,&joueur);

        joueur++;
        if(joueur==3)joueur=1;
    }
    while(jeu!=0);
}
/*******************************************/
/**     affiche la grille du jeu           */
/*******************************************/
void aficherGrille(char tab[][7])
{
    VIDER_ECRAN
    printf("\n\n\t  1   2   3   4   5   6   7  \n\n");
    printf("\t*****************************\n");
    printf("\t* %1c * %1c * %1c * %1c * %1c * %1c * %1c *\n",tab[0][0]
           ,tab[0][1]
           ,tab[0][2]
           ,tab[0][3]
           ,tab[0][4]
           ,tab[0][5]
           ,tab[0][6]);
    printf("\t*****************************\n");
    printf("\t* %1c * %1c * %1c * %1c * %1c * %1c * %1c *\n",tab[1][0]
           ,tab[1][1]
           ,tab[1][2]
           ,tab[1][3]
           ,tab[1][4]
           ,tab[1][5]
           ,tab[1][6]);
    printf("\t*****************************\n");
    printf("\t* %1c * %1c * %1c * %1c * %1c * %1c * %1c *\n",tab[2][0]
           ,tab[2][1]
           ,tab[2][2]
           ,tab[2][3]
           ,tab[2][4]
           ,tab[2][5]
           ,tab[2][6]);
    printf("\t*****************************\n");
    printf("\t* %1c * %1c * %1c * %1c * %1c * %1c * %1c *\n",tab[3][0]
           ,tab[3][1]
           ,tab[3][2]
           ,tab[3][3]
           ,tab[3][4]
           ,tab[3][5]
           ,tab[3][6]);
    printf("\t*****************************\n");
    printf("\t* %1c * %1c * %1c * %1c * %1c * %1c * %1c *\n",tab[4][0]
           ,tab[4][1]
           ,tab[4][2]
           ,tab[4][3]
           ,tab[4][4]
           ,tab[4][5]
           ,tab[4][6] );
    printf("\t*****************************\n");
    printf("\t* %1c * %1c * %1c * %1c * %1c * %1c * %1c *\n",tab[5][0]
           ,tab[5][1]
           ,tab[5][2]
           ,tab[5][3]
           ,tab[5][4]
           ,tab[5][5]
           ,tab[5][6] );
    printf("\t*****************************\n");
}
/*******************************************/
/**  met à zero la grille au debut du jeu  */
/*******************************************/
void mise_a_zero_de_la_grille(char tab[][7])
{
    int i,j;
    for (i=0; i<6; i++)
    {
        for (j=0; j<7; j++)
        {
            tab[i][j]=' ';
        }
    }
}
/*******************************************/
/**  placement  du pion dans la grille     */
/*******************************************/
void placement_pion(int player,int colonne,char tab[][7])
{
    char a;
    int i,plein=1;

    for(i=5; i>=0; i--)
    {
        if(tab[i][colonne-1]==' ')
        {
            if(player==1)
                tab[i][colonne-1]='O';

            else
                tab[i][colonne-1]='X';
            return;
        }
    }
    printf("\n\tCette colonne est pleine !!\n\tAppuyez sur entree...");
    scanf("%c",&a);
    getchar();
}
/*******************************************/
/**     verifie si la grille est pleine    */
/*******************************************/
void verif_si_grille_pleine(char tab[][7],int *player)
{
    char a;
    int i,j,partie=0;

    for(i=0; i<6; i++)
    {
        for(j=0; j<7; j++)
        {
            if(tab[i][j]==' ')   // si il reste des cases vides on continu
                partie=1;
        }
    }
    if(partie==0)
    {
        printf("\n\tLa grille est pleine on recommence :)");
        printf("\n\tAppuyez sur entree...");
        getchar();
        scanf("%c",&a);
        mise_a_zero_de_la_grille(tab);
        *player=1;
    }
}
/*******************************************/
/** va verifier si il y a 4 pions  alignés */
/**     a la vertical                      */
/*******************************************/
void alignement_vertical_ok(char tab[][7],int *player)
{
    int i,j;
    char a;
//verification si 4 pions ont alignés a la vertical
    for(i=0; i<6; i++)
    {
        for(j=0; j<7; j++)
        {
            if(tab[i][j]!= ' ')
            {
                if(anti_deborde_haut(i)==0)
                {
                    if(tab[i][j]==tab[i-1][j])
                    {
                        if(tab[i][j]==tab[i-2][j])
                        {
                            if(tab[i][j]==tab[i-3][j])
                            {
                                printf("\tle joueur %d Gagne la partie !!\n",*player);
                                printf("\tappuyez sur entree...");
                                scanf("%c",&a);
                                getchar();
                                mise_a_zero_de_la_grille(tab);
                            }
                        }
                    }
                }
            }
        }
    }
}
/*******************************************/
/** va verifier si il y a 4 pions  alignés */
/**          a l'horizontal                */
/*******************************************/
void alignement_horizontal_ok(char tab[][7],int *player)
{
    int i,j;
    char a;
//verification si 4 pions ont alignés a l'horizontal
    for(i=0; i<6; i++)
    {
        for(j=0; j<7; j++)
        {
            if(tab[i][j]!= ' ')
            {
                if(anti_deborde_droite(j)==0)
                {
                    if(tab[i][j]==tab[i][j+1])
                    {
                        if(tab[i][j]==tab[i][j+2])
                        {
                            if(tab[i][j]==tab[i][j+3])
                            {
                                printf("\tle joueur %d Gagne la partie !!\n",*player);
                                printf("\tappuyez sur entree...");
                                scanf("%c",&a);
                                getchar();
                                mise_a_zero_de_la_grille(tab);
                            }
                        }
                    }
                }
            }
        }
    }
}
/*******************************************/
/** va verifier si il y a 4 pions  alignés */
/**        en diagonale  haut              */
/*******************************************/
void alignement_diagonale_montante(char tab[][7],int *player)
{
    int i,j;
    char a;

    for(i=0; i<6; i++)
    {
        for(j=0; j<7; j++)
        {
            if(tab[i][j]!= ' ')
            {
                if(anti_deborde_haut(i)==0)
                {
                    if(anti_deborde_droite(j)==0)
                    {
                        if(tab[i][j]==tab[i-1][j+1])
                        {
                            if(tab[i][j]==tab[i-2][j+2])
                            {
                                if(tab[i][j]==tab[i-3][j+3])
                                {
                                    printf("\tle joueur %d Gagne la partie !!\n",*player);
                                    printf("\tappuyez sur entree...");
                                    scanf("%c",&a);
                                    getchar();
                                    mise_a_zero_de_la_grille(tab);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
/*******************************************/
/** va verifier si il y a 4 pions  alignés */
/**        en diagonale en descendant      */
/*******************************************/
void alignement_diagonale_descendante(char tab[][7],int *player)
{
    int i,j;
    char a;

    for(i=0; i<6; i++)
    {
        for(j=0; j<7; j++)
        {
            if(tab[i][j]!= ' ')
            {
                if(anti_deborde_bas(i)==0)
                {
                    if(anti_deborde_droite(j)==0)
                    {
                        if(tab[i][j]==tab[i+1][j+1])
                        {
                            if(tab[i][j]==tab[i+2][j+2])
                            {
                                if(tab[i][j]==tab[i+3][j+3])
                                {
                                    printf("\tle joueur %d Gagne la partie !!\n",*player);
                                    printf("\tappuyez sur entree...");
                                    scanf("%c",&a);
                                    getchar();
                                    mise_a_zero_de_la_grille(tab);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
/*******************************************/
/** verification anti debordement          */
/**         axe ordonée   ( bas )          */
/*******************************************/
int anti_deborde_bas(int position_y)
{
    /*avant la verification ,si 4 pions sont alignés ,il faudras s'assurer
    que l'on ne deborde pas du tableau
    par exemple si j'ajoute 3 pions en dessous d'une position donnée ,es ce que je deborde ?
    cette fonction serviras a savoir si oui ou non on verfie l'alignement de 4 pions
    vers la diagonale bas-droite
    et la diagonale bas-gauche
    x==position du pion sur la ligne  abscisses
    y== position du pion sur la colonne ordonnées
    si on deborde la fonction renvoie 1 */

    int resultat;

    if(resultat>2)// si condition vrai on deborde
        resultat=1;
    else
        resultat=0;
    return resultat;
}
/*******************************************/
/** verification anti debordement          */
/**          axe des ordonées ( haut )     */
/*******************************************/
int anti_deborde_haut(int position_y)
{
    /*avant la verification ,si 4 pions sont alignés ,il faudras s'assurer
    que l'on ne deborde pas du tableau
    par exemple si j'ajoute 3 pions au dessus d'une position donnée
    es ce que je deborde ?
    cette fonction serviras a savoir si oui ou non on verfie l'alignement de 4 pions
    vers le  haut,la diagonale haut-droite
    et la diagonale haut-gaucheA
    x==position du pion sur la ligne  abscisses
    y== position du pion sur la colonne ordonnées
    si on deborde la fonction renvoie 1 */

    int resultat;

    if(position_y<3)// si condition vrai on deborde
        resultat=1;
    else
        resultat=0;
    return resultat;
}
/*******************************************/
/** verification anti debordement          */
/**         axe des abscisses              */
/*******************************************/
int anti_deborde_droite(int position_x)
{
    /*avant la verification ,si 4 pions sont alignés ,il faudras s'assurer
       que l'on ne deborde pas du tableau
       par exemple si j'ajoute 3 pions a droite d'une position donnée
       es ce que je deborde ?
     si on deborde la fonction renvoie 1 */
    int resultat;

    if(position_x>3)// si condition vrai on deborde
        resultat=1;
    else
        resultat=0;
    return resultat;
}

#include <stdio.h>
#include <stdlib.h>
#include  <time.h>
#include <string.h>

#define VIDER_ECRAN system("cls");  //remplacer par system("clear");   pour linux
                                    //remplacer par system("cls");   pour windows


void mise_en_minuscule(char *lettre);
void premier_affichage(int a);
void second_affichage(int nb_lettre,char *copie_mot,char mot[][15],char lettre,int *compteur,int *jeu,int x);


int main()
{
    char mot_secret[13][15]= {"accorder\0","anterieur\0","billeterie\0","courageux\0","caramel\0",
        "dangereux\0","divisions\0","dentelles\0","embrouille\0","fantomes\0",
        "gorilles\0","grandeur\0","gribouilli\0"};


    char copie_mot[15]={"--------------"};
    char lettre_saisi;
    int x=0,i=0,nb_lettre=0,jeu=2,compteur=5;

    srand(time(0)); // Une fois suffit
    x= (rand() % 13) + 1; // on va choisir un nombre au hasard(enfin presque....)
    nb_lettre=strlen(mot_secret[x]);// on compte le nombre de lettre du mot secret


do{
    VIDER_ECRAN
    printf("Jeu du pendu trouver le mot secret:\n\n");
    if(jeu==2)
    {
    premier_affichage(nb_lettre);
    jeu=1;
    }
    else
    {
    second_affichage(nb_lettre,copie_mot,mot_secret,lettre_saisi,&compteur,&jeu,x);
    }
    if(jeu!=0)
    {
    printf("\n\nSaisissez une lettre au clavier:");
    lettre_saisi=getch();
    mise_en_minuscule(&lettre_saisi);
    }

}while(jeu==1);
}

/******************************************/
/** met en minuscule le lettre saisie    */
/****************************************/
void mise_en_minuscule(char *lettre)
{
    *lettre=tolower(*lettre);
}
/******************************************/
/** Affichage du mot la premiere fois    */
/****************************************/
void premier_affichage(int a)
{
    int i;
printf("Le mot contient %d letrres  a vous de jouez !\n\n",a);
    for(i=0; i<a; i++)
    {
        printf("-");
    }
    printf("        5 tentative(s) restante(s)\n");

}
/*******************************************/
/** verifie si la lettre fait partie      */
/** du mot et actualise l'affichage      */
/** arrete la partie si necéssaire      */
/***************************************/
void second_affichage(int nb_lettre,char *copie_mot,char mot[][15],char lettre,int *compteur,int *jeu,int x)
{
    int i=0,j=0;

    printf("Le mot contient %d letrres  a vous de jouez !\n\n",nb_lettre);
    for(i=0; i<nb_lettre; i++)
    {
        if(lettre==mot[x][i])
        {
            j=1;
            if(copie_mot[i]=='-');
            copie_mot[i]=mot[x][i];
        }
    }
    if(j==0) // le joueur n'as pas trouve de lettre
        *compteur=*compteur-1;

    for(i=0; i<nb_lettre; i++)
    {
        printf("%c",copie_mot[i]);
    }
    printf("        %-2d tentative(s) restante(s)\n",*compteur);

    if(*compteur==0)// le joueur à perdu
    {
        printf("\n\nVous avez Perdu !");
        printf("\nVoici le mot secret:%s",mot[x]);
        *jeu=0;
        return;
    }
    // on verifie si le mot est trouvé
    j=0;
    for(i=0; i<nb_lettre; i++)
    {
        if(copie_mot[i]=='-')
            j=1;
    }
    if(j==0)     //le mot est trouvé
    {
        printf("\n\nVICTIOIRE ! ");
        *jeu=0;
    }
}


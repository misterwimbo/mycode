#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define VERIF if(fichier==NULL){ printf("Erreur lors de l'ouverture du fichier");exit(0);}





/*********************************************/
/**            ecriture dans le fichier     */
/*******************************************/
void afficher_nbr(int N,FILE *file)
{
    /*j'aurais pu mettre l'algo pour l'ouverture du fichier dans la fonction mais
    je voulais voir comment faire un passage de parametre utilisant un fichier dans une fonction
     */
    int i;

    for(i=0; i<N; i++)
    {
        if(i%10==0 && i!=0) // on passe à la ligne tout les 10
            fprintf(file,"\n");
        fprintf(file," %2d;",i+1);
    }
    fclose(file);
}

/*********************************************/
/**      lit les lignes du fichiers         */
/*******************************************/
void afficherligne(FILE *file,char ligne[])
{


    while(fgets(ligne,100,file)!=NULL)
    printf("%s",ligne);
    fclose(file);


}

/*********************************************/
/**      lit champs par champs              */
/*******************************************/
champsparchamps( const char nom_fichier[])
{
    char c;
    FILE *fichier=NULL;
    fichier=fopen(nom_fichier,"r");
    VERIF
    printf("\n");
    while((c=fgetc(fichier))!=EOF)
    {
        if(c==';')
            printf ("\n");
        else if (c!='\n' && c!=';')
            printf("%c",c);
    }
    fclose(fichier);
}


int main(int argc,char *argv[])

{

    char file[500];
    int argument=0,n=0;
    if(argc>1)
    {
        argument=1;
        n=atoi(argv[2]);
        strcpy(file,argv[1]);
    }
    else
    {
        strcpy(file,"test.txt");

    }

    char ligne[1000];
    int i=0;


    /*for (i=0; i < argc; i++)

    {

        printf("Argument %ld : %s \n", i+1, argv[i]); // un test

    }*/

    FILE *fichier=NULL;
    fichier=fopen(file,"w"); // ouverture du fichier en mode ecriture  crée si il n'existe pas, sinon ecrasé
    VERIF

   if(argument==0)
    {
     printf("Entrez un nombre:");
    scanf("%d",&n);
    }


    afficher_nbr(n,fichier);

    fichier=fopen(file,"r");  // ça fait "crade" de l'ouvrir dans le main mais c'est pour voir le passage parametre
    VERIF
    afficherligne(fichier,ligne);
    printf("\n");
    champsparchamps(file);




}


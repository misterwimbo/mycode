#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define VERIF if(fichier==NULL){ printf("\nErreur lors de l'ouverture du fichier");exit(0);}
#define Saut_ligne k++;if(k==8){k=0;fprintf(fichier,"\n");}
#define reset_id for(j=0;j<50;j++)  id[j]='\0';

/* pour l'exercice :

Puis les fonctions
ecrirefwrite
ecrirefread
qui écrivent et lisent les données au format binaire

les fonctions fwrite et fread ecrivent au format brut...pas binaire,enfin je crois hein !:)  je pense que c'est un malententu ??
j'ai neanmoins pris au mot l'ennoncé  c'est pegagogique :) */



struct date
{
    int jour;
    int mois;
    int year;
};

struct personne
{
    char nom[50];
    char prenom[50];
    struct date naissance;
};

void comptedonnees(const char files[],int *nbr_ligne);
void lirefscanf(const char files[],int nbr_ligne,struct personne P[]);
void ecrirefprintf(const char files[],int nbr_ligne,struct personne P[]);
void ecrirefwrite(const char files[],int nbr_ligne,struct personne P[]);
void ecrirefread(const char files[],struct personne P[]); //  lirefread...

int conversionbinaire(int nombre);
int conversiondecimal(char nombre[]);

int main(int argc ,char *argv[])
{
// pour les besoins de l'exercice on met le fichier dans le meme repertoire
    struct personne identite[100];
    struct personne who_is_it[100]; // on stockeras dedans apres la conversion du fichier binaire.txt

    char nom_fichier[]="seance2.txt";
    char fichier_xls[]="donnees.xls"; // pour l'excercice j'impose les noms de fichier
    char fichier_bin[]="binaire.txt";

    int ligne=0;

    comptedonnees(nom_fichier,&ligne);
    lirefscanf(nom_fichier,ligne,identite);
    ecrirefprintf(fichier_xls,ligne,identite);
    ecrirefwrite(fichier_bin,ligne,identite);
    ecrirefread(fichier_bin,who_is_it);



//printf("\nresultat de la fonction :%08d",conversionbinaire(32));
//printf("\nresultat de la fonction: %d",conversiondecimal("11111111"));



}

/*********************************************/
/**      comptez les lignes                 */
/*******************************************/
void comptedonnees(const char files[],int *nbr_ligne)
{
    FILE *fichier=NULL;
    fichier=fopen(files,"r");
    VERIF

    char ligne[1000];
    int i=0;
    char c;
    while(c=(fgets(ligne,1000,fichier))!=NULL)
    {
        i++;                            //si il y a une ligne avec que des espaces ,ça la compte,.... :/
    }

    printf("il y a %d lignes dans le fichier %s\n",i,files);
    *nbr_ligne=i;
    fclose(fichier);
}
/*********************************************/
/**     releve les infos du fichier         */
/**    et les met dans la structure        */
/******************************************/
void lirefscanf(const char files[],int nbr_ligne,struct personne P[])
{
    FILE *fichier=NULL;
    fichier=fopen(files,"r");
    VERIF

    char recup[10];
    int i=0,j=0;
    printf("\nVoici ce qui a ete rajoute a la structure personne:\n%d entree en tout\n",nbr_ligne);

    for(i=0; i<nbr_ligne; i++)
    {

        fscanf(fichier,"%s",&P[i].nom);  // recup du nom
        printf("\n%-10s",&P[i].nom);

        fscanf(fichier,"%s",&P[i].prenom); // recup du prenom
        printf("%-10s",&P[i].prenom);

        fscanf(fichier,"%s",recup);          //recup du jour de naissance
        P[i].naissance.jour=atoi(recup);     // c'etait pour un test
        printf("%02d ",P[i].naissance.jour);

        fscanf(fichier,"%d",&P[i].naissance.mois); // recup du mois de naissance
        printf("%02d ",P[i].naissance.mois); // on enleve le '&' sinon on affiche l'adresse

        fscanf(fichier,"%d",&P[i].naissance.year); //recup de l'année de naissance
        printf("%4d",P[i].naissance.year);
    }
    fclose(fichier);
}
/*********************************************/
/**    met les infos de la structure        */
/**         dans un fichier                */
/******************************************/
void ecrirefprintf(const char files[],int nbr_ligne,struct personne P[])
{
    FILE *fichier=NULL;
    fichier=fopen(files,"w");
    VERIF

    char recup[30];
    int i=0,nbr=0;

    for(i=0; i<nbr_ligne; i++)
    {
        fprintf(fichier,"%s; ",P[i].nom); // on inscrit le nom dans le fichier

        strcpy(recup,P[i].prenom); // je sais je me complique,c'est pedagogique ... :)
        fprintf(fichier,"%s; ",recup); // le prenom

        nbr=P[i].naissance.jour;
        fprintf(fichier,"%02d/",nbr); //le jour de naissance

        nbr=P[i].naissance.mois;
        fprintf(fichier,"%02d/",nbr); //le mois de naissance

        nbr=P[i].naissance.year;
        fprintf(fichier,"%4d\n",nbr); //l'annee de naissance
    }
    fclose(fichier);
}
/*********************************************/
/**    converti   un nombre decimal         */
/**    en nombre binaire                   */
/******************************************/
int conversionbinaire(int nombre)
{
    /*division avec des entiers      exemple avec le chiffre 8

                  ^
    8/2 = 4 reste 0|^
    4/2 = 2 reste 0|^
    2/2 = 1 reste 0|^
    1/2 = 0 reste 1|^

    on lit du bas vers le haut 8(decimal)=>1000(binaire)*/

    int tab[100]= {0},i=0,j=0,k=0,resultat=-1,nbr;
    char tab2[100]= {0},tab3[100]= {0},c;

    nombre=nombre*2;
    while(resultat!=0 && resultat!=1)
    {
        nombre=nombre/2; // on retient le resultat il faudras le redivisé par 2 sauf si ==1 ou ==0
        /*Attention division d'entiers */
        resultat=nombre;
        //printf("\n%d",resultat); // valeur de la la variablee resultat

        tab[i]=nombre%2;// soit 1 ou 0
        i++;
    }

    k=0;
    for(j=i-1; j>=0; j--)
    {
        nbr=tab[j];
        if(k==0)
            sprintf(tab3,"%d",nbr);// on copie le 1er 'nombre' dans le chaine tab3
        if(k!=0)
        {
            sprintf(tab2,"%d",nbr); // on copie le n+1 nbr dans la chaine tab2 pour eviter ecrasement de tab3
            strcat(tab3,tab2);     // on copie tab2 à la fin de tab3
        }
        k++;
    }
    nbr=atoi(tab3);// conversion de la chaine en nombre
    //printf("le nombre binaire correspondant est: %08d",nbr); // affichage sur 8 bits
    return nbr;
}
/*********************************************/
/**    ecrit dans le fichier                */
/**    au format binaire                   */
/******************************************/
void ecrirefwrite(const char files[],int nbr_ligne,struct personne P[])
{
    /* les infos seront directement pris dans la structure */
    FILE *fichier=NULL;
    fichier=fopen(files,"w");
    VERIF

    int i=0,j=0,k=0,nbr_bin=0,nbr_c=0,nbr_date=0;
    char recup[30],nbr_d[5];

    for(i=0; i<nbr_ligne; i++)
    {
        /*on va prendre le nom dans la strucure personne */
        strcpy(recup,P[i].nom);
        nbr_c=strlen(recup);
        for(j=0; j<nbr_c; j++)
        {
            nbr_bin=conversionbinaire(recup[j]);
            fprintf(fichier,"%08d ",nbr_bin);
            Saut_ligne // saute une ligne tout les 8
        }
        fprintf(fichier,"%08d ",conversionbinaire(32));// un espace entre chaque infos
        Saut_ligne

        /*on va recuperer le prenom dans la structure */
        strcpy(recup,P[i].prenom);
        nbr_c=strlen(recup);
        for(j=0; j<nbr_c; j++)
        {
            nbr_bin=conversionbinaire(recup[j]);
            fprintf(fichier,"%08d ",nbr_bin);
            Saut_ligne
        }
        fprintf(fichier,"%08d ",conversionbinaire(32));// un espace
        Saut_ligne

        /* on va recuperer la date de naissance */

        /* le jour */
        nbr_date=P[i].naissance.jour;
        sprintf(nbr_d,"%d",nbr_date);// on met le nombre dans un chaine
        nbr_date=strlen(nbr_d); // on peut ainsi compter le nbre de cracteres
        for(j=0; j<nbr_date; j++)
        {
            nbr_bin=conversionbinaire(nbr_d[j]);
            fprintf(fichier,"%08d ",nbr_bin);
            Saut_ligne
        }
        fprintf(fichier,"%08d ",conversionbinaire(32));// code ascii de l'espace
        Saut_ligne

        /* le mois */
        nbr_date=P[i].naissance.mois;
        sprintf(nbr_d,"%d",nbr_date);// on met le nombre dans un chaine
        nbr_date=strlen(nbr_d); // on peut ainsi compter le nbre de cracteres
        for(j=0; j<nbr_date; j++)
        {
            nbr_bin=conversionbinaire(nbr_d[j]);
            fprintf(fichier,"%08d ",nbr_bin);
            Saut_ligne
        }
        fprintf(fichier,"%08d ",conversionbinaire(32));// code ascii de l'espace
        Saut_ligne

        /*l'année */
        nbr_date=P[i].naissance.year;
        sprintf(nbr_d,"%d",nbr_date);// on met le nombre dans un chaine
        nbr_date=strlen(nbr_d); // on peut ainsi compter le nbre de cracteres
        for(j=0; j<nbr_date; j++)
        {
            nbr_bin=conversionbinaire(nbr_d[j]);
            fprintf(fichier,"%08d ",nbr_bin);
            Saut_ligne
        }
        fprintf(fichier,"%08d ",conversionbinaire(32));//  fin des infos sur la personne
        Saut_ligne
    }
    fclose(fichier);
    printf("\n\nLe fichier binaire:%s est fait\n\n",files);
}
/*********************************************/
/**    converti   un nombre binaire         */
/**    en nombre decimal                   */
/******************************************/
int conversiondecimal(char nombre[])
{
    /* soit le nombre 00010010 en binaire

     0      0      0      1      0       0      1      0
     2^7    2^6    2^5    2^4    2^3     2^2    2^1    2^0
     128     64    32      16     8       4      2      1

    on additionne ou il y a '1' donc 16+2 >>> 18 en decimal */

    int nbr_dec=0,i=0;
    char tab[9];

    sprintf(tab,"%s",nombre);
    for(i=0; i<8; i++) // la chaine est normalement sur 8 bits xxxxxxxx dans le fichier binaire.txt
    {
        //conversion
        if(tab[i]=='1')
            nbr_dec=nbr_dec+pow(2,(8-(i+1)));
    }
    return nbr_dec;
}
/*********************************************/
/**    lit le fichier binaire et  affiche   */
/** le contenu en version 'lisible'        */
/******************************************/
void ecrirefread(const char files[],struct personne P[])
{
    char recup[9];
    char id[50]= {'\0'},provisoire[2]= {'\0'};
    int ascii,nbr_ligne,i=0,j=0,prenom=0,nom=0,jour=0,mois=0,k=0;
    comptedonnees(files,&nbr_ligne); // recupere le nombre de ligne du fichier (18 normalement)
    if(nbr_ligne!=18)
    {
        printf("fichier corrompu!");
        return;
    }
    printf("\nvoici le fichier %s apres la conversion:\n",files);


    /* on ouvre à nouveau le fichier car il à été fermé par la fonction ci-dessus*/

    FILE *fichier=NULL;
    fichier=fopen(files,"r"); // ouverture fichier binaire.txt
    VERIF
    k=0; //position dans le tableau de structure (who_is_it[k])
    while(k!=100)
    {
        fscanf(fichier,"%s",recup);
        ascii=conversiondecimal(recup);


        if(ascii!=32) // si different de 'espace'
        {
            sprintf(provisoire,"%c",ascii);
            strcat(id,provisoire);

        }
        if(ascii==32) // les infos sont toujours entre des espaces dans le fichier binaire.txt
        {
            if(nom==0)
            {
                strcpy(P[k].nom,id);
                reset_id
                nom=1;
            }

            else if(prenom==0)
            {
                strcpy(P[k].prenom,id);
                reset_id
                prenom=1;
            }

            else if(jour==0)
            {
                P[k].naissance.jour=atoi(id);
                reset_id
                jour=1;
            }

            else if(mois==0)
            {
                P[k].naissance.mois=atoi(id);
                reset_id
                mois=1;
            }

            else
            {
                P[k].naissance.year=atoi(id);
                k++;
                nom=0;
                prenom=0;
                jour=0;
                mois=0;
                reset_id
            }
        }
    }

    /******************** Affichage de la nouvelle table*******************/
    for(i=0; i<6; i++)
    {
        printf("\n%-10s",&P[i].nom);
        printf("%-10s",&P[i].prenom);
        printf("%02d ",P[i].naissance.jour);
        printf("%02d ",P[i].naissance.mois);
        printf("%d",P[i].naissance.year);
    }
    /*********************************************************************/
    fclose(fichier);
}

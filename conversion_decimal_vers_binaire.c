#include  <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{

    // conversion d'un nombre decimal en nombre binaire

   /* int nbr=256;
    char tab[100];
    test avec sprintf
    sprintf(tab,"%d",nbr);
    printf("chaine:%s la chaine fait %d de long\n",tab,strlen(tab));
    fin du test*/

    binaire(255); // convertit le nombre decimal, entre paranthese, en binaire max 255 pour test

}

 int binaire(int nombre)
{
    /*division avec des entiers      exemple avec le chiffre 8
                   ^
    8/2 = 4 reste 0|
    4/2 = 2 reste 0|
    2/2 = 1 reste 0|
    1/2 = 0 reste 1|

    on lit du bas vers le haut 8(decimal)=>1000(binaire)*/
    int tab[100]= {0},i=0,j=0,k=0,resultat=-1,nbr;
    char tab2[100]= {0},tab3[100]= {0},c;

    nombre=nombre*2;
    while(resultat!=0 && resultat!=1)
    {
        nombre=nombre/2; // on retient le resultat il faudras le redivisé par 2 si !=1 ou !=0
                                             /*Attention division d'entiers */
        resultat=nombre;
        printf("\n%d",resultat);

        tab[i]=nombre%2;// soit 1 ou 0
        i++;
    }
    printf("\n\n");
    k=0;
    for(j=i-1; j>=0; j--)
    {
        nbr=tab[j];
        if(k==0)
            sprintf(tab3,"%d",nbr);// on copie le 1er nombre dans le chaine tab3
        if(k!=0)
        {
            sprintf(tab2,"%d",nbr); // on copie le n+1 nbr dans la chaine tab2 pour eviter ecrasement de tab3
            strcat(tab3,tab2);     // on copie tab2 à la fin de tab3
        }
        k++;
    }
    nbr=atoi(tab3);// conversion de la chaine en nombre
    printf("le nombre binaire correspondant est: %08d",nbr); // affichage sur 8 bits
}

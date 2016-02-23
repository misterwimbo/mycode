#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

int conversiondecimal(char nombre[])
{
    /* soit le nombre 00010010 en binaire

    0      0      0      1      0       0      1      0
    2^7    2^6    2^5    2^4    2^3     2^2    2^1    2^0
    128     64    32      16     8       4      2      1

    on additionne ou il y a '1' donc 16+2 >>> 18 en decimal */
    int nbr_dec=0,i=0;
    char tab[8];

    printf("\nvoici la chaine :%s\n",nombre);

    sprintf(tab,"%s",nombre);
    printf("voici le tableau:");
    for(i=0; i<8; i++) // je suppose que le nombre est sur 8 bits xxxxxxxx
    {
        // on liste tab
        printf("%c",tab[i]);
    }
    printf("\n");
    for(i=0; i<8; i++)
    {
        //conversion
        if(tab[i]=='1')
            nbr_dec=nbr_dec+pow(2,(8-(i+1)));
        printf("\n[i]:%d  nbr_dec:%d",i,nbr_dec);
    }

    return nbr_dec;
}

int main(int argc,char *argv[])
{
    int i=0;
    char nombre[]="11110100"; // changer le nombre binaire pour les test,attention sur 8 chiffes
    i=conversiondecimal(nombre);
    printf("\n\nle nombre %s en binaire correspond a %d en decimal",nombre,i);
}

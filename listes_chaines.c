#include <stdio.h>
#include <stdlib.h>


struct liste
{

    int numero;
    struct liste *suivant;
};

void afficherliste( struct liste *debut );
void sasirliste   ( struct liste *debut );
main()
{

struct liste *ma_liste;



// je defenie le debut de strcut liste
ma_liste=malloc(sizeof(struct liste));

ma_liste->suivant=NULL;

sasirliste   (ma_liste);
afficherliste(ma_liste);




}

void afficherliste( struct liste *debut )
{

struct liste *courant;
courant=debut->suivant;
int continu=1;

  do{
      if(debut->suivant == NULL)
      continu=0;

     printf("Numero:%d\n",debut->numero);
     if(debut->suivant!=NULL)
     {
         debut=debut->suivant;
         continu=1;
     }


  }while(continu==1);
}

void sasirliste   ( struct liste *debut )
{
    int i=1,continu=1;
    char reponse;
   struct liste *nouveau=NULL;


do{

  printf("entrez le numero de la fiche No%d:",i);
  scanf("%d",&debut->numero);

  getchar();

  printf("voulez vous continuer la saisie ?:(o/n)");
  scanf("%c",&reponse);

  if(reponse == 'n')
  continu = 0;
  debut->suivant=NULL;


  if(reponse == 'o')
  {
      nouveau=malloc(sizeof(struct liste));
      debut->suivant=nouveau;
      i++;
      debut=nouveau;
      debut->suivant=NULL;

  }


}while(continu==1);

}

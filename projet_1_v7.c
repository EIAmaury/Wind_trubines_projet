#include "projet_1_v7.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
float matrice[3][3]={{0.2,0.73,0.07},{0.11,0.74,0.15},{0.04,0.61,0.35}};
float prod[3]={0.1,0.4,0.65};

// fonction permettant de calculer la production maximale du parc éolien
float production_max(float prod[])
{
  int jour;
  int éolienne;
  printf("Nombre de jour de l'expérience");
  scanf("%d",&jour);
  printf("Nombre d'éoliennes dans le parc");
  scanf("%d",&éolienne);
 return jour*prod[2]*éolienne;
}
//fonction qui calcule la force du vent
int calcul_vent(float matrice[3][3],float prod[],int vent)
{     
      float totalProbability = 0.0;
      for (int i = 0; i <3; i++) 
      {
        totalProbability += matrice[i][vent];
      }
        double randomValue = ((double)rand() / RAND_MAX)* totalProbability;
        double cumulProbabilité = 0.0;
        int indice_matrice = 0;
  
      for (int i = 0; i <3; i++) 
      {
        cumulProbabilité += matrice[i][vent];
        if (randomValue <= cumulProbabilité) 
        {
            indice_matrice = i;
            
            break;
         }
       }
      
      return indice_matrice;
}
// fonction booléenne qui renvoie vrai si une éolienne tombe en panne
bool calcul_panne(float p_proba_panne)
{
      int j=0;
      int vent=2;
      float totalProbability = 0.0;
      double randomValue_2 = ((double)rand() / RAND_MAX);
      if (randomValue_2 <= (p_proba_panne)) 
      {
       return true;
       }
       else
       {
        return false;
       }
       
}
// fonction qui permet de connaitre la production journalière d'un jour défini par l'utilisateur
void simulation_journée(float matrice[3][3],float prod[])
{
  int jour;
  int éolienne;
  printf("Nombre de jour de l'expérience");
  scanf("%d",&jour);
  printf("Nombre d'éolienne dans le parc");
  scanf("%d",&éolienne);
  float proba;
  printf("Quelle est la probabilité de tomber en panne pour une éolienne ?\n");
  scanf("%f",&proba);
  float *tableau;
  tableau = (float *)malloc(jour * sizeof(int));
      for(int i=0;i<jour;i++)
    {
     tableau[i]=0;
    }

   for (int j=0;j<éolienne;j++)
  {
  srand(time(NULL));
  int vent=0;
  for(int i=0;i<jour;i++)
  {
  switch(vent)
  {
    case 0:
      vent=calcul_vent(matrice,prod,0);
      tableau[i]+=prod[0];
      break;
    case 1:
      vent=calcul_vent(matrice,prod,1);
      tableau[i]+=prod[1];
      break;
    case 2:
       if (calcul_panne(proba)==true)
      {
       int état_vent=2;
       int jour_réparation=0;
       while (jour_réparation!=3)
       {
        vent=calcul_vent(matrice,prod,état_vent);
        état_vent=vent;
        if (vent==2)
        {
        i++;
        vent=calcul_vent(matrice,prod,2);
        }
        else
        {
         jour_réparation++;
         i++;
        }
       }
       break;     
       }
       
       
      else
      {
      vent=calcul_vent(matrice,prod,2);
      tableau[i]+=prod[2];
       break;
      }
     
   }
}
}
    printf("Pour quel jour souhaitez-vous obtenir la production journalière ?\n");
    int jour_1;
    scanf("%d", &jour_1);

    if (jour_1 >= 1 && jour_1 <= jour) {
        printf("La production du jour %d est de %f MW\n", jour_1, tableau[(jour_1 - 1)]);
    } else {
        printf("Jour invalide.\n");
    }
    free(tableau);
}
//fonction qui permet de suivre la progression et du vent ainsi que la production journalière des éoliennes du parc
void production_aléatoire(float matrice[3][3],float prod[])
{
 int jour;
  int intervention=0;
  int éolienne;
  printf("Nombre de jour de l'expérience");
  scanf("%d",&jour);
  printf("Nombre d'éolienne dans le parc");
  scanf("%d",&éolienne);
  float proba;
  printf("Quelle est la probabilité de tomber en panne pour une éolienne ?\n");
  scanf("%f",&proba);
  float production=0.0;
  
  for (int j=0;j<éolienne;j++)
  {
  srand(time(NULL));
  int vent=0;
  for(int i=1;i<=jour;i++)
  {
  switch(vent)
  {
    case 0:
      vent=calcul_vent(matrice,prod,0);
      production+=prod[0];
      break;
    case 1:
      vent=calcul_vent(matrice,prod,1);
      production+=prod[1];
      break;
    case 2:
       if (calcul_panne(proba)==true)
      {
       int état_vent=2;
       intervention+=150;
       int jour_réparation=0;
       while (jour_réparation!=3)
       {
        vent=calcul_vent(matrice,prod,état_vent);
        état_vent=vent;
        if (vent==2)
        {
        i++;
        vent=calcul_vent(matrice,prod,2);
        }
        else
        {
         jour_réparation++;
         i++;
        }
       }
       break;     
       }
       
       
      else
      {
      vent=calcul_vent(matrice,prod,2);
      production+=prod[2];
       break;
      }
     
   }
}
}
printf("La production finale du parc est %f MW\n",production);
printf("Les couts d'intervention sur l'emsemble des éoliennes sont de %dK euros \n",intervention);
}
// fonction qui permet de calculer la production totale et les couts d'intervention
void descriptif(float matrice[3][3],float prod[])
{
  int jour;
  int intervention=0;
  int éolienne;
  printf("Nombre de jour de l'expérience");
  scanf("%d",&jour);
  printf("Nombre d'éolienne dans le parc");
  scanf("%d",&éolienne);
  float proba;
  printf("Quelle est la probabilité de tomber en panne pour une éolienne ?\n");
  scanf("%f",&proba);
  float production=0.0;
  
  for (int j=0;j<éolienne;j++)
  {
  srand(time(NULL));
  int vent=0;
  for(int i=1;i<=jour;i++)
  {
  switch(vent)
  {
    case 0:
     printf("le vent est faible\n");
      vent=calcul_vent(matrice,prod,0);
      printf("La production journalière de l'éolienne %d est de %fMW pour le jour %d\n",j+1,prod[0],i);
      printf("le vent vient de passer au niveau %d\n",vent);
      production+=prod[0];
      break;
    case 1:
      printf("le vent est moyen\n");
      vent=calcul_vent(matrice,prod,1);
      printf("La production journalière de l'éolienne %d est de %fMW pour le jour %d\n",j+1,prod[1],i);
      production+=prod[1];
      printf("le vent vient de passer au niveau %d\n",vent);
      break;
    case 2:
      printf("le vent est fort\n");
       if (calcul_panne(proba)==true)
      {
       int état_vent=2;
       printf("\033[1;31ml'éolienne %d vient de tomber en panne\n\033[0m", j + 1);
       printf("la production journalière esl nulle pour le jour %d\n",i);
       printf("le cout de l'intervention est 150K euros\n");
       intervention+=150;
       printf("3 jours de réparation sont nécessaire si le vent n'est pas fort\n");
       int jour_réparation=0;
       while (jour_réparation!=3)
       {
        vent=calcul_vent(matrice,prod,état_vent);
        état_vent=vent;
        if (vent==2)
        {
        printf("le vent est fort on ne peut pas réparer l'éolienne\n");
        i++;
        vent=calcul_vent(matrice,prod,2);
        }
        else
        {
         jour_réparation++;
         printf("Nous avons atteint %d jour de réparation\n",jour_réparation);
         i++;
        }
       }
       printf("\033[1;32ml'éolienne %d est réparée\n\033[0m", j + 1);
       break;     
       }
       
       
      else
      {
      vent=calcul_vent(matrice,prod,2);
      printf("La production journalière de l'éolienne %d est de %fMW pour le jour %d\n",j+1,prod[2],i);
      production+=prod[2];
      printf("le vent vient de passer au niveau %d\n",vent);
       break;
      }
     
   }
}
}
printf("La production finale du parc est %f MW\n",production);
printf("Les couts d'intervention sur l'emsemble des éoliennes sont de %dK euros \n",intervention);
}

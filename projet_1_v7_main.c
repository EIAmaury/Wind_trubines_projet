#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include "projet_1_v7.h"






int main()
{
float matrice[3][3]={{0.2,0.73,0.07},{0.11,0.74,0.15},{0.04,0.61,0.35}};
float prod[3]={0.1,0.4,0.65};
bool quitter=true;
while (quitter)
{
int choix;
printf("-------------------------\n");
printf("Choisissez une option\n");
printf("1.Production totale du parc éolien et les couts d'interventions\n");
printf("2.Descriptif détaillé jour par jour de la progression du vent ainsi que de la production journalière de l’ensemble des éoliennes\n");
printf("3.Production max sur une période définie\n");
printf("4.Production min sur une période définie\n");
printf("5.Production journalière pour un jour défini\n");
printf("6.Quitter\n");
scanf("%d",&choix);
switch(choix)
{
 case 1:
 production_aléatoire(matrice,prod);
 break;
 case 2:
 descriptif(matrice,prod);
 break;
 case 3:
 printf("La production max est de %fMW\n",production_max(prod));
 break;
 case 4:
 printf("La production min est 0MW\n");
 break;
 case 5:
 simulation_journée(matrice,prod);
 break;
 case 6:
 quitter=false;
 break;
}
}
}

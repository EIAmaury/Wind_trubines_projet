#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>


void simulation_journée(float matrice[3][3],float prod[]);
float production_max(float prod[]);
int calcul_vent(float matrice[3][3],float prod[],int vent);
bool calcul_panne(float p_proba_panne);
void production_aléatoire(float matrice[3][3],float prod[]);
void descriptif(float matrice[3][3],float prod[]);

Ce document vise à expliciter les conditions d’utilisations de notre programme visant à rendre compte d’une simulation d’un parc éolien sur une plage horaire donnée avec un nombre d’éoliennes choisi préalablement. Le programme a été conçu dans le but de permettre à un opérateur de simuler et comprendre les données de son parc éolien.
 
Pour pouvoir générer l’exécutable ,on veillera à exécuter dans un premier temps les deux commandes suivantes : 
make projet_1_v7_main
./ projet_1_v7_main
 
L’exécution du programme renvoie un menu qui permet à l’utilisateur de choisir entre 6 fonctionnalités : 
 
	1 : la production totale du parc éolien ainsi que les coûts d’intervention
	2 : le descriptif détaillé jour par jour de la progression du vent ainsi que de la production journalière de l’ensemble des éoliennes
	3 : la production maximale du parc sur une période définie
	4 : la production minimale du parc sur une période définie	
	5 : la production journalière sur une journée que l’utilisateur pourra choisir
	6 : Quitter 
 
Les 5 premières fonctionnalités renvoient alors des données précises sur le terminal. Le dernier choix laisse la possibilité à l’utilisateur de quitter le programme quand il le souhaite.
 
Le programme utilise un Makefile pour le rendre plus simple à exécuter et comprendre.
Le module contient deux fichiers : 
Le premier est une interface intitulée projet_1_v7.h. C’est un fichier d’en-tête qui spécifie les fonctionnalités offertes par le programme.
Le deuxième est une implémentation des fonctionnalités spécifiées par le programme intitulée projet_1_v7.c, c’est-à-dire l’ensemble des fonctions du programme.
 
Enfin, le fichier projet_1_v7_main renferme le menu de l’utilisateur. 

Il est aussi nécessaire de détailler ici les différents choix techniques imposés par le programme. Le programme a été conçu pour être le plus simple et facile d’utilisation et de compréhension. Il utilise des éléments classiques du langage C comme des tableaux, des matrices (pour gérer la transition du vent) ou encore de l’allocation dynamique (nécessaire étant donné que les tableaux peuvent être très volumineux en fonction du nombre de jours choisi par l’utilisateur).


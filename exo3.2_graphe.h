#ifndef __GRAPHE_H__
#define __GRAPHE_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define NB_SOMMETS_MAX 20

// Structure de données pour les graphes : matrices d'adjacences
typedef struct
{
    int nb_sommets;
    int ** matrice;
} t_graphe;

// Fonctions de base
t_graphe * creer_graphe(int nb_sommets);
t_graphe * reset_graphe(t_graphe * G);
t_graphe * creer_graphe_aleatoirement(void);
t_graphe * ajout_aleatoire_adj(t_graphe * G);
void liberer_graphe(t_graphe * G);
void afficher_graphe(t_graphe * G);
void ajouter_adjacence(t_graphe * G, int src, int dest);
void sauver_graphe(t_graphe * G, char * nom_fichier);
t_graphe * charger_graphe(const char * nom_fichier);

// Algorithme de parcours en profondeur
t_graphe * parcours_profondeur(t_graphe * G, int v);
void DFS(t_graphe * G, int v, int * pere, bool * estMarque);

#endif

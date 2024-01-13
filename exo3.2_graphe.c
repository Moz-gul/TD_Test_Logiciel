#include "exo3.2_graphe.h"

// CREATION DE GRAPHE
t_graphe * creer_graphe(int nb_sommets)
{
    // Allocation dynamique du graphe et de sa matrice d'adjacences
    t_graphe * G = (t_graphe*) malloc(sizeof(t_graphe));
    if(G != NULL)
    {
        G->matrice = (int**) malloc(nb_sommets*sizeof(int*));
        if(G->matrice != NULL)
        {
            for(int i=0 ; i<nb_sommets ; i++)
                G->matrice[i] = (int*) malloc(nb_sommets*sizeof(int));
            G->nb_sommets = nb_sommets;
            return reset_graphe(G);
        }
    }
    printf("Echec de la creation de graphe\n");
    exit(EXIT_FAILURE);   
}


//Réinitalise le graphe
t_graphe * reset_graphe(t_graphe * G)
{
    for(int l=0 ; l<G->nb_sommets ; l++)
        for(int c=0 ; c<G->nb_sommets ; c++) 
            G->matrice[l][c] = 0;
    return G;
}



// CREATION ALEATOIRE DE GRAPHE
t_graphe * creer_graphe_aleatoirement(void)
{
    srand(time(NULL));

    // Dimensionnement aleatoire du graphe
    int nb_sommets = (rand() % (NB_SOMMETS_MAX-1)) + 2;  // entre 2 et NB_SOMMETS_MAX sommets
    t_graphe * G = creer_graphe(nb_sommets);
    return ajout_aleatoire_adj(G);
}


// AJOUT ALÉATOIRE D'ADJACENCES
t_graphe * ajout_aleatoire_adj(t_graphe * G)
{
    int nb_adjecences = (rand() % G->nb_sommets*2) + 5;    // entre 5 et nb_sommets*2 + 5 ajout d'adjacences
    int src, dest;

    for(int i=0 ; i<nb_adjecences ; i++)
    {
        do{
            src = rand() % G->nb_sommets;
            dest = rand() % G->nb_sommets;
        } while(src == dest);
        ajouter_adjacence(G, src, dest);
    }
    return G;
}


// LIBERATION DE GRAPHE
void liberer_graphe(t_graphe * G)
{
    for(int l=0 ; l<G->nb_sommets ; l++)
        free(G->matrice[l]);
    free(G->matrice);
    free(G);
}


// AJOUTER UNE ADJACENCE
// On suppose que tous les graphes sont orientés
void ajouter_adjacence(t_graphe * G, int src, int dest)
{
    if((src < G->nb_sommets) && (dest < G->nb_sommets))
    {
        if(src != dest)
            G->matrice[src][dest] = 1;
        else printf("Echec de l'ajout d'une adjacence : les sommets choisis ne doivent pas etre les memes\n");
    }
    else printf("Echec de l'ajout d'une adjacence : au moins un sommet n'existe pas\n");
}


// PARCOURS EN PROFONDEUR
t_graphe * parcours_profondeur(t_graphe * G, int v)
{
    // Initialisation : creation de 2 tableaux
    int * pere = (int*) malloc(G->nb_sommets * sizeof(int));
    bool * estMarque = (bool*) malloc(G->nb_sommets * sizeof(bool));
    for(int i=0 ; i<G->nb_sommets ; i++)
    {
        pere[i] = 1000; // nil
        estMarque[i] = false;
    }

    // Exploration du graphe
    DFS(G, v, pere, estMarque);

    // Verification que tous les sommets aient ete explores
    for(int i=0 ; i<G->nb_sommets ; i++)
        // Si un sommet n'est pas marque, lancement d'un parcours a partir de ce dernier
        if(estMarque[i] == false) DFS(G, i, pere, estMarque);

    // Creation de l'arborescence
    t_graphe * A = creer_graphe(G->nb_sommets);
    for(int i=0 ; i<G->nb_sommets ; i++)
        if(pere[i] < 1000) A->matrice[pere[i]][i] = 1;

    return A;
}


// DEPTH FIRST SEARCH
void DFS(t_graphe * G, int v, int * pere, bool * estMarque)
{
    estMarque[v] = true;
    for(int c=0 ; c<G->nb_sommets ; c++)
    {
        if(G->matrice[v][c] == 1)
        {
            if(estMarque[c] == false)
            {
                pere[c] = v;
                DFS(G, c, pere, estMarque);
            }
        }
    }
}


// RECUPERER UN GRAPHE DEPUIS UN FICHIER
t_graphe * charger_graphe(const char * nom_fichier)
{
    FILE * fichier = fopen(nom_fichier, "r");
    if(fichier == NULL)
    {
        printf("Erreur d'ouverture de fichier\n");
        exit(EXIT_FAILURE);
    }

    int nb_sommets;
    fscanf(fichier, "%d", &nb_sommets);
    t_graphe * G = creer_graphe(nb_sommets);

    for(int l=0 ; l<nb_sommets ; l++)
        for(int c=0 ; c<nb_sommets ; c++) 
            fscanf(fichier, "%d", &G->matrice[l][c]);

    fclose(fichier);
    return G;
}

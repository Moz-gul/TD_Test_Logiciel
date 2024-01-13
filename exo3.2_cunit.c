#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "exo3.2_graphe.h"



int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

// Test case for creer_graphe
void test_creer_graphe(void) {
    int nb_sommets = 5;
    t_graphe* G = creer_graphe(nb_sommets);

    // Perform assertions to check if G is created correctly
    CU_ASSERT_PTR_NOT_NULL(G);
    CU_ASSERT_PTR_NOT_NULL(G->matrice);
    for(int i=0 ; i<G->nb_sommets ; i++)
        CU_ASSERT_PTR_NOT_NULL(G->matrice[i]);
    for(int l=0 ; l<G->nb_sommets ; l++)
        for(int c=0 ; c<G->nb_sommets ; c++)
            CU_ASSERT_FALSE(G->matrice[l][c]);

    liberer_graphe(G);
}

// Test case for creer_graphe_aleatoirement
void test_creer_graphe_aleatoirement(void) {
    t_graphe* G = creer_graphe_aleatoirement();
    int count=0;

    // Perform assertions to check if G is created correctly
    CU_ASSERT_PTR_NOT_NULL(G);
    CU_ASSERT_PTR_NOT_NULL(G->matrice);
    for(int i=0 ; i<G->nb_sommets ; i++)
        CU_ASSERT_PTR_NOT_NULL(G->matrice[i]);
    for(int l=0 ; l<G->nb_sommets ; l++)
        for(int c=0 ; c<G->nb_sommets ; c++)
            count+=G->matrice[l][c];
    CU_ASSERT_TRUE(count);

    liberer_graphe(G);
}

// Test case for ajouter_adjacence
void test_ajouter_adjacence(void) {
    int nb_sommets = 5;
    t_graphe* G = creer_graphe(nb_sommets);

    CU_ASSERT_FALSE(G->matrice[0][1]);

    ajouter_adjacence(G, 0, 1);

    // Perform assertions to check if the adjacency is added correctly
    for(int l=0 ; l<G->nb_sommets ; l++)
        for(int c=0 ; c<G->nb_sommets ; c++)
        {   
            if (l==0 & c==1)
                {CU_ASSERT_TRUE(G->matrice[l][c]);}
            else
                {CU_ASSERT_FALSE(G->matrice[l][c]);}
        }

    liberer_graphe(G);
}

// Test case for creer_graphe
void test_charger_graphe(void) {
    t_graphe* G = charger_graphe("exemple_CM1_p43");

    // Perform assertions to check if G is created correctly
    CU_ASSERT_PTR_NOT_NULL(G);
    CU_ASSERT_PTR_NOT_NULL(G->matrice);
    for(int i=0 ; i<G->nb_sommets ; i++)
        CU_ASSERT_PTR_NOT_NULL(G->matrice[i]);
    CU_ASSERT_TRUE(G->matrice[0][1]);
    CU_ASSERT_TRUE(G->matrice[0][2]);
    CU_ASSERT_TRUE(G->matrice[1][4]);
    CU_ASSERT_TRUE(G->matrice[2][3]);
    CU_ASSERT_TRUE(G->matrice[2][5]);
    CU_ASSERT_TRUE(G->matrice[3][0]);
    CU_ASSERT_TRUE(G->matrice[4][5]);
    CU_ASSERT_TRUE(G->matrice[5][3]);
    CU_ASSERT_TRUE(G->matrice[5][4]);
    CU_ASSERT_TRUE(G->matrice[7][8]);
    CU_ASSERT_TRUE(G->matrice[8][6]);
    CU_ASSERT_TRUE(G->matrice[8][9]);
    CU_ASSERT_TRUE(G->matrice[9][7]);

    liberer_graphe(G);
}

// Test case for parcours_profondeur
void test_parcours_profondeur(void) {
    t_graphe* G = charger_graphe("exemple_CM1_p43");
    t_graphe* A = charger_graphe("exemple_CM1_p43_parcours_profondeur");

    t_graphe* A2 = parcours_profondeur(G, 0);

    // Perform assertions to check if G is created correctly

    for(int l=0 ; l<G->nb_sommets ; l++)
        for(int c=0 ; c<G->nb_sommets ; c++)
            CU_ASSERT_EQUAL(A->matrice[l][c],A2->matrice[l][c]);
    

    liberer_graphe(G);
    liberer_graphe(A);
    liberer_graphe(A2);
}

// Main function to run the tests
int main() {
    // Initialize the test suite
    if (CUE_SUCCESS != CU_initialize_registry()) {
        return CU_get_error();
    }

    // Add a suite to the registry
    CU_pSuite pSuite = CU_add_suite("Suite", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add the tests to the suite
    if ((NULL == CU_add_test(pSuite, "test_creer_graphe", test_creer_graphe)) ||
        (NULL == CU_add_test(pSuite, "test_creer_graphe_aleatoirement", test_creer_graphe_aleatoirement)) ||
        (NULL == CU_add_test(pSuite, "test_ajouter_adjacence", test_ajouter_adjacence)) ||
        (NULL == CU_add_test(pSuite, "test_charger_graphe", test_charger_graphe)) ||
        (NULL == CU_add_test(pSuite, "test_parcours_profondeur", test_parcours_profondeur))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run all tests using the basic interface
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // Cleanup and return
    CU_cleanup_registry();
    return CU_get_error();
}

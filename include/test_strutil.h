#ifndef STRUTIL_TEST_STRUTIL_H
#define STRUTIL_TEST_STRUTIL_H

/**
 * @brief Point d'entrée pour exécuter tous les tests de la bibliothèque strutil.
 * @return 0 si tous les tests passent, le nombre d'échecs sinon.
 */
int run_all_tests();

// Fonctions de test spécifiques
void test_str_trim();
void test_str_trim_inplace();
void test_str_left_trim();
void test_str_left_trim_inplace();
void test_str_right_trim();
void test_str_right_trim_inplace(); // Ajouté pour la cohérence
void test_str_case();
void test_str_pad();
void test_str_reverse(); // Nouveau test pour str_reverse
void test_str_reverse_inplace(); // Ajouté pour la cohérence

void test_str_startsWith();
void test_str_endsWith();
void test_str_contains();
void test_str_isNumeric();
void test_str_isAlpha();
void test_str_isEmptyOrWhitespace();

void test_str_substring();
void test_str_repeat();
void test_str_replace();
void test_str_split();
void test_str_join();

#endif //STRUTIL_TEST_STRUTIL_H


#ifndef STRUTIL_H
#define STRUTIL_H

#include <stdlib.h>

/**
 * @file strutil.h
 * @brief Fonctions utilitaires pour la manipulation de chaînes de caractères (string).
 */

/**
 * @brief Supprime les espaces blancs au début et à la fin d'une chaîne.
 *
 * Cette fonction crée une copie de la chaîne originale sans les espaces de début et de fin.
 * Elle alloue dynamiquement de la mémoire.
 *
 * @param str La chaîne de caractères source à traiter.
 * @return Un pointeur vers la nouvelle chaîne allouée, ou NULL si l'allocation échoue.
 * @note L'utilisateur est responsable de libérer la mémoire avec free().
 */
char* str_trim(const char* str);

/**
 * @brief Supprime les espaces blancs au début et à la fin d'une chaîne en place.
 *
 * Modifie directement la chaîne passée en paramètre sans allocation de mémoire supplémentaire.
 *
 * @param str La chaîne de caractères à modifier.
 * @return Un pointeur vers le début de la chaîne traitée à l'intérieur du tampon d'origine.
 */
char* str_trim_inplace(char* str);

/**
 * @brief Cette fonction crée une copie de la chaîne originale sans les espaces de début. Elle alloue dynamiquement de la mémoire
 * @param str La chaîne de caractère source à traiter.
 * @return Un pointeur vers la nouvelle chaîne allouée, ou NULL si l'allocation échoue.
 * @note L'utilisateur est responsable de libérer de la mémoire avec free().
 */
char* str_left_trim(const char* str);

/**
 *@brief Cette fonction supprime les espaces blancs au début d'une chaîne en place.
 * @param str La chaîne de caractères à modifier.
 * @return Un pointeur vers le début de la chaîne traitée à l'intérieur du tampon d'origine.
 */
char* str_left_trim_inplace(char* str);

/**
 * @brief Cette fonction crée une copie de la chaîne originale sans les espaces de fin. Elle alloue dynamiquement de la mémoire
 * @param str La chaîne de caractère source à traiter.
 * @return Un pointeur vers la nouvelle chaîne allouée, ou NULL si l'allocation échoue.
 * @note L'utilisateur est responsable de libérer de la mémoire avec free().
 */
char* str_right_trim(const char* str);

/**
 *@brief Cette fonction supprime les espaces blancs en fin d'une chaîne en place.
 * @param str La chaîne de caractères à modifier.
 * @return Un pointeur vers le début de la chaîne traitée à l'intérieur du tampon d'origine.
 */
char* str_right_trim_inplace(char* str);

/**
 * @brief Cette fonction crée une nouvelle chaîne de caractères en ajoutant des caractères de remplissage à gauche d'une chaîne donnée.
 *
 * @param str La chaîne de caractères source à traiter.
 * @param total_length La longueur totale souhaitée pour la nouvelle chaîne (y compris les caractères de remplissage).
 * @param pad_char Le caractère à utiliser pour le remplissage.
 * @return Un pointeur vers la nouvelle chaîne allouée, ou NULL si l'allocation échoue ou si total_length est inférieur à la longueur de str.
 * @note L'utilisateur est responsable de libérer de la mémoire avec free().
 */
char* str_pad_left(const char* str, size_t total_length, char pad_char);

/**
 * @brief Cette fonction ajoute des caractères de remplissage à gauche d'une chaîne donnée en place.
 * @param str La chaîne de caractères à modifier. Doit être suffisamment grande pour contenir la nouvelle chaîne.
 * @param total_length La longueur totale souhaitée pour la chaîne après ajout du remplissage (y compris les caractères de remplissage).
 * @param pad_char Le caractère à utiliser pour le remplissage.
 * @return Un pointeur vers la chaîne modifiée, ou NULL si total_length est inférieur à la longueur de str.
 * @warning IMPORTANT : L'utilisateur DOIT garantir que le buffer pointé par str a une capacité >= total_length + 1 octets.
 *          En cas de buffer insuffisant, comportement indéfini (débordement de mémoire).
 * @note La chaîne d'origine doit être suffisamment grande pour contenir la nouvelle chaîne après ajout du remplissage.
 * @example
 *   char buffer[11] = "test";  // Capacité = 11 octets
 *   str_pad_left_inplace(buffer, 10, '*');  // OK: buffer est assez grand
 *   // buffer devient "******test"
 */
char* str_pad_left_inplace(char* str, size_t total_length, char pad_char);

/**
 * @brief Cette fonction crée une nouvelle chaîne de caractères en ajoutant des caractères de remplissage à droite d'une chaîne donnée.
 *
 * @param str La chaîne de caractères source à traiter.
 * @param total_length La longueur totale souhaitée pour la nouvelle chaîne (y compris les caractères de remplissage).
 * @param pad_char Le caractère à utiliser pour le remplissage.
 * @return Un pointeur vers la nouvelle chaîne allouée, ou NULL si l'allocation échoue ou si total_length est inférieur à la longueur de str.
 * @note L'utilisateur est responsable de libérer de la mémoire avec free().
 */
char* str_pad_right(const char* str, size_t total_length, char pad_char);

/**
 * @brief Cette fonction ajoute des caractères de remplissage à droite d'une chaîne donnée en place.
 * @param str La chaîne de caractères à modifier. Doit être suffisamment grande pour contenir la nouvelle chaîne.
 * @param total_length La longueur totale souhaitée pour la chaîne après ajout du remplissage (y compris les caractères de remplissage).
 * @param pad_char Le caractère à utiliser pour le remplissage.
 * @return Un pointeur vers la chaîne modifiée, ou NULL si total_length est inférieur à la longueur de str.
 * @warning IMPORTANT : L'utilisateur DOIT garantir que le buffer pointé par str a une capacité >= total_length + 1 octets.
 * @note Les paramètres sont dans l'ordre : str, total_length, pad_char
 */
char* str_pad_right_inplace(char* str, size_t total_length, char pad_char);

/**
 * @brief Cette fonction crée une nouvelle chaîne de caractères en ajoutant des caractères de remplissage à gauche ou à droite d'une chaîne donnée.
 * @param str La chaîne de caractères source à traiter.
 * @param total_length La longueur totale souhaitée pour la nouvelle chaîne (y compris les caractères de remplissage).
 * @param pad_char Le caractère à utiliser pour le remplissage.
 * @param pad_left Un entier indiquant si le remplissage doit être ajouté à gauche (non zéro) ou à droite (zéro).
 * @return Un pointeur vers la nouvelle chaîne allouée, ou NULL si l'allocation échoue ou si total_length est inférieur à la longueur de str.
 * @note L'utilisateur est responsable de libérer de la mémoire avec free().
 */
char* str_pad(const char* str, size_t total_length, char pad_char, int pad_left);

/**
 * @brief Cette fonction ajoute des caractères de remplissage à gauche ou à droite d'une chaîne donnée en place.
 * @param str La chaîne de caractères à modifier. Doit être suffisamment grande pour contenir la nouvelle chaîne.
 * @param total_length La longueur totale souhaitée pour la chaîne après ajout du remplissage (y compris les caractères de remplissage).
 * @param pad_char Le caractère à utiliser pour le remplissage.
 * @param pad_left Un entier indiquant si le remplissage doit être ajouté à gauche (non zéro) ou à droite (zéro).
 * @return Un pointeur vers la chaîne modifiée, ou NULL si total_length est inférieur à la longueur de str
 * @warning IMPORTANT : L'utilisateur DOIT garantir que le buffer pointé par str a une capacité >= total_length + 1 octets.
 * @note Paramètres dans l'ordre : str, total_length, pad_char, pad_left
 */
char* str_pad_inplace(char* str, size_t total_length, char pad_char, int pad_left);

/**
 * @brief Cette fonction convertit une chaîne de caractères en minuscules.
 * @param str La chaîne de caractères source à traiter.
 * @return Un pointeur vers la nouvelle chaîne allouée, ou NULL si l'allocation échoue.
 * @note L'utilisateur est responsable de libérer de la mémoire avec free().
 */
char* str_toLower(const char* str);

/**
 * @brief Cette fonction convertit une chaîne de caractères en minuscules en place.
 * @param str La chaîne de caractères à modifier.
 * @return Un pointeur vers la chaîne modifiée, ou NULL si allocation échoue.
 * @note Pas d'allocation de mémoire supplémentaire - modifie la chaîne sur place.
 */
char* str_toLower_inplace(char* str);

/**
 * @brief Cette fonction convertit une chaîne de caractères en majuscules.
 * @param str La chaîne de caractères source à traiter.
 * @return Un pointeur vers la nouvelle chaîne allouée, ou NULL si l'allocation échoue.
 * @note L'utilisateur est responsable de libérer de la mémoire avec free().
 */
char* str_toUpper(const char* str);

/**
 * @brief Cette fonction convertit une chaîne de caractères en majuscules en place.
 * @param str La chaîne de caractères à modifier. Doit être suffisamment grande pour contenir la nouvelle chaîne.
 * @return Un pointeur vers la chaîne modifiée, ou NULL si l'allocation échoue.
 */
char* str_toUpper_inplace(char* str);

/**
 * @brief Cette fonction convertit une chaîne de caractères en format "Title Case" (première lettre de chaque mot en majuscule, le reste en minuscule).
 * @param str La chaîne de caractères source à traiter.
 * @return Un pointeur vers la nouvelle chaîne allouée, ou NULL si l'allocation échoue.
 * @note L'utilisateur est responsable de libérer de la mémoire avec free().
 */
char* str_titleCase(const char* str);

/**
 * @brief Cette fonction convertit une chaîne de caractères en format "Title Case" en place.
 * @param str La chaîne de caractères à modifier.
 * @return Un pointeur vers la chaîne modifiée.
 */
char* str_titleCase_inplace(char* str);

/**
 * @brief Cette fonction inverse une chaîne de caractères (génère une copie).
 * @param str La chaîne de caractères source à inverser.
 * @return Un pointeur vers la nouvelle chaîne allouée inversée, ou NULL si allocation échoue.
 * @note L'utilisateur est responsable de libérer la mémoire avec free().
 * @example
 *   char* result = str_reverse("hello");  // "olleh"
 *   free(result);
 */
char* str_reverse(const char* str);

/**
 * @brief Cette fonction inverse une chaîne de caractères en place.
 * @param str La chaîne de caractères à inverser.
 * @return Un pointeur vers la chaîne modifiée, ou NULL en cas d'erreur.
 */
char* str_reverse_inplace(char* str);

/**
 * @brief Cette fonction vérifie si la chaîne commence par un préfixe.
 * @param str La chaîne de caractère source à vérifier.
 * @param prefix Le préfixe à rechercher au début de la chaîne.
 * @return 1 (vrai) si la chaîne commence par le préfixe, 0 (faux) sinon.
 * @note Retourne 0 si str ou prefix est NULL.
 * @example
 *   str_startsWith("hello world", "hello");  // Retourne 1
 *   str_startsWith("hello world", "world");  // Retourne 0
 */
int str_startsWith(const char* str, const char* prefix);

/**
 * @brief Cette fonction vérifie si la chaîne se termine par un suffixe.
 * @param str La chaîne de caractère source à vérifier.
 * @param suffix Le suffixe à rechercher à la fin de la chaîne.
 * @return 1 (vrai) si la chaîne se termine par le suffixe, 0 (faux) sinon.
 * @note Retourne 0 si str ou suffix est NULL.
 * @example
 *   str_endsWith("hello world", "world");  // Retourne 1
 *   str_endsWith("hello world", "hello");  // Retourne 0
 */
int str_endsWith(const char* str, const char* suffix);

/**
 * @brief Cette fonction vérifie si une sous-chaîne est présente dans la chaîne.
 * @param str La chaîne de caractère source à vérifier.
 * @param substring La sous-chaîne à rechercher.
 * @return 1 (vrai) si la sous-chaîne est présente, 0 (faux) sinon.
 * @note Retourne 0 si str ou substring est NULL.
 * @example
 *   str_contains("hello world", "world");  // Retourne 1
 *   str_contains("hello world", "xyz");    // Retourne 0
 */
int str_contains(const char* str, const char* substring);

/**
 * @brief Cette fonction vérifie si la chaîne contient uniquement des chiffres (0-9).
 * @param str La chaîne de caractères à vérifier.
 * @return 1 (vrai) si la chaîne ne contient que des chiffres, 0 (faux) sinon.
 * @note Retourne 0 si str est NULL ou vide.
 * @example
 *   str_isNumeric("12345");   // Retourne 1
 *   str_isNumeric("123abc");  // Retourne 0
 */
int str_isNumeric(const char* str);

/**
 * @brief Cette fonction vérifie si la chaîne contient uniquement des lettres de l'alphabet.
 * @param str La chaîne de caractères à vérifier.
 * @return 1 (vrai) si la chaîne ne contient que des lettres, 0 (faux) sinon.
 * @note Retourne 0 si str est NULL ou vide.
 * @example
 *   str_isAlpha("hello");      // Retourne 1
 *   str_isAlpha("hello123");   // Retourne 0
 */
int str_isAlpha(const char* str);

/**
 * @brief Cette fonction vérifie si la chaîne est vide ou ne contient que des espaces blancs.
 * @param str La chaîne de caractères à vérifier.
 * @return 1 (vrai) si la chaîne est vide ou contient uniquement des espaces, 0 (faux) sinon.
 * @note Retourne 1 si str est NULL.
 * @example
 *   str_isEmptyOrWhitespace("");       // Retourne 1
 *   str_isEmptyOrWhitespace("   ");    // Retourne 1
 *   str_isEmptyOrWhitespace("hello");  // Retourne 0
 */
int str_isEmptyOrWhitespace(const char* str);

/**
 * @brief Cette fonction extrait une sous-chaîne d'une chaîne donnée.
 * @param str La chaîne de caractères source à traiter.
 * @return Un pointeur vers la nouvelle chaîne allouée contenant la sous-chaîne extraite, ou NULL si l'allocation échoue.
 * @note L'utilisateur est responsable de libérer de la mémoire avec free().
 * @example
 *   char* result = str_substring("hello world");  // "hello world" (extrait la chaîne entière dans cet exemple)
 *   free(result);
 *   char* result2 = str_substring("hello world", 0, 5);  // "hello" (extrait les 5 premiers caractères)
 *   free(result2);
 */
char* str_substring(const char* str);

/**
 * @brief Cette fonction répète une chaîne de caractères un nombre spécifié de fois.
 * @param str La chaîne de caractères source à répéter.
 * @param count Le nombre de fois que la chaîne doit être répétée.
 * @return Un pointeur vers la nouvelle chaîne allouée contenant la chaîne répétée, ou NULL si l'allocation échoue.
 * @note L'utilisateur est responsable de libérer de la mémoire avec free().
 * @example
 *   char* result = str_repeat("abc", 3);  // "abcabcabc"
 *   free(result);
 *   char* result2 = str_repeat("xyz", 0);  // "" (chaîne vide)
 *   free(result2);
 */
char* str_repeat(const char* str, size_t count);

/**
 * @brief Cette fonction remplace toutes les occurrences d'une sous-chaîne par une autre dans une chaîne donnée.
 * @param str La chaîne de caractères source à traiter.
 * @param target La sous-chaîne à remplacer.
 * @replacement La sous-chaîne de remplacement.
 * @return Un pointeur vers la nouvelle chaîne allouée contenant le résultat du remplacement, ou NULL si l'allocation échoue.
 * @note L'utilisateur est responsable de libérer de la mémoire avec free().
 * @example
 *   char* result = str_replace("hello world", "world", "there");  // "hello there"
 *   free(result);
 *   char* result2 = str_replace("abcabc", "abc", "x");  // "xx"
 *   free(result2);
 */
char* str_replace(const char* str, const char* target, const char* replacement);

/**
 * @brief Cette fonction divise une chaîne de caractères en un tableau de sous-chaînes en utilisant un délimiteur spécifié.
 * @param str La chaîne de caractères source à diviser.
 * @param delimiter Le caractère utilisé comme délimiteur pour diviser la chaîne.
 * @param out_count Un pointeur vers une variable de type size_t où sera stocké le nombre de sous-chaînes résultantes.
 * @return Un pointeur vers un tableau de chaînes allouées, ou NULL si l'allocation échoue. Le nombre de sous-chaînes est stocké dans out_count.
 * @note L'utilisateur est responsable de libérer la mémoire allouée pour le tableau et les chaînes individuelles avec free().
 * @example
 *   char* str = "apple,banana,cherry";
 *   size_t count;
 *   char** result = str_split(str, ',', &count);  // result[0] = "apple", result[1] = "banana", result[2] = "cherry", count = 3
 *   
 */
char** str_split(const char* str, char delimiter, size_t* out_count);

/**
 * @brief Cette fonction joint un tableau de chaînes de caractères en une seule chaîne en utilisant un séparateur spécifié.
 * @param strings Un tableau de chaînes de caractères à joindre.
 * @param count Le nombre de chaînes dans le tableau.
 * @param separator Le séparateur à insérer entre les chaînes lors de la jonction.
 * @return Un pointeur vers la nouvelle chaîne allouée résultant de la jonction, ou NULL si l'allocation échoue.
 * @note L'utilisateur est responsable de libérer la mémoire allouée avec free().
 * @example
 *   char* strings[] = {"apple", "banana", "cherry"};
 *   char* result = str_join(strings, 3, ", ");  // "apple, banana, cherry"
 *   free(result);
 *   char* string2[] = {"hello", NULL, "world"};
 *   char* result2 = str_join(string2, 1, ", ");  // "hello"
 *   free(result2);
 */
char** str_join(const char** strings, size_t count, const char* separator);
#endif /* STRUTIL_H */
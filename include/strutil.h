
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
 * @note La chaîne d'origine doit être suffisamment grande pour contenir la nouvelle chaîne après ajout du remplissage. L'utilisateur doit s'assurer que la mémoire est gérée correctement pour éviter les dépassements de tampon.
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
 * @param pad_char Le caractère à utiliser pour le remplissage.
 * @param total_length La longueur totale souhaitée pour la chaîne après ajout du remplissage (y compris les caractères de remplissage).
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
 * @param pad_left Un entier indiquant si le remplissage doit être ajouté à gauche (non zéro) ou à droite (zéro).
 * @param total_length La longueur totale souhaitée pour la chaîne après ajout du remplissage (y compris les caractères de remplissage).
 * @param pad_char Le caractère à utiliser pour le remplissage.
 * @return Un pointeur vers la chaîne modifiée, ou NULL si l'allocation échoue ou si total_length est inférieur à la longueur de str
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
 * @param str La chaîne de caractères à modifier. Doit être suffisamment grande pour contenir la nouvelle chaîne.
 * @return Un pointeur vers la chaîne modifiée, ou NULL si l'allocation éch
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
 * @brief Cette fonction inverse une chaîne de caractères.
 * @param str La chaîne de caractères source à traiter.
 * @return Un pointeur vers la nouvelle chaîne.
 */
char* str_reverse_inplace(char* str);

/**
 * @brief Cette fonction
 * @param str La chaîne de caractère source à traiter.
 * @return Un pointeur vers la nouvelle chaîne allouée, ou NULL si l'allocation échoue.
 * @note L'utilisateur est responsable de libérer la mémoire avec free().
 */
char* str_reverse(const char* str);

/**
 * @brief Cette fonction vérifie si la chaîne commence par un préfixe.
 * @param str La chaîne de caractère source à vérifier.
 * @param substr Le préfixe
 * @return Un entier (1) si la chaine commence par un préfixe donné, (0) dans le cas contraire ou si les chaîne et le préfixe sont NULL, ou si la taille du préfixe est supérieur à la taille de la chaîne.
 */
int str_startsWith(const char* str, const char* substr);

/**
 * @brief Cette fonction vérifie si la chaîne se termine par un préfixe.
 * @param str La chaîne de caractère source à vérifier.
 * @param substr Le préfixe de fin de chaîne.
 * @return Un entier (1) si la chaine se termine par un préfixe donné, (0) dans le cas contraire ou si les chaîne et le préfixe sont NULL, ou si la taille du préfixe est supérieur à la taille de la chaîne.
 */
int str_endsWith(const char* str, const char* substr);

/**
 *
 * @param str La chaîne de caractère source à vérifier.
 * @param substr Le mot ou sous-chaîne à véridier si présent dans la chaîne
 * @return Un entier (1) si le mot ou sous-chaîne n'est pas présent dans la chaîne, (0) dans le cas contraire ou si les chaîne et le préfixe sont NULL, ou si la taille du préfixe est supérieur à la taille de la chaîne.
 */
int str_contains(const char* str, const char* substr);
#endif /* STRUTIL_H */
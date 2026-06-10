# StrUtil - Bibliothèque Utilitaire pour Chaînes de Caractères en C

## 📋 Description

**StrUtil** est une bibliothèque C moderne et performante qui fournit un ensemble complet de fonctions utilitaires pour manipuler et traiter les chaînes de caractères. Elle offre des opérations courantes comme le trimming, le padding, la conversion de casse et bien plus encore.

Conçue avec C11, cette bibliothèque met l'accent sur :
- **Performance** : opérations optimisées avec allocation mémoire efficace
- **Flexibilité** : versions in-place (modification directe) et allocantes (création de copie)
- **Portabilité** : compatible avec les standards C11
- **Sécurité** : gestion robuste des pointeurs NULL et des cas limites

## 📋 Feuille de route : Bibliothèque strutil

### 🔹 Module 1 : Nettoyage & Espaces (Trimming)
*Ces fonctions retirent les espaces blancs (' ', '\t', '\n', etc.).*

- [x] **str_ltrim** : Supprime les espaces au début (génère une copie)
- [x] **str_ltrim_inplace** : Supprime les espaces au début (modifie l'original)
- [x] **str_rtrim** : Supprime les espaces à la fin (génère une copie)
- [x] **str_rtrim_inplace** : Supprime les espaces à la fin (modifie l'original)
- [x] **str_trim** : Supprime les espaces au début ET à la fin (génère une copie)
- [x] **str_trim_inplace** : Supprime les espaces au début ET à la fin (modifie l'original)

### 🔹 Module 2 : Alignement & Remplissage (Padding)
*Ces fonctions calibrent la taille d'une chaîne avec un caractère de remplissage.*

- [x] **str_pad_left** : Aligne à gauche une chaîne dans un espace fixe (génère une copie)
- [x] **str_pad_left_inplace** : Aligne à gauche une chaîne dans un espace fixe (modifie l'original)
- [x] **str_pad_right** : Aligne à droite une chaîne dans un espace fixe (génère une copie)
- [x] **str_pad_right_inplace** : Aligne à droite une chaîne dans un espace fixe (modifie l'original)
- [x] **str_pad** : Alignement flexible (génère une copie)
- [x] **str_pad_inplace** : Alignement flexible (modifie l'original)

### 🔹 Module 3 : Casse & Transformation (Casing)
*Ces fonctions modifient la casse des lettres (majuscules/minuscules).*

- [x] **str_toLower** : Convertit toute la chaîne en minuscules (génère une copie)
- [x] **str_toLower_inplace** : Convertit toute la chaîne en minuscules (modifie l'original)
- [x] **str_toUpper** : Convertit toute la chaîne en majuscules (génère une copie)
- [x] **str_toUpper_inplace** : Convertit toute la chaîne en majuscules (modifie l'original)
- [x] **str_titleCase** : Met la première lettre de chaque mot en majuscule, le reste en minuscule (génère une copie)
- [x] **str_titleCase_inplace** : Met la première lettre de chaque mot en majuscule (modifie l'original)
- [x] **str_reverse_inplace** : Inverse l'ordre des caractères d'une chaîne sur place

### 🔹 Module 4 : Analyse & Vérification (Predicates)
*Ces fonctions analysent une chaîne et renvoient un booléen (1 pour vrai, 0 pour faux).*

- [x] **str_startsWith** : Vérifie si la chaîne commence par un préfixe donné
- [x] **str_endsWith** : Vérifie si la chaîne se termine par un suffixe donné
- [x] **str_contains** : Vérifie si un mot ou sous-ensemble est présent dans la chaîne
- [x] **str_isNumeric** : Vérifie si la chaîne ne contient que des chiffres (0-9)
- [x] **str_isAlpha** : Vérifie si la chaîne ne contient que des lettres de l'alphabet
- [x] **str_isEmptyOrWhitespace** : Vérifie si la chaîne est vide ou ne contient que des espaces

### 🔹 Module 5 : Édition, Recherche & Découpage (Advanced)
*Les fonctions de manipulation avancée de la mémoire.*

- [ ] **str_substring** : Extrait de manière sécurisée une portion de la chaîne (génère une copie)
- [ ] **str_repeat** : Répète une chaîne N fois
- [ ] **str_replace** : Remplace toutes les occurrences d'un sous-mot par un autre (génère une copie)
- [ ] **str_split** : Découpe une chaîne selon un délimiteur et renvoie un tableau de chaînes (char **)
- [ ] **str_join** : Prend un tableau de chaînes (char **) et les fusionne en une seule chaîne

### 🔹 Module 6 : Tests & Qualité (Engineering)
- [x] Créer le fichier d'en-tête global `strutil.h`
- [ ] Écrire la suite complète de tests unitaires avec `assert.h` dans `test_strutil.c`
- [x] Écrire un `Makefile` pour automatiser la compilation du projet et des tests

## 🔧 Compilation

### Avec CMake
```bash
mkdir cmake-build-debug
cd cmake-build-debug
cmake ..
cmake --build .
```

### Avec Make (si Makefile disponible)
```bash
make
```

## 📦 Installation

1. Clonez le dépôt :
```bash
git clone https://github.com/votre-utilisateur/strutil.git
cd strutil
```

2. Compilez la bibliothèque :
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## 💻 Utilisation

### Exemple d'utilisation basique

```c
#include "strutil.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    const char* original = "  Hello World  ";
    
    // Suppression des espaces
    char* trimmed = str_trim(original);
    printf("Trim: '%s'\n", trimmed);
    free(trimmed);
    
    // Conversion en majuscules
    char* upper = str_toUpper(original);
    printf("Upper: '%s'\n", upper);
    free(upper);
    
    // Title Case
    char* title = str_titleCase("bonjour le monde");
    printf("Title: '%s'\n", title);
    free(title);
    
    // Padding
    char* padded = str_pad_left("test", 10, '*');
    printf("Padded: '%s'\n", padded);
    free(padded);
    
    return 0;
}
```

### Versions In-Place

Pour plus de performance et moins d'allocations mémoire, utilisez les versions in-place :

```c
char buffer[100] = "  exemple  ";

// Modifie directement le buffer
str_trim_inplace(buffer);
printf("Result: '%s'\n", buffer);
```

⚠️ **Important** : Les versions in-place nécessitent que le buffer soit suffisamment grand pour contenir le résultat.

## 🧪 Tests

La suite de tests est fournie dans `src/test_strutil.c`. Pour exécuter les tests :

```bash
./strutil
```

## 📁 Structure du Projet

```
strutil/
├── include/
│   ├── strutil.h          # En-têtes de la bibliothèque
│   └── test_strutil.h     # En-têtes des tests
├── src/
│   ├── strutil.c          # Implémentation des fonctions
│   ├── test_strutil.c     # Suite de tests
│   └── main.c             # Point d'entrée (tests)
├── CMakeLists.txt         # Configuration CMake
├── Makefile               # Configuration Make
└── README.md              # Ce fichier
```

## 🛠️ API Référence Complète

### Module 1 : Trimming (Nettoyage & Espaces)

#### `char* str_trim(const char* str)` ✅
Supprime les espaces de début et de fin. Alloue une nouvelle chaîne.
```c
const char* input = "  hello world  ";
char* result = str_trim(input);  // "hello world"
free(result);
```

#### `char* str_trim_inplace(char* str)` ✅
Supprime les espaces de début et de fin. Modifie in-place.
```c
char buffer[50] = "  hello world  ";
str_trim_inplace(buffer);  // "hello world"
```

#### `char* str_left_trim(const char* str)` / `str_left_trim_inplace(char* str)` ✅
Supprime uniquement les espaces au début.

#### `char* str_right_trim(const char* str)` / `str_right_trim_inplace(char* str)` ✅
Supprime uniquement les espaces à la fin.

---

### Module 2 : Padding (Alignement & Remplissage)

#### `char* str_pad_left(const char* str, size_t total_length, char pad_char)` ✅
Ajoute des caractères de remplissage à gauche jusqu'à `total_length`.
```c
char* result = str_pad_left("42", 5, '0');  // "00042"
free(result);
```

#### `char* str_pad_left_inplace(char* str, size_t total_length, char pad_char)` ✅
Ajoute des caractères de remplissage à gauche in-place.

#### `char* str_pad_right(const char* str, size_t total_length, char pad_char)` ✅
Ajoute des caractères de remplissage à droite jusqu'à `total_length`.
```c
char* result = str_pad_right("42", 5, '.');  // "42..."
free(result);
```

#### `char* str_pad_right_inplace(char* str, size_t total_length, char pad_char)` ✅
Ajoute des caractères de remplissage à droite in-place.

#### `char* str_pad(const char* str, size_t total_length, char pad_char, int pad_left)` ✅
Remplissage flexible : `pad_left` != 0 pour gauche, 0 pour droite.
```c
char* left = str_pad("X", 3, '*', 1);    // "**X"
char* right = str_pad("X", 3, '*', 0);   // "X**"
free(left);
free(right);
```

#### `char* str_pad_inplace(char* str, size_t total_length, char pad_char, int pad_left)` ✅
Remplissage flexible in-place.

---

### Module 3 : Casing (Casse & Transformation)

#### `char* str_toLower(const char* str)` ✅
Convertit en minuscules. Alloue une nouvelle chaîne.
```c
char* result = str_toLower("HELLO");  // "hello"
free(result);
```

#### `char* str_toLower_inplace(char* str)` ✅
Convertit en minuscules in-place.

#### `char* str_toUpper(const char* str)` ✅
Convertit en majuscules. Alloue une nouvelle chaîne.
```c
char* result = str_toUpper("hello");  // "HELLO"
free(result);
```

#### `char* str_toUpper_inplace(char* str)` ✅
Convertit en majuscules in-place.

#### `char* str_titleCase(const char* str)` ✅
Convertit en "Title Case" (première lettre de chaque mot en majuscule).
```c
char* result = str_titleCase("hello world");  // "Hello World"
free(result);
```

#### `char* str_titleCase_inplace(char* str)` ✅
Convertit en "Title Case" in-place.

#### `char* str_reverse_inplace(char* str)` ✅
Inverse une chaîne de caractères in-place.
```c
char buffer[50] = "hello";
str_reverse_inplace(buffer);  // "olleh"
```

#### `char* str_reverse(const char* str)` ✅
Inverse une chaîne de caractères. Alloue une nouvelle chaîne.
```c
char* result = str_reverse("hello");  // "olleh"
char* result2 = str_reverse("world"); // "dlrow"
free(result);
free(result2);
```

---

### Module 4 : Predicates (Analyse & Vérification) ✅ Complet

#### `int str_startsWith(const char* str, const char* prefix)` ✅
Vérifie si la chaîne commence par un préfixe donné.
```c
int result = str_startsWith("hello world", "hello");  // 1 (true)
int result2 = str_startsWith("hello world", "world"); // 0 (false)
int result3 = str_startsWith(NULL, "test");           // 0 (false)
```

#### `int str_endsWith(const char* str, const char* suffix)` ✅
Vérifie si la chaîne se termine par un suffixe donné.
```c
int result = str_endsWith("hello world", "world");  // 1 (true)
int result2 = str_endsWith("hello world", "hello"); // 0 (false)
int result3 = str_endsWith("test.txt", ".txt");     // 1 (true)
```

#### `int str_contains(const char* str, const char* substring)` ✅
Vérifie si un mot ou sous-ensemble est présent dans la chaîne.
```c
int result = str_contains("hello world", "world");  // 1 (true)
int result2 = str_contains("hello world", "ll");    // 1 (true)
int result3 = str_contains("hello world", "xyz");   // 0 (false)
```

#### `int str_isNumeric(const char* str)` ✅
Vérifie si la chaîne ne contient que des chiffres (0-9).
```c
int result = str_isNumeric("12345");    // 1 (true)
int result2 = str_isNumeric("123abc");  // 0 (false)
int result3 = str_isNumeric("3.14");    // 0 (false - contient un point)
```

#### `int str_isAlpha(const char* str)` ✅
Vérifie si la chaîne ne contient que des lettres de l'alphabet.
```c
int result = str_isAlpha("hello");       // 1 (true)
int result2 = str_isAlpha("hello123");   // 0 (false)
int result3 = str_isAlpha("Hello");      // 1 (true - majuscules/minuscules OK)
```

#### `int str_isEmptyOrWhitespace(const char* str)` ✅
Vérifie si la chaîne est vide ou ne contient que des espaces.
```c
int result = str_isEmptyOrWhitespace("");       // 1 (true - vide)
int result2 = str_isEmptyOrWhitespace("   ");   // 1 (true - espaces)
int result3 = str_isEmptyOrWhitespace("hello"); // 0 (false - contient du texte)
int result4 = str_isEmptyOrWhitespace(NULL);    // 1 (true - NULL)
```

---

### Module 5 : Advanced (Édition, Recherche & Découpage) ⏳ À faire

#### `char* str_substring(const char* str, size_t start, size_t length)` ⏳
Extrait de manière sécurisée une portion de la chaîne.
```c
// À implémenter
// char* result = str_substring("hello world", 0, 5);  // "hello"
// free(result);
```

#### `char* str_repeat(const char* str, size_t count)` ⏳
Répète une chaîne N fois.
```c
// char* result = str_repeat("ab", 3);  // "ababab"
// free(result);
```

#### `char* str_replace(const char* str, const char* find, const char* replace_with)` ⏳
Remplace toutes les occurrences d'un sous-mot par un autre.
```c
// char* result = str_replace("hello world", "world", "there");  // "hello there"
// free(result);
```

#### `char** str_split(const char* str, const char* delimiter, int* count)` ⏳
Découpe une chaîne selon un délimiteur et renvoie un tableau de chaînes.
```c
// int count = 0;
// char** parts = str_split("a,b,c", ",", &count);  // ["a", "b", "c"], count = 3
// // Libérer la mémoire
```

#### `char* str_join(char** strings, int count, const char* separator)` ⏳
Fusionne un tableau de chaînes en une seule chaîne.
```c
// char* arr[] = {"hello", "world"};
// char* result = str_join(arr, 2, " ");  // "hello world"
// free(result);
```

---

## ✅ Statut d'implémentation

| Module | Statut | Progression |
|--------|--------|-------------|
| 1. Trimming | ✅ Complet | 6/6 (100%) |
| 2. Padding | ✅ Complet | 6/6 (100%) |
| 3. Casing | ✅ Complet | 8/8 (100%) |
| 4. Predicates | ✅ Complet | 6/6 (100%) |
| 5. Advanced | ⏳ En cours | 0/5 (0%) |
| **Total** | **ℹ️ En développement** | **26/30 (87%)** |

## 📝 Gestion Mémoire

- Les fonctions **sans** `_inplace` allouent de la mémoire. **L'utilisateur doit libérer** avec `free()`
- Les fonctions **avec** `_inplace` modifient la chaîne donnée directement
- Toutes les fonctions gèrent le cas `NULL` en entrée
- En cas d'erreur d'allocation mémoire, la fonction retourne `NULL`

## 📄 License

Ce projet est libre d'utilisation. Consultez les fichiers du projet pour plus de détails.

## 👤 Auteur

Projet personnel - strutil

## 🤝 Contribution

Les contributions sont bienvenues ! N'hésitez pas à :
- Signaler les bugs
- Suggérer des améliorations
- Proposer des nouvelles fonctionnalités

## 📌 Notes

- La bibliothèque utilise C11 comme standard
- Compatible avec les systèmes Windows, Linux et macOS
- Aucune dépendance externe requise (sauf libc standard)

---

**Dernière mise à jour** : Juin 2026

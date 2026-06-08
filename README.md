# StrUtil - Bibliothèque Utilitaire pour Chaînes de Caractères en C

## 📋 Description

**StrUtil** est une bibliothèque C moderne et performante qui fournit un ensemble complet de fonctions utilitaires pour manipuler et traiter les chaînes de caractères. Elle offre des opérations courantes comme le trimming, le padding, la conversion de casse et bien plus encore.

Conçue avec C11, cette bibliothèque met l'accent sur :
- **Performance** : opérations optimisées avec allocation mémoire efficace
- **Flexibilité** : versions in-place (modification directe) et allocantes (création de copie)
- **Portabilité** : compatible avec les standards C11
- **Sécurité** : gestion robuste des pointeurs NULL et des cas limites

## 🎯 Fonctionnalités

### Suppression d'espaces blancs (Trimming)
- `str_trim()` / `str_trim_inplace()` - Supprime espaces début et fin
- `str_left_trim()` / `str_left_trim_inplace()` - Supprime espaces au début
- `str_right_trim()` / `str_right_trim_inplace()` - Supprime espaces à la fin

### Remplissage (Padding)
- `str_pad_left()` / `str_pad_left_inplace()` - Ajoute des caractères à gauche
- `str_pad_right()` / `str_pad_right_inplace()` - Ajoute des caractères à droite
- `str_pad()` / `str_pad_inplace()` - Remplissage flexible (gauche/droite)

### Conversion de casse
- `str_toLower()` / `str_toLower_inplace()` - Convertit en minuscules
- `str_toUpper()` / `str_toUpper_inplace()` - Convertit en majuscules
- `str_titleCase()` / `str_titleCase_inplace()` - Convertit en "Title Case"

### Manipulation
- `str_reverse_inplace()` - Inverse une chaîne de caractères

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

## 🛠️ API Référence

### Trimming

#### `char* str_trim(const char* str)`
Supprime les espaces de début et de fin. Alloue une nouvelle chaîne.

#### `char* str_trim_inplace(char* str)`
Supprime les espaces de début et de fin. Modifie in-place.

#### `char* str_left_trim(const char* str)` / `str_left_trim_inplace(char* str)`
Supprime uniquement les espaces au début.

#### `char* str_right_trim(const char* str)` / `str_right_trim_inplace(char* str)`
Supprime uniquement les espaces à la fin.

### Padding

#### `char* str_pad_left(const char* str, size_t total_length, char pad_char)`
Ajoute des caractères de remplissage à gauche jusqu'à `total_length`.

#### `char* str_pad_right(const char* str, size_t total_length, char pad_char)`
Ajoute des caractères de remplissage à droite jusqu'à `total_length`.

#### `char* str_pad(const char* str, size_t total_length, char pad_char, int pad_left)`
Remplissage flexible : `pad_left` != 0 pour gauche, 0 pour droite.

### Casse

#### `char* str_toLower(const char* str)` / `str_toLower_inplace(char* str)`
Convertit en minuscules.

#### `char* str_toUpper(const char* str)` / `str_toUpper_inplace(char* str)`
Convertit en majuscules.

#### `char* str_titleCase(const char* str)` / `str_titleCase_inplace(char* str)`
Convertit en "Title Case" (première lettre de chaque mot en majuscule).

### Autres

#### `char* str_reverse_inplace(char* str)`
Inverse une chaîne de caractères.

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

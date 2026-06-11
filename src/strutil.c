#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdint.h>

#include "../include/strutil.h"

char* str_trim(const char* str) {
    if (str == NULL) return NULL;

    const char* start = str;
    while (*start && isspace((unsigned char)*start)) {
        start++;
    }

    if (*start == '\0') {
        char* empty = malloc(1);
        if (empty) *empty = '\0';
        return empty;
    }

    const char* end = start + strlen(start) - 1;
    while (end > start && isspace((unsigned char)*end)) {
        end--;
    }

    size_t len = (size_t)(end - start + 1);

    char* new_str = malloc(len + 1);
    if (new_str == NULL) return NULL;

    memcpy(new_str, start, len);
    new_str[len] = '\0';

    return new_str;
}

char* str_trim_inplace(char* str) {
    if (str == NULL) return NULL;

    char* start = str;
    while (*start && isspace((unsigned char)*start)) {
        start++;
    }

    if (*start == '\0') {
        *str = '\0';
        return str;
    }

    char* end = start + strlen(start) - 1;
    while (end > start && isspace((unsigned char)*end)) {
        end--;
    }

    size_t len = (size_t)(end - start + 1);

    if (start != str) {
        memmove(str, start, len);
    }
    str[len] = '\0';

    return str;
}

char* str_left_trim(const char* str)
{
    if (str == NULL) return NULL;

    const char* start = str;
    while (*start && isspace((unsigned char)*start)) start++;

    // Remplacement de strdup par malloc + memcpy pour une portabilité C11 pure
    size_t len = strlen(start);
    char* str_cpy = malloc(len + 1);
    if (str_cpy == NULL) return NULL;

    memcpy(str_cpy, start, len + 1);
    return str_cpy;
}

char* str_left_trim_inplace(char* str)
{
    if (str == NULL) return NULL;

    char* start = str;
    while (*start && isspace((unsigned char)*start)) start++;

    if (start != str)
    {
        memmove(str, start, strlen(start) + 1);
    }
    return str;
}

char* str_right_trim(const char* str) {
    if (str == NULL) return NULL;

    size_t len_orig = strlen(str);

    if (len_orig == 0) {
        char* new_str_empty = malloc(1);
        if (new_str_empty) *new_str_empty = '\0';
        return new_str_empty;
    }

    const char* p_end = str + len_orig - 1;

    while (p_end >= str && isspace((unsigned char)*p_end)) {
        p_end--;
    }

    size_t final_len = (p_end < str) ? 0 : (size_t)(p_end - str + 1);

    char* new_str = malloc(final_len + 1);
    if (new_str == NULL) return NULL;

    memcpy(new_str, str, final_len);
    new_str[final_len] = '\0';
    return new_str;
}

char* str_right_trim_inplace(char* str) {
    if (str == NULL) return NULL;

    size_t len_orig = strlen(str);

    if (len_orig == 0) {
        return str;
    }

    char* p_end = str + len_orig - 1;

    while(p_end >= str && isspace((unsigned char)*p_end)) {
        p_end--;
    }

    size_t final_len = (p_end < str) ? 0 : (size_t)(p_end - str + 1);
    str[final_len] = '\0';
    return str;
}

char* str_pad(const char* str, size_t total_length, char pad_char, int pad_left) {
    if (str == NULL) return NULL;

    size_t str_len = strlen(str);
    if (total_length <= str_len) return NULL;

    char* new_str = malloc(total_length + 1);
    if (new_str == NULL) return NULL;

    size_t pad_count = total_length - str_len;

    if (pad_left) {
        memset(new_str, pad_char, pad_count);
        memcpy(new_str + pad_count, str, str_len + 1);
    } else {
        memcpy(new_str, str, str_len);
        memset(new_str + str_len, pad_char, pad_count);
        new_str[total_length] = '\0';
    }
    return new_str;
}

char* str_pad_inplace(char* str, size_t total_length, char pad_char, int pad_left) {
    if (str == NULL) return NULL;

    size_t str_len = strlen(str);
    if (str_len >= total_length) return NULL;

    size_t pad_count = total_length - str_len;

    if (pad_left) {
        memmove(str + pad_count, str, str_len + 1);
        memset(str, pad_char, pad_count);
    } else {
        memset(str + str_len, pad_char, pad_count);
        str[total_length] = '\0';
    }
    return str;
}

char* str_pad_left(const char* str, size_t total_length, char pad_char) {
    return str_pad(str, total_length, pad_char, 1);
}

char* str_pad_left_inplace(char* str, size_t total_length, char pad_char) {
    return str_pad_inplace(str, total_length, pad_char, 1);
}

char* str_pad_right(const char* str, size_t total_length, char pad_char) {
    return str_pad(str, total_length, pad_char, 0);
}

char* str_pad_right_inplace(char* str, size_t total_length, char pad_char) {
    return str_pad_inplace(str, total_length, pad_char, 0);
}

char* str_toLower(const char* str) {
    if (str == NULL) return NULL;

    size_t len = strlen(str);
    char* new_str = malloc(len + 1);
    if (new_str == NULL) return NULL;

    for(size_t i = 0; i < len; i++) {
        new_str[i] = (char)tolower((unsigned char)str[i]);
    }
    new_str[len] = '\0';

    return new_str;
}

char* str_toLower_inplace(char* str) {
    if (str == NULL) return NULL;

    for (char* p = str; *p; p++) {
        *p = (char)tolower((unsigned char)*p);
    }
    return str;
}

char* str_toUpper(const char* str) {
    if (str == NULL) return NULL;

    size_t len = strlen(str);
    char* new_str = malloc(len + 1);
    if (new_str == NULL) return NULL;

    for(size_t i = 0; i < len; i++) {
        new_str[i] = (char)toupper((unsigned char)str[i]);
    }
    new_str[len] = '\0';

    return new_str;
}

char* str_toUpper_inplace(char* str) {
    if (str == NULL) return NULL;

    for (char* p = str; *p; p++) {
        *p = (char)toupper((unsigned char)*p);
    }
    return str;
}

char* str_titleCase(const char* str) {
    if (str == NULL) return NULL;

    size_t len = strlen(str);
    char* new_str = malloc(len + 1);
    if (new_str == NULL) return NULL;

    int new_word = 1;
    for (size_t i = 0; i < len; i++) {
        unsigned char c = (unsigned char)str[i];
        if (isspace(c)) {
            new_str[i] = (char)c;
            new_word = 1;
        } else {
            if (new_word) {
                new_str[i] = (char)toupper(c);
                new_word = 0;
            } else {
                new_str[i] = (char)tolower(c);
            }
        }
    }
    new_str[len] = '\0';

    return new_str;
}

char* str_titleCase_inplace(char* str) {
    if (str == NULL) return NULL;

    int new_word = 1;
    for (char* p = str; *p; p++) {
        unsigned char c = (unsigned char)*p;
        if (isspace(c)) {
            new_word = 1;
        } else {
            if (new_word) {
                *p = (char)toupper(c);
                new_word = 0;
            } else {
                *p = (char)tolower(c);
            }
        }
    }

    return str;
}

char* str_reverse(const char* str) {
    if (str == NULL) return NULL;
    
    size_t len = strlen(str);
    char* new_str = malloc(len + 1);
    if (new_str == NULL) return NULL;
    
    for (size_t i = 0; i < len; i++) {
        new_str[i] = str[len - 1 - i];
    }
    new_str[len] = '\0';
    return new_str;
}

char* str_reverse_inplace(char* str)
{
    if (str == NULL) return NULL;

    size_t len = strlen(str);
    for (size_t i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
    return str;
}

int str_startsWith(const char* str, const char* prefix) {
    if (str == NULL || prefix == NULL) return 0;
    
    size_t str_len = strlen(str);
    size_t prefix_len = strlen(prefix);
    
    if (prefix_len > str_len) return 0;
    
    return strncmp(str, prefix, prefix_len) == 0 ? 1 : 0;
}

int str_endsWith(const char* str, const char* suffix) {
    if (str == NULL || suffix == NULL) return 0;
    
    size_t str_len = strlen(str);
    size_t suffix_len = strlen(suffix);
    
    if (suffix_len > str_len) return 0;
    
    return strncmp(str + str_len - suffix_len, suffix, suffix_len) == 0 ? 1 : 0;
}

int str_contains(const char* str, const char* substring) {
    if (str == NULL || substring == NULL) return 0;
    
    return strstr(str, substring) != NULL ? 1 : 0;
}

int str_isNumeric(const char* str) {
    if (str == NULL || *str == '\0') return 0;
    
    for (const char* p = str; *p; p++) {
        if (!isdigit((unsigned char)*p)) {
            return 0;
        }
    }
    return 1;
}

int str_isAlpha(const char* str) {
    if (str == NULL || *str == '\0') return 0;
    
    for (const char* p = str; *p; p++) {
        if (!isalpha((unsigned char)*p)) {
            return 0;
        }
    }
    return 1;
}

int str_isEmptyOrWhitespace(const char* str) {
    if (str == NULL || *str == '\0') return 1;
    
    for (const char* p = str; *p; p++) {
        if (!isspace((unsigned char)*p)) {
            return 0;
        }
    }
    return 1;
}

char* str_substring(const char* str, size_t start, size_t end) {
    if (str == NULL) return NULL;

    size_t full_len = strlen(str);

    if (start >= full_len) {
        char* empty = malloc(1);
        if (empty) *empty = '\0';
        return empty;
    }

    // Si end est invalide ou <= start, on va jusqu'à la fin (selon la spec)
    if (end <= start || end > full_len) {
        end = full_len;
    }

    size_t sub_len = end - start;
    char* new_str = malloc(sub_len + 1);
    if (new_str == NULL) return NULL;

    memcpy(new_str, str + start, sub_len);
    new_str[sub_len] = '\0';

    return new_str;
}

char* str_repeat(const char* str, size_t count) {
    if (str == NULL) return NULL;

    size_t str_len = strlen(str);
    if (count > 0 && str_len > SIZE_MAX / count) return NULL;
    size_t total_len = str_len * count;

    char* new_str = malloc(total_len + 1);
    if (new_str == NULL) return NULL;

    char* p = new_str;
    for (size_t i = 0; i < count; i++) {
        memcpy(p, str, str_len);
        p += str_len;
    }
    *p = '\0';

    return new_str;
}

char* str_replace(const char* str, const char* target, const char* replacement) {
    if (str == NULL || target == NULL || replacement == NULL) return NULL;

    size_t str_len = strlen(str);
    size_t target_len = strlen(target);
    size_t replacement_len = strlen(replacement);

    if (target_len == 0) {
        char* new_str = malloc(str_len + 1);
        if (new_str == NULL) return NULL;
        memcpy(new_str, str, str_len + 1);
        return new_str;
    }

    // Compter les occurrences de target
    size_t count = 0;
    const char* p = str;
    while ((p = strstr(p, target)) != NULL) {
        count++;
        p += target_len;
    }

    size_t new_len;
    if (replacement_len >= target_len) {
        size_t growth = replacement_len - target_len;
        if (growth > 0 && count > (SIZE_MAX - str_len) / growth) return NULL;
        new_len = str_len + count * growth;
    } else {
        size_t shrink = target_len - replacement_len;
        new_len = str_len - count * shrink;
    }
    char* new_str = malloc(new_len + 1);
    if (new_str == NULL) return NULL;

    char* dest = new_str;
    const char* src = str;
    while ((p = strstr(src, target)) != NULL) {
        size_t bytes_to_copy = (size_t)(p - src);
        memcpy(dest, src, bytes_to_copy);
        dest += bytes_to_copy;

        memcpy(dest, replacement, replacement_len);
        dest += replacement_len;

        src = p + target_len;
    }
    // Copier le reste de la chaîne
    strcpy(dest, src);

    return new_str;
}

char** str_split(const char* str, char delimiter, size_t* out_count) {
    if (str == NULL || out_count == NULL) return NULL;

    size_t count = 0;
    const char* p = str;
    while (*p) {
        if (*p == delimiter) {
            count++;
        }
        p++;
    }
    count++; // Pour le dernier segment

    char** result = malloc(count * sizeof(char*));
    if (result == NULL) return NULL;

    size_t index = 0;
    const char* start = str;
    p = str;
    while (*p) {
        if (*p == delimiter) {
            size_t len = (size_t)(p - start);
            result[index] = malloc(len + 1);
            if (result[index] == NULL) {
                for (size_t i = 0; i < index; i++) {
                    free(result[i]);
                }
                free(result);
                return NULL;
            }
            memcpy(result[index], start, len);
            result[index][len] = '\0';
            index++;
            start = p + 1;
        }
        p++;
    }
    // Dernier segment
    size_t len = (size_t)(p - start);
    result[index] = malloc(len + 1);
    if (result[index] == NULL) {
        for (size_t i = 0; i < index; i++) {
            free(result[i]);
        }
        free(result);
        return NULL;
    }
    memcpy(result[index], start, len);
    result[index][len] = '\0';

    *out_count = count;
    return result;
}

char* str_join(const char** strings, size_t count, const char* separator) {
    if (strings == NULL || separator == NULL) return NULL;

    size_t total_len = 0;
    size_t sep_len = strlen(separator);

    for (size_t i = 0; i < count; i++) {
        if (strings[i] == NULL) {
            total_len += 0;
        } else {
            total_len += strlen(strings[i]);
        }
        if (i < count - 1) {
            total_len += sep_len;
        }
    }

    char* new_str = malloc(total_len + 1);
    if (new_str == NULL) return NULL;

    char* dest = new_str;
    for (size_t i = 0; i < count; i++) {
        const char* s = strings[i] ? strings[i] : "";
        size_t len = strlen(s);
        memcpy(dest, s, len);
        dest += len;

        if (i < count - 1) {
            memcpy(dest, separator, sep_len);
            dest += sep_len;
        }
    }
    *dest = '\0';

    return new_str;
}
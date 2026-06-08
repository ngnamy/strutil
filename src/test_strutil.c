#include "../include/test_strutil.h"
#include "../include/strutil.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

// Macros pour simplifier l'affichage des tests
#define TEST_START(name) printf("Testing %s... ", name)
#define TEST_END() printf("✅ PASSED\n")

void test_str_trim() {
    TEST_START("str_trim");

    char* r1 = str_trim("  hello  ");
    assert(strcmp(r1, "hello") == 0);
    free(r1);

    char* r2 = str_trim("   ");
    assert(strcmp(r2, "") == 0);
    free(r2);

    char* r3 = str_trim(NULL);
    assert(r3 == NULL);

    TEST_END();
}

void test_str_trim_inplace() {
    TEST_START("str_trim_inplace");

    char s1[] = "  world  ";
    assert(strcmp(str_trim_inplace(s1), "world") == 0);

    char s2[] = "   ";
    assert(strcmp(str_trim_inplace(s2), "") == 0);

    TEST_END();
}

void test_str_left_trim() {
    TEST_START("str_left_trim");
    char* r1 = str_left_trim("  hello  ");
    assert(strcmp(r1, "hello  ") == 0);
    free(r1);
    TEST_END();
}

void test_str_left_trim_inplace() {
    TEST_START("str_left_trim_inplace");
    char s1[] = "  world  ";
    assert(strcmp(str_left_trim_inplace(s1), "world  ") == 0);
    TEST_END();
}

void test_str_right_trim() {
    TEST_START("str_right_trim");
    char* r1 = str_right_trim("  hello  ");
    assert(strcmp(r1, "  hello") == 0);
    free(r1);
    TEST_END();
}

void test_str_case() {
    TEST_START("str_toUpper/toLower");

    char* up = str_toUpper("Hello World");
    assert(strcmp(up, "HELLO WORLD") == 0);
    free(up);

    char* lo = str_toLower("Hello World");
    assert(strcmp(lo, "hello world") == 0);
    free(lo);

    char tc[] = "hello world";
    str_titleCase_inplace(tc);
    assert(strcmp(tc, "Hello World") == 0);

    TEST_END();
}

void test_str_pad() {
    TEST_START("str_pad");

    char* p1 = str_pad_left("test", 10, '*');
    assert(strcmp(p1, "******test") == 0);
    free(p1);

    char* p2 = str_pad_right("test", 10, '-');
    assert(strcmp(p2, "test------") == 0);
    free(p2);

    TEST_END();
}

void test_str_reverse() {
    TEST_START("str_reverse_inplace");
    char s1[] = "abcde";
    str_reverse_inplace(s1);
    assert(strcmp(s1, "edcba") == 0);
    TEST_END();
}

int run_all_tests() {
    printf("--- ⚙️ RUNNING ALL TESTS ---\n");
    test_str_trim();
    test_str_trim_inplace();
    test_str_left_trim();
    test_str_left_trim_inplace();
    test_str_right_trim();
    test_str_case();
    test_str_pad();
    test_str_reverse();
    printf("--- ✅ ALL TESTS PASSED SUCCESSFULLY ---\n");
    return 0;
}

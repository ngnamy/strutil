#include "../include/test_strutil.h"
#include "../include/strutil.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h> // Pour free

// Macros pour simplifier l'affichage des tests
#define TEST_START(name) printf("Testing %s... ", name)
#define TEST_END() printf("✅ PASSED\n")
#define ASSERT_STR_EQ(expected, actual) assert(strcmp(expected, actual) == 0)
#define ASSERT_NULL(ptr) assert(ptr == NULL)
#define ASSERT_INT_EQ(expected, actual) assert((expected) == (actual))

void test_str_trim() {
    TEST_START("str_trim");

    char* r1 = str_trim("  hello  ");
    ASSERT_STR_EQ("hello", r1);
    free(r1);

    char* r2 = str_trim("   ");
    ASSERT_STR_EQ("", r2);
    free(r2);

    char* r3 = str_trim(NULL);
    ASSERT_NULL(r3);

    char* r4 = str_trim("hello");
    ASSERT_STR_EQ("hello", r4);
    free(r4);

    char* r5 = str_trim("");
    ASSERT_STR_EQ("", r5);
    free(r5);

    TEST_END();
}

void test_str_trim_inplace() {
    TEST_START("str_trim_inplace");

    char s1[] = "  world  ";
    ASSERT_STR_EQ("world", str_trim_inplace(s1));

    char s2[] = "   ";
    ASSERT_STR_EQ("", str_trim_inplace(s2));

    char s3[] = "hello";
    ASSERT_STR_EQ("hello", str_trim_inplace(s3));

    char s4[] = "";
    ASSERT_STR_EQ("", str_trim_inplace(s4));

    ASSERT_NULL(str_trim_inplace(NULL));

    TEST_END();
}

void test_str_left_trim() {
    TEST_START("str_left_trim");
    char* r1 = str_left_trim("  hello  ");
    ASSERT_STR_EQ("hello  ", r1);
    free(r1);

    char* r2 = str_left_trim("   ");
    ASSERT_STR_EQ("", r2);
    free(r2);

    ASSERT_NULL(str_left_trim(NULL));

    char* r3 = str_left_trim("hello");
    ASSERT_STR_EQ("hello", r3);
    free(r3);

    TEST_END();
}

void test_str_left_trim_inplace() {
    TEST_START("str_left_trim_inplace");
    char s1[] = "  world  ";
    ASSERT_STR_EQ("world  ", str_left_trim_inplace(s1));

    char s2[] = "   ";
    ASSERT_STR_EQ("", str_left_trim_inplace(s2));

    char s3[] = "hello";
    ASSERT_STR_EQ("hello", str_left_trim_inplace(s3));

    ASSERT_NULL(str_left_trim_inplace(NULL));

    TEST_END();
}

void test_str_right_trim() {
    TEST_START("str_right_trim");
    char* r1 = str_right_trim("  hello  ");
    ASSERT_STR_EQ("  hello", r1);
    free(r1);

    char* r2 = str_right_trim("   ");
    ASSERT_STR_EQ("", r2);
    free(r2);

    ASSERT_NULL(str_right_trim(NULL));

    char* r3 = str_right_trim("hello");
    ASSERT_STR_EQ("hello", r3);
    free(r3);

    TEST_END();
}

void test_str_right_trim_inplace() {
    TEST_START("str_right_trim_inplace");
    char s1[] = "  hello  ";
    ASSERT_STR_EQ("  hello", str_right_trim_inplace(s1));

    char s2[] = "   ";
    ASSERT_STR_EQ("", str_right_trim_inplace(s2));

    char s3[] = "hello";
    ASSERT_STR_EQ("hello", str_right_trim_inplace(s3));

    ASSERT_NULL(str_right_trim_inplace(NULL));

    TEST_END();
}

void test_str_case() {
    TEST_START("str_toUpper/toLower/titleCase");

    char* up = str_toUpper("Hello World");
    ASSERT_STR_EQ("HELLO WORLD", up);
    free(up);

    char* lo = str_toLower("Hello World");
    ASSERT_STR_EQ("hello world", lo);
    free(lo);

    char tc_in[] = "hello world";
    ASSERT_STR_EQ("Hello World", str_titleCase_inplace(tc_in));

    char* tc_out = str_titleCase("hello world");
    ASSERT_STR_EQ("Hello World", tc_out);
    free(tc_out);

    char up_in[] = "Hello World";
    ASSERT_STR_EQ("HELLO WORLD", str_toUpper_inplace(up_in));

    char lo_in[] = "Hello World";
    ASSERT_STR_EQ("hello world", str_toLower_inplace(lo_in));

    TEST_END();
}

void test_str_pad() {
    TEST_START("str_pad");

    // str_pad_left
    char* p1 = str_pad_left("test", 10, '*');
    ASSERT_STR_EQ("******test", p1);
    free(p1);
    ASSERT_NULL(str_pad_left("test", 3, '*')); // total_length <= str_len
    ASSERT_NULL(str_pad_left(NULL, 10, '*'));

    // str_pad_right
    char* p2 = str_pad_right("test", 10, '-');
    ASSERT_STR_EQ("test------", p2);
    free(p2);
    ASSERT_NULL(str_pad_right("test", 3, '-')); // total_length <= str_len
    ASSERT_NULL(str_pad_right(NULL, 10, '-'));

    // str_pad_left_inplace (requires buffer to be large enough)
    char p3_in[11] = "test"; // "test\0" + 6 chars = 11
    ASSERT_STR_EQ("******test", str_pad_left_inplace(p3_in, 10, '*'));
    ASSERT_NULL(str_pad_left_inplace(p3_in, 3, '*')); // str_len >= total_length
    ASSERT_NULL(str_pad_left_inplace(NULL, 10, '*'));

    // str_pad_right_inplace (requires buffer to be large enough)
    char p4_in[11] = "test"; // "test\0" + 6 chars = 11
    ASSERT_STR_EQ("test------", str_pad_right_inplace(p4_in, 10, '-'));
    ASSERT_NULL(str_pad_right_inplace(p4_in, 3, '-')); // str_len >= total_length
    ASSERT_NULL(str_pad_right_inplace(NULL, 10, '-'));

    // str_pad (general)
    char* p5 = str_pad("abc", 7, '#', 1); // pad_left = true
    ASSERT_STR_EQ("####abc", p5);
    free(p5);

    char* p6 = str_pad("abc", 7, '#', 0); // pad_left = false
    ASSERT_STR_EQ("abc####", p6);
    free(p6);
    ASSERT_NULL(str_pad("abc", 2, '#', 1)); // total_length <= str_len
    ASSERT_NULL(str_pad(NULL, 7, '#', 1));

    // str_pad_inplace (general)
    char p7_in[10] = "abc"; // Buffer large enough
    ASSERT_STR_EQ("####abc", str_pad_inplace(p7_in, 7, '#', 1));

    char p8_in[10] = "abc"; // Buffer large enough
    ASSERT_STR_EQ("abc####", str_pad_inplace(p8_in, 7, '#', 0));
    ASSERT_NULL(str_pad_inplace(p7_in, 2, '#', 1)); // str_len >= total_length
    ASSERT_NULL(str_pad_inplace(NULL, 7, '#', 1));

    TEST_END();
}

void test_str_reverse() {
    TEST_START("str_reverse");
    char* r1 = str_reverse("hello");
    ASSERT_STR_EQ("olleh", r1);
    free(r1);

    char* r2 = str_reverse("world");
    ASSERT_STR_EQ("dlrow", r2);
    free(r2);

    char* r3 = str_reverse("");
    ASSERT_STR_EQ("", r3);
    free(r3);

    ASSERT_NULL(str_reverse(NULL));

    char* r4 = str_reverse("a");
    ASSERT_STR_EQ("a", r4);
    free(r4);

    char* r5 = str_reverse("ab");
    ASSERT_STR_EQ("ba", r5);
    free(r5);

    TEST_END();
}

void test_str_reverse_inplace() {
    TEST_START("str_reverse_inplace");
    char s1[] = "hello";
    ASSERT_STR_EQ("olleh", str_reverse_inplace(s1));

    char s2[] = "world";
    ASSERT_STR_EQ("dlrow", str_reverse_inplace(s2));

    char s3[] = "";
    ASSERT_STR_EQ("", str_reverse_inplace(s3));

    ASSERT_NULL(str_reverse_inplace(NULL));

    char s4[] = "a";
    ASSERT_STR_EQ("a", str_reverse_inplace(s4));

    char s5[] = "ab";
    ASSERT_STR_EQ("ba", str_reverse_inplace(s5));

    TEST_END();
}

void test_str_startsWith() {
    TEST_START("str_startsWith");

    ASSERT_INT_EQ(1, str_startsWith("hello world", "hello"));
    ASSERT_INT_EQ(1, str_startsWith("hello", "h"));
    ASSERT_INT_EQ(1, str_startsWith("hello", "hello"));
    ASSERT_INT_EQ(1, str_startsWith("hello", ""));
    ASSERT_INT_EQ(1, str_startsWith("", ""));
    
    ASSERT_INT_EQ(0, str_startsWith("hello", "world"));
    ASSERT_INT_EQ(0, str_startsWith("hello", "H")); // Sensible à la casse
    ASSERT_INT_EQ(0, str_startsWith("h", "hello"));
    ASSERT_INT_EQ(0, str_startsWith(NULL, "h"));
    ASSERT_INT_EQ(0, str_startsWith("h", NULL));

    TEST_END();
}

void test_str_endsWith() {
    TEST_START("str_endsWith");

    ASSERT_INT_EQ(1, str_endsWith("hello world", "world"));
    ASSERT_INT_EQ(1, str_endsWith("hello", "o"));
    ASSERT_INT_EQ(1, str_endsWith("hello", "hello"));
    ASSERT_INT_EQ(1, str_endsWith("hello", ""));
    ASSERT_INT_EQ(1, str_endsWith("", ""));

    ASSERT_INT_EQ(0, str_endsWith("hello", "hello world"));
    ASSERT_INT_EQ(0, str_endsWith("hello", "he"));
    ASSERT_INT_EQ(0, str_endsWith(NULL, "o"));
    ASSERT_INT_EQ(0, str_endsWith("o", NULL));

    TEST_END();
}

void test_str_contains() {
    TEST_START("str_contains");

    ASSERT_INT_EQ(1, str_contains("hello world", "world"));
    ASSERT_INT_EQ(1, str_contains("hello world", "hello"));
    ASSERT_INT_EQ(1, str_contains("hello world", "lo w"));
    ASSERT_INT_EQ(1, str_contains("hello", ""));

    ASSERT_INT_EQ(0, str_contains("hello", "xyz"));
    ASSERT_INT_EQ(0, str_contains("hello", "HELLO")); // Sensible à la casse
    ASSERT_INT_EQ(0, str_contains(NULL, "a"));
    ASSERT_INT_EQ(0, str_contains("a", NULL));

    TEST_END();
}

void test_str_isNumeric() {
    TEST_START("str_isNumeric");
    ASSERT_INT_EQ(1, str_isNumeric("1234567890"));
    ASSERT_INT_EQ(0, str_isNumeric(""));
    ASSERT_INT_EQ(0, str_isNumeric("123a45"));
    ASSERT_INT_EQ(0, str_isNumeric(" "));
    ASSERT_INT_EQ(0, str_isNumeric(NULL));
    TEST_END();
}

void test_str_isAlpha() {
    TEST_START("str_isAlpha");
    ASSERT_INT_EQ(1, str_isAlpha("Alphabet"));
    ASSERT_INT_EQ(0, str_isAlpha(""));
    ASSERT_INT_EQ(0, str_isAlpha("Alpha1"));
    ASSERT_INT_EQ(0, str_isAlpha("Alpha Beta"));
    ASSERT_INT_EQ(0, str_isAlpha(NULL));
    TEST_END();
}

void test_str_isEmptyOrWhitespace() {
    TEST_START("str_isEmptyOrWhitespace");
    ASSERT_INT_EQ(1, str_isEmptyOrWhitespace(""));
    ASSERT_INT_EQ(1, str_isEmptyOrWhitespace("   "));
    ASSERT_INT_EQ(1, str_isEmptyOrWhitespace("\n\t \r"));
    ASSERT_INT_EQ(1, str_isEmptyOrWhitespace(NULL));
    ASSERT_INT_EQ(0, str_isEmptyOrWhitespace("  content  "));
    TEST_END();
}

void test_str_substring() {
    TEST_START("str_substring");

    char* r1 = str_substring("hello world", 0, 5);
    ASSERT_STR_EQ("hello", r1);
    free(r1);

    char* r2 = str_substring("hello world", 6, 11);
    ASSERT_STR_EQ("world", r2);
    free(r2);

    // end <= start → extract to end of string
    char* r3 = str_substring("hello world", 6, 0);
    ASSERT_STR_EQ("world", r3);
    free(r3);

    // start >= length → empty string
    char* r4 = str_substring("hello", 10, 15);
    ASSERT_STR_EQ("", r4);
    free(r4);

    // Empty string
    char* r5 = str_substring("", 0, 0);
    ASSERT_STR_EQ("", r5);
    free(r5);

    ASSERT_NULL(str_substring(NULL, 0, 5));

    TEST_END();
}

void test_str_repeat() {
    TEST_START("str_repeat");

    char* r1 = str_repeat("abc", 3);
    ASSERT_STR_EQ("abcabcabc", r1);
    free(r1);

    char* r2 = str_repeat("x", 5);
    ASSERT_STR_EQ("xxxxx", r2);
    free(r2);

    char* r3 = str_repeat("abc", 0);
    ASSERT_STR_EQ("", r3);
    free(r3);

    char* r4 = str_repeat("abc", 1);
    ASSERT_STR_EQ("abc", r4);
    free(r4);

    char* r5 = str_repeat("", 5);
    ASSERT_STR_EQ("", r5);
    free(r5);

    ASSERT_NULL(str_repeat(NULL, 3));

    TEST_END();
}

void test_str_replace() {
    TEST_START("str_replace");

    char* r1 = str_replace("hello world", "world", "there");
    ASSERT_STR_EQ("hello there", r1);
    free(r1);

    char* r2 = str_replace("abcabc", "abc", "x");
    ASSERT_STR_EQ("xx", r2);
    free(r2);

    char* r3 = str_replace("hello", "xyz", "abc");
    ASSERT_STR_EQ("hello", r3);
    free(r3);

    // Replace with longer string
    char* r4 = str_replace("aaa", "a", "bb");
    ASSERT_STR_EQ("bbbbbb", r4);
    free(r4);

    // Replace with empty string (deletion)
    char* r5 = str_replace("hello world", " ", "");
    ASSERT_STR_EQ("helloworld", r5);
    free(r5);

    // Empty target → returns copy
    char* r6 = str_replace("hello", "", "x");
    ASSERT_STR_EQ("hello", r6);
    free(r6);

    ASSERT_NULL(str_replace(NULL, "a", "b"));
    ASSERT_NULL(str_replace("hello", NULL, "b"));
    ASSERT_NULL(str_replace("hello", "a", NULL));

    TEST_END();
}

void test_str_split() {
    TEST_START("str_split");

    size_t count = 0;
    char** r1 = str_split("apple,banana,cherry", ',', &count);
    ASSERT_INT_EQ(3, (int)count);
    ASSERT_STR_EQ("apple", r1[0]);
    ASSERT_STR_EQ("banana", r1[1]);
    ASSERT_STR_EQ("cherry", r1[2]);
    for (size_t i = 0; i < count; i++) free(r1[i]);
    free(r1);

    // Single element (no delimiter)
    char** r2 = str_split("hello", ',', &count);
    ASSERT_INT_EQ(1, (int)count);
    ASSERT_STR_EQ("hello", r2[0]);
    free(r2[0]);
    free(r2);

    // Empty segments
    char** r3 = str_split(",a,,b,", ',', &count);
    ASSERT_INT_EQ(5, (int)count);
    ASSERT_STR_EQ("", r3[0]);
    ASSERT_STR_EQ("a", r3[1]);
    ASSERT_STR_EQ("", r3[2]);
    ASSERT_STR_EQ("b", r3[3]);
    ASSERT_STR_EQ("", r3[4]);
    for (size_t i = 0; i < count; i++) free(r3[i]);
    free(r3);

    // Empty string
    char** r4 = str_split("", ',', &count);
    ASSERT_INT_EQ(1, (int)count);
    ASSERT_STR_EQ("", r4[0]);
    free(r4[0]);
    free(r4);

    ASSERT_NULL(str_split(NULL, ',', &count));
    ASSERT_NULL(str_split("hello", ',', NULL));

    TEST_END();
}

void test_str_join() {
    TEST_START("str_join");

    const char* arr1[] = {"apple", "banana", "cherry"};
    char* r1 = str_join(arr1, 3, ", ");
    ASSERT_STR_EQ("apple, banana, cherry", r1);
    free(r1);

    const char* arr2[] = {"hello"};
    char* r2 = str_join(arr2, 1, " ");
    ASSERT_STR_EQ("hello", r2);
    free(r2);

    const char* arr3[] = {"a", "b", "c"};
    char* r3 = str_join(arr3, 3, "");
    ASSERT_STR_EQ("abc", r3);
    free(r3);

    // NULL element handled gracefully
    const char* arr4[] = {"hello", NULL, "world"};
    char* r4 = str_join(arr4, 3, "-");
    ASSERT_STR_EQ("hello--world", r4);
    free(r4);

    ASSERT_NULL(str_join(NULL, 3, ", "));
    ASSERT_NULL(str_join(arr1, 3, NULL));

    TEST_END();
}

int run_all_tests() {
    printf("--- ⚙️ RUNNING ALL TESTS ---\n");
    test_str_trim();
    test_str_trim_inplace();
    test_str_left_trim();
    test_str_left_trim_inplace();
    test_str_right_trim();
    test_str_right_trim_inplace();
    test_str_case();
    test_str_pad();
    test_str_reverse();
    test_str_reverse_inplace();
    test_str_startsWith();
    test_str_endsWith();
    test_str_contains();
    test_str_isNumeric();
    test_str_isAlpha();
    test_str_isEmptyOrWhitespace();
    test_str_substring();
    test_str_repeat();
    test_str_replace();
    test_str_split();
    test_str_join();
    printf("--- ✅ ALL TESTS PASSED SUCCESSFULLY ---\n");
    return 0;
}

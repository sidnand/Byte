#ifndef TEST_READER_H
#define TEST_READER_H

#include "./../../libs/unity/unity.h"
#include "./../../include/io/reader.h"

void test_get_extension() {
    const char *filename_txt = "test.txt";
    const char *filename_no_extension = "test";
    const char *filename_empty = "";
    const char *filename_bad = "test..txt";

    const char *extension_txt = get_extension(filename_txt);
    const char *no_extension = get_extension(filename_no_extension);
    const char *extension_empty = get_extension(filename_empty);
    const char *extension_bad = get_extension(filename_bad);

    TEST_ASSERT_EQUAL_STRING("txt", extension_txt);
    TEST_ASSERT_EQUAL_STRING("", no_extension);
    TEST_ASSERT_EQUAL_STRING("", extension_empty);
    TEST_ASSERT_EQUAL_STRING("txt", extension_bad);
}

// void test_read_file() {
//     const char empty_txt = "empty.txt";
//     const char sentence_txt = "sentence.txt";
//     const char blank_txt = "";
    
//     const char *content_empty = read_file(empty_txt);
//     const char *content_sentence = read_file(sentence_txt);
//     const char *content_blank = read_file(blank_txt);
    

//     TEST_ASSERT_EQUAL_STRING("", content_empty);
//     TEST_ASSERT_EQUAL_STRING("This is some text inside of a div block.", content_sentence);
//     TEST_ASSERT_EQUAL_STRING("Error opening file\n", content_blank);
// }

void setUp() {}

void tearDown() {}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_get_extension);
    return UNITY_END();
}

#endif
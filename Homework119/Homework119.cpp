#define MAX_TEXT 1000
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
using namespace std;
//1
//int mystrlen(const char* str)
//{
//    int length = 0;
//    while (str[length] != '\0') 
//    {
//        length++;
//    }
//    return length;
//}
//
//char* mystrcpy(char* str1, const char* str2)
//{
//    char* start = str1;
//    while ((*str1++ = *str2++) != '\0');
//    return start;
//}
//
//char* mystrcat(char* str1, const char* str2) 
//{
//    char* start = str1;
//    while (*str1 != '\0') str1++;       
//    while ((*str1++ = *str2++) != '\0');
//    return start;
//}
//
//char* mystrchr(char* str, char s) 
//{
//    while (*str != '\0') 
//    {
//        if (*str == s)
//            return str;
//        str++;
//    }
//    return NULL;
//}
//
//char* mystrstr(const char* haystack, const char* needle)
//{
//    if (*needle == '\0') return (char*)haystack;
//
//    for (; *haystack != '\0'; haystack++) 
//    {
//        const char* h = haystack;
//        const char* n = needle;
//
//        while (*h && *n && *h == *n)
//        {
//            h++; n++;
//        }
//
//        if (*n == '\0')
//            return (char*)haystack;
//    }
//    return NULL;
//}
//int main() 
//{
//    char text1[100] = "Hello";
//    char text2[] = " World";
//
//    printf("Length: %d\n", mystrlen(text1));
//    mystrcpy(text1, "Hi");
//    printf("Copy: %s\n", text1);
//    mystrcat(text1, text2);
//    printf("Concat: %s\n", text1);
//
//    char* pos = mystrchr(text1, 'W');
//    if (pos)
//        printf("Found 'W' at position: %ld\n", pos - text1);
//    else
//        printf("'W' not found\n");
//
//    char* substr = mystrstr(text1, "World");
//    if (substr)
//        printf("Substring found: %s\n", substr);
//    else
//        printf("Substring not found\n");
//
//}

//2



void reverse(char* str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        char tmp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = tmp;
    }
}

int countWordOccurrences(const char* text, const char* word) 
{
    int count = 0;
    const char* p = text;
    int wordLen = strlen(word);

    while ((p = strstr(p, word)) != NULL) 
    {
        if ((p == text || !isalnum(*(p - 1))) && !isalnum(*(p + wordLen))) 
        {
            count++;
        }
        p += wordLen;
    }
    return count;
}

int countSentences(const char* text) 
{
    int count = 0;
    while (*text)
    {
        if (*text == '.' || *text == '!' || *text == '?') {
            count++;
        }
        text++;
    }
    return count;
}

void countDotsAndCommas(const char* text, int* dots, int* commas) 
{
    *dots = 0;
    *commas = 0;
    while (*text)
    {
        if (*text == '.') (*dots)++;
        if (*text == ',') (*commas)++;
        text++;
    }
}

void reverseEachSentence(const char* text) 
{
    char buffer[MAX_TEXT];
    strcpy(buffer, text);
    char* sentence = strtok(buffer, ".!?");

    while (sentence != NULL)
    {
        while (isspace(*sentence)) sentence++;
        char temp[MAX_TEXT];
        strcpy(temp, sentence);
        reverse(temp);
        printf("%s.\n", temp);
        sentence = strtok(NULL, ".!?");
    }
}

int main() {
    char text[MAX_TEXT] = "Hello, world. This is a test! How are you? This is a test.";
    char word[100];

    printf("Enter word to search: ");
    scanf("%s", word);
    int wordCount = countWordOccurrences(text, word);
    printf("Occurrences of '%s': %d\n", word, wordCount);

    int sentenceCount = countSentences(text);
    printf("Number of sentences: %d\n", sentenceCount);

    int dots, commas;
    countDotsAndCommas(text, &dots, &commas);
    printf("Dots: %d, Commas: %d\n", dots, commas);

    char reversed[MAX_TEXT];
    strcpy(reversed, text);
    reverse(reversed);
    printf("Reversed text: %s\n", reversed);
    printf("Each sentence reversed:\n");
    reverseEachSentence(text);

}

/*
Name : Nestin Gregorios Sunny

Date : 14.09.2025

Description :
Implement Inverted Search using Single Linked List and Hash Table

Functions Implemented :
    1. Create database from Files
    2. Display database
    3. Search word
    4. Save database to File
    5. Update database
*/

#include "inverted_search.h"


int search_word(H_Table *Hash, char *word)
{
    char clean_word[30];
    int i = 0, j =0;

    // Clean the input word
    while (word[i])
    {
        if (isalnum(word[i]))
        {
            clean_word[j++] = tolower(word[i]);
        }
        i++;
    }
    clean_word[j] = '\0';

    if (strlen(clean_word) == 0)
    {
        printf(RED "ERROR : Invalid word\n" RESET);
        return FAILURE;
    }

    int index = hash_function(clean_word);
    M_node *main = Hash[index].Hlink;

    while (main)
    {
        if (strcmp(main -> word, clean_word) == 0)
        {
            printf(GREEN "\nWord '%s' is present in %d file(s):\n", clean_word, main -> file_count); printf(RESET);
            S_node *sub = main -> m_sublink;
            while (sub)
            {
                printf(GREEN "In file : %s %d time(s)\n", sub -> s_filename, sub -> word_count); printf(RESET);
                sub = sub -> sublink;
            }
            return SUCCESS;
        }
        main = main -> mainlink;
    }
    return FAILURE;
}
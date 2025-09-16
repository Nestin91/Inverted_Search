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

int create_database(F_List **head, H_Table *Hash)
{
    F_List *file_node = *head;
    char  raw[100], clean[30];

    while (file_node)
    {
        FILE *fp = fopen(file_node -> filename, "r");
        if (fp == NULL)
        {
            printf(RED "ERROR : Error opening file : %s\n", file_node -> filename); printf(RESET);
            file_node = file_node -> Flink;
            continue;
        }

        while (fscanf(fp, "%s", raw) != EOF)
        {
            // Clean the word
            int i = 0, j = 0;
            while (raw[i])
            {
                if (isalnum(raw[i]))
                {
                    clean[j++] = tolower(raw[i]);
                }
                i++;
            }
            clean[j] = '\0';
            if (strlen(clean) == 0)
            {
                continue;
            }

            int index = hash_function(clean);
            M_node *main = Hash[index].Hlink;
            M_node *prev_main = NULL;

            // Search for word in main_node list
            while (main && strcmp(main -> word, clean) != 0)
            {
                prev_main = main;
                main = main -> mainlink;
            }
            
            if (!main)
            {
                // Word not found - create main_node and sub_node
                M_node *new_main = malloc(sizeof(M_node));
                strcpy(new_main -> word, clean);
                new_main -> file_count = 1;
                new_main -> mainlink = NULL;

                S_node *new_sub = malloc(sizeof(S_node));
                strcpy(new_sub -> s_filename, file_node -> filename);
                new_sub -> word_count = 1;
                new_sub -> sublink = NULL;

                new_main -> m_sublink = new_sub;

                if (prev_main)
                {
                    prev_main -> mainlink = new_main;
                }
                else
                {
                    Hash[index].Hlink = new_main;
                }
            }
            else
            {
                // Word exists - Check sub_node list
                S_node *sub = main -> m_sublink;
                S_node *prev_sub = NULL;

                while (sub && strcmp(sub -> s_filename, file_node -> filename) != 0)
                {
                    prev_sub = sub;
                    sub = sub -> sublink;
                }
                
                if ((!sub))
                {
                    // File not listed - create new sub_node
                    S_node *new_sub = malloc(sizeof(S_node));
                    strcpy(new_sub -> s_filename, file_node -> filename);
                    new_sub -> word_count = 1;
                    new_sub -> sublink = NULL;

                    prev_sub -> sublink = new_sub;
                    main -> file_count++;
                }
                else
                {
                    // File already listed - increment word_count
                    sub -> word_count++;
                }
            }            
        }
        
        fclose(fp);
        file_node = file_node -> Flink;
    }
    
    return SUCCESS;
}    

int hash_function(char *word) 
{
    if(!word || !word[0])
    {
        return 27; //Treat empty or malformed as punctuation
    }

    char ch = tolower(word[0]);
    if (isalpha(ch))
    {
        return ch - 'a';
    }
    else if (isdigit(ch))
    {
        return 26;
    }
    else
    {
        return 27;
    }
}

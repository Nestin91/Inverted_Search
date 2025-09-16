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

int save_database(H_Table *Hash, char *filename)
{
    if (!is_txt_file(filename))
    {
        printf(RED "ERROR : Output file must have a '.txt' extension\n" RESET);
        return FAILURE;
    }
    
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf(RED "ERROR : Unable to open '%s' for writing\n", filename); printf(RESET);
        return FAILURE;
    }
    for (int i = 0; i < 28; i++)
    {
        M_node *main = Hash[i]. Hlink;
        while (main)
        {
            fprintf(fp, "#%d;%s;%d;", i, main -> word, main -> file_count);

            S_node *sub = main -> m_sublink;
            while (sub)
            {
                fprintf(fp, "%s;%d;", sub -> s_filename, sub -> word_count);
                sub = sub -> sublink;
            }
            
            fprintf(fp, "#\n");
            main = main -> mainlink;
        }
    }
    
    fclose(fp);
    printf(GREEN "INFO : Database successfully saved to '%s'\n", filename); printf(RESET);
    return SUCCESS;
}

int is_txt_file(const char *filename) 
{
    const char *dot = strrchr(filename, '.');
    return (dot && strcmp(dot, ".txt") == 0);
}

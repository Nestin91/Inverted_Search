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

int display_database(H_Table *Hash)
{
    printf(CYAN "\nInverted Search Database\n\n" RESET);

    printf(PURPLE "Index\tWord\tFile_Count\tFilename\tWord_Count\n" RESET);
    
    int i;
    for (i = 0; i < 28; i++)
    {
        M_node *main = Hash[i].Hlink;
        while (main)
        {
            printf("%d\t%s\t%d", i, main-> word, main -> file_count);

            S_node *sub = main -> m_sublink;
            if (sub)
            {
                printf("\t\t%s\t\t%d\n", sub -> s_filename, sub -> word_count);
                sub = sub -> sublink;
            } 
            
            while (sub)
            {
                printf("\t\t");
                printf("\t\t%s\t\t%d\n", sub -> s_filename, sub -> word_count);
                sub = sub -> sublink;
            }
            
            main = main -> mainlink;
        }       
    }
    return SUCCESS;
}
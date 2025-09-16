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

int delete_file_from_list(char file_name[], F_List **head)
{
    if (*head == NULL)
    {
        return SUCCESS;
    }
    
    F_List *temp = *head;
    F_List *prev = NULL;
    
    // Traverse till it reaches NULL
    while (temp != NULL)
    {
        if ((strcmp(temp -> filename, file_name) == 0))
        {
            printf(GREEN "INFO : %s removed from list\n", file_name); printf(RESET);
            if (prev == NULL)
            {
                *head = temp -> Flink;
                free(temp);
                return 1;
            }
            else
            {
                prev -> Flink = temp -> Flink;
                free(temp);
                return 1;
            }
        }
        
        prev = temp;
        temp = temp -> Flink;
    }
    
    return 0;
}
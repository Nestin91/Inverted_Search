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

int insert_data_to_table(M_node *new, H_Table *Hash)
{
    int index = find_index(new -> word[0]);  // Get index

    if(Hash[index].Hlink == NULL)  // If particular index link is NULL
    {
        Hash[index].Hlink = new;
        return SUCCESS;
    }

    M_node *temp = Hash[index].Hlink;
    
    // Traverse till reaches last main node
    while(temp -> mainlink != NULL)  
    {
        temp = temp -> mainlink;
    }

    temp -> mainlink = new;
    return SUCCESS;
     
}

int find_index(char ch)
{
    if(ch >= 'a' && ch <= 'z')  // lower case
    {
        return ch - 'a';
    }
    else if(ch >= 'A' && ch <= 'Z')  // Upper case
    {
        return ch - 'A';
    }
    else if(ch >= '0' && ch <= '9')  // Digits
    {
        return 26;
    }
    else  // Puncuations
    {
        return 27;
    }
}
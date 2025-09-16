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

int update_database(F_List **head, H_Table *Hash)
{
    char filename[30];
    FILE *fp;

    while (1)
    {
        printf(PURPLE "Enter the backup filename : " RESET);
        scanf(" %s", filename);

        char *ptr = strstr(filename, ".txt");
        if (ptr != NULL && strcmp(ptr, ".txt") == 0)
        {
            fp = fopen(filename, "r");
            if (fp != NULL)
            {
                char first_char = fgetc(fp);
                if (first_char == EOF)
                {
                    printf(RED "INFO : File is empty\n\n" RESET);
                    fclose(fp);
                    continue;
                }
                
                fseek(fp, -2, SEEK_END);
                char last_char = fgetc(fp);

                if (first_char == '#' && last_char == '#')
                {
                    printf(GREEN "INFO : Validation successful\n" RESET);
                    break;
                }
                else
                {
                    printf(RED "ERROR : Invalid backup file format\n" RESET);

                }
                fclose(fp);
            }
            else
            {
                printf(RED "ERROR : File is not in the current directory\n\n" RESET);
            }
        
        }
        else
        {
            printf(RED "ERROR : File name must end with .txt\n\n" RESET);
        }
    }

    rewind(fp);
    int index, file_count, word_count;
    char word[30], file_name[30];

    S_node *sub;
    while (fscanf(fp, "#%d;%[^;];%d;", &index, word, &file_count) == 3)
    {
        M_node *new_main = create_main_node(word);
        new_main -> file_count = file_count;

        for (int i = 0; i < file_count; i++)
        {
            fscanf(fp, "%[^;];%d;", file_name, &word_count);

            S_node *new_sub = create_sub_node(file_name);
            new_sub -> word_count = word_count;

            delete_file_from_list (file_name, head);

            if (new_main -> m_sublink == NULL)
            {
                new_main -> m_sublink = new_sub;
            }
            else
            {
                sub -> sublink = new_sub;
            }
            sub = new_sub;
        }
        fscanf(fp, "#\n");
        insert_data_to_table(new_main, Hash);
    }
    
    create_database (head, Hash);
    return SUCCESS;
}

M_node *create_main_node(char word[])
{
    // Create a new Node
    M_node *new = malloc(sizeof(M_node));

    // Validate
    if(new == NULL)
    {
        return NULL;
    }

    // Update
    strcpy(new -> word, word);
    new -> file_count = 1;
    new -> m_sublink = NULL;
    new-> mainlink = NULL;

    return new;
}

S_node *create_sub_node(char file_name[])
{
    // Create a new Node
    S_node *new = malloc(sizeof(S_node));

    // Validate
    if(new == NULL)
    {
        return NULL;
    }

    // Update
    strcpy(new -> s_filename, file_name);
    new -> word_count = 1;
    new -> sublink = NULL;
    return new;
}

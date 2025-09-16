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
#include "colors.h"

int read_and_validate_args(int argc, char **argv, F_List **head)
{
    int i;
    if (argc < 2)
    {
        printf(RED "ERROR : Not enough arguments, provide atleast one file\n" RESET);
        printf(YELLOW "INFO: Usage ./inverted_index <file.txt> <file1.txt> ...\n" RESET);
        return FAILURE;
    }
    for ( i = 1; i < argc; i++)
    {
        char *filename = argv[i];

        // Check if extension exists
        if (strrchr(filename, '.') ==  NULL)
        {
            printf(RED "INFO : File '%s' has no extension\n", filename); printf(RESET);
            continue;
        }
        
        // Check if extension is ".txt"
        if (!check_extension(filename))
        {
            printf(RED "INFO : File '%s' is not a .txt file\n", filename); printf(RESET);
            continue;
        }

        // Check if file exists and is not empty
        if (!file_exist_and_not_empty(filename))
        {
            printf(RED "INFO : File '%s' does not exist or is empty\n", filename); printf(RESET);
            continue;
        }
        
        // Insert into list
        printf(GREEN "INFO : Successfull : Inserting filename '%s' into file linked list\n\n", filename); printf(RESET);
        insert_at_last(head, filename);
    }
    print_list(*head);
    return SUCCESS;
}

void print_list(F_List *head)
{
	if (head == NULL)
	{
		printf(RED "INFO : List is empty\n" RESET);
	}
    else
    {
	    while (head)		
	    {
		    printf("%s -> ", head -> filename);
		    head = head -> Flink;
	    }

	    printf("NULL\n");
    }
}

int check_extension(char *filename)
{
    char *ext = strrchr(filename, '.');
    return (ext && strcmp(ext, ".txt") == 0);
}

int file_exist_and_not_empty(char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        return 0;
    }
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fclose(fp);

    return size > 0;
}

int insert_at_last(F_List **head, char *data)
{
    /* Create new node */
    F_List *new = malloc(sizeof(F_List));
    
    /* Validate */
    if(new == NULL)
    {
        printf(RED "ERROR: Memory not allocated\n" RESET);
        return FAILURE;
    }
    
    /* Update node */
    strcpy(new -> filename, data);
    new -> Flink = NULL;
    
    /* Check if list is empty */
    if(*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }
    
    /* List is not empty */
    
    //traverse upto last node
    F_List *temp = *head;
    while(temp -> Flink != NULL)
    {
        temp = temp -> Flink;
    }
    temp -> Flink = new;
    return SUCCESS;
}
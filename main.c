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

int main(int argc, char **argv)
{
    F_List *head = NULL;
    H_Table Hash[28] = {0};

    int option;
    char word[30], backup_file[50];

    if (read_and_validate_args(argc, argv, &head) == FAILURE)
    {
        return FAILURE;
    }
    int db_flag = 0; 

    while(1)
    {
        printf(CYAN "\nInverted Search Menu:\n");
		printf("1. Create database from Files\n");
        printf("2. Display database\n");
		printf("3. Search word\n");
		printf("4. Save database to File\n");
        printf("5. Update database\n");
		printf("6. Exit\n" RESET);
		printf(BLUE "Enter your choice: " RESET);
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            if (db_flag == 0)
            {
                if (create_database (&head, Hash) == SUCCESS)
                {
                    db_flag = 1;
                    printf(GREEN "INFO : Database is created successfully\n" RESET);
                }
                else
                {
                    printf(RED "ERROR : Failed to create database\n" RESET);
                }
            }
            else
            {
                printf(YELLOW "INFO : Database is already created\n" RESET);
            }
            break;

        case 2:
            if (db_flag == 1)
            {
                display_database(Hash);
            }
            else
            {
                printf(YELLOW "INFO : Either update or create database before displaying\n" RESET);
            }
            break;
        
        case 3:
            if(db_flag == 1)
            {
                printf(BLUE "Enter word to search : " RESET);
                scanf(" %[^\n]", word);
                if (search_word (Hash, word) == FAILURE)
                {
                    printf(RED "ERROR : Word  not found in database\n" RESET);
                    break;
                }
            }
            else
            {
                printf(YELLOW "INFO : Either update or create database before searching\n" RESET);
            }
            
            break;
        
        case 4:
            if(db_flag == 1)
            {
                printf(BLUE "\nEnter filename to save (e.g., backup.txt) :" RESET);
                scanf(" %[^\n]", backup_file);
                if (save_database (Hash, backup_file) == FAILURE)
                {
                    printf(RED "ERROR : Saving database failed\n" RESET);
                    break;
                }
            }
            else
            {
                printf(YELLOW "INFO : Either update or create database before saving\n" RESET);
            }
            
            break;
        case 5:
            if (db_flag == 0)
            {
                if (update_database (&head, Hash) == SUCCESS)
                {
                    db_flag = 1;
                    printf(GREEN "INFO : Database is updated successfully\n" RESET);
                    print_list(head);
                }
                else
                {
                    printf(RED "ERROR : Failed to update database\n" RESET);
                }
            }
            else
            {
                printf(YELLOW "INFO : Database is already updated\n" RESET);
            }
            
            break;

        case 6:
            printf(GREEN "INFO : Exiting...\n" RESET);
            return SUCCESS;

        default:
            printf(RED "ERROR : Invalid case, Try again\n" RESET);
        }
    }    
    return SUCCESS;
}


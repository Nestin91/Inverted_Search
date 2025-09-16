#ifndef INVERTED_SEARCH_H
#define INVERTED_SEARCH_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "colors.h"

#define SUCCESS  0
#define FAILURE -1

typedef struct file_list
{
    char filename[30];
    struct file_list *Flink;
}F_List;

typedef struct hash_table
{
    int data;
    struct main_node *Hlink;
}H_Table;

typedef struct main_node
{
    char word[30];
    int file_count;
    struct sub_node *m_sublink;
    struct main_node *mainlink;
}M_node;

typedef struct  sub_node
{
    char s_filename[30];
    int word_count;
    struct sub_node *sublink;
}S_node;

/* Function Prototypes */
int read_and_validate_args(int argc, char **argv, F_List **head);
int check_extension(char *filename);
int file_exist_and_not_empty(char *filename);
int insert_at_last(F_List **head, char *data);
void print_list(F_List *head);
int create_database(F_List **head, H_Table *Hash);
int hash_function(char *word);
int search_word(H_Table *Hash, char *word);
int display_database(H_Table *Hash);
int save_database(H_Table *Hash, char *filename);
int is_txt_file(const char *filename);
int update_database(F_List **head, H_Table *Hash);
int find_index(char ch);
int insert_data_to_table(M_node *new, H_Table *Hash);
int delete_file_from_list(char file_name[], F_List **head);
M_node *create_main_node(char word[]);
S_node *create_sub_node(char file_name[]);
#endif
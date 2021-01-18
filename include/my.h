/*
** EPITECH PROJECT, 2018
** include
** File description:
** create an include
*/

#ifndef MY_H_
#define MY_H_

#ifndef STRUCT_H
#define STRUCT_H

typedef struct t_a_list {
    int l_a;
    int nb_tot;
    struct t_a_list *next;
    struct t_a_list *prev;
} s_a_list;

typedef struct t_b_list {
    int l_b;
    int nb_tot;
    struct t_b_list *next;
    struct t_b_list *prev;
} s_b_list;

#endif

int add_element_to_l_b(s_b_list **l_b, s_a_list **l_a);
int add_element_to_l_a(s_a_list **l_a, s_b_list **l_b);
s_b_list *supprelem_b(s_b_list *l_b);
s_a_list *supprelem_a(s_a_list *l_a);
s_a_list *swapl_a_to_l_b(s_a_list *tmp);
void my_putchar(char c);
int my_putstr (char const *str);
void my_swap (int *a, int *b);
char *my_revstr (char *str);
char *my_strcpy(char const *src);
int my_strlen(char const *str);
int my_strlen2(char const *str, int i);
int my_strcmp(char const *s1, char const *s2);
int my_getnbr(char *str);
char *my_strdup(char const *src);
char *openfile(char *filepath);
int main(int argc, char **argv);
char **strtotab(char *str, int *f);
int my_strlen3(char *str);
int my_strlentab(char **tab, int j);
int my_tablen_line(char **tab);
void my_put_nbr(int nb);
s_a_list *reset_a(s_a_list *tmp);
s_b_list *reset_b(s_b_list *tmp);
s_a_list *swap_element_a(s_a_list *tmp, int i, int j);
s_b_list *swap_element_b(s_b_list *tmp, int i, int j);
void print_list_a(s_a_list *tmp);
void print_list_b(s_b_list *tmp);
int add_element(s_a_list **li, int nb, char **argv);
int first(int argc, char **argv);
void swap_end_a(s_a_list **l_a);
void swap_end_b(s_b_list **l_b);
s_a_list algo(s_a_list **l_a, s_b_list **l_b);
void freethelist(s_a_list *l_a, s_b_list *l_b);
#endif

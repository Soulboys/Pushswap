/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** __DESCRIPTION__
*/

#include "include/my.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

s_a_list algo(s_a_list **l_a, s_b_list **l_b)
{
    int smallest = 2147483647;

    (*l_a) = reset_a((*l_a));
    for (; (*l_a)->next != NULL; (*l_a) = (*l_a)->next) {
        if ((*l_a)->l_a <= smallest)
            smallest = (*l_a)->l_a;
    }
    if ((*l_a)->l_a <= smallest)
        smallest = (*l_a)->l_a;
    (*l_a) = reset_a((*l_a));
    for (; (*l_a)->l_a != smallest;) {
        swap_end_a(l_a);
        write(1, "rra ", 4);
    }
    add_element_to_l_b(l_b, l_a);
    write(1, "pb ", 3);
}

void print_list_a(s_a_list *tmp)
{
    if (tmp == NULL)
        return;
    tmp = reset_a(tmp);
    write(1, "l_a : ", 6);
    while (tmp != NULL) {
        my_put_nbr(tmp->l_a);
        my_putchar(' ');
        tmp = tmp->next;
    }
    my_putchar('\n');
}

int add_element(s_a_list **l_a, int nb, char **argv)
{
    s_a_list *new = malloc(sizeof(*new));
    s_a_list *tmp;

    tmp = *l_a;
    new->l_a = my_getnbr(argv[nb]);
    new->nb_tot = nb;
    new->next = NULL;
    new->prev = NULL;
    if (tmp == NULL) {
        *l_a = new;
    } else {
        while (tmp->next) {
            tmp = tmp->next;
        }
        new->prev = tmp;
        tmp->next = new;
    }
}

int first(int argc, char **argv)
{
    int i = 1;
    int k = 0;
    int d = 1, j = 1;
    s_a_list *l_a = 0;
    s_b_list *l_b = 0;
    s_a_list *tmp = 0;

    while (i < argc) {
        add_element(&l_a, i, argv);
        i++;
    }
    for (; argc != d; d++)
        algo(&l_a, &l_b);
    for (int e = 1; argc != e; e++)
        add_element_to_l_a(&l_a, &l_b);
    for (int a = 2; a != d; a++)
        write(1, "pa ", 3);
    my_putstr("pa\n");
    freethelist(l_a, l_b);
}

int main(int argc, char **argv)
{
    first(argc, argv);
}

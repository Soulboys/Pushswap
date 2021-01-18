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

s_a_list *reset_a(s_a_list *tmp)
{
    while (tmp->prev != NULL) {
        tmp = tmp->prev;
    }
    return (tmp);
}

void print_list_b(s_b_list *tmp)
{
    if (tmp == NULL)
        return;
    tmp = reset_b(tmp);
    write(1, "l_b : ", 6);
    while (tmp) {
        my_put_nbr(tmp->l_b);
        my_putchar(' ');
        tmp = tmp->next;
    }
    my_putchar('\n');
}

void freethelist(s_a_list *l_a, s_b_list *l_b)
{
    s_a_list *tmp = l_a;

    free(l_b);
    while (tmp != NULL) {
        tmp = tmp->next;
        free(l_a);
        l_a = tmp;
    }
}

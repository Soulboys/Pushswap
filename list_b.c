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

s_b_list *reset_b(s_b_list *tmp)
{
    while (tmp->prev != NULL) {
        tmp = tmp->prev;
    }
    return (tmp);
}


s_a_list *supprelem_a(s_a_list *l_a)
{
    l_a = reset_a(l_a);
    l_a = l_a->next;
    if (l_a) {
        free(l_a->prev);
        l_a->prev = NULL;
    }
    return (l_a);
}

s_b_list *supprelem_b(s_b_list *l_b)
{
    l_b = reset_b(l_b);
    l_b = l_b->next;
    if (l_b) {
        free(l_b->prev);
        l_b->prev = NULL;
    }
    return (l_b);
}

int add_element_to_l_a(s_a_list **l_a, s_b_list **l_b)
{
    s_a_list *new = malloc(sizeof(*new));
    s_a_list *tmp = *l_a;

    *l_b = reset_b(*l_b);
    if (tmp)
        tmp = reset_a(tmp);
    new->l_a = (*l_b)->l_b;
    new->next = tmp;
    new->prev = NULL;
    if (tmp)
        tmp->prev = new;
    *l_a = new;
    *l_b = supprelem_b(*l_b);
}

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


int add_element_to_l_b(s_b_list **l_b, s_a_list **l_a)
{
    s_b_list *new = malloc(sizeof(*new));
    s_b_list *tmp = *l_b;

    *l_a = reset_a(*l_a);
    if (tmp)
        tmp = reset_b(tmp);
    new->l_b = (*l_a)->l_a;
    new->next = tmp;
    new->prev = NULL;
    tmp = *l_b;
    *l_b = new;
    if (tmp)
        tmp->prev = new;
    *l_a = supprelem_a(*l_a);
}

s_a_list *swap_element_a(s_a_list *tmp, int i, int j)
{
    int tmp_nb;
    int tmp_nb2;

    tmp = reset_a(tmp);
    if (i > j)
        my_swap(&i, &j);
    for (int k = 0; k != i; k++)
        tmp = tmp->next;
    tmp_nb = tmp->l_a;
    tmp = reset_a(tmp);
    for (int e = 0; e != j; e++)
        tmp = tmp->next;
    tmp_nb2 = tmp->l_a;
    tmp->l_a = tmp_nb;
    tmp = reset_a(tmp);
    for (int k = 0; k != i; k++)
        tmp = tmp->next;
    tmp->l_a = tmp_nb2;
    return (tmp);
}

s_b_list *swap_element_b(s_b_list *tmp, int i, int j)
{
    int tmp_nb;
    int tmp_nb2;

    tmp = reset_b(tmp);
    if (i > j)
        my_swap(&i, &j);
    for (int k = 0; k != i; k++)
        tmp = tmp->next;
    tmp_nb = tmp->l_b;
    tmp = reset_b(tmp);
    for (int e = 0; e != j; e++)
        tmp = tmp->next;
    tmp_nb2 = tmp->l_b;
    tmp->l_b = tmp_nb;
    tmp = reset_b(tmp);
    for (int k = 0; k != i; k++)
        tmp = tmp->next;
    tmp->l_b = tmp_nb2;
    return (tmp);
}

void swap_end_a(s_a_list **l_a)
{
    s_a_list *tmp2;
    s_a_list *tmp = reset_a(*l_a);
    while ((*l_a)->next != NULL) {
        (*l_a) = (*l_a)->next;
        tmp2 = (*l_a)->prev;
    }
    tmp->prev = (*l_a);
    (*l_a)->next = tmp;
    (*l_a)->prev = NULL;
    tmp2->next = NULL;
}

void swap_end_b(s_b_list **l_b)
{
    s_b_list *tmp2;
    s_b_list *tmp = reset_b(*l_b);
    while ((*l_b)->next != NULL) {
        (*l_b) = (*l_b)->next;
        tmp2 = (*l_b)->prev;
    }
    tmp->prev = (*l_b);
    (*l_b)->next = tmp;
    (*l_b)->prev = NULL;
    tmp2->next = NULL;
}

#include "answer08.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

List * List_append(List * list, List * node);

/*******************************************************************************************/
/**
 * Create a new list-node with the passed string.
 * str should be copied (with strdup).
 */
List * List_createNode(const char * str)
{
    List * node;
    node = malloc(sizeof(List));
    node->next = NULL;
    node->str = strdup(str);
    return(node);
}
/*******************************************************************************************/
/**
 * Free all memory associated with the linked list, including memory for
 * contained strings. Must safely handle NULL lists.
 */
void List_destroy(List * list)
{
    if(list == NULL)
    {
        return;
    }
    while(list != NULL)
    {
        List * p = list -> next;
        //list = list->next;
        free(list -> str);
        free(list);
        list = p;
    }
}
/*******************************************************************************************/
/**
 * Length of a linked list.
 * The length of "NULL" is 0.
 */
int List_length(List * list)
{
    int length=1;
    if (list == NULL)
    {
        return 0;
    }
    while(list->next != NULL)
    {
        length++;
        list = list->next;
    }
    return(length);
}
/*******************************************************************************************/
/**
 * Merge two sorted lists to produce a final sorted list.
 *
 * 'lhs' and 'rhs' are two sorted linked-list. Read 'left-hand-side' and 'right-
 * hand-side'. Note that either (or both) could be NULL, signifying the empty
 * list.
 * 'compar' is a function that is used to compare two nodes. This parameter is
 * similar to the parameter in qsort(...), except that it only compares two
 * strings. You can pass 'strcmp' to this function if you want to sort lists in
 * ascending order.
 *
 * When implementing this function, do not call List_createNode(...) or
 * malloc(...) Instead, think about how to build a new list by:
 * (1) Create a new (empty -- i.e., NULL) list where we build the result. You
 *     will need to track the first and last node of this list.
 * (2) In a while-loop:
 * (2.a) Use compar to identify whether the front node of lhs or rhs is smaller.
 *       Remember that lhs or rhs could be NULL.
 * (2.b) Move the front node of 'lhs/rhs' to the end of the result list.
 *
 * You will need to consider what happens when 'lhs' or 'rhs' becomes NULL.
 *
 * Well-written code should be 20-30 lines long, including comments and spacing.
 * If your code is longer than this, then you may save time by rethinking your
 * approach.
 */

List * List_append(List * list, List * node)
{
    if(list == NULL)
    {
        return (node);
    }
    List * curr = list;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = node;
    return(list);
}


List * List_merge(List * lhs, List * rhs, int (*compar)(const char *, const char*))
{
    List * temp = NULL;
    List * newlist = NULL;
    while(lhs != NULL && rhs != NULL)
    {
        if ( compar(lhs->str, rhs->str) < 0)
        {
            temp = lhs->next;
            lhs->next = NULL;
            newlist = List_append(newlist,lhs);
            lhs = temp;
        }
        else
        {
            temp = rhs->next;
            rhs->next = NULL;
            newlist = List_append(newlist,rhs);
            rhs = temp;
        }
    }
    if(lhs != NULL)
    {
        newlist = List_append(newlist, lhs);
    }
    if(rhs != NULL)
    {
        newlist = List_append(newlist, rhs);
    }
    return(newlist);
}

/*******************************************************************************************/
/**
 * Sorts the list's elements using the merge-sort algorithm.
 * Merge-sort is a recursive algorithm. See the README for hints.
 *
 * The brief instructions are as follows:
 *
 * (1) Base case:
 * Lists of length 0 or 1 are already (defacto) sorted. In this case, return
 * 'list'.
 *
 * (2) Recursive case:
 * (2.a) Split the linked-list into two approx. equal sized lists.
 * (2.b) Call List_sort(...) on each of these smaller lists.
 * (2.c) Call List_merge(...) to merge the now sorted smaller lists into a
 *       single larger sorted list, which you return.
 *
 * Well-written code should be 20-30 lines long, including comments and spacing.
 * If your code is longer than this, then you may save time by rethinking your
 * approach.
 */
List * List_sort(List * list, int (*compar)(const char *, const char*))
{
    //return list;
    int len = List_length(list);
    List * left_head = list;
    List * left_curr = list;
    List * right_head = NULL;
    int i = 0;
    int middle = len/2;
    if(len == 0 || len == 1)
    {
        return(list);
    }
    for(i=1;i<middle; i++)
    {
        left_curr=left_curr->next;
    }
    right_head = left_curr->next;
    left_curr->next = NULL;
    left_head = List_sort(left_head, compar);
    right_head = List_sort(right_head, compar);
    return(List_merge(left_head, right_head, compar));
}
/*int *compar(const char str1, const char str2 )
{
    if(strcmp(str1,str2) > 0)
    {
        return(1);
    }
    if(strcmp(str1,str2) < 0)
    {
        return(-1);
    }
    if(strcmp(str1,str2) == 0)
    {
        return(0);
    }
}*/






/*******************************************************************************************/

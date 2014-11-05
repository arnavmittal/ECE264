#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "answer09.h"

/************************************************************************************************/
/* A BusinessNode contains the name, address, and average rating of a Business.
 * It also contains pointers to the left and right children of the node.
 */
/************************************************************************************************/
/*
 * Construct one BusinessNode. You need to allocate memory for this node first.
 *
 * The caller needs to make sure to use strdup(...) for the arguments, do not
 * use strdup(...) inside of this function.
 *
 * stars: the stars of this business
 * name: name of this business
 * address: address of this business
 */
BusinessNode * create_node(char * stars, char * name, char * address)
{
    BusinessNode * t;
    t = malloc(sizeof(BusinessNode));
    t->name = name;
    t->stars = stars;
    t->address = address;
    t->left = NULL;
    t->right = NULL;
    return(t);
}
/************************************************************************************************/

/* Insert a node into a BST. Primarily used in load_tree_from_file(). Return a
 * pointer to the root of the BST.
 */
BusinessNode * tree_insert(BusinessNode * node, BusinessNode * root)
{
    int val=0;
    if(root == NULL)
    {
        return(node);
    }
    val=strcmp(node->name, root->name);
    if(val <= 0)
    {
        root->left=tree_insert(node, root->left);
    }
    else
    {
        root->right=tree_insert(node, root->right);
    }
    return(root);
}
/************************************************************************************************/
/* Parse a .tsv file line by line, create a BusinessNode for each entry, and
 * enter that node into a new BST. Return a pointer to the root of the BST.
 *
 * The explode(...) function from PA03 may be useful for breaking up a lines
 * into seperate fields.
 */
char * * explode(const char * str, const char * delims, int * arrLen)
{
    int ind=0;
    int last=0;
    int len=0;
    int arrInd=0;
    *arrLen = 1;
    for(ind = 0; ind < strlen(str); ind++)
    {
        if (strchr(delims, str[ind]) != NULL)
        {
            (*arrLen)++;
        }
    }
    char * * strArr = malloc(((*arrLen)) * sizeof(char *));
    for(ind=0; ind < strlen(str); ind++)
    {
        if (strchr(delims, str[ind]) != NULL)
        {
            len = ind - last;
            strArr[arrInd]=malloc((len+1)*sizeof(char));
            memcpy(strArr[arrInd], &str[last], len);
            strArr[arrInd][len]='\0';
            arrInd++;
            last=ind+1;
        }
    }
    len = ind - last;
    strArr[arrInd]=malloc((len+1)*sizeof(char));
    memcpy(strArr[arrInd], &str[last], len);
    strArr[arrInd][len]='\0';
    arrInd++;
    last=ind+1;
    return(strArr);
}
               
BusinessNode * load_tree_from_file(char * filename)
{
    FILE * fp = NULL;
    fp = fopen(filename, "r");
    if(fp == NULL)
    {
        return(NULL);
    }
    BusinessNode * root = NULL;
    char ** stringarr = NULL;
    char * string = malloc(sizeof(char)*2000);
    int arrLen = 0;
    while(1)
    {
        fgets(string, 2000, fp);
        if(feof(fp))
        {
            break;
        }
        stringarr = explode(string, "\t", &arrLen);
        if(arrLen == 3)
        {
            BusinessNode * newnode = create_node(stringarr[0], stringarr[1], stringarr[2]);
            root = tree_insert(newnode, root);
        }
        free(stringarr);
    }
    free(string);
    fclose(fp);
    return(root);
}
/************************************************************************************************/

/* Search a BusinessNode BST for the node with the name 'name'. Returns
 * pointer to the node with a match.
 *
 * If there is no match, return NULL.
 */
BusinessNode * tree_search_name(char * name, BusinessNode * root)
{
    if(root == NULL)
    {
        return (NULL);
    }
    int val=0;
    val = strcmp(name, root->name);
    if (val == 0)
    {
        return(root);
    }
    else if(val < 0)
    {
        return(tree_search_name(name, root->left));
    }
    else
    {
        return(tree_search_name(name, root->right));
    }
}
/************************************************************************************************/
/* Print out a single node: name, address, and stars
 * The format can be similar to this:
 *
 * Country Cafe
 * ============
 * Stars:
 *    3.5
 * Address:
 *    1030 Emerald Ter, Sun Prairie, WI 53590
 *
 * This function is not graded, but it could come in very handful while
 * debugging this assignment.
 */
void print_node(BusinessNode * node);
/************************************************************************************************/
/* Print the entire tree, starting from the root. Like the print_node(...)
 * function, this is not graded.
 */
void print_tree(BusinessNode * tree);
/************************************************************************************************/
/* Deallocate all of the memory used by a BusinessNode BST, without memory
 * leaks.
 */
void destroy_tree(BusinessNode * root)
{
    if(root == NULL)
    {
        return;
    }
    destroy_tree(root->left);
    destroy_tree(root->right);
    free(root->name);
    free(root->stars);
    free(root->address);
    free(root);
}
/************************************************************************************************/

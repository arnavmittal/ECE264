#include<stdio.h>
#include<stdlib.h>
#include "answer09.h"

int main()
{
	BusinessNode * root = load_tree_from_file("randomtest.tsv");
	destroy_tree(root);
	return(0);
}

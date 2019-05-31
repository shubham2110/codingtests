#include<stdio.h>

struct node {
	
	int test;
};


int main()
{
	
	struct node *ptr;
	struct node ** ptr2;
	ptr= (struct node *)malloc(sizeof(struct node));
	

	ptr2= (struct node **)malloc(sizeof(struct node *));


}
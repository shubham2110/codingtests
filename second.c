#include<stdio.h>
#include"model.c"
int main()
{
	struct node **ptr2;
	scanf("%d",&count);
	ptr2=makelist();
	printf("%d",findmax(ptr2));
	return 0;

}
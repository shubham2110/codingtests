#include<stdio.h>
#include "model.c"

int main()
{
	struct node **ptr2;
	int maximumsum=0;
	int sum1=0;
	int no1=-1;

	scanf("%d",&count);

	ptr2 =  makelist();

	for(i=0;i<count;i++)
	{	
		sum1=0;
		no1=-1;
		printf("Trying for %d \n:",i);
		if(traverse(ptr2[i], &sum1, &no1))
		{

			if(i == no1)
			{ 
				if(maximumsum < sum1) maximumsum = sum1;

				printf("%d\n",sum1);
			}
			else
			{ 
					printf("Visits Cleared by_ %d\n",i);
					clearvisit(ptr2[i]->next);
			}
		}
			
	}

	printf("%d", maximumsum);
	return 0;
}
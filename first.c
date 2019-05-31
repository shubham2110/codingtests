#include<stdio.h>
#include "model.c"

int main()
{
	struct node **ptr2;
	int maximumsum=0;
	int sum1=0;
	int no1=-1;


	scanf("%d",&count); // Scan number of nodes.
	ptr2 =  makelist(); // create adjacency list. 

	for(i=0;i<count;i++)
	{	
		sum1=0;
		no1=-1;
		if (debug)
			printf("Trying for %d \n:",i);
		/*
		If traverse(ptr2[i], &sum1, &no1)) function returns 1,
			that means 'node i' somehow went into looping.
			Now we have to check if ptr[i] is part of loop or it was just\
			outside the loop but went inside.(Example: 17, 18, 2)
		else if traverse returns 0, means no loop was detected.
		*/
		if(traverse(ptr2[i], &sum1, &no1)) 
		{

			/*
			if i==no1 means loop started with i and ended with i.. so there is a loop. 
			*/
			if(i == no1)  /* Because there is a loop, so we should check the sum1 now. */
			{
				if(maximumsum < sum1) maximumsum = sum1;
			}
			else // Loop detected with i is not part of loop. So clear all visits created by i. 
			{
				clearvisit(ptr2[i]->next);
			}
		}
			
	}

	printf("%d", maximumsum);
	return 0;
}
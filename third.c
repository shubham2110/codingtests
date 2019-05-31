#include<stdio.h>
#include"model.c"
int main()
{
	int X,Y;
	int sum1,no1;
	
	struct node *ptr4;
	struct node *ptr5;
	int min=count;
	struct node **ptr;


	scanf("%d",&count);
	ptr=makelist();

	scanf("%d %d",&X,&Y);  // scanning node number for finding meeting point


	// Traverse from the first node
	ptr4=ptr[X];
	ptr4->data=0;
	while(1)
	{
		if(ptr4 == NULL || ptr4->visited ==1) break; // stop if already visited or found Null

		// Check if node Y is in path of node X.
        if(ptr4->nodeno == ptr[Y]->nodeno)
			min=ptr[X]->data ;

		//counting length of ptr4 from ptr[X]
        ptr[X]->data +=1;
		

		ptr4->visited=1;
		if(ptr4->next)
		{
			ptr4=ptr4->next;
		}
		
	}


	
	// Now traverse from node Y
	ptr5=ptr[Y];
	ptr5->data=0;
	while(1)
	{
		printf("PTR5 values: %d , %d",ptr5->nodeno, ptr5->visited);
		return 0;
		/*
			This condition will be true in two cases:
			1. Node Y is already visited by Node X
			2. Node Y is visted by Node Y itself, because Node Y is in loop.
		*/
		if(ptr5->visited==1 && ptr5->nodeno == ptr[Y]->nodeno) 
		{
			/*
				ptr[Y]->data means ptr5 did not move. Means Node Y is already visited by NODE X.
				Warning: This code doesn't support Self loop nodes yet. 
			*/
			 if(ptr[Y]->data == 0) 
			 {
			 	/*
					Find length from Y to X. 
					Because X and Y may be in the same loop. We have to check, if 'X to Y' is sort or 'Y to X'. 
			 	*/
			 	ptr5->data = findlength(ptr5,ptr[X]);
			 	if(min < ptr5->data) // if X can reach to Y earlier than Y reaches to X
			 	 	printf("%d",Y);
			 	else
			 		printf("%d",X);
			 	return 0;
			 }
			 else // This shows, that Y traveled back to himself but he never found X on the way. Means, they don't meet.
			 {
			 	printf("%d",-1);
			 	return 0;
			 }
		} 
		if(ptr5->visited ==1) // They both meet at this location.
		{
			printf("%d",ptr5->nodeno);
			return 0;
		}

	  ptr[Y]->data +=1; // Increamenting length from Y to ptr5. For checking length from Y to X .
	  ptr5->visited=1;
	 
	  if(ptr5->next)
	    ptr5=ptr5->next;
	  else 
	  {	
	  	printf("%d",-1);
	  	return 0;
	  }
	}

	

	return 0;
}
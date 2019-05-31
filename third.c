#include<stdio.h>
#include"model.c"
int main()
{
	int X,Y;
	int sum1,no1,temp2;
	int gotloop=0, xpartofloop=0, ypartofloop=0; 	
	struct node *ptr4;
	struct node *ptr5;
	int min=count;
	struct node **ptr;


	scanf("%d",&count);
	ptr=makelist();

	scanf("%d %d",&X,&Y);  // scanning node number for finding meeting point
	if(X == Y)
	{

	 printf("%d",X);
		return 0;
	}
	// Traverse from the first node

	ptr4=ptr[X];
	ptr4->data=0;
	while(1)
	{
		if(ptr4 == NULL || ptr4->visited ==1)
		{
			if(ptr4) gotloop=1;
			if(ptr4 == ptr[X]) xpartofloop=1;
			if(ptr[X]->traverser ==1 && gotloop) ypartofloop=1;
			break; // stop if already visited or found Null
		}
		// Check if node Y is in path of node X.
        if(ptr4->nodeno == ptr[Y]->nodeno)
        {
			min=ptr[X]->data ;
			ptr[X]->traverser=1;
        }


		//counting length of ptr4 from ptr[X]
		if(ptr4 != ptr[X] && ptr[X]->traverser ==1)
			ptr4->weight = 1;
		else 
			ptr4->weight=0; // If visited by X before visiting by Y
        ptr[X]->data +=1;
		ptr4->visited = 1;
		if(ptr4->next)
		{
			ptr4=ptr4->next;
		}
		else
		{
			break;
		}
		
	}


	//printf("X:%d Y:%d Loop:%d    %d",xpartofloop, ypartofloop,gotloop, ptr[X]->visited);
	//return 0;
	// Now traverse from node Y
	ptr5=ptr[Y];
	ptr5->data=0;
	if( ptr[X]->traverser ==1 && xpartofloop ==1)
	{
		// Both Belong to same loop
		temp2=findlength(ptr[Y], ptr[X]);
		if(min < temp2)
			printf("%d",Y);
		else
			printf("%d",X);
		return 0;
	}
	else if(gotloop && ypartofloop && !xpartofloop)
	{
		int init=1;
		while( init || ptr5->weight == 	1 )
		{
			init=0;
			ptr[Y]->data +=1;
			ptr5=ptr5->next;
		}
		if(min < ptr[Y]->data)
			printf("%d",Y);
		else
			printf("%d",ptr5->nodeno);
		return 0;
	}
	else// if (gotloop && xpartofloop && !ypartofloop)
	{
		//printf("ss");
		while(ptr5 && ptr5->visited !=1)
		{
			if(ptr5 == ptr[X])
				ptr[Y]->traverser=1;
			ptr5->visited=1;
			ptr5= ptr5->next;
		}

		if(ptr5== NULL && ptr[Y]->traverser) // Y found X on the way 
			printf("%d",X);
		else if(ptr5)
			printf("%d",ptr5->nodeno);
		else if (ptr[X]->traverser) // there was no loop but X found Y on the way 
			printf("%d",Y);
		else 
			printf("-1");
	}

	return 0;
}
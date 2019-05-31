#include<stdio.h>
#include"model.c"
int main()
{
	int k,l;
	int sum1,no1;
	
	struct node *ptr4;
	struct node *ptr5;
	int min=count;
	struct node **ptr;
	scanf("%d",&count);
	
	ptr=makelist();

	scanf("%d %d",&k,&l);

	//printf("%d",findmax(ptr));
	ptr4=ptr[k];
	ptr4->data=0;

	while(1)
	{
		if(ptr4 == NULL) break;
		if(ptr4->visited==1)
		{
			 break;
		}

        ptr[k]->data +=1;

        if(ptr4->nodeno == ptr[l]->nodeno)
		{
			min=ptr[k]->data ;
		} 

		ptr4->visited=1;
		if(ptr4->next)
		{
			ptr4=ptr4->next;
		}
		
	}

	//printf("%d\n",min);
	
	ptr5=ptr[l];
	ptr5->data=0;
	while(1)
	{
		if(ptr5->visited==1 && ptr5->nodeno == ptr[l]->nodeno) {
			 if(ptr[l]->data == 0) 
			 {
			 	ptr5->data = find(ptr5,ptr[k]);
			 	if(min < ptr5->data)
			 	{
			 	 printf("%d",l);
			 	}
			 	else
			 	printf("%d",k);
			 	return 0;
			 }
			 else
			 {
			 	printf("%d",-1);
			 	return 0;
			 }
		} 
		if(ptr5->visited ==1)
		{
			printf("%d",ptr5->nodeno);
			return 0;
		}

	  ptr[l]->data +=1;
	  ptr5->visited=1;
	  if(ptr5->next)
	    ptr5=ptr5->next;
	}

	printf("%d",-1);


}
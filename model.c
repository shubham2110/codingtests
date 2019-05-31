struct node
{
	
	int nodeno;
	int weight;
	int visited;
	int partofcycle;
	int traverser;
	int data;
	int loop;
	struct node *next;

};

int i,temp;
int count;

int find(struct node *a, struct node *b)
{

	int count=0;
	while(a!=b)
	{
		count++;
		a=a->next;
	}
	return count++;
}

struct node ** makelist()
{
	static struct node **ptr;
	ptr=(struct node **)malloc(count *sizeof(struct node * ));


	for(i=0;i<count;i++)
	{
		struct node *tmp2= (struct node *)malloc(sizeof(struct node ));
		tmp2->nodeno=i;
		tmp2->weight=0;
		tmp2 ->next = NULL;
		tmp2->partofcycle=0;
		tmp2->traverser=0;
		tmp2->data=-1;
		tmp2->loop=0;
		ptr[i]=tmp2;
	}

	for(i=0;i<count;i++)
	{

		scanf("%d",&temp);

		if(temp != -1)
		{
			ptr[i]->next = ptr[temp];
			ptr[temp]->weight += ptr[i]->nodeno;
		}
	//	printf("List: %d --> %d\n",i, temp);
	}

	return ptr;
}

void clearvisit(struct node *node)
{
	if(node == NULL) return;
	if(node->traverser == 1)
	{
		return;
	}
	node->traverser=1;
	node->visited = 0;
	clearvisit(node->next);
	node->traverser=0;
	
}





int traverse(struct node *node, int *sum, int *no) // return 1 if cycle is found
{
	if(node) *no=node->nodeno;
	else *no=-1;

	while(node && node->visited ==0 )
	{
		*sum = *sum + node->nodeno;
		node->visited = 1;
		node=node->next;
	}

	if(node == NULL) return 0;
	if(node->visited ==1)
	{
	 *no=node->nodeno;
	 return 1;
	} 
	return 0;
	
}


int findmax(struct node **ptr)
{
	int max=-1;
	int location=-1;
	for( i=0;i<count;i++)
	{
		if(! ptr[i]) 
			continue;
		if(max < ptr[i]->weight) 
		{	max=ptr[i]->weight ;
			location=i;
		}
	}

	return location;
}
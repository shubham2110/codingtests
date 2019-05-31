struct node
{
	
	int nodeno;
	int weight;
	int visited;
	int visted2;
	int traverser;
	int data;
	struct node *next;

};

int i,temp;
int count;
int debug=0;


/* 
This Function will be used to find length from 'node a' to 'node b'.
This function is called only if both 'node a' has path to 'node b'.
*/
int findlength(struct node *a, struct node *b) 
{

	int length=0;
	while(a && a!=b)
	{
		length++;
		a=a->next;
	}
	if(a)
		return length;
	else 
		return count+1;
}


/*
This Function will create a adjacency list for the given graph. 
It will take all inputs and them create a adjacency list.
*/
struct node ** makelist()
{
	static struct node **ptr; // array ptr[] stores pointer of all nodes.	
	ptr=(struct node **)malloc(count *sizeof(struct node * )); // Creating array of n struct nodes.

	/* Initializing all nodes with initial values. */
	for(i=0;i<count;i++)
	{
		struct node *tmp2= (struct node *)malloc(sizeof(struct node ));
		tmp2->nodeno=i;
		tmp2->weight=0;
		tmp2 ->next = NULL;
		tmp2->traverser=0;
		tmp2->data=-1;
		ptr[i]=tmp2;
	}


	for(i=0;i<count;i++)
	{
		scanf("%d",&temp);
		if(temp != -1)
		{
			/* Linking node[i] to node[temp] as given in the problem. */
			ptr[i]->next = ptr[temp]; 
			/* This is for 2nd question, calculating weight on the go. */
			ptr[temp]->weight += ptr[i]->nodeno;
		}
	}

	return ptr;
}

/* This function will clear 'node->visited' state to 0.
This is called so that if any element which is not part of loop \
tries to enter into loop and make all loop nodes as visited. 
*/ 
void clearvisit(struct node *node)
{
	if(node == NULL || node->traverser == 1 ) return;
	node->traverser=1;
	node->visited = 0;
	clearvisit(node->next);
	node->traverser=0;
	
}




/*
This function is used to calculate sum of cycle in a graph. 
This function returns 1 is cycle is found (when we visit a already visited node)
This function calculates the sum untill cycle is found or list is finished.
int 'no', the variable stores the last visited node.
int 'no' is used to check if  the node is part of cycle, will be used in main function. 
*/
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


/*
Simple program to find a node with max weight. 
 */
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

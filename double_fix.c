                                                                                           
/* 					Double Linked List	 						*/

#include<stdio.h>
#include<malloc.h>
#include<string.h>
/* Self Referential Structure to implement Dynamic Data Structure */
struct List_data {
	int a;
	struct List_data *next;
	struct List_data *prev;
};

/* typedef names for struct List_data */

typedef struct List_data **Pointer_Pointer;
typedef struct List_data *Pointer;
typedef struct List_data Data;

/* Double Linked List Operations */

/* Init Function */
Pointer init(int a)	/* Init Function */ 
{
	Pointer ptr;
	ptr = (Pointer ) malloc (sizeof(Data));
	if(ptr)			
	{
		ptr->a=a;
		ptr->next = NULL;
		ptr->prev = NULL;
		return ptr; 
	}	
	return ptr; 	
}

/* Function to insert the new node as first node in the list */
void insert_first(Pointer_Pointer pptr,Pointer ptr)	
{
	if(*pptr == NULL)	/* Check whether list is empty */		
		*pptr = ptr;	/* Make new node as first node if list in empty */	
	else
	{
		ptr->next = *pptr; /* Make new node as first node if list is not empty */(*pptr)->prev=ptr;
		ptr->prev = NULL;
		*pptr = ptr;
	
	}	
}

void print_list(Pointer ptr)	/* Print all nodes data in the list */
{       
       Pointer cur;
	printf("\n");
	while(ptr)
	{
		printf("%d->\n",ptr->a);
      		cur=ptr;	
		ptr = ptr->next;
	}
	printf("NULL\n");
	while(cur)
	{
	printf("%d->",cur->a);
	cur=cur->prev;
	}
	printf("NULL\n");

}


















// Function to insert the new node in the middle or end of the list 
void insert_middle(Pointer_Pointer pptr,Pointer ptr,int pos)
{
	int i=1;
	Pointer start=*pptr; 	
	if(start==NULL || pos==1)		
	{
		ptr->next = *pptr;
		ptr->prev = NULL;
               (*pptr)->prev=ptr;
		*pptr = ptr;	// Make new node as first node if list in empty or positions in one//	
		return;
	}
	else
	{
		while((i<pos-1) && start )	//Navigate upto position-1 node //
		{
			start=start->next;
			i++;
		}
	}
	if(start!=NULL)		// Make new node as part of list 
	{
		ptr->next = start->next; 	
		start->next = ptr;
              ptr->next->prev=ptr;
	}
	else
		printf("\n Not A Valied Position \n");
		 
}

/* Print all nodes data in the list */


/* Function to delete a node for the list */
int delete_node(Pointer_Pointer pptr,int data)		/* Function to delete a node for the list */	
{
	Pointer temp,start = *pptr,prev = *pptr;
        printf("\n Before Deletion\n");
        print_list(*pptr);
	if(start==NULL)		/* Check if list is empty */	
	{
		printf("\n List is Empty \n");
		return;
	}
	if(start->a == data)	/* Delete first element */
	{
		temp = start;
		*pptr = start->next;
                start->next->prev=NULL;
		free(temp);
                printf("\n After Deletion\n");
                print_list(*pptr);
		return 0;	
	}
	else
	{
		while( (start->a!=data) && start)	/* Search for the node to delete */
		{
			prev = start;
			start = start->next;
		}
		if(start != NULL)		/* Delete node */	
		{
			prev->next = start->next;
                       if(start->next)
                       { 
                        start->next->prev=prev;
                       }
			free(start);
                       printf("\n After Deletion \n");
                       print_list (*pptr);
		}
		else
			printf("\n Node not Found \n");
	}
	
}

/* Function to count total number of elements in the list */
int count_node(Pointer start)
{
	int count=1;
	while(start->next)
	{
		start=start->next;
		count++;	
	}
	return count;
}


int main()
{

int a , pos;

Pointer start =NULL; /*Pointer pointing to first node of the list */

Pointer ptr;

ptr = init(10);
if (ptr==NULL)
printf("Fail to create a node \n");
else 
insert_first(&start,ptr);
print_list(start);

ptr = init(20);
if (ptr==NULL)
printf("Fail to create a node \n");
else
insert_first(&start,ptr);
print_list(start);

ptr = init(30);
if (ptr==NULL)
printf("Fail to create a node \n");
else
insert_middle(&start,ptr,2);
print_list(start);
delete_node(&start,30);
 
printf("\n Total Number of Elements : %d \n",count_node(start));

}


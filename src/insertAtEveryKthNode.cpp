/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * createNode(int k)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node*));
	temp->num = k;
	temp->next = NULL;
	return temp;
}

struct node * insertAtEveryKthNode(struct node *head, int K) 
{
	if ((head == NULL) || (K <= 0))
		return NULL;
	int count = 0;
	struct node *newhead = head;
	struct node *prev_node;
	while (head != NULL)
	{
		if (count == K)
		{
			count = 0;
			prev_node->next = createNode(K);
			prev_node = prev_node->next;
			prev_node->next = head;
		}
		prev_node = head;
		head = head->next;
		count++;
	}
	if (count == K)
	{
		count = 0;
		prev_node->next = createNode(K);
		prev_node = prev_node->next;
		prev_node->next = head;
	}
	return newhead;
}

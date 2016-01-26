/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) 
{
	if ((head1 == NULL) && (head2 == NULL))
		return NULL;
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	struct node *temp1 = (struct node *)malloc(sizeof(struct node *));
	struct node *mergedlist = (struct node *)malloc(sizeof(struct node *));
	if (head1->num<head2->num)
	{
		temp1 = head1;
		head1 = head1->next;
	}
	else
	{
		temp1 = head2;
		head2 = head2->next;
	}
	mergedlist = temp1;
	while ((head1 != NULL) && (head2 != NULL))
	{
		if (head1->num<head2->num)
		{
			temp1->next = head1;
			head1 = head1->next;
		}
		else
		{
			temp1->next= head2;
			head2 = head2->next;
		}
		temp1 = temp1->next;
	}
	if (head1 != NULL)
	{
		temp1->next = head1;
	}
	if (head2 != NULL)
	{
		temp1->next = head2;
	}
	return mergedlist;
}

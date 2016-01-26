/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head)
{
	if (head == NULL)
		return NULL;
	struct node *temp =head;
	head = head->next;
	struct node *ptr = head;
	temp->next = NULL;
	while (head != NULL)
	{
		ptr = ptr->next;
		head->next = temp;
		temp = head;
		head = ptr;
	}
	return temp;
}

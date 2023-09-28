#include <stdlib.h>
#include <stdio.h>

struct node {
	int		data;
	struct node*	next;
};

struct node*
BuildOneTwoThree()
{
	struct node *head = malloc(3 * sizeof(struct node));

	head[0].data = 1;
	head[0].next = head + 1;
	head[1].data = 2;
	head[1].next = head + 2;
	head[2].data = 3;
	head[2].next = NULL;

	return head;
}

struct node*
BuildTwoThree()
{
	struct node *head = malloc(2 * sizeof(struct node));

	head[0].data = 2;
	head[0].next = head;
	head[1].data = 3;
	head[1].next = NULL;

	return head;
}

void
FreeOneTwoThree(struct node* list)
{
	free(list);
}

int
Length(struct node* head)
{
	struct node* current = head;
	int count = 0;

	while (current != NULL) {
		count++;
		current = current->next;
	}

	return count;
}

void
LengthTest()
{
	struct node *myList = BuildOneTwoThree();

	int len = Length(myList);
	printf("%d\n", len);

	FreeOneTwoThree(myList);

}

void
LinkTest()
{
	struct node *head = BuildOneTwoThree();
	struct node *newNode;

	newNode = malloc(sizeof(struct node));
	newNode->data = 0;

	newNode->next = head;

	head = newNode;

	int len = Length(head);
	printf("%d\n", len);
}

void
WrongPush(struct node *head, int data)
{
	struct node *newNode = malloc(sizeof(struct node));
	printf("WrongPush(): %d\n", head->data);

	newNode->data = data;
	newNode->next = head;
	head = newNode;

	printf("WrongPush(): %d\n", head->data);
}

void
WrongPushTest()
{
	struct node *head = BuildTwoThree();

	WrongPush(head, 1);
}
	
int
main()
{
	LengthTest();
	LinkTest();
	WrongPushTest();

	return 0;
}

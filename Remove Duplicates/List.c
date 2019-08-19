#include "List.h"
#include <stdio.h>

struct Node
{
	int Element;
	Position Next;
};

List delete(List L)
{
	Position Curr = L;
	Position Tmp;
	int val;
	List Dummy = (List *)malloc(sizeof(List));
	Dummy->Next = Curr;
	Dummy->Element = 0;
	Position Node = Dummy;
	Position TmpNode = NULL;

	while (Node->Next != NULL && Node->Next->Next != NULL)
	{
		if (Node->Next->Element == Node->Next->Next->Element)
		{
			val = Node->Next->Element;
			while (Node->Next != NULL && val == Node->Next->Element)
			{
				Node->Next = Node->Next->Next;
			}
		}
		else
			Node = Node->Next;
	}

	return L;


}

List Duplicates(List L)
{
	List newHead = (List *)malloc(sizeof(List));
	List pre = (List *)malloc(sizeof(List));
	List cur = (List *)malloc(sizeof(List));
	newHead->Next = L;
	pre = newHead;
	cur = L;

	while (cur != NULL)
	{
		if (pre->Next->Element == cur->Next->Element)
		{
			while (cur != NULL && pre->Next->Element == cur->Next->Element)
			{
				cur = cur->Next;
			}
			pre->Next = cur->Next;
		}
		else
		{
			pre = cur;
			cur = cur->Next;
		}
		return newHead->Next;


	}

}
int main()
{
	List Node1 = (List *)malloc(sizeof(List));
	List Node2 = (List *)malloc(sizeof(List));
	List Node3 = (List *)malloc(sizeof(List));
	List Node4 = (List *)malloc(sizeof(List));
	List MyList = (List *)malloc(sizeof(List));
	List Head = (List *)malloc(sizeof(List));
	Head->Next = MyList;
	MyList->Element = 1;
	Node1->Element = 1;
	MyList->Next = Node1;
	Node2->Element = 1;
	Node1->Next = Node2;
	Node2->Next = Node3;
	Node3->Element = 2;
	Node3->Next = Node4;
	Node4->Element = 3;
	Node4->Next = NULL;
	printf("%d %d %d %d %d\n", MyList->Element, MyList->Next->Element, MyList->Next->Next->Element, MyList->Next->Next->Next->Element, MyList->Next->Next->Next->Next->Element);
	List NewList = Duplicates(MyList);
	printf("%d %d\n", NewList->Element, NewList->Next->Element);

	system("pause");

}
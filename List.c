#include "List.h"
#include <stdio.h>

struct Node
{
	int Element;
	Position Next;
};

int IsEmpty(List L)
{
	return L->Next == NULL;
}

void Insert(int x, List L, Position P)
{
	Position TmpCell;
	TmpCell = malloc(sizeof(struct Node));
	if (TmpCell == NULL)
		printf("Out of space");
	TmpCell->Element = x;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}

Position Find(int x, List L)
{
	Position P;
	P = L->Next;
	while (P != NULL && P->Element != x)
		P = P->Next;

	return P;
}
int IsLast(Position P, List L)
{
	return P->Next == NULL;
}

Position FindPrevious(int x, List L)
{
	Position P;
	P = L;
	while (P->Next != NULL && P->Next->Element != x)
		P = P->Next;
	return P;
}
void Delete(int x, List L)
{
	Position P, TmpCell;
	P = FindPrevious(x, L);
	if (! IsLast(P, L))
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
}

int main()
{
	List MyList = NULL;
	MyList = (List *)malloc(sizeof(List));
	if (MyList == NULL)
	{
		printf("malloc fair!");
	}
	memset(MyList, 0, sizeof(List));
	MyList->Element = 100;
	MyList->Next = NULL;
	printf("%d\n %d\n", MyList->Element, IsEmpty(MyList));
	Insert(50, MyList, MyList);
	Position P = MyList->Next;
	Insert(10, MyList, P);
	printf("%d\n %d\n %d\n %d\n", MyList->Element, MyList->Next->Element, MyList->Next->Next->Element,IsEmpty(MyList));

	Position Pfind = Find(50, MyList);
	printf("%d\n", Pfind->Element);

	Delete(10, MyList);
	Delete(50, MyList);
	printf("%d\n", IsEmpty(MyList));

	system("pause");
}
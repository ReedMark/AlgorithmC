#include "List.h"
#include <stdio.h>

struct Node
{
	int Element;
	Position Next;
};
 
void PrintNode(List L)
{
	while (L->Next != NULL)
	{
		L = L->Next;    //L是表头没有数据，故要从下一个数据读取, 判断时也要从L->Next开始
		printf("%d ", L->Element);
	}
	printf("\n");
}

List CreatNode(int x, List L)
{
	Position NewNode = malloc(sizeof(Position));
	NewNode->Element = x;
	L->Next = NewNode;
	return L;
}

List InterSect(List L1, List L2)
{
	L1 = L1->Next;
	L2 = L2->Next;
	List Result = malloc(sizeof(List));
	List Tmp = malloc(sizeof(List));
	Tmp = Result;
	while (L1 != NULL && L2 != NULL)
	{
		if (L1->Element < L2->Element)
		{
			L1 = L1->Next;
		}
		else if (L1->Element > L2->Element)
		{
			L2 = L2->Next;
		}
		else
		{
			Tmp->Next = L1;
			Tmp = Tmp->Next;
			L1 = L1->Next;
			L2 = L2->Next;
		}
	}
	return Result;
}


int main()
{
	List L1 = malloc(sizeof(List)); //L1作为表头，不存放数据
	List L2 = malloc(sizeof(List));
	List Tmp = malloc(sizeof(List));
	List Result_InterSect;
	int a[6] = { 0,1,2,3,4,6};
	int b[6] = { 0,2,4,6,9,10};
	int i = 0;
	Tmp = L1;
	for (; i < sizeof(a) / sizeof(int); i++)
	{
		Tmp = CreatNode(a[i], Tmp);
		Tmp = Tmp->Next;
	}
	Tmp->Next = NULL;
	PrintNode(L1);
	Tmp = L2;
	i = 0;
	for (; i < sizeof(b) / sizeof(int); i++)
	{
		Tmp = CreatNode(b[i], Tmp);
		Tmp = Tmp->Next;
	}
	Tmp->Next = NULL;
	PrintNode(L2);
	Result_InterSect = InterSect(L1, L2);
	PrintNode(Result_InterSect);
	system("pause");
}
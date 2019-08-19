#include"UnionList.h"
#include<stdio.h>

struct Node
{
	int Element;
	Position Next;
};

List Union(List L1, List L2)
{
	L1 = L1->Next;
	L2 = L2->Next;
	List Result_Union = malloc(sizeof(List));
	List Tmp = malloc(sizeof(List));
	Tmp = Result_Union;
	while (L2 != NULL && L1 != NULL)
	{
		if (L1->Element < L2->Element)
		{
			Tmp->Next = L1;
			Tmp = Tmp->Next;
			L1 = L1->Next;
		}
		else if (L1->Element > L2->Element)
		{
			Tmp->Next = L2;
			Tmp = Tmp->Next;
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
	if (L1 != NULL)
	{
		Tmp->Next = L1;
		L1 = L1->Next;
	}
	
	if (L2 != NULL)
	{
		Tmp->Next = L2;
		L2 = L2->Next;
	}
	return Result_Union;
}


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
int main()
{
	List L1 = malloc(sizeof(List)); //L1作为表头，不存放数据
	List L2 = malloc(sizeof(List));
	List Tmp = malloc(sizeof(List));
	List Result_Union;
	int a[6] = { 0,1,4,5,8,10 };
	int b[6] = { 2,3,4,6,7,9 };
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
	Result_Union = Union(L1, L2);
	PrintNode(Result_Union);
	system("pause");
}
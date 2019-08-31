#include"Tree.h"
#include<stdio.h>

struct TreeNode
{
	int Element;
	SearchTree Left;
	SearchTree Right;
};

SearchTree MakeEmpty(SearchTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

Position Find(int x, SearchTree T)
{
	if (T == NULL)
		return NULL;
	if (T->Element > x)
		return Find(x, T->Left);
	else if (T->Element < x)
		return Find(x, T->Right);
	else
		return T;
}
Position FindMin(SearchTree T)
{
	if (T == NULL)
		return NULL;
	else if (T->Left == NULL)
		return T;
	else
		return FindMin(T->Left);
}

Position FindMax(SearchTree T)
{
	if (T != NULL)
	{
		while (T->Right != NULL)
			T = T->Right;
	}
	return T;
}
SearchTree Insert(int x, SearchTree T)
{
	if (T == NULL)
	{
		T = malloc(sizeof(struct TreeNode));
		if (T == NULL)
			printf("Out of space");
		else
		{
			T->Element = x;
			T->Left = T->Right = NULL;
		}
	}
	else if (x < T->Element)
		T->Left = Insert(x, T->Left);
	else if (x > T->Element)
		T->Right = Insert(x, T->Right);
	return T;
}

SearchTree Delete(int x,SearchTree T)
{
	Position TmpCell;
	if (T == NULL)
		printf("Element not found");
	else if (x < T->Element)
		T->Left = Delete(x, T->Left);
	else if (x > T->Element)
		T->Right = Delete(x, T->Right);
	else if (T->Left&&T->Right)
	{
		TmpCell = FindMin(T->Right);
		T->Element = TmpCell->Element;
		T->Right = Delete(T->Element, T->Right);
	}
	else
	{
		TmpCell = T;
		if (T->Left == NULL)
			T = T->Right;
		else if (T->Right == NULL)
			T = T->Left;
		free(TmpCell);
	}
	return T;
}

SearchTree CreateNode(int x1,int x2, SearchTree T)
{
	SearchTree LeftNode = malloc(3*sizeof(SearchTree));
	SearchTree RightNode = malloc(3*sizeof(SearchTree));

	LeftNode->Element = x1;
	RightNode->Element = x2;
	T->Left = LeftNode;
	T->Left->Left = NULL;
	T->Left->Right = NULL;
	T->Right = RightNode;
	T->Right->Right = NULL;
	T->Right->Left = NULL;
	return T;

}

int main()
{
	SearchTree T = malloc(3*sizeof(SearchTree));
	T->Element = 6;
	T = CreateNode(2, 8, T);
	SearchTree Tmp = T->Left;
	Tmp = CreateNode(1, 4, Tmp);
	printf("%d %d %d %d %d\n", T->Element, T->Left->Element, T->Right->Element, T->Left->Left->Element,T->Left->Right->Element);
	//T = Find(4, T);
	//printf("%d\n", T->Element);
	Position Min = FindMin(T);
	printf("%d\n", Min->Element);
	Position Max = FindMax(T);
	printf("%d\n", Max->Element);
	T = Insert(5, T);
	printf("%d %d %d %d %d %d\n", T->Element, T->Left->Element, T->Right->Element, T->Left->Left->Element, T->Left->Right->Element,T->Left->Right->Right->Element);

	getchar();
}
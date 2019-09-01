#include"AVLTree.h"
#include<stdio.h>
#include"Stack.h"

struct AVLNode
{
	int Element;
	AVLTree Left;
	AVLTree Right;
	int height;
};

AVLTree MakeEmpty(AVLTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
}
Position Find(int x, AVLTree T)
{
	if (T == NULL)
		return NULL;
	if (x < T->Element)
		return Find(x, T->Left);
	else if (x > T->Element)
		return Find(x, T->Right);
	else
		return T;
}
Position FindMin(AVLTree T)
{
	if (T == NULL)
		return NULL;
	else if (T->Left == NULL)
		return T;
	else
		return FindMin(T->Left);
}
Position FindMax(AVLTree T)
{
	if (T == NULL)
		return NULL;
	else if (T->Right == NULL)
		return T;
	else
		return FindMax(T->Right);
}
static int Height(Position P)
{
	if (P == NULL)
		return P;
	else
		return P->height;
}
int Max(int x1, int x2)
{
	if (x1 > x2)
		return x1;
	else
		return x2;
}

/*AVLTree Insert(int x, AVLTree T)
{
	if (T == NULL)
	{
		T = malloc(sizeof(struct AVLNode));
		if (T == NULL)
			printf("Error");
		else
		{
			T->Element = x;
			T->Left = T->Right = NULL;
		}
	}
	else if (x < T->Element)
	{
		T->Left = Insert(x, T->Left);
		if (Height(T->Left) - Height(T->Right) == 2)
			if (x < T->Left->Element)
				T = SingleRotateWithLeft(T);
			else
				T = DoubleRotateWithLeft(T);
	}
	else if (x > T->Element)
	{
		T->Right = Insert(x, T->Right);
		if (Height(T->Right) - Height(T->Left) == 2)
			if (x > T->Right->Element)
				T = SingleRotateWithRight(T);
			else
				T = DoubleRotateWithRight(T);
	}
	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
	return T;
}*/
AVLTree Insert(int x, AVLTree T)
{
	Stack stack = CreateStack(100);
	AVLTree root = T;
	while (1)
	{
		if (T == NULL)
		{
			T = malloc(sizeof(struct AVLNode));
			if (T == NULL)
				printf("Error");
			else
			{
				T->Element = x;
				T->Left = T->Right = NULL;
				T->height = 0;
				Push(T, stack);
				break;
			}
		}
		else if (x < T->Element)
		{
			Push(T, stack);
			T = T->Left;
			continue;
		}
		else if (x > T->Element)
		{
			Push(T, stack);
			T = T->Right;
			continue;
		}
		else
			return root;
	}
	AVLTree father, son;
	while (1)
	{
		son = Top(stack);
		Pop(stack);
		if (IsEmpty(stack))
			return son;
		father = Top(stack);
		Pop(stack);
		if (father->Element < son->Element)
		{
			father->Right = son;
			if (Height(father->Right) - Height(father->Left) == 2)
			{
				if (x > father->Right->Element)
					father = SingleRotateWithRight(father);
				else
					father = DoubleRotateWithRight(father);
			}
			Push(father, stack);
		}
		else if (father->Element > son->Element)
		{
			father->Left = son;
			if (Height(father->Left) - Height(father->Right) == 2)
			{
				if (x < father->Left->Element)
					father = SingleRotateWithLeft(father);
				else
					father = DoubleRotateWithLeft(father);
			}
			Push(father, stack);
		}
		father->height = Max(Height(father->Left), Height(father->Right)) + 1;
	}

}

static Position SingleRotateWithLeft(Position K2)
{
	Position K1;
	K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;
	K2->height = Max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->height = Max(Height(K1->Left), K2->height) + 1;
	return K1;
}
static Position SingleRotateWithRight(Position K1)
{
	Position K2;
	K2 = K1->Right;
	K1->Right = K2->Left;
	K2->Left = K1;
	K1->height = Max(Height(K2->Left), Height(K2->Right)) + 1;
	K2->height = Max(Height(K1->Right), K2->height) + 1;
	return K2;
}
static Position DoubleRotateWithLeft(Position K1)
{
	
	K1->Left = SingleRotateWithLeft(K1->Left);
	return SingleRotateWithLeft(K1);
}
static Position DoubleRotateWithRight(Position K3)
{
	K3->Right = SingleRotateWithRight(K3->Right);
	return SingleRotateWithRight(K3);
}
AVLTree Delete(int x, AVLTree T)
{
	Position TmpCell;
	if (T == NULL)
		printf("Error");
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
AVLTree CreateNode(int x)
{	
	AVLTree TmpCell = malloc(sizeof(struct AVLNode));
	TmpCell->Element = x;
	TmpCell->Left = TmpCell->Right = NULL;
	return TmpCell;
}

void PrintTree(AVLTree T)
{
	if (T != NULL)
	{
		PrintTree(T->Left);
		printf("%d ", T->Element);
		PrintTree(T->Right);
	}
}

int main()
{
	AVLTree T = malloc(sizeof(struct AVLNode));
	T->Element = 5;
	T->Left = CreateNode(2);
	T->Right = CreateNode(8);
	T->Left->Left = CreateNode(1);
	T->Left->Right = CreateNode(4);
	T->Right->Left = CreateNode(7);
	T->Left->Right->Left = CreateNode(3);
	Insert(6, T);
	PrintTree(T);
	getchar();

}




#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#define MinStackSize 5

struct StackRecord
{
	int Capacity;
	int TopOfStack;
	AVLTree *Array;
};
void MakeEmptyStack(Stack S)
{
	S->TopOfStack = -1;
}
int IsFull(Stack S)
{
	return S->TopOfStack == S->Capacity - 1;

}
int IsEmpty(Stack S)
{
	return S->TopOfStack == -1;
}

Stack CreateStack(int MaxElement)
{
	Stack S;
	if (MaxElement < MinStackSize)
		printf("Stack size is too small");
	S = malloc(sizeof(struct StackRecord));
	if (S == NULL)
		printf("Out of Space");
	S->Array = malloc(sizeof(int)*MaxElement);
	if (S->Array == NULL)
		printf("Out of Space");
	S->Capacity = MaxElement;
	MakeEmptyStack(S);
	return S;

}
void Push(AVLTree X, Stack S)
{
	if (IsFull(S))
		printf("Full Stack");
	else
		S->Array[++S->TopOfStack] = X;
}
void Pop(Stack S)
{
	if (IsEmpty(S))
		printf("Empty Stack");
	else
		return S->TopOfStack--;
}
AVLTree Top(Stack S)
{
	if (S == NULL)
		return NULL;
	else
		return S->Array[S->TopOfStack];
}

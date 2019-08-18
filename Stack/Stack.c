#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include "error.h"
#define MinStackSize 5

struct StackRecord
{
	int Capacity;
	int TopOfStack;
	int *Array;
};
void MakeEmpty(Stack S)
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
		Error("Stack size is too small");
	S = malloc(sizeof(struct StackRecord));
	if (S == NULL)
		FatalError("Out of Space");
	S->Array = malloc(sizeof(int)*MaxElement);
	if (S->Array == NULL)
		FatalError("Out of Space");
	S->Capacity = MaxElement;
	MakeEmpty(S);
	return S;

}
void Push(int X, Stack S)
{
	if (IsFull(S))
		Error("Full Stack");
	else
		S->Array[++S->TopOfStack] = X;
}
void Pop(Stack S)
{
	if (IsEmpty(S))
		Error("Empty Stack");
	else
		S->TopOfStack--;
}

int main()
{
	Stack MyStack = CreateStack(10);
	printf("%d\n", IsEmpty(MyStack));
	Push(1, MyStack);
	Push(2, MyStack);
	printf("%d %d\n", MyStack->Array[MyStack->TopOfStack - 1], MyStack->Array[MyStack->TopOfStack]);
	system("pause");
}
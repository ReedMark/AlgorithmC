#include "Queue.h"
#include <stdio.h>

struct QueueRecord
{
	int CapaCity;
	int Front;
	int Rear;
	int Size;
	int *Array;
};

int IsEmpty(Queue Q)
{
	return Q->Size == 0;
}

int IsFull(Queue Q)
{
	return Q->Size == Q->CapaCity;
}
void MakeEmpty(Queue Q)
{
	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0; //队头在队尾右边，表示空
}

static int Succ(int Value, Queue Q)
{
	if (++Value == Q->CapaCity)
		Value = 0;
	return Value;
}

Queue CreatQueue(int MaxElement)
{
	Queue Q = malloc(sizeof(Queue));
	Q->CapaCity = MaxElement;
	MakeEmpty(Q);
	return Q;
}

void EnQueue(int x, Queue Q)
{
	if (IsFull(Q))
		printf("Full Queue");
	else
	{
		Q->Size++;
		Q->Rear = Succ(Q->Rear, Q);
		Q->Array[Q->Rear] = x;
	}
}

int main()
{
	Queue Q = CreatQueue(5);
	Q->Array = malloc(sizeof(int) * Q->CapaCity);
	EnQueue(1, Q);
	EnQueue(4, Q);
	EnQueue(0, Q);
	printf("%d %d %d\n", Q->Array[Q->Front], Q->Array[Q->Rear], Q->Size);
	system("pause");
}

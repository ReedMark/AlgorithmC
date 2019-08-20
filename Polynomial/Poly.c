#include "Poly.h"
#include <stdio.h>
struct Node
{
	float c;
	int e;
	Poly next;
};

Poly CreateNode(Poly P, float c, int e)
{
	Poly NewNode = malloc(sizeof(Poly)*2); // ��������ڴ���Ҫ*2�����������ڴ����� 
	NewNode->c = c;						   // Poly�ǽṹ��ָ�룬���СΪ4��������ṹ������float��int��������������ռ4�ֽ�
	NewNode->e = e;
	P->next = NewNode;
	return P;
}

Poly CreatePoly(Poly P, float c[], int e[], int n)
{
	Poly Tmp1 = malloc(sizeof(Poly));
	Tmp1 = P;
	int i = 0;
	for (; i < n; i++)    //��������������n��ֱ����sizeof�������޷�ʵ�֣�ԭ����ʱ����
	{
		Tmp1 = CreateNode(Tmp1, c[i], e[i]);
		Tmp1 = Tmp1->next;
	}
	Tmp1->next = NULL;
	return P;
	
}

/*Poly InSertSortList(Poly P)
{
	Poly prep1, p1, prep2, p2, tmp;
	prep1 = P->next;
	p1 = prep1->next;
	int flag;
	while (p1 != NULL)
	{
		flag = 1;
		tmp = p1;
		for (prep2 = P, p2 = prep2->next; p2 != p1; prep2 = prep2->next, p2 = p2->next)
		{
			if (p2->e > p1->e)
			{
				p1 = p1->next;
				prep1->next = p1;
				prep2->next = tmp;
				tmp->next = p2;
				flag = 0;
				break;
			}

		}
		if (flag)
		{
			prep1 = prep1->next;
			p1 = p1->next;
		}
	}
}*/

Poly InSertSortList(Poly P)
{
	Poly p1, p2, tmp;
	p1 = P->next;
	p2 = P;
	while (p1->next != NULL)
	{
		tmp = p1;
		for (p2 = P; p2 != p1; p2 = p2->next)
		{
			if (p2->next->e > p1->next->e)  //�ǰ�����е�e�Ĵ�С���ȵ�
			{
				p1 = p1->next;
				tmp->next = p1->next;
				p1->next = p2->next;
				p2->next = p1;
				break;
			}
		}
			p1 = p1->next;

	}
	
}

void PrintList(Poly P)
{
	while (P->next != NULL)
	{
		P = P->next;
		printf("%.2f*X^%d", P->c, P->e); //���������һ��Ҫƥ����У��������ֶϵ�
		if(P->next!=NULL)
			printf("+");
	}
	printf("\n");
}

Poly AddPoly(Poly P1, Poly P2)
{
	Poly SumPoly = malloc(sizeof(Poly) * 2);
	Poly Tmp = SumPoly;
	P1 = P1->next;
	P2 = P2->next;
	while (P1 != NULL && P2!=NULL)
	{
		if (P1->e < P2->e)
		{
			Tmp = CreateNode(Tmp, P1->c, P1->e);
			Tmp = Tmp->next;
			P1 = P1->next;
		}
		else if (P1->e > P2->e)
		{
			Tmp = CreateNode(Tmp, P2->c, P2->e);
			Tmp = Tmp->next;
			P2 = P2->next;
		}
		else
		{
			Tmp = CreateNode(Tmp, P1->c + P2->c, P1->e);
			Tmp = Tmp->next;
			P1 = P1->next;
			P2 = P2->next;
		}                //����ʹ�ô����ڵ��������Ľ��Ͳ�ʱ��ָ��ԭ���Ľڵ�Ч������ͬ��
	}
	Tmp->next = NULL;   //���һ��Ҫ�ýڵ�ָ��NULL�������ڴ�ӡʱ��������ѭ��
	return SumPoly;
}

int main()
{
	Poly PHead1 = (Poly *)malloc(sizeof(Poly));
	Poly PHead2 = (Poly *)malloc(sizeof(Poly));
	Poly Result = malloc(sizeof(Poly));
	float c[] = { 1.0,2.0,4.0,5,2};
	int e[] = { 2,4,5,1,4};
	int n = sizeof(e) / sizeof(int);
	CreatePoly(PHead1,c,e,n);
	printf("----------��һ������ʽ����Ϊ----------\n");
	PrintList(PHead1);
	printf("\n");
	float c2[] = { 2,5,6,4 };
	int e2[] = { 4,5,1,3 };
	int n2 = sizeof(e2) / sizeof(int);
	CreatePoly(PHead2, c2, e2, n2);
	printf("----------�ڶ�������ʽ����Ϊ----------\n");
	PrintList(PHead2);
	printf("\n");
	InSertSortList(PHead1);
	printf("----------������һ������ʽ����Ϊ------------\n");
	PrintList(PHead1);
	printf("\n");
	InSertSortList(PHead2);
	printf("----------�����ڶ�������ʽ����Ϊ------------\n");
	PrintList(PHead2);
	printf("\n");
	Result = AddPoly(PHead1, PHead2);
	printf("----------��Ӻ�Ķ���ʽ����Ϊ----------------\n");
	PrintList(Result);
	getchar();

}

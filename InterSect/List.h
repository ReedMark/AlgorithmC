struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

void PrintNode(List L);
List CreatNode(int x, List L);
List InterSect(List L1, List L2); //˼·�����������������1<2��1��λ�ü�һ�����1>2��2��λ�ü�1�����������������������ȵ�ֵ

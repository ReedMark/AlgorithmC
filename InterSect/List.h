struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

void PrintNode(List L);
List CreatNode(int x, List L);
List InterSect(List L1, List L2); //思路：遍历两个链表，如果1<2则1的位置加一，如果1>2则2的位置加1，若相等则在新链表后插入相等的值

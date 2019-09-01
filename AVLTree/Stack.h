#include"AVlTree.h"
struct StackRecord;
typedef struct StackRecord *Stack;

int IsEmpty(Stack S);
Stack CreateStack(int MaxElements);
void Push(AVLTree Element, Stack S);
AVLTree Top(Stack S);
void Pop(Stack S);
int IsFull(Stack S);

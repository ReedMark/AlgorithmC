struct StackRecord;
typedef struct StackRecord *Stack;

int IsEmpty(Stack S);
Stack CreateStack(int MaxElements);
void Push(int Element, Stack S);
int Top(Stack S);
void Pop(Stack S);
void MakeEmpty(Stack S);
int IsFull(Stack S);

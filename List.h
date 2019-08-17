struct Node; //结构体Node，里面有int型数据和指向结构体的指针类型Position
typedef struct Node *PtrToNode; //表明Node和指针类型等价，根据链表图来理解
typedef PtrToNode List;
typedef PtrToNode Position;

int IsEmpty(List L);
void Insert(int X, List L, Position P);
Position Find(int x, List L);
void Delete(int x, List L);
Position FindPrevious(int x, List L);
int IsLast(Position P, List L);
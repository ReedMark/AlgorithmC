struct Node; //�ṹ��Node��������int�����ݺ�ָ��ṹ���ָ������Position
typedef struct Node *PtrToNode; //����Node��ָ�����͵ȼۣ���������ͼ�����
typedef PtrToNode List;
typedef PtrToNode Position;

int IsEmpty(List L);
void Insert(int X, List L, Position P);
Position Find(int x, List L);
void Delete(int x, List L);
Position FindPrevious(int x, List L);
int IsLast(Position P, List L);
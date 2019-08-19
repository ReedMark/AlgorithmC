
struct QueueRecord;
typedef struct QueueRecord *Queue;

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreatQueue(int MaxElement);
void MakeEmpty(Queue Q);
void EnQueue(Queue Q, int x);
void DeQueue(Queue Q);


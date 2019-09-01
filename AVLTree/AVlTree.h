#ifndef __AVLTree_H

struct AVLNode;
typedef struct AVLNode *Position;
typedef struct AVLNode *AVLTree;

AVLTree MakeEmpty(AVLTree T);
Position Find(int x, AVLTree T);
Position FindMin(AVLTree T);
Position FindMax(AVLTree T);
AVLTree Insert(int x, AVLTree T);
AVLTree Delete(int x, AVLTree T);
int Retrieve(Position P);
static Position SingleRotateWithLeft(Position K2);
static Position SingleRotateWithRight(Position K1);
static Position DoubleRotateWithLeft(Position K3);
static Position DoubleRotateWithRight(Position K1);

void PrintTree(AVLTree T);
#endif
#ifndef __Tree_H

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(int x, SearchTree T);
Position FindMax(SearchTree T);
Position FindMin(SearchTree T);
SearchTree Insert(int x, SearchTree T);
SearchTree Delete(int x, SearchTree T);
int Retrieve(Position P);

#endif
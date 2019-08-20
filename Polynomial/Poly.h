struct Node;
typedef struct Node *PolyNode;
typedef PolyNode Poly;

Poly CreatePoly(Poly P, float c[], int e[], int n);
void PrintList(Poly P);
Poly CreateNode(Poly P, float c, int e);
Poly InSertSortList(Poly P);
Poly AddPoly(Poly P1, Poly P2);

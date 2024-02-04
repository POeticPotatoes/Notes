#import <stdio.h>
#import <stdlib.h>

const int MAX_N = 31;

enum GraphType { ADJ_MATRIX , ADJ_LIST }; // Types of Graph Representation

typedef struct _listnode {
    int vertex ;
    struct _listnode * next ;
} ListNode ;

union GraphForm {
    int * matrix ;
    ListNode ** list ;
};

typedef struct _graph {
    int V;
    int E;
    enum GraphType type ;
    union GraphForm adj ;
} Graph ;

void BFS(Graph g, int v);

int main() {
    int n;
    scanf("%d", &n);
    if (n>MAX_N) {
        printf("n exceeds max allowed size!\n");
        return 0;
    }
    ListNode **list = (ListNode**) malloc(sizeof(ListNode (*) )*n);
    Graph A = {n, 0, ADJ_LIST, {.list=list}};
    
    char S[MAX_N];
    for (int i=0;i<n;i++) {
        scanf("%s", S);
        int size = 0;
        ListNode *head = NULL;
        for (int j=n;j--;) if (S[j]-'0') {
            ListNode *e = (ListNode*) malloc(sizeof(ListNode));
            e->vertex = j;
            e->next = head;
            head = e;
            A.E++;
        }
        A.adj.list[i] = head;
    }
    
    // Check if it works
    for (int i=0;i<n;i++) {
        printf("%d: ", i);
        for (ListNode *t = A.adj.list[i];t;t = t->next) printf("%d ", t->vertex);
        printf("\n");
    }

    printf("\nConverting to adjacency matrix\n");
    int *matrix = (int*) malloc(sizeof(int)*n);
    Graph B = {A.V, A.E, ADJ_MATRIX, {.matrix = matrix}};
    for (int i=0;i<n;i++) {
        int row = 0;
        for (ListNode *t = A.adj.list[i];t;t=t->next) row += 1<<t->vertex;
        B.adj.matrix[i] = row;
    }

    // Check if it works
    for (int i=0;i<n;i++) {
        printf("%d: ", i);
        for (int j=0;j<n;j++) printf("%d", (B.adj.matrix[i]>>j)&1);
        printf("\n");
    }

    printf("\nDegree of nodes:\n");
    for (int i=0;i<n;i++) {
        int d1=0, d2=0;
        for (ListNode *t = A.adj.list[i];t;t=t->next, d1++);
        for (int j=0;j<n;j++) d2 += B.adj.matrix[i]>>j&1;
        printf("%d: list: %d matrix: %d\n", i, d1, d2);
    }

    BFS(A, 0);
}

void BFS(Graph g, int v) {
    // creating a stack like a normal person
    printf("\nBFS: ");
    int stack[MAX_N*10], *p = stack+1;
    int vis[MAX_N] = {};
    while (p>stack) {
        int v = *--p;
        if (vis[v]) continue;
        printf("%d ", v);
        vis[v] = 1;
        for (ListNode *t = g.adj.list[v];t;t=t->next) *p++ = t->vertex;
    }
    printf("\n");
}

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
void DFS(Graph g, int v);

ListNode *insertSorted(ListNode *n, int v) {
    ListNode *k = (ListNode*) calloc(1, sizeof(ListNode));
    k->vertex = v;
    if (!n) return k;
    if (n->vertex<v) {
        k->next = n;
        return k;
    }
    ListNode *t = n;
    while (t->next && t->next->vertex>v) t = t->next;
    k->next = t->next;
    t->next = k;
    return n;
}

int main() {
    int n;
    scanf("%d", &n);
    if (n>MAX_N) {
        printf("n exceeds max allowed size!\n");
        return 0;
    }
    ListNode **list = (ListNode**) calloc(n, sizeof(ListNode*));
    Graph A = {n, 0, ADJ_LIST, {.list=list}};
    
    int a, b;
    while (scanf("%d%d", &a, &b) == 2) {
        a--, b--;
        A.E++;
        A.adj.list[a] = insertSorted(A.adj.list[a], b);
        A.adj.list[b] = insertSorted(A.adj.list[b], a);
    }
    
    // Check if it works
    for (int i=0;i<n;i++) {
        printf("%d: ", i);
        for (ListNode *t = A.adj.list[i];t;t = t->next) printf("%d ", t->vertex);
        printf("\n");
    }

    DFS(A, 10);
    printf("\n");
}

typedef struct _q {
    int size;
    ListNode *start, *end;
} queue;

void push(queue *q, int v) {
    ListNode *n = (ListNode*) malloc(sizeof(ListNode));
    n->vertex = v;
    n->next = NULL;
    if (q->size++) q->start->next = n;
    else q->end = n;
    q->start = n;
}

int pop(queue *q) {
    q->size--;
    ListNode *t = q->end;
    q->end = t->next;
    int v = t->vertex;
    free(t);
    return v;
}

void ps(int *p, int *s) {
    while (--p >= s) printf("%d ", *p+1);
    printf("\n");
}

void DFS(Graph g, int v) {
    int *stack = (int*) malloc(sizeof(int)*g.V), *p = stack;
    *p++ = v;
    int *vis = (int*) calloc(g.V, sizeof(int));
    while (p>stack) {
        int v = *--p;
        printf("? %d\n", v+1);
        if (vis[v]==1) {
            printf("Visited %d\n", v+1);
            ps(p, stack);
            continue;
        }
        *p++ = v;
        vis[v] = 1;
        for (ListNode *t = g.adj.list[v];t;t=t->next)
            if (!vis[t->vertex]) *p++ = t->vertex;
    }
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

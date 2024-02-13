#include<stdio.h>
#include <stdlib.h>
  
int* city_population (int N, int* population, int** road, int Q, int** cities) ;

int main() {
    int N;
    scanf("%d", &N);
    int i_population;
    int *population = (int *)malloc(sizeof(int)*(N));
    for(i_population = 0; i_population < N; i_population++)
    	scanf("%d", &population[i_population]);
    int i_road, j_road;
    int **road = (int **)malloc((N-1)*sizeof(int *));
    for(i_road = 0; i_road < N-1; i_road++)
    {
    	road[i_road] = (int *)malloc((2)*sizeof(int));
    }
    for(i_road = 0; i_road < N-1; i_road++)
    {
    	for(j_road = 0; j_road < 2; j_road++)
    	{
    		scanf("%d", &road[i_road][j_road]);
    	}
    }
    int Q;
    scanf("%d", &Q);
    int i_cities, j_cities;
    int **cities = (int **)malloc((Q)*sizeof(int *));
    for(i_cities = 0; i_cities < Q; i_cities++)
    {
    	cities[i_cities] = (int *)malloc((3)*sizeof(int));
    }
    for(i_cities = 0; i_cities < Q; i_cities++)
    {
    	for(j_cities = 0; j_cities < 3; j_cities++)
    	{
    		scanf("%d", &cities[i_cities][j_cities]);
    	}
    }

    int* out_ = city_population(N, population, road, Q, cities);
    printf("%d", out_[0]);
    int i_out_;
    for(i_out_ = 1; i_out_ < Q; i_out_++)
    	printf("\n%d", out_[i_out_]);
}


typedef struct _v{
    int size;
    int depth;
    int parent;
    int *get;
} vertex;

int* city_population (int N, int* population, int** road, int Q, int** cities) 
{
    vertex *adj = (vertex*) calloc(N+1, sizeof(vertex)*(N+1));
    int *e = (int*) malloc(sizeof(int)*(N+1));
    for (int i=0;i<N-1;i++) {
        e[road[i][0]]++;
        e[road[i][1]]++;
    }

    for (int i=0;i<N-1;i++) {
        int a = road[i][0], b = road[i][1];
        if (!adj[a].size) adj[a].get = (int*) malloc(sizeof(int)*e[a]);
        if (!adj[b].size) adj[b].get = (int*) malloc(sizeof(int)*e[b]);

        adj[a].get[adj[a].size++] = b;
        adj[b].get[adj[b].size++] = a;
    }

    // Perform DFS
    int *stack = (int*) malloc(sizeof(int)*(N+1)), *S = stack;
    adj[1].parent = 1, adj[1].depth=0;
    *S++ = 1;
    while (S>stack) {
        int k = *--S;
        for (int i=0;i<adj[k].size;i++) {
            int j = adj[k].get[i];
            if (j == adj[k].parent) continue;
            adj[j].parent = k;
            adj[j].depth = adj[k].depth+1;
            *S++ = j;
        }
    }
    int *ANS = (int*) malloc(sizeof(int)*Q);

    for (int t=0;t<Q;t++) {
        int v = cities[t][2], a, b;
        if (cities[t][0]>cities[t][1]) a = cities[t][1], b = cities[t][0];
        else a = cities[t][0], b = cities[t][1];
        
        int ans = 0;
        while (adj[b].depth>adj[a].depth) {
            ans += population[b-1] <= v;
            b = adj[b].parent;
        }
        while (a != b) {
            ans += population[a-1] <= v;
            ans += population[b-1] <= v;
            a = adj[a].parent;
            b = adj[b].parent;
        }
        ans += population[b-1] <= v;
        ANS[t] = ans;
    }
    return ANS;
}

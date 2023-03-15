#include <stdio.h>
#include <stdlib.h>

#define TABLESIZE 5
#define PRIME     3

enum Marker {EMPTY,USED,DELETED};

typedef struct _slot{
    int key;
    enum Marker indicator;
} HashSlot;

int HashInsert(int key, HashSlot hashTable[]);
int HashDelete(int key, HashSlot hashTable[]);


int hash1(int key);
int hash2(int key);

int main()
{
    int opt;
    int i;
    int key;
    int comparison;
    HashSlot hashTable[TABLESIZE];

    for(i=0;i<TABLESIZE;i++){
        hashTable[i].indicator = EMPTY;
        hashTable[i].key = 0;
    }

    scanf("%d",&opt);
    while(opt>=1 && opt <=3){
        switch(opt){
        case 1:
            scanf("%d",&key);
            comparison = HashInsert(key,hashTable);
            if(comparison <0)
                printf("%d Duplicate key\n", key);
            else if(comparison < TABLESIZE)
                printf("Insert: %d Key Comparisons: %d\n",key, comparison);
            else
                printf("Key Comparisons: %d. Table is full.\n",comparison);
            break;
        case 2:
            scanf("%d",&key);
            comparison = HashDelete(key,hashTable);
            if(comparison <0)
                printf("%d does not exist.\n", key);
            else if(comparison <= TABLESIZE)
                printf("Delete: %d Key Comparisons: %d\n",key, comparison);
            else
                printf("Error\n");
            break;
        case 3:
            for(i=0;i<TABLESIZE;i++) printf("%d: %d %c\n",i, hashTable[i].key,hashTable[i].indicator==DELETED?'*':' ');
            break;
        }
        scanf("%d",&opt);
    }
    return 0;
}

int hash1(int key)
{
    return ((key+TABLESIZE) % TABLESIZE);
}

int hash2(int key)
{
    return ((key+PRIME) % PRIME) + 1;
}

int HashInsert(int key, HashSlot hashTable[])
{
    int t=hash1(key), o = hash2(key), i=0, s, h;
    while (hashTable[t].indicator == USED) {
        if (i++ >= TABLESIZE) return TABLESIZE;
        if (hashTable[t].key == key) return -1;
        t = (t+o) % TABLESIZE;
    }
    h = t %TABLESIZE, s = i;
    while (hashTable[h].indicator != EMPTY) {
        if (s++ >= TABLESIZE) break;
        if (hashTable[h].indicator==USED && hashTable[h].key==key) return -1;
        h = (h+o) %TABLESIZE;
    }
    hashTable[t].key = key;
    hashTable[t].indicator = USED;
    return i;
}

int HashDelete(int key, HashSlot hashTable[])
{
    int t = hash1(key), o = hash2(key), i=0;
    while (hashTable[t].indicator != EMPTY) {
        if (i++ >= TABLESIZE) return -1;
        if (hashTable[t].indicator==USED && hashTable[t].key == key) {
            hashTable[t].indicator=DELETED;
            return i;
        }
        t = (t+o) % TABLESIZE;
    }
    return -1;
}

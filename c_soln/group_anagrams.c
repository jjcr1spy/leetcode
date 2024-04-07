//#include <stdlib.h>
//#include <string.h>
//#include "uthash.h" defines a map we can use 
#define MAX 100;

struct hash_map {
    char * key; 
    char ** words;
    int size;

    UT_hash_handle hh;
};

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmpfunc (const void * a, const void * b) {
   return (*(char*)a - *(char*)b );
}

char *** groupAnagrams(char ** strs, int strsSize, int * returnSize, int ** returnColumnSizes) {
    struct hash_map * m = NULL;

    for (int i = 0; i < strsSize; i++) {
        char * s = strdup(strs[i]); 

        qsort(strs[i], strlen(strs[i]), sizeof(char), &cmpfunc);

        struct hash_map * to_add = NULL;
        HASH_FIND_STR(m, strs[i], to_add); // since we are using a char * as key

        if (to_add == NULL) {
            to_add = (struct hash_map *) malloc(sizeof(struct hash_map));
            to_add->key = strs[i];
            to_add->size = 0;
            to_add->words = (char **) calloc(100, sizeof(char *));
            
            // since our key is stored elsewhere and not in struct itself
            HASH_ADD_KEYPTR(hh, m, to_add->key, strlen(to_add->key), to_add);
        } 

        to_add->words[to_add->size] = s;
        to_add->size++;
    }


    *returnSize = HASH_COUNT(m);
    printf("count %d\n", *returnSize);
    char *** soln = (char ***) malloc(*returnSize * sizeof(char **));
    int * column_sizes = (int *) malloc(*returnSize * sizeof(int));

    *returnColumnSizes = column_sizes;
    
    int i = 0;
    for (struct hash_map * key = m; key != NULL; key = key->hh.next, i++) {
        column_sizes[i] = key->size;
        soln[i] = key->words;
    }

    return soln;
}
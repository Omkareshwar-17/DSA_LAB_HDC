#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) return 0;

    int* hashTable = (int*)malloc(m * sizeof(int));
    int* occupied = (int*)calloc(m, sizeof(int));

    for (int k = 0; k < n; k++) {
        char op[10];
        int key;
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            int h = key % m;
            for (int i = 0; i < m; i++) {
                int pos = (h + i * i) % m;
                if (!occupied[pos]) {
                    hashTable[pos] = key;
                    occupied[pos] = 1;
                    break;
                }
            }
        } else if (strcmp(op, "SEARCH") == 0) {
            int h = key % m;
            int found = 0;
            for (int i = 0; i < m; i++) {
                int pos = (h + i * i) % m;
                if (!occupied[pos]) {
                    break;
                }
                if (hashTable[pos] == key) {
                    found = 1;
                    break;
                }
            }
            if (found) printf("FOUND\n");
            else printf("NOT FOUND\n");
        }
    }

    free(hashTable);
    free(occupied);
    return 0;
}
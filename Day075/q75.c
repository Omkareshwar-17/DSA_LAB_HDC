#include <stdio.h>
#include <stdlib.h>

// A simple hash map entry to store prefix sum and its first index
typedef struct {
    long long sum;
    int index;
} HashEntry;

// Hash function for handling negative sums
int getHash(long long sum, int m) {
    int h = sum % m;
    if (h < 0) h += m;
    return h;
}

int main() {
    int n;
    // Note: The problem asks for an array input. We'll read until EOF or size n.
    // For this implementation, we assume the number of elements is provided or detectable.
    int arr[100005];
    int i = 0;
    while (scanf("%d", &arr[i]) != EOF) {
        i++;
    }
    n = i;

    // Use a hash table with linear probing
    int tableSize = n * 2; 
    HashEntry* hashTable = (HashEntry*)malloc(tableSize * sizeof(HashEntry));
    int* occupied = (int*)calloc(tableSize, sizeof(int));

    long long prefixSum = 0;
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // Case 1: Prefix sum itself is 0
        if (prefixSum == 0) {
            maxLength = i + 1;
        }

        // Case 2: Check if prefixSum has been seen before
        int h = getHash(prefixSum, tableSize);
        int found = 0;
        int foundIndex = -1;

        while (occupied[h]) {
            if (hashTable[h].sum == prefixSum) {
                found = 1;
                foundIndex = hashTable[h].index;
                break;
            }
            h = (h + 1) % tableSize;
        }

        if (found) {
            int currentLen = i - foundIndex;
            if (currentLen > maxLength) {
                maxLength = currentLen;
            }
        } else {
            // Store the first occurrence of this prefix sum
            hashTable[h].sum = prefixSum;
            hashTable[h].index = i;
            occupied[h] = 1;
        }
    }

    printf("%d\n", maxLength);

    free(hashTable);
    free(occupied);
    return 0;
}
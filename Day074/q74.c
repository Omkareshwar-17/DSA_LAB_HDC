#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[105];
    int count;
} Candidate;

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    Candidate* votes = (Candidate*)malloc(n * sizeof(Candidate));
    int uniqueCount = 0;

    for (int i = 0; i < n; i++) {
        char currentName[105];
        scanf("%s", currentName);

        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(votes[j].name, currentName) == 0) {
                votes[j].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(votes[uniqueCount].name, currentName);
            votes[uniqueCount].count = 1;
            uniqueCount++;
        }
    }

    char* winName = votes[0].name;
    int maxVotes = votes[0].count;

    for (int i = 1; i < uniqueCount; i++) {
        if (votes[i].count > maxVotes) {
            maxVotes = votes[i].count;
            winName = votes[i].name;
        } else if (votes[i].count == maxVotes) {
            if (strcmp(votes[i].name, winName) < 0) {
                winName = votes[i].name;
            }
        }
    }

    printf("%s %d\n", winName, maxVotes);

    free(votes);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

// Comparator to sort intervals by start time
int compareIntervals(const void* a, const void* b) {
    Interval* i1 = (Interval*)a;
    Interval* i2 = (Interval*)b;
    if (i1->start != i2->start)
        return i1->start - i2->start;
    return i1->end - i2->end;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void mergeIntervals(Interval intervals[], int n) {
    if (n <= 0) return;

    // 1. Sort intervals based on start time
    qsort(intervals, n, sizeof(Interval), compareIntervals);

    // 2. Merge overlapping intervals
    int index = 0; // Index of the last merged interval

    for (int i = 1; i < n; i++) {
        // If current interval overlaps with the last merged interval
        if (intervals[index].end >= intervals[i].start) {
            // Merge them by updating the end time
            intervals[index].end = max(intervals[index].end, intervals[i].end);
        } else {
            // No overlap, move to the next index and update it
            index++;
            intervals[index] = intervals[i];
        }
    }

    // 3. Print the merged intervals
    for (int i = 0; i <= index; i++) {
        printf("[%d, %d]%c", intervals[i].start, intervals[i].end, (i == index) ? '\n' : ' ');
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    Interval* intervals = (Interval*)malloc(n * sizeof(Interval));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }

    mergeIntervals(intervals, n);

    free(intervals);
    return 0;
}
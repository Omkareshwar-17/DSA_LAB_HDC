#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

// Compare function to sort meetings by start time
int compareIntervals(const void* a, const void* b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

// Min-Heap functions for end times
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(int heap[], int size, int i) {
    int smallest = i;
    int l = 2 * i + 1, r = 2 * i + 2;
    if (l < size && heap[l] < heap[smallest]) smallest = l;
    if (r < size && heap[r] < heap[smallest]) smallest = r;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}

void push(int heap[], int* size, int val) {
    heap[(*size)++] = val;
    int curr = *size - 1;
    while (curr > 0 && heap[(curr - 1) / 2] > heap[curr]) {
        swap(&heap[curr], &heap[(curr - 1) / 2]);
        curr = (curr - 1) / 2;
    }
}

void pop(int heap[], int* size) {
    heap[0] = heap[--(*size)];
    minHeapify(heap, *size, 0);
}

int minMeetingRooms(Interval meetings[], int n) {
    if (n == 0) return 0;

    // 1. Sort meetings by start time
    qsort(meetings, n, sizeof(Interval), compareIntervals);

    // 2. Use a min-heap to store end times of meetings in progress
    int* minHeap = (int*)malloc(n * sizeof(int));
    int heapSize = 0;

    // Add the first meeting's end time
    push(minHeap, &heapSize, meetings[0].end);

    for (int i = 1; i < n; i++) {
        // If the room with the earliest end time is free, reuse it
        if (meetings[i].start >= minHeap[0]) {
            pop(minHeap, &heapSize);
        }
        
        // Add the current meeting's end time to the heap
        // (This either occupies a new room or re-occupies a vacated one)
        push(minHeap, &heapSize, meetings[i].end);
    }

    int result = heapSize;
    free(minHeap);
    return result;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    Interval* meetings = (Interval*)malloc(n * sizeof(Interval));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &meetings[i].start, &meetings[i].end);
    }

    printf("%d\n", minMeetingRooms(meetings, n));

    free(meetings);
    return 0;
}
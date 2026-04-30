#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    double time;
} Car;

// Sort cars by position in descending order (closest to target first)
int compareCars(const void* a, const void* b) {
    return ((Car*)b)->pos - ((Car*)a)->pos;
}

int countCarFleets(int target, int position[], int speed[], int n) {
    if (n == 0) return 0;

    Car* cars = (Car*)malloc(n * sizeof(Car));
    for (int i = 0; i < n; i++) {
        cars[i].pos = position[i];
        // time = (distance to target) / speed
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    // 1. Sort by position descending
    qsort(cars, n, sizeof(Car), compareCars);

    int fleets = 0;
    double currentTimeLimit = 0.0;

    // 2. Iterate through cars
    for (int i = 0; i < n; i++) {
        // If this car takes more time than the fleet in front, 
        // it cannot catch up. It starts a new fleet.
        if (cars[i].time > currentTimeLimit) {
            fleets++;
            currentTimeLimit = cars[i].time;
        }
        // If cars[i].time <= currentTimeLimit, it catches up
        // and joins the existing fleet.
    }

    free(cars);
    return fleets;
}

int main() {
    int target, n;
    if (scanf("%d %d", &target, &n) != 2) return 0;

    int* position = (int*)malloc(n * sizeof(int));
    int* speed = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) scanf("%d", &position[i]);
    for (int i = 0; i < n; i++) scanf("%d", &speed[i]);

    printf("%d\n", countCarFleets(target, position, speed, n));

    free(position);
    free(speed);
    return 0;
}
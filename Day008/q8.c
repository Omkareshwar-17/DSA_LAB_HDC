/*
Problem: Given integers a and b, compute a^b using recursion without using pow() function.

Input:
- Two space-separated integers a and b

Output:
- Print a raised to power b

Example:
Input:
2 5

Output:
32
*/

#include <stdio.h>

long long power(int a, int b) {
    if (b == 0) {
        return 1;
    }
    return a * power(a, b - 1);
}

int main() {
    int a, b;
    if (scanf("%d %d", &a, &b) != 2) {
        return 0;
    }

    if (b < 0) {
        printf("0\n"); 
    } else {
        printf("%lld\n", power(a, b));
    }

    return 0;
}
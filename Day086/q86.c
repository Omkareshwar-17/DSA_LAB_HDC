#include <stdio.h>

long long integerSquareRoot(long long n) {
    if (n < 2) return n;

    long long low = 0, high = n;
    long long ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        
        // Check for potential overflow by comparing mid with n/mid
        // instead of mid * mid with n
        if (mid == 0) {
            low = mid + 1;
            continue;
        }

        if (mid <= n / mid) { 
            // mid * mid <= n
            ans = mid;    // mid is a possible answer, try larger
            low = mid + 1;
        } else {
            // mid * mid > n
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    long long n;
    if (scanf("%lld", &n) != 1) return 0;

    if (n < 0) {
        // Square root of negative numbers is not defined in integers
        return 0;
    }

    printf("%lld\n", integerSquareRoot(n));

    return 0;
}
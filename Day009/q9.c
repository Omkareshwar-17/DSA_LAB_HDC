/*
Problem: A secret system stores code names in forward order. To display them 
in mirror format, you must transform the given code name so that its 
characters appear in the opposite order.

Input:
- Single line: a lowercase string containing only alphabetic characters

Output:
- Print the transformed code name after applying the mirror operation

Example:
Input:
hello

Output:
olleh
*/

#include <stdio.h>
#include <string.h>

int main() {
    char str[1001];
    if (scanf("%s", str) != 1) {
        return 0;
    }

    int n = strlen(str);
    int left = 0;
    int right = n - 1;

    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }

    printf("%s\n", str);

    return 0;
}
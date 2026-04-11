#include <stdio.h>
#include <string.h>

int main() {
    char s[100005];
    if (scanf("%s", s) != 1) return 0;

    int seen[26] = {0};
    int found = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';
        
        if (seen[index] == 1) {
            printf("%c\n", s[i]);
            found = 1;
            break;
        }
        
        seen[index] = 1;
    }

    if (!found) {
        printf("-1\n");
    }

    return 0;
}
#include <stdio.h>
#include <string.h>

int main() {
    char s[100005];
    if (scanf("%s", s) != 1) return 0;

    int freq[26] = {0};
    int len = strlen(s);

    // First pass: Count frequency of each character
    for (int i = 0; i < len; i++) {
        freq[s[i] - 'a']++;
    }

    // Second pass: Find the first character with frequency 1
    int found = 0;
    for (int i = 0; i < len; i++) {
        if (freq[s[i] - 'a'] == 1) {
            printf("%c\n", s[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("$\n");
    }

    return 0;
}
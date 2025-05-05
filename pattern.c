#include <stdio.h>
#include <string.h>

void naivePatternMatching(char* text, char* pattern) {
    int n = strlen(text);
    int m = strlen(pattern);

    printf("Pattern found at index: ");
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        if (j == m) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    char text[100], pattern[100];

    printf("Enter the text: ");
    scanf("%s", text);
    printf("Enter the pattern: ");
    scanf("%s", pattern);

    naivePatternMatching(text, pattern);
    return 0;
}

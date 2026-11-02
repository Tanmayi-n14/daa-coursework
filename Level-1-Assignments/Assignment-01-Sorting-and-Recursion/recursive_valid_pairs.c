#include <stdio.h>
#include <string.h>

int getSum(char s[], int current, int target) {
    if (current >= target) {
        return 0;
    }
    return (int)s[current] + getSum(s, current + 1, target);
}


int countPairs(char s[], int n, int i, int j) {
    if (i >= n - 1) {
        return 0;
    }
    if (j >= n) {
        return countPairs(s, n, i + 1, i + 2);
    }

    int isValid = 0;
    if (s[i] == s[j]) {
        int dist = j - i - 1;
        if (dist % 2 == 0) {
            int asciiSum = getSum(s, i + 1, j);
            if (asciiSum % 3 == 0) {
                isValid = 1;
            }
        }
    }
    return isValid + countPairs(s, n, i, j + 1);
}

int main() {
    char s[1000];
    if (scanf("%s", s) != 1) return 0;
    int n = strlen(s);
    int result = countPairs(s, n, 0, 1);
    printf("%d\n", result);
    return 0;
}

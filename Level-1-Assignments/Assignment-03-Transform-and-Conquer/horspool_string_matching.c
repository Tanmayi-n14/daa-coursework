#include <stdio.h>
#include <string.h>

#define MAX 256


void buildShiftTable(char pattern[], int m, int shift[]) {
    int i;
    
    for (i = 0; i < MAX; i++) {
        shift[i] = m;
    }
    
    for (i = 0; i < m - 1; i++) {
        shift[(unsigned char)pattern[i]] = m - 1 - i;
    }
}

int horspool(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);
    int shift[MAX];
    
    if (m > n) return -1;

    buildShiftTable(pattern, m, shift);

    int i = m - 1; 
    
    while (i < n) {
        int k = 0;
        
        while (k < m && pattern[m - 1 - k] == text[i - k]) {
            k++;
        }
        
        if (k == m) {
         
            return i - m + 1;
        } else {
     
            i += shift[(unsigned char)text[i]];
        }
    }

    return -1;
}


int main() {
    char text[100005], pattern[100005];

    fgets(text, sizeof(text), stdin);
    fgets(pattern, sizeof(pattern), stdin);

    text[strcspn(text, "\n")] = '\0';
    pattern[strcspn(pattern, "\n")] = '\0';

    printf("%d\n", horspool(text, pattern));

    return 0;
}

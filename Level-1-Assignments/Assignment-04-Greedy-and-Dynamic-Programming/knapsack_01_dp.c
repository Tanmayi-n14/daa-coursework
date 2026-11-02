#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int N, W;
    if (scanf("%d %d", &N, &W) != 2) return 0;

    int *weights = (int *)malloc(N * sizeof(int));
    int *values = (int *)malloc(N * sizeof(int));

    // Input weights
    for (int i = 0; i < N; i++) {
        scanf("%d", &weights[i]);
    }
    // Input values
    for (int i = 0; i < N; i++) {
        scanf("%d", &values[i]);
    }

    // dp[j] will store the maximum value for capacity j
    // Long long is safer if N*Value exceeds 2^31 - 1, but based on constraints int is fine
    int *dp = (int *)calloc(W + 1, sizeof(int));

    // Process each item
    for (int i = 0; i < N; i++) {
        // Iterate backwards to ensure each item is used only once
        for (int j = W; j >= weights[i]; j--) {
            dp[j] = max(dp[j], values[i] + dp[j - weights[i]]);
        }
    }

    printf("%d\n", dp[W]);

    // Clean up
    free(weights);
    free(values);
    free(dp);

    return 0;
}

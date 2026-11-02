#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int weights[], int values[], int n, int W) {
    int i, w;

    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (i = 0; i <= n; i++) {
        dp[i] = (int *)malloc((W + 1) * sizeof(int));
    }

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w],
                               values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("Maximum Value = %d\n", dp[n][W]);

    printf("\nDP Table:\n");
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            printf("%d ", dp[i][w]);
        }
        printf("\n");
    }

    int *selected = (int *)malloc(n * sizeof(int));
    int selectedCount = 0;

    w = W;
    for (i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            selected[selectedCount++] = i - 1;
            w -= weights[i - 1];
        }
    }

    printf("\nSelected items:\n");
    if (selectedCount == 0) {
        printf("No items selected\n");
    } else {
        for (i = selectedCount - 1; i >= 0; i--) {
            int idx = selected[i];
            printf("Item %d -> Weight = %d, Value = %d\n",
                   idx + 1, weights[idx], values[idx]);
        }
    }

    for (i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);
    free(selected);
}

int main() {
    int weights1[] = {1, 3, 4, 5};
    int values1[] = {1, 4, 5, 7};
    int n1 = 4, W1 = 7;

    int weights2[] = {2, 3, 4, 5};
    int values2[] = {3, 4, 5, 6};
    int n2 = 4, W2 = 5;

    int weights3[] = {};
    int values3[] = {};
    int n3 = 0, W3 = 10;

    printf("Test Case 1\n");
    knapsack(weights1, values1, n1, W1);
    printf("--------------------------------------------------\n");

    printf("Test Case 2\n");
    knapsack(weights2, values2, n2, W2);
    printf("--------------------------------------------------\n");

    printf("Test Case 3\n");
    knapsack(weights3, values3, n3, W3);
    printf("--------------------------------------------------\n");

    return 0;
}

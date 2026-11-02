#include <stdio.h>

void sortDescending(int coins[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (coins[j] < coins[j + 1]) {
                int temp = coins[j];
                coins[j] = coins[j + 1];
                coins[j + 1] = temp;
            }
        }
    }
}

int removeInvalidAndDuplicateCoins(int coins[], int n) {
    int temp[1000];
    int newSize = 0;

    for (int i = 0; i < n; i++) {
        if (coins[i] <= 0) {
            continue;
        }

        int exists = 0;
        for (int j = 0; j < newSize; j++) {
            if (temp[j] == coins[i]) {
                exists = 1;
                break;
            }
        }

        if (!exists) {
            temp[newSize++] = coins[i];
        }
    }

    for (int i = 0; i < newSize; i++) {
        coins[i] = temp[i];
    }

    return newSize;
}

void greedyCoinChange(int coins[], int n, int amount) {
    if (amount < 0) {
        printf("Invalid amount\n");
        return;
    }

    if (amount == 0) {
        printf("Minimum coins by Greedy = 0\n");
        printf("No coins needed\n");
        return;
    }

    n = removeInvalidAndDuplicateCoins(coins, n);

    if (n == 0) {
        printf("No valid coin denominations available\n");
        return;
    }

    sortDescending(coins, n);

    int usedCount[1000] = {0};
    int totalCoins = 0;
    int originalAmount = amount;

    for (int i = 0; i < n; i++) {
        if (coins[i] <= amount) {
            usedCount[i] = amount / coins[i];
            totalCoins += usedCount[i];
            amount %= coins[i];
        }
    }

    printf("Coins: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", coins[i]);
    }
    printf("\n");

    printf("Amount: %d\n", originalAmount);

    if (amount != 0) {
        printf("Greedy could not form the exact amount\n");
    } else {
        printf("Minimum coins by Greedy = %d\n", totalCoins);
        printf("Coins used:\n");
        for (int i = 0; i < n; i++) {
            if (usedCount[i] > 0) {
                printf("%d coin(s) of %d\n", usedCount[i], coins[i]);
            }
        }
    }

    printf("--------------------------------------------------\n");
}

int main() {
    int coins1[] = {1, 5, 10, 25};
    int coins2[] = {1, 2, 5, 10};
    int coins3[] = {1, 3, 4};
    int coins4[] = {0, -2, 1, 1, 7, 10};
    int coins5[] = {5, 10};

    greedyCoinChange(coins1, 4, 63);
    greedyCoinChange(coins2, 4, 18);
    greedyCoinChange(coins3, 3, 6);
    greedyCoinChange(coins4, 6, 14);
    greedyCoinChange(coins5, 2, 3);

    printf("Failure Example:\n");
    printf("For coins {1, 3, 4} and amount 6\n");
    printf("Greedy gives 4 + 1 + 1 = 3 coins\n");
    printf("Optimal gives 3 + 3 = 2 coins\n");

    return 0;
}

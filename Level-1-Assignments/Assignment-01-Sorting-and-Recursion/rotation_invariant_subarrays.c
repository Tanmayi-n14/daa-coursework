#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAXN 50

int isPrime(int x) {
    if (x < 2) return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int calculateDiff(int temp[], int len) {
    int primeSum = 0;
    int nonPrimeSum = 0;
    for (int i = 0; i < len; i++) {
        if (isPrime(i)) primeSum += temp[i];
        else nonPrimeSum += temp[i];
    }
    return abs(primeSum - nonPrimeSum);
}

int isRotationInvariant(int arr[], int start, int end) {
    int len = end - start + 1;
    if (len < 2) return 0;

    int temp[MAXN];
    for (int i = 0; i < len; i++) temp[i] = arr[start + i];
    
    int targetDiff = calculateDiff(temp, len);
    
    for (int r = 1; r < len; r++) {
        int first = temp[0];
        for (int i = 0; i < len - 1; i++) temp[i] = temp[i + 1];
        temp[len - 1] = first;
        
        if (calculateDiff(temp, len) != targetDiff) return 0;
    }
    return 1;
}

int countRotationInvariantSubarrays(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (isRotationInvariant(arr, i, j)) count++;
        }
    }
    return count;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int arr[MAXN];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("%d\n", countRotationInvariantSubarrays(arr, n));
    return 0;
}

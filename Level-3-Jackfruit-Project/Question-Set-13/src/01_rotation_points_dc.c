#include <stdio.h>

int countRotationLinear(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            count++;
        }
    }
    return count;
}

int countRotationDCUtil(int arr[], int low, int high) {
    if (low >= high) {
        return 0;
    }

    int mid = low + (high - low) / 2;

    int leftCount = countRotationDCUtil(arr, low, mid);
    int rightCount = countRotationDCUtil(arr, mid + 1, high);

    int crossCount = 0;
    if (mid < high && arr[mid] > arr[mid + 1]) {
        crossCount = 1;
    }

    return leftCount + rightCount + crossCount;
}

int countRotationDC(int arr[], int n) {
    if (n <= 1) {
        return 0;
    }
    return countRotationDCUtil(arr, 0, n - 1);
}

int main() {
    int arr1[] = {3, 8, 5, 7, 2};
    int arr2[] = {1, 2, 3, 4, 5};
    int arr3[] = {9, 6, 8, 4, 7, 2};
    int arr4[] = {10};
    int arr5[] = {-5, -2, -8, -1};

    int *tests[] = {arr1, arr2, arr3, arr4, arr5};
    int sizes[] = {5, 5, 6, 1, 4};

    for (int t = 0; t < 5; t++) {
        printf("Array: ");
        for (int i = 0; i < sizes[t]; i++) {
            printf("%d ", tests[t][i]);
        }
        printf("\n");

        printf("Linear Scan Rotation Points: %d\n", countRotationLinear(tests[t], sizes[t]));
        printf("Divide and Conquer Rotation Points: %d\n", countRotationDC(tests[t], sizes[t]));
        printf("--------------------------------------------------\n");
    }

    return 0;
}

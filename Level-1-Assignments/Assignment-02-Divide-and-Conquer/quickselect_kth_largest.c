#include <stdio.h> 
#include <stdlib.h>
#define MAXN 100005 

// Helper to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function: Places elements > pivot to the left
int partition(int arr[], int left, int right) {
    // Randomized pivot to avoid O(N^2) on sorted inputs
    int pivotIndex = left + rand() % (right - left + 1);
    int pivotValue = arr[pivotIndex];
    swap(&arr[pivotIndex], &arr[right]); // Move pivot to end
    
    int storeIndex = left;
    for (int i = left; i < right; i++) {
        // For Kth largest, we want descending order logic
        if (arr[i] > pivotValue) {
            swap(&arr[i], &arr[storeIndex]);
            storeIndex++;
        }
    }
    swap(&arr[storeIndex], &arr[right]); // Move pivot to final place
    return storeIndex;
} 

int findKthLargest(int arr[], int N, int k) { 
    int left = 0, right = N - 1;
    int target = k - 1; // 0-indexed position for kth largest
    
    while (left <= right) {
        int pivotIndex = partition(arr, left, right);
        
        if (pivotIndex == target) {
            return arr[pivotIndex];
        } else if (pivotIndex > target) {
            right = pivotIndex - 1;
        } else {
            left = pivotIndex + 1;
        }
    }
    return -1;
} 

int main() { 
    int N; 
    if (scanf("%d", &N) != 1) return 0; 

    int arr[MAXN]; 
    for (int i = 0; i < N; i++) { 
        scanf("%d", &arr[i]); 
    } 
    
    int k; 
    scanf("%d", &k); 
    
    // Seed for randomness in partition
    srand(42); 
    
    int result = findKthLargest(arr, N, k); 
    printf("%d\n", result); 
    return 0; 
}

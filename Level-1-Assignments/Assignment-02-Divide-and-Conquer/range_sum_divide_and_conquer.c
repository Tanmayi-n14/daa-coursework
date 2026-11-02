#include <stdio.h> 
#include <stdlib.h> 
#define MAXN 100005 

// Declare temp globally to handle the merge step memory
long long temp[MAXN + 1];

int mergeSort(long long prefix[], int left, int right, long long lower, long long upper) { 
    if (left >= right) return 0;
    
    int mid = left + (right - left) / 2;
    int count = mergeSort(prefix, left, mid, lower, upper) + 
                mergeSort(prefix, mid + 1, right, lower, upper);
    
    // Count valid pairs across the two halves
    int j = mid + 1, k = mid + 1;
    for (int i = left; i <= mid; i++) {
        while (j <= right && prefix[j] - prefix[i] < lower) j++;
        while (k <= right && prefix[k] - prefix[i] <= upper) k++;
        count += (k - j);
    }
    
    // Merge step
    int p1 = left, p2 = mid + 1, p = 0;
    while (p1 <= mid && p2 <= right) {
        temp[p++] = (prefix[p1] <= prefix[p2]) ? prefix[p1++] : prefix[p2++];
    }
    while (p1 <= mid) temp[p++] = prefix[p1++];
    while (p2 <= right) temp[p++] = prefix[p2++];
    
    for (int i = 0; i < p; i++) {
        prefix[left + i] = temp[i];
    }
    
    return count;
} 

int countRangeSum(int nums[], int N, long long lower, long long upper) { 
    long long prefix[MAXN + 1];
    prefix[0] = 0;
    for (int i = 0; i < N; i++) {
        prefix[i + 1] = prefix[i] + (long long)nums[i];
    }
    return mergeSort(prefix, 0, N, lower, upper);
} 

int main() { 
    int N; 
    if (scanf("%d", &N) != 1) return 0; 

    int nums[MAXN]; 
    for (int i = 0; i < N; i++) { 
        scanf("%d", &nums[i]); 
    } 
    
    long long lower, upper; 
    scanf("%lld %lld", &lower, &upper); 
    
    int result = countRangeSum(nums, N, lower, upper); 
    printf("%d\n", result); 
    return 0; 
}

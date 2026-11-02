#include <stdio.h>
#define MAXN 85

void constrainedSelectionSort(int arr[], int N, int *swap_count){

    for (int i = 0; i < N - 1; i++) {
        
        int min_index = i;
        for (int j = i + 1; j < N; j++) {
         
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }


        while (min_index > i) {
          
            int temp = arr[min_index];
            arr[min_index] = arr[min_index - 1];
            arr[min_index - 1] = temp;


            min_index--;

            (*swap_count)++;
        }
    }
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0; 

    int arr[MAXN];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int swap_count = 0;
    constrainedSelectionSort(arr, N, &swap_count);

    for (int i = 0; i < N; i++) {
        printf("%d", arr[i]);
        if (i != N - 1) printf(" ");
    }
    printf("\n%d\n", swap_count);

    if (swap_count % 2 == 0)
        printf("EVEN\n");
    else
        printf("ODD\n");

    return 0;
}

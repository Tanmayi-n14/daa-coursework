#include <stdio.h>
#include <stdlib.h>

// Structure to represent an activity
typedef struct {
    int start;
    int end;
} Activity;

// Comparator function to sort activities by their end times
int compare(const void *a, const void *b) {
    Activity *actA = (Activity *)a;
    Activity *actB = (Activity *)b;
    
    if (actA->end < actB->end) return -1;
    if (actA->end > actB->end) return 1;
    return 0;
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    Activity *activities = (Activity *)malloc(N * sizeof(Activity));

    // Input all start times
    for (int i = 0; i < N; i++) {
        scanf("%d", &activities[i].start);
    }
    // Input all end times
    for (int i = 0; i < N; i++) {
        scanf("%d", &activities[i].end);
    }

    // Step 1: Sort activities based on end times
    qsort(activities, N, sizeof(Activity), compare);

    // Step 2: Greedy Selection
    int count = 0;
    int last_end_time = -1;

    for (int i = 0; i < N; i++) {
        // If the start time of current activity is >= end time of last selected activity
        if (activities[i].start >= last_end_time) {
            count++;
            last_end_time = activities[i].end;
        }
    }

    printf("%d\n", count);

    free(activities);
    return 0;
}

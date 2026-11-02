#include <stdio.h> 

int josephus(int N, int K) { 
    int g = 0; // Base case: the winner for 1 person is index 0
    for (int i = 2; i <= N; i++) {
        // Find the winner position for 'i' people based on 'i-1' people
        g = (g + K) % i;
    }
    return g;
} 

int main() { 
    int N, K; 
    if (scanf("%d %d", &N, &K) == 2) {
        int winner = josephus(N, K); 
        printf("%d\n", winner); 
    }
    return 0; 
}

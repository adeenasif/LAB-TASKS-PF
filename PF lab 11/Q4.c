#include<stdio.h>

int main(){
    int T, N;
    scanf("%d", &T);

    while(T--){
        scanf("%d", &N);
        if (N < 1 || N > 1000){
            printf("Enter a number between 1 & 1000!!");
            return 1;
        }
        int Array[N];
        for (int j = 0; j < N; j++){
            scanf("%d", &Array[j]);
        }

        int freq[1001] = {0}; // assumed numbers are between 0 and 1000

        // Calculate the frequency of each number in the array
        for (int i = 0; i < N; i++) {
            freq[Array[i]]++;
        }

        int ans = Array[0];
        int maxFreq = freq[0];
        // Find the element with the highest frequency
        for (int i = 1; i < N; i++){
            if (freq[Array[i]] > maxFreq) {
                maxFreq = freq[Array[i]];
                ans = Array[i];
            } else if (freq[Array[i]] == maxFreq && Array[i] < ans) {
                ans = Array[i];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
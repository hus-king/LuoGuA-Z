#include <stdio.h>
int main() {
    int N;
    long long int B;
    scanf("%d %lld", &N, &B);
    long long int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }
    long long int sum = 0;
    long long int temp;
    for(int i=0;i<N;i++){
        for(int j=0;j<N-i-1;j++){
            if(A[j]<A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
    int key = 0;
    for(int i=0;i<N;i++){
        sum += A[i];
        key++;
        if(sum>=B){
            break;
        }
    }
    printf("%d", key);
}
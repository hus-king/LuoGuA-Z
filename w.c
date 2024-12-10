#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int isPrime(int n);
#define MAX 1000000
int *prime;
void generatePrime(){
    prime=(int*)malloc(sizeof(int)*MAX);
    memset(prime,1,sizeof(int)*MAX);
    prime[0]=prime[1]=0;
    for(int i=2;i*i<MAX;i++){
        if(prime[i]){
            for(int j=i*i;j<MAX;j+=i){
                prime[j]=0;
            }
        }
    }
}
unsigned long long f(int n) {
    if (n == 0) {
        return 1;
    }
    return n * f(n - 1);
}
int sum=0;
int b[25]={0};
int flag=0;
long long out=0;
void make(int a[],int k,int n){
    if(flag==k){
        if(prime[sum]){
            out++;
        }
        return;
    }
    for(int i=0;i<n;i++){
        if(b[i]==0){
            b[i]=1;
            sum+=a[i];
            flag++;
            make(a,k,n);
            b[i]=0;
            sum-=a[i];
            flag--;
        }
    }
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[25]={0};
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    generatePrime();
    make(a,k,n);
    out = out/f(k);
    printf("%lld\n",out);
}
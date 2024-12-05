#include <stdio.h>
#include <math.h>
void desloveby2(int n);
int main(){
    int n;
    scanf("%d", &n);
    desloveby2(n);
}
void desloveby2(int n){
    if(n==1){
        printf("2(0)");
    }
    else if(n==2){
        printf("2");
    }
    else if(n==3){
        printf("2+2(0)");
    }
    else if(n==4){
        printf("2(2)");
    }
    else if (n==5){
        printf("2(2)+2(0)");
    }
    else{
        int i=0;
        while(n>pow(2,i)){
            i++;
        }
        if(n==pow(2,i)){
            printf("2(");
            desloveby2(i);
            printf(")");
        }
        else{
            printf("2(");
            desloveby2(i-1);
            printf(")+");
            desloveby2(n-pow(2,i-1));
        }
    }
}
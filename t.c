#include <stdio.h>
//0表示未提及
//1表示为是这一行的前置任务
//2表示为需要完成
#define MAX 20
int main(){
    int n;
    scanf("%d", &n);
    getchar();
    int task[MAX][MAX]={0};
    int make[MAX]={0};
    int k[MAX]={0};
    for(int i = 0; i < n; i++){
        scanf("%d", &k[i]);
        for(int j = 0; j < k[i]; j++){
            int m;
            scanf("%d", &m);
            task[i][m-1]=1;
        }
        getchar();
    }
    make[0]=1;
    for(int i = 0,k=0; k < 2*n; i++){
        i=i%n;
        if(make[i]==1){
            for(int j=0;j<n;j++){
                if(task[i][j]==1)
                make[j]=1;
            }
        }
        k++;
    }
    int flag=0;
    for(int i = 0; i < n; i++){
        if(make[i]==1){
            flag++;
        }
    }
    printf("%d", flag);
}
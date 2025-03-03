#include<stdio.h>
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int a[110000][2];
    for(int i=0;i<n;i++){
        scanf("%d %d",&a[i][0],&a[i][1]);
    }
    int result = a[0][0];
    while(1){
        int max=0,min=0xffffff,key=-1;
        for(int i=0;i<n;i++){
            if(a[i][0]>max){
                max = a[i][0];
            }
        }
        result = max;
        for(int i=0;i<n;i++){
            if((a[i][0]==max)&&(a[i][1]<=min)&&(a[i][0]>k)&&(a[i][1]<=m)){
                min=a[i][1];
                key=i;
            }
        }
        if(key!=-1){
            m-=min;
            a[key][0]--;
        }
        else{
            break;
        }
    }
    printf("%d\n",result);
}
#include <stdio.h>
void out(int a[]);
void out1(int a[]);
int main(){
    int a[3]={};
    scanf("%d%d%d",&a[0],&a[1],&a[2]);
    out1(a);
}
void out(int a[]){
    int b[10]={0};
    for(int i=0;i<3;i++) b[a[i]]=1;
    for(int i=0;i<10;i++) if(b[i]==0) printf("%d ",i);
}
void out1(int a[]){
    for(int i=0;i<10;i++){
        int flag=1;
        for(int j=0;j<3;j++) if(a[j]==i) flag=0;
        if(flag) printf("%d ",i);
    }
}
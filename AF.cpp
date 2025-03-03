#include <stdio.h>
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int x=0,y=0;
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        x+=a;
        y+=b;
    }
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        a+=x;
        b+=y;
        printf("%d %d\n",a,b);
    }
}
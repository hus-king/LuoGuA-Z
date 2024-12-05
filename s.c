#include <stdio.h>
#include <string.h>
void substring(const char *oldstring, char *newstring, int i, int j);
int main(){
    char s[1200],t[1200];
    scanf("%s",s);
    getchar();
    scanf("%s",t);
    getchar();
    int q=0;
    scanf("%d",&q);
    int a[1200],b[1200],c[1200],d[1200];
    for(int i=0;i<q;i++){
        scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
        getchar();
    }
    for(int i=0;i<q;i++){
        char sub1[1200],sub2[1200];
        substring(s,sub1,a[i]-1,b[i]-1);
        substring(t,sub2,c[i]-1,d[i]-1);
        if(strcmp(sub1,sub2)<0){
            printf("yifusuyi\n");
        }
        else if(strcmp(sub1,sub2)>0){
            printf("erfusuer\n");
        }
        else{
            printf("ovo\n");
        }
    }
}

void substring(const char *oldstring, char *newstring, int i, int j) {
    strncpy(newstring, oldstring + i, j - i + 1);
    newstring[j - i + 1] = '\0'; // 确保新字符串以空字符结尾
}
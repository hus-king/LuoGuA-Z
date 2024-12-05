#include <stdio.h>
#include <string.h>
void make(char *past,char *now,int i,int j){
    strcpy(now,past);
    while(i<j){
        char temp;
        temp=now[j];
        now[j]=now[i];
        now[i]=temp;
        i++;
        j--;
    }
}
int main(){
    char past[200];
    scanf("%s",past);
    int n;
    n=strlen(past);
    char min[200];
    strcpy(min,past);
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            char now[200];
            make(past,now,i,j);
            if(strcmp(now,min)<0){
                strcpy(min,now);
            }
        }
    }
    puts(min);
}
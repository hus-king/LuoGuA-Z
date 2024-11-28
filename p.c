#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void replaceSubstring(char *str, char *from, char *to);
void remove_char(char *str, char c);
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    getchar(); 
    char a[5000][100];
    char b[5000][13];
    for (int i = 0; i < n; i++) {
        scanf("%s %s", a[i], b[i]); 
        char p[100];
        strcpy(p, "{");
        strcat(p, a[i]);
        strcat(p, "}");
        strcpy(a[i], p);
        getchar(); 
    }
    char c[20][60000];
    for (int i = 0; i < m; i++) {
        fgets(c[i], 60000, stdin); 
        if(c[i][strlen(c[i]) - 1]== '\n') c[i][strlen(c[i]) - 1] = '\0';
        for (int j = 0; j < n; j++) {
            if(strstr(c[i], a[j])!=NULL)
            replaceSubstring(c[i], a[j], b[j]);
        }
        puts(c[i]);
    }
}
    char *pos;
void replaceSubstring(char *str, char *from, char *to) {
    int index = 0;
    char temp[60000];
    while ((pos = strstr(str, from)) != NULL) {
        strncpy(temp, str, pos - str);
        temp[pos-str] = '\0';
        strcat(temp, to);
        int Length = strlen(str) - (pos - str) - strlen(from);
        if (Length > 0) strcat(temp, pos + strlen(from));
        strcpy(str + index, temp);
    }
}
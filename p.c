/*
小S 是一位世界记录员，她的职责是将来自不同异世界的文字材料整理归档。
虽然异世界的文明不知道为何都是用日语交流，但是他们的文字各异。所以处理这
些材料并非易事。
幸好小S 是一位NLP（自然语言处理）高手，通过机器学习，她的模型帮她轻松
地把所有文本翻译成了英文。
但是小S 发现，她的语言模型不能很好的处理不同进制数值的转换，所以她只好进
行人脑NLP，手动完成异世界数字文本的替换工作。
幸好，小S 有一份巨大的字典，其中包含n 个异世界数字代表的数值。她只需要单
纯的依此对翻译后的英文文本进行简单替换即可。
不过由于小S 正在用电脑玩肉鸽游戏tarjan lusa，无法使用，所以这项任务就被丢
给了你。
为了方便本世界的计算机处理，需要进行替换的异世界数字都被替换成了小写英
文字符串，并处于{} 之间。简单的说，你需要把给出的英文文本里每一句话中全部的
{异世界数字} 替换为变量的值并输出。同时小S 保证，给你的每句话都满足仅由大小
写英文字母、空格、半角逗号、半角句号和{、} 组成。同时每句话由在{} 之间的，必
然为字典中N 个异世界数字中的一个。
例如，有a = 20, b = 10，对于句子Kitsuki achieved a {b} game winning
streak on advanced difficulty of {a}.，替换后将得到Kitsuki achieved a
10 game winning streak on advanced difficulty of 20.。
*/
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
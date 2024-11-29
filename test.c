#include <stdio.h>
#include <string.h>

void sort(char a[][20], int n);
int compare(const char *a, const char *b);
int comparechar(char a, char b);

int main() {
    char arr[100][20] = {
        "VrT47TlIMO", "UQsK2QofGh", "Bdqxk7nDjV", "edK4vLsWld", "lB4FMbjIwb", "iE4feL1SSg", "IFjm8lSl0e", "13SKTfJ4L2",
        "ELep2FPabF", "PktP3R0Xl2", "YWpPdnSTta", "Ti2AupATrR", "Ad98KfIVqa", "5SVJvykzlJ", "NMYyFmpPmm", "kxWwOlNUkk",
        "elqDCGTBVu", "FRLwfaUXgk", "HaYYJpruv2", "WMTslR5mOL", "mMQXkffZeh", "dOVJflbGhV", "BReTHlD3Zq", "LvenfkIyTX",
        "1cmVSirMlG", "Arz53G2JtS", "2wOFRPDdVd", "EpZKAMjy6f", "JroCPQWfeF", "FNTVwXWA1A", "DfwIsy49z0", "LIqvVZR0On",
        "kr8NJgCEKZ", "XLOHsedhCT", "1t9mRQRtaM", "oxRHuOU5Jf", "UiGApq5Jhs", "pXYHqZpJ5A", "mCp7gIjA4Z", "qUJYro3fbo",
        "Ec151438aH", "uGJw8S63a1", "xp9SVvxIOo", "DAFdDo5rrS", "3JmUGa8gRv", "0LI8uKhecf", "U00Vv6uX4v", "YaJnnKBo6p",
        "2IrsLxV8N8", "siz4AqfbLe", "CePsbiAM0I", "mtAXXKSXQA", "WFzP8mSlq7", "yNfqTt1H7l", "NojEof9DpF", "jng1aevsM0",
        "gV7L11cxho", "u2qswwMxCw", "jwKAk4wFoj", "XJqolnbxgW", "W6UENx7GJF", "Zb1sneUWQZ", "YsPf6DCgoP", "vOIdcB3WD4",
        "3BnDyTTfWk", "MEQgkSGdro", "yySj0jOUk2", "QBz1CAjxRZ", "wWzRLyIOfJ", "kiiNaZs0xy", "yIXX90wLgy", "AfY2xTLyGf",
        "D76A3uEQef", "XhS3WwJLRM", "kQRz9Nxmov", "QfIZL0449V", "VM0sXSPY9z", "Bs90T3mk7s", "U9aX9ymOvm", "uH2vW4R3Wl",
        "1VXbKZlpjv", "FQDddgmikl", "WaL9YONoCd", "FRcDEWscyx", "6yyXtG304J", "KF96LoTWKl", "MkFq97eWFo", "rQFSeGKHqI",
        "ICsQsUiuFo", "B6DV1mTUoi", "KF00KlP95h", "CjAkZrPvMe", "QkiZdGjmZD", "wkHhb1lSgG", "lMY5jlH7zH", "ZNbTGXEwhM",
        "HAF8v1yoAY", "QxDeMKzIlb", "2MAuzYK9pC", "hzCFxiVYJZ"
    };
    int n = 100;

    sort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    return 0;
}

void sort(char a[][20], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (compare(a[j], a[j + 1]) > 0) { // ascii码小的在前
                char temp[20];
                strcpy(temp, a[j]);
                strcpy(a[j], a[j + 1]);
                strcpy(a[j + 1], temp);
            }
        }
    }
}

int compare(const char *a, const char *b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        int result = comparechar(a[i], b[i]);
        if (result != 0) {
            return result;
        }
        i++;
    }
    if (a[i] == '\0' && b[i] == '\0') {
        return 0;
    } else if (a[i] == '\0') {
        return -1;
    } else {
        return 1;
    }
}

int comparechar(char a, char b) {
    if (a == b) {
        return 0;
    } else if (a > b) {
        return 1;
    } else {
        return -1;
    }
}
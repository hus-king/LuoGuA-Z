#include <stdio.h>
#include <string.h>

void quicksort(char a[][20], int low, int high);
int partition(char a[][20], int low, int high);
int compare(const char *a, const char *b);
int comparechar(char a, char b);

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    char old[110000][20]; // n
    int flag[110000]; // n
    char full[110000][20]; // m
    char new1[110000][20]; // k
    for (int i = 0; i < n; i++) {
        scanf("%s", old[i]);
        flag[i] = 0; // 0为要输出
    }
    for (int i = 0; i < m; i++) {
        scanf("%s", full[i]);
    }
    for (int i = 0; i < k; i++) {
        scanf("%s", new1[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (strcmp(old[i], full[j]) == 0) {
                flag[i] = 1;
                break;
            }
        }
    }
    char putout[210000][20];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (flag[i] == 0) {
            strcpy(putout[j], old[i]);
            j++;
        }
    }
    for (int i = 0; i < k; i++) {
        strcpy(putout[j], new1[i]);
        j++;
    }
    quicksort(putout, 0, j - 1);
    for (int i = 0; i < j; i++) {
        puts(putout[i]);
    }
}

void quicksort(char a[][20], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quicksort(a, low, pi - 1);
        quicksort(a, pi + 1, high);
    }
}

int partition(char a[][20], int low, int high) {
    char pivot[20];
    strcpy(pivot, a[high]);
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (compare(a[j], pivot) < 0) {
            i++;
            char temp[20];
            strcpy(temp, a[i]);
            strcpy(a[i], a[j]);
            strcpy(a[j], temp);
        }
    }
    char temp[20];
    strcpy(temp, a[i + 1]);
    strcpy(a[i + 1], a[high]);
    strcpy(a[high], temp);
    return (i + 1);
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
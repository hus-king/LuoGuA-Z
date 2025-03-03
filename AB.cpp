#include <stdio.h>
#include <algorithm>  // 引入标准库算法头文件

int height(int i, int n, int m);

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    // 有n层，每层m个货槽
    int H[110000];
    for (int i = 0; i < k; i++) {
        scanf("%d", &H[i]);
    }

    // 使用标准库中的排序函数
    std::sort(H, H + k);

    int flag = 1;
    for (int i = 0; i < k; i++) {
        if (H[i] < height(i, n, m)) {
            flag = 0;
            break;
        }
    }
    if (flag == 0) {
        printf("No");
    } else {
        printf("Yes");
    }
}

int height(int i, int n, int m) {
    int ht = i / m + 1;
    return ht;
}
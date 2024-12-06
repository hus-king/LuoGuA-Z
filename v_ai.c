#include <stdio.h>
#include <limits.h>

void map(int x, int y, int coin, int magicflag);
int min = INT_MAX;
int m, n;
int a[120][120];
int dp[120][120][2];  // 动态规划数组，记录每个状态的最小金币数

#define find(x, y) (a[x][y] < 2) && (x > 0) && (y > 0) && (x <= m) && (y <= m)
#define find2(x, y) (a[x][y] == 2) && (x > 0) && (y > 0) && (x <= m) && (y <= m) && (magicflag == 1)

int main() {
    scanf("%d %d", &m, &n);
    getchar();
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = 2;
            dp[i][j][0] = dp[i][j][1] = INT_MAX;  // 初始化动态规划数组
        }
    }
    for (int i = 0; i < n; i++) {
        int k, j, l;
        scanf("%d %d %d", &k, &j, &l);
        for (int p = 0; p <= l; p++) {
            a[k][j] = l;
        }
        getchar();
    }
    map(1, 1, 0, 1);
    if (min == INT_MAX)
        printf("-1");
    else
        printf("%d", min);
}

void map(int x, int y, int coin, int magicflag) {
    if (coin >= min) return;  // 剪枝优化
    if (coin >= dp[x][y][magicflag]) return;  // 动态规划剪枝
    dp[x][y][magicflag] = coin;

    if ((x == m) && (y == m)) {
        min = (coin < min) ? coin : min;
        return;
    }

    int directions[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    for (int i = 0; i < 4; i++) {
        int nx = x + directions[i][0];
        int ny = y + directions[i][1];

        if (find(nx, ny)) {
            if (a[nx][ny] == a[x][y]) {
                a[x][y] += 10;
                map(nx, ny, coin, 1);
                a[x][y] -= 10;
            } else {
                a[x][y] += 10;
                map(nx, ny, coin + 1, 1);
                a[x][y] -= 10;
            }
        } else if (find2(nx, ny)) {
            int temp = a[nx][ny];
            a[nx][ny] = a[x][y];
            a[x][y] += 10;
            map(nx, ny, coin + 2, 0);
            a[x][y] -= 10;
            a[nx][ny] = temp;
        }
    }
}
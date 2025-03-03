#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    // 读取矩阵 Q, K, V
    vector<vector<int>> Q(n, vector<int>(d));
    vector<vector<int>> K(n, vector<int>(d));
    vector<vector<int>> V(n, vector<int>(d));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            cin >> Q[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            cin >> K[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            cin >> V[i][j];
        }
    }

    // 读取向量 W
    vector<int> W(n);
    for (int i = 0; i < n; ++i) {
        cin >> W[i];
    }

    // 计算 Q × K^T
    vector<vector<int>> QK(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < d; ++k) {
                QK[i][j] += Q[i][k] * K[j][k];
            }
        }
    }

    // 计算 W · (Q × K^T)
    vector<vector<int>> WQK(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            WQK[i][j] = W[i] * QK[i][j];
        }
    }

    // 计算 (W · (Q × K^T)) × V
    vector<vector<int>> result(n, vector<int>(d, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += WQK[i][k] * V[k][j];
            }
        }
    }

    // 输出结果
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
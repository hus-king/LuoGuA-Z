#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

// 将8x8字符矩阵转换为字符串，方便存储和比较
string matrixToString(const vector<string>& matrix) {
    string result;
    for (const auto& row : matrix) {
        result += row;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<vector<string>> matrices(n, vector<string>(8));
    unordered_map<string, int> matrixCount;

    // 读取n个8x8字符矩阵
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 8; ++j) {
            cin >> matrices[i][j];
        }
    }

    // 统计每个字符矩阵出现的次数并输出
    for (const auto& matrix : matrices) {
        string matrixStr = matrixToString(matrix);
        matrixCount[matrixStr]++;
        cout << matrixCount[matrixStr] << endl;
    }

    return 0;
}
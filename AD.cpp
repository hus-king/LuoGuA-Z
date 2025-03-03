#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> vectors(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> vectors[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        int min_index = 0;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            bool all_greater = true;
            for (int k = 0; k < m; ++k) {
                if (vectors[j][k] <= vectors[i][k]) {
                    all_greater = false;
                    break;
                }
            }
            if (all_greater) {
                if (min_index == 0 || j + 1 < min_index) {
                    min_index = j + 1;
                }
            }
        }
        cout << min_index << endl;
    }

    return 0;
}
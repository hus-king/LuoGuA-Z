#include <stdio.h>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

struct Item {
    int value;
    int cost;
    bool operator<(const Item& other) const {
        return value < other.value;
    }
};

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    priority_queue<Item> pq;
    for (int i = 0; i < n; i++) {
        int value, cost;
        scanf("%d %d", &value, &cost);
        pq.push({value, cost});
    }
    int result = pq.top().value;
    while (!pq.empty()) {
        Item maxItem = pq.top();
        pq.pop();
        if (maxItem.value <= k || maxItem.cost > m) {
            break;
        }
        m -= maxItem.cost;
        maxItem.value--;
        if (maxItem.value > 0) {
            pq.push(maxItem);
        }
        if (!pq.empty()) {
            result = pq.top().value;
        }
    }
    printf("%d\n", result);
}
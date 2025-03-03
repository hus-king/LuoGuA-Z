#include <stdio.h>

typedef long long ll;

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        ll a, k;
        scanf("%lld%lld", &a, &k);
        if (k <= 1) {
            printf("%lld\n", a);
            continue;
        }
        ll res = 1;
        ll tmp = a;
        // 处理因子2
        if (tmp % 2 == 0) {
            ll cnt = 0;
            while (tmp % 2 == 0) {
                cnt++;
                tmp /= 2;
            }
            if (cnt >= k) {
                ll pow_val = 1;
                for (int i = 0; i < cnt; i++) {
                    pow_val *= 2;
                }
                res *= pow_val;
            }
        }
        // 处理奇数因子
        for (ll i = 3; i * i <= tmp; i += 2) {
            if (tmp % i == 0) {
                ll cnt = 0;
                while (tmp % i == 0) {
                    cnt++;
                    tmp /= i;
                }
                if (cnt >= k) {
                    ll pow_val = 1;
                    for (int j = 0; j < cnt; j++) {
                        pow_val *= i;
                    }
                    res *= pow_val;
                }
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}
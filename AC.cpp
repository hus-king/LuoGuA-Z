#include <stdio.h>
#define MOD 998244353

void multiply(long long F[3][3], long long M[3][3]) {
    long long x = (F[0][0] * M[0][0] + F[0][1] * M[1][0] + F[0][2] * M[2][0]) % MOD;
    long long y = (F[0][0] * M[0][1] + F[0][1] * M[1][1] + F[0][2] * M[2][1]) % MOD;
    long long z = (F[0][0] * M[0][2] + F[0][1] * M[1][2] + F[0][2] * M[2][2]) % MOD;
    long long w = (F[1][0] * M[0][0] + F[1][1] * M[1][0] + F[1][2] * M[2][0]) % MOD;
    long long u = (F[1][0] * M[0][1] + F[1][1] * M[1][1] + F[1][2] * M[2][1]) % MOD;
    long long v = (F[1][0] * M[0][2] + F[1][1] * M[1][2] + F[1][2] * M[2][2]) % MOD;
    long long p = (F[2][0] * M[0][0] + F[2][1] * M[1][0] + F[2][2] * M[2][0]) % MOD;
    long long q = (F[2][0] * M[0][1] + F[2][1] * M[1][1] + F[2][2] * M[2][1]) % MOD;
    long long r = (F[2][0] * M[0][2] + F[2][1] * M[1][2] + F[2][2] * M[2][2]) % MOD;

    F[0][0] = x;
    F[0][1] = y;
    F[0][2] = z;
    F[1][0] = w;
    F[1][1] = u;
    F[1][2] = v;
    F[2][0] = p;
    F[2][1] = q;
    F[2][2] = r;
}

void power(long long F[3][3], long long n, long long a, long long b, long long c) {
    if (n == 0 || n == 1)
        return;
    long long M[3][3] = {{a, b, c}, {1, 0, 0}, {0, 0, 1}};

    power(F, n / 2, a, b, c);
    multiply(F, F);

    if (n % 2 != 0)
        multiply(F, M);
}

long long fib(long long n, long long f1, long long f2, long long a, long long b, long long c) {
    if (n == 1)
        return f1 % MOD;
    if (n == 2)
        return f2 % MOD;

    long long F[3][3] = {{a, b, c}, {1, 0, 0}, {0, 0, 1}};
    power(F, n - 2, a, b, c);

    return (F[0][0] * f2 + F[0][1] * f1 + F[0][2]) % MOD;
}

int main() {
    long long int n;
    scanf("%lld", &n);
    long long int f1, f2;
    scanf("%lld %lld", &f1, &f2);
    long long int a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);

    printf("%lld\n", fib(n, f1, f2, a, b, c));
    return 0;
}
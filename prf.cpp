#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
const long long MOD = 998244353;
const int LG100 = 7;

long long add(long long x, long long y)
{
    return (x + y) % MOD;
}

long long mul(long long x, long long y)
{
    return (x * y) % MOD;
}

long long n, s, k, c[200], v[200], L[200][200]; // L[i][j] = number of ways to select last one is a[i] and total of j
long long P[200][200][10];

void sol0()
{
    for (long long i = 1; i <= n; i++)
    {
        if (c[i] <= s)
            L[i][c[i]] = 1;
        for (long long j = c[i] + 1; j <= s; j++)
            for (long long ii = 1; ii < i; ii++)
                if (L[ii][j - c[i]])
                    L[i][j] = add(L[i][j], L[ii][j - c[i]]);
    }
    long long ans = 1;
    for (long long i = 1; i <= n; i++)
        for (long long j = c[i]; j <= s; j++)
            ans = add(ans, L[i][j]);
    cout << ans;
}

void sol1()
{
    for (long long i = 1; i <= n; i++)
    {
        if (c[i] <= s)
        {
            L[i][c[i]] = 1;
            P[i][c[i]] = v[i] % MOD;
        }
        for (long long j = c[i] + 1; j <= s; j++)
            for (long long ii = 1; ii < i; ii++)
                if (L[ii][j - c[i]])
                {
                    L[i][j] = add(L[i][j], L[ii][j - c[i]]);
                    P[i][j] = add(P[i][j], add(P[ii][j - c[i]], mul(L[ii][j - c[i]], v[i])));
                }
    }
    long long ans = 0;
    for (long long i = 1; i <= n; i++)
        for (long long j = c[i]; j <= s; j++)
            ans = add(ans, P[i][j]);
    cout << ans;
}

void sol2()
{
    for (long long i = 1; i <= n; i++)
    {
        if (c[i] <= s)
        {
            L[i][c[i]] = 1;
            P[i][c[i]] = v[i] % MOD;
            PP[i][c[i]] = (P[i][c[i]] * P[i][c[i]]) % MOD;
        }
        for (long long j = c[i] + 1; j <= s; j++)
            for (long long ii = 1; ii < i; ii++)
                if (L[ii][j - c[i]])
                {
                    L[i][j] = add(L[i][j], L[ii][j - c[i]]);
                    P[i][j] = add(P[i][j], add(P[ii][j - c[i]], mul(L[ii][j - c[i]], v[i])));
                    PP[i][j] =  add(PP[i][j],
                                add(mul(mul(L[ii][j - c[i]], v[i]), v[i]),
                                add(PP[ii][j - c[i]],
                                mul(2 * v[i], P[ii][j - c[i]]))));
                }
    }
    long long ans = 0;
    for (long long i = 1; i <= n; i++)
        for (long long j = c[i]; j <= s; j++)
            ans = add(ans, PP[i][j]);
    cout << ans;
}

void sol3()
{
    for (long long i = 1; i <= n; i++)
    {
        if (c[i] <= s)
        {
            L[i][c[i]] = 1;
            P[i][c[i]][0] = v[i] % MOD;
            for (int i = 1; i <= LG100; i++)
                P[i][c[i]][i] = mul(P[i][c[i]][i - 1], P[i][c[i]][i - 1]);
        }
        for (long long j = c[i] + 1; j <= s; j++)
            for (long long ii = 1; ii < i; ii++)
                if (L[ii][j - c[i]])
                {
                    L[i][j] = add(L[i][j], L[ii][j - c[i]]);
                    P[i][j] = add( P[i][j], add(P[ii][j - c[i]], mul(L[ii][j - c[i]], v[i])));
                    PP[i][j] =  add(PP[i][j],
                                add(mul(mul(L[ii][j - c[i]], v[i]), v[i]),
                                add(PP[ii][j - c[i]],
                                mul(2 * v[i], P[ii][j - c[i]]))));
                }
    }
    long long ans = 0;
    for (long long i = 1; i <= n; i++)
        for (long long j = c[i]; j <= s; j++)
            ans = add(ans, PP[i][j]);
    cout << ans;
}

int main()
{
    cin >> n >> s >> k;
    for (long long i = 1; i <= n; i++)
        cin >> c[i] >> v[i];
    if (k == 0)
        sol0();
    else if (k == 1)
        sol1();
    else if (k == 2)
        sol2();
    else
        sol3();
}

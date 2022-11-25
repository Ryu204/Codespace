#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

long long t, n, c, l, k, d, s, dp[1010][110][110];
bool avail[1010][110][110];

int main()
{
    cin >> t >> s >> c >> k >> l >> d;
    avail[0][0][c] = true;
    for (long long i = 1; i <= t; i++)
    {
        // acceleration
        for (long long prev = 0; prev <= s; prev++)
        for (long long prep = l; prep <= c; prep++)
            if (avail[i - 1][prev][prep])
            {
                long long v = min(prev + 1, s);
                long long p = prep - l;
                dp[i][v][p] = max(dp[i][v][p], dp[i - 1][prev][prep] + v);
                avail[i][v][p] = true;
            }
        // conserve
        for (long long v = 0; v <= s; v++)
        for (long long prep = k; prep <= c; prep++)
            if (avail[i - 1][v][prep])
            {
                long long p = prep - k;
                dp[i][v][p] = max(dp[i][v][p], dp[i - 1][v][prep] + v);
                avail[i][v][p] = true;
            }
        // slowdown
        for (long long prev = 0; prev <= s; prev++)
        for (long long prep = 0; prep <= c; prep++)
            if (avail[i - 1][prev][prep])
            {
                long long v = max(0ll, prev - 1);
                long long p = min(prep + d, c);
                dp[i][v][p] = max(dp[i][v][p], dp[i - 1][prev][prep] + v);
                avail[i][v][p] = true;
            }
    }
    long long mx = 0;
    for (long long v = 0; v <= s; v++)
    for (long long p = 0; p <= c; p++)
        mx = max(mx, dp[t][v][p]);
    cout << mx;
}




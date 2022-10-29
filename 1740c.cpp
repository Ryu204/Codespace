#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define fi first
#define se second

ll t, n, a[200010];

inline calc(ll x, ll y, ll z)
{
    return abs(x - y) + abs(y - z);
}

void sol()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    ll res = a[3] - a[2] + a[3] - a[1];
    for (int i = 3; i <= n; i++)
        res = max(res, a[i] - a[i - 1] + a[i] - a[1]);
    for (int i = 1; i <= n - 2; i++)
        res = max(res, a[i + 1] - a[i] + a[n] - a[i]);
    cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--)
        sol();
}
